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
Double_t getdNdptEXPO(Double_t* pT, Double_t* params);
Double_t getdETdEtaIntegrandEXPO(Double_t* myPt, Double_t* par);
Double_t getdETdyIntegrandEXPO(Double_t* myPt, Double_t* par);
Double_t getdNdEtaIntegrandEXPO(Double_t* myPt, Double_t* par);
Double_t getdNdyIntegrandEXPO(Double_t* myPt, Double_t* par);
//---------------------expo2
Double_t getdNdptEXPO2(Double_t* pT, Double_t* params);
Double_t getdETdEtaIntegrandEXPO2(Double_t* myPt, Double_t* par);
Double_t getdETdyIntegrandEXPO2(Double_t* myPt, Double_t* par);
Double_t getdNdEtaIntegrandEXPO2(Double_t* myPt, Double_t* par);
Double_t getdNdyIntegrandEXPO2(Double_t* myPt, Double_t* par);




// main function:
int fitcompare14v4(){
	std::ofstream datFile ("compfitResults.dat", std::ofstream::app);
	/*	datFile << "FIT"<< "\t" << "CollEn"<< "\t"
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
	*/
	TFile* myFile = new TFile("ALLSTAR.root");
	TIter next(myFile->GetListOfKeys());
	TKey* mikey;
	TH1D* h;
	TH1D* h1;
	TH1D* h2;
	TH1D* h3;
	TH1D* h4;
	
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



	//exponential
	TF1* EXPO;
	TF1* dETdEtaIntegrandFuncEXPO;
	TF1* dETdyIntegrandFuncEXPO;
	TF1* dNdEtaIntegrandFuncEXPO;
	TF1* dNdyIntegrandFuncEXPO;

	//expontial soren
	TF1* EXPO2;
	TF1* dETdEtaIntegrandFuncEXPO2;
	TF1* dETdyIntegrandFuncEXPO2;
	TF1* dNdEtaIntegrandFuncEXPO2;
	TF1* dNdyIntegrandFuncEXPO2;



	
	int breakOutForTesting =0;
	int stop =476; // breakOut after this many iterations (if achieved); default: 140
	cout << "Flag" << endl;
	while((mikey=(TKey*)next())){
	  breakOutForTesting++;
		if (breakOutForTesting<475) continue;// 140 histograms already analyzed
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

		EXPO = new TF1("getdNdptEXPO", getdNdptEXPO,0.000000000001,10.,4);

		EXPO2 = new TF1("getdNdptEXPO2", getdNdptEXPO2,0.000000000001,10.,5);



		
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



		
		dETdEtaIntegrandFuncEXPO = new TF1("dETdEtaIntegrandEXPO",
									getdETdEtaIntegrandEXPO,
									0, 10, 4 );// function goes from 0 to 10
										// and has 6 parameters"
										// mass, pt,
		dETdyIntegrandFuncEXPO = new TF1("dETdyIntegrandEXPO",
								  getdETdyIntegrandEXPO,
								  0,10,4);
		dNdEtaIntegrandFuncEXPO = new TF1("dETdyIntegrandEXPO",
								  getdNdEtaIntegrandEXPO,
								  0,10,4); // 5 parameters:m, 6th is type*0
		dNdyIntegrandFuncEXPO = new TF1("dETdyIntegrandEXPO",
								  getdNdEtaIntegrandEXPO,
								  0,10,4);// 5 parameters:m, 6th is type*0

		

		dETdEtaIntegrandFuncEXPO2 = new TF1("dETdEtaIntegrandEXPO2",
									getdETdEtaIntegrandEXPO2,
									0, 10, 5 );// function goes from 0 to 10
										// and has 6 parameters"
										// mass, pt,
		dETdyIntegrandFuncEXPO2 = new TF1("dETdyIntegrandEXPO2",
								  getdETdyIntegrandEXPO2,
								  0,10,5);
		dNdEtaIntegrandFuncEXPO2 = new TF1("dETdyIntegrandEXPO2",
								  getdNdEtaIntegrandEXPO2,
								  0,10,5); // 5 parameters:m, 6th is type*0
		dNdyIntegrandFuncEXPO2 = new TF1("dETdyIntegrandEXPO2",
								  getdNdEtaIntegrandEXPO2,
								  0,10,5);// 5 parameters:m, 6th is type*0



		//gPad->SetLogy();
		//gStyle->SetOptFit(1111);// display fit parameters; customizable
		//	gStyle->SetOptDate();// display date (at bottom left)
		gROOT-> SetBatch(kTRUE);// save canvases without displaying them
		c1->Update();

		// read histogram object for current iteration of key:
		h = (TH1D*)mikey->ReadObj();
		h1 = (TH1D*)mikey->ReadObj();
		h2 = (TH1D*)mikey->ReadObj();
		h3 = (TH1D*)mikey->ReadObj();
		g = (TH1D*)mikey->ReadObj();
		
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
		else {cout << "Check particle: "
				<< particleID<<endl;return 1;}

		Double_t* integralDataPtr;
		// TODO : need to fix what function this should be:
		integralDataPtr = getIntegralsAndErrorsFromData(h,type,mass);
					// ^ method verified!!!
		/*
		Double_t* integralDataPtr2;
		integralDataPtr2 = getIntegralsAndErrorsFromData(h1,type,mass);
		Double_t* integralDataPtr3;
		integralDataPtr3 = getIntegralsAndErrorsFromData(h2,type,mass);
		Double_t* integralDataPtr4;
		integralDataPtr4 = getIntegralsAndErrorsFromData(h3,type,mass);
		Double_t* integralDataPtr5;
		integralDataPtr5 = getIntegralsAndErrorsFromData(g,type,mass);
		*/


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
		//EXPOS
		if(particleID == "pi+"||particleID == "pi-"){
		 EXPO->SetParameters(10000.,.01,mass,type);
		EXPO->SetParNames("Ae","Be","mass","type");
		//EXPO->SetParLimits(0,300,1000);
		//EXPO->SetParLimits(1,.01,1.);
		EXPO->SetLineColor(kBlack);
		EXPO->FixParameter(3,type);
		EXPO->FixParameter(2,mass);
		EXPO2->SetParameters(1.,1.,1.,mass,type);
		EXPO2->SetParNames("A2","B2","C2","mass","type");
		//	EXPO2->SetParLimits(0,.1,1);
		//EXPO2->SetParLimits(1,-4,0);
		//EXPO2->SetParLimits(2,.3,2);
		EXPO2->SetLineColor(kViolet);
		EXPO2->FixParameter(4,type);
		EXPO2->FixParameter(3,mass);
		}
		else if(particleID=="ka-"||particleID == "ka+"){
		 EXPO->SetParameters(.1,.1,mass,type);
		EXPO->SetParNames("Ae","Be","mass","type");
		//EXPO->SetParLimits(0,400,500);
		//EXPO->SetParLimits(1,.01,1);
		EXPO->SetLineColor(kBlack);
		EXPO->FixParameter(3,type);
		EXPO->FixParameter(2,mass);
		
		EXPO2->SetParameters(.01,0.01,0.01,mass,type);
		EXPO2->SetParNames("A2","B2","C2","mass","type");
		//EXPO2->SetParLimits(0,.1,1);
		//EXPO2->SetParLimits(1,-4,0);
		//EXPO2->SetParLimits(2,.3,2);
		EXPO2->SetLineColor(kViolet);
		EXPO2->FixParameter(4,type);
		EXPO2->FixParameter(3,mass);
		}
		
		else{
		EXPO->SetParameters(.1,.1,mass,type);
		EXPO->SetParNames("Ae","Be","mass","type");
		//EXPO->SetParLimits(0,400,500);
		//EXPO->SetParLimits(1,.01,1);
		EXPO->SetLineColor(kBlack);
		EXPO->FixParameter(3,type);
		EXPO->FixParameter(2,mass);
		
		EXPO2->SetParameters(0.01,0.01,0.01,mass,type);
		EXPO2->SetParNames("A2","B2","C2","mass","type");
		//	EXPO2->SetParLimits(0,.1,1);
		//EXPO2->SetParLimits(1,-4,0);
		//EXPO2->SetParLimits(2,.3,2);
		EXPO2->SetLineColor(kViolet);
		EXPO2->FixParameter(4,type);
		EXPO2->FixParameter(3,mass);
		
		}

		
		ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(20000);
		TFitResultPtr r = h->Fit("getdNdpt","S","",0.00000000000001,10.);
		Double_t meanpt1= funcBGBW->GetHistogram()->GetMean();
		
		TFitResultPtr l = h->Fit("getdNdpt2","S+","",0.00000000000001,10.);
	        //g->Fit("getdNdpt2","S","",0.00000000000001,10.);
		Double_t meanpt2 = funcBGBW2->GetHistogram()->GetMean();

		TFitResultPtr p = h->Fit("getdNdptHAGE","S+","",0.000000000001,10.);
		Double_t meanpt3= HAGE->GetHistogram()->GetMean();
		//EXPO
		TFitResultPtr v = h->Fit("getdNdptEXPO","S+","M",0.000000000001,10.);
		Double_t meanpt4= EXPO->GetHistogram()->GetMean();
			
		
		TFitResultPtr w = h->Fit("getdNdptEXPO2","S+","M",0.000000000001,10.);
		Double_t meanpt5= EXPO2->GetHistogram()->GetMean();

		
		Double_t chi2Prob = r->Prob();
		Double_t chi2prob2 = l->Prob();
		Double_t chi3prob3 = p->Prob();
		Double_t chi4prob4 = v->Prob();
		Double_t chi5prob5 = w->Prob();

		
		cout << "chi-sq prob: " << chi2Prob << "\t" << chi2prob2 << "\t" << chi3prob3 << "\t" << chi4prob4 << "\t" << chi5prob5 << endl;
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
		
		Double_t Ae = EXPO->GetParameter(0);
		Double_t Be = EXPO->GetParameter(1);
		Double_t AeErr = EXPO->GetParError(0);
		Double_t BeErr = EXPO->GetParError(1);
		
		//---------------------------------------------------expo2---------------
		Double_t A2 = EXPO2->GetParameter(0);
		Double_t B2 = EXPO2->GetParameter(1);
		Double_t C2 = EXPO2->GetParameter(2);
		Double_t A2Err = EXPO2->GetParError(0);
		Double_t B2Err = EXPO2->GetParError(1);
		Double_t C2Err = EXPO2->GetParError(2);




		
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
		NpartAndArrPtr = getNpartAndErr(collEn,centrality);
		Npart = *(NpartAndArrPtr+0);
		NpartErr = *(NpartAndArrPtr+1);
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
		NpartAndArrPtr2 = getNpartAndErr(collEn,centrality);
		Npart2 = *(NpartAndArrPtr2+0);
		NpartErr2 = *(NpartAndArrPtr2+1);
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
		NpartAndArrPtrH = getNpartAndErr(collEn,centrality);
		NpartH = *(NpartAndArrPtrH+0);
		NpartErrH = *(NpartAndArrPtrH+1);
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


		EXPO			 	-> SetParameters(Ae,Be,mass,type);
		dETdEtaIntegrandFuncEXPO 	-> SetParameters(Ae,Be,mass,type);
		dETdEtaIntegrandFuncEXPO	-> FixParameter(3,type);
		dETdEtaIntegrandFuncEXPO	-> FixParameter(2,mass);
		dETdyIntegrandFuncEXPO 		-> SetParameters(Ae,Be,mass,type);
		dETdyIntegrandFuncEXPO		-> FixParameter(3,type);
		dETdyIntegrandFuncEXPO		-> FixParameter(2,mass);
		dNdEtaIntegrandFuncEXPO 	-> SetParameters(Ae,Be,mass,type);
		dNdEtaIntegrandFuncEXPO		-> FixParameter(2,mass);
		dNdEtaIntegrandFuncEXPO		-> FixParameter(3,type);
		dNdyIntegrandFuncEXPO		-> SetParameters(Ae,Be,mass,type);
		dNdyIntegrandFuncEXPO		-> FixParameter(2,mass);
		dNdyIntegrandFuncEXPO		-> FixParameter(3,type);

		Int_t totBinsE 	= h->GetNbinsX();
		Int_t binx1E 	= 0;
		Int_t binx2E 	= totBins+1;

		Double_t leftCutE 	= h->GetXaxis()->GetBinLowEdge(binx1E+2);
		Double_t rightCutE 	= h->GetXaxis()->GetBinUpEdge(binx2E-1);

		Double_t dETdEtaLeftE 	= dETdEtaIntegrandFuncEXPO -> Integral(0.,leftCutE);
		Double_t dETdEtaRightE 	= dETdEtaIntegrandFuncEXPO -> Integral(rightCutE,10.);
		Double_t dETdyLeftE 		= dETdyIntegrandFuncEXPO -> Integral(0.,leftCutE);
		Double_t dETdyRightE 	= dETdyIntegrandFuncEXPO -> Integral(rightCutE,10.);
		Double_t dNdEtaLeftE 	= dNdEtaIntegrandFuncEXPO -> Integral(0.,leftCutE);
		Double_t dNdEtaRightE 	= dNdEtaIntegrandFuncEXPO -> Integral(rightCutE,10.);
		Double_t dNdyLeftE 		= dNdyIntegrandFuncEXPO -> Integral(0.,leftCutE);
		Double_t dNdyRightE 		= dNdyIntegrandFuncEXPO -> Integral(rightCutE,10.);
		// Errors:
		Double_t dETdEtaLErrE	=
		dETdEtaIntegrandFuncEXPO->IntegralError(0.,leftCutE,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdEtaRErrE	=
		dETdEtaIntegrandFuncEXPO->IntegralError(rightCutE,10.,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyLErrE	=
		dETdyIntegrandFuncEXPO->IntegralError(0.,leftCutE,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyRErrE	=
		dETdyIntegrandFuncEXPO->IntegralError(rightCutE,10.,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaLErrE	=
		dNdEtaIntegrandFuncEXPO->IntegralError(0.,leftCutE,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaRErrE	=
		dETdEtaIntegrandFuncEXPO->IntegralError(rightCutE,10.,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyLErrE	=
		dNdyIntegrandFuncEXPO->IntegralError(0.,leftCutE,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyRErrE	=
		dNdyIntegrandFuncEXPO->IntegralError(rightCutE,10.,
								v->GetParams(),
								v->GetCovarianceMatrix().GetMatrixArray());

		Double_t dETdEta_dE= *(integralDataPtr+0);
		Double_t dETdEta_d_errE = *(integralDataPtr+1);
		Double_t dETdEtaTotalE = dETdEtaLeftE+dETdEta_dE+dETdEtaRightE;
		Double_t dETdEtaTErrE = dETdEtaLErrE+dETdEta_d_errE+dETdEtaRErrE;

		Double_t dETdy_dE = *(integralDataPtr+2);
		Double_t dETdy_d_errE = *(integralDataPtr+3);
		Double_t dETdyTotalE = dETdyLeftE+dETdy_dE+dETdyRightE;
		Double_t dETdyTErrE = dETdyLErrE+dETdy_d_errE+dETdyRErrE;

		Double_t dNdEta_dE = *(integralDataPtr+4);
		Double_t dNdEta_d_errE = *(integralDataPtr+5);
		Double_t dNdEtaTotalE = dNdEtaLeftE+dNdEta_dE+dNdEtaRightE;
		Double_t dNdEtaTErrE = dNdEtaLErrE+dNdEta_d_errE+dNdEtaRErrE;

		Double_t dNdy_dE = *(integralDataPtr+6);
		Double_t dNdy_d_errE = *(integralDataPtr+7);
		Double_t dNdyTotalE = dNdyLeftE+dNdy_dE+dNdyRightE;
		Double_t dNdyTErrE = dNdyLErrE+dNdy_d_errE+dNdyRErrE;

		cout <<"Integral from data for histo "<<breakOutForTesting+1<<": "<<*(integralDataPtr+0)<<endl;// 357.633 for pi minus cent 0
		cout<<"-----------------------------------"<<endl;
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtrE;
		Int_t NpartE;
		Int_t NpartErrE;
		NpartAndArrPtrE = getNpartAndErr(collEn,centrality);
		NpartE = *(NpartAndArrPtrE+0);
		NpartErrE = *(NpartAndArrPtrE+1);
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		datFile << "ex1\t"<<collEn << "\t"
				<< particleID << "\t"
				<< centrality << "\t"
				<< mass << "\t"
				<< Ae <<"\t"
				<< AeErr <<"\t"
				<< Be <<"\t"
				<< BeErr <<"\t"
				<< dETdEta_dE << "\t" //dETdEta_d
				<< dETdEta_d_errE<< "\t" //dETdEta_d_err
				<< dETdEtaLeftE << "\t"
				<< dETdEtaLErrE << "\t"
				<< dETdEtaRightE << "\t"
				<< dETdEtaRErrE << "\t"
				<< dETdEtaTotalE<< "\t" // dETdEtaTotal
				<< dETdEtaTErrE << "\t"
				<< dETdy_dE << "\t" //dETdy_d
				<< dETdy_d_errE<< "\t" //dETdy_d_err
				<< dETdyLeftE<< "\t"
				<< dETdyLErrE << "\t"
				<< dETdyRightE << "\t"
				<< dETdyRErrE << "\t"
				<< dETdyTotalE<< "\t" // dETdyTotal
				<< dETdyTErrE << "\t"
				<< dNdEta_dE << "\t" //dNdEta_d
				<< dNdEta_d_errE<< "\t" //dNdEta_d_err
				<< dNdEtaLeftE << "\t"
				<< dNdEtaLErrE << "\t"
				<< dNdEtaRightE << "\t"
				<< dNdEtaRErrE << "\t"
				<< dNdEtaTotalE << "\t" // dNdEtaTotal
				<< dNdEtaTErrE << "\t"
				<< dNdy_dE << "\t" //dNdy_d
				<< dNdy_d_errE<< "\t" //dNdy_d_err
				<< dNdyLeftE << "\t"
				<< dNdyLErrE << "\t"
				<< dNdyRightE << "\t"
				<< dNdyRErrE << "\t"
				<< dNdyTotalE << "\t" // dNdyTotal
				<< dNdyTErrE << "\t"
				<< NpartE << "\t"
				<< NpartErrE << "\n";

		//-- end- output results to file------------------------
		c1->Update();
	
		
		Double_t chi2BGBWE = EXPO->GetChisquare();
		Double_t nDFBGBW2E = EXPO->GetNDF();
		Double_t p2E = EXPO->GetParameter(2);
		Double_t e2E = EXPO->GetParError(2);
	
		
		EXPO2			 	-> SetParameters(A2,B2,C2,mass,type);
		dETdEtaIntegrandFuncEXPO2 	-> SetParameters(A2,B2,C2,mass,type);
		dETdEtaIntegrandFuncEXPO2	-> FixParameter(4,type);
		dETdEtaIntegrandFuncEXPO2	-> FixParameter(3,mass);
		dETdyIntegrandFuncEXPO2 		-> SetParameters(A2,B2,C2,mass,type);
		dETdyIntegrandFuncEXPO2		-> FixParameter(4,type);
		dETdyIntegrandFuncEXPO2		-> FixParameter(3,mass);
		dNdEtaIntegrandFuncEXPO2 	-> SetParameters(A2,B2,C2,mass,type);
		dNdEtaIntegrandFuncEXPO2	-> FixParameter(3,mass);
		dNdEtaIntegrandFuncEXPO2		-> FixParameter(4,type);
		dNdyIntegrandFuncEXPO2		-> SetParameters(A2,B2,C2,mass,type);
		dNdyIntegrandFuncEXPO2		-> FixParameter(3,mass);
		dNdyIntegrandFuncEXPO2		-> FixParameter(4,type);

		Int_t totBinsE2 	= h->GetNbinsX();
		Int_t binx1E2 	= 0;
		Int_t binx2E2 	= totBins+1;

		Double_t leftCutE2 	= h->GetXaxis()->GetBinLowEdge(binx1E2+2);
		Double_t rightCutE2 	= h->GetXaxis()->GetBinUpEdge(binx2E2-1);

		Double_t dETdEtaLeftE2 	= dETdEtaIntegrandFuncEXPO2 -> Integral(0.,leftCutE2);
		Double_t dETdEtaRightE2 	= dETdEtaIntegrandFuncEXPO2 -> Integral(rightCutE2,10.);
		Double_t dETdyLeftE2 		= dETdyIntegrandFuncEXPO2 -> Integral(0.,leftCutE2);
		Double_t dETdyRightE2 	= dETdyIntegrandFuncEXPO2 -> Integral(rightCutE2,10.);
		Double_t dNdEtaLeftE2	= dNdEtaIntegrandFuncEXPO2 -> Integral(0.,leftCutE2);
		Double_t dNdEtaRightE2 	= dNdEtaIntegrandFuncEXPO2 -> Integral(rightCutE2,10.);
		Double_t dNdyLeftE2 		= dNdyIntegrandFuncEXPO2 -> Integral(0.,leftCutE2);
		Double_t dNdyRightE2 		= dNdyIntegrandFuncEXPO2 -> Integral(rightCutE2,10.);
		// Errors:
		Double_t dETdEtaLErrE2	=
		dETdEtaIntegrandFuncEXPO2->IntegralError(0.,leftCutE2,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdEtaRErrE2	=
		dETdEtaIntegrandFuncEXPO2->IntegralError(rightCutE2,10.,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyLErrE2	=
		dETdyIntegrandFuncEXPO2->IntegralError(0.,leftCutE2,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dETdyRErrE2	=
		dETdyIntegrandFuncEXPO2->IntegralError(rightCutE2,10.,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaLErrE2	=
		dNdEtaIntegrandFuncEXPO2->IntegralError(0.,leftCutE2,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdEtaRErrE2	=
		dETdEtaIntegrandFuncEXPO2->IntegralError(rightCutE2,10.,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyLErrE2	=
		dNdyIntegrandFuncEXPO2->IntegralError(0.,leftCutE2,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());
		Double_t dNdyRErrE2	=
		dNdyIntegrandFuncEXPO2->IntegralError(rightCutE2,10.,
								w->GetParams(),
								w->GetCovarianceMatrix().GetMatrixArray());

		Double_t dETdEta_dE2= *(integralDataPtr+0);
		Double_t dETdEta_d_errE2 = *(integralDataPtr+1);
		Double_t dETdEtaTotalE2 = dETdEtaLeftE2+dETdEta_dE2+dETdEtaRightE2;
		Double_t dETdEtaTErrE2 = dETdEtaLErrE2+dETdEta_d_errE2+dETdEtaRErrE2;

		Double_t dETdy_dE2 = *(integralDataPtr+2);
		Double_t dETdy_d_errE2 = *(integralDataPtr+3);
		Double_t dETdyTotalE2 = dETdyLeftE2+dETdy_dE2+dETdyRightE2;
		Double_t dETdyTErrE2 = dETdyLErrE2+dETdy_d_errE2+dETdyRErrE2;

		Double_t dNdEta_dE2 = *(integralDataPtr+4);
		Double_t dNdEta_d_errE2 = *(integralDataPtr+5);
		Double_t dNdEtaTotalE2 = dNdEtaLeftE2+dNdEta_dE2+dNdEtaRightE2;
		Double_t dNdEtaTErrE2 = dNdEtaLErrE2+dNdEta_d_errE2+dNdEtaRErrE2;

		Double_t dNdy_dE2 = *(integralDataPtr+6);
		Double_t dNdy_d_errE2 = *(integralDataPtr+7);
		Double_t dNdyTotalE2 = dNdyLeftE2+dNdy_dE2+dNdyRightE2;
		Double_t dNdyTErrE2 = dNdyLErrE2+dNdy_d_errE2+dNdyRErrE2;

		cout <<"Integral from data for histo "<<breakOutForTesting+1<<": "<<*(integralDataPtr+0)<<endl;// 357.633 for pi minus cent 0
		cout<<"-----------------------------------"<<endl;
		//------ end Find integrals left and right of data points ----//
		//------ begin - assign Npart and errors from BES paper -----//
		Int_t* NpartAndArrPtrE2;
		Int_t NpartE2;
		Int_t NpartErrE2;
		NpartAndArrPtrE2 = getNpartAndErr(collEn,centrality);
		NpartE2 = *(NpartAndArrPtrE2+0);
		NpartErrE2 = *(NpartAndArrPtrE2+1);
		//------ end - assign Npart and errors from BES paper -------//
		//-- Output results to file-----------------------------
		datFile << "ex2\t"<<collEn << "\t"
				<< particleID << "\t"
				<< centrality << "\t"
				<< mass << "\t"
				<< A2 <<"\t"
				<< A2Err <<"\t"
				<< B2 <<"\t"
				<< B2Err <<"\t"
			        << C2 << "\t"
			        <<C2Err<< "\t"
				<< dETdEta_dE2 << "\t" //dETdEta_d
				<< dETdEta_d_errE2<< "\t" //dETdEta_d_err
				<< dETdEtaLeftE2 << "\t"
				<< dETdEtaLErrE2 << "\t"
				<< dETdEtaRightE2 << "\t"
				<< dETdEtaRErrE2 << "\t"
				<< dETdEtaTotalE2<< "\t" // dETdEtaTotal
				<< dETdEtaTErrE2 << "\t"
				<< dETdy_dE2 << "\t" //dETdy_d
				<< dETdy_d_errE2<< "\t" //dETdy_d_err
				<< dETdyLeftE2<< "\t"
				<< dETdyLErrE2 << "\t"
				<< dETdyRightE2 << "\t"
				<< dETdyRErrE2 << "\t"
				<< dETdyTotalE2<< "\t" // dETdyTotal
				<< dETdyTErrE2 << "\t"
				<< dNdEta_dE2 << "\t" //dNdEta_d
				<< dNdEta_d_errE2<< "\t" //dNdEta_d_err
				<< dNdEtaLeftE2 << "\t"
				<< dNdEtaLErrE2 << "\t"
				<< dNdEtaRightE2 << "\t"
				<< dNdEtaRErrE2 << "\t"
				<< dNdEtaTotalE2 << "\t" // dNdEtaTotal
				<< dNdEtaTErrE2 << "\t"
				<< dNdy_dE2 << "\t" //dNdy_d
				<< dNdy_d_errE2<< "\t" //dNdy_d_err
				<< dNdyLeftE2 << "\t"
				<< dNdyLErrE2 << "\t"
				<< dNdyRightE2 << "\t"
				<< dNdyRErrE2 << "\t"
				<< dNdyTotalE2 << "\t" // dNdyTotal
				<< dNdyTErrE2 << "\t"
				<< NpartE2 << "\t"
				<< NpartErrE2 << "\n";

		//-- end- output results to file------------------------
		c1->Update();
	
		
		Double_t chi2BGBWE2 = EXPO2->GetChisquare();
		Double_t nDFBGBW2E2 = EXPO2->GetNDF();
		Double_t p2E2 = EXPO2->GetParameter(2);
		Double_t e2E2 = EXPO2->GetParError(2);
	
		TString b1;
		TString b2;
		TString b3;
		TString b4;
		TString b5;
		TString b6;
	        TString b7;
		TString b8;
		TString b9;
		TString b10;


		std::ostringstream streamObj1;
		std::ostringstream streamObj2;
		std::ostringstream streamObj3;
		std::ostringstream streamObj4;
		std::ostringstream streamObj5;
		std::ostringstream streamObj6;
		std::ostringstream streamObj7;
		std::ostringstream streamObj8;
		std::ostringstream streamObj9;
		std::ostringstream streamObj10;
		std::ostringstream streamObj11;
		std::ostringstream streamObj12;
		std::ostringstream streamObj13;
		std::ostringstream streamObj14;
		std::ostringstream streamObj15;
		std::ostringstream streamObj16;
		std::ostringstream streamObj17;
		std::ostringstream streamObj18;
		std::ostringstream streamObj19;
		std::ostringstream streamObj20;
		std::ostringstream streamObj21;
		std::ostringstream streamObj22;
		std::ostringstream streamObj23;
		std::ostringstream streamObj24;
		std::ostringstream streamObj25;
		std::ostringstream streamObj26;
		std::ostringstream streamObj27;
		std::ostringstream streamObj28;
		std::ostringstream streamObj29;
		std::ostringstream streamObj30;
		std::ostringstream streamObj31;
		std::ostringstream streamObj32;
		std::ostringstream streamObj33;
	     
	
		std::ostringstream streamObj34;
		std::ostringstream streamObj35;
		std::ostringstream streamObj36;
		std::ostringstream streamObj37;
		std::ostringstream streamObj38;
		std::ostringstream streamObj39;
		std::ostringstream streamObj40;
		std::ostringstream streamObj41;
		std::ostringstream streamObj42;
		std::ostringstream streamObj43;
		std::ostringstream streamObj44;
		std::ostringstream streamObj45;
		std::ostringstream streamObj46;
		std::ostringstream streamObj47;
		std::ostringstream streamObj48;
		streamObj1 << std::fixed<<std::setprecision(3)<<dETdEtaTotal2;
		streamObj2 << std::fixed<<std::setprecision(3)<<dETdEtaTErr2; 
		streamObj3 << std::fixed<<std::setprecision(3)<<meanpt2;
		streamObj4 << std::fixed<<std::setprecision(3)<<dETdEtaTotal;
		streamObj5 << std::fixed<<std::setprecision(3)<<dETdEtaTErr;
		streamObj6 << std::fixed<<std::setprecision(3)<<meanpt1;
		streamObj7 << std::fixed<<std::setprecision(3)<<beta2;
		  streamObj8 << std::fixed<<std::setprecision(3)<<betaErr2;
		  streamObj9 << std::fixed<<std::setprecision(3)<<temp2;
		  streamObj10 << std::fixed<<std::setprecision(3)<<tempErr2;
		  streamObj11 << std::fixed<<std::setprecision(3)<<n2;
		  streamObj12 << std::fixed<<std::setprecision(3)<<nErr2;
		  streamObj13 << std::fixed<<std::setprecision(3)<<beta;
		  streamObj14 << std::fixed<<std::setprecision(3)<<betaErr;
		  streamObj15 << std::fixed<<std::setprecision(3)<<temp;
		  streamObj16 << std::fixed<<std::setprecision(3)<<tempErr;
		  streamObj17 << std::fixed<<std::setprecision(3)<<n;
		  streamObj18 << std::fixed<<std::setprecision(3)<<nErr;
		  streamObj19 << std::fixed<<std::setprecision(3)<<A;
		  streamObj20 << std::fixed<<std::setprecision(3)<<AErr;
		  streamObj21 << std::fixed<<std::setprecision(3)<<tempH;
		  streamObj22 << std::fixed<<std::setprecision(3)<<tempHErr;
		  streamObj23 << std::fixed<<std::setprecision(3)<<nH;
		  streamObj24 << std::fixed<<std::setprecision(3)<<nHErr;
		  streamObj25 << std::fixed<<std::setprecision(3)<<dETdEtaTotalH;
		  streamObj26 << std::fixed<<std::setprecision(3)<<dETdEtaTErrH;
		  streamObj27 << std::fixed<<std::setprecision(3)<<meanpt3;
		  streamObj28 << std::fixed<<std::setprecision(3)<<Ae;
		  streamObj29 << std::fixed<<std::setprecision(3)<<AeErr;
		  streamObj30 << std::fixed<<std::setprecision(3)<<Be;
		  streamObj31 << std::fixed<<std::setprecision(3)<<BeErr;
		  streamObj32 << std::fixed<<std::setprecision(3)<<dETdEtaTotalE;
		  streamObj33 << std::fixed<<std::setprecision(3)<<dETdEtaTErrE;
		  streamObj34 << std::fixed<<std::setprecision(3)<<meanpt4;
		  streamObj35 << std::fixed<<std::setprecision(3)<<A2;
		  streamObj36 << std::fixed<<std::setprecision(3)<<A2Err;
		  streamObj37 << std::fixed<<std::setprecision(3)<<B2;
		  streamObj38 << std::fixed<<std::setprecision(3)<<B2Err;
		  streamObj39 << std::fixed<<std::setprecision(3)<<C2;
		  streamObj40 << std::fixed<<std::setprecision(3)<<C2Err;
		  streamObj41 << std::fixed<<std::setprecision(3)<<dETdEtaTotalE2;
		  streamObj42 << std::fixed<<std::setprecision(3)<<dETdEtaTErrE2;
		  streamObj43 << std::fixed<<std::setprecision(3)<<meanpt5;
		  streamObj44 << std::fixed<<std::setprecision(3)<<chi2Prob;
		  streamObj45 << std::fixed<<std::setprecision(3)<<chi2prob2;
		  streamObj46 << std::fixed<<std::setprecision(3)<<chi3prob3;
		  streamObj47 << std::fixed<<std::setprecision(3)<<chi4prob4;
		  streamObj48 << std::fixed<<std::setprecision(3)<<chi5prob5;

		  std::string var1 = streamObj1.str();
		  std::string var2 = streamObj2.str();
		  std::string var3 = streamObj3.str();
		  std::string var4 = streamObj4.str();
		  std::string var5 = streamObj5.str();
		  std::string var6 = streamObj6.str();
		  std::string var7 = streamObj7.str();
		  std::string var8 = streamObj8.str();
		  std::string var9 = streamObj9.str();
		  std::string var10 = streamObj10.str();
		  std::string var11 = streamObj11.str();
		  std::string var12 = streamObj12.str();
		  std::string var13 = streamObj13.str();
		  std::string var14 = streamObj14.str();
		  std::string var15 = streamObj15.str();
		  std::string var16 = streamObj16.str();
		  std::string var17 = streamObj17.str();
		  std::string var18 = streamObj18.str();
		  std::string var19 = streamObj19.str();
		  std::string var20 = streamObj20.str();
		  std::string var21 = streamObj21.str();
		  std::string var22 = streamObj22.str();
		  std::string var23 = streamObj23.str();
		  std::string var24 = streamObj24.str();
		  std::string var25 = streamObj25.str();
		  std::string var26 = streamObj26.str();
		  std::string var27 = streamObj27.str();
		  std::string var28 = streamObj28.str();
		  std::string var29 = streamObj29.str();
		  std::string var30 = streamObj30.str();
		  std::string var31 = streamObj31.str();
		  std::string var32 = streamObj32.str();
		  std::string var33 = streamObj33.str();
		  std::string var34 = streamObj34.str();
		  std::string var35 = streamObj35.str();
		  std::string var36 = streamObj36.str();
		  std::string var37 = streamObj37.str();
		  std::string var38 = streamObj38.str();
		  std::string var39 = streamObj39.str();
		  std::string var40 = streamObj40.str();
		  std::string var41 = streamObj41.str();
		  std::string var42 = streamObj42.str();
		  std::string var43 = streamObj43.str();
		  std::string var44 = streamObj44.str();
		  std::string var45 = streamObj45.str();
		  std::string var46 = streamObj46.str();
		  std::string var47 = streamObj47.str();
		  std::string var48 = streamObj48.str();
		  //streamObj44 << std::fixed<<std::setprecision(3)<<
		  //streamObj45 << std::fixed<<std::setprecision(3)<<
		//streamObj46 << std::fixed<<std::setprecision(3);
		//streamObj47 << std::fixed<<std::setprecision(3);
		//streamObj48 << std::fixed<<std::setprecision(3);
		//streamObj49 << std::fixed<<std::setprecision(3);
		//streamObj50 << std::fixed<<std::setprecision(3);
	
		
		  //	std::string strObj3 = streamObj3.str();
		
		  b4.Form("Total Et= %s#pm%s, Mean Pt= %s, #frac{#Chi^{2}}{ndf}=%s", var1.c_str(),var2.c_str(),var3.c_str(),var45.c_str());
		  b2.Form("Total Et= %s#pm%s, Mean Pt= %s, #frac{#Chi^{2}}{ndf}=%s",var4.c_str(),var5.c_str(),var6.c_str(),var44.c_str());
		b3.Form("b= %s#pm%s, t= %s#pm%s, n= %s#pm%s",var7.c_str(),var8.c_str(),var9.c_str(),var10.c_str(),var11.c_str(),var12.c_str());
		b1.Form("b= %s#pm%s, t= %s#pm%s, n= %s#pm%s",var13.c_str(),var14.c_str(),var15.c_str(),var16.c_str(),var17.c_str(),var18.c_str());
		b5.Form("a= %s#pm%s, T= %s#pm%s, n= %s#pm%s", var19.c_str(),var20.c_str(),var21.c_str(),var22.c_str(),var23.c_str(),var24.c_str());
		b6.Form("Total Et= %s#pm%s, Mean Pt= %s, #frac{#Chi^{2}}{ndf}=%s",var25.c_str(),var26.c_str(),var27.c_str(),var46.c_str());
		b7.Form("A= %s#pm%s, B= %s#pm%s", var28.c_str(),var29.c_str(),var30.c_str(),var31.c_str());
		b8.Form("Total Et= %s#pm%s, Mean Pt= %s, #frac{#Chi^{2}}{ndf}=%s",var32.c_str(),var33.c_str(),var34.c_str(),var47.c_str());
		b9.Form("A= %s#pm%s, B= %s#pm%s, C=%s#pm%s",var35.c_str(),var36.c_str(),var37.c_str(),var38.c_str(),var39.c_str(),var40.c_str());
		b10.Form("Total Et= %s#pm%s, Mean Pt= %s, #frac{#Chi^{2}}{ndf}=%s",var41.c_str(),var42.c_str(),var43.c_str(),var48.c_str());
	
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
	hj->GetHistogram()->GetXaxis()->SetRangeUser(0.,3.);
	hj->GetHistogram()->GetYaxis()->SetRangeUser(0.,(11.0*yloc));
	hj->GetHistogram()->SetXTitle(xlabel);
	hj->GetHistogram()->SetYTitle(ylabel);
	hj->SetTitle(hisst);
	hj->SetLineColor(kWhite);
	h->Draw("same");
	TLatex* t1 = new TLatex();
		t1->SetTextSize(0.025);
		t1->SetTextColor(kRed);
		//	t1->DrawLatex(1.,(2.5*yloc),b1);
       TLatex* t2 = new TLatex();
		t2->SetTextSize(0.025);
		t2->SetTextColor(kRed);
		// t2->DrawLatex(1.,(2.0*yloc),b2);		
      	TLatex* t3 = new TLatex();
		t3->SetTextSize(0.025);
		t3->SetTextColor(kBlue);
		//t3->DrawLatex(1.,(yloc),b4);
      	TLatex* t4 = new TLatex();
		t4->SetTextSize(0.025);
		t4->SetTextColor(kBlue);
		//	t4->DrawLatex(1.,(1.5*yloc),b3);


       	TLatex* t5 = new TLatex();
		t5->SetTextSize(0.025);
		t5->SetTextColor(kCyan+2);
		//	t5->DrawLatex(1.,(3.5*yloc),b5);
      	TLatex* t6 = new TLatex();
		t6->SetTextSize(0.025);
		t6->SetTextColor(kCyan+2);
		//	t6->DrawLatex(1.,(3.0*yloc),b6);

	TLatex* t7 = new TLatex();
		t7->SetTextSize(0.025);
		t7->SetTextColor(kBlack);
		//	t7->DrawLatex(1.,(4.5*yloc),b7);
      	TLatex* t8 = new TLatex();
		t8->SetTextSize(0.025);
		t8->SetTextColor(kBlack);
		//	t8->DrawLatex(1.,(4.0*yloc),b8);

	TLatex* t9 = new TLatex();
		t9->SetTextSize(0.025);
		t9->SetTextColor(kViolet);
		//	t9->DrawLatex(1.,(5.5*yloc),b9);
      	TLatex* t10 = new TLatex();
		t10->SetTextSize(0.025);
		t10->SetTextColor(kViolet);
		//	t10->DrawLatex(1.,(5.0*yloc),b10);
		
		TLine* l1 = new TLine(meanpt1,.0,meanpt1,(11.0*yloc));//biswas mean
		l1->SetLineColor(kRed);
		l1->SetLineStyle(2);
		l1->Draw();
		TLine* l2 = new TLine(meanpt2,.0,meanpt2,(11.0*yloc));//my mean
		l2->SetLineColor(kBlue);
		l2->SetLineStyle(2);
	       	l2->Draw();
		TLine* l3 = new TLine(meanpt3,.0,meanpt3,(11.0*yloc));//my mean
		l3->SetLineColor(kCyan+2);
		l3->SetLineStyle(2);
			l3->Draw();

		TLine* l4 = new TLine(meanpt4,.0,meanpt4,(11.0*yloc));//my mean
		l4->SetLineColor(kBlack);
		l4->SetLineStyle(2);
			l4->Draw();

		TLine* l5 = new TLine(meanpt5,.0,meanpt5,(11.0*yloc));//my mean
		l5->SetLineColor(kViolet);
		l5->SetLineStyle(2);
			l5->Draw();
	//	funcBGBW->SetLineColor(kRed);
	//c1->Update();
        h->GetXaxis()->SetRangeUser(0.,3.);
	h->GetYaxis()->SetRangeUser(0.,(13.0*yloc));
	c1->Update();

	auto *legend = new TLegend(.7,.6,1,1);
	legend->SetHeader("Fit Function","C");
	legend->AddEntry(funcBGBW,"Unconst. BGBW","l");
	legend->AddEntry(funcBGBW2,"Const. BGBW","l");
	legend->AddEntry(HAGE,"Hage.","l");
		legend->AddEntry(EXPO,"Ae^{-p_{t}/B}","l");
       legend->AddEntry(EXPO2,"Ap_{t}^{B}e^{-p_{t}/C}");
		legend->AddEntry(l3,"Mean P_{t}- Hagedorn","l");
	legend->AddEntry(l1,"Mean P_{t}- Un.","l");
	legend->AddEntry(l2,"Mean P_{t} - const.","l");
	legend->AddEntry(l4,"Mean P_{t} - Expo.","l");
	legend->AddEntry(l5, "Mean P_{t} - Expo2.", "l");

	legend->Draw();
	//	h->Draw("same");
	c1->Update();
	//f->Write();
	//c1->Write();
	
	
	        

		//cout << "chi2: " << chi2BGBW << "\nndf: "
			//<< nDFBGBW<< "\nchi2/ndf: " << chi2BGBW/nDFBGBW <<endl;

		/* FIXME */
		string imgPathAndName = "./fittedPlots51/"+histoName+".png";
				//c1 -> SaveAs("./fittedPlots/trial1.png");
		TImage *png = TImage::Create();// FIXME try to use canvas method instead of png object
		png->FromPad(c1);
		const char* imgPathAndNameConstCharPtr = imgPathAndName.c_str();
		png->WriteImage(imgPathAndNameConstCharPtr);
		/**/
		//cout << "Draw class here: \n";
		//h-> DrawClass();
		///////h->Delete();// works
		///////////FIXME c1->Clear();//
		/// sometimes when you delete objects, they stay in the program stack
		//FIXME delete png;
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
	delete myFile;
	datFile.close();
return 0;
}
