/// evolved from fitBESData_4_1.cpp
// added centrality column in output file : DONE
	// corresponding change in code to retreive centrality information from root file: DONE
// changed all functions (esp the fitting function funcBGBW) to have 6 parameters
	// otherwise the cov. matrix in later functions, with 5 parameters, is not consistent
// added // h->SetMaximum(5*(h->GetMaximum()));

#include <iostream>
#include <string>
#include "TKey.h"
#include <sstream>
#include <fstream>
#include "fitBESData10.h"
using namespace std;
// forward declarations for methods in fitBESData.h:


Double_t getdNdptOverptIntegrand(Double_t* rad, Double_t* par);// not used
Double_t getdNdpt(Double_t* pT, Double_t* params);
string concatenateHistoname(string,string,string,string);
Double_t* getIntegralsAndErrorsFromData(TH1D*, Double_t, Double_t);
/////Double_t* getIntegralsAndErrorsFromFit(Double_t* myPt, Double_t* par);
Double_t getdNdpt(Double_t* pT, Double_t* params);
Double_t getdETdEtaIntegrand(Double_t* myPt, Double_t* par);
Double_t getdETdyIntegrand(Double_t* myPt, Double_t* par);
Double_t getdNdEtaIntegrand(Double_t* myPt, Double_t* par);
Double_t getdNdyIntegrand(Double_t* myPt, Double_t* par);
Int_t* getNpartAndErr(Double_t collisionEnergy, string centrality);

//-------------------------HAGE
Double_t getdNdptHAGE(Double_t* pT, Double_t* params);
Double_t getdETdEtaIntegrandHAGE(Double_t* myPt, Double_t* par);
Double_t getdETdyIntegrandHAGE(Double_t* myPt, Double_t* par);
Double_t getdNdEtaIntegrandHAGE(Double_t* myPt, Double_t* par);
Double_t getdNdyIntegrandHAGE(Double_t* myPt, Double_t* par);
//--------------------expo




// main function:
int fitlams(){
	std::ofstream datFile ("compfitLAMResults.dat", std::ofstream::out);
	datFile << "FIT"<< "\t" << "CollEn"<< "\t"
			<< "particle" << "\t"
			<< "centrality" << "\t"
			<< "mass" << "\t"
			<< "beta" <<"\t"
			<< "betaErr" <<"\t"
			<< "temp" <<"\t"
			<< "tempErr" <<"\t"
			<< "n-v_prof" <<"\t"
			<< "nErr" <<"\t"
			<< "norm" <<"\t"
			<< "normErr" <<"\t"
			<< "dETdEta_data" << "\t" //dETdEta_d
			<< "dETdEta_d_err"<< "\t" //dETdEta_d_err
			<< "dETdEtaLeft" << "\t"
			<< "dETdEtaLErr" << "\t"
			<< "dETdEtaRight" << "\t"
			<< "dETdEtaRErr" << "\t"
			<< "dETdEtaTotal" << "\t" // dETdEtaTotal
			<< "dETdEtaTErr" << "\t"
			<< "dETdy_d" << "\t" //dETdy_d
			<< "dETdy_d_err"<< "\t" //dETdy_d_err
			<< "dETdyLeft" << "\t"
			<< "dETdyLErr" << "\t"
			<< "dETdyRight" << "\t"
			<< "dETdyRErr" << "\t"
			<< "dETdyTotal" << "\t" // dETdyTotal
			<< "dETdyTErr" << "\t"
			<< "dNdEta_d" << "\t" //dNdEta_d
			<< "dNdEta_d_err"<< "\t" //dNdEta_d_err
			<< "dNdEtaLeft" << "\t"
			<< "dNdEtaLErr" << "\t"
			<< "dNdEtaRight" << "\t"
			<< "dNdEtaRErr" << "\t"
			<< "dNdEtaTotal" << "\t" // dNdEtaTotal
			<< "dNdEtaTErr" << "\t"
			<< "dNdy_d" << "\t" //dNdy_d
			<< "dNdy_d_err"<< "\t" //dNdy_d_err
			<< "dNdyLeft" << "\t"
			<< "dNdyLErr" << "\t"
			<< "dNdyRight" << "\t"
			<< "dNdyRErr" << "\t"
			<< "dNdyTotal" << "\t" // dNdyTotal
			<< "dNdyTErr" << "\t"
			<< "Npart" << "\t"
			<< "NpartErr" << "\n";
	
	TFile* myFile = new TFile("STARLAM.root");


	TObjArray *betastack2 = new TObjArray(18);	
	TIter next(myFile->GetListOfKeys());
	TKey* mikey;
	TH1D* h;

	
	TH1D* g;
	TCanvas* c1;
	TClass* class1;
	TF1* funcBGBW;
	TF1* funcBGBW2;
	TF1* dETdEtaIntegrandFunc;
	TF1* dETdyIntegrandFunc;
	TF1* dNdEtaIntegrandFunc;
	TF1* dNdyIntegrandFunc;

	//Constrained
	
	TF1* dETdEtaIntegrandFunc2;
	TF1* dETdyIntegrandFunc2;
	TF1* dNdEtaIntegrandFunc2;
	TF1* dNdyIntegrandFunc2;


	//hagedorn
	
	TF1* HAGE;
	TF1* dETdEtaIntegrandFuncHAGE;
	TF1* dETdyIntegrandFuncHAGE;
	TF1* dNdEtaIntegrandFuncHAGE;
	TF1* dNdyIntegrandFuncHAGE;




	int breakOutForTesting =0;
	int stop =105; // breakOut after this many iterations (if achieved); default: 140
	cout << "Flag" << endl;
	while((mikey=(TKey*)next())){
	  breakOutForTesting++;
		if (breakOutForTesting<0) continue;// 140 histograms already analyzed
		///cout << "Histo iter: " << breakOutForTesting+1 << endl;
		class1 = gROOT->GetClass(mikey->GetClassName());
		if(!class1->InheritsFrom("TH1")){
			delete class1;
			mikey->DeleteBuffer();
			continue;
		}

		c1 = new TCanvas(); // a la Rademakers

		
		funcBGBW = new TF1("getdNdpt",getdNdpt,0.00000000000001,10.,6); // actually has 5 parameters
											
		funcBGBW2 = new TF1("getdNdpt2",getdNdpt,0.00000000000001,10.,6); // second blastwave for alternate starting parms

		
		HAGE = new TF1("getdNdptHAGE",getdNdptHAGE,0.0000000000001,10.,5); // HAGEDORN Function 

	



		
		dETdEtaIntegrandFunc = new TF1("dETdEtaIntegrand",getdETdEtaIntegrand,0, 10, 6 );// function goes from 0 to 10
										// and has 6 parameters"
										// mass, beta, temp, n, norm, type
		dETdyIntegrandFunc = new TF1("dETdyIntegrand", getdETdyIntegrand,0,10,6);
		dNdEtaIntegrandFunc = new TF1("dETdyIntegrand",
								  getdNdEtaIntegrand,
								  0,10,6); // 5 parameters:m,b,t,n,norm, 6th is type*0
		dNdyIntegrandFunc = new TF1("dETdyIntegrand",
								  getdNdEtaIntegrand,
								  0,10,6);// 5 parameters:m,b,t,n,norm, 6th is type*0



		
		dETdEtaIntegrandFunc2 = new TF1("dETdEtaIntegrand2",
									getdETdEtaIntegrand,
									0, 10, 6 );// function goes from 0 to 10
										// and has 6 parameters"
										// mass, beta, temp, n, norm, type
		dETdyIntegrandFunc2 = new TF1("dETdyIntegrand2",
								  getdETdyIntegrand,
								  0,10,6);
		dNdEtaIntegrandFunc2 = new TF1("dETdyIntegrand2",
								  getdNdEtaIntegrand,
								  0,10,6); // 5 parameters:m,b,t,n,norm, 6th is type*0
		dNdyIntegrandFunc2 = new TF1("dETdyIntegrand2",
								  getdNdEtaIntegrand,
								  0,10,6);//


		//Function definitions for hagedorn fitting

		dETdEtaIntegrandFuncHAGE = new TF1("dETdEtaIntegrandHAGE",
									getdETdEtaIntegrandHAGE,
									0, 10, 5 );// function goes from 0 to 10
										// and has 6 parameters"
										// mass, pt,
		dETdyIntegrandFuncHAGE = new TF1("dETdyIntegrandHAGE",
								  getdETdyIntegrandHAGE,
								  0,10,5);
		dNdEtaIntegrandFuncHAGE = new TF1("dETdyIntegrandHAGE",
								  getdNdEtaIntegrandHAGE,
								  0,10,5); // 5 parameters:m, 6th is type*0
		dNdyIntegrandFuncHAGE = new TF1("dETdyIntegrandHAGE",
								  getdNdEtaIntegrandHAGE,
								  0,10,5);// 5 parameters:m, 6th is type*0




		//gPad->SetLogy();
		//gStyle->SetOptFit(1111);// display fit parameters; customizable
		//	gStyle->SetOptDate();// display date (at bottom left)
		gROOT-> SetBatch(kTRUE);// save canvases without displaying them
		c1->Update();

		// read histogram object for current iteration of key:
		h = (TH1D*)mikey->ReadObj();
		g = (TH1D*)mikey->ReadObj();
		string lol =  h->GetName();
		string histoName = lol ;
		//	string histoName = h->GetName();
		Double_t collEn = 0.;// initialize
		//cent8_ka+_Au+Au_7.7 // sample histo name
		if(histoName.substr( histoName.length() - 4 ) == "_7.7") collEn = 7.7;
		else if(histoName.substr( histoName.length() - 4 ) == "11.5") collEn = 11.5;
		else if(histoName.substr( histoName.length() - 4 ) == "19.6") collEn = 19.6;
		else if(histoName.substr( histoName.length() - 4 ) == "u_27") collEn = 27;
		else if(histoName.substr( histoName.length() - 4 ) == "u_39") collEn = 39;
		else if(histoName.substr( histoName.length() - 7 ) == "62.4") collEn = 62.4;
	       	else if(histoName.substr( histoName.length() - 7 ) == "_130") collEn = 130;
		else if(histoName.substr( histoName.length() - 4 ) == "_200") collEn = 200;
		//get first three characters of particle name from histoName:
		string particleID = histoName.substr(6,3);// starting position in array:6, 3 chars total
		string centrality = histoName.substr(4,1);// starting position in array:4, 1 char total

		//------------ Assign mass & type to particle -----------------//
		Double_t mass; // in GeV

		// type Double_t instead of Int_t
		 //to use as argument in TF1 method SetParameters()
		Double_t type;// 0 for mesons, -1 for baryons, 1 for antibaryons
		if		(particleID=="pi-"||particleID=="pi+")
				{mass = 0.13957; type = 0.;}
		else if	(particleID=="ka-"||particleID=="ka+")
				{mass = 0.49368; type = 0.;}
		else if	(particleID=="pro")
				{mass = 0.93827; type = -1.;}
		else if	(particleID=="pba")
				{mass = 0.93827; type = 1.;}
		else if (particleID=="pi0")
				{mass = 0.13497; type = 0.;}
		else if (particleID=="eta")
				{mass = 0.54786; type = 0.;}
		else if (particleID=="la_")
				{mass = 1.11568; type = -1.;}
		else if (particleID=="ala")
				{mass = 1.11568; type = 1.;}
		else {cout << "Check particle: "
				<< particleID<<endl;return 1;}

		Double_t* integralDataPtr;
		// TODO : need to fix what function this should be:
		integralDataPtr = getIntegralsAndErrorsFromData(h,type,mass);
					// ^ method verified!!!


		//------------- Begin BGBW fit --------------------------//
		//FIXME when you delete, use the "C"? option to delete all the inherited objects as well
		if(histoName == "cent0_la_Au+Au_11.5"
		   ||histoName == "cent0_la_Au+Au_200"
		   ||histoName == "cent1_la_Au+Au_19.6"
		   ||histoName == "cent1_la_Au+Au_27"
		   ||histoName == "cent2_ala_Au+Au_39"
		  
		   ||histoName == "cent3_la_Au+Au_7.7"
		  
		   ||histoName == "cent5_la_Au+Au_7.7"
		   ||histoName == "cent6_la_Au+Au_11.5"
		   ||histoName == "cent2_la_Au+Au_200"
		   ||histoName == "cent4_la_Au+Au_39"
		   ||histoName == "cent4_ala_Au+Au_200"){
		  cout<< "altparms" <<endl;
		funcBGBW->SetParameters(mass,0.95,0.05,0.1,1000000.,type);
		funcBGBW->SetParNames("mass","beta (c)","temp","n","norm","type");
	       	}

	
		else{
			cout << "histoname is: " << histoName << endl;
			funcBGBW->SetParameters(mass,0.9,0.05,0.01,1000000.,type);
			//	funcBGBW2->SetParameters(mass,0.6,0.05,0.1,10000.,type);
			}
	
		funcBGBW->SetParNames("mass","beta (c)","temp","n","norm","type");
		funcBGBW->SetParLimits(1,0.3,0.999999999999999999999);//param 1
		funcBGBW->FixParameter(0,mass);// mass in GeV
		funcBGBW->FixParameter(5,type);

		//fixing bgbw2
		funcBGBW2->SetParameters(mass,0.3,.08,.01,10000.,type);
		funcBGBW2->SetParLimits(1,0.3,0.8);//beta
		funcBGBW2->SetParLimits(2,.08,.2);//temp
	        funcBGBW2->SetParLimits(3,0.01,5);//n		
		funcBGBW2->SetParNames("mass","beta (c)","temp","n","norm","type");
	       //funcBGBW2->SetParLimits(1,0.5,0.999999999999999999999);//param 1
		funcBGBW2->FixParameter(0,mass);// mass in GeV
		funcBGBW2->FixParameter(5,type);
		//	funcBGBW2->SetLineColor(kBlue);

		//HAGEDORN
		if(particleID=="pro"){
	        HAGE->SetParameters(mass,1.,1.,5.,type);
		HAGE->SetParNames("mass","A","temp","n","type");
		HAGE->FixParameter(0,mass);// mass in GeV
		HAGE->FixParameter(4,type);
		//HAGE->SetLineColor(kCyan+2);
		}
		else{
		HAGE->SetParameters(mass,1.,1.,5.,type);
		HAGE->SetParNames("mass","A","temp","n","type");
		HAGE->SetLineColor(kCyan);
		HAGE->SetParLimits(2,50.,200.); // temp
		HAGE->SetParLimits(3,5.,15.); // norm
		HAGE->FixParameter(0,mass);// mass in GeV
		HAGE->FixParameter(4,type);
		}
		//EXPOS
	

			funcBGBW->SetLineColor(kBlue);
		funcBGBW->SetLineStyle(10);
		funcBGBW->SetLineWidth(1);
		
		funcBGBW2->SetLineColor(kRed);
		funcBGBW2->SetLineStyle(7);
		funcBGBW2->SetLineWidth(1);

		HAGE->SetLineColor(kCyan+2);
		HAGE->SetLineStyle(5);
		HAGE->SetLineWidth(1);

	
	

		
		ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(20000);
		TFitResultPtr r = h->Fit("getdNdpt","S+","M",0.00000000000001,10.);
		Double_t meanpt1= funcBGBW->GetHistogram()->GetMean();
		
		TFitResultPtr l = h->Fit("getdNdpt2","S+","M",0.00000000000001,10.);
	        //g->Fit("getdNdpt2","S","",0.00000000000001,10.);
		Double_t meanpt2 = funcBGBW2->GetHistogram()->GetMean();

		TFitResultPtr p = h->Fit("getdNdptHAGE","S+","M",0.000000000001,10.);
		Double_t meanpt3= HAGE->GetHistogram()->GetMean();
		//EXPO
	
		
		Double_t chi2Prob = r->Prob();
		Double_t chi2prob2 = l->Prob();
		Double_t chi3prob3 = p->Prob();
	

		
	
		h->SetMaximum(5*(h->GetMaximum()));
		//h-> GetYaxis()->SetRangeUser(0.,maxY);
		//TMatrixDSym cov = r->GetCovarianceMatrix();
		h-> GetXaxis()->SetRangeUser(0.,10.);
		TString xlabel = "p_{T}";
		TString ylabel = "#frac{d^{2}N}{dydp_{T}}";
		h-> SetXTitle(xlabel);
		h-> SetYTitle(ylabel);
		Double_t beta2 =                  funcBGBW2->GetParameter(1);
		Double_t temp2 			= funcBGBW2->GetParameter(2);
		Double_t n2	  		= funcBGBW2->GetParameter(3);
		Double_t norm2 			= funcBGBW2->GetParameter(4);
		Double_t betaErr2 		= funcBGBW2->GetParError(1);
		Double_t tempErr2 		= funcBGBW2->GetParError(2);
		Double_t nErr2 			= funcBGBW2->GetParError(3);
		Double_t normErr2 		= funcBGBW2->GetParError(4);

		
		Double_t beta 			= funcBGBW->GetParameter(1);
		Double_t temp 			= funcBGBW->GetParameter(2);
		Double_t n	  		= funcBGBW->GetParameter(3);
		Double_t norm 			= funcBGBW->GetParameter(4);
		Double_t betaErr 		= funcBGBW->GetParError(1);
		Double_t tempErr 		= funcBGBW->GetParError(2);
		Double_t nErr 			= funcBGBW->GetParError(3);
		Double_t normErr 		= funcBGBW->GetParError(4);
		//------------- end BGBW fit ----------------------------


		//-------------hagedorn varibles-------------------------
		Double_t A = HAGE->GetParameter(1);
		Double_t tempH = HAGE->GetParameter(2);
		Double_t nH = HAGE->GetParameter(3);
		Double_t AErr = HAGE->GetParError(1);
		Double_t tempHErr = HAGE->GetParError(2);
		Double_t nHErr = HAGE->GetParError(3);


		//------------------------------------expoparms-----------
		
	




		
		//-------- Find integrals left and right of data points -------//
		funcBGBW			 	-> SetParameters(mass,beta,temp,n,norm,type);
		dETdEtaIntegrandFunc 	-> SetParameters(mass,beta,temp,n,norm,type);
		dETdEtaIntegrandFunc	-> FixParameter(5,type);
		dETdEtaIntegrandFunc	-> FixParameter(0,mass);
		dETdyIntegrandFunc 		-> SetParameters(mass,beta,temp,n,norm,type);
		dETdyIntegrandFunc		-> FixParameter(5,type);
		dETdyIntegrandFunc		-> FixParameter(0,mass);
		dNdEtaIntegrandFunc 	-> SetParameters(mass,beta,temp,n,norm,type);
		dNdEtaIntegrandFunc		-> FixParameter(0,mass);
		dNdEtaIntegrandFunc		-> FixParameter(5,type);
		dNdyIntegrandFunc 		-> SetParameters(mass,beta,temp,n,norm,type);
		dNdyIntegrandFunc		-> FixParameter(0,mass);
		dNdyIntegrandFunc		-> FixParameter(5,type);

		Int_t totBins 	= h->GetNbinsX();
		Int_t binx1 	= 0;
		Int_t binx2 	= totBins+1;

		Double_t leftCut 	= h->GetXaxis()->GetBinLowEdge(binx1+2);
		Double_t rightCut 	= h->GetXaxis()->GetBinUpEdge(binx2-1);

		Double_t dETdEtaLeft 	= dETdEtaIntegrandFunc -> Integral(0.,leftCut);
		Double_t dETdEtaRight 	= dETdEtaIntegrandFunc -> Integral(rightCut,10.);
		Double_t dETdyLeft 		= dETdyIntegrandFunc -> Integral(0.,leftCut);
		Double_t dETdyRight 	= dETdyIntegrandFunc -> Integral(rightCut,10.);
		Double_t dNdEtaLeft 	= dNdEtaIntegrandFunc -> Integral(0.,leftCut);
		Double_t dNdEtaRight 	= dNdEtaIntegrandFunc -> Integral(rightCut,10.);
		Double_t dNdyLeft 		= dNdyIntegrandFunc -> Integral(0.,leftCut);
		Double_t dNdyRight 		= dNdyIntegrandFunc -> Integral(rightCut,10.);
		// Errors:
		Double_t dETdEtaLErr	=
		dETdEtaIntegrandFunc->IntegralError(0.,leftCut,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdEtaRErr	=
		dETdEtaIntegrandFunc->IntegralError(rightCut,10.,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyLErr	=
		dETdyIntegrandFunc->IntegralError(0.,leftCut,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyRErr	=
		dETdyIntegrandFunc->IntegralError(rightCut,10.,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaLErr	=
		dNdEtaIntegrandFunc->IntegralError(0.,leftCut,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaRErr	=
		dETdEtaIntegrandFunc->IntegralError(rightCut,10.,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyLErr	=
		dNdyIntegrandFunc->IntegralError(0.,leftCut,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyRErr	=
		dNdyIntegrandFunc->IntegralError(rightCut,10.,
								r->GetParams(),
								r->GetCovarianceMatrix().GetMatrixArray());

		Double_t dETdEta_d = *(integralDataPtr+0);
		Double_t dETdEta_d_err = *(integralDataPtr+1);
		Double_t dETdEtaTotal = dETdEtaLeft+dETdEta_d+dETdEtaRight;
		Double_t dETdEtaTErr = dETdEtaLErr+dETdEta_d_err+dETdEtaRErr;

		Double_t dETdy_d = *(integralDataPtr+2);
		Double_t dETdy_d_err = *(integralDataPtr+3);
		Double_t dETdyTotal = dETdyLeft+dETdy_d+dETdyRight;
		Double_t dETdyTErr = dETdyLErr+dETdy_d_err+dETdyRErr;

		Double_t dNdEta_d = *(integralDataPtr+4);
		Double_t dNdEta_d_err = *(integralDataPtr+5);
		Double_t dNdEtaTotal = dNdEtaLeft+dNdEta_d+dNdEtaRight;
		Double_t dNdEtaTErr = dNdEtaLErr+dNdEta_d_err+dNdEtaRErr;

		Double_t dNdy_d = *(integralDataPtr+6);
		Double_t dNdy_d_err = *(integralDataPtr+7);
		Double_t dNdyTotal = dNdyLeft+dNdy_d+dNdyRight;
		Double_t dNdyTErr = dNdyLErr+dNdy_d_err+dNdyRErr;

		cout <<"Integral from data for histo "<<breakOutForTesting+1<<": "<<*(integralDataPtr+0)<<endl;// 357.633 for pi minus cent 0
		cout<<"-----------------------------------"<<endl;
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtr;
		Int_t Npart;
		Int_t NpartErr;

		// for lambdas, last four centrality classes are binned into two:

		if(collEn == 200||collEn == 130){
		  if (centrality == "1" || centrality == "2"||centrality == "3"||centrality == "4"){
		  if(centrality == "1"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			Npart = *(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"2");
		  }
		  else if(centrality== "2"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"3");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"4");

		  }
		  else if(centrality== "3"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"5");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"6");

		  }
		  else if(centrality == "4"){
		    NpartAndArrPtr = getNpartAndErr(collEn,"7");
		    Npart =* (NpartAndArrPtr+0);
		    NpartAndArrPtr = getNpartAndErr(collEn,"8");
		  }
		  
		 
		         Npart +=* (NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/4.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
	}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
		 if(collEn == 7.7||collEn == 11.5||collEn == 19.6 || collEn == 27 || collEn  ==39){
		  
		if ((particleID=="la_" || particleID=="ala") &&	(centrality == "5" || centrality == "6")){
			 if(centrality == "5") // which should be 40-60% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"6"); // 50-60%

			 }
			 else if(centrality == "6") // which should be 60-80% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,"7"); // 60-70%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"8"); // 70-80%
			 }
			 Npart += *(NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/2.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
		}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
	
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		datFile <<"bis\t" <<collEn << "\t"
				<< particleID << "\t"
				<< centrality << "\t"
				<< mass << "\t"
				<< beta <<"\t"
				<< betaErr <<"\t"
				<< temp <<"\t"
				<< tempErr <<"\t"
				<< n <<"\t"
				<< nErr <<"\t"
				<< norm <<"\t"
				<< normErr <<"\t"
				<< dETdEta_d << "\t" //dETdEta_d
				<< dETdEta_d_err<< "\t" //dETdEta_d_err
				<< dETdEtaLeft << "\t"
				<< dETdEtaLErr << "\t"
				<< dETdEtaRight << "\t"
				<< dETdEtaRErr << "\t"
				<< dETdEtaTotal<< "\t" // dETdEtaTotal
				<< dETdEtaTErr << "\t"
				<< dETdy_d << "\t" //dETdy_d
				<< dETdy_d_err<< "\t" //dETdy_d_err
				<< dETdyLeft << "\t"
				<< dETdyLErr << "\t"
				<< dETdyRight << "\t"
				<< dETdyRErr << "\t"
				<< dETdyTotal<< "\t" // dETdyTotal
				<< dETdyTErr << "\t"
				<< dNdEta_d << "\t" //dNdEta_d
				<< dNdEta_d_err<< "\t" //dNdEta_d_err
				<< dNdEtaLeft << "\t"
				<< dNdEtaLErr << "\t"
				<< dNdEtaRight << "\t"
				<< dNdEtaRErr << "\t"
				<< dNdEtaTotal << "\t" // dNdEtaTotal
				<< dNdEtaTErr << "\t"
				<< dNdy_d << "\t" //dNdy_d
				<< dNdy_d_err<< "\t" //dNdy_d_err
				<< dNdyLeft << "\t"
				<< dNdyLErr << "\t"
				<< dNdyRight << "\t"
				<< dNdyRErr << "\t"
				<< dNdyTotal << "\t" // dNdyTotal
				<< dNdyTErr << "\t"
				<< Npart << "\t"
				<< NpartErr << "\n";

		//-- end- output results to file------------------------
		c1->Update();
		Double_t chi2BGBW = funcBGBW->GetChisquare();
		Double_t nDFBGBW = funcBGBW->GetNDF();
		Double_t p2 = funcBGBW->GetParameter(2);
		Double_t e2 = funcBGBW->GetParError(2);

		funcBGBW2			 	-> SetParameters(mass,beta2,temp2,n2,norm2,type);
		dETdEtaIntegrandFunc2 	-> SetParameters(mass,beta2,temp2,n2,norm2,type);
		dETdEtaIntegrandFunc2	-> FixParameter(5,type);
		dETdEtaIntegrandFunc2	-> FixParameter(0,mass);
		dETdyIntegrandFunc2 		-> SetParameters(mass,beta2,temp2,n2,norm2,type);
		dETdyIntegrandFunc2		-> FixParameter(5,type);
		dETdyIntegrandFunc2		-> FixParameter(0,mass);
		dNdEtaIntegrandFunc2 	-> SetParameters(mass,beta2,temp2,n2,norm2,type);
		dNdEtaIntegrandFunc2		-> FixParameter(0,mass);
		dNdEtaIntegrandFunc2		-> FixParameter(5,type);
		dNdyIntegrandFunc2		-> SetParameters(mass,beta2,temp2,n2,norm2,type);
		dNdyIntegrandFunc2		-> FixParameter(0,mass);
		dNdyIntegrandFunc2		-> FixParameter(5,type);

		Int_t totBins2 	= h->GetNbinsX();
		Int_t binx12 	= 0;
		Int_t binx22 	= totBins+1;

		Double_t leftCut2 	= h->GetXaxis()->GetBinLowEdge(binx12+2);
		Double_t rightCut2 	= h->GetXaxis()->GetBinUpEdge(binx22-1);

		Double_t dETdEtaLeft2 	= dETdEtaIntegrandFunc2 -> Integral(0.,leftCut2);
		Double_t dETdEtaRight2 	= dETdEtaIntegrandFunc2 -> Integral(rightCut2,10.);
		Double_t dETdyLeft2 		= dETdyIntegrandFunc2 -> Integral(0.,leftCut2);
		Double_t dETdyRight2 	= dETdyIntegrandFunc2 -> Integral(rightCut2,10.);
		Double_t dNdEtaLeft2 	= dNdEtaIntegrandFunc2 -> Integral(0.,leftCut2);
		Double_t dNdEtaRight2 	= dNdEtaIntegrandFunc2 -> Integral(rightCut2,10.);
		Double_t dNdyLeft2 		= dNdyIntegrandFunc2 -> Integral(0.,leftCut2);
		Double_t dNdyRight2 		= dNdyIntegrandFunc2 -> Integral(rightCut2,10.);
		// Errors:
		Double_t dETdEtaLErr2	=
		dETdEtaIntegrandFunc2->IntegralError(0.,leftCut2,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdEtaRErr2	=
		dETdEtaIntegrandFunc2->IntegralError(rightCut2,10.,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyLErr2	=
		dETdyIntegrandFunc2->IntegralError(0.,leftCut2,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyRErr2	=
		dETdyIntegrandFunc2->IntegralError(rightCut2,10.,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaLErr2	=
		dNdEtaIntegrandFunc2->IntegralError(0.,leftCut2,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaRErr2	=
		dETdEtaIntegrandFunc2->IntegralError(rightCut2,10.,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyLErr2	=
		dNdyIntegrandFunc2->IntegralError(0.,leftCut2,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyRErr2	=
		dNdyIntegrandFunc2->IntegralError(rightCut2,10.,
								l->GetParams(),
								l->GetCovarianceMatrix().GetMatrixArray());

		Double_t dETdEta_d2 = *(integralDataPtr+0);
		Double_t dETdEta_d_err2 = *(integralDataPtr+1);
		Double_t dETdEtaTotal2 = dETdEtaLeft2+dETdEta_d2+dETdEtaRight2;
		Double_t dETdEtaTErr2 = dETdEtaLErr2+dETdEta_d_err2+dETdEtaRErr2;

		Double_t dETdy_d2 = *(integralDataPtr+2);
		Double_t dETdy_d_err2 = *(integralDataPtr+3);
		Double_t dETdyTotal2 = dETdyLeft2+dETdy_d2+dETdyRight2;
		Double_t dETdyTErr2 = dETdyLErr2+dETdy_d_err2+dETdyRErr2;

		Double_t dNdEta_d2 = *(integralDataPtr+4);
		Double_t dNdEta_d_err2 = *(integralDataPtr+5);
		Double_t dNdEtaTotal2 = dNdEtaLeft2+dNdEta_d2+dNdEtaRight2;
		Double_t dNdEtaTErr2 = dNdEtaLErr2+dNdEta_d_err2+dNdEtaRErr2;

		Double_t dNdy_d2 = *(integralDataPtr+6);
		Double_t dNdy_d_err2 = *(integralDataPtr+7);
		Double_t dNdyTotal2 = dNdyLeft2+dNdy_d2+dNdyRight2;
		Double_t dNdyTErr2 = dNdyLErr2+dNdy_d_err2+dNdyRErr2;

		cout <<"Integral from data for histo "<<breakOutForTesting+1<<": "<<*(integralDataPtr+0)<<endl;// 357.633 for pi minus cent 0
		cout<<"-----------------------------------"<<endl;
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtr2;
		Int_t Npart2;
		Int_t NpartErr2;

		// for lambdas, last four centrality classes are binned into two:

	
		if(collEn == 200||collEn == 130){
		  if ((centrality == "1" || centrality == "2"||centrality == "3"||centrality == "4")){
		  if(centrality == "1"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			Npart = *(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"2");
		  }
		  else if(centrality== "2"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"3");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"4");

		  }
		  else if(centrality== "3"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"5");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"6");

		  }
		  else if(centrality == "4"){
		    NpartAndArrPtr = getNpartAndErr(collEn,"7");
		    Npart =* (NpartAndArrPtr+0);
		    NpartAndArrPtr = getNpartAndErr(collEn,"8");
		  }
		  
		 
		         Npart +=* (NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/4.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
	}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
		 if(collEn == 7.7||collEn == 11.5||collEn == 19.6 || collEn == 27 || collEn  ==39){
		  
		if ((particleID=="la_" || particleID=="ala") &&	(centrality == "5" || centrality == "6")){
			 if(centrality == "5") // which should be 40-60% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"6"); // 50-60%

			 }
			 else if(centrality == "6") // which should be 60-80% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,"7"); // 60-70%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"8"); // 70-80%
			 }
			 Npart += *(NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/2.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
		}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
	
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		datFile << "tan\t"<<collEn << "\t"
				<< particleID << "\t"
				<< centrality << "\t"
				<< mass << "\t"
				<< beta2 <<"\t"
				<< betaErr2 <<"\t"
				<< temp2 <<"\t"
				<< tempErr2 <<"\t"
				<< n2 <<"\t"
				<< nErr2 <<"\t"
				<< norm2 <<"\t"
				<< normErr2 <<"\t"
				<< dETdEta_d2 << "\t" //dETdEta_d
				<< dETdEta_d_err2<< "\t" //dETdEta_d_err
				<< dETdEtaLeft2 << "\t"
				<< dETdEtaLErr2 << "\t"
				<< dETdEtaRight2 << "\t"
				<< dETdEtaRErr2 << "\t"
				<< dETdEtaTotal2<< "\t" // dETdEtaTotal
				<< dETdEtaTErr2 << "\t"
				<< dETdy_d2 << "\t" //dETdy_d
				<< dETdy_d_err2<< "\t" //dETdy_d_err
				<< dETdyLeft2 << "\t"
				<< dETdyLErr2 << "\t"
				<< dETdyRight2 << "\t"
				<< dETdyRErr2 << "\t"
				<< dETdyTotal2<< "\t" // dETdyTotal
				<< dETdyTErr2 << "\t"
				<< dNdEta_d2 << "\t" //dNdEta_d
				<< dNdEta_d_err2<< "\t" //dNdEta_d_err
				<< dNdEtaLeft2 << "\t"
				<< dNdEtaLErr2 << "\t"
				<< dNdEtaRight2 << "\t"
				<< dNdEtaRErr2 << "\t"
				<< dNdEtaTotal2 << "\t" // dNdEtaTotal
				<< dNdEtaTErr2 << "\t"
				<< dNdy_d2 << "\t" //dNdy_d
				<< dNdy_d_err2<< "\t" //dNdy_d_err
				<< dNdyLeft2 << "\t"
				<< dNdyLErr2 << "\t"
				<< dNdyRight2 << "\t"
				<< dNdyRErr2 << "\t"
				<< dNdyTotal2 << "\t" // dNdyTotal
				<< dNdyTErr2 << "\t"
				<< Npart2 << "\t"
				<< NpartErr2 << "\n";

		//-- end- output results to file------------------------
		c1->Update();
	
		
		Double_t chi2BGBW2 = funcBGBW2->GetChisquare();
		Double_t nDFBGBW2 = funcBGBW2->GetNDF();
		Double_t p22 = funcBGBW2->GetParameter(2);
		Double_t e22 = funcBGBW2->GetParError(2);


		HAGE			 	-> SetParameters(mass,A,tempH,nH,type);
		dETdEtaIntegrandFuncHAGE 	-> SetParameters(mass,A,tempH,nH,type);
		dETdEtaIntegrandFuncHAGE	-> FixParameter(4,type);
		dETdEtaIntegrandFuncHAGE	-> FixParameter(0,mass);
		dETdyIntegrandFuncHAGE 		-> SetParameters(mass,A,tempH,nH,type);
		dETdyIntegrandFuncHAGE		-> FixParameter(4,type);
		dETdyIntegrandFuncHAGE		-> FixParameter(0,mass);
		dNdEtaIntegrandFuncHAGE 	-> SetParameters(mass,A,tempH,nH,type);
		dNdEtaIntegrandFuncHAGE		-> FixParameter(0,mass);
		dNdEtaIntegrandFuncHAGE		-> FixParameter(4,type);
		dNdyIntegrandFuncHAGE		-> SetParameters(mass,A,tempH,nH,type);
		dNdyIntegrandFuncHAGE		-> FixParameter(0,mass);
		dNdyIntegrandFuncHAGE		-> FixParameter(4,type);

		Int_t totBinsH 	= h->GetNbinsX();
		Int_t binx1H 	= 0;
		Int_t binx2H 	= totBins+1;

		Double_t leftCutH 	= h->GetXaxis()->GetBinLowEdge(binx1H+2);
		Double_t rightCutH 	= h->GetXaxis()->GetBinUpEdge(binx2H-1);

		Double_t dETdEtaLeftH 	= dETdEtaIntegrandFuncHAGE -> Integral(0.,leftCutH);
		Double_t dETdEtaRightH 	= dETdEtaIntegrandFuncHAGE -> Integral(rightCutH,10.);
		Double_t dETdyLeftH 		= dETdyIntegrandFuncHAGE -> Integral(0.,leftCutH);
		Double_t dETdyRightH 	= dETdyIntegrandFuncHAGE -> Integral(rightCutH,10.);
		Double_t dNdEtaLeftH 	= dNdEtaIntegrandFuncHAGE -> Integral(0.,leftCutH);
		Double_t dNdEtaRightH 	= dNdEtaIntegrandFuncHAGE -> Integral(rightCutH,10.);
		Double_t dNdyLeftH 		= dNdyIntegrandFuncHAGE -> Integral(0.,leftCutH);
		Double_t dNdyRightH 		= dNdyIntegrandFuncHAGE -> Integral(rightCutH,10.);
		// Errors:
		Double_t dETdEtaLErrH	=
		dETdEtaIntegrandFuncHAGE->IntegralError(0.,leftCutH,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdEtaRErrH	=
		dETdEtaIntegrandFuncHAGE->IntegralError(rightCutH,10.,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyLErrH	=
		dETdyIntegrandFuncHAGE->IntegralError(0.,leftCutH,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyRErrH	=
		dETdyIntegrandFuncHAGE->IntegralError(rightCutH,10.,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaLErrH	=
		dNdEtaIntegrandFuncHAGE->IntegralError(0.,leftCutH,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaRErrH	=
		dETdEtaIntegrandFuncHAGE->IntegralError(rightCutH,10.,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyLErrH	=
		dNdyIntegrandFuncHAGE->IntegralError(0.,leftCutH,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyRErrH	=
		dNdyIntegrandFuncHAGE->IntegralError(rightCutH,10.,
								p->GetParams(),
								p->GetCovarianceMatrix().GetMatrixArray());

		Double_t dETdEta_dH = *(integralDataPtr+0);
		Double_t dETdEta_d_errH = *(integralDataPtr+1);
		Double_t dETdEtaTotalH = dETdEtaLeftH+dETdEta_dH+dETdEtaRightH;
		Double_t dETdEtaTErrH = dETdEtaLErrH+dETdEta_d_errH+dETdEtaRErrH;

		Double_t dETdy_dH = *(integralDataPtr+2);
		Double_t dETdy_d_errH = *(integralDataPtr+3);
		Double_t dETdyTotalH = dETdyLeftH+dETdy_dH+dETdyRightH;
		Double_t dETdyTErrH = dETdyLErrH+dETdy_d_errH+dETdyRErrH;

		Double_t dNdEta_dH = *(integralDataPtr+4);
		Double_t dNdEta_d_errH = *(integralDataPtr+5);
		Double_t dNdEtaTotalH = dNdEtaLeftH+dNdEta_dH+dNdEtaRightH;
		Double_t dNdEtaTErrH = dNdEtaLErrH+dNdEta_d_errH+dNdEtaRErrH;

		Double_t dNdy_dH = *(integralDataPtr+6);
		Double_t dNdy_d_errH = *(integralDataPtr+7);
		Double_t dNdyTotalH = dNdyLeftH+dNdy_dH+dNdyRightH;
		Double_t dNdyTErrH = dNdyLErrH+dNdy_d_errH+dNdyRErrH;

		cout <<"Integral from data for histo "<<breakOutForTesting+1<<": "<<*(integralDataPtr+0)<<endl;// 357.633 for pi minus cent 0
		cout<<"-----------------------------------"<<endl;
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtrH;
		Int_t NpartH;
		Int_t NpartErrH;

		// for lambdas, last four centrality classes are binned into two:

	
		if(collEn == 200||collEn == 130){
		  if ((centrality == "1" || centrality == "2"||centrality == "3"||centrality == "4")){
		  if(centrality == "1"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			Npart = *(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"2");
		  }
		  else if(centrality== "2"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"3");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"4");

		  }
		  else if(centrality== "3"){
		    	NpartAndArrPtr = getNpartAndErr(collEn,"5");
			Npart =*(NpartAndArrPtr+0);
			NpartAndArrPtr = getNpartAndErr(collEn,"6");

		  }
		  else if(centrality == "4"){
		    NpartAndArrPtr = getNpartAndErr(collEn,"7");
		    Npart =* (NpartAndArrPtr+0);
		    NpartAndArrPtr = getNpartAndErr(collEn,"8");
		  }
		  
		 
		         Npart +=* (NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/4.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
	}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
		 if(collEn == 7.7||collEn == 11.5||collEn == 19.6 || collEn == 27 || collEn  ==39){
		  
		if ((particleID=="la_" || particleID=="ala") &&	(centrality == "5" || centrality == "6")){
			 if(centrality == "5") // which should be 40-60% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,centrality); // 40-50%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"6"); // 50-60%

			 }
			 else if(centrality == "6") // which should be 60-80% for lambdas
			 {
			 	NpartAndArrPtr = getNpartAndErr(collEn,"7"); // 60-70%
			 	Npart = *(NpartAndArrPtr+0);
			 	NpartAndArrPtr = getNpartAndErr(collEn,"8"); // 70-80%
			 }
			 Npart += *(NpartAndArrPtr+0); // added the two, next average:
			 Double_t tempAvg = Npart/2.;
			 Npart = ceil(tempAvg); // FIXME rounded down
			 // for a conservative estimate, take the bigger error between the two (50-60%):
			 NpartErr = *(NpartAndArrPtr+0);
		}
		}
		else
		{
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		}
	
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		datFile << "hag\t"<<collEn << "\t"
				<< particleID << "\t"
				<< centrality << "\t"
				<< mass << "\t"
				<< A <<"\t"
				<< AErr <<"\t"
				<< tempH <<"\t"
				<< tempHErr <<"\t"
				<< nH <<"\t"
				<< nHErr <<"\t"
				<< dETdEta_dH << "\t" //dETdEta_d
				<< dETdEta_d_errH<< "\t" //dETdEta_d_err
				<< dETdEtaLeftH << "\t"
				<< dETdEtaLErrH << "\t"
				<< dETdEtaRightH << "\t"
				<< dETdEtaRErrH << "\t"
				<< dETdEtaTotalH<< "\t" // dETdEtaTotal
				<< dETdEtaTErrH << "\t"
				<< dETdy_dH << "\t" //dETdy_d
				<< dETdy_d_errH<< "\t" //dETdy_d_err
				<< dETdyLeftH<< "\t"
				<< dETdyLErrH << "\t"
				<< dETdyRightH << "\t"
				<< dETdyRErrH << "\t"
				<< dETdyTotalH<< "\t" // dETdyTotal
				<< dETdyTErrH << "\t"
				<< dNdEta_dH << "\t" //dNdEta_d
				<< dNdEta_d_errH<< "\t" //dNdEta_d_err
				<< dNdEtaLeftH << "\t"
				<< dNdEtaLErrH << "\t"
				<< dNdEtaRightH << "\t"
				<< dNdEtaRErrH << "\t"
				<< dNdEtaTotalH << "\t" // dNdEtaTotal
				<< dNdEtaTErrH << "\t"
				<< dNdy_dH << "\t" //dNdy_d
				<< dNdy_d_errH<< "\t" //dNdy_d_err
				<< dNdyLeftH << "\t"
				<< dNdyLErrH << "\t"
				<< dNdyRightH << "\t"
				<< dNdyRErrH << "\t"
				<< dNdyTotalH << "\t" // dNdyTotal
				<< dNdyTErrH << "\t"
				<< NpartH << "\t"
				<< NpartErrH << "\n";

		//-- end- output results to file------------------------
		c1->Update();
	
		
		Double_t chi2BGBWH = HAGE->GetChisquare();
		Double_t nDFBGBW2H = HAGE->GetNDF();
		Double_t p2H = HAGE->GetParameter(2);
		Double_t e2H = HAGE->GetParError(2);



		/*
	auto *legend = new TLegend(.6,.6,1,.94);
	legend->SetHeader("Fit Function","C");
	legend->AddEntry(funcBGBW,"Unconstrained BGBW","l");
	legend->AddEntry(funcBGBW2,"Constrained BGBW","l");
	legend->AddEntry(l1,"Mean PT- Un.","l");
	legend->AddEntry(l2,"Mean PT - const.","l");
	legend->Draw();
		*/

	
	TString hisst = g->GetName();
	c1->cd();
	Double_t yloc = funcBGBW->GetHistogram()->GetMaximum();
	yloc = yloc/10.0;
	
	TF1* hj = new TF1();
	hj =dETdyIntegrandFunc ;
	hj->DrawCopy();
	hj->Draw();
	hj->GetHistogram()->GetXaxis()->SetRangeUser(0.,5.);
	hj->GetHistogram()->GetYaxis()->SetRangeUser(0.,(100.0*yloc));
	hj->GetHistogram()->SetXTitle(xlabel);
	hj->GetHistogram()->SetYTitle(ylabel);
	hj->SetTitle(hisst);
	hj->SetLineColor(kWhite);
	h->SetMarkerSize(2);
	h->SetMarkerStyle(3);
	h->Draw("same");

        h->GetXaxis()->SetRangeUser(0.,3.);
	//	h->SetMarkerSize(5);
	//	h->GetYaxis()->SetRangeUser(0.,(13.0*yloc));
	c1->Update();

	auto *legend = new TLegend(.75,.77,.99,.95);
	legend->SetHeader("Fit Function","C");
	legend->AddEntry(funcBGBW,"Blastwave 1","l");
	legend->AddEntry(funcBGBW2,"Blastwave 2","l");
	legend->AddEntry(HAGE,"Hagedorn","l");

	legend->Draw();
	//	h->Draw("same");
	c1->Update();
	c1->SetTitle(hisst);


	
	        

		//cout << "chi2: " << chi2BGBW << "\nndf: "
			//<< nDFBGBW<< "\nchi2/ndf: " << chi2BGBW/nDFBGBW <<endl;

		/* FIXME */
		string imgPathAndName = "./fittedPlots53/"+histoName+".png";
				//c1 -> SaveAs("./fittedPlots/trial1.png");
		TImage *png = TImage::Create();// FIXME try to use canvas method instead of png object
		png->FromPad(c1);
		const char* imgPathAndNameConstCharPtr = imgPathAndName.c_str();
		png->WriteImage(imgPathAndNameConstCharPtr);

	
		mikey->DeleteBuffer();// works!
		//	breakOutForTesting++;
		if(breakOutForTesting>=stop) break;

		gSystem->ProcessEvents();
		delete h;
		delete funcBGBW;
		delete dETdEtaIntegrandFunc;
		delete dETdyIntegrandFunc;
		delete c1;	// Rademakers
		//delete mikey; // FIXME 9 segmentation violation
		//delete class1; // segmentation violation
	}
	//}// end of while loop to iterate through every key
	/////////////delete c1;
	//delete mikey;
	//delete h;
	//delete class1;
	//delete funcBGBW;
	//delete dETdEtaIntegrandFunc;
	//delete dETdyIntegrandFunc;
	gObjectTable->Print();
	
	datFile.close();

	//	fout->Close();
return 0;
}



