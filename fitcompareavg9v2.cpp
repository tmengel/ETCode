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




// main function:
int fitcompareavg9v2(){
	std::ofstream avg ("avgfitResults.dat", std::ofstream::app);

	
	TFile* myFile = new TFile("ALLSTAR.root");
	TIter next(myFile->GetListOfKeys());
	TKey* mikey;
	TH1D* h;
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
	int stop =450; // breakOut after this many iterations (if achieved); default: 140
	cout << "Flag" << endl;
	while((mikey=(TKey*)next())){
	  breakOutForTesting++;
		if (breakOutForTesting<400) continue;// 140 histograms already analyzed
		///cout << "Histo iter: " << breakOutForTesting+1 << endl;
		class1 = gROOT->GetClass(mikey->GetClassName());
		if(!class1->InheritsFrom("TH1")){
			delete class1;
			mikey->DeleteBuffer();
			continue;
		}

			
		Double_t avgET=0.0;
		Double_t avgET_err=0.0;
		Double_t avgN=0.0;
		Double_t avgN_err=0.0;
		Double_t avgNpart=0.0;
		Double_t avgNpart_err=0.0;
	
		
	       	c1 = new TCanvas(); 
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





	
		//gStyle->SetOptFit(1111);// display fit parameters; customizable
		//	gStyle->SetOptDate();// display date (at bottom left)
		gPad->SetLogy();
		gStyle->SetOptFit(1111);// display fit parameters; customizable
		gStyle->SetOptDate();
		gROOT-> SetBatch(kTRUE);// save canvases without displaying them
		c1->Update();
	
		// read histogram object for current iteration of key:
		h = (TH1D*)mikey->ReadObj();
			
		string histoName = h->GetName();
		Double_t collEn = 0.;// initialize
		//cent8_ka+_Au+Au_7.7 // sample histo name
		if(histoName.substr( histoName.length() - 4 ) == "_7.7") collEn = 7.7;
		else if(histoName.substr( histoName.length() - 4 ) == "11.5") collEn = 11.5;
		else if(histoName.substr( histoName.length() - 4 ) == "19.6") collEn = 19.6;
		else if(histoName.substr( histoName.length() - 4 ) == "u_27") collEn = 27;
		else if(histoName.substr( histoName.length() - 4 ) == "u_39") collEn = 39;
		else if(histoName.substr( histoName.length() - 4 ) == "62.4") collEn = 62.4;
	       	else if(histoName.substr( histoName.length() - 4 ) == "_130") collEn = 130;
		else if(histoName.substr( histoName.length() - 4 ) == "_200") collEn = 200;
		//get first three characters of particle name from histoName:
		string particleID = histoName.substr(6,3);// starting position in array:6, 3 chars total
		string centrality = histoName.substr(4,1);// starting position in array:4, 1 char total

		//------------ Assign mass & type to particle -----------------//
		Double_t mass; // in GeV

		// type Double_t instead of Int_t
		 //to use as argument in TF1 method SetParameters()
		Double_t type;// 0 for mesons, -1 for baryons, 1 for antibaryons
		if	(particleID=="pi-"||particleID=="pi+")
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
		else if (particleID == "ome")
		                {mass = 1.6725; type = -1;}
		else {cout << "Check particle: "
				<< particleID<<endl;return 1;}

		Double_t* integralDataPtr;
		// TODO : need to fix what function this should be:
		integralDataPtr = getIntegralsAndErrorsFromData(h,type,mass);
					// ^ method verified!!!
	


		//------------- Begin BGBW fit --------------------------//
		//FIXME when you delete, use the "C"? option to delete all the inherited objects as well
		if (	histoName == "cent7_ka-_Au+Au_7.7"
			|| 	histoName == "cent7_ka-_Au+Au_11.5"
			||	histoName == "cent7_pi+_Au+Au_7.7"
			||	histoName == "cent4_pi-_Au+Au_19.6"
			||	histoName == "cent5_ka+_Au+Au_27"
			||	histoName == "cent5_ka-_Au+Au_7.7"
			||	histoName == "cent6_pi+_Au+Au_11.5"
			||	histoName == "cent3_pi-_Au+Au_7.7"
			||	histoName == "cent4_pi-_Au+Au_7.7"
			||	histoName == "cent5_pi-_Au+Au_7.7"
			||	histoName == "cent7_pi-_Au+Au_7.7"
			||	histoName == "cent1_pbar_Au+Au_7.7"	// NOT POS-DEF
			||	histoName == "cent3_pbar_Au+Au_7.7"
			||	histoName == "cent4_pbar_Au+Au_7.7"
			||	histoName == "cent6_pbar_Au+Au_7.7"
			||	histoName == "cent7_pbar_Au+Au_7.7"
			||	histoName == "cent8_ka+_Au+Au_7.7"
			||	histoName == "cent8_ka-_Au+Au_7.7"
			||	histoName == "cent6_pi-_Au+Au_11.5"
			||	histoName == "cent0_pi+_Au+Au_11.5"
			||	histoName == "cent7_pi+_Au+Au_11.5"
			||	histoName == "cent8_proton_Au+Au_19.6"
			||	histoName == "cent5_proton_Au+Au_7.7"
			||	histoName == "cent6_pi+_Au+Au_27"
			||	histoName == "cent2_ka-_Au+Au_27"
			||	histoName == "cent3_ka+_Au+Au_27"
			||	histoName == "cent7_pbar_Au+Au_27"
			||	histoName == "cent8_pi+_Au+Au_39"
			||	histoName == "cent8_ka-_Au+Au_62.4"
			||	histoName == "cent8_ka+_Au+Au_62.4"
			||	histoName == "cent7_pi+_Au+Au_130"
			)
			{
			funcBGBW->SetParameters(mass,0.9,0.03,0.01,10000.,type);
			cout << "alternate init pars: 0.9,0.03,0.01,10000." << endl; //find final param pion //should look like average
			}

	
		else if(collEn == 62.4 &&( particleID =="pi-"||particleID=="pi+")){
			cout << "histoname is: " << histoName << endl;
			funcBGBW->SetParameters(mass,0.9,0.03,.01,10000.,type);
		}
		else{
			cout << "histoname is: " << histoName << endl;
			funcBGBW->SetParameters(mass,0.95,0.05,0.1,1000000.,type);
			//	funcBGBW2->SetParameters(mass,0.6,0.05,0.1,10000.,type);
			}
	
		funcBGBW->SetParNames("mass","beta (c)","temp","n","norm","type");
		funcBGBW->SetParLimits(1,0.5,0.999999999999999999999);//param 1
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
		funcBGBW2->SetLineColor(kBlue);

		//HAGEDORN
		if(particleID=="pro"){
	        HAGE->SetParameters(mass,1.,1.,5.,type);
		HAGE->SetParNames("mass","A","temp","n","type");
		HAGE->FixParameter(0,mass);// mass in GeV
		HAGE->FixParameter(4,type);
		HAGE->SetLineColor(kCyan+2);
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
		  funcBGBW->SetParLimits(1,0.0,0.99);//beta
		  funcBGBW2->SetParLimits(1,0.0,0.99);//beta
		  funcBGBW2->SetParLimits(2,.01,.2);//temp
		  funcBGBW2->SetParLimits(3,0.01,100);//n
		  HAGE->SetParLimits(3,.5,500000.); // norm
		  HAGE->SetParLimits(2,0.5,2000.); // temp
	
		ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(20000);
		TFitResultPtr r = h->Fit("getdNdpt","S","",0.00000000000001,10.);
		Double_t meanpt1= funcBGBW->GetHistogram()->GetMean();

		if(gMinuit->fLimset) cout<<"Histogram "<<h->GetName()<<" hits limit on BW1"<<endl; 
		
		TFitResultPtr l = h->Fit("getdNdpt2","S+","",0.00000000000001,10.);
	        //g->Fit("getdNdpt2","S","",0.00000000000001,10.);
		Double_t meanpt2 = funcBGBW2->GetHistogram()->GetMean();
		if(gMinuit->fLimset) cout<<"Histogram "<<h->GetName()<<" hits limit on BW2"<<endl;

		TFitResultPtr p = h->Fit("getdNdptHAGE","S+","",0.000000000001,10.);
		Double_t meanpt3= HAGE->GetHistogram()->GetMean();
		if(gMinuit->fLimset) cout<<"Histogram "<<h->GetName()<<" hits limit on Hagedorn"<<endl;
	
			
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

		
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtr;
		Int_t Npart;
		Int_t NpartErr;
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
	
	
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

		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtr2;
		Int_t Npart2;
		Int_t NpartErr2;
		NpartAndArrPtr2 = getNpartAndErr(collEn,centrality);
		Npart2 = *(NpartAndArrPtr2+0);
		NpartErr2 = *(NpartAndArrPtr2+1);
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		//-- end- output results to file------------------------
	
	
		
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

	
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtrH;
		Int_t NpartH;
		Int_t NpartErrH;
		NpartAndArrPtrH = getNpartAndErr(collEn,centrality);
		NpartH = *(NpartAndArrPtrH+0);
		NpartErrH = *(NpartAndArrPtrH+1);
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
			//-- end- output results to file------------------------
	
	
		
		Double_t chi2BGBWH = HAGE->GetChisquare();
		Double_t nDFBGBW2H = HAGE->GetNDF();
		Double_t p2H = HAGE->GetParameter(2);
		Double_t e2H = HAGE->GetParError(2);

	
		// Double_t per1 = 0;
		// Double_t per2 = 0;
		// Double_t per3 = 0;
		// per1 = Abs(((dETdEtaTotal-dETdEtaTotal2)/dETdEtaTotal)*100);
		// per2 = Abs(((dETdEtaTotal-dETdEtaTotalH)/dETdEtaTotal)*100);
		// per3 = Abs(((dETdEtaTotal2-dETdEtaTotalH)/dETdEtaTotalH)*100);
		// if(per1 >= 10){
		// avgET=(dETdEtaTotal2+dETdEtaTotal+dETdEtaTotalH)/3.0;
		// avgET_err=(dETdEtaTErrH+dETdEtaTErr+dETdEtaTErr2)/3.0;
		// avgN=((dETdEtaTotalH-dETdEta_dH)+(dETdEtaTotal2-dETdEta_d2)+(dETdEtaTotal-dETdEta_d))/3.0;
		// avg_err=(dETdyLErrH+dETdyRErrH+dETdyRErr+dETdyLErr+dETdyLErr2+dETdyRErr2)/6.0;
	 	// avgNpart=(NpartH+Npart+Npart2)/3.0;;
		// avgNpart_err=(NpartErr+NpartErr2+NpartErrH)/3.0;
		// }
		// else if(per2 >=10){
		// }
		// else if(per3 >= 10){
		// }
		// else{
		
	TString hisst = h->GetName();
	//	c1->cd();
	//	gPad->SetLogy();
	c1->Update();
	c1->cd();
	Double_t yloc = funcBGBW->GetHistogram()->GetMaximum();
	yloc = yloc/10.0;
	
	TF1* hj = new TF1();
	hj =dETdyIntegrandFunc ;
	hj->DrawCopy();
	hj->Draw();
	hj->GetHistogram()->GetXaxis()->SetRangeUser(0.,3.);
	hj->GetHistogram()->GetYaxis()->SetRangeUser(0.,(11.0*yloc));
	hj->GetHistogram()->SetXTitle(xlabel);
	hj->GetHistogram()->SetYTitle(ylabel);
	hj->SetTitle(hisst);
	hj->SetLineColor(kWhite);
	h->Draw("same");
	h->GetXaxis()->SetRangeUser(0.,10.);
	c1->Update();
	
	Double_t diffBW = TMath::Abs((dETdEtaTotalH)-dETdEtaTotal)/(dETdEtaTotalH);
	Double_t diffBW2 = TMath::Abs((dETdEtaTotal+dETdEtaTotalH)/2.0-dETdEtaTotal2)/(dETdEtaTotal+dETdEtaTotalH)*2.0;
	Double_t diffH = TMath::Abs((dETdEtaTotal)-dETdEtaTotalH)/(dETdEtaTotal);
	cout<<breakOutForTesting<<" : "<<h->GetName()<<": BW: Chi^2: "<<chi2BGBW<<" : NDF: "<<nDFBGBW<<" : Chi^2/NDF: "<<chi2BGBW/nDFBGBW<<" : Diff : "<<diffBW<<endl;
	//cout<<breakOutForTesting<<" : "<<h->GetName()<<": BW2: Chi^2: "<<chi2BGBW2<<" : NDF: "<<nDFBGBW2<<" : Chi^2/NDF: "<<chi2BGBW2/nDFBGBW2<<" : Diff : "<<diffBW<<endl;
	cout<<breakOutForTesting<<" : "<<h->GetName()<<": Hagedorn: Chi^2: "<<chi2BGBWH<<" : NDF: "<<nDFBGBW2H<<" : Chi^2/NDF: "<<chi2BGBWH/nDFBGBW2H<<" : Diff : "<<diffBW<<endl;	

		avgET=(dETdEtaTotal+dETdEtaTotalH)/2.0;
		avgET_err=(dETdEtaTErrH+dETdEtaTErr)/2.0;//averages the error in the points/fit.  Probably OK, especially since it looks like the fits actually pretty much agree and have small uncertainties
		Double_t avgETfitErr=TMath::Abs(dETdEtaTotal-dETdEtaTotalH)/2.0;
		avgN=(dNdEtaTotalH +dNdEtaTotal)/2.0;
		avgN_err=(dNdEtaTErrH +dNdEtaTErr)/2.0;
		//This part doesn't really mean anything since the Nparts are coming from the same place...
	 	avgNpart=(NpartH+Npart+Npart2)/3.0;;
		avgNpart_err=(NpartErr+NpartErr2+NpartErrH)/3.0;
		
		avg <<collEn << "\t"
		    << particleID << "\t"
		    << centrality << "\t"
		    << avgET <<  "\t"
		    << avgET_err <<  "\t"
		    << avgETfitErr <<  "\t"
		    << avgN <<  "\t"
		    << avgN_err <<  "\t"
		    << avgNpart <<  "\t"
		    << avgNpart_err <<  "\n";
	string imgPathAndName = "./fittedPlots55/"+histoName+".png";
				//c1 -> SaveAs("./fittedPlots/trial1.png");
		TImage *png = TImage::Create();// FIXME try to use canvas method instead of png object
		png->FromPad(c1);
		const char* imgPathAndNameConstCharPtr = imgPathAndName.c_str();
		png->WriteImage(imgPathAndNameConstCharPtr);
		mikey->DeleteBuffer();// works!
	
		if(breakOutForTesting>=stop) break;

		gSystem->ProcessEvents();
		delete h;
		delete funcBGBW;
		delete dETdEtaIntegrandFunc;
		delete dETdyIntegrandFunc;
		delete funcBGBW2;
		delete dETdEtaIntegrandFunc2;
		delete dETdyIntegrandFunc2;
		delete HAGE;
		delete dETdEtaIntegrandFuncHAGE;
		delete dETdyIntegrandFuncHAGE;
		delete c1;
	}
	gObjectTable->Print();
	delete myFile;
	avg.close();
return 0;
}
