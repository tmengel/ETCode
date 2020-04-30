/*
In this version: applied transformation to 
account for the fact that BES data contains d^2N/(2pi*pt*dpt*dy)[(GeV/c)^-2]
instead of d^2N/(dpt*dy)[(GeV/c)^-2]
*/

#ifndef fitBESData5_H
#define fitBESData5_H
/* Function that returns an array containing, in order:
dEt/dEta
dEt/dEta_Error;
dEt/dy;
dEt/dy_Error;
dN/dEta;
dNd/Eta_Error;
dN/dy;
dN/dy_Error

corresponding to the data points in the passed TGraphErrors object, i.e.,
without extrapolation:
*/
Double_t* getIntegralsAndErrorsFromData(TGraphErrors* gr, Double_t type, Double_t mass){
	static Double_t integralArr[8]; //array to return
	//^ if not static, error:
	//address of stack memory associated with local variable returned
	Double_t dEtdEta;
	Double_t dEtdEtaError;
	Double_t dEtdy;
	Double_t dEtdyError;
	Double_t dNdEta;
	Double_t dNdEtaError;
	Double_t dNdy;
	Double_t dNdyError;
	Int_t binx1 = 0;
	Int_t binx2 = 1000; // arbitrary, large value
	Double_t integral = 0.;
	Int_t totBins = hist -> GetNbinsX();
	if (binx1 < 0) binx1 = 0; // sanity check
	   	if (binx2 > totBins+1 || binx2 < 0) binx2 = totBins+1;
		for(Int_t binx = binx1; binx <= binx2; binx++){
			Double_t pt = (hist->GetXaxis()->GetBinLowEdge(binx)+
						hist->GetXaxis()->GetBinUpEdge(binx))/2;// avg of bin edges
			//float pt = h->GetXaxis()->GetBinLowEdge(binx);
			// calculate E_T needed for dE_T/dy:
			Double_t et = TMath::Sqrt(pt*pt+mass*mass)+type*mass;
			// ^ sin(theta)=1 at midrapidity
			
			// calculate J*E_T needed for dE_T/dEta:
			Double_t JTimeset = pt/(TMath::Sqrt(pt*pt+mass*mass))*et; 
			Double_t J = pt/(TMath::Sqrt(pt*pt+mass*mass));
			Double_t dx = hist->GetXaxis()->GetBinWidth(binx);
			//cout << "bin width from bin " << binx << ": " << dx << endl;
			//cout << "content in bin " << binx << ": " << h->GetBinContent(binx) << endl;
			//dE_tdEtaIntegralData +
			Double_t tr = 2. * TMath::Pi() * pt; // transformation to be applied becaue
								// BES data contains d^2N/(2pi*pt*dpt*dy)[(GeV/c)^-2]
			dEtdEta += hist->GetBinContent(binx)*tr*J*et*dx;
			dEtdy 	+= hist->GetBinContent(binx)*tr*et*dx;
			dNdEta 	+= hist->GetBinContent(binx)*tr*J*dx;
			dNdy 	+= hist->GetBinContent(binx)*tr*dx;
			//dE_tdyIntegralData += h->GetBinContent(binx)*et*dx;
			// checking with et0:
			//if (width) integralData += h->GetBinContent(binx)*et0*dx; 
			dEtdEtaError 	+= hist->GetBinError(binx)*tr*J*et*dx;
			dEtdyError 		+= hist->GetBinError(binx)*tr*et*dx;
			dNdEtaError		+= hist->GetBinError(binx)*tr*J*dx;
			dNdyError		+= hist->GetBinError(binx)*tr*dx;
			//igerr2 += h->GetBinError(binx)*dx*et; //// !!look up details later
			// ^ if the errors are completely correlated
			// if uncorrelated: take the square root of igerr2
			}
			integralArr[0] = dEtdEta;
			integralArr[1] = dEtdEtaError;
			integralArr[2] = dEtdy;
			integralArr[3] = dEtdyError;
			integralArr[4] = dNdEta;
			integralArr[5] = dNdEtaError;
			integralArr[6] = dNdy;
			integralArr[7] = dNdyError;
		/* check: 
			for(int i=0; i<8; i++){
			
			cout<<"Int result "<<i+1<<": "<<integralArr[i]<<endl;
		}
		*/
			
		
	return integralArr;
}
/* Function that returns an array containing, in order:
dEt/dEta
dEt/dEta_Error;
dEt/dy;
dEt/dy_Error;
dN/dEta;
dNd/Eta_Error;
dN/dy;
dN/dy_Error

corresponding to the data points in the passed histogram, i.e.,
without extrapolation:
*/
Double_t* getIntegralsAndErrorsFromData(TH1D* hist, Double_t type, Double_t mass){
	static Double_t integralArr[8]; //array to return
	//^ if not static, error:
	//address of stack memory associated with local variable returned
	Double_t dEtdEta;
	Double_t dEtdEtaError;
	Double_t dEtdy;
	Double_t dEtdyError;
	Double_t dNdEta;
	Double_t dNdEtaError;
	Double_t dNdy;
	Double_t dNdyError;
	Int_t binx1 = 0;
	Int_t binx2 = 1000; // arbitrary, large value
	Double_t integral = 0.;
	Int_t totBins = hist -> GetNbinsX();
	if (binx1 < 0) binx1 = 0; // sanity check
	   	if (binx2 > totBins+1 || binx2 < 0) binx2 = totBins+1;
		for(Int_t binx = binx1; binx <= binx2; binx++){
			Double_t pt = (hist->GetXaxis()->GetBinLowEdge(binx)+
						hist->GetXaxis()->GetBinUpEdge(binx))/2;// avg of bin edges
			//float pt = h->GetXaxis()->GetBinLowEdge(binx);
			// calculate E_T needed for dE_T/dy:
			Double_t et = TMath::Sqrt(pt*pt+mass*mass)+type*mass;
			// ^ sin(theta)=1 at midrapidity
			
			// calculate J*E_T needed for dE_T/dEta:
			Double_t JTimeset = pt/(TMath::Sqrt(pt*pt+mass*mass))*et; 
			Double_t J = pt/(TMath::Sqrt(pt*pt+mass*mass));
			Double_t dx = hist->GetXaxis()->GetBinWidth(binx);
			//cout << "bin width from bin " << binx << ": " << dx << endl;
			//cout << "content in bin " << binx << ": " << h->GetBinContent(binx) << endl;
			//dE_tdEtaIntegralData +
			Double_t tr = 2. * TMath::Pi() * pt; // transformation to be applied becaue
								// BES data contains d^2N/(2pi*pt*dpt*dy)[(GeV/c)^-2]
			dEtdEta += hist->GetBinContent(binx)*tr*J*et*dx;
			dEtdy 	+= hist->GetBinContent(binx)*tr*et*dx;
			dNdEta 	+= hist->GetBinContent(binx)*tr*J*dx;
			dNdy 	+= hist->GetBinContent(binx)*tr*dx;
			//dE_tdyIntegralData += h->GetBinContent(binx)*et*dx;
			// checking with et0:
			//if (width) integralData += h->GetBinContent(binx)*et0*dx; 
			dEtdEtaError 	+= hist->GetBinError(binx)*tr*J*et*dx;
			dEtdyError 		+= hist->GetBinError(binx)*tr*et*dx;
			dNdEtaError		+= hist->GetBinError(binx)*tr*J*dx;
			dNdyError		+= hist->GetBinError(binx)*tr*dx;
			//igerr2 += h->GetBinError(binx)*dx*et; //// !!look up details later
			// ^ if the errors are completely correlated
			// if uncorrelated: take the square root of igerr2
			}
			integralArr[0] = dEtdEta;
			integralArr[1] = dEtdEtaError;
			integralArr[2] = dEtdy;
			integralArr[3] = dEtdyError;
			integralArr[4] = dNdEta;
			integralArr[5] = dNdEtaError;
			integralArr[6] = dNdy;
			integralArr[7] = dNdyError;
		/* check: 
			for(int i=0; i<8; i++){
			
			cout<<"Int result "<<i+1<<": "<<integralArr[i]<<endl;
		}
		*/
			
		
	return integralArr;
}

// Function to return 1/pt dN/dpt integrand (which is used in...
	// ...function getdNdpt):
Double_t getdNdptOverptIntegrand(Double_t* rad, Double_t* par){
	// (dN/dpt)/pt= r*dr*mt*I0((pt*sinh(rho))/T)*K1((mt*cosh(rho))/T)
	// rho=arctanh(beta); beta=betaMax*(r/R)^n
	//Double_t pT		= pt[0];
	Double_t r 			= rad[0];
	// parameters used to fit: mass, beta, temp, n, norm
	Double_t mass 		= par[0];// not mT
	Double_t pt			= par[1];
	Double_t betaMax 	= par[2];
	Double_t temp 		= par[3];
	Double_t n 			= par[4];
	Double_t type		= par[5];

	Double_t beta = betaMax*TMath::Power(r,n);
	if(beta > 0.99999999999999999999) beta = 0.99999999999999999999;
	Double_t mT 	= TMath::Sqrt(mass*mass + pt*pt);
	Double_t rho0 	= TMath::ATanH(beta);
	Double_t avoidFPE = pt*TMath::SinH(rho0)/temp;
	if(avoidFPE > 700.) avoidFPE = 700.;
	Double_t bk1arg = mT*TMath::CosH(rho0)/temp;
	Double_t integrand = /*definition*/
	r*mT*TMath::BesselI0(avoidFPE)*TMath::BesselK1(bk1arg)+type*0.;
	return integrand;
}// end of method getdNdptOverptIntegrand

// Function to return dN/dpt 
	//(normalized using free parameter 'norm'
	// and transformed by multiplying with 2pi*pT;
	// result of this function is used 
	// in the function getdETdyIntegrand):
Double_t getdNdpt(Double_t* pT, Double_t* params){
	TF1* dNdptOverptIntegrandFunc = new TF1("integrandFunc", 
									getdNdptOverptIntegrand, 
									0, 1, 6 );
	
	Double_t pt		= pT[0];
	Double_t mass 	= params[0];// not mT
	Double_t beta 	= params[1];
	Double_t temp 	= params[2];
	Double_t n 		= params[3];
	Double_t norm	= params[4];
	Double_t type	= params[5];
	dNdptOverptIntegrandFunc->SetParameters(mass,pt,beta,temp,n);

	Double_t dNdptOverpt 	= dNdptOverptIntegrandFunc->Integral(0,1);
	// ^ normalized r goes from 0 to 1 instead of from 0 to R
	Double_t dNdpt_normalized			= 2 * TMath::Pi() * pt * norm * dNdptOverpt+type*0.;
	gSystem->ProcessEvents();
	gROOT->Reset();
	return dNdpt_normalized;
}

// Function to return the integrand to be used
	// to calculate dET/dy using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram: 
Double_t getdETdyIntegrand(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass  = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdpt(myPt,par);
	//////cout<< "funcVal: " << funcVal<< "pt: "<< pt<< endl;
	Double_t integrand = funcVal*(TMath::Sqrt(pt*pt+mass*mass)+type*mass);
	
	return integrand;
}

// Function to return the integrand to be used
	// to calculate dET/dEta using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram: 
Double_t getdETdEtaIntegrand(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdpt(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal*(pt/TMath::Sqrt(pt*pt+mass*mass))*(TMath::Sqrt(pt*pt+mass*mass)+type*mass);
	
	return integrand;
}

// Function to return the integrand to be used
	// to calculate dET/dy using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram: 
Double_t getdNdEtaIntegrand(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	//Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdpt(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal*(pt/TMath::Sqrt(pt*pt+mass*mass));
	
	return integrand;
}

// Function to return the integrand to be used
	// to calculate dN/dy using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram:
Double_t getdNdyIntegrand(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	//Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdpt(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal;
	
	return integrand;
}

/*Double_t use_funcBGBW(TF1* funcObj, Double_t* pt){
	return funcObj->Eval(pt);
}*/
string concatenatePlotname(string centStr,string pName,string colSp,string colEn){
	string initText = "cent";
	string undScr = "_";//underscore
	//string enUnits = "GeV";
	string addedString = initText+centStr+undScr+pName+undScr+colSp+undScr+colEn;//+enUnits;
	return addedString; //type: const char*: to be done later
}

// results: par1,par2,par3,par4,transEn, 
	//transEnErr, collEn
// args 2, 3: centrality, partName

//FIXME: actually, this function is probably not needed
		// just outstream this info everytime a fit is good?
		// TODO: convert function to ifstream from ofstream
void outputDatFile(Double_t* results, int centra, string partName){
	std::ofstream datFile ("fitResults.dat", std::ofstream::out);
	datFile << "par1\t"<<"par2\t"<<"par3\t"<<"par4\t"
			<<"transEn\t"<<"transEnErr\t"<<"collEn\t"
			<<"centrality\t"<<"partName\n";
	for(int i=0; i<270; i++){// FIXME: all these indices can't be i:
		datFile << results[i]<<"\t"<< results[i]<<"\t"
				<< results[i]<<"\t"<< results[i]<<"\t"
				<< results[i]<<"\t"<< results[i]<<"\t"
				<< results[i]<<"\t"<< results[i]<<"\n";
	
	}			
	datFile.close();	
}

Int_t* getNpartAndErr(Double_t en, string cent){// args energy and centrality
	Int_t Npart = 0;
	Int_t NpartErr = 0;
		if (en == 7.7){
			if (cent == "0"){
				Npart 		= 337;
				NpartErr 	= 2;
			}
			else if (cent == "1"){
				Npart 		= 290;
				NpartErr 	= 6;
			}
			else if (cent == "2"){
				Npart 		= 226;
				NpartErr	= 8;
			}
			else if (cent == "3"){
				Npart 		= 160;
				NpartErr 	= 10;
			}
			else if (cent == "4"){
				Npart 		= 110;
				NpartErr 	= 11;
			}
			else if (cent == "5"){
				Npart 		= 72;
				NpartErr 	= 10;
			}
			else if (cent == "6"){
				Npart 		= 45;
				NpartErr	= 9;
			}
			else if (cent == "7"){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == "8"){
				Npart 		= 14;
				NpartErr 	= 4;
			}
		}
		if (en == 11.5){
			if (cent == "0"){
				Npart 		= 338;
				NpartErr 	= 2;
			}
			else if (cent == "1"){
				Npart 		= 291;
				NpartErr 	= 6;
			}
			else if (cent == "2"){
				Npart 		= 226;
				NpartErr	= 8;
			}
			else if (cent == "3"){
				Npart 		= 160;
				NpartErr 	= 9;
			}
			else if (cent == "4"){
				Npart 		= 110;
				NpartErr 	= 10;
			}
			else if (cent == "5"){
				Npart 		= 73;
				NpartErr 	= 10;
			}
			else if (cent == "6"){
				Npart 		= 45;
				NpartErr	= 9;
			}
			else if (cent == "7"){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == "8"){
				Npart 		= 14;
				NpartErr 	= 4;
			}
		}
		if (en == 19.6){
			if (cent == "0"){
				Npart 		= 338;
				NpartErr 	= 2;
			}
			else if (cent == "1"){
				Npart 		= 289;
				NpartErr 	= 6;
			}
			else if (cent == "2"){
				Npart 		= 225;
				NpartErr	= 9;
			}
			else if (cent == "3"){
				Npart 		= 158;
				NpartErr 	= 10;
			}
			else if (cent == "4"){
				Npart 		= 108;
				NpartErr 	= 11;
			}
			else if (cent == "5"){
				Npart 		= 71;
				NpartErr 	= 10;
			}
			else if (cent == "6"){
				Npart 		= 44;
				NpartErr	= 9;
			}
			else if (cent == "7"){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == "8"){
				Npart 		= 14;
				NpartErr 	= 5;
			}
		}
		if (en == 27){
			if (cent == "0"){
				Npart 		= 343;
				NpartErr 	= 2;
			}
			else if (cent == "1"){
				Npart 		= 299;
				NpartErr 	= 6;
			}
			else if (cent == "2"){
				Npart 		= 234;
				NpartErr	= 9;
			}
			else if (cent == "3"){
				Npart 		= 166;
				NpartErr 	= 11;
			}
			else if (cent == "4"){
				Npart 		= 114;
				NpartErr 	= 11;
			}
			else if (cent == "5"){
				Npart 		= 75;
				NpartErr 	= 10;
			}
			else if (cent == "6"){
				Npart 		= 47;
				NpartErr	= 9;
			}
			else if (cent == "7"){
				Npart 		= 27;
				NpartErr 	= 8;
			}
			else if (cent == "8"){
				Npart 		= 14;
				NpartErr 	= 6;
			}
		}
		if (en == 39){
			if (cent == "0"){
				Npart 		= 342;
				NpartErr 	= 2;
			}
			else if (cent == "1"){
				Npart 		= 294;
				NpartErr 	= 6;
			}
			else if (cent == "2"){
				Npart 		= 230;
				NpartErr	= 9;
			}
			else if (cent == "3"){
				Npart 		= 162;
				NpartErr 	= 10;
			}
			else if (cent == "4"){
				Npart 		= 111;
				NpartErr 	= 11;
			}
			else if (cent == "5"){
				Npart 		= 74;
				NpartErr 	= 10;
			}
			else if (cent == "6"){
				Npart 		= 46;
				NpartErr	= 9;
			}
			else if (cent == "7"){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == "8"){
				Npart 		= 14;
				NpartErr 	= 5;
			}
		}
	static Int_t npartAndErrArr[2];// first element is Npar, second Npar_err
	npartAndErrArr[0] = Npart;
	npartAndErrArr[1] = NpartErr;
	
	return npartAndErrArr;
}

void classifyParticleKmeans(){

	
}

#endif
