// Inputs all Pt spectra data from various .txt files 

#include "Riostream.h"
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include "TString.h"
#include "TMath.h"
#include "TH1D.h"
#include <iostream> // to use cout for debugging
using namespace std;

/*const char* */ string concatenateHistoname(string,string,string,string);

int Strz(){ // main
	string 				myString;// temporary string to hold ifstream instance
	string				collidingSpecies;/////////////
	string 				collisionEnergy;
	string 				collisionEnergyStr;////////////////////
	string 				particleName;// eg. pi+
	Float_t 			myFloat; //temporary float to hold energy value
	Double_t			myDouble; // temporary double to hold values from histo row
	Int_t				histonum = 0; // track number of histos created/parsed
	//TODO: std::vector<TH1D> 	histoList; // vector (list) of histograms
	ifstream 			in;

	TFile* f = new TFile("PPlot.root","RECREATE");// .root file to be created
	//-----------------------------------------------------------------------------------
	//Biswas data first







	//START OF MY DATA------------------------------------------------------------------------
	//62.4, 9 cents
	
	in.open(Form("./paperplots.txt"));
		while(in >> collidingSpecies){
		while(collidingSpecies!="Au+Au") {in >> collidingSpecies;}
		in >> collisionEnergy;
		for(int i = 0; i<8; i++) in >> myString; // skipping 8 strings
		
		for(int cent = 0; cent<1; cent++){// iterate 9X for 9 centralities
			std::vector<Double_t> binEdgesVec;
			std::vector<Double_t> binContent;
			std::vector<Double_t> binContentErrStat;
			std::vector<Double_t> binContentErrSys;

			if (cent==0){
				in>>myString;
			}
			in >> particleName;
			if(!in.good()) cout<< "particleName not read correctly"<< endl;
			in >> myString;// read & skip string corresponding to centrality
			Int_t binNum = 0;
			Double_t tempDouble; /////////// flag used in debugging
			Double_t binHighEdge; // only pushed_back after completion of while loop
									// to avoid redundancy
			/////// FIXME binEdgesVec.push_back(0.0);// to set the left-most edge to zero  DONE
			while(in>>myDouble){// get single content from each of the 5 columns, and repeat
									// until in.fail(), i,e. fail bit encountered
								// fstream malfunction if input stream statement within loop body
									// instead of in loop condition
				binNum++;// first iteration gets first bin, etc.
				binEdgesVec.push_back(myDouble);
				in >> binHighEdge;// not pushed_back until the while loop terminates
				in >> myDouble;
				binContent.push_back(myDouble);
				in >> myDouble;
				binContentErrStat.push_back(myDouble);
				in >> myDouble;
				binContentErrSys.push_back(myDouble);
				cout << "bin: " << binNum << " " << binEdgesVec[binNum-1] << " " << binContent[binNum-1] << endl;
			}// end of while loop to capture every histo bin
			//TODO:

			/*if (in.fail())cout << "Error! Fail bit!"<< endl; // this is what happens
			else if (in.bad())cout << "Error! Not fail bit but bad bit!"<<endl;
			else cout << "Error! But neither fail bit nor bad bit!"<< endl;*/
       
	
			in.clear(); // to restore input stream in a good state after failbit
			in >> myString;// read end of histo: ---------------- and do nothing
			binEdgesVec.push_back(binHighEdge);
			string centString = std::to_string(cent);////////////////////
//TH1D *cent0_pion_minus__3 = new TH1D(name,"0-5%",52, xAxis2);// example constructor
// cent$centrality$_$particleName$_$collidingSpecies$_$collisionEnergy$// histoname format
			string histoname = concatenateHistoname(centString,particleName,collidingSpecies,collisionEnergy);
			// TH1D constructor takes const char*, not string, as name args:
			const char* histonameConstCharPtr = histoname.c_str();// convert string to const char*
			histonum++;// just to track
			cout << "Histoname: " << histoname << ", Histonum: "<< histonum<< endl;
			//for(int c = 0; c<binNum; c++){cout<< binEdgesArr[c]<<endl;}return 0;//////////////
			// fourth arg in TH1D constructor is a pointer
			//to list (of bin edges), in this case a vector:
			Double_t* a = &binEdgesVec[0];
			TH1D *h = new TH1D(histonameConstCharPtr,histonameConstCharPtr, binNum, a);
			// ^ here histoname needs to be a const char*
			// check if pointers for two histos are not different:
			cout << "his. pointer " << histonum <<":" << h << endl;
			cout << "arr. pointer " << histonum <<":" << /*a*/&binEdgesVec[0] << endl;
	
	
			h->GetXaxis()->SetRangeUser(0.,10.);
			cout << "bin num: " << binNum << endl;
			for(int j = 1; j<=binNum; j++){// fill in bin content and error for every bin
				// Y-axis of data transformed to match BGBW fit y-axis:
				h->SetBinContent(j,
							binContent[j-1]);//*2*TMath::Pi());//*(binEdgesVec[j]+binEdgesVec[j+1])/2);
				// ^ (data y-value multiplied by 2pi// not:*pt; pt = ptLow+0.5 of binWidth)

				// add errors in quadrature:
				h->SetBinError(j,TMath::Sqrt(binContentErrStat[j-1]*binContentErrStat[j-1]
								+binContentErrSys[j-1]*binContentErrSys[j-1]));

			}
			cout <<"--------------------------------------------"<< endl<< endl;
			// TODO: histoList.push_back(*h);	// Not necessary if histo list not created
		}// end of for loop to capture each centrality
	}// end of global while loop to capture each collisionEnergy
	in.close();
         
	





	f->Write(); // writes objects in memory (TH1D objects in this case) to TFile
	delete f; // instead of f->Close(), in order to automatically delete all objects
				// owned by this file
	return 0;
}


string concatenateHistoname(string centStr,string pName,string colSp,string colEn){
	string initText = "cent";
	string undScr = "_";//underscore
	string addedString = initText+centStr+undScr+pName+undScr+colSp+undScr+colEn;
	return addedString; //type: const char*: to be done later
}

