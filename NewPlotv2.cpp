#include <iostream>
#include <string>
#include "TKey.h"
#include <sstream>
#include <fstream>
#include "fitBESData10.h"
#include <TTree.h>
#include <TH1.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TGraph.h>
#include <stdio.h>
using namespace std;
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

void NewPlot(){
  
        TFile* myFile = new TFile("PPlot.root");
	TFile* fout = new TFile("PPlotz.root","RECREATE");
	TIter next(myFile->GetListOfKeys());
	TKey* mikey;
	TH1D* h;
	TH1D* h2;
	TH1D* h3;
	TH1D* h4;
	TH1D* h5;
	TH1D* h6;
	TH1D* h7;
	TH1D* h8;
	TH1D* h9;
	TClass* class1;
	TF1* funcBGBW;
	TF1* dETdEtaIntegrandFunc;
	TF1* dETdyIntegrandFunc;
	TF1* dNdEtaIntegrandFunc;
	TF1* dNdyIntegrandFunc;


	
	//hagedorn
	
	TF1* HAGE;
	TF1* dETdEtaIntegrandFuncHAGE;
	TF1* dETdyIntegrandFuncHAGE;
	TF1* dNdEtaIntegrandFuncHAGE;
	TF1* dNdyIntegrandFuncHAGE;

	TCanvas *c = new TCanvas("c","c",800,450);
	gStyle->SetOptStat(0);
	c->Range(0,0,1,1);
	c->SetFillColor(0);
	c->SetBorderMode(0);
	c->SetBorderSize(0);
	c->SetFrameFillColor(0);
	c->SetFrameBorderMode(0);
	c->SetTopMargin(0.0);
	c->SetLeftMargin(0.0);
	c->SetRightMargin(0.0);
	c->SetBottomMargin(0.0);
	gROOT->SetStyle("Plain");
	float fractionYAxis =0.06;// 0.2;
	float fractionXAxis =0.12;// 0.12;
	float xwidth = (1.0-fractionYAxis)/3.0;//these are crossed because the x-axis takes up room in the y direction and vice versa
	float ywidth = (1.0-fractionXAxis)/3.0;
	cout<<"xwidth "<<xwidth <<" ywidth "<<ywidth<<endl;
   //Double_t xlow, Double_t ylow, Double_t xup, Double_t yup
   // pad1 pad2 pad3
   // pad4 pad5 pad6
   TPad *part1 = new TPad("part1","part1", 0.0           ,1.0-ywidth    ,1.0-2.0*xwidth,1.0       ,0);
   TPad *part2 = new TPad("part2","part2", 1.0-2.0*xwidth,1.0-ywidth    ,1.0-1.0*xwidth,1.0       ,0);
   TPad *part3 = new TPad("part3","part3",1.0-1.0*xwidth,1.0-ywidth    ,1.0           ,1.0       ,0);
   TPad *part4 = new TPad("part4","part4",0.0           ,1.0-2.0*ywidth,1.0-2.0*xwidth,1.0-ywidth,0);
   TPad *part5 = new TPad("part5","part5",1.0-2.0*xwidth,1.0-2.0*ywidth,1.0-1.0*xwidth,1.0-ywidth,0);
   TPad *part6 = new TPad("part6","part6",1.0-1.0*xwidth,1.0-2.0*ywidth,1.0           ,1.0-ywidth,0);
   TPad *part7 = new TPad("part7","part7",0.0           ,0.0           ,1.0-2.0*xwidth,1.0-2.0*ywidth,0);
   TPad *part8 = new TPad("part8","part8",1.0-2.0*xwidth,0.0           ,1.0-1.0*xwidth,1.0-2.0*ywidth,0);
   TPad *part9 = new TPad("part9","part9",1.0-1.0*xwidth,0.0           ,1.0           ,1.0-2.0*ywidth,0);
   
   float topmargin = 0.03;
   float rightmargin = 0.01;
   float leftmargin = fractionYAxis/(fractionYAxis+xwidth);
   float bottommargin = fractionXAxis/(fractionXAxis+ywidth);
   cout<<"leftmargine "<<leftmargin<<" bottom margin "<<bottommargin<<endl;

   part1->SetTopMargin(topmargin);
   part2->SetTopMargin(topmargin);
   part3->SetTopMargin(topmargin);
   
   part4->SetTopMargin(0.0);
   part5->SetTopMargin(0.0);
   part6->SetTopMargin(0.0);

   part7->SetTopMargin(0.0);
   part8->SetTopMargin(0.0);
   part9->SetTopMargin(0.0);
   
   part1->SetBottomMargin(0.0);
   part2->SetBottomMargin(0.0);
   part3->SetBottomMargin(0.0);

   part4->SetBottomMargin(0.0);
   part5->SetBottomMargin(0.0);
   part6->SetBottomMargin(0.0);
   
   part7->SetBottomMargin(bottommargin);
   part8->SetBottomMargin(bottommargin);
   part9->SetBottomMargin(bottommargin);
   
   part1->SetLeftMargin(leftmargin);
   part4->SetLeftMargin(leftmargin);
   part7->SetLeftMargin(leftmargin);
   
   part2->SetLeftMargin(0.0);
   part3->SetLeftMargin(0.0);
   part5->SetLeftMargin(0.0);
   part6->SetLeftMargin(0.0);
   part8->SetLeftMargin(0.0);
   part9->SetLeftMargin(0.0);
   
   part3->SetRightMargin(rightmargin);
   part6->SetRightMargin(rightmargin);
   part9->SetRightMargin(rightmargin);
   
   part1->SetRightMargin(0.0);
   part2->SetRightMargin(0.0);
   part4->SetRightMargin(0.0);
   part5->SetRightMargin(0.0);
   part7->SetRightMargin(0.0);
   part8->SetRightMargin(0.0);
   
   part1->Draw();
   part2->Draw();
   part3->Draw();
   part4->Draw();
   part5->Draw();
   part6->Draw();
   part7->Draw();
   part8->Draw();
   part9->Draw();


   part1->SetFrameFillColor(0);
   part1->SetFrameBorderMode(0);
   part1->SetBorderMode(0);
   part1->SetBorderSize(0);
   part2->SetFrameFillColor(0);
   part2->SetFrameBorderMode(0);
   part2->SetBorderMode(0);
   part2->SetBorderSize(0);
   part3->SetFrameFillColor(0);
   part3->SetFrameBorderMode(0);
   part3->SetBorderMode(0);
   part3->SetBorderSize(0);
   part4->SetFrameFillColor(0);
   part4->SetFrameBorderMode(0);
   part4->SetBorderMode(0);
   part4->SetBorderSize(0);
   part5->SetFrameFillColor(0);
   part5->SetFrameBorderMode(0);
   part5->SetBorderMode(0);
   part5->SetBorderSize(0);
   part6->SetFrameFillColor(0);
   part6->SetFrameBorderMode(0);
   part6->SetBorderMode(0);
   part6->SetBorderSize(0);
   part7->SetFrameFillColor(0);
   part7->SetFrameBorderMode(0);
   part7->SetBorderMode(0);
   part7->SetBorderSize(0);
   part8->SetFrameFillColor(0);
   part8->SetFrameBorderMode(0);
   part8->SetBorderMode(0);
   part8->SetBorderSize(0);
   part9->SetFrameFillColor(0);
   part9->SetFrameBorderMode(0);
   part9->SetBorderMode(0);
   part9->SetBorderSize(0);

   
	int breakOutForTesting =0;
	int stop =10; // breakOut after this many iterations (if achieved); default: 140
	cout << "Flag" << endl;
	int plotnum=0;
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
	

		
		funcBGBW = new TF1("getdNdpt",getdNdpt,0.00000000000001,10.,6); // actually has 5 parameters
									
	
		
		HAGE = new TF1("getdNdptHAGE",getdNdptHAGE,0.0000000000001,10.,5); // HAGEDORN Function 
		
		dETdEtaIntegrandFunc = new TF1("dETdEtaIntegrand",getdETdEtaIntegrand,0, 10, 6 );// function goes from 0 to 10					
		dETdyIntegrandFunc = new TF1("dETdyIntegrand", getdETdyIntegrand,0,10,6);
		dNdEtaIntegrandFunc = new TF1("dETdyIntegrand",
								  getdNdEtaIntegrand,
								  0,10,6); // 5 parameters:m,b,t,n,norm, 6th is type*0
		dNdyIntegrandFunc = new TF1("dETdyIntegrand",
								  getdNdEtaIntegrand,
								  0,10,6);// 5 parameters:m,b,t,n,norm, 6th is type*0



		
	
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
		//gROOT-> SetBatch(kTRUE);// save canvases without displaying them
	
		// read histogram object for current iteration of key:
	

		h = (TH1D*)mikey->ReadObj();
			
		string histoName = h->GetName();
		Double_t collEn = 0.;// initialize
		if(histoName.substr( histoName.length() - 4 ) == "_7.7") collEn = 7.7;
	       	else if(histoName.substr( histoName.length() - 4 ) == "62.4") collEn = 62.4;
		else if(histoName.substr( histoName.length() - 4 ) == "_200") collEn = 200;
		string particleID = histoName.substr(6,3);// starting position in array:6, 3 chars total
		string centrality = histoName.substr(4,1);// starting position in array:4, 1 char total
	
		//------------ Assign mass & type to particle -----------------//
		Double_t mass; // in GeV

		
		Double_t type;// 0 for mesons, -1 for baryons, 1 for antibaryons
		if	(particleID=="pi-"||particleID=="pi+")
				{mass = 0.13957; type = 0.;}
		else if	(particleID=="ka-"||particleID=="ka+")
				{mass = 0.49368; type = 0.;}
		else if	(particleID=="pro")
				{mass = 0.93827; type = -1.;}
		else if	(particleID=="pba")
				{mass = 0.93827; type = 1.;}
		else {cout << "Check particle: "
				<< particleID<<endl;return 1;}

		Double_t* integralDataPtr;
		integralDataPtr = getIntegralsAndErrorsFromData(h,type,mass);
					// ^ method verified!!!
	


	        if(collEn == 62.4 &&( particleID =="pi-"||particleID=="pi+")){
			cout << "histoname is: " << histoName << endl;
			funcBGBW->SetParameters(mass,0.9,0.03,.01,10000.,type);
		}
		else{
			cout << "histoname is: " << histoName << endl;
			funcBGBW->SetParameters(mass,0.95,0.05,0.1,1000000.,type);
		}
		funcBGBW->SetParNames("mass","beta (c)","temp","n","norm","type");
		funcBGBW->SetParLimits(1,0.5,0.999999999999999999999);//param 1
		funcBGBW->FixParameter(0,mass);// mass in GeV
		funcBGBW->FixParameter(5,type);
	
		
	
		//HAGEDORN-------------------------------------------------------
		if(particleID=="pro"){
	        HAGE->SetParameters(mass,1.,1.,5.,type);
		HAGE->SetParNames("mass","A","temp","n","type");
		HAGE->FixParameter(0,mass);// mass in GeV
		HAGE->FixParameter(4,type);
		
		}
		else{
		HAGE->SetParameters(mass,1.,1.,5.,type);
		HAGE->SetParNames("mass","A","temp","n","type");
	
		HAGE->SetParLimits(2,50.,200.); // temp
		HAGE->SetParLimits(3,5.,15.); // norm
		HAGE->FixParameter(0,mass);// mass in GeV
		HAGE->FixParameter(4,type);
		}
	
		HAGE->SetLineColor(kRed);
		HAGE->SetLineWidth(2);
	
		
		ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(20000);
		TString xlabel = "p_{T}";
		TString ylabel = "#frac{d^{2}N}{dydp_{T}}";
		TString b2 = "#pi^{+} 62.4 GeV";
		TString b1= "#pi^{+} 7.7 GeV";
		TString b3= "#pi^{+} 200 GeV";
		TString b5= "k^{+}  62.4 GeV";
		TString b4= "k^{+}  7.7 GeV";
		TString b6= "k^{+}  200 GeV";
	        TString b8= "p 62.4 GeV";
		TString b7= "p 7.7 GeV";
		TString b9= "p 200 GeV";
		TLatex* t1 = new TLatex();
		t1->SetTextSize(0.1);
		t1->SetTextColor(kBlack);

      	TLatex* t4 = new TLatex();
		t4->SetTextSize(0.1);
		t4->SetTextColor(kBlack);
	
      	TLatex* t8 = new TLatex();
		t8->SetTextSize(0.08);
		t8->SetTextColor(kBlack);

	

		if(plotnum ==0){
		 part1->cd();
		 gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		 // h->GetYaxis()->SetRangeUser(0,800.);
		 h->GetYaxis()->SetLimits(0,1000);
		 part1->SetLogy();
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		 h->GetYaxis()->ChangeLabel(1,0,0,0,0,0);
		  h->GetXaxis()->SetLimits(0.1,1.5);
		 t1->DrawLatex(.1,90,b1);
		 // part7->SetLogy();
		 part1->Update();
		 c->Update();
		}
	 	if(plotnum ==3){
		  part2->cd();
		  
		
		  gStyle->SetOptTitle(0);
		  gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		 h->GetYaxis()->SetLimits(0,1000);
		 part2->SetLogy();
		 //h->GetYaxis()->SetRangeUser(0,800.);
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
		 t1->DrawLatex(.1,100,b2);
		  part2->Update();
		  c->Update();
	       	}
		if(plotnum ==6){
		  part3->cd();
		  gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		 //h->GetYaxis()->SetRangeUser(0,800.);
		 h->GetYaxis()->SetLimits(0,1000);
		 part3->SetLogy();
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
			auto *legend = new TLegend(.4,.5,1,1);
			//legend->SetHeader("Fit Function","C");
			legend->SetBorderSize(0);
	legend->AddEntry(funcBGBW,"Blast Wave","l");
	legend->AddEntry(HAGE,"Hagedorn","l");
	legend->Draw();
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
		 t1->DrawLatex(0.1,100,b3);
		  part3->Update();
		  c->Update();
		}
		if(plotnum ==1){
		  part4->cd();
		    gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		  h->SetYTitle(ylabel);
		 // h->GetYaxis()->SetTitleSize(1);
		 h->GetXaxis()->SetLimits(0.1,1.);
		 h->GetXaxis()->SetLabelSize(0.1);
		  h->GetYaxis()->SetLimits(0,100);
		 part4->SetLogy();
		 //h->GetYaxis()->SetRangeUser(0,50.);
		 h->GetYaxis()->ChangeLabel(11,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		 h->GetYaxis()->ChangeLabel(1,0,0,0,0,0);
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.07);
		  h->GetYaxis()->SetTitleOffset(0.5);
		 h->GetYaxis()->SetTitleSize(.1);
		 h->GetYaxis()->CenterTitle();
		 t4->DrawLatex(0.1,5,b4);
		  part4->Update();
		  c->Update();
		}
		if(plotnum ==4){
		  part5->cd();
		    gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		  h->GetYaxis()->SetLimits(0,100);
		 part5->SetLogy();
		 // h->GetYaxis()->SetRangeUser(0,50.);
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		 h->GetXaxis()->SetTitleOffset(0.5);
		 h->GetXaxis()->SetTitleSize(.2);
		 h->GetXaxis()->CenterTitle();
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
		 t4->DrawLatex(0.1,5,b5);
		  part5->Update();
		  c->Update();
		}
		if(plotnum ==7){
		  part6->cd();
		     gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		  h->GetYaxis()->SetLimits(0,100);
		 part6->SetLogy();
		 // h->GetYaxis()->SetRangeUser(0,50.);
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
		 t4->DrawLatex(0.1,5,b6);
		  part6->Update();
		  c->Update();
		}
		if(plotnum ==2){
		  part7->cd();
		    gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		  h->GetYaxis()->SetLimits(0,20);
		 part7->SetLogy();
		 // h->GetYaxis()->SetRangeUser(0,12.);
		 h->GetYaxis()->ChangeLabel(7,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
		 t8->DrawLatex(0.1,2,b7);
		  part7->Update();
		  c->Update();
		}
		if(plotnum ==5){
		  part8->cd();
		   gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 // h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		 //h->GetYaxis()->SetRangeUser(0,12.);
		  h->GetYaxis()->SetLimits(0,20);
		 part8->SetLogy();
		 h->GetYaxis()->ChangeLabel(9,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.08);
		 h->SetXTitle(xlabel);
		 h->GetXaxis()->SetTitleOffset(0.5);
		 h->GetXaxis()->SetTitleSize(.2);
		 h->GetXaxis()->CenterTitle();
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.09);
		 t8->DrawLatex(0.1,2,b8);
		  part8->Update();
		  c->Update();
		}
		if(plotnum ==8){
		  part9->cd();
		    gStyle->SetOptTitle(0);
		 gStyle->SetOptStat(0);
		 h->Draw();
		 h->SetMarkerColor(1);
		 h->SetMarkerStyle(20);
		 h->SetMarkerSize(1.);
		 h->Fit("getdNdpt","S+","",0.00000000000001,100.);
		 //	 h->Fit("getdNdpt2","S+","",0.00000000000001,100.);
		 h->Fit("getdNdptHAGE","S+","",0.000000000001,100.);
		 // part7->SetLogy();
		  h->GetYaxis()->SetLimits(0,20);
		 part9->SetLogy();
		 // h->GetYaxis()->SetRangeUser(0,12.);
		 h->GetYaxis()->ChangeLabel(13,0,0,0,0,0);
		 h->GetYaxis()->SetLabelSize(0.1);
		
		 h->GetXaxis()->SetLimits(0.1,1.5);
		 h->GetXaxis()->SetLabelSize(0.1);
	
		 t8->DrawLatex(0.1,2,b9);
		  part9->Update();
		  c->Update();
		}
	
		c->Update();		
		mikey->DeleteBuffer();// works!
		plotnum++;
		h->Write();
		if(breakOutForTesting>=stop) break;

		gSystem->ProcessEvents();
		
		// delete h;
		// delete funcBGBW;
		// delete dETdEtaIntegrandFunc;
		// delete dETdyIntegrandFunc;
		// delete funcBGBW2;
		// delete dETdEtaIntegrandFunc2;
		// delete dETdyIntegrandFunc2;
		// delete HAGE;
		// delete dETdEtaIntegrandFuncHAGE;
		// delete dETdyIntegrandFuncHAGE;
	}
	string imgPathAndName = "./paperplot.png";
				//c1 -> SaveAs("./fittedPlots/trial1.png");
		TImage *png = TImage::Create();// FIXME try to use canvas method instead of png object
		png->FromPad(c);
		const char* imgPathAndNameConstCharPtr = imgPathAndName.c_str();
		png->WriteImage(imgPathAndNameConstCharPtr);
  	c->Update();
		string  macroPathAndName = "./paperplot.C";
	const char* macroname = macroPathAndName.c_str();
	c->SaveAs(macroname);
	//	c->Draw();
	//	c->Write();
		fout->Write();
		fout->Close();
	return 0;

  

}
