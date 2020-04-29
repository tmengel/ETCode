
#include <iostream>
#include <string>
#include "TKey.h"
#include <sstream>
#include <fstream>
#include <TTree.h>
#include <TH1.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TGraph.h>
#include <stdio.h>

#include "TMath.h"
#include "TF1.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "Riostream.h"

#include <TSystem.h>
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


void paperplot()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Apr 10 13:05:50 2020) by ROOT version 6.12/04
   TCanvas *c = new TCanvas("c", "c",566,52,800,450);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   c->Range(0,0,1,1);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(0);
   c->SetLeftMargin(0);
   c->SetRightMargin(0);
   c->SetTopMargin(0);
   c->SetBottomMargin(0);
   c->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: part1
   TPad *part1 = new TPad("part1", "part1",0,0.7066667,0.3733333,1);
   part1->Draw();
   part1->cd();
   part1->Range(-0.3425532,1.175864,1.54,3.294129);
   part1->SetFillColor(0);
   part1->SetBorderMode(0);
   part1->SetBorderSize(0);
   part1->SetLogy();
   part1->SetLeftMargin(0.1607143);
   part1->SetRightMargin(0);
   part1->SetTopMargin(0.03);
   part1->SetBottomMargin(0);
   part1->SetFrameBorderMode(0);
   part1->SetFrameBorderMode(0);
   Double_t xAxis1[11] = {0.23, 0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72}; 
   
   TH1D *cent0_pipL_AupLAu_62dO4__1 = new TH1D("cent0_pipL_AupLAu_62dO4__1","cent0_pi+_Au+Au_62.4",10, xAxis1);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(1,295.283);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(2,226.8522);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(3,174.8156);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(4,135.9606);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(5,105.482);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(6,82.0692);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(7,63.774);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(8,49.8719);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(9,39.0152);
   cent0_pipL_AupLAu_62dO4__1->SetBinContent(10,30.9134);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(1,5.91339);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(2,4.5434);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(3,3.50081);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(4,1.36693);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(5,1.06124);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(6,0.82633);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(7,0.64282);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(8,0.99979);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(9,0.7826);
   cent0_pipL_AupLAu_62dO4__1->SetBinError(10,0.92912);
   cent0_pipL_AupLAu_62dO4__1->SetEntries(10);
   
   TF1 *getdNdpt1 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt1->SetRange(1e-14,100);
   getdNdpt1->SetName("getdNdpt");
   getdNdpt1->SetTitle("getdNdpt");
   getdNdpt1->SetSavedPoint(0,814.4038);
   getdNdpt1->SetSavedPoint(1,8.244014);
   getdNdpt1->SetSavedPoint(2,0.1666481);
   getdNdpt1->SetSavedPoint(3,0.004636099);
   getdNdpt1->SetSavedPoint(4,0.0001469601);
   getdNdpt1->SetSavedPoint(5,4.997862e-06);
   getdNdpt1->SetSavedPoint(6,1.775908e-07);
   getdNdpt1->SetSavedPoint(7,6.502319e-09);
   getdNdpt1->SetSavedPoint(8,2.433126e-10);
   getdNdpt1->SetSavedPoint(9,9.25621e-12);
   getdNdpt1->SetSavedPoint(10,3.567234e-13);
   getdNdpt1->SetSavedPoint(11,1.389206e-14);
   getdNdpt1->SetSavedPoint(12,5.456777e-16);
   getdNdpt1->SetSavedPoint(13,2.158905e-17);
   getdNdpt1->SetSavedPoint(14,8.593891e-19);
   getdNdpt1->SetSavedPoint(15,3.439024e-20);
   getdNdpt1->SetSavedPoint(16,1.382526e-21);
   getdNdpt1->SetSavedPoint(17,5.580363e-23);
   getdNdpt1->SetSavedPoint(18,2.2605e-24);
   getdNdpt1->SetSavedPoint(19,9.186159e-26);
   getdNdpt1->SetSavedPoint(20,3.743792e-27);
   getdNdpt1->SetSavedPoint(21,1.529746e-28);
   getdNdpt1->SetSavedPoint(22,1.91862e-30);
   getdNdpt1->SetSavedPoint(23,2.577648e-33);
   getdNdpt1->SetSavedPoint(24,3.823911e-37);
   getdNdpt1->SetSavedPoint(25,8.291601e-42);
   getdNdpt1->SetSavedPoint(26,1.588279e-43);
   getdNdpt1->SetSavedPoint(27,4.528423e-49);
   getdNdpt1->SetSavedPoint(28,6.208576e-51);
   getdNdpt1->SetSavedPoint(29,2.608388e-57);
   getdNdpt1->SetSavedPoint(30,2.484084e-59);
   getdNdpt1->SetSavedPoint(31,1.796606e-66);
   getdNdpt1->SetSavedPoint(32,1.164753e-68);
   getdNdpt1->SetSavedPoint(33,1.770908e-76);
   getdNdpt1->SetSavedPoint(34,7.728481e-79);
   getdNdpt1->SetSavedPoint(35,3.038592e-87);
   getdNdpt1->SetSavedPoint(36,8.907559e-90);
   getdNdpt1->SetSavedPoint(37,1.126116e-98);
   getdNdpt1->SetSavedPoint(38,3.112413e-101);
   getdNdpt1->SetSavedPoint(39,1.173573e-110);
   getdNdpt1->SetSavedPoint(40,5.088424e-120);
   getdNdpt1->SetSavedPoint(41,2.394503e-129);
   getdNdpt1->SetSavedPoint(42,1.588226e-132);
   getdNdpt1->SetSavedPoint(43,7.794515e-142);
   getdNdpt1->SetSavedPoint(44,9.133857e-151);
   getdNdpt1->SetSavedPoint(45,1.756171e-163);
   getdNdpt1->SetSavedPoint(46,9.204658e-173);
   getdNdpt1->SetSavedPoint(47,1.897236e-184);
   getdNdpt1->SetSavedPoint(48,2.396554e-204);
   getdNdpt1->SetSavedPoint(49,6.793567e-216);
   getdNdpt1->SetSavedPoint(50,3.115587e-236);
   getdNdpt1->SetSavedPoint(51,3.742675e-268);
   getdNdpt1->SetSavedPoint(52,0);
   getdNdpt1->SetSavedPoint(53,0);
   getdNdpt1->SetSavedPoint(54,0);
   getdNdpt1->SetSavedPoint(55,0);
   getdNdpt1->SetSavedPoint(56,0);
   getdNdpt1->SetSavedPoint(57,0);
   getdNdpt1->SetSavedPoint(58,0);
   getdNdpt1->SetSavedPoint(59,0);
   getdNdpt1->SetSavedPoint(60,0);
   getdNdpt1->SetSavedPoint(61,0);
   getdNdpt1->SetSavedPoint(62,0);
   getdNdpt1->SetSavedPoint(63,0);
   getdNdpt1->SetSavedPoint(64,0);
   getdNdpt1->SetSavedPoint(65,0);
   getdNdpt1->SetSavedPoint(66,0);
   getdNdpt1->SetSavedPoint(67,0);
   getdNdpt1->SetSavedPoint(68,0);
   getdNdpt1->SetSavedPoint(69,0);
   getdNdpt1->SetSavedPoint(70,0);
   getdNdpt1->SetSavedPoint(71,0);
   getdNdpt1->SetSavedPoint(72,0);
   getdNdpt1->SetSavedPoint(73,0);
   getdNdpt1->SetSavedPoint(74,0);
   getdNdpt1->SetSavedPoint(75,0);
   getdNdpt1->SetSavedPoint(76,0);
   getdNdpt1->SetSavedPoint(77,0);
   getdNdpt1->SetSavedPoint(78,0);
   getdNdpt1->SetSavedPoint(79,0);
   getdNdpt1->SetSavedPoint(80,0);
   getdNdpt1->SetSavedPoint(81,0);
   getdNdpt1->SetSavedPoint(82,0);
   getdNdpt1->SetSavedPoint(83,0);
   getdNdpt1->SetSavedPoint(84,0);
   getdNdpt1->SetSavedPoint(85,0);
   getdNdpt1->SetSavedPoint(86,0);
   getdNdpt1->SetSavedPoint(87,0);
   getdNdpt1->SetSavedPoint(88,0);
   getdNdpt1->SetSavedPoint(89,0);
   getdNdpt1->SetSavedPoint(90,0);
   getdNdpt1->SetSavedPoint(91,0);
   getdNdpt1->SetSavedPoint(92,0);
   getdNdpt1->SetSavedPoint(93,0);
   getdNdpt1->SetSavedPoint(94,0);
   getdNdpt1->SetSavedPoint(95,0);
   getdNdpt1->SetSavedPoint(96,0);
   getdNdpt1->SetSavedPoint(97,0);
   getdNdpt1->SetSavedPoint(98,0);
   getdNdpt1->SetSavedPoint(99,0);
   getdNdpt1->SetSavedPoint(100,0);
   getdNdpt1->SetSavedPoint(101,1e-14);
   getdNdpt1->SetSavedPoint(102,100);
   getdNdpt1->SetFillColor(19);
   getdNdpt1->SetFillStyle(0);
   getdNdpt1->SetLineWidth(2);
   getdNdpt1->SetChisquare(6.554914);
   getdNdpt1->SetNDF(6);
   getdNdpt1->SetParameter(0,0.13957);
   getdNdpt1->SetParError(0,0);
   getdNdpt1->SetParLimits(0,0.13957,0.13957);
   getdNdpt1->SetParameter(1,0.9074926);
   getdNdpt1->SetParError(1,0.01084796);
   getdNdpt1->SetParLimits(1,0.5,1);
   getdNdpt1->SetParameter(2,0.06994361);
   getdNdpt1->SetParError(2,0.0008870167);
   getdNdpt1->SetParLimits(2,0,0);
   getdNdpt1->SetParameter(3,0.9992613);
   getdNdpt1->SetParError(3,0.08849525);
   getdNdpt1->SetParLimits(3,0,0);
   getdNdpt1->SetParameter(4,173175.1);
   getdNdpt1->SetParError(4,8324.845);
   getdNdpt1->SetParLimits(4,0,0);
   getdNdpt1->SetParameter(5,0);
   getdNdpt1->SetParError(5,0);
   getdNdpt1->SetParLimits(5,1,1);
   getdNdpt1->SetParent(cent0_pipL_AupLAu_62dO4__1);
   cent0_pipL_AupLAu_62dO4__1->GetListOfFunctions()->Add(getdNdpt1);
   
   TF1 *getdNdpt22 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt22->SetRange(1e-14,100);
   getdNdpt22->SetName("getdNdpt2");
   getdNdpt22->SetTitle("getdNdpt2");
   getdNdpt22->SetSavedPoint(0,743.3621);
   getdNdpt22->SetSavedPoint(1,7.936519);
   getdNdpt22->SetSavedPoint(2,0.1487534);
   getdNdpt22->SetSavedPoint(3,0.003870929);
   getdNdpt22->SetSavedPoint(4,0.0001151546);
   getdNdpt22->SetSavedPoint(5,3.68168e-06);
   getdNdpt22->SetSavedPoint(6,1.231159e-07);
   getdNdpt22->SetSavedPoint(7,4.245044e-09);
   getdNdpt22->SetSavedPoint(8,1.496558e-10);
   getdNdpt22->SetSavedPoint(9,5.365545e-12);
   getdNdpt22->SetSavedPoint(10,1.949234e-13);
   getdNdpt22->SetSavedPoint(11,7.156909e-15);
   getdNdpt22->SetSavedPoint(12,2.650808e-16);
   getdNdpt22->SetSavedPoint(13,9.890145e-18);
   getdNdpt22->SetSavedPoint(14,3.712952e-19);
   getdNdpt22->SetSavedPoint(15,1.401361e-20);
   getdNdpt22->SetSavedPoint(16,5.313624e-22);
   getdNdpt22->SetSavedPoint(17,2.022991e-23);
   getdNdpt22->SetSavedPoint(18,7.729561e-25);
   getdNdpt22->SetSavedPoint(19,2.962802e-26);
   getdNdpt22->SetSavedPoint(20,1.13892e-27);
   getdNdpt22->SetSavedPoint(21,4.389383e-29);
   getdNdpt22->SetSavedPoint(22,1.69562e-30);
   getdNdpt22->SetSavedPoint(23,6.56413e-32);
   getdNdpt22->SetSavedPoint(24,2.546069e-33);
   getdNdpt22->SetSavedPoint(25,9.893235e-35);
   getdNdpt22->SetSavedPoint(26,3.850531e-36);
   getdNdpt22->SetSavedPoint(27,1.500939e-37);
   getdNdpt22->SetSavedPoint(28,5.858929e-39);
   getdNdpt22->SetSavedPoint(29,2.29004e-40);
   getdNdpt22->SetSavedPoint(30,8.961891e-42);
   getdNdpt22->SetSavedPoint(31,3.511184e-43);
   getdNdpt22->SetSavedPoint(32,1.377127e-44);
   getdNdpt22->SetSavedPoint(33,5.406707e-46);
   getdNdpt22->SetSavedPoint(34,2.124735e-47);
   getdNdpt22->SetSavedPoint(35,8.357312e-49);
   getdNdpt22->SetSavedPoint(36,3.290011e-50);
   getdNdpt22->SetSavedPoint(37,1.296216e-51);
   getdNdpt22->SetSavedPoint(38,5.1108e-53);
   getdNdpt22->SetSavedPoint(39,2.01658e-54);
   getdNdpt22->SetSavedPoint(40,7.962361e-56);
   getdNdpt22->SetSavedPoint(41,3.145965e-57);
   getdNdpt22->SetSavedPoint(42,1.243765e-58);
   getdNdpt22->SetSavedPoint(43,4.920198e-60);
   getdNdpt22->SetSavedPoint(44,1.94749e-61);
   getdNdpt22->SetSavedPoint(45,7.712685e-63);
   getdNdpt22->SetSavedPoint(46,3.062969e-64);
   getdNdpt22->SetSavedPoint(47,3.698573e-68);
   getdNdpt22->SetSavedPoint(48,1.498719e-69);
   getdNdpt22->SetSavedPoint(49,4.732995e-74);
   getdNdpt22->SetSavedPoint(50,1.849833e-79);
   getdNdpt22->SetSavedPoint(51,4.579136e-81);
   getdNdpt22->SetSavedPoint(52,2.048038e-87);
   getdNdpt22->SetSavedPoint(53,4.094476e-89);
   getdNdpt22->SetSavedPoint(54,2.560113e-96);
   getdNdpt22->SetSavedPoint(55,4.036016e-98);
   getdNdpt22->SetSavedPoint(56,8.511509e-100);
   getdNdpt22->SetSavedPoint(57,5.540417e-108);
   getdNdpt22->SetSavedPoint(58,6.790056e-110);
   getdNdpt22->SetSavedPoint(59,1.414405e-118);
   getdNdpt22->SetSavedPoint(60,1.325519e-120);
   getdNdpt22->SetSavedPoint(61,9.021734e-130);
   getdNdpt22->SetSavedPoint(62,6.452709e-132);
   getdNdpt22->SetSavedPoint(63,1.947679e-141);
   getdNdpt22->SetSavedPoint(64,1.063282e-143);
   getdNdpt22->SetSavedPoint(65,1.999862e-153);
   getdNdpt22->SetSavedPoint(66,8.627346e-156);
   getdNdpt22->SetSavedPoint(67,1.407337e-165);
   getdNdpt22->SetSavedPoint(68,3.839645e-175);
   getdNdpt22->SetSavedPoint(69,6.042487e-178);
   getdNdpt22->SetSavedPoint(70,5.285443e-187);
   getdNdpt22->SetSavedPoint(71,7.642403e-196);
   getdNdpt22->SetSavedPoint(72,2.273112e-208);
   getdNdpt22->SetSavedPoint(73,8.334804e-219);
   getdNdpt22->SetSavedPoint(74,1.637531e-232);
   getdNdpt22->SetSavedPoint(75,7.299626e-247);
   getdNdpt22->SetSavedPoint(76,4.788321e-271);
   getdNdpt22->SetSavedPoint(77,1.938602e-307);
   getdNdpt22->SetSavedPoint(78,0);
   getdNdpt22->SetSavedPoint(79,0);
   getdNdpt22->SetSavedPoint(80,0);
   getdNdpt22->SetSavedPoint(81,0);
   getdNdpt22->SetSavedPoint(82,0);
   getdNdpt22->SetSavedPoint(83,0);
   getdNdpt22->SetSavedPoint(84,0);
   getdNdpt22->SetSavedPoint(85,0);
   getdNdpt22->SetSavedPoint(86,0);
   getdNdpt22->SetSavedPoint(87,0);
   getdNdpt22->SetSavedPoint(88,0);
   getdNdpt22->SetSavedPoint(89,0);
   getdNdpt22->SetSavedPoint(90,0);
   getdNdpt22->SetSavedPoint(91,0);
   getdNdpt22->SetSavedPoint(92,0);
   getdNdpt22->SetSavedPoint(93,0);
   getdNdpt22->SetSavedPoint(94,0);
   getdNdpt22->SetSavedPoint(95,0);
   getdNdpt22->SetSavedPoint(96,0);
   getdNdpt22->SetSavedPoint(97,0);
   getdNdpt22->SetSavedPoint(98,0);
   getdNdpt22->SetSavedPoint(99,0);
   getdNdpt22->SetSavedPoint(100,0);
   getdNdpt22->SetSavedPoint(101,1e-14);
   getdNdpt22->SetSavedPoint(102,100);
   getdNdpt22->SetFillColor(19);
   getdNdpt22->SetFillStyle(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   getdNdpt22->SetLineColor(ci);
   getdNdpt22->SetLineWidth(2);
   getdNdpt22->SetChisquare(7.733326);
   getdNdpt22->SetNDF(6);
   getdNdpt22->SetParameter(0,0.13957);
   getdNdpt22->SetParError(0,0);
   getdNdpt22->SetParLimits(0,0.13957,0.13957);
   getdNdpt22->SetParameter(1,0.8);
   getdNdpt22->SetParError(1,0.03116309);
   getdNdpt22->SetParLimits(1,0.3,0.8);
   getdNdpt22->SetParameter(2,0.1039538);
   getdNdpt22->SetParError(2,0.01361976);
   getdNdpt22->SetParLimits(2,0.08,0.2);
   getdNdpt22->SetParameter(3,1.325768);
   getdNdpt22->SetParError(3,0.529855);
   getdNdpt22->SetParLimits(3,0.01,5);
   getdNdpt22->SetParameter(4,43200.43);
   getdNdpt22->SetParError(4,18509.64);
   getdNdpt22->SetParLimits(4,0,0);
   getdNdpt22->SetParameter(5,0);
   getdNdpt22->SetParError(5,0);
   getdNdpt22->SetParLimits(5,1,1);
   getdNdpt22->SetParent(cent0_pipL_AupLAu_62dO4__1);
   cent0_pipL_AupLAu_62dO4__1->GetListOfFunctions()->Add(getdNdpt22);
   
   TF1 *getdNdptHAGE3 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE3->SetRange(1e-12,100);
   getdNdptHAGE3->SetName("getdNdptHAGE");
   getdNdptHAGE3->SetTitle("getdNdptHAGE");
   getdNdptHAGE3->SetSavedPoint(0,927.0348);
   getdNdptHAGE3->SetSavedPoint(1,10.92121);
   getdNdptHAGE3->SetSavedPoint(2,0.5012433);
   getdNdptHAGE3->SetSavedPoint(3,0.04216956);
   getdNdptHAGE3->SetSavedPoint(4,0.005121484);
   getdNdptHAGE3->SetSavedPoint(5,0.0008076021);
   getdNdptHAGE3->SetSavedPoint(6,0.0001554382);
   getdNdptHAGE3->SetSavedPoint(7,3.505697e-05);
   getdNdptHAGE3->SetSavedPoint(8,9.00178e-06);
   getdNdptHAGE3->SetSavedPoint(9,2.57603e-06);
   getdNdptHAGE3->SetSavedPoint(10,8.082545e-07);
   getdNdptHAGE3->SetSavedPoint(11,2.745056e-07);
   getdNdptHAGE3->SetSavedPoint(12,9.988472e-08);
   getdNdptHAGE3->SetSavedPoint(13,3.861511e-08);
   getdNdptHAGE3->SetSavedPoint(14,1.575154e-08);
   getdNdptHAGE3->SetSavedPoint(15,6.740387e-09);
   getdNdptHAGE3->SetSavedPoint(16,3.011061e-09);
   getdNdptHAGE3->SetSavedPoint(17,1.39835e-09);
   getdNdptHAGE3->SetSavedPoint(18,6.726904e-10);
   getdNdptHAGE3->SetSavedPoint(19,3.341698e-10);
   getdNdptHAGE3->SetSavedPoint(20,1.709595e-10);
   getdNdptHAGE3->SetSavedPoint(21,8.985841e-11);
   getdNdptHAGE3->SetSavedPoint(22,4.842284e-11);
   getdNdptHAGE3->SetSavedPoint(23,2.670285e-11);
   getdNdptHAGE3->SetSavedPoint(24,1.504382e-11);
   getdNdptHAGE3->SetSavedPoint(25,8.645806e-12);
   getdNdptHAGE3->SetSavedPoint(26,5.061953e-12);
   getdNdptHAGE3->SetSavedPoint(27,3.015586e-12);
   getdNdptHAGE3->SetSavedPoint(28,1.825961e-12);
   getdNdptHAGE3->SetSavedPoint(29,1.122655e-12);
   getdNdptHAGE3->SetSavedPoint(30,7.002335e-13);
   getdNdptHAGE3->SetSavedPoint(31,4.427136e-13);
   getdNdptHAGE3->SetSavedPoint(32,2.835027e-13);
   getdNdptHAGE3->SetSavedPoint(33,1.837571e-13);
   getdNdptHAGE3->SetSavedPoint(34,1.204775e-13);
   getdNdptHAGE3->SetSavedPoint(35,7.985198e-14);
   getdNdptHAGE3->SetSavedPoint(36,5.34745e-14);
   getdNdptHAGE3->SetSavedPoint(37,3.616342e-14);
   getdNdptHAGE3->SetSavedPoint(38,2.468596e-14);
   getdNdptHAGE3->SetSavedPoint(39,1.700195e-14);
   getdNdptHAGE3->SetSavedPoint(40,1.180971e-14);
   getdNdptHAGE3->SetSavedPoint(41,8.270026e-15);
   getdNdptHAGE3->SetSavedPoint(42,5.836435e-15);
   getdNdptHAGE3->SetSavedPoint(43,4.149707e-15);
   getdNdptHAGE3->SetSavedPoint(44,2.971538e-15);
   getdNdptHAGE3->SetSavedPoint(45,2.142459e-15);
   getdNdptHAGE3->SetSavedPoint(46,1.554863e-15);
   getdNdptHAGE3->SetSavedPoint(47,1.135554e-15);
   getdNdptHAGE3->SetSavedPoint(48,8.343619e-16);
   getdNdptHAGE3->SetSavedPoint(49,6.166406e-16);
   getdNdptHAGE3->SetSavedPoint(50,4.582969e-16);
   getdNdptHAGE3->SetSavedPoint(51,3.424602e-16);
   getdNdptHAGE3->SetSavedPoint(52,2.572393e-16);
   getdNdptHAGE3->SetSavedPoint(53,1.942e-16);
   getdNdptHAGE3->SetSavedPoint(54,1.473228e-16);
   getdNdptHAGE3->SetSavedPoint(55,1.122867e-16);
   getdNdptHAGE3->SetSavedPoint(56,8.597177e-17);
   getdNdptHAGE3->SetSavedPoint(57,6.611317e-17);
   getdNdptHAGE3->SetSavedPoint(58,5.105793e-17);
   getdNdptHAGE3->SetSavedPoint(59,3.959339e-17);
   getdNdptHAGE3->SetSavedPoint(60,3.082554e-17);
   getdNdptHAGE3->SetSavedPoint(61,2.409206e-17);
   getdNdptHAGE3->SetSavedPoint(62,1.889999e-17);
   getdNdptHAGE3->SetSavedPoint(63,1.488075e-17);
   getdNdptHAGE3->SetSavedPoint(64,1.175757e-17);
   getdNdptHAGE3->SetSavedPoint(65,9.321703e-18);
   getdNdptHAGE3->SetSavedPoint(66,7.41507e-18);
   getdNdptHAGE3->SetSavedPoint(67,5.917483e-18);
   getdNdptHAGE3->SetSavedPoint(68,4.737197e-18);
   getdNdptHAGE3->SetSavedPoint(69,3.803919e-18);
   getdNdptHAGE3->SetSavedPoint(70,3.063588e-18);
   getdNdptHAGE3->SetSavedPoint(71,2.474484e-18);
   getdNdptHAGE3->SetSavedPoint(72,2.004291e-18);
   getdNdptHAGE3->SetSavedPoint(73,1.627897e-18);
   getdNdptHAGE3->SetSavedPoint(74,1.325723e-18);
   getdNdptHAGE3->SetSavedPoint(75,1.082452e-18);
   getdNdptHAGE3->SetSavedPoint(76,8.86067e-19);
   getdNdptHAGE3->SetSavedPoint(77,7.271082e-19);
   getdNdptHAGE3->SetSavedPoint(78,5.981084e-19);
   getdNdptHAGE3->SetSavedPoint(79,4.931554e-19);
   getdNdptHAGE3->SetSavedPoint(80,4.075552e-19);
   getdNdptHAGE3->SetSavedPoint(81,3.375703e-19);
   getdNdptHAGE3->SetSavedPoint(82,2.80217e-19);
   getdNdptHAGE3->SetSavedPoint(83,2.331069e-19);
   getdNdptHAGE3->SetSavedPoint(84,1.943235e-19);
   getdNdptHAGE3->SetSavedPoint(85,1.623246e-19);
   getdNdptHAGE3->SetSavedPoint(86,1.358665e-19);
   getdNdptHAGE3->SetSavedPoint(87,1.139438e-19);
   getdNdptHAGE3->SetSavedPoint(88,9.574149e-20);
   getdNdptHAGE3->SetSavedPoint(89,8.059784e-20);
   getdNdptHAGE3->SetSavedPoint(90,6.7974e-20);
   getdNdptHAGE3->SetSavedPoint(91,5.743039e-20);
   getdNdptHAGE3->SetSavedPoint(92,4.860757e-20);
   getdNdptHAGE3->SetSavedPoint(93,4.121104e-20);
   getdNdptHAGE3->SetSavedPoint(94,3.499898e-20);
   getdNdptHAGE3->SetSavedPoint(95,2.977245e-20);
   getdNdptHAGE3->SetSavedPoint(96,2.536745e-20);
   getdNdptHAGE3->SetSavedPoint(97,2.164852e-20);
   getdNdptHAGE3->SetSavedPoint(98,1.850355e-20);
   getdNdptHAGE3->SetSavedPoint(99,1.583961e-20);
   getdNdptHAGE3->SetSavedPoint(100,1.357949e-20);
   getdNdptHAGE3->SetSavedPoint(101,1e-12);
   getdNdptHAGE3->SetSavedPoint(102,100);
   getdNdptHAGE3->SetFillColor(19);
   getdNdptHAGE3->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE3->SetLineColor(ci);
   getdNdptHAGE3->SetLineWidth(2);
   getdNdptHAGE3->SetChisquare(78.0764);
   getdNdptHAGE3->SetNDF(7);
   getdNdptHAGE3->SetParameter(0,0.13957);
   getdNdptHAGE3->SetParError(0,0);
   getdNdptHAGE3->SetParLimits(0,0.13957,0.13957);
   getdNdptHAGE3->SetParameter(1,3.166148);
   getdNdptHAGE3->SetParError(1,0.009583184);
   getdNdptHAGE3->SetParLimits(1,0,0);
   getdNdptHAGE3->SetParameter(2,200);
   getdNdptHAGE3->SetParError(2,0.3103169);
   getdNdptHAGE3->SetParLimits(2,50,200);
   getdNdptHAGE3->SetParameter(3,15);
   getdNdptHAGE3->SetParError(3,0.2951089);
   getdNdptHAGE3->SetParLimits(3,5,15);
   getdNdptHAGE3->SetParameter(4,0);
   getdNdptHAGE3->SetParError(4,0);
   getdNdptHAGE3->SetParLimits(4,1,1);
   getdNdptHAGE3->SetParent(cent0_pipL_AupLAu_62dO4__1);
   cent0_pipL_AupLAu_62dO4__1->GetListOfFunctions()->Add(getdNdptHAGE3);

   ci = TColor::GetColor("#000099");
   cent0_pipL_AupLAu_62dO4__1->SetLineColor(ci);
   cent0_pipL_AupLAu_62dO4__1->SetMarkerStyle(20);
   cent0_pipL_AupLAu_62dO4__1->GetXaxis()->SetRange(0,11);
   cent0_pipL_AupLAu_62dO4__1->GetXaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_62dO4__1->GetXaxis()->SetLabelSize(0.035);
   cent0_pipL_AupLAu_62dO4__1->GetXaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_62dO4__1->GetXaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_62dO4__1->GetYaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_62dO4__1->GetYaxis()->SetLabelSize(0.1);
   cent0_pipL_AupLAu_62dO4__1->GetYaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_62dO4__1->GetYaxis()->SetTitleOffset(0);
   cent0_pipL_AupLAu_62dO4__1->GetYaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_62dO4__1->GetZaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_62dO4__1->GetZaxis()->SetLabelSize(0.035);
   cent0_pipL_AupLAu_62dO4__1->GetZaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_62dO4__1->GetZaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_62dO4__1->Draw("");
   TLatex *   tex = new TLatex(0.1,90,"#pi^{+} 62.4 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part1->Modified();
   c->cd();
  
// ------------>Primitives in pad: part2
   TPad *part2 = new TPad("part2", "part2",0.3733333,0.7066667,0.6866667,1);
   part2->Draw();
   part2->cd();
   part2->Range(-0.04,1.260468,1.54,3.311764);
   part2->SetFillColor(0);
   part2->SetBorderMode(0);
   part2->SetBorderSize(0);
   part2->SetLogy();
   part2->SetLeftMargin(0);
   part2->SetRightMargin(0);
   part2->SetTopMargin(0.03);
   part2->SetBottomMargin(0);
   part2->SetFrameBorderMode(0);
   part2->SetFrameBorderMode(0);
   Double_t xAxis2[11] = {0.23, 0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72}; 
   
   TH1D *cent0_pipL_AupLAu_130__2 = new TH1D("cent0_pipL_AupLAu_130__2","cent0_pi+_Au+Au_130",10, xAxis2);
   cent0_pipL_AupLAu_130__2->SetBinContent(1,362.8691);
   cent0_pipL_AupLAu_130__2->SetBinContent(2,275.0515);
   cent0_pipL_AupLAu_130__2->SetBinContent(3,209.8039);
   cent0_pipL_AupLAu_130__2->SetBinContent(4,160.3239);
   cent0_pipL_AupLAu_130__2->SetBinContent(5,124.5709);
   cent0_pipL_AupLAu_130__2->SetBinContent(6,96.9626);
   cent0_pipL_AupLAu_130__2->SetBinContent(7,76.6678);
   cent0_pipL_AupLAu_130__2->SetBinContent(8,59.412);
   cent0_pipL_AupLAu_130__2->SetBinContent(9,47.1458);
   cent0_pipL_AupLAu_130__2->SetBinContent(10,36.8889);
   cent0_pipL_AupLAu_130__2->SetBinError(1,7.81417);
   cent0_pipL_AupLAu_130__2->SetBinError(2,5.70672);
   cent0_pipL_AupLAu_130__2->SetBinError(3,2.39715);
   cent0_pipL_AupLAu_130__2->SetBinError(4,1.83359);
   cent0_pipL_AupLAu_130__2->SetBinError(5,1.48022);
   cent0_pipL_AupLAu_130__2->SetBinError(6,1.14217);
   cent0_pipL_AupLAu_130__2->SetBinError(7,1.5424);
   cent0_pipL_AupLAu_130__2->SetBinError(8,1.7774);
   cent0_pipL_AupLAu_130__2->SetBinError(9,1.42461);
   cent0_pipL_AupLAu_130__2->SetBinError(10,0.4154);
   cent0_pipL_AupLAu_130__2->SetEntries(10);
   
   TF1 *getdNdpt4 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt4->SetRange(1e-14,100);
   getdNdpt4->SetName("getdNdpt");
   getdNdpt4->SetTitle("getdNdpt");
   getdNdpt4->SetSavedPoint(0,800.7362);
   getdNdpt4->SetSavedPoint(1,12.51239);
   getdNdpt4->SetSavedPoint(2,1.488535);
   getdNdpt4->SetSavedPoint(3,0.3377538);
   getdNdpt4->SetSavedPoint(4,6.925251e-07);
   getdNdpt4->SetSavedPoint(5,3.695545e-09);
   getdNdpt4->SetSavedPoint(6,1.961341e-11);
   getdNdpt4->SetSavedPoint(7,1.037594e-13);
   getdNdpt4->SetSavedPoint(8,5.47797e-16);
   getdNdpt4->SetSavedPoint(9,2.888168e-18);
   getdNdpt4->SetSavedPoint(10,1.521291e-20);
   getdNdpt4->SetSavedPoint(11,8.007582e-23);
   getdNdpt4->SetSavedPoint(12,4.212744e-25);
   getdNdpt4->SetSavedPoint(13,2.215416e-27);
   getdNdpt4->SetSavedPoint(14,1.164686e-29);
   getdNdpt4->SetSavedPoint(15,6.121441e-32);
   getdNdpt4->SetSavedPoint(16,3.216693e-34);
   getdNdpt4->SetSavedPoint(17,1.690023e-36);
   getdNdpt4->SetSavedPoint(18,8.877987e-39);
   getdNdpt4->SetSavedPoint(19,4.663212e-41);
   getdNdpt4->SetSavedPoint(20,2.456468e-43);
   getdNdpt4->SetSavedPoint(21,1.038107e-64);
   getdNdpt4->SetSavedPoint(22,6.63472e-68);
   getdNdpt4->SetSavedPoint(23,4.240161e-71);
   getdNdpt4->SetSavedPoint(24,2.709718e-74);
   getdNdpt4->SetSavedPoint(25,1.731609e-77);
   getdNdpt4->SetSavedPoint(26,1.106521e-80);
   getdNdpt4->SetSavedPoint(27,7.243821e-100);
   getdNdpt4->SetSavedPoint(28,1.181518e-103);
   getdNdpt4->SetSavedPoint(29,1.9271e-107);
   getdNdpt4->SetSavedPoint(30,1.42056e-123);
   getdNdpt4->SetSavedPoint(31,9.006116e-128);
   getdNdpt4->SetSavedPoint(32,5.119215e-141);
   getdNdpt4->SetSavedPoint(33,2.113887e-151);
   getdNdpt4->SetSavedPoint(34,0);
   getdNdpt4->SetSavedPoint(35,0);
   getdNdpt4->SetSavedPoint(36,0);
   getdNdpt4->SetSavedPoint(37,0);
   getdNdpt4->SetSavedPoint(38,0);
   getdNdpt4->SetSavedPoint(39,0);
   getdNdpt4->SetSavedPoint(40,0);
   getdNdpt4->SetSavedPoint(41,0);
   getdNdpt4->SetSavedPoint(42,0);
   getdNdpt4->SetSavedPoint(43,0);
   getdNdpt4->SetSavedPoint(44,0);
   getdNdpt4->SetSavedPoint(45,0);
   getdNdpt4->SetSavedPoint(46,0);
   getdNdpt4->SetSavedPoint(47,0);
   getdNdpt4->SetSavedPoint(48,0);
   getdNdpt4->SetSavedPoint(49,0);
   getdNdpt4->SetSavedPoint(50,0);
   getdNdpt4->SetSavedPoint(51,0);
   getdNdpt4->SetSavedPoint(52,0);
   getdNdpt4->SetSavedPoint(53,0);
   getdNdpt4->SetSavedPoint(54,0);
   getdNdpt4->SetSavedPoint(55,0);
   getdNdpt4->SetSavedPoint(56,0);
   getdNdpt4->SetSavedPoint(57,0);
   getdNdpt4->SetSavedPoint(58,0);
   getdNdpt4->SetSavedPoint(59,0);
   getdNdpt4->SetSavedPoint(60,0);
   getdNdpt4->SetSavedPoint(61,0);
   getdNdpt4->SetSavedPoint(62,0);
   getdNdpt4->SetSavedPoint(63,0);
   getdNdpt4->SetSavedPoint(64,0);
   getdNdpt4->SetSavedPoint(65,0);
   getdNdpt4->SetSavedPoint(66,0);
   getdNdpt4->SetSavedPoint(67,0);
   getdNdpt4->SetSavedPoint(68,0);
   getdNdpt4->SetSavedPoint(69,0);
   getdNdpt4->SetSavedPoint(70,0);
   getdNdpt4->SetSavedPoint(71,0);
   getdNdpt4->SetSavedPoint(72,0);
   getdNdpt4->SetSavedPoint(73,0);
   getdNdpt4->SetSavedPoint(74,0);
   getdNdpt4->SetSavedPoint(75,0);
   getdNdpt4->SetSavedPoint(76,0);
   getdNdpt4->SetSavedPoint(77,0);
   getdNdpt4->SetSavedPoint(78,0);
   getdNdpt4->SetSavedPoint(79,0);
   getdNdpt4->SetSavedPoint(80,0);
   getdNdpt4->SetSavedPoint(81,0);
   getdNdpt4->SetSavedPoint(82,0);
   getdNdpt4->SetSavedPoint(83,0);
   getdNdpt4->SetSavedPoint(84,0);
   getdNdpt4->SetSavedPoint(85,0);
   getdNdpt4->SetSavedPoint(86,0);
   getdNdpt4->SetSavedPoint(87,0);
   getdNdpt4->SetSavedPoint(88,0);
   getdNdpt4->SetSavedPoint(89,0);
   getdNdpt4->SetSavedPoint(90,0);
   getdNdpt4->SetSavedPoint(91,0);
   getdNdpt4->SetSavedPoint(92,0);
   getdNdpt4->SetSavedPoint(93,0);
   getdNdpt4->SetSavedPoint(94,0);
   getdNdpt4->SetSavedPoint(95,0);
   getdNdpt4->SetSavedPoint(96,0);
   getdNdpt4->SetSavedPoint(97,0);
   getdNdpt4->SetSavedPoint(98,0);
   getdNdpt4->SetSavedPoint(99,0);
   getdNdpt4->SetSavedPoint(100,0);
   getdNdpt4->SetSavedPoint(101,1e-14);
   getdNdpt4->SetSavedPoint(102,100);
   getdNdpt4->SetFillColor(19);
   getdNdpt4->SetFillStyle(0);
   getdNdpt4->SetLineWidth(2);
   getdNdpt4->SetChisquare(11.52087);
   getdNdpt4->SetNDF(6);
   getdNdpt4->SetParameter(0,0.13957);
   getdNdpt4->SetParError(0,0);
   getdNdpt4->SetParLimits(0,0.13957,0.13957);
   getdNdpt4->SetParameter(1,0.5);
   getdNdpt4->SetParError(1,0.05210365);
   getdNdpt4->SetParLimits(1,0.5,1);
   getdNdpt4->SetParameter(2,0.0528027);
   getdNdpt4->SetParError(2,0.0004176268);
   getdNdpt4->SetParLimits(2,0,0);
   getdNdpt4->SetParameter(3,-4.657457);
   getdNdpt4->SetParError(3,0.3806186);
   getdNdpt4->SetParLimits(3,0,0);
   getdNdpt4->SetParameter(4,2464476);
   getdNdpt4->SetParError(4,137670.1);
   getdNdpt4->SetParLimits(4,0,0);
   getdNdpt4->SetParameter(5,0);
   getdNdpt4->SetParError(5,0);
   getdNdpt4->SetParLimits(5,1,1);
   getdNdpt4->SetParent(cent0_pipL_AupLAu_130__2);
   cent0_pipL_AupLAu_130__2->GetListOfFunctions()->Add(getdNdpt4);
   
   TF1 *getdNdpt25 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt25->SetRange(1e-14,100);
   getdNdpt25->SetName("getdNdpt2");
   getdNdpt25->SetTitle("getdNdpt2");
   getdNdpt25->SetSavedPoint(0,890.3003);
   getdNdpt25->SetSavedPoint(1,9.461369);
   getdNdpt25->SetSavedPoint(2,0.1832006);
   getdNdpt25->SetSavedPoint(3,0.004978587);
   getdNdpt25->SetSavedPoint(4,0.0001550367);
   getdNdpt25->SetSavedPoint(5,5.193371e-06);
   getdNdpt25->SetSavedPoint(6,1.820352e-07);
   getdNdpt25->SetSavedPoint(7,6.580609e-09);
   getdNdpt25->SetSavedPoint(8,2.432677e-10);
   getdNdpt25->SetSavedPoint(9,9.146493e-12);
   getdNdpt25->SetSavedPoint(10,3.484848e-13);
   getdNdpt25->SetSavedPoint(11,1.341979e-14);
   getdNdpt25->SetSavedPoint(12,5.213327e-16);
   getdNdpt25->SetSavedPoint(13,2.040176e-17);
   getdNdpt25->SetSavedPoint(14,8.033825e-19);
   getdNdpt25->SetSavedPoint(15,3.180523e-20);
   getdNdpt25->SetSavedPoint(16,1.265001e-21);
   getdNdpt25->SetSavedPoint(17,5.051853e-23);
   getdNdpt25->SetSavedPoint(18,2.024756e-24);
   getdNdpt25->SetSavedPoint(19,8.141136e-26);
   getdNdpt25->SetSavedPoint(20,3.282791e-27);
   getdNdpt25->SetSavedPoint(21,1.327163e-28);
   getdNdpt25->SetSavedPoint(22,5.37802e-30);
   getdNdpt25->SetSavedPoint(23,2.18397e-31);
   getdNdpt25->SetSavedPoint(24,8.886226e-33);
   getdNdpt25->SetSavedPoint(25,3.622141e-34);
   getdNdpt25->SetSavedPoint(26,1.478869e-35);
   getdNdpt25->SetSavedPoint(27,6.04723e-37);
   getdNdpt25->SetSavedPoint(28,2.476269e-38);
   getdNdpt25->SetSavedPoint(29,1.01534e-39);
   getdNdpt25->SetSavedPoint(30,4.168296e-41);
   getdNdpt25->SetSavedPoint(31,1.71319e-42);
   getdNdpt25->SetSavedPoint(32,7.048898e-44);
   getdNdpt25->SetSavedPoint(33,2.903205e-45);
   getdNdpt25->SetSavedPoint(34,1.196877e-46);
   getdNdpt25->SetSavedPoint(35,4.938709e-48);
   getdNdpt25->SetSavedPoint(36,2.039616e-49);
   getdNdpt25->SetSavedPoint(37,8.430139e-51);
   getdNdpt25->SetSavedPoint(38,3.487022e-52);
   getdNdpt25->SetSavedPoint(39,1.443416e-53);
   getdNdpt25->SetSavedPoint(40,5.979017e-55);
   getdNdpt25->SetSavedPoint(41,2.478307e-56);
   getdNdpt25->SetSavedPoint(42,1.027908e-57);
   getdNdpt25->SetSavedPoint(43,4.265936e-59);
   getdNdpt25->SetSavedPoint(44,1.771429e-60);
   getdNdpt25->SetSavedPoint(45,7.359887e-62);
   getdNdpt25->SetSavedPoint(46,3.059469e-63);
   getdNdpt25->SetSavedPoint(47,1.288348e-64);
   getdNdpt25->SetSavedPoint(48,1.021545e-68);
   getdNdpt25->SetSavedPoint(49,2.888753e-73);
   getdNdpt25->SetSavedPoint(50,8.888653e-75);
   getdNdpt25->SetSavedPoint(51,2.037647e-80);
   getdNdpt25->SetSavedPoint(52,5.178374e-82);
   getdNdpt25->SetSavedPoint(53,1.248714e-88);
   getdNdpt25->SetSavedPoint(54,2.541893e-90);
   getdNdpt25->SetSavedPoint(55,4.302792e-92);
   getdNdpt25->SetSavedPoint(56,1.286813e-99);
   getdNdpt25->SetSavedPoint(57,2.053132e-101);
   getdNdpt25->SetSavedPoint(58,8.705149e-110);
   getdNdpt25->SetSavedPoint(59,1.065293e-111);
   getdNdpt25->SetSavedPoint(60,1.076923e-120);
   getdNdpt25->SetSavedPoint(61,1.002803e-122);
   getdNdpt25->SetSavedPoint(62,8.886613e-125);
   getdNdpt25->SetSavedPoint(63,2.359737e-134);
   getdNdpt25->SetSavedPoint(64,1.615542e-136);
   getdNdpt25->SetSavedPoint(65,1.927235e-146);
   getdNdpt25->SetSavedPoint(66,1.032505e-148);
   getdNdpt25->SetSavedPoint(67,7.856847e-159);
   getdNdpt25->SetSavedPoint(68,7.445203e-169);
   getdNdpt25->SetSavedPoint(69,2.342958e-171);
   getdNdpt25->SetSavedPoint(70,3.06696e-181);
   getdNdpt25->SetSavedPoint(71,1.014752e-190);
   getdNdpt25->SetSavedPoint(72,1.214596e-199);
   getdNdpt25->SetSavedPoint(73,7.090543e-208);
   getdNdpt25->SetSavedPoint(74,6.796807e-219);
   getdNdpt25->SetSavedPoint(75,4.413575e-229);
   getdNdpt25->SetSavedPoint(76,2.66865e-245);
   getdNdpt25->SetSavedPoint(77,8.586322e-268);
   getdNdpt25->SetSavedPoint(78,1.146963e-298);
   getdNdpt25->SetSavedPoint(79,0);
   getdNdpt25->SetSavedPoint(80,0);
   getdNdpt25->SetSavedPoint(81,0);
   getdNdpt25->SetSavedPoint(82,0);
   getdNdpt25->SetSavedPoint(83,0);
   getdNdpt25->SetSavedPoint(84,0);
   getdNdpt25->SetSavedPoint(85,0);
   getdNdpt25->SetSavedPoint(86,0);
   getdNdpt25->SetSavedPoint(87,0);
   getdNdpt25->SetSavedPoint(88,0);
   getdNdpt25->SetSavedPoint(89,0);
   getdNdpt25->SetSavedPoint(90,0);
   getdNdpt25->SetSavedPoint(91,0);
   getdNdpt25->SetSavedPoint(92,0);
   getdNdpt25->SetSavedPoint(93,0);
   getdNdpt25->SetSavedPoint(94,0);
   getdNdpt25->SetSavedPoint(95,0);
   getdNdpt25->SetSavedPoint(96,0);
   getdNdpt25->SetSavedPoint(97,0);
   getdNdpt25->SetSavedPoint(98,0);
   getdNdpt25->SetSavedPoint(99,0);
   getdNdpt25->SetSavedPoint(100,0);
   getdNdpt25->SetSavedPoint(101,1e-14);
   getdNdpt25->SetSavedPoint(102,100);
   getdNdpt25->SetFillColor(19);
   getdNdpt25->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt25->SetLineColor(ci);
   getdNdpt25->SetLineWidth(2);
   getdNdpt25->SetChisquare(17.86281);
   getdNdpt25->SetNDF(6);
   getdNdpt25->SetParameter(0,0.13957);
   getdNdpt25->SetParError(0,0);
   getdNdpt25->SetParLimits(0,0.13957,0.13957);
   getdNdpt25->SetParameter(1,0.8);
   getdNdpt25->SetParError(1,0.008822761);
   getdNdpt25->SetParLimits(1,0.3,0.8);
   getdNdpt25->SetParameter(2,0.1055295);
   getdNdpt25->SetParError(2,0.006551885);
   getdNdpt25->SetParLimits(2,0.08,0.2);
   getdNdpt25->SetParameter(3,1.411569);
   getdNdpt25->SetParError(3,0.2718173);
   getdNdpt25->SetParLimits(3,0.01,5);
   getdNdpt25->SetParameter(4,49321.52);
   getdNdpt25->SetParError(4,9950.781);
   getdNdpt25->SetParLimits(4,0,0);
   getdNdpt25->SetParameter(5,0);
   getdNdpt25->SetParError(5,0);
   getdNdpt25->SetParLimits(5,1,1);
   getdNdpt25->SetParent(cent0_pipL_AupLAu_130__2);
   cent0_pipL_AupLAu_130__2->GetListOfFunctions()->Add(getdNdpt25);
   
   TF1 *getdNdptHAGE6 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE6->SetRange(1e-12,100);
   getdNdptHAGE6->SetName("getdNdptHAGE");
   getdNdptHAGE6->SetTitle("getdNdptHAGE");
   getdNdptHAGE6->SetSavedPoint(0,968.9783);
   getdNdptHAGE6->SetSavedPoint(1,14.36004);
   getdNdptHAGE6->SetSavedPoint(2,0.7990185);
   getdNdptHAGE6->SetSavedPoint(3,0.07771414);
   getdNdptHAGE6->SetSavedPoint(4,0.010567);
   getdNdptHAGE6->SetSavedPoint(5,0.001823978);
   getdNdptHAGE6->SetSavedPoint(6,0.0003780221);
   getdNdptHAGE6->SetSavedPoint(7,9.068191e-05);
   getdNdptHAGE6->SetSavedPoint(8,2.453263e-05);
   getdNdptHAGE6->SetSavedPoint(9,7.341756e-06);
   getdNdptHAGE6->SetSavedPoint(10,2.394644e-06);
   getdNdptHAGE6->SetSavedPoint(11,8.413634e-07);
   getdNdptHAGE6->SetSavedPoint(12,3.154553e-07);
   getdNdptHAGE6->SetSavedPoint(13,1.252443e-07);
   getdNdptHAGE6->SetSavedPoint(14,5.232019e-08);
   getdNdptHAGE6->SetSavedPoint(15,2.287401e-08);
   getdNdptHAGE6->SetSavedPoint(16,1.041842e-08);
   getdNdptHAGE6->SetSavedPoint(17,4.924447e-09);
   getdNdptHAGE6->SetSavedPoint(18,2.407412e-09);
   getdNdptHAGE6->SetSavedPoint(19,1.213706e-09);
   getdNdptHAGE6->SetSavedPoint(20,6.294157e-10);
   getdNdptHAGE6->SetSavedPoint(21,3.350022e-10);
   getdNdptHAGE6->SetSavedPoint(22,1.826336e-10);
   getdNdptHAGE6->SetSavedPoint(23,1.018051e-10);
   getdNdptHAGE6->SetSavedPoint(24,5.793337e-11);
   getdNdptHAGE6->SetSavedPoint(25,3.360812e-11);
   getdNdptHAGE6->SetSavedPoint(26,1.98501e-11);
   getdNdptHAGE6->SetSavedPoint(27,1.192297e-11);
   getdNdptHAGE6->SetSavedPoint(28,7.275384e-12);
   getdNdptHAGE6->SetSavedPoint(29,4.505731e-12);
   getdNdptHAGE6->SetSavedPoint(30,2.829675e-12);
   getdNdptHAGE6->SetSavedPoint(31,1.800635e-12);
   getdNdptHAGE6->SetSavedPoint(32,1.160159e-12);
   getdNdptHAGE6->SetSavedPoint(33,7.563489e-13);
   getdNdptHAGE6->SetSavedPoint(34,4.98623e-13);
   getdNdptHAGE6->SetSavedPoint(35,3.322166e-13);
   getdNdptHAGE6->SetSavedPoint(36,2.235841e-13);
   getdNdptHAGE6->SetSavedPoint(37,1.519215e-13);
   getdNdptHAGE6->SetSavedPoint(38,1.041741e-13);
   getdNdptHAGE6->SetSavedPoint(39,7.205758e-14);
   getdNdptHAGE6->SetSavedPoint(40,5.025834e-14);
   getdNdptHAGE6->SetSavedPoint(41,3.533344e-14);
   getdNdptHAGE6->SetSavedPoint(42,2.503018e-14);
   getdNdptHAGE6->SetSavedPoint(43,1.786089e-14);
   getdNdptHAGE6->SetSavedPoint(44,1.28343e-14);
   getdNdptHAGE6->SetSavedPoint(45,9.284281e-15);
   getdNdptHAGE6->SetSavedPoint(46,6.759525e-15);
   getdNdptHAGE6->SetSavedPoint(47,4.951843e-15);
   getdNdptHAGE6->SetSavedPoint(48,3.649203e-15);
   getdNdptHAGE6->SetSavedPoint(49,2.70466e-15);
   getdNdptHAGE6->SetSavedPoint(50,2.01567e-15);
   getdNdptHAGE6->SetSavedPoint(51,1.510191e-15);
   getdNdptHAGE6->SetSavedPoint(52,1.137283e-15);
   getdNdptHAGE6->SetSavedPoint(53,8.606987e-16);
   getdNdptHAGE6->SetSavedPoint(54,6.544954e-16);
   getdNdptHAGE6->SetSavedPoint(55,4.999942e-16);
   getdNdptHAGE6->SetSavedPoint(56,3.836718e-16);
   getdNdptHAGE6->SetSavedPoint(57,2.956842e-16);
   getdNdptHAGE6->SetSavedPoint(58,2.288283e-16);
   getdNdptHAGE6->SetSavedPoint(59,1.778064e-16);
   getdNdptHAGE6->SetSavedPoint(60,1.387032e-16);
   getdNdptHAGE6->SetSavedPoint(61,1.086113e-16);
   getdNdptHAGE6->SetSavedPoint(62,8.536172e-17);
   getdNdptHAGE6->SetSavedPoint(63,6.732923e-17);
   getdNdptHAGE6->SetSavedPoint(64,5.329064e-17);
   getdNdptHAGE6->SetSavedPoint(65,4.232155e-17);
   getdNdptHAGE6->SetSavedPoint(66,3.37205e-17);
   getdNdptHAGE6->SetSavedPoint(67,2.695307e-17);
   getdNdptHAGE6->SetSavedPoint(68,2.161058e-17);
   getdNdptHAGE6->SetSavedPoint(69,1.737927e-17);
   getdNdptHAGE6->SetSavedPoint(70,1.401744e-17);
   getdNdptHAGE6->SetSavedPoint(71,1.13382e-17);
   getdNdptHAGE6->SetSavedPoint(72,9.196555e-18);
   getdNdptHAGE6->SetSavedPoint(73,7.479644e-18);
   getdNdptHAGE6->SetSavedPoint(74,6.099319e-18);
   getdNdptHAGE6->SetSavedPoint(75,4.98652e-18);
   getdNdptHAGE6->SetSavedPoint(76,4.086973e-18);
   getdNdptHAGE6->SetSavedPoint(77,3.357896e-18);
   getdNdptHAGE6->SetSavedPoint(78,2.765466e-18);
   getdNdptHAGE6->SetSavedPoint(79,2.282865e-18);
   getdNdptHAGE6->SetSavedPoint(80,1.888768e-18);
   getdNdptHAGE6->SetSavedPoint(81,1.566177e-18);
   getdNdptHAGE6->SetSavedPoint(82,1.3015e-18);
   getdNdptHAGE6->SetSavedPoint(83,1.083846e-18);
   getdNdptHAGE6->SetSavedPoint(84,9.044607e-19);
   getdNdptHAGE6->SetSavedPoint(85,7.562942e-19);
   getdNdptHAGE6->SetSavedPoint(86,6.336526e-19);
   getdNdptHAGE6->SetSavedPoint(87,5.319272e-19);
   getdNdptHAGE6->SetSavedPoint(88,4.473791e-19);
   getdNdptHAGE6->SetSavedPoint(89,3.769675e-19);
   getdNdptHAGE6->SetSavedPoint(90,3.182144e-19);
   getdNdptHAGE6->SetSavedPoint(91,2.690959e-19);
   getdNdptHAGE6->SetSavedPoint(92,2.279552e-19);
   getdNdptHAGE6->SetSavedPoint(93,1.934334e-19);
   getdNdptHAGE6->SetSavedPoint(94,1.644138e-19);
   getdNdptHAGE6->SetSavedPoint(95,1.399765e-19);
   getdNdptHAGE6->SetSavedPoint(96,1.193625e-19);
   getdNdptHAGE6->SetSavedPoint(97,1.019443e-19);
   getdNdptHAGE6->SetSavedPoint(98,8.720209e-20);
   getdNdptHAGE6->SetSavedPoint(99,7.47045e-20);
   getdNdptHAGE6->SetSavedPoint(100,6.409292e-20);
   getdNdptHAGE6->SetSavedPoint(101,1e-12);
   getdNdptHAGE6->SetSavedPoint(102,100);
   getdNdptHAGE6->SetFillColor(19);
   getdNdptHAGE6->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE6->SetLineColor(ci);
   getdNdptHAGE6->SetLineWidth(2);
   getdNdptHAGE6->SetChisquare(417.3557);
   getdNdptHAGE6->SetNDF(7);
   getdNdptHAGE6->SetParameter(0,0.13957);
   getdNdptHAGE6->SetParError(0,0);
   getdNdptHAGE6->SetParLimits(0,0.13957,0.13957);
   getdNdptHAGE6->SetParameter(1,2.840236);
   getdNdptHAGE6->SetParError(1,0.009763428);
   getdNdptHAGE6->SetParLimits(1,0,0);
   getdNdptHAGE6->SetParameter(2,200);
   getdNdptHAGE6->SetParError(2,0.1049087);
   getdNdptHAGE6->SetParLimits(2,50,200);
   getdNdptHAGE6->SetParameter(3,15);
   getdNdptHAGE6->SetParError(3,0.115444);
   getdNdptHAGE6->SetParLimits(3,5,15);
   getdNdptHAGE6->SetParameter(4,0);
   getdNdptHAGE6->SetParError(4,0);
   getdNdptHAGE6->SetParLimits(4,1,1);
   getdNdptHAGE6->SetParent(cent0_pipL_AupLAu_130__2);
   cent0_pipL_AupLAu_130__2->GetListOfFunctions()->Add(getdNdptHAGE6);

   ci = TColor::GetColor("#000099");
   cent0_pipL_AupLAu_130__2->SetLineColor(ci);
   cent0_pipL_AupLAu_130__2->SetMarkerStyle(20);
   cent0_pipL_AupLAu_130__2->GetXaxis()->SetRange(0,11);
   cent0_pipL_AupLAu_130__2->GetXaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_130__2->GetXaxis()->SetLabelSize(0.1);
   cent0_pipL_AupLAu_130__2->GetXaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_130__2->GetXaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_130__2->GetYaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_130__2->GetYaxis()->SetLabelSize(0.1);
   cent0_pipL_AupLAu_130__2->GetYaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_130__2->GetYaxis()->SetTitleOffset(0);
   cent0_pipL_AupLAu_130__2->GetYaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_130__2->GetZaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_130__2->GetZaxis()->SetLabelSize(0.035);
   cent0_pipL_AupLAu_130__2->GetZaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_130__2->GetZaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_130__2->Draw("");
      tex = new TLatex(0.1,100,"#pi^{+} 130 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part2->Modified();
   c->cd();
  
// ------------>Primitives in pad: part3
   TPad *part3 = new TPad("part3", "part3",0.6866667,0.7066667,1,1);
   part3->Draw();
   part3->cd();
   part3->Range(-0.02727273,1.235528,1.576033,3.32874);
   part3->SetFillColor(0);
   part3->SetBorderMode(0);
   part3->SetBorderSize(0);
   part3->SetLogy();
   part3->SetLeftMargin(0);
   part3->SetRightMargin(0.01);
   part3->SetTopMargin(0.03);
   part3->SetBottomMargin(0);
   part3->SetFrameBorderMode(0);
   part3->SetFrameBorderMode(0);
   Double_t xAxis3[12] = {0.23, 0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.78}; 
   
   TH1D *cent0_pipL_AupLAu_200__3 = new TH1D("cent0_pipL_AupLAu_200__3","cent0_pi+_Au+Au_200",11, xAxis3);
   cent0_pipL_AupLAu_200__3->SetBinContent(1,403);
   cent0_pipL_AupLAu_200__3->SetBinContent(2,298.1);
   cent0_pipL_AupLAu_200__3->SetBinContent(3,232.5);
   cent0_pipL_AupLAu_200__3->SetBinContent(4,183.9);
   cent0_pipL_AupLAu_200__3->SetBinContent(5,145);
   cent0_pipL_AupLAu_200__3->SetBinContent(6,113.8);
   cent0_pipL_AupLAu_200__3->SetBinContent(7,89.98);
   cent0_pipL_AupLAu_200__3->SetBinContent(8,71.1);
   cent0_pipL_AupLAu_200__3->SetBinContent(9,56.1);
   cent0_pipL_AupLAu_200__3->SetBinContent(10,44.3);
   cent0_pipL_AupLAu_200__3->SetBinContent(11,35.8);
   cent0_pipL_AupLAu_200__3->SetBinError(1,12);
   cent0_pipL_AupLAu_200__3->SetBinError(2,6);
   cent0_pipL_AupLAu_200__3->SetBinError(3,4.7);
   cent0_pipL_AupLAu_200__3->SetBinError(4,1.9);
   cent0_pipL_AupLAu_200__3->SetBinError(5,1.5);
   cent0_pipL_AupLAu_200__3->SetBinError(6,1.2);
   cent0_pipL_AupLAu_200__3->SetBinError(7,0.92);
   cent0_pipL_AupLAu_200__3->SetBinError(8,1.4);
   cent0_pipL_AupLAu_200__3->SetBinError(9,1.6);
   cent0_pipL_AupLAu_200__3->SetBinError(10,1.3);
   cent0_pipL_AupLAu_200__3->SetBinError(11,1.4);
   cent0_pipL_AupLAu_200__3->SetEntries(11);
   
   TF1 *getdNdpt7 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt7->SetRange(1e-14,100);
   getdNdpt7->SetName("getdNdpt");
   getdNdpt7->SetTitle("getdNdpt");
   getdNdpt7->SetSavedPoint(0,876.9702);
   getdNdpt7->SetSavedPoint(1,14.41715);
   getdNdpt7->SetSavedPoint(2,1.543321);
   getdNdpt7->SetSavedPoint(3,0.4116689);
   getdNdpt7->SetSavedPoint(4,0.126557);
   getdNdpt7->SetSavedPoint(5,0.03390078);
   getdNdpt7->SetSavedPoint(6,0.007136917);
   getdNdpt7->SetSavedPoint(7,0.001139375);
   getdNdpt7->SetSavedPoint(8,0.0001363627);
   getdNdpt7->SetSavedPoint(9,2.183922e-08);
   getdNdpt7->SetSavedPoint(10,1.869718e-09);
   getdNdpt7->SetSavedPoint(11,1.599396e-10);
   getdNdpt7->SetSavedPoint(12,1.367301e-11);
   getdNdpt7->SetSavedPoint(13,1.168324e-12);
   getdNdpt7->SetSavedPoint(14,9.979237e-14);
   getdNdpt7->SetSavedPoint(15,8.521177e-15);
   getdNdpt7->SetSavedPoint(16,7.274359e-16);
   getdNdpt7->SetSavedPoint(17,4.063145e-26);
   getdNdpt7->SetSavedPoint(18,9.678252e-28);
   getdNdpt7->SetSavedPoint(19,2.305105e-29);
   getdNdpt7->SetSavedPoint(20,5.489713e-31);
   getdNdpt7->SetSavedPoint(21,1.307311e-32);
   getdNdpt7->SetSavedPoint(22,3.113023e-34);
   getdNdpt7->SetSavedPoint(23,7.412477e-36);
   getdNdpt7->SetSavedPoint(24,1.764919e-37);
   getdNdpt7->SetSavedPoint(25,4.604073e-49);
   getdNdpt7->SetSavedPoint(26,4.324801e-51);
   getdNdpt7->SetSavedPoint(27,4.062366e-53);
   getdNdpt7->SetSavedPoint(28,3.815771e-55);
   getdNdpt7->SetSavedPoint(29,3.584073e-57);
   getdNdpt7->SetSavedPoint(30,7.628054e-69);
   getdNdpt7->SetSavedPoint(31,3.392782e-71);
   getdNdpt7->SetSavedPoint(32,1.509012e-73);
   getdNdpt7->SetSavedPoint(33,6.711573e-76);
   getdNdpt7->SetSavedPoint(34,2.41815e-87);
   getdNdpt7->SetSavedPoint(35,5.784552e-90);
   getdNdpt7->SetSavedPoint(36,1.384157e-92);
   getdNdpt7->SetSavedPoint(37,1.610746e-103);
   getdNdpt7->SetSavedPoint(38,2.290762e-106);
   getdNdpt7->SetSavedPoint(39,1.386104e-116);
   getdNdpt7->SetSavedPoint(40,1.471894e-119);
   getdNdpt7->SetSavedPoint(41,3.862926e-129);
   getdNdpt7->SetSavedPoint(42,8.20793e-138);
   getdNdpt7->SetSavedPoint(43,1.204134e-145);
   getdNdpt7->SetSavedPoint(44,1.981912e-157);
   getdNdpt7->SetSavedPoint(45,0);
   getdNdpt7->SetSavedPoint(46,0);
   getdNdpt7->SetSavedPoint(47,0);
   getdNdpt7->SetSavedPoint(48,0);
   getdNdpt7->SetSavedPoint(49,0);
   getdNdpt7->SetSavedPoint(50,0);
   getdNdpt7->SetSavedPoint(51,0);
   getdNdpt7->SetSavedPoint(52,0);
   getdNdpt7->SetSavedPoint(53,0);
   getdNdpt7->SetSavedPoint(54,0);
   getdNdpt7->SetSavedPoint(55,0);
   getdNdpt7->SetSavedPoint(56,0);
   getdNdpt7->SetSavedPoint(57,0);
   getdNdpt7->SetSavedPoint(58,0);
   getdNdpt7->SetSavedPoint(59,0);
   getdNdpt7->SetSavedPoint(60,0);
   getdNdpt7->SetSavedPoint(61,0);
   getdNdpt7->SetSavedPoint(62,0);
   getdNdpt7->SetSavedPoint(63,0);
   getdNdpt7->SetSavedPoint(64,0);
   getdNdpt7->SetSavedPoint(65,0);
   getdNdpt7->SetSavedPoint(66,0);
   getdNdpt7->SetSavedPoint(67,0);
   getdNdpt7->SetSavedPoint(68,0);
   getdNdpt7->SetSavedPoint(69,0);
   getdNdpt7->SetSavedPoint(70,0);
   getdNdpt7->SetSavedPoint(71,0);
   getdNdpt7->SetSavedPoint(72,0);
   getdNdpt7->SetSavedPoint(73,0);
   getdNdpt7->SetSavedPoint(74,0);
   getdNdpt7->SetSavedPoint(75,0);
   getdNdpt7->SetSavedPoint(76,0);
   getdNdpt7->SetSavedPoint(77,0);
   getdNdpt7->SetSavedPoint(78,0);
   getdNdpt7->SetSavedPoint(79,0);
   getdNdpt7->SetSavedPoint(80,0);
   getdNdpt7->SetSavedPoint(81,0);
   getdNdpt7->SetSavedPoint(82,0);
   getdNdpt7->SetSavedPoint(83,0);
   getdNdpt7->SetSavedPoint(84,0);
   getdNdpt7->SetSavedPoint(85,0);
   getdNdpt7->SetSavedPoint(86,0);
   getdNdpt7->SetSavedPoint(87,0);
   getdNdpt7->SetSavedPoint(88,0);
   getdNdpt7->SetSavedPoint(89,0);
   getdNdpt7->SetSavedPoint(90,0);
   getdNdpt7->SetSavedPoint(91,0);
   getdNdpt7->SetSavedPoint(92,0);
   getdNdpt7->SetSavedPoint(93,0);
   getdNdpt7->SetSavedPoint(94,0);
   getdNdpt7->SetSavedPoint(95,0);
   getdNdpt7->SetSavedPoint(96,0);
   getdNdpt7->SetSavedPoint(97,0);
   getdNdpt7->SetSavedPoint(98,0);
   getdNdpt7->SetSavedPoint(99,0);
   getdNdpt7->SetSavedPoint(100,0);
   getdNdpt7->SetSavedPoint(101,1e-14);
   getdNdpt7->SetSavedPoint(102,100);
   getdNdpt7->SetFillColor(19);
   getdNdpt7->SetFillStyle(0);
   getdNdpt7->SetLineWidth(2);
   getdNdpt7->SetChisquare(10.98233);
   getdNdpt7->SetNDF(7);
   getdNdpt7->SetParameter(0,0.13957);
   getdNdpt7->SetParError(0,0);
   getdNdpt7->SetParLimits(0,0.13957,0.13957);
   getdNdpt7->SetParameter(1,0.5);
   getdNdpt7->SetParError(1,0.02501226);
   getdNdpt7->SetParLimits(1,0.5,1);
   getdNdpt7->SetParameter(2,0.06901234);
   getdNdpt7->SetParError(2,0.01351602);
   getdNdpt7->SetParLimits(2,0,0);
   getdNdpt7->SetParameter(3,-1.431946);
   getdNdpt7->SetParError(3,1.499388);
   getdNdpt7->SetParLimits(3,0,0);
   getdNdpt7->SetParameter(4,380463.8);
   getdNdpt7->SetParError(4,520214.7);
   getdNdpt7->SetParLimits(4,0,0);
   getdNdpt7->SetParameter(5,0);
   getdNdpt7->SetParError(5,0);
   getdNdpt7->SetParLimits(5,1,1);
   getdNdpt7->SetParent(cent0_pipL_AupLAu_200__3);
   cent0_pipL_AupLAu_200__3->GetListOfFunctions()->Add(getdNdpt7);
   
   TF1 *getdNdpt28 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt28->SetRange(1e-14,100);
   getdNdpt28->SetName("getdNdpt2");
   getdNdpt28->SetTitle("getdNdpt2");
   getdNdpt28->SetSavedPoint(0,929.9392);
   getdNdpt28->SetSavedPoint(1,12.10987);
   getdNdpt28->SetSavedPoint(2,0.2569974);
   getdNdpt28->SetSavedPoint(3,0.007460661);
   getdNdpt28->SetSavedPoint(4,0.000246949);
   getdNdpt28->SetSavedPoint(5,8.777777e-06);
   getdNdpt28->SetSavedPoint(6,3.262278e-07);
   getdNdpt28->SetSavedPoint(7,1.249934e-08);
   getdNdpt28->SetSavedPoint(8,4.896183e-10);
   getdNdpt28->SetSavedPoint(9,1.950359e-11);
   getdNdpt28->SetSavedPoint(10,7.872025e-13);
   getdNdpt28->SetSavedPoint(11,3.211147e-14);
   getdNdpt28->SetSavedPoint(12,1.321351e-15);
   getdNdpt28->SetSavedPoint(13,5.477004e-17);
   getdNdpt28->SetSavedPoint(14,2.284318e-18);
   getdNdpt28->SetSavedPoint(15,9.578141e-20);
   getdNdpt28->SetSavedPoint(16,4.034724e-21);
   getdNdpt28->SetSavedPoint(17,1.706503e-22);
   getdNdpt28->SetSavedPoint(18,7.243637e-24);
   getdNdpt28->SetSavedPoint(19,3.084551e-25);
   getdNdpt28->SetSavedPoint(20,1.317251e-26);
   getdNdpt28->SetSavedPoint(21,5.639808e-28);
   getdNdpt28->SetSavedPoint(22,2.420324e-29);
   getdNdpt28->SetSavedPoint(23,1.04089e-30);
   getdNdpt28->SetSavedPoint(24,4.485178e-32);
   getdNdpt28->SetSavedPoint(25,1.936101e-33);
   getdNdpt28->SetSavedPoint(26,8.37122e-35);
   getdNdpt28->SetSavedPoint(27,3.624999e-36);
   getdNdpt28->SetSavedPoint(28,1.571945e-37);
   getdNdpt28->SetSavedPoint(29,6.825496e-39);
   getdNdpt28->SetSavedPoint(30,2.96729e-40);
   getdNdpt28->SetSavedPoint(31,1.291458e-41);
   getdNdpt28->SetSavedPoint(32,5.626825e-43);
   getdNdpt28->SetSavedPoint(33,2.45404e-44);
   getdNdpt28->SetSavedPoint(34,1.071295e-45);
   getdNdpt28->SetSavedPoint(35,4.680827e-47);
   getdNdpt28->SetSavedPoint(36,2.04692e-48);
   getdNdpt28->SetSavedPoint(37,8.958272e-50);
   getdNdpt28->SetSavedPoint(38,3.923512e-51);
   getdNdpt28->SetSavedPoint(39,1.719636e-52);
   getdNdpt28->SetSavedPoint(40,7.542129e-54);
   getdNdpt28->SetSavedPoint(41,3.310038e-55);
   getdNdpt28->SetSavedPoint(42,1.453586e-56);
   getdNdpt28->SetSavedPoint(43,6.387116e-58);
   getdNdpt28->SetSavedPoint(44,2.808111e-59);
   getdNdpt28->SetSavedPoint(45,1.23526e-60);
   getdNdpt28->SetSavedPoint(46,5.436603e-62);
   getdNdpt28->SetSavedPoint(47,2.393936e-63);
   getdNdpt28->SetSavedPoint(48,2.671673e-65);
   getdNdpt28->SetSavedPoint(49,2.508002e-68);
   getdNdpt28->SetSavedPoint(50,2.19761e-72);
   getdNdpt28->SetSavedPoint(51,1.087925e-73);
   getdNdpt28->SetSavedPoint(52,7.171706e-79);
   getdNdpt28->SetSavedPoint(53,1.093694e-84);
   getdNdpt28->SetSavedPoint(54,2.640582e-86);
   getdNdpt28->SetSavedPoint(55,8.935255e-88);
   getdNdpt28->SetSavedPoint(56,1.269284e-94);
   getdNdpt28->SetSavedPoint(57,2.495858e-96);
   getdNdpt28->SetSavedPoint(58,9.725182e-104);
   getdNdpt28->SetSavedPoint(59,1.513682e-105);
   getdNdpt28->SetSavedPoint(60,1.530223e-113);
   getdNdpt28->SetSavedPoint(61,1.874179e-115);
   getdNdpt28->SetSavedPoint(62,6.423059e-124);
   getdNdpt28->SetSavedPoint(63,6.164655e-126);
   getdNdpt28->SetSavedPoint(64,9.432427e-135);
   getdNdpt28->SetSavedPoint(65,7.085239e-137);
   getdNdpt28->SetSavedPoint(66,6.589235e-146);
   getdNdpt28->SetSavedPoint(67,3.892741e-148);
   getdNdpt28->SetSavedPoint(68,3.056725e-157);
   getdNdpt28->SetSavedPoint(69,2.205982e-159);
   getdNdpt28->SetSavedPoint(70,1.357314e-168);
   getdNdpt28->SetSavedPoint(71,2.562312e-177);
   getdNdpt28->SetSavedPoint(72,1.439447e-185);
   getdNdpt28->SetSavedPoint(73,3.55807e-193);
   getdNdpt28->SetSavedPoint(74,1.627902e-203);
   getdNdpt28->SetSavedPoint(75,3.261158e-213);
   getdNdpt28->SetSavedPoint(76,1.614923e-228);
   getdNdpt28->SetSavedPoint(77,5.572564e-244);
   getdNdpt28->SetSavedPoint(78,4.427586e-254);
   getdNdpt28->SetSavedPoint(79,1.557238e-280);
   getdNdpt28->SetSavedPoint(80,0);
   getdNdpt28->SetSavedPoint(81,0);
   getdNdpt28->SetSavedPoint(82,0);
   getdNdpt28->SetSavedPoint(83,0);
   getdNdpt28->SetSavedPoint(84,0);
   getdNdpt28->SetSavedPoint(85,0);
   getdNdpt28->SetSavedPoint(86,0);
   getdNdpt28->SetSavedPoint(87,0);
   getdNdpt28->SetSavedPoint(88,0);
   getdNdpt28->SetSavedPoint(89,0);
   getdNdpt28->SetSavedPoint(90,0);
   getdNdpt28->SetSavedPoint(91,0);
   getdNdpt28->SetSavedPoint(92,0);
   getdNdpt28->SetSavedPoint(93,0);
   getdNdpt28->SetSavedPoint(94,0);
   getdNdpt28->SetSavedPoint(95,0);
   getdNdpt28->SetSavedPoint(96,0);
   getdNdpt28->SetSavedPoint(97,0);
   getdNdpt28->SetSavedPoint(98,0);
   getdNdpt28->SetSavedPoint(99,0);
   getdNdpt28->SetSavedPoint(100,0);
   getdNdpt28->SetSavedPoint(101,1e-14);
   getdNdpt28->SetSavedPoint(102,100);
   getdNdpt28->SetFillColor(19);
   getdNdpt28->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt28->SetLineColor(ci);
   getdNdpt28->SetLineWidth(2);
   getdNdpt28->SetChisquare(8.8815);
   getdNdpt28->SetNDF(7);
   getdNdpt28->SetParameter(0,0.13957);
   getdNdpt28->SetParError(0,0);
   getdNdpt28->SetParLimits(0,0.13957,0.13957);
   getdNdpt28->SetParameter(1,0.8);
   getdNdpt28->SetParError(1,0.03109645);
   getdNdpt28->SetParLimits(1,0.3,0.8);
   getdNdpt28->SetParameter(2,0.1074794);
   getdNdpt28->SetParError(2,0.01254312);
   getdNdpt28->SetParLimits(2,0.08,0.2);
   getdNdpt28->SetParameter(3,1.197047);
   getdNdpt28->SetParError(3,0.4280848);
   getdNdpt28->SetParLimits(3,0.01,5);
   getdNdpt28->SetParameter(4,51500.21);
   getdNdpt28->SetParError(4,19214.78);
   getdNdpt28->SetParLimits(4,0,0);
   getdNdpt28->SetParameter(5,0);
   getdNdpt28->SetParError(5,0);
   getdNdpt28->SetParLimits(5,1,1);
   getdNdpt28->SetParent(cent0_pipL_AupLAu_200__3);
   cent0_pipL_AupLAu_200__3->GetListOfFunctions()->Add(getdNdpt28);
   
   TF1 *getdNdptHAGE9 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE9->SetRange(1e-12,100);
   getdNdptHAGE9->SetName("getdNdptHAGE");
   getdNdptHAGE9->SetTitle("getdNdptHAGE");
   getdNdptHAGE9->SetSavedPoint(0,1017.563);
   getdNdptHAGE9->SetSavedPoint(1,19.53209);
   getdNdptHAGE9->SetSavedPoint(2,1.359241);
   getdNdptHAGE9->SetSavedPoint(3,0.1571202);
   getdNdptHAGE9->SetSavedPoint(4,0.02450185);
   getdNdptHAGE9->SetSavedPoint(5,0.004727466);
   getdNdptHAGE9->SetSavedPoint(6,0.001074475);
   getdNdptHAGE9->SetSavedPoint(7,0.0002785742);
   getdNdptHAGE9->SetSavedPoint(8,8.053143e-05);
   getdNdptHAGE9->SetSavedPoint(9,2.552073e-05);
   getdNdptHAGE9->SetSavedPoint(10,8.75043e-06);
   getdNdptHAGE9->SetSavedPoint(11,3.212645e-06);
   getdNdptHAGE9->SetSavedPoint(12,1.252407e-06);
   getdNdptHAGE9->SetSavedPoint(13,5.148487e-07);
   getdNdptHAGE9->SetSavedPoint(14,2.219051e-07);
   getdNdptHAGE9->SetSavedPoint(15,9.979354e-08);
   getdNdptHAGE9->SetSavedPoint(16,4.663283e-08);
   getdNdptHAGE9->SetSavedPoint(17,2.256289e-08);
   getdNdptHAGE9->SetSavedPoint(18,1.126879e-08);
   getdNdptHAGE9->SetSavedPoint(19,5.793974e-09);
   getdNdptHAGE9->SetSavedPoint(20,3.059649e-09);
   getdNdptHAGE9->SetSavedPoint(21,1.656007e-09);
   getdNdptHAGE9->SetSavedPoint(22,9.169574e-10);
   getdNdptHAGE9->SetSavedPoint(23,5.185857e-10);
   getdNdptHAGE9->SetSavedPoint(24,2.991155e-10);
   getdNdptHAGE9->SetSavedPoint(25,1.757241e-10);
   getdNdptHAGE9->SetSavedPoint(26,1.050221e-10);
   getdNdptHAGE9->SetSavedPoint(27,6.378504e-11);
   getdNdptHAGE9->SetSavedPoint(28,3.932972e-11);
   getdNdptHAGE9->SetSavedPoint(29,2.459797e-11);
   getdNdptHAGE9->SetSavedPoint(30,1.559194e-11);
   getdNdptHAGE9->SetSavedPoint(31,1.00092e-11);
   getdNdptHAGE9->SetSavedPoint(32,6.502772e-12);
   getdNdptHAGE9->SetSavedPoint(33,4.272912e-12);
   getdNdptHAGE9->SetSavedPoint(34,2.838066e-12);
   getdNdptHAGE9->SetSavedPoint(35,1.904408e-12);
   getdNdptHAGE9->SetSavedPoint(36,1.290386e-12);
   getdNdptHAGE9->SetSavedPoint(37,8.824715e-13);
   getdNdptHAGE9->SetSavedPoint(38,6.088571e-13);
   getdNdptHAGE9->SetSavedPoint(39,4.236327e-13);
   getdNdptHAGE9->SetSavedPoint(40,2.971395e-13);
   getdNdptHAGE9->SetSavedPoint(41,2.100274e-13);
   getdNdptHAGE9->SetSavedPoint(42,1.495525e-13);
   getdNdptHAGE9->SetSavedPoint(43,1.072458e-13);
   getdNdptHAGE9->SetSavedPoint(44,7.743021e-14);
   getdNdptHAGE9->SetSavedPoint(45,5.626864e-14);
   getdNdptHAGE9->SetSavedPoint(46,4.114693e-14);
   getdNdptHAGE9->SetSavedPoint(47,3.027046e-14);
   getdNdptHAGE9->SetSavedPoint(48,2.239817e-14);
   getdNdptHAGE9->SetSavedPoint(49,1.666577e-14);
   getdNdptHAGE9->SetSavedPoint(50,1.246721e-14);
   getdNdptHAGE9->SetSavedPoint(51,9.374782e-15);
   getdNdptHAGE9->SetSavedPoint(52,7.08471e-15);
   getdNdptHAGE9->SetSavedPoint(53,5.379939e-15);
   getdNdptHAGE9->SetSavedPoint(54,4.10446e-15);
   getdNdptHAGE9->SetSavedPoint(55,3.145507e-15);
   getdNdptHAGE9->SetSavedPoint(56,2.421125e-15);
   getdNdptHAGE9->SetSavedPoint(57,1.871434e-15);
   getdNdptHAGE9->SetSavedPoint(58,1.452462e-15);
   getdNdptHAGE9->SetSavedPoint(59,1.131755e-15);
   getdNdptHAGE9->SetSavedPoint(60,8.852472e-16);
   getdNdptHAGE9->SetSavedPoint(61,6.9501e-16);
   getdNdptHAGE9->SetSavedPoint(62,5.476254e-16);
   getdNdptHAGE9->SetSavedPoint(63,4.330083e-16);
   getdNdptHAGE9->SetSavedPoint(64,3.43546e-16);
   getdNdptHAGE9->SetSavedPoint(65,2.734685e-16);
   getdNdptHAGE9->SetSavedPoint(66,2.183853e-16);
   getdNdptHAGE9->SetSavedPoint(67,1.749421e-16);
   getdNdptHAGE9->SetSavedPoint(68,1.405669e-16);
   getdNdptHAGE9->SetSavedPoint(69,1.132802e-16);
   getdNdptHAGE9->SetSavedPoint(70,9.155303e-17);
   getdNdptHAGE9->SetSavedPoint(71,7.42005e-17);
   getdNdptHAGE9->SetSavedPoint(72,6.030101e-17);
   getdNdptHAGE9->SetSavedPoint(73,4.913553e-17);
   getdNdptHAGE9->SetSavedPoint(74,4.014125e-17);
   getdNdptHAGE9->SetSavedPoint(75,3.287625e-17);
   getdNdptHAGE9->SetSavedPoint(76,2.699248e-17);
   getdNdptHAGE9->SetSavedPoint(77,2.221499e-17);
   getdNdptHAGE9->SetSavedPoint(78,1.832599e-17);
   getdNdptHAGE9->SetSavedPoint(79,1.515244e-17);
   getdNdptHAGE9->SetSavedPoint(80,1.255648e-17);
   getdNdptHAGE9->SetSavedPoint(81,1.0428e-17);
   getdNdptHAGE9->SetSavedPoint(82,8.678807e-18);
   getdNdptHAGE9->SetSavedPoint(83,7.238092e-18);
   getdNdptHAGE9->SetSavedPoint(84,6.048851e-18);
   getdNdptHAGE9->SetSavedPoint(85,5.065084e-18);
   getdNdptHAGE9->SetSavedPoint(86,4.249585e-18);
   getdNdptHAGE9->SetSavedPoint(87,3.572185e-18);
   getdNdptHAGE9->SetSavedPoint(88,3.008371e-18);
   getdNdptHAGE9->SetSavedPoint(89,2.538174e-18);
   getdNdptHAGE9->SetSavedPoint(90,2.145297e-18);
   getdNdptHAGE9->SetSavedPoint(91,1.816407e-18);
   getdNdptHAGE9->SetSavedPoint(92,1.540576e-18);
   getdNdptHAGE9->SetSavedPoint(93,1.308827e-18);
   getdNdptHAGE9->SetSavedPoint(94,1.11377e-18);
   getdNdptHAGE9->SetSavedPoint(95,9.49312e-19);
   getdNdptHAGE9->SetSavedPoint(96,8.10417e-19);
   getdNdptHAGE9->SetSavedPoint(97,6.929164e-19);
   getdNdptHAGE9->SetSavedPoint(98,5.933525e-19);
   getdNdptHAGE9->SetSavedPoint(99,5.088523e-19);
   getdNdptHAGE9->SetSavedPoint(100,4.370241e-19);
   getdNdptHAGE9->SetSavedPoint(101,1e-12);
   getdNdptHAGE9->SetSavedPoint(102,100);
   getdNdptHAGE9->SetFillColor(19);
   getdNdptHAGE9->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE9->SetLineColor(ci);
   getdNdptHAGE9->SetLineWidth(2);
   getdNdptHAGE9->SetChisquare(254.8365);
   getdNdptHAGE9->SetNDF(8);
   getdNdptHAGE9->SetParameter(0,0.13957);
   getdNdptHAGE9->SetParError(0,0);
   getdNdptHAGE9->SetParLimits(0,0.13957,0.13957);
   getdNdptHAGE9->SetParameter(1,2.48103);
   getdNdptHAGE9->SetParError(1,0.009598343);
   getdNdptHAGE9->SetParLimits(1,0,0);
   getdNdptHAGE9->SetParameter(2,200);
   getdNdptHAGE9->SetParError(2,0.1693489);
   getdNdptHAGE9->SetParLimits(2,50,200);
   getdNdptHAGE9->SetParameter(3,15);
   getdNdptHAGE9->SetParError(3,0.2429446);
   getdNdptHAGE9->SetParLimits(3,5,15);
   getdNdptHAGE9->SetParameter(4,0);
   getdNdptHAGE9->SetParError(4,0);
   getdNdptHAGE9->SetParLimits(4,1,1);
   getdNdptHAGE9->SetParent(cent0_pipL_AupLAu_200__3);
   cent0_pipL_AupLAu_200__3->GetListOfFunctions()->Add(getdNdptHAGE9);

   ci = TColor::GetColor("#000099");
   cent0_pipL_AupLAu_200__3->SetLineColor(ci);
   cent0_pipL_AupLAu_200__3->SetMarkerStyle(20);
   cent0_pipL_AupLAu_200__3->GetXaxis()->SetRange(0,12);
   cent0_pipL_AupLAu_200__3->GetXaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_200__3->GetXaxis()->SetLabelSize(0.1);
   cent0_pipL_AupLAu_200__3->GetXaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_200__3->GetXaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_200__3->GetYaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_200__3->GetYaxis()->SetLabelSize(0.1);
   cent0_pipL_AupLAu_200__3->GetYaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_200__3->GetYaxis()->SetTitleOffset(0);
   cent0_pipL_AupLAu_200__3->GetYaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_200__3->GetZaxis()->SetLabelFont(42);
   cent0_pipL_AupLAu_200__3->GetZaxis()->SetLabelSize(0.035);
   cent0_pipL_AupLAu_200__3->GetZaxis()->SetTitleSize(0.035);
   cent0_pipL_AupLAu_200__3->GetZaxis()->SetTitleFont(42);
   cent0_pipL_AupLAu_200__3->Draw("");
   
   TLegend *leg = new TLegend(0.4,0.5,1,1,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Fit Function","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextAlign(22);
   entry->SetTextFont(62);
   entry=leg->AddEntry("getdNdpt","Unconst. BGBW","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("getdNdpt2","Const. BGBW","l");

   ci = TColor::GetColor("#0000ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("getdNdptHAGE","Hage.","l");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
      tex = new TLatex(0.1,100,"#pi^{+} 200 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part3->Modified();
   c->cd();
  
// ------------>Primitives in pad: part4
   TPad *part4 = new TPad("part4", "part4",0,0.4133334,0.3733333,0.7066667);
   part4->Draw();
   part4->cd();
   part4->Range(-0.3502128,0.5457295,1.58,1.786371);
   part4->SetFillColor(0);
   part4->SetBorderMode(0);
   part4->SetBorderSize(0);
   part4->SetLogy();
   part4->SetLeftMargin(0.1607143);
   part4->SetRightMargin(0);
   part4->SetTopMargin(0);
   part4->SetBottomMargin(0);
   part4->SetFrameBorderMode(0);
   part4->SetFrameBorderMode(0);
   Double_t xAxis4[11] = {0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.8}; 
   
   TH1D *cent0_kapL_AupLAu_62dO4__4 = new TH1D("cent0_kapL_AupLAu_62dO4__4","cent0_ka+_Au+Au_62.4",10, xAxis4);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(1,22.5418);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(2,20.3193);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(3,18.755);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(4,16.8424);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(5,14.3725);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(6,12.771);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(7,11.371);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(8,10.0626);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(9,8.7058);
   cent0_kapL_AupLAu_62dO4__4->SetBinContent(10,7.4113);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(1,0.46231);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(2,0.61472);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(3,0.94015);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(4,2.02208);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(5,1.7257);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(6,1.53347);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(7,0.91097);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(8,1.00765);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(9,1.04696);
   cent0_kapL_AupLAu_62dO4__4->SetBinError(10,0.38447);
   cent0_kapL_AupLAu_62dO4__4->SetEntries(10);
   
   TF1 *getdNdpt10 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt10->SetRange(1e-14,100);
   getdNdpt10->SetName("getdNdpt");
   getdNdpt10->SetTitle("getdNdpt");
   getdNdpt10->SetSavedPoint(0,30.8762);
   getdNdpt10->SetSavedPoint(1,3.959602);
   getdNdpt10->SetSavedPoint(2,0.5227996);
   getdNdpt10->SetSavedPoint(3,0.1295908);
   getdNdpt10->SetSavedPoint(4,0.04015167);
   getdNdpt10->SetSavedPoint(5,0.01379116);
   getdNdpt10->SetSavedPoint(6,0.005025515);
   getdNdpt10->SetSavedPoint(7,0.001902471);
   getdNdpt10->SetSavedPoint(8,0.0007395673);
   getdNdpt10->SetSavedPoint(9,0.0002931605);
   getdNdpt10->SetSavedPoint(10,0.0001179548);
   getdNdpt10->SetSavedPoint(11,4.802282e-05);
   getdNdpt10->SetSavedPoint(12,1.973916e-05);
   getdNdpt10->SetSavedPoint(13,8.177864e-06);
   getdNdpt10->SetSavedPoint(14,3.41063e-06);
   getdNdpt10->SetSavedPoint(15,1.4305e-06);
   getdNdpt10->SetSavedPoint(16,6.029241e-07);
   getdNdpt10->SetSavedPoint(17,2.552036e-07);
   getdNdpt10->SetSavedPoint(18,1.084271e-07);
   getdNdpt10->SetSavedPoint(19,4.622013e-08);
   getdNdpt10->SetSavedPoint(20,1.976115e-08);
   getdNdpt10->SetSavedPoint(21,8.471297e-09);
   getdNdpt10->SetSavedPoint(22,3.64026e-09);
   getdNdpt10->SetSavedPoint(23,1.567702e-09);
   getdNdpt10->SetSavedPoint(24,6.821214e-10);
   getdNdpt10->SetSavedPoint(25,2.951592e-10);
   getdNdpt10->SetSavedPoint(26,1.279229e-10);
   getdNdpt10->SetSavedPoint(27,5.55222e-11);
   getdNdpt10->SetSavedPoint(28,2.412947e-11);
   getdNdpt10->SetSavedPoint(29,1.049865e-11);
   getdNdpt10->SetSavedPoint(30,4.572687e-12);
   getdNdpt10->SetSavedPoint(31,1.993487e-12);
   getdNdpt10->SetSavedPoint(32,8.697941e-13);
   getdNdpt10->SetSavedPoint(33,3.79788e-13);
   getdNdpt10->SetSavedPoint(34,1.659406e-13);
   getdNdpt10->SetSavedPoint(35,7.254686e-14);
   getdNdpt10->SetSavedPoint(36,3.173297e-14);
   getdNdpt10->SetSavedPoint(37,1.388683e-14);
   getdNdpt10->SetSavedPoint(38,6.079572e-15);
   getdNdpt10->SetSavedPoint(39,2.66256e-15);
   getdNdpt10->SetSavedPoint(40,1.166445e-15);
   getdNdpt10->SetSavedPoint(41,5.111525e-16);
   getdNdpt10->SetSavedPoint(42,2.240495e-16);
   getdNdpt10->SetSavedPoint(43,9.822729e-17);
   getdNdpt10->SetSavedPoint(44,6.195042e-19);
   getdNdpt10->SetSavedPoint(45,2.407282e-19);
   getdNdpt10->SetSavedPoint(46,9.353971e-20);
   getdNdpt10->SetSavedPoint(47,3.634559e-20);
   getdNdpt10->SetSavedPoint(48,1.412195e-20);
   getdNdpt10->SetSavedPoint(49,5.486843e-21);
   getdNdpt10->SetSavedPoint(50,1.256805e-25);
   getdNdpt10->SetSavedPoint(51,3.961179e-26);
   getdNdpt10->SetSavedPoint(52,1.248451e-26);
   getdNdpt10->SetSavedPoint(53,3.934681e-27);
   getdNdpt10->SetSavedPoint(54,1.24005e-27);
   getdNdpt10->SetSavedPoint(55,3.908054e-28);
   getdNdpt10->SetSavedPoint(56,1.231613e-28);
   getdNdpt10->SetSavedPoint(57,3.881334e-29);
   getdNdpt10->SetSavedPoint(58,1.223153e-29);
   getdNdpt10->SetSavedPoint(59,3.854561e-30);
   getdNdpt10->SetSavedPoint(60,3.90956e-37);
   getdNdpt10->SetSavedPoint(61,9.521704e-38);
   getdNdpt10->SetSavedPoint(62,2.318979e-38);
   getdNdpt10->SetSavedPoint(63,5.647739e-39);
   getdNdpt10->SetSavedPoint(64,1.375461e-39);
   getdNdpt10->SetSavedPoint(65,3.349791e-40);
   getdNdpt10->SetSavedPoint(66,8.157996e-41);
   getdNdpt10->SetSavedPoint(67,1.986761e-41);
   getdNdpt10->SetSavedPoint(68,4.838427e-42);
   getdNdpt10->SetSavedPoint(69,1.17831e-42);
   getdNdpt10->SetSavedPoint(70,2.869535e-43);
   getdNdpt10->SetSavedPoint(71,6.998714e-44);
   getdNdpt10->SetSavedPoint(72,4.416705e-53);
   getdNdpt10->SetSavedPoint(73,8.12992e-54);
   getdNdpt10->SetSavedPoint(74,1.496483e-54);
   getdNdpt10->SetSavedPoint(75,2.754579e-55);
   getdNdpt10->SetSavedPoint(76,5.070334e-56);
   getdNdpt10->SetSavedPoint(77,9.332884e-57);
   getdNdpt10->SetSavedPoint(78,1.717882e-57);
   getdNdpt10->SetSavedPoint(79,3.16205e-58);
   getdNdpt10->SetSavedPoint(80,5.82026e-59);
   getdNdpt10->SetSavedPoint(81,1.071308e-59);
   getdNdpt10->SetSavedPoint(82,1.971892e-60);
   getdNdpt10->SetSavedPoint(83,3.858275e-61);
   getdNdpt10->SetSavedPoint(84,2.468069e-72);
   getdNdpt10->SetSavedPoint(85,3.400767e-73);
   getdNdpt10->SetSavedPoint(86,4.685923e-74);
   getdNdpt10->SetSavedPoint(87,6.456725e-75);
   getdNdpt10->SetSavedPoint(88,8.896686e-76);
   getdNdpt10->SetSavedPoint(89,1.225866e-76);
   getdNdpt10->SetSavedPoint(90,1.689106e-77);
   getdNdpt10->SetSavedPoint(91,2.327392e-78);
   getdNdpt10->SetSavedPoint(92,3.206869e-79);
   getdNdpt10->SetSavedPoint(93,4.418776e-80);
   getdNdpt10->SetSavedPoint(94,6.26151e-81);
   getdNdpt10->SetSavedPoint(95,9.126305e-94);
   getdNdpt10->SetSavedPoint(96,9.386215e-95);
   getdNdpt10->SetSavedPoint(97,9.65351e-96);
   getdNdpt10->SetSavedPoint(98,9.9284e-97);
   getdNdpt10->SetSavedPoint(99,1.02111e-97);
   getdNdpt10->SetSavedPoint(100,1.050183e-98);
   getdNdpt10->SetSavedPoint(101,1e-14);
   getdNdpt10->SetSavedPoint(102,100);
   getdNdpt10->SetFillColor(19);
   getdNdpt10->SetFillStyle(0);
   getdNdpt10->SetLineWidth(2);
   getdNdpt10->SetChisquare(0.1471773);
   getdNdpt10->SetNDF(6);
   getdNdpt10->SetParameter(0,0.49368);
   getdNdpt10->SetParError(0,0);
   getdNdpt10->SetParLimits(0,0.49368,0.49368);
   getdNdpt10->SetParameter(1,0.9544776);
   getdNdpt10->SetParError(1,0.3287331);
   getdNdpt10->SetParLimits(1,0.5,1);
   getdNdpt10->SetParameter(2,0.191496);
   getdNdpt10->SetParError(2,0.008400953);
   getdNdpt10->SetParLimits(2,0,0);
   getdNdpt10->SetParameter(3,2.915645);
   getdNdpt10->SetParError(3,0.8105413);
   getdNdpt10->SetParLimits(3,0,0);
   getdNdpt10->SetParameter(4,2756.863);
   getdNdpt10->SetParError(4,523.8842);
   getdNdpt10->SetParLimits(4,0,0);
   getdNdpt10->SetParameter(5,0);
   getdNdpt10->SetParError(5,0);
   getdNdpt10->SetParLimits(5,1,1);
   getdNdpt10->SetParent(cent0_kapL_AupLAu_62dO4__4);
   cent0_kapL_AupLAu_62dO4__4->GetListOfFunctions()->Add(getdNdpt10);
   
   TF1 *getdNdpt211 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt211->SetRange(1e-14,100);
   getdNdpt211->SetName("getdNdpt2");
   getdNdpt211->SetTitle("getdNdpt2");
   getdNdpt211->SetSavedPoint(0,30.91137);
   getdNdpt211->SetSavedPoint(1,3.855652);
   getdNdpt211->SetSavedPoint(2,0.291901);
   getdNdpt211->SetSavedPoint(3,0.02679198);
   getdNdpt211->SetSavedPoint(4,0.002701555);
   getdNdpt211->SetSavedPoint(5,0.0002874845);
   getdNdpt211->SetSavedPoint(6,3.168667e-05);
   getdNdpt211->SetSavedPoint(7,3.580188e-06);
   getdNdpt211->SetSavedPoint(8,4.120458e-07);
   getdNdpt211->SetSavedPoint(9,4.810392e-08);
   getdNdpt211->SetSavedPoint(10,5.680038e-09);
   getdNdpt211->SetSavedPoint(11,6.769365e-10);
   getdNdpt211->SetSavedPoint(12,8.130011e-11);
   getdNdpt211->SetSavedPoint(13,9.827898e-12);
   getdNdpt211->SetSavedPoint(14,1.194672e-12);
   getdNdpt211->SetSavedPoint(15,1.459252e-13);
   getdNdpt211->SetSavedPoint(16,1.789953e-14);
   getdNdpt211->SetSavedPoint(17,2.203768e-15);
   getdNdpt211->SetSavedPoint(18,2.722217e-16);
   getdNdpt211->SetSavedPoint(19,3.372566e-17);
   getdNdpt211->SetSavedPoint(20,4.189386e-18);
   getdNdpt211->SetSavedPoint(21,5.216535e-19);
   getdNdpt211->SetSavedPoint(22,6.509694e-20);
   getdNdpt211->SetSavedPoint(23,8.139601e-21);
   getdNdpt211->SetSavedPoint(24,1.019618e-21);
   getdNdpt211->SetSavedPoint(25,1.279381e-22);
   getdNdpt211->SetSavedPoint(26,1.60781e-23);
   getdNdpt211->SetSavedPoint(27,2.023445e-24);
   getdNdpt211->SetSavedPoint(28,2.549917e-25);
   getdNdpt211->SetSavedPoint(29,3.21735e-26);
   getdNdpt211->SetSavedPoint(30,4.064177e-27);
   getdNdpt211->SetSavedPoint(31,5.139449e-28);
   getdNdpt211->SetSavedPoint(32,6.505802e-29);
   getdNdpt211->SetSavedPoint(33,8.243261e-30);
   getdNdpt211->SetSavedPoint(34,1.04541e-30);
   getdNdpt211->SetSavedPoint(35,1.326912e-31);
   getdNdpt211->SetSavedPoint(36,1.685563e-32);
   getdNdpt211->SetSavedPoint(37,2.142775e-33);
   getdNdpt211->SetSavedPoint(38,2.725962e-34);
   getdNdpt211->SetSavedPoint(39,3.470239e-35);
   getdNdpt211->SetSavedPoint(40,4.420593e-36);
   getdNdpt211->SetSavedPoint(41,5.63469e-37);
   getdNdpt211->SetSavedPoint(42,7.186465e-38);
   getdNdpt211->SetSavedPoint(43,9.170752e-39);
   getdNdpt211->SetSavedPoint(44,1.170923e-39);
   getdNdpt211->SetSavedPoint(45,1.495806e-40);
   getdNdpt211->SetSavedPoint(46,1.911773e-41);
   getdNdpt211->SetSavedPoint(47,2.444574e-42);
   getdNdpt211->SetSavedPoint(48,3.127285e-43);
   getdNdpt211->SetSavedPoint(49,4.002409e-44);
   getdNdpt211->SetSavedPoint(50,5.124576e-45);
   getdNdpt211->SetSavedPoint(51,6.564025e-46);
   getdNdpt211->SetSavedPoint(52,8.411082e-47);
   getdNdpt211->SetSavedPoint(53,1.078194e-47);
   getdNdpt211->SetSavedPoint(54,1.382608e-48);
   getdNdpt211->SetSavedPoint(55,1.773591e-49);
   getdNdpt211->SetSavedPoint(56,2.275909e-50);
   getdNdpt211->SetSavedPoint(57,2.921448e-51);
   getdNdpt211->SetSavedPoint(58,3.751273e-52);
   getdNdpt211->SetSavedPoint(59,4.818279e-53);
   getdNdpt211->SetSavedPoint(60,6.190613e-54);
   getdNdpt211->SetSavedPoint(61,7.95609e-55);
   getdNdpt211->SetSavedPoint(62,1.022789e-55);
   getdNdpt211->SetSavedPoint(63,1.315192e-56);
   getdNdpt211->SetSavedPoint(64,1.691628e-57);
   getdNdpt211->SetSavedPoint(65,2.176358e-58);
   getdNdpt211->SetSavedPoint(66,2.800668e-59);
   getdNdpt211->SetSavedPoint(67,3.60492e-60);
   getdNdpt211->SetSavedPoint(68,4.641189e-61);
   getdNdpt211->SetSavedPoint(69,5.976671e-62);
   getdNdpt211->SetSavedPoint(70,7.698091e-63);
   getdNdpt211->SetSavedPoint(71,9.91739e-64);
   getdNdpt211->SetSavedPoint(72,1.277927e-64);
   getdNdpt211->SetSavedPoint(73,1.006202e-65);
   getdNdpt211->SetSavedPoint(74,3.083484e-67);
   getdNdpt211->SetSavedPoint(75,2.408092e-70);
   getdNdpt211->SetSavedPoint(76,2.782631e-71);
   getdNdpt211->SetSavedPoint(77,1.117448e-75);
   getdNdpt211->SetSavedPoint(78,1.161489e-76);
   getdNdpt211->SetSavedPoint(79,1.2498e-77);
   getdNdpt211->SetSavedPoint(80,3.419948e-83);
   getdNdpt211->SetSavedPoint(81,3.107109e-84);
   getdNdpt211->SetSavedPoint(82,2.826156e-85);
   getdNdpt211->SetSavedPoint(83,7.869171e-92);
   getdNdpt211->SetSavedPoint(84,6.12048e-93);
   getdNdpt211->SetSavedPoint(85,4.760348e-94);
   getdNdpt211->SetSavedPoint(86,3.706055e-95);
   getdNdpt211->SetSavedPoint(87,1.137457e-102);
   getdNdpt211->SetSavedPoint(88,7.453939e-104);
   getdNdpt211->SetSavedPoint(89,4.884688e-105);
   getdNdpt211->SetSavedPoint(90,3.208036e-106);
   getdNdpt211->SetSavedPoint(91,1.474697e-114);
   getdNdpt211->SetSavedPoint(92,8.053098e-116);
   getdNdpt211->SetSavedPoint(93,4.397651e-117);
   getdNdpt211->SetSavedPoint(94,2.779057e-118);
   getdNdpt211->SetSavedPoint(95,2.389443e-127);
   getdNdpt211->SetSavedPoint(96,1.080641e-128);
   getdNdpt211->SetSavedPoint(97,4.88659e-130);
   getdNdpt211->SetSavedPoint(98,1.830575e-139);
   getdNdpt211->SetSavedPoint(99,6.842902e-141);
   getdNdpt211->SetSavedPoint(100,2.557926e-142);
   getdNdpt211->SetSavedPoint(101,1e-14);
   getdNdpt211->SetSavedPoint(102,100);
   getdNdpt211->SetFillColor(19);
   getdNdpt211->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt211->SetLineColor(ci);
   getdNdpt211->SetLineWidth(2);
   getdNdpt211->SetChisquare(0.1506325);
   getdNdpt211->SetNDF(6);
   getdNdpt211->SetParameter(0,0.49368);
   getdNdpt211->SetParError(0,0);
   getdNdpt211->SetParLimits(0,0.49368,0.49368);
   getdNdpt211->SetParameter(1,0.7999967);
   getdNdpt211->SetParError(1,0.4970875);
   getdNdpt211->SetParLimits(1,0.3,0.8);
   getdNdpt211->SetParameter(2,0.1637587);
   getdNdpt211->SetParError(2,0.001924221);
   getdNdpt211->SetParLimits(2,0.08,0.2);
   getdNdpt211->SetParameter(3,1.560256);
   getdNdpt211->SetParError(3,0.7780092);
   getdNdpt211->SetParLimits(3,0.01,5);
   getdNdpt211->SetParameter(4,5272.49);
   getdNdpt211->SetParError(4,303.7946);
   getdNdpt211->SetParLimits(4,0,0);
   getdNdpt211->SetParameter(5,0);
   getdNdpt211->SetParError(5,0);
   getdNdpt211->SetParLimits(5,1,1);
   getdNdpt211->SetParent(cent0_kapL_AupLAu_62dO4__4);
   cent0_kapL_AupLAu_62dO4__4->GetListOfFunctions()->Add(getdNdpt211);
   
   TF1 *getdNdptHAGE12 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE12->SetRange(1e-12,100);
   getdNdptHAGE12->SetName("getdNdptHAGE");
   getdNdptHAGE12->SetTitle("getdNdptHAGE");
   getdNdptHAGE12->SetSavedPoint(0,32.39675);
   getdNdptHAGE12->SetSavedPoint(1,3.823839);
   getdNdptHAGE12->SetSavedPoint(2,0.338877);
   getdNdptHAGE12->SetSavedPoint(3,0.0431322);
   getdNdptHAGE12->SetSavedPoint(4,0.007127705);
   getdNdptHAGE12->SetSavedPoint(5,0.001432694);
   getdNdptHAGE12->SetSavedPoint(6,0.0003359646);
   getdNdptHAGE12->SetSavedPoint(7,8.930803e-05);
   getdNdptHAGE12->SetSavedPoint(8,2.635486e-05);
   getdNdptHAGE12->SetSavedPoint(9,8.49815e-06);
   getdNdptHAGE12->SetSavedPoint(10,2.957435e-06);
   getdNdptHAGE12->SetSavedPoint(11,1.099891e-06);
   getdNdptHAGE12->SetSavedPoint(12,4.336568e-07);
   getdNdptHAGE12->SetSavedPoint(13,1.800651e-07);
   getdNdptHAGE12->SetSavedPoint(14,7.830634e-08);
   getdNdptHAGE12->SetSavedPoint(15,3.5499e-08);
   getdNdptHAGE12->SetSavedPoint(16,1.670909e-08);
   getdNdptHAGE12->SetSavedPoint(17,8.137927e-09);
   getdNdptHAGE12->SetSavedPoint(18,4.088875e-09);
   getdNdptHAGE12->SetSavedPoint(19,2.113937e-09);
   getdNdptHAGE12->SetSavedPoint(20,1.121978e-09);
   getdNdptHAGE12->SetSavedPoint(21,6.101022e-10);
   getdNdptHAGE12->SetSavedPoint(22,3.392869e-10);
   getdNdptHAGE12->SetSavedPoint(23,1.926558e-10);
   getdNdptHAGE12->SetSavedPoint(24,1.115383e-10);
   getdNdptHAGE12->SetSavedPoint(25,6.575545e-11);
   getdNdptHAGE12->SetSavedPoint(26,3.942749e-11);
   getdNdptHAGE12->SetSavedPoint(27,2.401968e-11);
   getdNdptHAGE12->SetSavedPoint(28,1.485315e-11);
   getdNdptHAGE12->SetSavedPoint(29,9.314798e-12);
   getdNdptHAGE12->SetSavedPoint(30,5.919483e-12);
   getdNdptHAGE12->SetSavedPoint(31,3.809175e-12);
   getdNdptHAGE12->SetSavedPoint(32,2.480402e-12);
   getdNdptHAGE12->SetSavedPoint(33,1.633381e-12);
   getdNdptHAGE12->SetSavedPoint(34,1.087121e-12);
   getdNdptHAGE12->SetSavedPoint(35,7.309088e-13);
   getdNdptHAGE12->SetSavedPoint(36,4.96169e-13);
   getdNdptHAGE12->SetSavedPoint(37,3.399218e-13);
   getdNdptHAGE12->SetSavedPoint(38,2.349236e-13);
   getdNdptHAGE12->SetSavedPoint(39,1.637196e-13);
   getdNdptHAGE12->SetSavedPoint(40,1.150113e-13);
   getdNdptHAGE12->SetSavedPoint(41,8.141342e-14);
   getdNdptHAGE12->SetSavedPoint(42,5.805328e-14);
   getdNdptHAGE12->SetSavedPoint(43,4.168704e-14);
   getdNdptHAGE12->SetSavedPoint(44,3.013665e-14);
   getdNdptHAGE12->SetSavedPoint(45,2.192767e-14);
   getdNdptHAGE12->SetSavedPoint(46,1.605402e-14);
   getdNdptHAGE12->SetSavedPoint(47,1.182404e-14);
   getdNdptHAGE12->SetSavedPoint(48,8.75873e-15);
   getdNdptHAGE12->SetSavedPoint(49,6.524059e-15);
   getdNdptHAGE12->SetSavedPoint(50,4.8855e-15);
   getdNdptHAGE12->SetSavedPoint(51,3.677327e-15);
   getdNdptHAGE12->SetSavedPoint(52,2.781695e-15);
   getdNdptHAGE12->SetSavedPoint(53,2.114301e-15);
   getdNdptHAGE12->SetSavedPoint(54,1.614485e-15);
   getdNdptHAGE12->SetSavedPoint(55,1.238353e-15);
   getdNdptHAGE12->SetSavedPoint(56,9.539691e-16);
   getdNdptHAGE12->SetSavedPoint(57,7.379781e-16);
   getdNdptHAGE12->SetSavedPoint(58,5.732108e-16);
   getdNdptHAGE12->SetSavedPoint(59,4.469842e-16);
   getdNdptHAGE12->SetSavedPoint(60,3.498843e-16);
   getdNdptHAGE12->SetSavedPoint(61,2.748915e-16);
   getdNdptHAGE12->SetSavedPoint(62,2.16748e-16);
   getdNdptHAGE12->SetSavedPoint(63,1.714984e-16);
   getdNdptHAGE12->SetSavedPoint(64,1.361547e-16);
   getdNdptHAGE12->SetSavedPoint(65,1.084504e-16);
   getdNdptHAGE12->SetSavedPoint(66,8.665936e-17);
   getdNdptHAGE12->SetSavedPoint(67,6.946198e-17);
   getdNdptHAGE12->SetSavedPoint(68,5.584568e-17);
   getdNdptHAGE12->SetSavedPoint(69,4.503055e-17);
   getdNdptHAGE12->SetSavedPoint(70,3.641384e-17);
   getdNdptHAGE12->SetSavedPoint(71,2.952804e-17);
   getdNdptHAGE12->SetSavedPoint(72,2.400935e-17);
   getdNdptHAGE12->SetSavedPoint(73,1.957374e-17);
   getdNdptHAGE12->SetSavedPoint(74,1.599874e-17);
   getdNdptHAGE12->SetSavedPoint(75,1.310956e-17);
   getdNdptHAGE12->SetSavedPoint(76,1.076849e-17);
   getdNdptHAGE12->SetSavedPoint(77,8.866643e-18);
   getdNdptHAGE12->SetSavedPoint(78,7.317737e-18);
   getdNdptHAGE12->SetSavedPoint(79,6.053178e-18);
   getdNdptHAGE12->SetSavedPoint(80,5.018291e-18);
   getdNdptHAGE12->SetSavedPoint(81,4.169383e-18);
   getdNdptHAGE12->SetSavedPoint(82,3.471439e-18);
   getdNdptHAGE12->SetSavedPoint(83,2.896331e-18);
   getdNdptHAGE12->SetSavedPoint(84,2.421406e-18);
   getdNdptHAGE12->SetSavedPoint(85,2.028376e-18);
   getdNdptHAGE12->SetSavedPoint(86,1.702439e-18);
   getdNdptHAGE12->SetSavedPoint(87,1.43159e-18);
   getdNdptHAGE12->SetSavedPoint(88,1.20607e-18);
   getdNdptHAGE12->SetSavedPoint(89,1.017924e-18);
   getdNdptHAGE12->SetSavedPoint(90,8.606593e-19);
   getdNdptHAGE12->SetSavedPoint(91,7.289602e-19);
   getdNdptHAGE12->SetSavedPoint(92,6.184685e-19);
   getdNdptHAGE12->SetSavedPoint(93,5.256025e-19);
   getdNdptHAGE12->SetSavedPoint(94,4.474131e-19);
   getdNdptHAGE12->SetSavedPoint(95,3.814673e-19);
   getdNdptHAGE12->SetSavedPoint(96,3.257537e-19);
   getdNdptHAGE12->SetSavedPoint(97,2.786068e-19);
   getdNdptHAGE12->SetSavedPoint(98,2.386443e-19);
   getdNdptHAGE12->SetSavedPoint(99,2.047175e-19);
   getdNdptHAGE12->SetSavedPoint(100,1.758699e-19);
   getdNdptHAGE12->SetSavedPoint(101,1e-12);
   getdNdptHAGE12->SetSavedPoint(102,100);
   getdNdptHAGE12->SetFillColor(19);
   getdNdptHAGE12->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE12->SetLineColor(ci);
   getdNdptHAGE12->SetLineWidth(2);
   getdNdptHAGE12->SetChisquare(0.7643895);
   getdNdptHAGE12->SetNDF(7);
   getdNdptHAGE12->SetParameter(0,0.49368);
   getdNdptHAGE12->SetParError(0,0);
   getdNdptHAGE12->SetParLimits(0,0.49368,0.49368);
   getdNdptHAGE12->SetParameter(1,2.398838);
   getdNdptHAGE12->SetParError(1,0.02491643);
   getdNdptHAGE12->SetParLimits(1,0,0);
   getdNdptHAGE12->SetParameter(2,50);
   getdNdptHAGE12->SetParError(2,3.382823);
   getdNdptHAGE12->SetParLimits(2,50,200);
   getdNdptHAGE12->SetParameter(3,14.99992);
   getdNdptHAGE12->SetParError(3,7.09657);
   getdNdptHAGE12->SetParLimits(3,5,15);
   getdNdptHAGE12->SetParameter(4,0);
   getdNdptHAGE12->SetParError(4,0);
   getdNdptHAGE12->SetParLimits(4,1,1);
   getdNdptHAGE12->SetParent(cent0_kapL_AupLAu_62dO4__4);
   cent0_kapL_AupLAu_62dO4__4->GetListOfFunctions()->Add(getdNdptHAGE12);

   ci = TColor::GetColor("#000099");
   cent0_kapL_AupLAu_62dO4__4->SetLineColor(ci);
   cent0_kapL_AupLAu_62dO4__4->SetMarkerStyle(20);
   cent0_kapL_AupLAu_62dO4__4->GetXaxis()->SetRange(0,11);
   cent0_kapL_AupLAu_62dO4__4->GetXaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_62dO4__4->GetXaxis()->SetLabelSize(0.07);
   cent0_kapL_AupLAu_62dO4__4->GetXaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_62dO4__4->GetXaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetTitle("#frac{d^{2}N}{dydp_{T}}");
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->CenterTitle(true);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetLabelSize(0.1);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetTitleSize(0.1);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetTitleOffset(0.5);
   cent0_kapL_AupLAu_62dO4__4->GetYaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_62dO4__4->GetZaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_62dO4__4->GetZaxis()->SetLabelSize(0.035);
   cent0_kapL_AupLAu_62dO4__4->GetZaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_62dO4__4->GetZaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_62dO4__4->Draw("");
      tex = new TLatex(0.1,5,"k^{+}  62.4 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part4->Modified();
   c->cd();
  
// ------------>Primitives in pad: part5
   TPad *part5 = new TPad("part5", "part5",0.3733333,0.4133334,0.6866667,0.7066667);
   part5->Draw();
   part5->cd();
   part5->Range(-0.007692308,0.4348881,1.54,1.850394);
   part5->SetFillColor(0);
   part5->SetBorderMode(0);
   part5->SetBorderSize(0);
   part5->SetLogy();
   part5->SetLeftMargin(0);
   part5->SetRightMargin(0);
   part5->SetTopMargin(0);
   part5->SetBottomMargin(0);
   part5->SetFrameBorderMode(0);
   part5->SetFrameBorderMode(0);
   Double_t xAxis5[14] = {0.17, 0.23, 0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.78, 0.82}; 
   
   TH1D *cent0_kapL_AupLAu_130__5 = new TH1D("cent0_kapL_AupLAu_130__5","cent0_ka+_Au+Au_130",13, xAxis5);
   cent0_kapL_AupLAu_130__5->SetBinContent(1,29.889);
   cent0_kapL_AupLAu_130__5->SetBinContent(2,30.22);
   cent0_kapL_AupLAu_130__5->SetBinContent(3,25.782);
   cent0_kapL_AupLAu_130__5->SetBinContent(4,24.528);
   cent0_kapL_AupLAu_130__5->SetBinContent(5,21.947);
   cent0_kapL_AupLAu_130__5->SetBinContent(6,19.935);
   cent0_kapL_AupLAu_130__5->SetBinContent(7,17.799);
   cent0_kapL_AupLAu_130__5->SetBinContent(8,15.673);
   cent0_kapL_AupLAu_130__5->SetBinContent(9,14.281);
   cent0_kapL_AupLAu_130__5->SetBinContent(10,12.27);
   cent0_kapL_AupLAu_130__5->SetBinContent(11,9.784);
   cent0_kapL_AupLAu_130__5->SetBinContent(12,9.099);
   cent0_kapL_AupLAu_130__5->SetBinContent(13,6.285);
   cent0_kapL_AupLAu_130__5->SetBinError(1,1.742);
   cent0_kapL_AupLAu_130__5->SetBinError(2,1.637);
   cent0_kapL_AupLAu_130__5->SetBinError(3,1.362);
   cent0_kapL_AupLAu_130__5->SetBinError(4,1.282);
   cent0_kapL_AupLAu_130__5->SetBinError(5,1.144);
   cent0_kapL_AupLAu_130__5->SetBinError(6,1.045);
   cent0_kapL_AupLAu_130__5->SetBinError(7,0.938);
   cent0_kapL_AupLAu_130__5->SetBinError(8,1.584);
   cent0_kapL_AupLAu_130__5->SetBinError(9,1.446);
   cent0_kapL_AupLAu_130__5->SetBinError(10,1.252);
   cent0_kapL_AupLAu_130__5->SetBinError(11,1.023);
   cent0_kapL_AupLAu_130__5->SetBinError(12,1.015);
   cent0_kapL_AupLAu_130__5->SetBinError(13,0.841);
   cent0_kapL_AupLAu_130__5->SetEntries(13);
   
   TF1 *getdNdpt13 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt13->SetRange(1e-14,100);
   getdNdpt13->SetName("getdNdpt");
   getdNdpt13->SetTitle("getdNdpt");
   getdNdpt13->SetSavedPoint(0,33.49655);
   getdNdpt13->SetSavedPoint(1,3.391948);
   getdNdpt13->SetSavedPoint(2,0.04885014);
   getdNdpt13->SetSavedPoint(3,0.0005313038);
   getdNdpt13->SetSavedPoint(4,5.473935e-06);
   getdNdpt13->SetSavedPoint(5,5.588114e-08);
   getdNdpt13->SetSavedPoint(6,5.719479e-10);
   getdNdpt13->SetSavedPoint(7,5.888144e-12);
   getdNdpt13->SetSavedPoint(8,6.100938e-14);
   getdNdpt13->SetSavedPoint(9,6.360665e-16);
   getdNdpt13->SetSavedPoint(10,6.669179e-18);
   getdNdpt13->SetSavedPoint(11,7.028476e-20);
   getdNdpt13->SetSavedPoint(12,7.44108e-22);
   getdNdpt13->SetSavedPoint(13,7.91019e-24);
   getdNdpt13->SetSavedPoint(14,8.439744e-26);
   getdNdpt13->SetSavedPoint(15,9.034452e-28);
   getdNdpt13->SetSavedPoint(16,9.699831e-30);
   getdNdpt13->SetSavedPoint(17,1.044225e-31);
   getdNdpt13->SetSavedPoint(18,1.126899e-33);
   getdNdpt13->SetSavedPoint(19,1.218831e-35);
   getdNdpt13->SetSavedPoint(20,1.320954e-37);
   getdNdpt13->SetSavedPoint(21,1.434317e-39);
   getdNdpt13->SetSavedPoint(22,1.560098e-41);
   getdNdpt13->SetSavedPoint(23,1.699616e-43);
   getdNdpt13->SetSavedPoint(24,1.85435e-45);
   getdNdpt13->SetSavedPoint(25,2.02595e-47);
   getdNdpt13->SetSavedPoint(26,2.216263e-49);
   getdNdpt13->SetSavedPoint(27,2.427353e-51);
   getdNdpt13->SetSavedPoint(28,2.661524e-53);
   getdNdpt13->SetSavedPoint(29,2.921352e-55);
   getdNdpt13->SetSavedPoint(30,3.209713e-57);
   getdNdpt13->SetSavedPoint(31,3.52982e-59);
   getdNdpt13->SetSavedPoint(32,1.492549e-61);
   getdNdpt13->SetSavedPoint(33,1.526497e-66);
   getdNdpt13->SetSavedPoint(34,3.771853e-71);
   getdNdpt13->SetSavedPoint(35,1.970726e-76);
   getdNdpt13->SetSavedPoint(36,2.404065e-82);
   getdNdpt13->SetSavedPoint(37,7.834028e-89);
   getdNdpt13->SetSavedPoint(38,8.125468e-96);
   getdNdpt13->SetSavedPoint(39,2.130588e-98);
   getdNdpt13->SetSavedPoint(40,6.385355e-106);
   getdNdpt13->SetSavedPoint(41,8.725842e-114);
   getdNdpt13->SetSavedPoint(42,6.838443e-122);
   getdNdpt13->SetSavedPoint(43,3.924216e-130);
   getdNdpt13->SetSavedPoint(44,2.127706e-138);
   getdNdpt13->SetSavedPoint(45,1.445208e-146);
   getdNdpt13->SetSavedPoint(46,1.683068e-154);
   getdNdpt13->SetSavedPoint(47,1.388251e-165);
   getdNdpt13->SetSavedPoint(48,4.203946e-174);
   getdNdpt13->SetSavedPoint(49,6.020525e-188);
   getdNdpt13->SetSavedPoint(50,1.094736e-201);
   getdNdpt13->SetSavedPoint(51,9.612412e-219);
   getdNdpt13->SetSavedPoint(52,1.524821e-238);
   getdNdpt13->SetSavedPoint(53,5.201309e-269);
   getdNdpt13->SetSavedPoint(54,0);
   getdNdpt13->SetSavedPoint(55,0);
   getdNdpt13->SetSavedPoint(56,0);
   getdNdpt13->SetSavedPoint(57,0);
   getdNdpt13->SetSavedPoint(58,0);
   getdNdpt13->SetSavedPoint(59,0);
   getdNdpt13->SetSavedPoint(60,0);
   getdNdpt13->SetSavedPoint(61,0);
   getdNdpt13->SetSavedPoint(62,0);
   getdNdpt13->SetSavedPoint(63,0);
   getdNdpt13->SetSavedPoint(64,0);
   getdNdpt13->SetSavedPoint(65,0);
   getdNdpt13->SetSavedPoint(66,0);
   getdNdpt13->SetSavedPoint(67,0);
   getdNdpt13->SetSavedPoint(68,0);
   getdNdpt13->SetSavedPoint(69,0);
   getdNdpt13->SetSavedPoint(70,0);
   getdNdpt13->SetSavedPoint(71,0);
   getdNdpt13->SetSavedPoint(72,0);
   getdNdpt13->SetSavedPoint(73,0);
   getdNdpt13->SetSavedPoint(74,0);
   getdNdpt13->SetSavedPoint(75,0);
   getdNdpt13->SetSavedPoint(76,0);
   getdNdpt13->SetSavedPoint(77,0);
   getdNdpt13->SetSavedPoint(78,0);
   getdNdpt13->SetSavedPoint(79,0);
   getdNdpt13->SetSavedPoint(80,0);
   getdNdpt13->SetSavedPoint(81,0);
   getdNdpt13->SetSavedPoint(82,0);
   getdNdpt13->SetSavedPoint(83,0);
   getdNdpt13->SetSavedPoint(84,0);
   getdNdpt13->SetSavedPoint(85,0);
   getdNdpt13->SetSavedPoint(86,0);
   getdNdpt13->SetSavedPoint(87,0);
   getdNdpt13->SetSavedPoint(88,0);
   getdNdpt13->SetSavedPoint(89,0);
   getdNdpt13->SetSavedPoint(90,0);
   getdNdpt13->SetSavedPoint(91,0);
   getdNdpt13->SetSavedPoint(92,0);
   getdNdpt13->SetSavedPoint(93,0);
   getdNdpt13->SetSavedPoint(94,0);
   getdNdpt13->SetSavedPoint(95,0);
   getdNdpt13->SetSavedPoint(96,0);
   getdNdpt13->SetSavedPoint(97,0);
   getdNdpt13->SetSavedPoint(98,0);
   getdNdpt13->SetSavedPoint(99,0);
   getdNdpt13->SetSavedPoint(100,0);
   getdNdpt13->SetSavedPoint(101,1e-14);
   getdNdpt13->SetSavedPoint(102,100);
   getdNdpt13->SetFillColor(19);
   getdNdpt13->SetFillStyle(0);
   getdNdpt13->SetLineWidth(2);
   getdNdpt13->SetChisquare(3.52391);
   getdNdpt13->SetNDF(9);
   getdNdpt13->SetParameter(0,0.49368);
   getdNdpt13->SetParError(0,0);
   getdNdpt13->SetParLimits(0,0.49368,0.49368);
   getdNdpt13->SetParameter(1,0.8081486);
   getdNdpt13->SetParError(1,0.03949564);
   getdNdpt13->SetParLimits(1,0.5,1);
   getdNdpt13->SetParameter(2,0.07270724);
   getdNdpt13->SetParError(2,0.0003748937);
   getdNdpt13->SetParLimits(2,0,0);
   getdNdpt13->SetParameter(3,0.8460893);
   getdNdpt13->SetParError(3,0.1305574);
   getdNdpt13->SetParLimits(3,0,0);
   getdNdpt13->SetParameter(4,912752.1);
   getdNdpt13->SetParError(4,17364.65);
   getdNdpt13->SetParLimits(4,0,0);
   getdNdpt13->SetParameter(5,0);
   getdNdpt13->SetParError(5,0);
   getdNdpt13->SetParLimits(5,1,1);
   getdNdpt13->SetParent(cent0_kapL_AupLAu_130__5);
   cent0_kapL_AupLAu_130__5->GetListOfFunctions()->Add(getdNdpt13);
   
   TF1 *getdNdpt214 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt214->SetRange(1e-14,100);
   getdNdpt214->SetName("getdNdpt2");
   getdNdpt214->SetTitle("getdNdpt2");
   getdNdpt214->SetSavedPoint(0,33.47196);
   getdNdpt214->SetSavedPoint(1,3.402333);
   getdNdpt214->SetSavedPoint(2,0.05021565);
   getdNdpt214->SetSavedPoint(3,0.0005479272);
   getdNdpt214->SetSavedPoint(4,5.48751e-06);
   getdNdpt214->SetSavedPoint(5,5.304046e-08);
   getdNdpt214->SetSavedPoint(6,5.035483e-10);
   getdNdpt214->SetSavedPoint(7,4.73171e-12);
   getdNdpt214->SetSavedPoint(8,4.418044e-14);
   getdNdpt214->SetSavedPoint(9,4.107938e-16);
   getdNdpt214->SetSavedPoint(10,3.808639e-18);
   getdNdpt214->SetSavedPoint(11,3.523966e-20);
   getdNdpt214->SetSavedPoint(12,3.255754e-22);
   getdNdpt214->SetSavedPoint(13,3.004673e-24);
   getdNdpt214->SetSavedPoint(14,2.770687e-26);
   getdNdpt214->SetSavedPoint(15,2.553344e-28);
   getdNdpt214->SetSavedPoint(16,2.351948e-30);
   getdNdpt214->SetSavedPoint(17,2.165666e-32);
   getdNdpt214->SetSavedPoint(18,1.993601e-34);
   getdNdpt214->SetSavedPoint(19,1.834838e-36);
   getdNdpt214->SetSavedPoint(20,1.688469e-38);
   getdNdpt214->SetSavedPoint(21,1.553612e-40);
   getdNdpt214->SetSavedPoint(22,1.429425e-42);
   getdNdpt214->SetSavedPoint(23,1.315106e-44);
   getdNdpt214->SetSavedPoint(24,1.209905e-46);
   getdNdpt214->SetSavedPoint(25,1.113116e-48);
   getdNdpt214->SetSavedPoint(26,1.024082e-50);
   getdNdpt214->SetSavedPoint(27,9.421926e-53);
   getdNdpt214->SetSavedPoint(28,8.668812e-55);
   getdNdpt214->SetSavedPoint(29,7.976238e-57);
   getdNdpt214->SetSavedPoint(30,7.339362e-59);
   getdNdpt214->SetSavedPoint(31,6.753713e-61);
   getdNdpt214->SetSavedPoint(32,6.215171e-63);
   getdNdpt214->SetSavedPoint(33,5.719938e-65);
   getdNdpt214->SetSavedPoint(34,5.26452e-67);
   getdNdpt214->SetSavedPoint(35,4.845699e-69);
   getdNdpt214->SetSavedPoint(36,4.460518e-71);
   getdNdpt214->SetSavedPoint(37,4.106255e-73);
   getdNdpt214->SetSavedPoint(38,3.780411e-75);
   getdNdpt214->SetSavedPoint(39,3.480685e-77);
   getdNdpt214->SetSavedPoint(40,3.204967e-79);
   getdNdpt214->SetSavedPoint(41,2.951316e-81);
   getdNdpt214->SetSavedPoint(42,2.717947e-83);
   getdNdpt214->SetSavedPoint(43,2.503224e-85);
   getdNdpt214->SetSavedPoint(44,2.305641e-87);
   getdNdpt214->SetSavedPoint(45,2.123816e-89);
   getdNdpt214->SetSavedPoint(46,1.956479e-91);
   getdNdpt214->SetSavedPoint(47,1.802463e-93);
   getdNdpt214->SetSavedPoint(48,1.660697e-95);
   getdNdpt214->SetSavedPoint(49,1.530194e-97);
   getdNdpt214->SetSavedPoint(50,1.410052e-99);
   getdNdpt214->SetSavedPoint(51,1.299438e-101);
   getdNdpt214->SetSavedPoint(52,1.197589e-103);
   getdNdpt214->SetSavedPoint(53,1.103803e-105);
   getdNdpt214->SetSavedPoint(54,1.017433e-107);
   getdNdpt214->SetSavedPoint(55,9.378883e-110);
   getdNdpt214->SetSavedPoint(56,8.646229e-112);
   getdNdpt214->SetSavedPoint(57,7.971358e-114);
   getdNdpt214->SetSavedPoint(58,7.349666e-116);
   getdNdpt214->SetSavedPoint(59,6.776918e-118);
   getdNdpt214->SetSavedPoint(60,6.249221e-120);
   getdNdpt214->SetSavedPoint(61,5.762993e-122);
   getdNdpt214->SetSavedPoint(62,5.314944e-124);
   getdNdpt214->SetSavedPoint(63,4.902044e-126);
   getdNdpt214->SetSavedPoint(64,4.521507e-128);
   getdNdpt214->SetSavedPoint(65,4.170773e-130);
   getdNdpt214->SetSavedPoint(66,3.847484e-132);
   getdNdpt214->SetSavedPoint(67,3.549471e-134);
   getdNdpt214->SetSavedPoint(68,3.274738e-136);
   getdNdpt214->SetSavedPoint(69,3.021451e-138);
   getdNdpt214->SetSavedPoint(70,2.787918e-140);
   getdNdpt214->SetSavedPoint(71,2.572585e-142);
   getdNdpt214->SetSavedPoint(72,2.374019e-144);
   getdNdpt214->SetSavedPoint(73,2.190904e-146);
   getdNdpt214->SetSavedPoint(74,2.020937e-148);
   getdNdpt214->SetSavedPoint(75,7.233927e-154);
   getdNdpt214->SetSavedPoint(76,2.882528e-165);
   getdNdpt214->SetSavedPoint(77,0);
   getdNdpt214->SetSavedPoint(78,0);
   getdNdpt214->SetSavedPoint(79,0);
   getdNdpt214->SetSavedPoint(80,0);
   getdNdpt214->SetSavedPoint(81,0);
   getdNdpt214->SetSavedPoint(82,0);
   getdNdpt214->SetSavedPoint(83,0);
   getdNdpt214->SetSavedPoint(84,0);
   getdNdpt214->SetSavedPoint(85,0);
   getdNdpt214->SetSavedPoint(86,0);
   getdNdpt214->SetSavedPoint(87,0);
   getdNdpt214->SetSavedPoint(88,0);
   getdNdpt214->SetSavedPoint(89,0);
   getdNdpt214->SetSavedPoint(90,0);
   getdNdpt214->SetSavedPoint(91,0);
   getdNdpt214->SetSavedPoint(92,0);
   getdNdpt214->SetSavedPoint(93,0);
   getdNdpt214->SetSavedPoint(94,0);
   getdNdpt214->SetSavedPoint(95,0);
   getdNdpt214->SetSavedPoint(96,0);
   getdNdpt214->SetSavedPoint(97,0);
   getdNdpt214->SetSavedPoint(98,0);
   getdNdpt214->SetSavedPoint(99,0);
   getdNdpt214->SetSavedPoint(100,0);
   getdNdpt214->SetSavedPoint(101,1e-14);
   getdNdpt214->SetSavedPoint(102,100);
   getdNdpt214->SetFillColor(19);
   getdNdpt214->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt214->SetLineColor(ci);
   getdNdpt214->SetLineWidth(2);
   getdNdpt214->SetChisquare(3.53606);
   getdNdpt214->SetNDF(9);
   getdNdpt214->SetParameter(0,0.49368);
   getdNdpt214->SetParError(0,0);
   getdNdpt214->SetParLimits(0,0.49368,0.49368);
   getdNdpt214->SetParameter(1,0.5301017);
   getdNdpt214->SetParError(1,0.0838905);
   getdNdpt214->SetParLimits(1,0.3,0.8);
   getdNdpt214->SetParameter(2,0.1184687);
   getdNdpt214->SetParError(2,0.02115598);
   getdNdpt214->SetParLimits(2,0.08,0.2);
   getdNdpt214->SetParameter(3,0.01065691);
   getdNdpt214->SetParError(3,3.715302);
   getdNdpt214->SetParLimits(3,0.01,5);
   getdNdpt214->SetParameter(4,30139.55);
   getdNdpt214->SetParError(4,30903.4);
   getdNdpt214->SetParLimits(4,0,0);
   getdNdpt214->SetParameter(5,0);
   getdNdpt214->SetParError(5,0);
   getdNdpt214->SetParLimits(5,1,1);
   getdNdpt214->SetParent(cent0_kapL_AupLAu_130__5);
   cent0_kapL_AupLAu_130__5->GetListOfFunctions()->Add(getdNdpt214);
   
   TF1 *getdNdptHAGE15 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE15->SetRange(1e-12,100);
   getdNdptHAGE15->SetName("getdNdptHAGE");
   getdNdptHAGE15->SetTitle("getdNdptHAGE");
   getdNdptHAGE15->SetSavedPoint(0,37.73447);
   getdNdptHAGE15->SetSavedPoint(1,4.66137);
   getdNdptHAGE15->SetSavedPoint(2,0.4370566);
   getdNdptHAGE15->SetSavedPoint(3,0.05827813);
   getdNdptHAGE15->SetSavedPoint(4,0.01000456);
   getdNdptHAGE15->SetSavedPoint(5,0.002075493);
   getdNdptHAGE15->SetSavedPoint(6,0.0004998063);
   getdNdptHAGE15->SetSavedPoint(7,0.0001359043);
   getdNdptHAGE15->SetSavedPoint(8,4.089598e-05);
   getdNdptHAGE15->SetSavedPoint(9,1.341299e-05);
   getdNdptHAGE15->SetSavedPoint(10,4.738057e-06);
   getdNdptHAGE15->SetSavedPoint(11,1.785564e-06);
   getdNdptHAGE15->SetSavedPoint(12,7.123429e-07);
   getdNdptHAGE15->SetSavedPoint(13,2.989256e-07);
   getdNdptHAGE15->SetSavedPoint(14,1.312416e-07);
   getdNdptHAGE15->SetSavedPoint(15,6.001292e-08);
   getdNdptHAGE15->SetSavedPoint(16,2.847086e-08);
   getdNdptHAGE15->SetSavedPoint(17,1.396653e-08);
   getdNdptHAGE15->SetSavedPoint(18,7.063976e-09);
   getdNdptHAGE15->SetSavedPoint(19,3.674362e-09);
   getdNdptHAGE15->SetSavedPoint(20,1.961185e-09);
   getdNdptHAGE15->SetSavedPoint(21,1.07202e-09);
   getdNdptHAGE15->SetSavedPoint(22,5.990644e-10);
   getdNdptHAGE15->SetSavedPoint(23,3.41705e-10);
   getdNdptHAGE15->SetSavedPoint(24,1.986675e-10);
   getdNdptHAGE15->SetSavedPoint(25,1.175849e-10);
   getdNdptHAGE15->SetSavedPoint(26,7.076685e-11);
   getdNdptHAGE15->SetSavedPoint(27,4.326256e-11);
   getdNdptHAGE15->SetSavedPoint(28,2.684047e-11);
   getdNdptHAGE15->SetSavedPoint(29,1.688459e-11);
   getdNdptHAGE15->SetSavedPoint(30,1.076149e-11);
   getdNdptHAGE15->SetSavedPoint(31,6.944217e-12);
   getdNdptHAGE15->SetSavedPoint(32,4.533727e-12);
   getdNdptHAGE15->SetSavedPoint(33,2.992979e-12);
   getdNdptHAGE15->SetSavedPoint(34,1.996749e-12);
   getdNdptHAGE15->SetSavedPoint(35,1.345514e-12);
   getdNdptHAGE15->SetSavedPoint(36,9.153519e-13);
   getdNdptHAGE15->SetSavedPoint(37,6.283877e-13);
   getdNdptHAGE15->SetSavedPoint(38,4.351364e-13);
   getdNdptHAGE15->SetSavedPoint(39,3.03817e-13);
   getdNdptHAGE15->SetSavedPoint(40,2.138108e-13);
   getdNdptHAGE15->SetSavedPoint(41,1.516107e-13);
   getdNdptHAGE15->SetSavedPoint(42,1.082866e-13);
   getdNdptHAGE15->SetSavedPoint(43,7.788145e-14);
   getdNdptHAGE15->SetSavedPoint(44,5.63879e-14);
   getdNdptHAGE15->SetSavedPoint(45,4.108805e-14);
   getdNdptHAGE15->SetSavedPoint(46,3.012416e-14);
   getdNdptHAGE15->SetSavedPoint(47,2.221684e-14);
   getdNdptHAGE15->SetSavedPoint(48,1.647864e-14);
   getdNdptHAGE15->SetSavedPoint(49,1.228971e-14);
   getdNdptHAGE15->SetSavedPoint(50,9.214182e-15);
   getdNdptHAGE15->SetSavedPoint(51,6.943619e-15);
   getdNdptHAGE15->SetSavedPoint(52,5.258376e-15);
   getdNdptHAGE15->SetSavedPoint(53,4.001115e-15);
   getdNdptHAGE15->SetSavedPoint(54,3.058473e-15);
   getdNdptHAGE15->SetSavedPoint(55,2.348315e-15);
   getdNdptHAGE15->SetSavedPoint(56,1.810813e-15);
   getdNdptHAGE15->SetSavedPoint(57,1.402157e-15);
   getdNdptHAGE15->SetSavedPoint(58,1.090106e-15);
   getdNdptHAGE15->SetSavedPoint(59,8.508149e-16);
   getdNdptHAGE15->SetSavedPoint(60,6.665679e-16);
   getdNdptHAGE15->SetSavedPoint(61,5.241398e-16);
   getdNdptHAGE15->SetSavedPoint(62,4.136147e-16);
   getdNdptHAGE15->SetSavedPoint(63,3.27526e-16);
   getdNdptHAGE15->SetSavedPoint(64,2.602277e-16);
   getdNdptHAGE15->SetSavedPoint(65,2.074329e-16);
   getdNdptHAGE15->SetSavedPoint(66,1.658741e-16);
   getdNdptHAGE15->SetSavedPoint(67,1.33051e-16);
   getdNdptHAGE15->SetSavedPoint(68,1.070435e-16);
   getdNdptHAGE15->SetSavedPoint(69,8.637138e-17);
   getdNdptHAGE15->SetSavedPoint(70,6.988971e-17);
   getdNdptHAGE15->SetSavedPoint(71,5.67098e-17);
   getdNdptHAGE15->SetSavedPoint(72,4.613958e-17);
   getdNdptHAGE15->SetSavedPoint(73,3.763829e-17);
   getdNdptHAGE15->SetSavedPoint(74,3.078209e-17);
   getdNdptHAGE15->SetSavedPoint(75,2.523776e-17);
   getdNdptHAGE15->SetSavedPoint(76,2.074251e-17);
   getdNdptHAGE15->SetSavedPoint(77,1.70885e-17);
   getdNdptHAGE15->SetSavedPoint(78,1.411087e-17);
   getdNdptHAGE15->SetSavedPoint(79,1.167851e-17);
   getdNdptHAGE15->SetSavedPoint(80,9.686831e-18);
   getdNdptHAGE15->SetSavedPoint(81,8.052195e-18);
   getdNdptHAGE15->SetSavedPoint(82,6.707548e-18);
   getdNdptHAGE15->SetSavedPoint(83,5.598988e-18);
   getdNdptHAGE15->SetSavedPoint(84,4.683078e-18);
   getdNdptHAGE15->SetSavedPoint(85,3.924733e-18);
   getdNdptHAGE15->SetSavedPoint(86,3.295543e-18);
   getdNdptHAGE15->SetSavedPoint(87,2.77245e-18);
   getdNdptHAGE15->SetSavedPoint(88,2.3367e-18);
   getdNdptHAGE15->SetSavedPoint(89,1.973003e-18);
   getdNdptHAGE15->SetSavedPoint(90,1.668866e-18);
   getdNdptHAGE15->SetSavedPoint(91,1.414061e-18);
   getdNdptHAGE15->SetSavedPoint(92,1.200197e-18);
   getdNdptHAGE15->SetSavedPoint(93,1.020375e-18);
   getdNdptHAGE15->SetSavedPoint(94,8.689102e-19);
   getdNdptHAGE15->SetSavedPoint(95,7.411125e-19);
   getdNdptHAGE15->SetSavedPoint(96,6.331021e-19);
   getdNdptHAGE15->SetSavedPoint(97,5.416647e-19);
   getdNdptHAGE15->SetSavedPoint(98,4.641319e-19);
   getdNdptHAGE15->SetSavedPoint(99,3.982851e-19);
   getdNdptHAGE15->SetSavedPoint(100,3.422758e-19);
   getdNdptHAGE15->SetSavedPoint(101,1e-12);
   getdNdptHAGE15->SetSavedPoint(102,100);
   getdNdptHAGE15->SetFillColor(19);
   getdNdptHAGE15->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE15->SetLineColor(ci);
   getdNdptHAGE15->SetLineWidth(2);
   getdNdptHAGE15->SetChisquare(7.850782);
   getdNdptHAGE15->SetNDF(10);
   getdNdptHAGE15->SetParameter(0,0.49368);
   getdNdptHAGE15->SetParError(0,0);
   getdNdptHAGE15->SetParLimits(0,0.49368,0.49368);
   getdNdptHAGE15->SetParameter(1,2.30609);
   getdNdptHAGE15->SetParError(1,0.2128427);
   getdNdptHAGE15->SetParLimits(1,0,0);
   getdNdptHAGE15->SetParameter(2,55.81494);
   getdNdptHAGE15->SetParError(2,7.02708);
   getdNdptHAGE15->SetParLimits(2,50,200);
   getdNdptHAGE15->SetParameter(3,15);
   getdNdptHAGE15->SetParError(3,8.704016);
   getdNdptHAGE15->SetParLimits(3,5,15);
   getdNdptHAGE15->SetParameter(4,0);
   getdNdptHAGE15->SetParError(4,0);
   getdNdptHAGE15->SetParLimits(4,1,1);
   getdNdptHAGE15->SetParent(cent0_kapL_AupLAu_130__5);
   cent0_kapL_AupLAu_130__5->GetListOfFunctions()->Add(getdNdptHAGE15);

   ci = TColor::GetColor("#000099");
   cent0_kapL_AupLAu_130__5->SetLineColor(ci);
   cent0_kapL_AupLAu_130__5->SetMarkerStyle(20);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetRange(0,14);
   cent0_kapL_AupLAu_130__5->GetXaxis()->CenterTitle(true);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetLabelSize(0.1);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetTitleSize(0.2);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetTitleOffset(0.5);
   cent0_kapL_AupLAu_130__5->GetXaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_130__5->GetYaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_130__5->GetYaxis()->SetLabelSize(0.1);
   cent0_kapL_AupLAu_130__5->GetYaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_130__5->GetYaxis()->SetTitleOffset(0);
   cent0_kapL_AupLAu_130__5->GetYaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_130__5->GetZaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_130__5->GetZaxis()->SetLabelSize(0.035);
   cent0_kapL_AupLAu_130__5->GetZaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_130__5->GetZaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_130__5->Draw("");
      tex = new TLatex(0.1,5,"k^{+}  130 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part5->Modified();
   c->cd();
  
// ------------>Primitives in pad: part6
   TPad *part6 = new TPad("part6", "part6",0.6866667,0.4133334,1,0.7066667);
   part6->Draw();
   part6->cd();
   part6->Range(-0.04,0.6857417,1.55596,1.843905);
   part6->SetFillColor(0);
   part6->SetBorderMode(0);
   part6->SetBorderSize(0);
   part6->SetLogy();
   part6->SetLeftMargin(0);
   part6->SetRightMargin(0.01);
   part6->SetTopMargin(0);
   part6->SetBottomMargin(0);
   part6->SetFrameBorderMode(0);
   part6->SetFrameBorderMode(0);
   Double_t xAxis6[11] = {0.23, 0.28, 0.33, 0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72}; 
   
   TH1D *cent0_kapL_AupLAu_200__6 = new TH1D("cent0_kapL_AupLAu_200__6","cent0_ka+_Au+Au_200",10, xAxis6);
   cent0_kapL_AupLAu_200__6->SetBinContent(1,27.3);
   cent0_kapL_AupLAu_200__6->SetBinContent(2,25.42);
   cent0_kapL_AupLAu_200__6->SetBinContent(3,23.85);
   cent0_kapL_AupLAu_200__6->SetBinContent(4,22.18);
   cent0_kapL_AupLAu_200__6->SetBinContent(5,20.5);
   cent0_kapL_AupLAu_200__6->SetBinContent(6,18.1);
   cent0_kapL_AupLAu_200__6->SetBinContent(7,16.5);
   cent0_kapL_AupLAu_200__6->SetBinContent(8,14.8);
   cent0_kapL_AupLAu_200__6->SetBinContent(9,13.1);
   cent0_kapL_AupLAu_200__6->SetBinContent(10,10.8);
   cent0_kapL_AupLAu_200__6->SetBinError(1,1.9);
   cent0_kapL_AupLAu_200__6->SetBinError(2,0.79);
   cent0_kapL_AupLAu_200__6->SetBinError(3,0.49);
   cent0_kapL_AupLAu_200__6->SetBinError(4,0.66);
   cent0_kapL_AupLAu_200__6->SetBinError(5,1);
   cent0_kapL_AupLAu_200__6->SetBinError(6,2.1);
   cent0_kapL_AupLAu_200__6->SetBinError(7,2);
   cent0_kapL_AupLAu_200__6->SetBinError(8,1.8);
   cent0_kapL_AupLAu_200__6->SetBinError(9,1);
   cent0_kapL_AupLAu_200__6->SetBinError(10,1.1);
   cent0_kapL_AupLAu_200__6->SetEntries(10);
   
   TF1 *getdNdpt16 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt16->SetRange(1e-14,100);
   getdNdpt16->SetName("getdNdpt");
   getdNdpt16->SetTitle("getdNdpt");
   getdNdpt16->SetSavedPoint(0,30.1567);
   getdNdpt16->SetSavedPoint(1,4.480191);
   getdNdpt16->SetSavedPoint(2,0.1696484);
   getdNdpt16->SetSavedPoint(3,0.01737688);
   getdNdpt16->SetSavedPoint(4,0.005089028);
   getdNdpt16->SetSavedPoint(5,0.002268361);
   getdNdpt16->SetSavedPoint(6,0.001189021);
   getdNdpt16->SetSavedPoint(7,0.0006499248);
   getdNdpt16->SetSavedPoint(8,0.0003442678);
   getdNdpt16->SetSavedPoint(9,0.0001696736);
   getdNdpt16->SetSavedPoint(10,7.629546e-05);
   getdNdpt16->SetSavedPoint(11,3.104618e-05);
   getdNdpt16->SetSavedPoint(12,1.139977e-05);
   getdNdpt16->SetSavedPoint(13,3.776322e-06);
   getdNdpt16->SetSavedPoint(14,1.334444e-08);
   getdNdpt16->SetSavedPoint(15,3.814351e-09);
   getdNdpt16->SetSavedPoint(16,1.088272e-09);
   getdNdpt16->SetSavedPoint(17,3.100101e-10);
   getdNdpt16->SetSavedPoint(18,4.149238e-15);
   getdNdpt16->SetSavedPoint(19,6.087623e-16);
   getdNdpt16->SetSavedPoint(20,9.23919e-17);
   getdNdpt16->SetSavedPoint(21,1.401438e-17);
   getdNdpt16->SetSavedPoint(22,2.124712e-18);
   getdNdpt16->SetSavedPoint(23,3.219879e-19);
   getdNdpt16->SetSavedPoint(24,4.877701e-20);
   getdNdpt16->SetSavedPoint(25,7.386628e-21);
   getdNdpt16->SetSavedPoint(26,1.118277e-21);
   getdNdpt16->SetSavedPoint(27,1.692538e-22);
   getdNdpt16->SetSavedPoint(28,2.561096e-23);
   getdNdpt16->SetSavedPoint(29,3.874556e-24);
   getdNdpt16->SetSavedPoint(30,5.860517e-25);
   getdNdpt16->SetSavedPoint(31,8.862895e-26);
   getdNdpt16->SetSavedPoint(32,1.340133e-26);
   getdNdpt16->SetSavedPoint(33,2.026093e-27);
   getdNdpt16->SetSavedPoint(34,3.062772e-28);
   getdNdpt16->SetSavedPoint(35,4.629341e-29);
   getdNdpt16->SetSavedPoint(36,6.996435e-30);
   getdNdpt16->SetSavedPoint(37,1.057284e-30);
   getdNdpt16->SetSavedPoint(38,1.5976e-31);
   getdNdpt16->SetSavedPoint(39,2.377646e-41);
   getdNdpt16->SetSavedPoint(40,2.076997e-42);
   getdNdpt16->SetSavedPoint(41,1.81426e-43);
   getdNdpt16->SetSavedPoint(42,1.584674e-44);
   getdNdpt16->SetSavedPoint(43,1.384073e-45);
   getdNdpt16->SetSavedPoint(44,1.20881e-46);
   getdNdpt16->SetSavedPoint(45,1.055694e-47);
   getdNdpt16->SetSavedPoint(46,9.219365e-49);
   getdNdpt16->SetSavedPoint(47,8.050955e-50);
   getdNdpt16->SetSavedPoint(48,7.13411e-51);
   getdNdpt16->SetSavedPoint(49,7.841853e-60);
   getdNdpt16->SetSavedPoint(50,4.683613e-61);
   getdNdpt16->SetSavedPoint(51,2.797255e-62);
   getdNdpt16->SetSavedPoint(52,1.6706e-63);
   getdNdpt16->SetSavedPoint(53,9.977069e-65);
   getdNdpt16->SetSavedPoint(54,5.943885e-66);
   getdNdpt16->SetSavedPoint(55,7.151704e-74);
   getdNdpt16->SetSavedPoint(56,3.207581e-75);
   getdNdpt16->SetSavedPoint(57,1.438595e-76);
   getdNdpt16->SetSavedPoint(58,6.458066e-78);
   getdNdpt16->SetSavedPoint(59,6.329889e-85);
   getdNdpt16->SetSavedPoint(60,2.266586e-86);
   getdNdpt16->SetSavedPoint(61,8.11735e-88);
   getdNdpt16->SetSavedPoint(62,4.638888e-94);
   getdNdpt16->SetSavedPoint(63,1.385809e-95);
   getdNdpt16->SetSavedPoint(64,5.58622e-97);
   getdNdpt16->SetSavedPoint(65,9.595549e-103);
   getdNdpt16->SetSavedPoint(66,9.120963e-108);
   getdNdpt16->SetSavedPoint(67,2.11379e-109);
   getdNdpt16->SetSavedPoint(68,5.874334e-114);
   getdNdpt16->SetSavedPoint(69,4.550397e-118);
   getdNdpt16->SetSavedPoint(70,1.117379e-121);
   getdNdpt16->SetSavedPoint(71,3.947993e-127);
   getdNdpt16->SetSavedPoint(72,4.894824e-131);
   getdNdpt16->SetSavedPoint(73,6.495164e-137);
   getdNdpt16->SetSavedPoint(74,6.177701e-142);
   getdNdpt16->SetSavedPoint(75,7.050237e-147);
   getdNdpt16->SetSavedPoint(76,7.214288e-153);
   getdNdpt16->SetSavedPoint(77,1.563538e-158);
   getdNdpt16->SetSavedPoint(78,0);
   getdNdpt16->SetSavedPoint(79,0);
   getdNdpt16->SetSavedPoint(80,0);
   getdNdpt16->SetSavedPoint(81,0);
   getdNdpt16->SetSavedPoint(82,0);
   getdNdpt16->SetSavedPoint(83,0);
   getdNdpt16->SetSavedPoint(84,0);
   getdNdpt16->SetSavedPoint(85,0);
   getdNdpt16->SetSavedPoint(86,0);
   getdNdpt16->SetSavedPoint(87,0);
   getdNdpt16->SetSavedPoint(88,0);
   getdNdpt16->SetSavedPoint(89,0);
   getdNdpt16->SetSavedPoint(90,0);
   getdNdpt16->SetSavedPoint(91,0);
   getdNdpt16->SetSavedPoint(92,0);
   getdNdpt16->SetSavedPoint(93,0);
   getdNdpt16->SetSavedPoint(94,0);
   getdNdpt16->SetSavedPoint(95,0);
   getdNdpt16->SetSavedPoint(96,0);
   getdNdpt16->SetSavedPoint(97,0);
   getdNdpt16->SetSavedPoint(98,0);
   getdNdpt16->SetSavedPoint(99,0);
   getdNdpt16->SetSavedPoint(100,0);
   getdNdpt16->SetSavedPoint(101,1e-14);
   getdNdpt16->SetSavedPoint(102,100);
   getdNdpt16->SetFillColor(19);
   getdNdpt16->SetFillStyle(0);
   getdNdpt16->SetLineWidth(2);
   getdNdpt16->SetChisquare(0.2752052);
   getdNdpt16->SetNDF(6);
   getdNdpt16->SetParameter(0,0.49368);
   getdNdpt16->SetParError(0,0);
   getdNdpt16->SetParLimits(0,0.49368,0.49368);
   getdNdpt16->SetParameter(1,0.5);
   getdNdpt16->SetParError(1,0.3561697);
   getdNdpt16->SetParLimits(1,0.5,1);
   getdNdpt16->SetParameter(2,0.1203453);
   getdNdpt16->SetParError(2,0.001195094);
   getdNdpt16->SetParLimits(2,0,0);
   getdNdpt16->SetParameter(3,-0.2662805);
   getdNdpt16->SetParError(3,0.07410585);
   getdNdpt16->SetParLimits(3,0,0);
   getdNdpt16->SetParameter(4,30064.66);
   getdNdpt16->SetParError(4,1.370688);
   getdNdpt16->SetParLimits(4,0,0);
   getdNdpt16->SetParameter(5,0);
   getdNdpt16->SetParError(5,0);
   getdNdpt16->SetParLimits(5,1,1);
   getdNdpt16->SetParent(cent0_kapL_AupLAu_200__6);
   cent0_kapL_AupLAu_200__6->GetListOfFunctions()->Add(getdNdpt16);
   
   TF1 *getdNdpt217 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt217->SetRange(1e-14,100);
   getdNdpt217->SetName("getdNdpt2");
   getdNdpt217->SetTitle("getdNdpt2");
   getdNdpt217->SetSavedPoint(0,30.22012);
   getdNdpt217->SetSavedPoint(1,4.396533);
   getdNdpt217->SetSavedPoint(2,0.1049553);
   getdNdpt217->SetSavedPoint(3,0.001875684);
   getdNdpt217->SetSavedPoint(4,3.090506e-05);
   getdNdpt217->SetSavedPoint(5,4.927181e-07);
   getdNdpt217->SetSavedPoint(6,7.729909e-09);
   getdNdpt217->SetSavedPoint(7,1.202098e-10);
   getdNdpt217->SetSavedPoint(8,1.859904e-12);
   getdNdpt217->SetSavedPoint(9,2.868837e-14);
   getdNdpt217->SetSavedPoint(10,4.416784e-16);
   getdNdpt217->SetSavedPoint(11,6.792266e-18);
   getdNdpt217->SetSavedPoint(12,1.043855e-19);
   getdNdpt217->SetSavedPoint(13,1.603695e-21);
   getdNdpt217->SetSavedPoint(14,2.463504e-23);
   getdNdpt217->SetSavedPoint(15,3.784427e-25);
   getdNdpt217->SetSavedPoint(16,5.814431e-27);
   getdNdpt217->SetSavedPoint(17,8.935241e-29);
   getdNdpt217->SetSavedPoint(18,1.37347e-30);
   getdNdpt217->SetSavedPoint(19,2.111838e-32);
   getdNdpt217->SetSavedPoint(20,3.248188e-34);
   getdNdpt217->SetSavedPoint(21,4.997664e-36);
   getdNdpt217->SetSavedPoint(22,7.69205e-38);
   getdNdpt217->SetSavedPoint(23,1.184317e-39);
   getdNdpt217->SetSavedPoint(24,1.824087e-41);
   getdNdpt217->SetSavedPoint(25,2.810435e-43);
   getdNdpt217->SetSavedPoint(26,4.331623e-45);
   getdNdpt217->SetSavedPoint(27,6.678437e-47);
   getdNdpt217->SetSavedPoint(28,1.030015e-48);
   getdNdpt217->SetSavedPoint(29,1.58911e-50);
   getdNdpt217->SetSavedPoint(30,2.452468e-52);
   getdNdpt217->SetSavedPoint(31,3.786065e-54);
   getdNdpt217->SetSavedPoint(32,5.846625e-56);
   getdNdpt217->SetSavedPoint(33,9.031325e-58);
   getdNdpt217->SetSavedPoint(34,1.39548e-59);
   getdNdpt217->SetSavedPoint(35,2.156841e-61);
   getdNdpt217->SetSavedPoint(36,3.334512e-63);
   getdNdpt217->SetSavedPoint(37,5.15659e-65);
   getdNdpt217->SetSavedPoint(38,7.976386e-67);
   getdNdpt217->SetSavedPoint(39,1.234127e-68);
   getdNdpt217->SetSavedPoint(40,1.909945e-70);
   getdNdpt217->SetSavedPoint(41,2.956556e-72);
   getdNdpt217->SetSavedPoint(42,4.577759e-74);
   getdNdpt217->SetSavedPoint(43,7.089552e-76);
   getdNdpt217->SetSavedPoint(44,1.098199e-77);
   getdNdpt217->SetSavedPoint(45,1.701519e-79);
   getdNdpt217->SetSavedPoint(46,2.636842e-81);
   getdNdpt217->SetSavedPoint(47,4.087148e-83);
   getdNdpt217->SetSavedPoint(48,6.33641e-85);
   getdNdpt217->SetSavedPoint(49,9.82541e-87);
   getdNdpt217->SetSavedPoint(50,1.523844e-88);
   getdNdpt217->SetSavedPoint(51,2.363799e-90);
   getdNdpt217->SetSavedPoint(52,3.667404e-92);
   getdNdpt217->SetSavedPoint(53,5.690932e-94);
   getdNdpt217->SetSavedPoint(54,8.832477e-96);
   getdNdpt217->SetSavedPoint(55,1.371053e-97);
   getdNdpt217->SetSavedPoint(56,2.128614e-99);
   getdNdpt217->SetSavedPoint(57,3.305285e-101);
   getdNdpt217->SetSavedPoint(58,5.133203e-103);
   getdNdpt217->SetSavedPoint(59,7.973225e-105);
   getdNdpt217->SetSavedPoint(60,1.238637e-106);
   getdNdpt217->SetSavedPoint(61,1.924496e-108);
   getdNdpt217->SetSavedPoint(62,2.990555e-110);
   getdNdpt217->SetSavedPoint(63,4.647791e-112);
   getdNdpt217->SetSavedPoint(64,7.224376e-114);
   getdNdpt217->SetSavedPoint(65,1.123082e-115);
   getdNdpt217->SetSavedPoint(66,1.74614e-117);
   getdNdpt217->SetSavedPoint(67,2.7152e-119);
   getdNdpt217->SetSavedPoint(68,4.222585e-121);
   getdNdpt217->SetSavedPoint(69,6.567615e-123);
   getdNdpt217->SetSavedPoint(70,1.021618e-124);
   getdNdpt217->SetSavedPoint(71,1.589352e-126);
   getdNdpt217->SetSavedPoint(72,2.47287e-128);
   getdNdpt217->SetSavedPoint(73,3.847962e-130);
   getdNdpt217->SetSavedPoint(74,5.98836e-132);
   getdNdpt217->SetSavedPoint(75,9.320337e-134);
   getdNdpt217->SetSavedPoint(76,1.451283e-135);
   getdNdpt217->SetSavedPoint(77,4.527327e-139);
   getdNdpt217->SetSavedPoint(78,2.596859e-145);
   getdNdpt217->SetSavedPoint(79,4.105453e-152);
   getdNdpt217->SetSavedPoint(80,3.049221e-158);
   getdNdpt217->SetSavedPoint(81,3.404247e-170);
   getdNdpt217->SetSavedPoint(82,0);
   getdNdpt217->SetSavedPoint(83,0);
   getdNdpt217->SetSavedPoint(84,0);
   getdNdpt217->SetSavedPoint(85,0);
   getdNdpt217->SetSavedPoint(86,0);
   getdNdpt217->SetSavedPoint(87,0);
   getdNdpt217->SetSavedPoint(88,0);
   getdNdpt217->SetSavedPoint(89,0);
   getdNdpt217->SetSavedPoint(90,0);
   getdNdpt217->SetSavedPoint(91,0);
   getdNdpt217->SetSavedPoint(92,0);
   getdNdpt217->SetSavedPoint(93,0);
   getdNdpt217->SetSavedPoint(94,0);
   getdNdpt217->SetSavedPoint(95,0);
   getdNdpt217->SetSavedPoint(96,0);
   getdNdpt217->SetSavedPoint(97,0);
   getdNdpt217->SetSavedPoint(98,0);
   getdNdpt217->SetSavedPoint(99,0);
   getdNdpt217->SetSavedPoint(100,0);
   getdNdpt217->SetSavedPoint(101,1e-14);
   getdNdpt217->SetSavedPoint(102,100);
   getdNdpt217->SetFillColor(19);
   getdNdpt217->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt217->SetLineColor(ci);
   getdNdpt217->SetLineWidth(2);
   getdNdpt217->SetChisquare(0.2686431);
   getdNdpt217->SetNDF(6);
   getdNdpt217->SetParameter(0,0.49368);
   getdNdpt217->SetParError(0,0);
   getdNdpt217->SetParLimits(0,0.49368,0.49368);
   getdNdpt217->SetParameter(1,0.5712742);
   getdNdpt217->SetParError(1,0.1422409);
   getdNdpt217->SetParLimits(1,0.3,0.8);
   getdNdpt217->SetParameter(2,0.1257947);
   getdNdpt217->SetParError(2,0.03431721);
   getdNdpt217->SetParLimits(2,0.08,0.2);
   getdNdpt217->SetParameter(3,0.02760401);
   getdNdpt217->SetParError(3,3.598043);
   getdNdpt217->SetParLimits(3,0.01,5);
   getdNdpt217->SetParameter(4,22913.94);
   getdNdpt217->SetParError(4,35319.35);
   getdNdpt217->SetParLimits(4,0,0);
   getdNdpt217->SetParameter(5,0);
   getdNdpt217->SetParError(5,0);
   getdNdpt217->SetParLimits(5,1,1);
   getdNdpt217->SetParent(cent0_kapL_AupLAu_200__6);
   cent0_kapL_AupLAu_200__6->GetListOfFunctions()->Add(getdNdpt217);
   
   TF1 *getdNdptHAGE18 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE18->SetRange(1e-12,100);
   getdNdptHAGE18->SetName("getdNdptHAGE");
   getdNdptHAGE18->SetTitle("getdNdptHAGE");
   getdNdptHAGE18->SetSavedPoint(0,36.97747);
   getdNdptHAGE18->SetSavedPoint(1,5.033458);
   getdNdptHAGE18->SetSavedPoint(2,0.5328836);
   getdNdptHAGE18->SetSavedPoint(3,0.07863445);
   getdNdptHAGE18->SetSavedPoint(4,0.01467787);
   getdNdptHAGE18->SetSavedPoint(5,0.003265601);
   getdNdptHAGE18->SetSavedPoint(6,0.0008343651);
   getdNdptHAGE18->SetSavedPoint(7,0.00023868);
   getdNdptHAGE18->SetSavedPoint(8,7.504799e-05);
   getdNdptHAGE18->SetSavedPoint(9,2.557759e-05);
   getdNdptHAGE18->SetSavedPoint(10,9.346176e-06);
   getdNdptHAGE18->SetSavedPoint(11,3.629637e-06);
   getdNdptHAGE18->SetSavedPoint(12,1.487465e-06);
   getdNdptHAGE18->SetSavedPoint(13,6.394623e-07);
   getdNdptHAGE18->SetSavedPoint(14,2.869528e-07);
   getdNdptHAGE18->SetSavedPoint(15,1.338451e-07);
   getdNdptHAGE18->SetSavedPoint(16,6.465795e-08);
   getdNdptHAGE18->SetSavedPoint(17,3.224882e-08);
   getdNdptHAGE18->SetSavedPoint(18,1.656145e-08);
   getdNdptHAGE18->SetSavedPoint(19,8.73659e-09);
   getdNdptHAGE18->SetSavedPoint(20,4.724261e-09);
   getdNdptHAGE18->SetSavedPoint(21,2.613767e-09);
   getdNdptHAGE18->SetSavedPoint(22,1.477142e-09);
   getdNdptHAGE18->SetSavedPoint(23,8.514463e-10);
   getdNdptHAGE18->SetSavedPoint(24,4.999128e-10);
   getdNdptHAGE18->SetSavedPoint(25,2.986157e-10);
   getdNdptHAGE18->SetSavedPoint(26,1.812763e-10);
   getdNdptHAGE18->SetSavedPoint(27,1.117254e-10);
   getdNdptHAGE18->SetSavedPoint(28,6.984824e-11);
   getdNdptHAGE18->SetSavedPoint(29,4.425843e-11);
   getdNdptHAGE18->SetSavedPoint(30,2.840191e-11);
   getdNdptHAGE18->SetSavedPoint(31,1.844637e-11);
   getdNdptHAGE18->SetSavedPoint(32,1.211743e-11);
   getdNdptHAGE18->SetSavedPoint(33,8.046228e-12);
   getdNdptHAGE18->SetSavedPoint(34,5.397859e-12);
   getdNdptHAGE18->SetSavedPoint(35,3.656626e-12);
   getdNdptHAGE18->SetSavedPoint(36,2.500157e-12);
   getdNdptHAGE18->SetSavedPoint(37,1.724623e-12);
   getdNdptHAGE18->SetSavedPoint(38,1.199737e-12);
   getdNdptHAGE18->SetSavedPoint(39,8.413557e-13);
   getdNdptHAGE18->SetSavedPoint(40,5.945968e-13);
   getdNdptHAGE18->SetSavedPoint(41,4.233233e-13);
   getdNdptHAGE18->SetSavedPoint(42,3.03525e-13);
   getdNdptHAGE18->SetSavedPoint(43,2.191108e-13);
   getdNdptHAGE18->SetSavedPoint(44,1.592071e-13);
   getdNdptHAGE18->SetSavedPoint(45,1.16407e-13);
   getdNdptHAGE18->SetSavedPoint(46,8.562673e-14);
   getdNdptHAGE18->SetSavedPoint(47,6.335111e-14);
   getdNdptHAGE18->SetSavedPoint(48,4.713252e-14);
   getdNdptHAGE18->SetSavedPoint(49,3.525499e-14);
   getdNdptHAGE18->SetSavedPoint(50,2.650761e-14);
   getdNdptHAGE18->SetSavedPoint(51,2.003049e-14);
   getdNdptHAGE18->SetSavedPoint(52,1.520928e-14);
   getdNdptHAGE18->SetSavedPoint(53,1.160249e-14);
   getdNdptHAGE18->SetSavedPoint(54,8.891009e-15);
   getdNdptHAGE18->SetSavedPoint(55,6.842966e-15);
   getdNdptHAGE18->SetSavedPoint(56,5.288957e-15);
   getdNdptHAGE18->SetSavedPoint(57,4.10459e-15);
   getdNdptHAGE18->SetSavedPoint(58,3.198072e-15);
   getdNdptHAGE18->SetSavedPoint(59,2.501339e-15);
   getdNdptHAGE18->SetSavedPoint(60,1.963687e-15);
   getdNdptHAGE18->SetSavedPoint(61,1.547174e-15);
   getdNdptHAGE18->SetSavedPoint(62,1.223283e-15);
   getdNdptHAGE18->SetSavedPoint(63,9.704914e-16);
   getdNdptHAGE18->SetSavedPoint(64,7.724872e-16);
   getdNdptHAGE18->SetSavedPoint(65,6.168581e-16);
   getdNdptHAGE18->SetSavedPoint(66,4.941228e-16);
   getdNdptHAGE18->SetSavedPoint(67,3.970115e-16);
   getdNdptHAGE18->SetSavedPoint(68,3.199294e-16);
   getdNdptHAGE18->SetSavedPoint(69,2.585556e-16);
   getdNdptHAGE18->SetSavedPoint(70,2.095413e-16);
   getdNdptHAGE18->SetSavedPoint(71,1.702823e-16);
   getdNdptHAGE18->SetSavedPoint(72,1.387469e-16);
   getdNdptHAGE18->SetSavedPoint(73,1.133449e-16);
   getdNdptHAGE18->SetSavedPoint(74,9.282762e-17);
   getdNdptHAGE18->SetSavedPoint(75,7.621176e-17);
   getdNdptHAGE18->SetSavedPoint(76,6.272062e-17);
   getdNdptHAGE18->SetSavedPoint(77,5.173887e-17);
   getdNdptHAGE18->SetSavedPoint(78,4.277773e-17);
   getdNdptHAGE18->SetSavedPoint(79,3.54478e-17);
   getdNdptHAGE18->SetSavedPoint(80,2.943805e-17);
   getdNdptHAGE18->SetSavedPoint(81,2.449939e-17);
   getdNdptHAGE18->SetSavedPoint(82,2.04318e-17);
   getdNdptHAGE18->SetSavedPoint(83,1.707431e-17);
   getdNdptHAGE18->SetSavedPoint(84,1.429701e-17);
   getdNdptHAGE18->SetSavedPoint(85,1.199481e-17);
   getdNdptHAGE18->SetSavedPoint(86,1.008253e-17);
   getdNdptHAGE18->SetSavedPoint(87,8.490945e-18);
   getdNdptHAGE18->SetSavedPoint(88,7.163668e-18);
   getdNdptHAGE18->SetSavedPoint(89,6.054678e-18);
   getdNdptHAGE18->SetSavedPoint(90,5.126333e-18);
   getdNdptHAGE18->SetSavedPoint(91,4.347775e-18);
   getdNdptHAGE18->SetSavedPoint(92,3.693657e-18);
   getdNdptHAGE18->SetSavedPoint(93,3.143117e-18);
   getdNdptHAGE18->SetSavedPoint(94,2.678951e-18);
   getdNdptHAGE18->SetSavedPoint(95,2.286944e-18);
   getdNdptHAGE18->SetSavedPoint(96,1.955326e-18);
   getdNdptHAGE18->SetSavedPoint(97,1.674336e-18);
   getdNdptHAGE18->SetSavedPoint(98,1.435864e-18);
   getdNdptHAGE18->SetSavedPoint(99,1.233159e-18);
   getdNdptHAGE18->SetSavedPoint(100,1.06059e-18);
   getdNdptHAGE18->SetSavedPoint(101,1e-12);
   getdNdptHAGE18->SetSavedPoint(102,100);
   getdNdptHAGE18->SetFillColor(19);
   getdNdptHAGE18->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE18->SetLineColor(ci);
   getdNdptHAGE18->SetLineWidth(2);
   getdNdptHAGE18->SetChisquare(6.146697);
   getdNdptHAGE18->SetNDF(7);
   getdNdptHAGE18->SetParameter(0,0.49368);
   getdNdptHAGE18->SetParError(0,0);
   getdNdptHAGE18->SetParLimits(0,0.49368,0.49368);
   getdNdptHAGE18->SetParameter(1,2.111071);
   getdNdptHAGE18->SetParError(1,0.02317441);
   getdNdptHAGE18->SetParLimits(1,0,0);
   getdNdptHAGE18->SetParameter(2,50);
   getdNdptHAGE18->SetParError(2,1.900893);
   getdNdptHAGE18->SetParLimits(2,50,200);
   getdNdptHAGE18->SetParameter(3,15);
   getdNdptHAGE18->SetParError(3,7.10917);
   getdNdptHAGE18->SetParLimits(3,5,15);
   getdNdptHAGE18->SetParameter(4,0);
   getdNdptHAGE18->SetParError(4,0);
   getdNdptHAGE18->SetParLimits(4,1,1);
   getdNdptHAGE18->SetParent(cent0_kapL_AupLAu_200__6);
   cent0_kapL_AupLAu_200__6->GetListOfFunctions()->Add(getdNdptHAGE18);

   ci = TColor::GetColor("#000099");
   cent0_kapL_AupLAu_200__6->SetLineColor(ci);
   cent0_kapL_AupLAu_200__6->SetMarkerStyle(20);
   cent0_kapL_AupLAu_200__6->GetXaxis()->SetRange(0,11);
   cent0_kapL_AupLAu_200__6->GetXaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_200__6->GetXaxis()->SetLabelSize(0.1);
   cent0_kapL_AupLAu_200__6->GetXaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_200__6->GetXaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_200__6->GetYaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_200__6->GetYaxis()->SetLabelSize(0.1);
   cent0_kapL_AupLAu_200__6->GetYaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_200__6->GetYaxis()->SetTitleOffset(0);
   cent0_kapL_AupLAu_200__6->GetYaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_200__6->GetZaxis()->SetLabelFont(42);
   cent0_kapL_AupLAu_200__6->GetZaxis()->SetLabelSize(0.035);
   cent0_kapL_AupLAu_200__6->GetZaxis()->SetTitleSize(0.035);
   cent0_kapL_AupLAu_200__6->GetZaxis()->SetTitleFont(42);
   cent0_kapL_AupLAu_200__6->Draw("");
      tex = new TLatex(0.1,5,"k^{+}  200 GeV");
   tex->SetTextSize(0.1);
   tex->SetLineWidth(2);
   tex->Draw();
   part6->Modified();
   c->cd();
  
// ------------>Primitives in pad: part7
   TPad *part7 = new TPad("part7", "part7",0,0,0.3733333,0.4133334);
   part7->Draw();
   part7->cd();
   part7->Range(-0.3041844,-0.3783679,1.63,1.205068);
   part7->SetFillColor(0);
   part7->SetBorderMode(0);
   part7->SetBorderSize(0);
   part7->SetLogy();
   part7->SetLeftMargin(0.1607143);
   part7->SetRightMargin(0);
   part7->SetTopMargin(0);
   part7->SetBottomMargin(0.2903226);
   part7->SetFrameBorderMode(0);
   part7->SetFrameBorderMode(0);
   Double_t xAxis7[16] = {0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.78, 0.82, 0.88, 0.93, 0.97, 1.02, 1.07, 1.12, 1.25}; 
   
   TH1D *cent0_proton_AupLAu_62dO4__7 = new TH1D("cent0_proton_AupLAu_62dO4__7","cent0_proton_Au+Au_62.4",15, xAxis7);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(1,6.4738);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(2,6.5029);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(3,6.4428);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(4,6.3758);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(5,6.0897);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(6,5.8399);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(7,5.4859);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(8,5.107);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(9,4.8046);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(10,4.2923);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(11,3.9044);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(12,3.6015);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(13,3.2748);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(14,2.9964);
   cent0_proton_AupLAu_62dO4__7->SetBinContent(15,2.6937);
   cent0_proton_AupLAu_62dO4__7->SetBinError(1,0.06713);
   cent0_proton_AupLAu_62dO4__7->SetBinError(2,0.06778);
   cent0_proton_AupLAu_62dO4__7->SetBinError(3,0.06741);
   cent0_proton_AupLAu_62dO4__7->SetBinError(4,0.06687);
   cent0_proton_AupLAu_62dO4__7->SetBinError(5,0.12343);
   cent0_proton_AupLAu_62dO4__7->SetBinError(6,0.11845);
   cent0_proton_AupLAu_62dO4__7->SetBinError(7,0.11137);
   cent0_proton_AupLAu_62dO4__7->SetBinError(8,0.10381);
   cent0_proton_AupLAu_62dO4__7->SetBinError(9,0.09777);
   cent0_proton_AupLAu_62dO4__7->SetBinError(10,0.12978);
   cent0_proton_AupLAu_62dO4__7->SetBinError(11,0.11827);
   cent0_proton_AupLAu_62dO4__7->SetBinError(12,0.10941);
   cent0_proton_AupLAu_62dO4__7->SetBinError(13,0.09934);
   cent0_proton_AupLAu_62dO4__7->SetBinError(14,0.12066);
   cent0_proton_AupLAu_62dO4__7->SetBinError(15,0.10915);
   cent0_proton_AupLAu_62dO4__7->SetEntries(15);
   
   TF1 *getdNdpt19 = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt19->SetRange(1e-14,100);
   getdNdpt19->SetName("getdNdpt");
   getdNdpt19->SetTitle("getdNdpt");
   getdNdpt19->SetSavedPoint(0,5.374045);
   getdNdpt19->SetSavedPoint(1,3.662305);
   getdNdpt19->SetSavedPoint(2,0.1929752);
   getdNdpt19->SetSavedPoint(3,0.004356293);
   getdNdpt19->SetSavedPoint(4,7.433783e-05);
   getdNdpt19->SetSavedPoint(5,1.125603e-06);
   getdNdpt19->SetSavedPoint(6,1.60494e-08);
   getdNdpt19->SetSavedPoint(7,2.212921e-10);
   getdNdpt19->SetSavedPoint(8,2.990584e-12);
   getdNdpt19->SetSavedPoint(9,3.99091e-14);
   getdNdpt19->SetSavedPoint(10,5.282448e-16);
   getdNdpt19->SetSavedPoint(11,6.954135e-18);
   getdNdpt19->SetSavedPoint(12,9.121607e-20);
   getdNdpt19->SetSavedPoint(13,1.193544e-21);
   getdNdpt19->SetSavedPoint(14,1.559193e-23);
   getdNdpt19->SetSavedPoint(15,2.034717e-25);
   getdNdpt19->SetSavedPoint(16,2.653548e-27);
   getdNdpt19->SetSavedPoint(17,3.459358e-29);
   getdNdpt19->SetSavedPoint(18,4.509218e-31);
   getdNdpt19->SetSavedPoint(19,5.87775e-33);
   getdNdpt19->SetSavedPoint(20,7.662564e-35);
   getdNdpt19->SetSavedPoint(21,9.991387e-37);
   getdNdpt19->SetSavedPoint(22,1.303143e-38);
   getdNdpt19->SetSavedPoint(23,1.700166e-40);
   getdNdpt19->SetSavedPoint(24,2.218896e-42);
   getdNdpt19->SetSavedPoint(25,2.896928e-44);
   getdNdpt19->SetSavedPoint(26,3.783548e-46);
   getdNdpt19->SetSavedPoint(27,4.943393e-48);
   getdNdpt19->SetSavedPoint(28,6.461254e-50);
   getdNdpt19->SetSavedPoint(29,8.448401e-52);
   getdNdpt19->SetSavedPoint(30,1.105089e-53);
   getdNdpt19->SetSavedPoint(31,1.44605e-55);
   getdNdpt19->SetSavedPoint(32,1.892912e-57);
   getdNdpt19->SetSavedPoint(33,2.478768e-59);
   getdNdpt19->SetSavedPoint(34,3.247108e-61);
   getdNdpt19->SetSavedPoint(35,4.255096e-63);
   getdNdpt19->SetSavedPoint(36,5.577899e-65);
   getdNdpt19->SetSavedPoint(37,7.31437e-67);
   getdNdpt19->SetSavedPoint(38,9.594551e-69);
   getdNdpt19->SetSavedPoint(39,1.258955e-70);
   getdNdpt19->SetSavedPoint(40,1.652457e-72);
   getdNdpt19->SetSavedPoint(41,2.169606e-74);
   getdNdpt19->SetSavedPoint(42,2.849436e-76);
   getdNdpt19->SetSavedPoint(43,3.743353e-78);
   getdNdpt19->SetSavedPoint(44,4.919073e-80);
   getdNdpt19->SetSavedPoint(45,6.465813e-82);
   getdNdpt19->SetSavedPoint(46,8.501138e-84);
   getdNdpt19->SetSavedPoint(47,1.118001e-85);
   getdNdpt19->SetSavedPoint(48,1.47067e-87);
   getdNdpt19->SetSavedPoint(49,1.935056e-89);
   getdNdpt19->SetSavedPoint(50,2.54668e-91);
   getdNdpt19->SetSavedPoint(51,3.352392e-93);
   getdNdpt19->SetSavedPoint(52,4.413999e-95);
   getdNdpt19->SetSavedPoint(53,5.813051e-97);
   getdNdpt19->SetSavedPoint(54,7.657166e-99);
   getdNdpt19->SetSavedPoint(55,1.008839e-100);
   getdNdpt19->SetSavedPoint(56,1.329421e-102);
   getdNdpt19->SetSavedPoint(57,1.75222e-104);
   getdNdpt19->SetSavedPoint(58,2.309924e-106);
   getdNdpt19->SetSavedPoint(59,3.045704e-108);
   getdNdpt19->SetSavedPoint(60,4.016581e-110);
   getdNdpt19->SetSavedPoint(61,5.297883e-112);
   getdNdpt19->SetSavedPoint(62,6.989131e-114);
   getdNdpt19->SetSavedPoint(63,9.221834e-116);
   getdNdpt19->SetSavedPoint(64,1.216979e-117);
   getdNdpt19->SetSavedPoint(65,1.606269e-119);
   getdNdpt19->SetSavedPoint(66,2.12042e-121);
   getdNdpt19->SetSavedPoint(67,2.799575e-123);
   getdNdpt19->SetSavedPoint(68,3.696812e-125);
   getdNdpt19->SetSavedPoint(69,4.882318e-127);
   getdNdpt19->SetSavedPoint(70,6.448919e-129);
   getdNdpt19->SetSavedPoint(71,8.519391e-131);
   getdNdpt19->SetSavedPoint(72,1.125614e-132);
   getdNdpt19->SetSavedPoint(73,1.487227e-134);
   getdNdpt19->SetSavedPoint(74,3.164551e-137);
   getdNdpt19->SetSavedPoint(75,3.726692e-143);
   getdNdpt19->SetSavedPoint(76,2.310069e-149);
   getdNdpt19->SetSavedPoint(77,4.6807e-156);
   getdNdpt19->SetSavedPoint(78,1.352322e-161);
   getdNdpt19->SetSavedPoint(79,5.243042e-169);
   getdNdpt19->SetSavedPoint(80,1.722049e-179);
   getdNdpt19->SetSavedPoint(81,1.480009e-188);
   getdNdpt19->SetSavedPoint(82,1.433119e-202);
   getdNdpt19->SetSavedPoint(83,5.099434e-205);
   getdNdpt19->SetSavedPoint(84,0);
   getdNdpt19->SetSavedPoint(85,0);
   getdNdpt19->SetSavedPoint(86,0);
   getdNdpt19->SetSavedPoint(87,0);
   getdNdpt19->SetSavedPoint(88,0);
   getdNdpt19->SetSavedPoint(89,0);
   getdNdpt19->SetSavedPoint(90,0);
   getdNdpt19->SetSavedPoint(91,0);
   getdNdpt19->SetSavedPoint(92,0);
   getdNdpt19->SetSavedPoint(93,0);
   getdNdpt19->SetSavedPoint(94,0);
   getdNdpt19->SetSavedPoint(95,0);
   getdNdpt19->SetSavedPoint(96,0);
   getdNdpt19->SetSavedPoint(97,0);
   getdNdpt19->SetSavedPoint(98,0);
   getdNdpt19->SetSavedPoint(99,0);
   getdNdpt19->SetSavedPoint(100,0);
   getdNdpt19->SetSavedPoint(101,1e-14);
   getdNdpt19->SetSavedPoint(102,100);
   getdNdpt19->SetFillColor(19);
   getdNdpt19->SetFillStyle(0);
   getdNdpt19->SetLineWidth(2);
   getdNdpt19->SetChisquare(11.68594);
   getdNdpt19->SetNDF(11);
   getdNdpt19->SetParameter(0,0.93827);
   getdNdpt19->SetParError(0,0);
   getdNdpt19->SetParLimits(0,0.93827,0.93827);
   getdNdpt19->SetParameter(1,0.5710731);
   getdNdpt19->SetParError(1,0.3905477);
   getdNdpt19->SetParLimits(1,0.5,1);
   getdNdpt19->SetParameter(2,0.1210957);
   getdNdpt19->SetParError(2,0.01495506);
   getdNdpt19->SetParLimits(2,0,0);
   getdNdpt19->SetParameter(3,0.06589194);
   getdNdpt19->SetParError(3,0.7507428);
   getdNdpt19->SetParLimits(3,0,0);
   getdNdpt19->SetParameter(4,291684.6);
   getdNdpt19->SetParError(4,333872.7);
   getdNdpt19->SetParLimits(4,0,0);
   getdNdpt19->SetParameter(5,-1);
   getdNdpt19->SetParError(5,0);
   getdNdpt19->SetParLimits(5,-1,-1);
   getdNdpt19->SetParent(cent0_proton_AupLAu_62dO4__7);
   cent0_proton_AupLAu_62dO4__7->GetListOfFunctions()->Add(getdNdpt19);
   
   TF1 *getdNdpt220 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt220->SetRange(1e-14,100);
   getdNdpt220->SetName("getdNdpt2");
   getdNdpt220->SetTitle("getdNdpt2");
   getdNdpt220->SetSavedPoint(0,5.374014);
   getdNdpt220->SetSavedPoint(1,3.662287);
   getdNdpt220->SetSavedPoint(2,0.1929715);
   getdNdpt220->SetSavedPoint(3,0.004356945);
   getdNdpt220->SetSavedPoint(4,7.437827e-05);
   getdNdpt220->SetSavedPoint(5,1.126887e-06);
   getdNdpt220->SetSavedPoint(6,1.608003e-08);
   getdNdpt220->SetSavedPoint(7,2.219163e-10);
   getdNdpt220->SetSavedPoint(8,3.002104e-12);
   getdNdpt220->SetSavedPoint(9,4.010806e-14);
   getdNdpt220->SetSavedPoint(10,5.315224e-16);
   getdNdpt220->SetSavedPoint(11,7.006273e-18);
   getdNdpt220->SetSavedPoint(12,9.202369e-20);
   getdNdpt220->SetSavedPoint(13,1.205797e-21);
   getdNdpt220->SetSavedPoint(14,1.577477e-23);
   getdNdpt220->SetSavedPoint(15,2.061635e-25);
   getdNdpt220->SetSavedPoint(16,2.692742e-27);
   getdNdpt220->SetSavedPoint(17,3.515902e-29);
   getdNdpt220->SetSavedPoint(18,4.590162e-31);
   getdNdpt220->SetSavedPoint(19,5.99286e-33);
   getdNdpt220->SetSavedPoint(20,7.825332e-35);
   getdNdpt220->SetSavedPoint(21,1.022042e-36);
   getdNdpt220->SetSavedPoint(22,1.335232e-38);
   getdNdpt220->SetSavedPoint(23,1.744959e-40);
   getdNdpt220->SetSavedPoint(24,2.281213e-42);
   getdNdpt220->SetSavedPoint(25,2.983373e-44);
   getdNdpt220->SetSavedPoint(26,3.903151e-46);
   getdNdpt220->SetSavedPoint(27,5.108486e-48);
   getdNdpt220->SetSavedPoint(28,6.688662e-50);
   getdNdpt220->SetSavedPoint(29,8.761052e-52);
   getdNdpt220->SetSavedPoint(30,1.148001e-53);
   getdNdpt220->SetSavedPoint(31,1.504855e-55);
   getdNdpt220->SetSavedPoint(32,1.973384e-57);
   getdNdpt220->SetSavedPoint(33,2.588748e-59);
   getdNdpt220->SetSavedPoint(34,3.397237e-61);
   getdNdpt220->SetSavedPoint(35,4.459811e-63);
   getdNdpt220->SetSavedPoint(36,5.856768e-65);
   getdNdpt220->SetSavedPoint(37,7.693904e-67);
   getdNdpt220->SetSavedPoint(38,1.011065e-68);
   getdNdpt220->SetSavedPoint(39,1.32908e-70);
   getdNdpt220->SetSavedPoint(40,1.74767e-72);
   getdNdpt220->SetSavedPoint(41,2.298794e-74);
   getdNdpt220->SetSavedPoint(42,3.024612e-76);
   getdNdpt220->SetSavedPoint(43,3.980748e-78);
   getdNdpt220->SetSavedPoint(44,5.240609e-80);
   getdNdpt220->SetSavedPoint(45,6.901085e-82);
   getdNdpt220->SetSavedPoint(46,9.090096e-84);
   getdNdpt220->SetSavedPoint(47,1.197655e-85);
   getdNdpt220->SetSavedPoint(48,1.578354e-87);
   getdNdpt220->SetSavedPoint(49,2.080575e-89);
   getdNdpt220->SetSavedPoint(50,2.743251e-91);
   getdNdpt220->SetSavedPoint(51,3.617832e-93);
   getdNdpt220->SetSavedPoint(52,4.772317e-95);
   getdNdpt220->SetSavedPoint(53,6.29659e-97);
   getdNdpt220->SetSavedPoint(54,8.309492e-99);
   getdNdpt220->SetSavedPoint(55,1.096817e-100);
   getdNdpt220->SetSavedPoint(56,1.448043e-102);
   getdNdpt220->SetSavedPoint(57,1.912119e-104);
   getdNdpt220->SetSavedPoint(58,2.525411e-106);
   getdNdpt220->SetSavedPoint(59,3.336036e-108);
   getdNdpt220->SetSavedPoint(60,4.407667e-110);
   getdNdpt220->SetSavedPoint(61,5.824578e-112);
   getdNdpt220->SetSavedPoint(62,7.698317e-114);
   getdNdpt220->SetSavedPoint(63,1.017656e-115);
   getdNdpt220->SetSavedPoint(64,1.345483e-117);
   getdNdpt220->SetSavedPoint(65,1.779203e-119);
   getdNdpt220->SetSavedPoint(66,2.353107e-121);
   getdNdpt220->SetSavedPoint(67,3.11261e-123);
   getdNdpt220->SetSavedPoint(68,4.117877e-125);
   getdNdpt220->SetSavedPoint(69,5.448613e-127);
   getdNdpt220->SetSavedPoint(70,7.210429e-129);
   getdNdpt220->SetSavedPoint(71,9.543273e-131);
   getdNdpt220->SetSavedPoint(72,1.263262e-132);
   getdNdpt220->SetSavedPoint(73,1.672881e-134);
   getdNdpt220->SetSavedPoint(74,1.45917e-137);
   getdNdpt220->SetSavedPoint(75,3.535402e-143);
   getdNdpt220->SetSavedPoint(76,1.873284e-149);
   getdNdpt220->SetSavedPoint(77,2.46973e-156);
   getdNdpt220->SetSavedPoint(78,4.998695e-162);
   getdNdpt220->SetSavedPoint(79,1.720871e-169);
   getdNdpt220->SetSavedPoint(80,4.157299e-180);
   getdNdpt220->SetSavedPoint(81,2.671158e-189);
   getdNdpt220->SetSavedPoint(82,1.438465e-191);
   getdNdpt220->SetSavedPoint(83,5.788433e-206);
   getdNdpt220->SetSavedPoint(84,0);
   getdNdpt220->SetSavedPoint(85,0);
   getdNdpt220->SetSavedPoint(86,0);
   getdNdpt220->SetSavedPoint(87,0);
   getdNdpt220->SetSavedPoint(88,0);
   getdNdpt220->SetSavedPoint(89,0);
   getdNdpt220->SetSavedPoint(90,0);
   getdNdpt220->SetSavedPoint(91,0);
   getdNdpt220->SetSavedPoint(92,0);
   getdNdpt220->SetSavedPoint(93,0);
   getdNdpt220->SetSavedPoint(94,0);
   getdNdpt220->SetSavedPoint(95,0);
   getdNdpt220->SetSavedPoint(96,0);
   getdNdpt220->SetSavedPoint(97,0);
   getdNdpt220->SetSavedPoint(98,0);
   getdNdpt220->SetSavedPoint(99,0);
   getdNdpt220->SetSavedPoint(100,0);
   getdNdpt220->SetSavedPoint(101,1e-14);
   getdNdpt220->SetSavedPoint(102,100);
   getdNdpt220->SetFillColor(19);
   getdNdpt220->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt220->SetLineColor(ci);
   getdNdpt220->SetLineWidth(2);
   getdNdpt220->SetChisquare(11.68595);
   getdNdpt220->SetNDF(11);
   getdNdpt220->SetParameter(0,0.93827);
   getdNdpt220->SetParError(0,0);
   getdNdpt220->SetParLimits(0,0.93827,0.93827);
   getdNdpt220->SetParameter(1,0.5715449);
   getdNdpt220->SetParError(1,0.1501155);
   getdNdpt220->SetParLimits(1,0.3,0.8);
   getdNdpt220->SetParameter(2,0.1210645);
   getdNdpt220->SetParError(2,0.01073297);
   getdNdpt220->SetParLimits(2,0.08,0.2);
   getdNdpt220->SetParameter(3,0.0675597);
   getdNdpt220->SetParError(3,3.361016);
   getdNdpt220->SetParLimits(3,0.01,5);
   getdNdpt220->SetParameter(4,292385);
   getdNdpt220->SetParError(4,241804.9);
   getdNdpt220->SetParLimits(4,0,0);
   getdNdpt220->SetParameter(5,-1);
   getdNdpt220->SetParError(5,0);
   getdNdpt220->SetParLimits(5,-1,-1);
   getdNdpt220->SetParent(cent0_proton_AupLAu_62dO4__7);
   cent0_proton_AupLAu_62dO4__7->GetListOfFunctions()->Add(getdNdpt220);
   
   TF1 *getdNdptHAGE21 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE21->SetRange(1e-12,100);
   getdNdptHAGE21->SetName("getdNdptHAGE");
   getdNdptHAGE21->SetTitle("getdNdptHAGE");
   getdNdptHAGE21->SetSavedPoint(0,8.489182);
   getdNdptHAGE21->SetSavedPoint(1,3.79693);
   getdNdptHAGE21->SetSavedPoint(2,1.035189);
   getdNdptHAGE21->SetSavedPoint(3,0.2907399);
   getdNdptHAGE21->SetSavedPoint(4,0.08621379);
   getdNdptHAGE21->SetSavedPoint(5,0.02663363);
   getdNdptHAGE21->SetSavedPoint(6,0.008476284);
   getdNdptHAGE21->SetSavedPoint(7,0.002758067);
   getdNdptHAGE21->SetSavedPoint(8,0.0009128368);
   getdNdptHAGE21->SetSavedPoint(9,0.0003062041);
   getdNdptHAGE21->SetSavedPoint(10,0.0001038332);
   getdNdptHAGE21->SetSavedPoint(11,3.55253e-05);
   getdNdptHAGE21->SetSavedPoint(12,1.224571e-05);
   getdNdptHAGE21->SetSavedPoint(13,4.248005e-06);
   getdNdptHAGE21->SetSavedPoint(14,1.481676e-06);
   getdNdptHAGE21->SetSavedPoint(15,5.192502e-07);
   getdNdptHAGE21->SetSavedPoint(16,1.827264e-07);
   getdNdptHAGE21->SetSavedPoint(17,6.453826e-08);
   getdNdptHAGE21->SetSavedPoint(18,2.286909e-08);
   getdNdptHAGE21->SetSavedPoint(19,8.127336e-09);
   getdNdptHAGE21->SetSavedPoint(20,2.895938e-09);
   getdNdptHAGE21->SetSavedPoint(21,1.034341e-09);
   getdNdptHAGE21->SetSavedPoint(22,3.702355e-10);
   getdNdptHAGE21->SetSavedPoint(23,1.327856e-10);
   getdNdptHAGE21->SetSavedPoint(24,4.771019e-11);
   getdNdptHAGE21->SetSavedPoint(25,1.717101e-11);
   getdNdptHAGE21->SetSavedPoint(26,6.189412e-12);
   getdNdptHAGE21->SetSavedPoint(27,2.234202e-12);
   getdNdptHAGE21->SetSavedPoint(28,8.075528e-13);
   getdNdptHAGE21->SetSavedPoint(29,2.922504e-13);
   getdNdptHAGE21->SetSavedPoint(30,1.058862e-13);
   getdNdptHAGE21->SetSavedPoint(31,3.840536e-14);
   getdNdptHAGE21->SetSavedPoint(32,1.394386e-14);
   getdNdptHAGE21->SetSavedPoint(33,5.067412e-15);
   getdNdptHAGE21->SetSavedPoint(34,1.843221e-15);
   getdNdptHAGE21->SetSavedPoint(35,6.710188e-16);
   getdNdptHAGE21->SetSavedPoint(36,2.444767e-16);
   getdNdptHAGE21->SetSavedPoint(37,8.913889e-17);
   getdNdptHAGE21->SetSavedPoint(38,3.252421e-17);
   getdNdptHAGE21->SetSavedPoint(39,1.187518e-17);
   getdNdptHAGE21->SetSavedPoint(40,4.338632e-18);
   getdNdptHAGE21->SetSavedPoint(41,1.586102e-18);
   getdNdptHAGE21->SetSavedPoint(42,5.801796e-19);
   getdNdptHAGE21->SetSavedPoint(43,2.123416e-19);
   getdNdptHAGE21->SetSavedPoint(44,7.775672e-20);
   getdNdptHAGE21->SetSavedPoint(45,2.848794e-20);
   getdNdptHAGE21->SetSavedPoint(46,1.044226e-20);
   getdNdptHAGE21->SetSavedPoint(47,3.829392e-21);
   getdNdptHAGE21->SetSavedPoint(48,1.404942e-21);
   getdNdptHAGE21->SetSavedPoint(49,5.156703e-22);
   getdNdptHAGE21->SetSavedPoint(50,1.893494e-22);
   getdNdptHAGE21->SetSavedPoint(51,6.955474e-23);
   getdNdptHAGE21->SetSavedPoint(52,2.555959e-23);
   getdNdptHAGE21->SetSavedPoint(53,9.395923e-24);
   getdNdptHAGE21->SetSavedPoint(54,3.455233e-24);
   getdNdptHAGE21->SetSavedPoint(55,1.271049e-24);
   getdNdptHAGE21->SetSavedPoint(56,4.677229e-25);
   getdNdptHAGE21->SetSavedPoint(57,1.721677e-25);
   getdNdptHAGE21->SetSavedPoint(58,6.339382e-26);
   getdNdptHAGE21->SetSavedPoint(59,2.334907e-26);
   getdNdptHAGE21->SetSavedPoint(60,8.60232e-27);
   getdNdptHAGE21->SetSavedPoint(61,3.170157e-27);
   getdNdptHAGE21->SetSavedPoint(62,1.168588e-27);
   getdNdptHAGE21->SetSavedPoint(63,4.308776e-28);
   getdNdptHAGE21->SetSavedPoint(64,1.589113e-28);
   getdNdptHAGE21->SetSavedPoint(65,5.862198e-29);
   getdNdptHAGE21->SetSavedPoint(66,2.163057e-29);
   getdNdptHAGE21->SetSavedPoint(67,7.983152e-30);
   getdNdptHAGE21->SetSavedPoint(68,2.946976e-30);
   getdNdptHAGE21->SetSavedPoint(69,1.088108e-30);
   getdNdptHAGE21->SetSavedPoint(70,4.018443e-31);
   getdNdptHAGE21->SetSavedPoint(71,1.484334e-31);
   getdNdptHAGE21->SetSavedPoint(72,5.483917e-32);
   getdNdptHAGE21->SetSavedPoint(73,2.026438e-32);
   getdNdptHAGE21->SetSavedPoint(74,7.489568e-33);
   getdNdptHAGE21->SetSavedPoint(75,2.768592e-33);
   getdNdptHAGE21->SetSavedPoint(76,1.023618e-33);
   getdNdptHAGE21->SetSavedPoint(77,3.785224e-34);
   getdNdptHAGE21->SetSavedPoint(78,1.399968e-34);
   getdNdptHAGE21->SetSavedPoint(79,5.178639e-35);
   getdNdptHAGE21->SetSavedPoint(80,1.915942e-35);
   getdNdptHAGE21->SetSavedPoint(81,7.089518e-36);
   getdNdptHAGE21->SetSavedPoint(82,2.623717e-36);
   getdNdptHAGE21->SetSavedPoint(83,9.711392e-37);
   getdNdptHAGE21->SetSavedPoint(84,3.595082e-37);
   getdNdptHAGE21->SetSavedPoint(85,1.33106e-37);
   getdNdptHAGE21->SetSavedPoint(86,4.928856e-38);
   getdNdptHAGE21->SetSavedPoint(87,1.82538e-38);
   getdNdptHAGE21->SetSavedPoint(88,6.761105e-39);
   getdNdptHAGE21->SetSavedPoint(89,2.504598e-39);
   getdNdptHAGE21->SetSavedPoint(90,9.279255e-40);
   getdNdptHAGE21->SetSavedPoint(91,3.438284e-40);
   getdNdptHAGE21->SetSavedPoint(92,1.274156e-40);
   getdNdptHAGE21->SetSavedPoint(93,4.722315e-41);
   getdNdptHAGE21->SetSavedPoint(94,1.7504e-41);
   getdNdptHAGE21->SetSavedPoint(95,6.488868e-42);
   getdNdptHAGE21->SetSavedPoint(96,2.405739e-42);
   getdNdptHAGE21->SetSavedPoint(97,8.920216e-43);
   getdNdptHAGE21->SetSavedPoint(98,3.307869e-43);
   getdNdptHAGE21->SetSavedPoint(99,1.22678e-43);
   getdNdptHAGE21->SetSavedPoint(100,4.550185e-44);
   getdNdptHAGE21->SetSavedPoint(101,1e-12);
   getdNdptHAGE21->SetSavedPoint(102,100);
   getdNdptHAGE21->SetFillColor(19);
   getdNdptHAGE21->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE21->SetLineColor(ci);
   getdNdptHAGE21->SetLineWidth(2);
   getdNdptHAGE21->SetChisquare(159.1755);
   getdNdptHAGE21->SetNDF(12);
   getdNdptHAGE21->SetParameter(0,0.93827);
   getdNdptHAGE21->SetParError(0,0);
   getdNdptHAGE21->SetParLimits(0,0.93827,0.93827);
   getdNdptHAGE21->SetParameter(1,0.9819048);
   getdNdptHAGE21->SetParError(1,2.662978e+07);
   getdNdptHAGE21->SetParLimits(1,0,0);
   getdNdptHAGE21->SetParameter(2,20.01269);
   getdNdptHAGE21->SetParError(2,2.662978e+07);
   getdNdptHAGE21->SetParLimits(2,0,0);
   getdNdptHAGE21->SetParameter(3,949301.8);
   getdNdptHAGE21->SetParError(3,1);
   getdNdptHAGE21->SetParLimits(3,0,0);
   getdNdptHAGE21->SetParameter(4,-1);
   getdNdptHAGE21->SetParError(4,0);
   getdNdptHAGE21->SetParLimits(4,-1,-1);
   getdNdptHAGE21->SetParent(cent0_proton_AupLAu_62dO4__7);
   cent0_proton_AupLAu_62dO4__7->GetListOfFunctions()->Add(getdNdptHAGE21);

   ci = TColor::GetColor("#000099");
   cent0_proton_AupLAu_62dO4__7->SetLineColor(ci);
   cent0_proton_AupLAu_62dO4__7->SetMarkerStyle(20);
   cent0_proton_AupLAu_62dO4__7->GetXaxis()->SetRange(0,16);
   cent0_proton_AupLAu_62dO4__7->GetXaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_62dO4__7->GetXaxis()->SetLabelSize(0.1);
   cent0_proton_AupLAu_62dO4__7->GetXaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_62dO4__7->GetXaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_62dO4__7->GetYaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_62dO4__7->GetYaxis()->SetLabelSize(0.1);
   cent0_proton_AupLAu_62dO4__7->GetYaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_62dO4__7->GetYaxis()->SetTitleOffset(0);
   cent0_proton_AupLAu_62dO4__7->GetYaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_62dO4__7->GetZaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_62dO4__7->GetZaxis()->SetLabelSize(0.035);
   cent0_proton_AupLAu_62dO4__7->GetZaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_62dO4__7->GetZaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_62dO4__7->Draw("");
      tex = new TLatex(0.1,2,"p 62.4 GeV");
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
   part7->Modified();
   c->cd();
  
// ------------>Primitives in pad: part8
   TPad *part8 = new TPad("part8", "part8",0.3733333,0,0.6866667,0.4133334);
   part8->Draw();
   part8->cd();
   part8->Range(-0.02727273,-0.04348054,1.55,1.16175);
   part8->SetFillColor(0);
   part8->SetBorderMode(0);
   part8->SetBorderSize(0);
   part8->SetLogy();
   part8->SetLeftMargin(0);
   part8->SetRightMargin(0);
   part8->SetTopMargin(0);
   part8->SetBottomMargin(0.2903226);
   part8->SetFrameBorderMode(0);
   part8->SetFrameBorderMode(0);
   Double_t xAxis8[12] = {0.38, 0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.78, 0.82, 0.88, 0.93}; 
   
   TH1D *cent0_proton_AupLAu_130__8 = new TH1D("cent0_proton_AupLAu_130__8","cent0_proton_Au+Au_130",11, xAxis8);
   cent0_proton_AupLAu_130__8->SetBinContent(1,6.01);
   cent0_proton_AupLAu_130__8->SetBinContent(2,5.73);
   cent0_proton_AupLAu_130__8->SetBinContent(3,5.69);
   cent0_proton_AupLAu_130__8->SetBinContent(4,5.67);
   cent0_proton_AupLAu_130__8->SetBinContent(5,5.62);
   cent0_proton_AupLAu_130__8->SetBinContent(6,5.39);
   cent0_proton_AupLAu_130__8->SetBinContent(7,5.18);
   cent0_proton_AupLAu_130__8->SetBinContent(8,4.96);
   cent0_proton_AupLAu_130__8->SetBinContent(9,4.73);
   cent0_proton_AupLAu_130__8->SetBinContent(10,4.36);
   cent0_proton_AupLAu_130__8->SetBinContent(11,4.08);
   cent0_proton_AupLAu_130__8->SetBinError(1,0.49);
   cent0_proton_AupLAu_130__8->SetBinError(2,0.33);
   cent0_proton_AupLAu_130__8->SetBinError(3,0.21);
   cent0_proton_AupLAu_130__8->SetBinError(4,0.15);
   cent0_proton_AupLAu_130__8->SetBinError(5,0.15);
   cent0_proton_AupLAu_130__8->SetBinError(6,0.09);
   cent0_proton_AupLAu_130__8->SetBinError(7,0.09);
   cent0_proton_AupLAu_130__8->SetBinError(8,0.08);
   cent0_proton_AupLAu_130__8->SetBinError(9,0.03);
   cent0_proton_AupLAu_130__8->SetBinError(10,0.03);
   cent0_proton_AupLAu_130__8->SetBinError(11,0.03);
   cent0_proton_AupLAu_130__8->SetEntries(11);
   
   TF1 *getdNdpt22a = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt22a->SetRange(1e-14,100);
   getdNdpt22a->SetName("getdNdpt");
   getdNdpt22a->SetTitle("getdNdpt");
   getdNdpt22a->SetSavedPoint(0,5.013999);
   getdNdpt22a->SetSavedPoint(1,3.469214);
   getdNdpt22a->SetSavedPoint(2,0.2374393);
   getdNdpt22a->SetSavedPoint(3,0.007221899);
   getdNdpt22a->SetSavedPoint(4,0.0001699438);
   getdNdpt22a->SetSavedPoint(5,3.612064e-06);
   getdNdpt22a->SetSavedPoint(6,7.32706e-08);
   getdNdpt22a->SetSavedPoint(7,1.451997e-09);
   getdNdpt22a->SetSavedPoint(8,2.842499e-11);
   getdNdpt22a->SetSavedPoint(9,5.52891e-13);
   getdNdpt22a->SetSavedPoint(10,1.071918e-14);
   getdNdpt22a->SetSavedPoint(11,2.075179e-16);
   getdNdpt22a->SetSavedPoint(12,4.015929e-18);
   getdNdpt22a->SetSavedPoint(13,7.773749e-20);
   getdNdpt22a->SetSavedPoint(14,1.505755e-21);
   getdNdpt22a->SetSavedPoint(15,2.919142e-23);
   getdNdpt22a->SetSavedPoint(16,5.664835e-25);
   getdNdpt22a->SetSavedPoint(17,1.10047e-26);
   getdNdpt22a->SetSavedPoint(18,2.140117e-28);
   getdNdpt22a->SetSavedPoint(19,4.16644e-30);
   getdNdpt22a->SetSavedPoint(20,8.119937e-32);
   getdNdpt22a->SetSavedPoint(21,1.58412e-33);
   getdNdpt22a->SetSavedPoint(22,3.093545e-35);
   getdNdpt22a->SetSavedPoint(23,6.047025e-37);
   getdNdpt22a->SetSavedPoint(24,1.183115e-38);
   getdNdpt22a->SetSavedPoint(25,2.316838e-40);
   getdNdpt22a->SetSavedPoint(26,4.540784e-42);
   getdNdpt22a->SetSavedPoint(27,8.90669e-44);
   getdNdpt22a->SetSavedPoint(28,1.748383e-45);
   getdNdpt22a->SetSavedPoint(29,3.434601e-47);
   getdNdpt22a->SetSavedPoint(30,6.751832e-49);
   getdNdpt22a->SetSavedPoint(31,1.328186e-50);
   getdNdpt22a->SetSavedPoint(32,2.614418e-52);
   getdNdpt22a->SetSavedPoint(33,5.149416e-54);
   getdNdpt22a->SetSavedPoint(34,1.014837e-55);
   getdNdpt22a->SetSavedPoint(35,2.001147e-57);
   getdNdpt22a->SetSavedPoint(36,3.948171e-59);
   getdNdpt22a->SetSavedPoint(37,7.793584e-61);
   getdNdpt22a->SetSavedPoint(38,1.539196e-62);
   getdNdpt22a->SetSavedPoint(39,3.041284e-64);
   getdNdpt22a->SetSavedPoint(40,6.011994e-66);
   getdNdpt22a->SetSavedPoint(41,1.188969e-67);
   getdNdpt22a->SetSavedPoint(42,2.352373e-69);
   getdNdpt22a->SetSavedPoint(43,4.656054e-71);
   getdNdpt22a->SetSavedPoint(44,9.219336e-73);
   getdNdpt22a->SetSavedPoint(45,1.826185e-74);
   getdNdpt22a->SetSavedPoint(46,3.618658e-76);
   getdNdpt22a->SetSavedPoint(47,7.173026e-78);
   getdNdpt22a->SetSavedPoint(48,1.422342e-79);
   getdNdpt22a->SetSavedPoint(49,2.821286e-81);
   getdNdpt22a->SetSavedPoint(50,5.597925e-83);
   getdNdpt22a->SetSavedPoint(51,1.111065e-84);
   getdNdpt22a->SetSavedPoint(52,2.205867e-86);
   getdNdpt22a->SetSavedPoint(53,4.380697e-88);
   getdNdpt22a->SetSavedPoint(54,8.702154e-90);
   getdNdpt22a->SetSavedPoint(55,1.72899e-91);
   getdNdpt22a->SetSavedPoint(56,6.26386e-95);
   getdNdpt22a->SetSavedPoint(57,1.202474e-99);
   getdNdpt22a->SetSavedPoint(58,2.048647e-103);
   getdNdpt22a->SetSavedPoint(59,1.719102e-107);
   getdNdpt22a->SetSavedPoint(60,6.446077e-112);
   getdNdpt22a->SetSavedPoint(61,1.899318e-119);
   getdNdpt22a->SetSavedPoint(62,1.920378e-124);
   getdNdpt22a->SetSavedPoint(63,1.527769e-129);
   getdNdpt22a->SetSavedPoint(64,1.110798e-134);
   getdNdpt22a->SetSavedPoint(65,9.544409e-140);
   getdNdpt22a->SetSavedPoint(66,2.873649e-147);
   getdNdpt22a->SetSavedPoint(67,1.719238e-153);
   getdNdpt22a->SetSavedPoint(68,2.103425e-159);
   getdNdpt22a->SetSavedPoint(69,1.091963e-168);
   getdNdpt22a->SetSavedPoint(70,1.318356e-174);
   getdNdpt22a->SetSavedPoint(71,5.308875e-186);
   getdNdpt22a->SetSavedPoint(72,5.736311e-194);
   getdNdpt22a->SetSavedPoint(73,1.132713e-202);
   getdNdpt22a->SetSavedPoint(74,7.615465e-212);
   getdNdpt22a->SetSavedPoint(75,7.119333e-230);
   getdNdpt22a->SetSavedPoint(76,2.3796e-241);
   getdNdpt22a->SetSavedPoint(77,2.340158e-263);
   getdNdpt22a->SetSavedPoint(78,2.122788e-288);
   getdNdpt22a->SetSavedPoint(79,0);
   getdNdpt22a->SetSavedPoint(80,0);
   getdNdpt22a->SetSavedPoint(81,0);
   getdNdpt22a->SetSavedPoint(82,0);
   getdNdpt22a->SetSavedPoint(83,0);
   getdNdpt22a->SetSavedPoint(84,0);
   getdNdpt22a->SetSavedPoint(85,0);
   getdNdpt22a->SetSavedPoint(86,0);
   getdNdpt22a->SetSavedPoint(87,0);
   getdNdpt22a->SetSavedPoint(88,0);
   getdNdpt22a->SetSavedPoint(89,0);
   getdNdpt22a->SetSavedPoint(90,0);
   getdNdpt22a->SetSavedPoint(91,0);
   getdNdpt22a->SetSavedPoint(92,0);
   getdNdpt22a->SetSavedPoint(93,0);
   getdNdpt22a->SetSavedPoint(94,0);
   getdNdpt22a->SetSavedPoint(95,0);
   getdNdpt22a->SetSavedPoint(96,0);
   getdNdpt22a->SetSavedPoint(97,0);
   getdNdpt22a->SetSavedPoint(98,0);
   getdNdpt22a->SetSavedPoint(99,0);
   getdNdpt22a->SetSavedPoint(100,0);
   getdNdpt22a->SetSavedPoint(101,1e-14);
   getdNdpt22a->SetSavedPoint(102,100);
   getdNdpt22a->SetFillColor(19);
   getdNdpt22a->SetFillStyle(0);
   getdNdpt22a->SetLineWidth(2);
   getdNdpt22a->SetChisquare(4.255788);
   getdNdpt22a->SetNDF(7);
   getdNdpt22a->SetParameter(0,0.93827);
   getdNdpt22a->SetParError(0,0);
   getdNdpt22a->SetParLimits(0,0.93827,0.93827);
   getdNdpt22a->SetParameter(1,0.7082503);
   getdNdpt22a->SetParError(1,0.02769858);
   getdNdpt22a->SetParLimits(1,0.5,1);
   getdNdpt22a->SetParameter(2,0.1059056);
   getdNdpt22a->SetParError(2,0.0005244904);
   getdNdpt22a->SetParLimits(2,0,0);
   getdNdpt22a->SetParameter(3,0.4831967);
   getdNdpt22a->SetParError(3,0.09617252);
   getdNdpt22a->SetParLimits(3,0,0);
   getdNdpt22a->SetParameter(4,1035452);
   getdNdpt22a->SetParError(4,52585.93);
   getdNdpt22a->SetParLimits(4,0,0);
   getdNdpt22a->SetParameter(5,-1);
   getdNdpt22a->SetParError(5,0);
   getdNdpt22a->SetParLimits(5,-1,-1);
   getdNdpt22a->SetParent(cent0_proton_AupLAu_130__8);
   cent0_proton_AupLAu_130__8->GetListOfFunctions()->Add(getdNdpt22a);
   
   TF1 *getdNdpt223 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt223->SetRange(1e-14,100);
   getdNdpt223->SetName("getdNdpt2");
   getdNdpt223->SetTitle("getdNdpt2");
   getdNdpt223->SetSavedPoint(0,4.912898);
   getdNdpt223->SetSavedPoint(1,3.474447);
   getdNdpt223->SetSavedPoint(2,0.2542362);
   getdNdpt223->SetSavedPoint(3,0.008652065);
   getdNdpt223->SetSavedPoint(4,0.0002291862);
   getdNdpt223->SetSavedPoint(5,5.464701e-06);
   getdNdpt223->SetSavedPoint(6,1.237406e-07);
   getdNdpt223->SetSavedPoint(7,2.724651e-09);
   getdNdpt223->SetSavedPoint(8,5.903445e-11);
   getdNdpt223->SetSavedPoint(9,1.26678e-12);
   getdNdpt223->SetSavedPoint(10,2.702261e-14);
   getdNdpt223->SetSavedPoint(11,5.7435e-16);
   getdNdpt223->SetSavedPoint(12,1.218082e-17);
   getdNdpt223->SetSavedPoint(13,2.580081e-19);
   getdNdpt223->SetSavedPoint(14,5.461562e-21);
   getdNdpt223->SetSavedPoint(15,1.155868e-22);
   getdNdpt223->SetSavedPoint(16,2.446413e-24);
   getdNdpt223->SetSavedPoint(17,5.179227e-26);
   getdNdpt223->SetSavedPoint(18,1.096907e-27);
   getdNdpt223->SetSavedPoint(19,2.324245e-29);
   getdNdpt223->SetSavedPoint(20,4.927488e-31);
   getdNdpt223->SetSavedPoint(21,1.045239e-32);
   getdNdpt223->SetSavedPoint(22,2.218504e-34);
   getdNdpt223->SetSavedPoint(23,4.711544e-36);
   getdNdpt223->SetSavedPoint(24,1.001208e-37);
   getdNdpt223->SetSavedPoint(25,2.128834e-39);
   getdNdpt223->SetSavedPoint(26,4.529092e-41);
   getdNdpt223->SetSavedPoint(27,9.64112e-43);
   getdNdpt223->SetSavedPoint(28,2.053453e-44);
   getdNdpt223->SetSavedPoint(29,4.375993e-46);
   getdNdpt223->SetSavedPoint(30,9.330314e-48);
   getdNdpt223->SetSavedPoint(31,1.990383e-49);
   getdNdpt223->SetSavedPoint(32,4.248065e-51);
   getdNdpt223->SetSavedPoint(33,9.070946e-53);
   getdNdpt223->SetSavedPoint(34,1.937824e-54);
   getdNdpt223->SetSavedPoint(35,4.141614e-56);
   getdNdpt223->SetSavedPoint(36,8.85548e-58);
   getdNdpt223->SetSavedPoint(37,1.894242e-59);
   getdNdpt223->SetSavedPoint(38,4.053533e-61);
   getdNdpt223->SetSavedPoint(39,8.677627e-63);
   getdNdpt223->SetSavedPoint(40,1.858367e-64);
   getdNdpt223->SetSavedPoint(41,3.981257e-66);
   getdNdpt223->SetSavedPoint(42,8.53221e-68);
   getdNdpt223->SetSavedPoint(43,1.829156e-69);
   getdNdpt223->SetSavedPoint(44,3.922679e-71);
   getdNdpt223->SetSavedPoint(45,8.414985e-73);
   getdNdpt223->SetSavedPoint(46,1.805751e-74);
   getdNdpt223->SetSavedPoint(47,3.876076e-76);
   getdNdpt223->SetSavedPoint(48,8.322473e-78);
   getdNdpt223->SetSavedPoint(49,1.787452e-79);
   getdNdpt223->SetSavedPoint(50,3.84003e-81);
   getdNdpt223->SetSavedPoint(51,8.251814e-83);
   getdNdpt223->SetSavedPoint(52,1.773681e-84);
   getdNdpt223->SetSavedPoint(53,3.813374e-86);
   getdNdpt223->SetSavedPoint(54,8.200647e-88);
   getdNdpt223->SetSavedPoint(55,1.76396e-89);
   getdNdpt223->SetSavedPoint(56,3.795142e-91);
   getdNdpt223->SetSavedPoint(57,8.167018e-93);
   getdNdpt223->SetSavedPoint(58,1.757893e-94);
   getdNdpt223->SetSavedPoint(59,3.784533e-96);
   getdNdpt223->SetSavedPoint(60,8.149303e-98);
   getdNdpt223->SetSavedPoint(61,1.755152e-99);
   getdNdpt223->SetSavedPoint(62,3.780878e-101);
   getdNdpt223->SetSavedPoint(63,8.146147e-103);
   getdNdpt223->SetSavedPoint(64,1.755461e-104);
   getdNdpt223->SetSavedPoint(65,3.783621e-106);
   getdNdpt223->SetSavedPoint(66,8.156419e-108);
   getdNdpt223->SetSavedPoint(67,1.758591e-109);
   getdNdpt223->SetSavedPoint(68,3.792295e-111);
   getdNdpt223->SetSavedPoint(69,8.17917e-113);
   getdNdpt223->SetSavedPoint(70,1.76435e-114);
   getdNdpt223->SetSavedPoint(71,3.806508e-116);
   getdNdpt223->SetSavedPoint(72,8.213606e-118);
   getdNdpt223->SetSavedPoint(73,1.772575e-119);
   getdNdpt223->SetSavedPoint(74,3.825933e-121);
   getdNdpt223->SetSavedPoint(75,8.259063e-123);
   getdNdpt223->SetSavedPoint(76,1.783132e-124);
   getdNdpt223->SetSavedPoint(77,3.850296e-126);
   getdNdpt223->SetSavedPoint(78,8.315079e-128);
   getdNdpt223->SetSavedPoint(79,1.721821e-129);
   getdNdpt223->SetSavedPoint(80,5.873213e-134);
   getdNdpt223->SetSavedPoint(81,7.09098e-139);
   getdNdpt223->SetSavedPoint(82,6.325304e-144);
   getdNdpt223->SetSavedPoint(83,7.50099e-150);
   getdNdpt223->SetSavedPoint(84,8.432877e-155);
   getdNdpt223->SetSavedPoint(85,1.0745e-160);
   getdNdpt223->SetSavedPoint(86,1.135987e-167);
   getdNdpt223->SetSavedPoint(87,7.400339e-173);
   getdNdpt223->SetSavedPoint(88,4.737387e-184);
   getdNdpt223->SetSavedPoint(89,1.154416e-192);
   getdNdpt223->SetSavedPoint(90,9.677218e-195);
   getdNdpt223->SetSavedPoint(91,2.679203e-206);
   getdNdpt223->SetSavedPoint(92,6.871418e-224);
   getdNdpt223->SetSavedPoint(93,0);
   getdNdpt223->SetSavedPoint(94,0);
   getdNdpt223->SetSavedPoint(95,0);
   getdNdpt223->SetSavedPoint(96,0);
   getdNdpt223->SetSavedPoint(97,0);
   getdNdpt223->SetSavedPoint(98,0);
   getdNdpt223->SetSavedPoint(99,0);
   getdNdpt223->SetSavedPoint(100,0);
   getdNdpt223->SetSavedPoint(101,1e-14);
   getdNdpt223->SetSavedPoint(102,100);
   getdNdpt223->SetFillColor(19);
   getdNdpt223->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt223->SetLineColor(ci);
   getdNdpt223->SetLineWidth(2);
   getdNdpt223->SetChisquare(4.282018);
   getdNdpt223->SetNDF(7);
   getdNdpt223->SetParameter(0,0.93827);
   getdNdpt223->SetParError(0,0);
   getdNdpt223->SetParLimits(0,0.93827,0.93827);
   getdNdpt223->SetParameter(1,0.5923874);
   getdNdpt223->SetParError(1,0.0557974);
   getdNdpt223->SetParLimits(1,0.3,0.8);
   getdNdpt223->SetParameter(2,0.1323124);
   getdNdpt223->SetParError(2,0.0007989017);
   getdNdpt223->SetParLimits(2,0.08,0.2);
   getdNdpt223->SetParameter(3,0.1001209);
   getdNdpt223->SetParError(3,0.1957916);
   getdNdpt223->SetParLimits(3,0.01,5);
   getdNdpt223->SetParameter(4,125107.7);
   getdNdpt223->SetParError(4,6290.942);
   getdNdpt223->SetParLimits(4,0,0);
   getdNdpt223->SetParameter(5,-1);
   getdNdpt223->SetParError(5,0);
   getdNdpt223->SetParLimits(5,-1,-1);
   getdNdpt223->SetParent(cent0_proton_AupLAu_130__8);
   cent0_proton_AupLAu_130__8->GetListOfFunctions()->Add(getdNdpt223);
   
   TF1 *getdNdptHAGE24 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE24->SetRange(1e-12,100);
   getdNdptHAGE24->SetName("getdNdptHAGE");
   getdNdptHAGE24->SetTitle("getdNdptHAGE");
   getdNdptHAGE24->SetSavedPoint(0,7.669504);
   getdNdptHAGE24->SetSavedPoint(1,3.73412);
   getdNdptHAGE24->SetSavedPoint(2,1.199758);
   getdNdptHAGE24->SetSavedPoint(3,0.4046609);
   getdNdptHAGE24->SetSavedPoint(4,0.1449857);
   getdNdptHAGE24->SetSavedPoint(5,0.05426067);
   getdNdptHAGE24->SetSavedPoint(6,0.02094877);
   getdNdptHAGE24->SetSavedPoint(7,0.008275621);
   getdNdptHAGE24->SetSavedPoint(8,0.003326974);
   getdNdptHAGE24->SetSavedPoint(9,0.001356046);
   getdNdptHAGE24->SetSavedPoint(10,0.000558869);
   getdNdptHAGE24->SetSavedPoint(11,0.0002324328);
   getdNdptHAGE24->SetSavedPoint(12,9.740622e-05);
   getdNdptHAGE24->SetSavedPoint(13,4.10842e-05);
   getdNdptHAGE24->SetSavedPoint(14,1.742469e-05);
   getdNdptHAGE24->SetSavedPoint(15,7.425727e-06);
   getdNdptHAGE24->SetSavedPoint(16,3.177877e-06);
   getdNdptHAGE24->SetSavedPoint(17,1.365041e-06);
   getdNdptHAGE24->SetSavedPoint(18,5.882825e-07);
   getdNdptHAGE24->SetSavedPoint(19,2.542774e-07);
   getdNdptHAGE24->SetSavedPoint(20,1.102004e-07);
   getdNdptHAGE24->SetSavedPoint(21,4.787426e-08);
   getdNdptHAGE24->SetSavedPoint(22,2.084347e-08);
   getdNdptHAGE24->SetSavedPoint(23,9.092944e-09);
   getdNdptHAGE24->SetSavedPoint(24,3.97405e-09);
   getdNdptHAGE24->SetSavedPoint(25,1.739774e-09);
   getdNdptHAGE24->SetSavedPoint(26,7.628289e-10);
   getdNdptHAGE24->SetSavedPoint(27,3.349547e-10);
   getdNdptHAGE24->SetSavedPoint(28,1.472737e-10);
   getdNdptHAGE24->SetSavedPoint(29,6.48342e-11);
   getdNdptHAGE24->SetSavedPoint(30,2.857508e-11);
   getdNdptHAGE24->SetSavedPoint(31,1.260789e-11);
   getdNdptHAGE24->SetSavedPoint(32,5.568514e-12);
   getdNdptHAGE24->SetSavedPoint(33,2.461794e-12);
   getdNdptHAGE24->SetSavedPoint(34,1.089319e-12);
   getdNdptHAGE24->SetSavedPoint(35,4.824224e-13);
   getdNdptHAGE24->SetSavedPoint(36,2.138198e-13);
   getdNdptHAGE24->SetSavedPoint(37,9.484137e-14);
   getdNdptHAGE24->SetSavedPoint(38,4.209785e-14);
   getdNdptHAGE24->SetSavedPoint(39,1.869899e-14);
   getdNdptHAGE24->SetSavedPoint(40,8.311087e-15);
   getdNdptHAGE24->SetSavedPoint(41,3.696283e-15);
   getdNdptHAGE24->SetSavedPoint(42,1.644855e-15);
   getdNdptHAGE24->SetSavedPoint(43,7.323747e-16);
   getdNdptHAGE24->SetSavedPoint(44,3.262655e-16);
   getdNdptHAGE24->SetSavedPoint(45,1.454223e-16);
   getdNdptHAGE24->SetSavedPoint(46,6.484895e-17);
   getdNdptHAGE24->SetSavedPoint(47,2.893199e-17);
   getdNdptHAGE24->SetSavedPoint(48,1.291364e-17);
   getdNdptHAGE24->SetSavedPoint(49,5.766412e-18);
   getdNdptHAGE24->SetSavedPoint(50,2.575979e-18);
   getdNdptHAGE24->SetSavedPoint(51,1.151202e-18);
   getdNdptHAGE24->SetSavedPoint(52,5.146675e-19);
   getdNdptHAGE24->SetSavedPoint(53,2.301768e-19);
   getdNdptHAGE24->SetSavedPoint(54,1.029794e-19);
   getdNdptHAGE24->SetSavedPoint(55,4.608793e-20);
   getdNdptHAGE24->SetSavedPoint(56,2.063323e-20);
   getdNdptHAGE24->SetSavedPoint(57,9.240281e-21);
   getdNdptHAGE24->SetSavedPoint(58,4.139391e-21);
   getdNdptHAGE24->SetSavedPoint(59,1.854884e-21);
   getdNdptHAGE24->SetSavedPoint(60,8.314217e-22);
   getdNdptHAGE24->SetSavedPoint(61,3.727749e-22);
   getdNdptHAGE24->SetSavedPoint(62,1.671816e-22);
   getdNdptHAGE24->SetSavedPoint(63,7.499694e-23);
   getdNdptHAGE24->SetSavedPoint(64,3.365178e-23);
   getdNdptHAGE24->SetSavedPoint(65,1.510354e-23);
   getdNdptHAGE24->SetSavedPoint(66,6.780353e-24);
   getdNdptHAGE24->SetSavedPoint(67,3.04457e-24);
   getdNdptHAGE24->SetSavedPoint(68,1.367403e-24);
   getdNdptHAGE24->SetSavedPoint(69,6.142731e-25);
   getdNdptHAGE24->SetSavedPoint(70,2.760057e-25);
   getdNdptHAGE24->SetSavedPoint(71,1.240406e-25);
   getdNdptHAGE24->SetSavedPoint(72,5.575656e-26);
   getdNdptHAGE24->SetSavedPoint(73,2.506759e-26);
   getdNdptHAGE24->SetSavedPoint(74,1.127226e-26);
   getdNdptHAGE24->SetSavedPoint(75,5.069786e-27);
   getdNdptHAGE24->SetSavedPoint(76,2.280584e-27);
   getdNdptHAGE24->SetSavedPoint(77,1.026073e-27);
   getdNdptHAGE24->SetSavedPoint(78,4.617259e-28);
   getdNdptHAGE24->SetSavedPoint(79,2.078081e-28);
   getdNdptHAGE24->SetSavedPoint(80,9.35429e-29);
   getdNdptHAGE24->SetSavedPoint(81,4.211414e-29);
   getdNdptHAGE24->SetSavedPoint(82,1.896321e-29);
   getdNdptHAGE24->SetSavedPoint(83,8.540068e-30);
   getdNdptHAGE24->SetSavedPoint(84,3.846579e-30);
   getdNdptHAGE24->SetSavedPoint(85,1.732807e-30);
   getdNdptHAGE24->SetSavedPoint(86,7.807048e-31);
   getdNdptHAGE24->SetSavedPoint(87,3.517896e-31);
   getdNdptHAGE24->SetSavedPoint(88,1.585395e-31);
   getdNdptHAGE24->SetSavedPoint(89,7.145768e-32);
   getdNdptHAGE24->SetSavedPoint(90,3.221188e-32);
   getdNdptHAGE24->SetSavedPoint(91,1.452238e-32);
   getdNdptHAGE24->SetSavedPoint(92,6.548064e-33);
   getdNdptHAGE24->SetSavedPoint(93,2.952842e-33);
   getdNdptHAGE24->SetSavedPoint(94,1.331738e-33);
   getdNdptHAGE24->SetSavedPoint(95,6.00686e-34);
   getdNdptHAGE24->SetSavedPoint(96,2.709725e-34);
   getdNdptHAGE24->SetSavedPoint(97,1.222507e-34);
   getdNdptHAGE24->SetSavedPoint(98,5.516001e-35);
   getdNdptHAGE24->SetSavedPoint(99,2.489108e-35);
   getdNdptHAGE24->SetSavedPoint(100,1.123333e-35);
   getdNdptHAGE24->SetSavedPoint(101,1e-12);
   getdNdptHAGE24->SetSavedPoint(102,100);
   getdNdptHAGE24->SetFillColor(19);
   getdNdptHAGE24->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE24->SetLineColor(ci);
   getdNdptHAGE24->SetLineWidth(2);
   getdNdptHAGE24->SetChisquare(30.77259);
   getdNdptHAGE24->SetNDF(8);
   getdNdptHAGE24->SetParameter(0,0.93827);
   getdNdptHAGE24->SetParError(0,0);
   getdNdptHAGE24->SetParLimits(0,0.93827,0.93827);
   getdNdptHAGE24->SetParameter(1,0.7859206);
   getdNdptHAGE24->SetParError(1,1.401996e+07);
   getdNdptHAGE24->SetParLimits(1,0,0);
   getdNdptHAGE24->SetParameter(2,15.04339);
   getdNdptHAGE24->SetParError(2,1.401996e+07);
   getdNdptHAGE24->SetParLimits(2,0,0);
   getdNdptHAGE24->SetParameter(3,197783.2);
   getdNdptHAGE24->SetParError(3,1);
   getdNdptHAGE24->SetParLimits(3,0,0);
   getdNdptHAGE24->SetParameter(4,-1);
   getdNdptHAGE24->SetParError(4,0);
   getdNdptHAGE24->SetParLimits(4,-1,-1);
   getdNdptHAGE24->SetParent(cent0_proton_AupLAu_130__8);
   cent0_proton_AupLAu_130__8->GetListOfFunctions()->Add(getdNdptHAGE24);

   ci = TColor::GetColor("#000099");
   cent0_proton_AupLAu_130__8->SetLineColor(ci);
   cent0_proton_AupLAu_130__8->SetMarkerStyle(20);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetTitle("p_{T}");
   cent0_proton_AupLAu_130__8->GetXaxis()->SetRange(0,12);
   cent0_proton_AupLAu_130__8->GetXaxis()->CenterTitle(true);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetLabelSize(0.09);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetTitleSize(0.2);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetTitleOffset(0.5);
   cent0_proton_AupLAu_130__8->GetXaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_130__8->GetYaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_130__8->GetYaxis()->SetLabelSize(0.08);
   cent0_proton_AupLAu_130__8->GetYaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_130__8->GetYaxis()->SetTitleOffset(0);
   cent0_proton_AupLAu_130__8->GetYaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_130__8->GetZaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_130__8->GetZaxis()->SetLabelSize(0.035);
   cent0_proton_AupLAu_130__8->GetZaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_130__8->GetZaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_130__8->Draw("");
      tex = new TLatex(0.1,2,"p 130 GeV");
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
   part8->Modified();
   c->cd();
  
// ------------>Primitives in pad: part9
   TPad *part9 = new TPad("part9", "part9",0.6866667,0,1,0.4133334);
   part9->Draw();
   part9->cd();
   part9->Range(0.0125,-0.292807,1.56553,1.192126);
   part9->SetFillColor(0);
   part9->SetBorderMode(0);
   part9->SetBorderSize(0);
   part9->SetLogy();
   part9->SetLeftMargin(0);
   part9->SetRightMargin(0.01);
   part9->SetTopMargin(0);
   part9->SetBottomMargin(0.2903226);
   part9->SetFrameBorderMode(0);
   part9->SetFrameBorderMode(0);
   Double_t xAxis9[17] = {0.42, 0.47, 0.53, 0.57, 0.62, 0.68, 0.72, 0.78, 0.82, 0.88, 0.93, 0.97, 1.02, 1.07, 1.12, 1.18, 1.23}; 
   
   TH1D *cent0_proton_AupLAu_200__9 = new TH1D("cent0_proton_AupLAu_200__9","cent0_proton_Au+Au_200",16, xAxis9);
   cent0_proton_AupLAu_200__9->SetBinContent(1,6.42);
   cent0_proton_AupLAu_200__9->SetBinContent(2,6.45);
   cent0_proton_AupLAu_200__9->SetBinContent(3,6.18);
   cent0_proton_AupLAu_200__9->SetBinContent(4,5.96);
   cent0_proton_AupLAu_200__9->SetBinContent(5,5.75);
   cent0_proton_AupLAu_200__9->SetBinContent(6,5.44);
   cent0_proton_AupLAu_200__9->SetBinContent(7,5.07);
   cent0_proton_AupLAu_200__9->SetBinContent(8,4.89);
   cent0_proton_AupLAu_200__9->SetBinContent(9,4.67);
   cent0_proton_AupLAu_200__9->SetBinContent(10,4.436);
   cent0_proton_AupLAu_200__9->SetBinContent(11,4.16);
   cent0_proton_AupLAu_200__9->SetBinContent(12,3.95);
   cent0_proton_AupLAu_200__9->SetBinContent(13,3.68);
   cent0_proton_AupLAu_200__9->SetBinContent(14,3.36);
   cent0_proton_AupLAu_200__9->SetBinContent(15,3.24);
   cent0_proton_AupLAu_200__9->SetBinContent(16,2.89);
   cent0_proton_AupLAu_200__9->SetBinError(1,0.31);
   cent0_proton_AupLAu_200__9->SetBinError(2,0.25);
   cent0_proton_AupLAu_200__9->SetBinError(3,0.2);
   cent0_proton_AupLAu_200__9->SetBinError(4,0.16);
   cent0_proton_AupLAu_200__9->SetBinError(5,0.13);
   cent0_proton_AupLAu_200__9->SetBinError(6,0.13);
   cent0_proton_AupLAu_200__9->SetBinError(7,0.12);
   cent0_proton_AupLAu_200__9->SetBinError(8,0.11);
   cent0_proton_AupLAu_200__9->SetBinError(9,0.1);
   cent0_proton_AupLAu_200__9->SetBinError(10,0.095);
   cent0_proton_AupLAu_200__9->SetBinError(11,0.13);
   cent0_proton_AupLAu_200__9->SetBinError(12,0.12);
   cent0_proton_AupLAu_200__9->SetBinError(13,0.12);
   cent0_proton_AupLAu_200__9->SetBinError(14,0.11);
   cent0_proton_AupLAu_200__9->SetBinError(15,0.14);
   cent0_proton_AupLAu_200__9->SetBinError(16,0.14);
   cent0_proton_AupLAu_200__9->SetEntries(16);
   
   TF1 *getdNdpt25l = new TF1("*getdNdpt",1e-14,100,6);
    //The original function : getdNdpt had originally been created by:
    //TF1 *getdNdpt = new TF1("getdNdpt",getdNdpt,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt25l->SetRange(1e-14,100);
   getdNdpt25l->SetName("getdNdpt");
   getdNdpt25l->SetTitle("getdNdpt");
   getdNdpt25l->SetSavedPoint(0,7.398666);
   getdNdpt25l->SetSavedPoint(1,3.894297);
   getdNdpt25l->SetSavedPoint(2,0.6975825);
   getdNdpt25l->SetSavedPoint(3,0.07530869);
   getdNdpt25l->SetSavedPoint(4,0.006567228);
   getdNdpt25l->SetSavedPoint(5,0.0005198403);
   getdNdpt25l->SetSavedPoint(6,3.921289e-05);
   getdNdpt25l->SetSavedPoint(7,2.882808e-06);
   getdNdpt25l->SetSavedPoint(8,2.089119e-07);
   getdNdpt25l->SetSavedPoint(9,1.501574e-08);
   getdNdpt25l->SetSavedPoint(10,1.07423e-09);
   getdNdpt25l->SetSavedPoint(11,7.665277e-11);
   getdNdpt25l->SetSavedPoint(12,5.462592e-12);
   getdNdpt25l->SetSavedPoint(13,3.891004e-13);
   getdNdpt25l->SetSavedPoint(14,2.771659e-14);
   getdNdpt25l->SetSavedPoint(15,1.975039e-15);
   getdNdpt25l->SetSavedPoint(16,1.408183e-16);
   getdNdpt25l->SetSavedPoint(17,1.004723e-17);
   getdNdpt25l->SetSavedPoint(18,7.174147e-19);
   getdNdpt25l->SetSavedPoint(19,5.126828e-20);
   getdNdpt25l->SetSavedPoint(20,3.666818e-21);
   getdNdpt25l->SetSavedPoint(21,2.624779e-22);
   getdNdpt25l->SetSavedPoint(22,1.880418e-23);
   getdNdpt25l->SetSavedPoint(23,1.348241e-24);
   getdNdpt25l->SetSavedPoint(24,9.674371e-26);
   getdNdpt25l->SetSavedPoint(25,6.947198e-27);
   getdNdpt25l->SetSavedPoint(26,4.99249e-28);
   getdNdpt25l->SetSavedPoint(27,3.590327e-29);
   getdNdpt25l->SetSavedPoint(28,2.583739e-30);
   getdNdpt25l->SetSavedPoint(29,1.860586e-31);
   getdNdpt25l->SetSavedPoint(30,1.340683e-32);
   getdNdpt25l->SetSavedPoint(31,9.666455e-34);
   getdNdpt25l->SetSavedPoint(32,6.973692e-35);
   getdNdpt25l->SetSavedPoint(33,5.033878e-36);
   getdNdpt25l->SetSavedPoint(34,3.635613e-37);
   getdNdpt25l->SetSavedPoint(35,2.627111e-38);
   getdNdpt25l->SetSavedPoint(36,1.899313e-39);
   getdNdpt25l->SetSavedPoint(37,1.373801e-40);
   getdNdpt25l->SetSavedPoint(38,9.941518e-42);
   getdNdpt25l->SetSavedPoint(39,7.197397e-43);
   getdNdpt25l->SetSavedPoint(40,5.21297e-44);
   getdNdpt25l->SetSavedPoint(41,3.777247e-45);
   getdNdpt25l->SetSavedPoint(42,2.73804e-46);
   getdNdpt25l->SetSavedPoint(43,1.984361e-47);
   getdNdpt25l->SetSavedPoint(44,3.799071e-50);
   getdNdpt25l->SetSavedPoint(45,3.160187e-53);
   getdNdpt25l->SetSavedPoint(46,1.900712e-54);
   getdNdpt25l->SetSavedPoint(47,2.86963e-58);
   getdNdpt25l->SetSavedPoint(48,8.701622e-60);
   getdNdpt25l->SetSavedPoint(49,4.759037e-64);
   getdNdpt25l->SetSavedPoint(50,1.198642e-65);
   getdNdpt25l->SetSavedPoint(51,1.568216e-70);
   getdNdpt25l->SetSavedPoint(52,5.838302e-72);
   getdNdpt25l->SetSavedPoint(53,1.163369e-77);
   getdNdpt25l->SetSavedPoint(54,3.618556e-79);
   getdNdpt25l->SetSavedPoint(55,2.298929e-85);
   getdNdpt25l->SetSavedPoint(56,5.864173e-87);
   getdNdpt25l->SetSavedPoint(57,1.445224e-93);
   getdNdpt25l->SetSavedPoint(58,3.007384e-95);
   getdNdpt25l->SetSavedPoint(59,3.486601e-102);
   getdNdpt25l->SetSavedPoint(60,5.907045e-104);
   getdNdpt25l->SetSavedPoint(61,9.003517e-106);
   getdNdpt25l->SetSavedPoint(62,5.557993e-113);
   getdNdpt25l->SetSavedPoint(63,1.064795e-114);
   getdNdpt25l->SetSavedPoint(64,3.2213e-122);
   getdNdpt25l->SetSavedPoint(65,1.601967e-129);
   getdNdpt25l->SetSavedPoint(66,1.496163e-131);
   getdNdpt25l->SetSavedPoint(67,9.716401e-139);
   getdNdpt25l->SetSavedPoint(68,1.327327e-145);
   getdNdpt25l->SetSavedPoint(69,8.810664e-148);
   getdNdpt25l->SetSavedPoint(70,2.954696e-154);
   getdNdpt25l->SetSavedPoint(71,4.311072e-163);
   getdNdpt25l->SetSavedPoint(72,1.037284e-168);
   getdNdpt25l->SetSavedPoint(73,1.111547e-176);
   getdNdpt25l->SetSavedPoint(74,1.373206e-187);
   getdNdpt25l->SetSavedPoint(75,1.13533e-195);
   getdNdpt25l->SetSavedPoint(76,1.164568e-204);
   getdNdpt25l->SetSavedPoint(77,1.633962e-214);
   getdNdpt25l->SetSavedPoint(78,4.414509e-225);
   getdNdpt25l->SetSavedPoint(79,6.085846e-245);
   getdNdpt25l->SetSavedPoint(80,2.512181e-257);
   getdNdpt25l->SetSavedPoint(81,2.580137e-287);
   getdNdpt25l->SetSavedPoint(82,0);
   getdNdpt25l->SetSavedPoint(83,0);
   getdNdpt25l->SetSavedPoint(84,0);
   getdNdpt25l->SetSavedPoint(85,0);
   getdNdpt25l->SetSavedPoint(86,0);
   getdNdpt25l->SetSavedPoint(87,0);
   getdNdpt25l->SetSavedPoint(88,0);
   getdNdpt25l->SetSavedPoint(89,0);
   getdNdpt25l->SetSavedPoint(90,0);
   getdNdpt25l->SetSavedPoint(91,0);
   getdNdpt25l->SetSavedPoint(92,0);
   getdNdpt25l->SetSavedPoint(93,0);
   getdNdpt25l->SetSavedPoint(94,0);
   getdNdpt25l->SetSavedPoint(95,0);
   getdNdpt25l->SetSavedPoint(96,0);
   getdNdpt25l->SetSavedPoint(97,0);
   getdNdpt25l->SetSavedPoint(98,0);
   getdNdpt25l->SetSavedPoint(99,0);
   getdNdpt25l->SetSavedPoint(100,0);
   getdNdpt25l->SetSavedPoint(101,1e-14);
   getdNdpt25l->SetSavedPoint(102,100);
   getdNdpt25l->SetFillColor(19);
   getdNdpt25l->SetFillStyle(0);
   getdNdpt25l->SetLineWidth(2);
   getdNdpt25l->SetChisquare(2.786392);
   getdNdpt25l->SetNDF(12);
   getdNdpt25l->SetParameter(0,0.93827);
   getdNdpt25l->SetParError(0,0);
   getdNdpt25l->SetParLimits(0,0.93827,0.93827);
   getdNdpt25l->SetParameter(1,0.8480553);
   getdNdpt25l->SetParError(1,0.02603637);
   getdNdpt25l->SetParLimits(1,0.5,1);
   getdNdpt25l->SetParameter(2,0.1101023);
   getdNdpt25l->SetParError(2,0.001011877);
   getdNdpt25l->SetParLimits(2,0,0);
   getdNdpt25l->SetParameter(3,0.8491475);
   getdNdpt25l->SetParError(3,0.05587763);
   getdNdpt25l->SetParLimits(3,0,0);
   getdNdpt25l->SetParameter(4,911605.1);
   getdNdpt25l->SetParError(4,83783.06);
   getdNdpt25l->SetParLimits(4,0,0);
   getdNdpt25l->SetParameter(5,-1);
   getdNdpt25l->SetParError(5,0);
   getdNdpt25l->SetParLimits(5,-1,-1);
   getdNdpt25l->SetParent(cent0_proton_AupLAu_200__9);
   cent0_proton_AupLAu_200__9->GetListOfFunctions()->Add(getdNdpt25l);
   
   TF1 *getdNdpt226 = new TF1("*getdNdpt2",1e-14,100,6);
    //The original function : getdNdpt2 had originally been created by:
    //TF1 *getdNdpt2 = new TF1("getdNdpt2",getdNdpt2,1e-14,100,6, 1, TF1::EAddToList::kNo);
   getdNdpt226->SetRange(1e-14,100);
   getdNdpt226->SetName("getdNdpt2");
   getdNdpt226->SetTitle("getdNdpt2");
   getdNdpt226->SetSavedPoint(0,7.378486);
   getdNdpt226->SetSavedPoint(1,3.892689);
   getdNdpt226->SetSavedPoint(2,0.7510161);
   getdNdpt226->SetSavedPoint(3,0.1054126);
   getdNdpt226->SetSavedPoint(4,0.0135733);
   getdNdpt226->SetSavedPoint(5,0.001704507);
   getdNdpt226->SetSavedPoint(6,0.0002127884);
   getdNdpt226->SetSavedPoint(7,2.658647e-05);
   getdNdpt226->SetSavedPoint(8,3.332712e-06);
   getdNdpt226->SetSavedPoint(9,4.194716e-07);
   getdNdpt226->SetSavedPoint(10,5.301829e-08);
   getdNdpt226->SetSavedPoint(11,6.728177e-09);
   getdNdpt226->SetSavedPoint(12,8.570422e-10);
   getdNdpt226->SetSavedPoint(13,1.095498e-10);
   getdNdpt226->SetSavedPoint(14,1.404751e-11);
   getdNdpt226->SetSavedPoint(15,1.806536e-12);
   getdNdpt226->SetSavedPoint(16,2.329406e-13);
   getdNdpt226->SetSavedPoint(17,3.010907e-14);
   getdNdpt226->SetSavedPoint(18,3.900456e-15);
   getdNdpt226->SetSavedPoint(19,5.063151e-16);
   getdNdpt226->SetSavedPoint(20,6.584821e-17);
   getdNdpt226->SetSavedPoint(21,8.578708e-18);
   getdNdpt226->SetSavedPoint(22,1.119434e-18);
   getdNdpt226->SetSavedPoint(23,1.462929e-19);
   getdNdpt226->SetSavedPoint(24,1.91448e-20);
   getdNdpt226->SetSavedPoint(25,2.50865e-21);
   getdNdpt226->SetSavedPoint(26,3.291199e-22);
   getdNdpt226->SetSavedPoint(27,4.322742e-23);
   getdNdpt226->SetSavedPoint(28,5.683618e-24);
   getdNdpt226->SetSavedPoint(29,7.480371e-25);
   getdNdpt226->SetSavedPoint(30,9.854361e-26);
   getdNdpt226->SetSavedPoint(31,1.299324e-26);
   getdNdpt226->SetSavedPoint(32,1.714625e-27);
   getdNdpt226->SetSavedPoint(33,2.264452e-28);
   getdNdpt226->SetSavedPoint(34,2.992829e-29);
   getdNdpt226->SetSavedPoint(35,3.958295e-30);
   getdNdpt226->SetSavedPoint(36,5.238739e-31);
   getdNdpt226->SetSavedPoint(37,6.937821e-32);
   getdNdpt226->SetSavedPoint(38,9.193564e-33);
   getdNdpt226->SetSavedPoint(39,1.21898e-33);
   getdNdpt226->SetSavedPoint(40,1.617148e-34);
   getdNdpt226->SetSavedPoint(41,2.146509e-35);
   getdNdpt226->SetSavedPoint(42,2.850592e-36);
   getdNdpt226->SetSavedPoint(43,3.787454e-37);
   getdNdpt226->SetSavedPoint(44,5.034554e-38);
   getdNdpt226->SetSavedPoint(45,6.695259e-39);
   getdNdpt226->SetSavedPoint(46,8.907563e-40);
   getdNdpt226->SetSavedPoint(47,1.185572e-40);
   getdNdpt226->SetSavedPoint(48,1.578585e-41);
   getdNdpt226->SetSavedPoint(49,2.102675e-42);
   getdNdpt226->SetSavedPoint(50,2.801783e-43);
   getdNdpt226->SetSavedPoint(51,3.734642e-44);
   getdNdpt226->SetSavedPoint(52,4.979781e-45);
   getdNdpt226->SetSavedPoint(53,6.642217e-46);
   getdNdpt226->SetSavedPoint(54,8.862422e-47);
   getdNdpt226->SetSavedPoint(55,1.182834e-47);
   getdNdpt226->SetSavedPoint(56,1.579146e-48);
   getdNdpt226->SetSavedPoint(57,2.108843e-49);
   getdNdpt226->SetSavedPoint(58,2.81699e-50);
   getdNdpt226->SetSavedPoint(59,3.763931e-51);
   getdNdpt226->SetSavedPoint(60,5.030483e-52);
   getdNdpt226->SetSavedPoint(61,6.724901e-53);
   getdNdpt226->SetSavedPoint(62,8.992222e-54);
   getdNdpt226->SetSavedPoint(63,1.202679e-54);
   getdNdpt226->SetSavedPoint(64,1.608908e-55);
   getdNdpt226->SetSavedPoint(65,2.152824e-56);
   getdNdpt226->SetSavedPoint(66,2.881236e-57);
   getdNdpt226->SetSavedPoint(67,3.856909e-58);
   getdNdpt226->SetSavedPoint(68,5.164019e-59);
   getdNdpt226->SetSavedPoint(69,6.915468e-60);
   getdNdpt226->SetSavedPoint(70,9.262716e-61);
   getdNdpt226->SetSavedPoint(71,1.240898e-61);
   getdNdpt226->SetSavedPoint(72,1.662693e-62);
   getdNdpt226->SetSavedPoint(73,2.228255e-63);
   getdNdpt226->SetSavedPoint(74,2.986705e-64);
   getdNdpt226->SetSavedPoint(75,4.003984e-65);
   getdNdpt226->SetSavedPoint(76,5.368627e-66);
   getdNdpt226->SetSavedPoint(77,7.199513e-67);
   getdNdpt226->SetSavedPoint(78,9.656293e-68);
   getdNdpt226->SetSavedPoint(79,1.295339e-68);
   getdNdpt226->SetSavedPoint(80,1.737883e-69);
   getdNdpt226->SetSavedPoint(81,2.331955e-70);
   getdNdpt226->SetSavedPoint(82,3.129544e-71);
   getdNdpt226->SetSavedPoint(83,4.200506e-72);
   getdNdpt226->SetSavedPoint(84,5.63872e-73);
   getdNdpt226->SetSavedPoint(85,7.570358e-74);
   getdNdpt226->SetSavedPoint(86,1.016501e-74);
   getdNdpt226->SetSavedPoint(87,1.365068e-75);
   getdNdpt226->SetSavedPoint(88,1.833384e-76);
   getdNdpt226->SetSavedPoint(89,2.462663e-77);
   getdNdpt226->SetSavedPoint(90,3.308321e-78);
   getdNdpt226->SetSavedPoint(91,4.44488e-79);
   getdNdpt226->SetSavedPoint(92,5.972572e-80);
   getdNdpt226->SetSavedPoint(93,8.026212e-81);
   getdNdpt226->SetSavedPoint(94,1.078715e-81);
   getdNdpt226->SetSavedPoint(95,1.449936e-82);
   getdNdpt226->SetSavedPoint(96,1.949107e-83);
   getdNdpt226->SetSavedPoint(97,2.620395e-84);
   getdNdpt226->SetSavedPoint(98,3.52323e-85);
   getdNdpt226->SetSavedPoint(99,4.737592e-86);
   getdNdpt226->SetSavedPoint(100,6.371133e-87);
   getdNdpt226->SetSavedPoint(101,1e-14);
   getdNdpt226->SetSavedPoint(102,100);
   getdNdpt226->SetFillColor(19);
   getdNdpt226->SetFillStyle(0);

   ci = TColor::GetColor("#0000ff");
   getdNdpt226->SetLineColor(ci);
   getdNdpt226->SetLineWidth(2);
   getdNdpt226->SetChisquare(2.813794);
   getdNdpt226->SetNDF(12);
   getdNdpt226->SetParameter(0,0.93827);
   getdNdpt226->SetParError(0,0);
   getdNdpt226->SetParLimits(0,0.93827,0.93827);
   getdNdpt226->SetParameter(1,0.7267911);
   getdNdpt226->SetParError(1,0.1040214);
   getdNdpt226->SetParLimits(1,0.3,0.8);
   getdNdpt226->SetParameter(2,0.1992213);
   getdNdpt226->SetParError(2,0.10683);
   getdNdpt226->SetParLimits(2,0.08,0.2);
   getdNdpt226->SetParameter(3,0.6151961);
   getdNdpt226->SetParError(3,0.3655492);
   getdNdpt226->SetParLimits(3,0.01,5);
   getdNdpt226->SetParameter(4,7972.942);
   getdNdpt226->SetParError(4,4970.006);
   getdNdpt226->SetParLimits(4,0,0);
   getdNdpt226->SetParameter(5,-1);
   getdNdpt226->SetParError(5,0);
   getdNdpt226->SetParLimits(5,-1,-1);
   getdNdpt226->SetParent(cent0_proton_AupLAu_200__9);
   cent0_proton_AupLAu_200__9->GetListOfFunctions()->Add(getdNdpt226);
   
   TF1 *getdNdptHAGE27 = new TF1("*getdNdptHAGE",1e-12,100,5);
    //The original function : getdNdptHAGE had originally been created by:
    //TF1 *getdNdptHAGE = new TF1("getdNdptHAGE",getdNdptHAGE,1e-12,100,5, 1, TF1::EAddToList::kNo);
   getdNdptHAGE27->SetRange(1e-12,100);
   getdNdptHAGE27->SetName("getdNdptHAGE");
   getdNdptHAGE27->SetTitle("getdNdptHAGE");
   getdNdptHAGE27->SetSavedPoint(0,8.241122);
   getdNdptHAGE27->SetSavedPoint(1,3.884591);
   getdNdptHAGE27->SetSavedPoint(2,1.172301);
   getdNdptHAGE27->SetSavedPoint(3,0.3687215);
   getdNdptHAGE27->SetSavedPoint(4,0.1229091);
   getdNdptHAGE27->SetSavedPoint(5,0.0427523);
   getdNdptHAGE27->SetSavedPoint(6,0.01533285);
   getdNdptHAGE27->SetSavedPoint(7,0.005625019);
   getdNdptHAGE27->SetSavedPoint(8,0.002099661);
   getdNdptHAGE27->SetSavedPoint(9,0.0007945022);
   getdNdptHAGE27->SetSavedPoint(10,0.0003039574);
   getdNdptHAGE27->SetSavedPoint(11,0.000117342);
   getdNdptHAGE27->SetSavedPoint(12,4.56431e-05);
   getdNdptHAGE27->SetSavedPoint(13,1.786813e-05);
   getdNdptHAGE27->SetSavedPoint(14,7.033514e-06);
   getdNdptHAGE27->SetSavedPoint(15,2.781883e-06);
   getdNdptHAGE27->SetSavedPoint(16,1.104896e-06);
   getdNdptHAGE27->SetSavedPoint(17,4.404608e-07);
   getdNdptHAGE27->SetSavedPoint(18,1.761649e-07);
   getdNdptHAGE27->SetSavedPoint(19,7.066562e-08);
   getdNdptHAGE27->SetSavedPoint(20,2.842146e-08);
   getdNdptHAGE27->SetSavedPoint(21,1.145842e-08);
   getdNdptHAGE27->SetSavedPoint(22,4.629661e-09);
   getdNdptHAGE27->SetSavedPoint(23,1.874293e-09);
   getdNdptHAGE27->SetSavedPoint(24,7.601827e-10);
   getdNdptHAGE27->SetSavedPoint(25,3.088355e-10);
   getdNdptHAGE27->SetSavedPoint(26,1.256636e-10);
   getdNdptHAGE27->SetSavedPoint(27,5.120528e-11);
   getdNdptHAGE27->SetSavedPoint(28,2.089291e-11);
   getdNdptHAGE27->SetSavedPoint(29,8.53536e-12);
   getdNdptHAGE27->SetSavedPoint(30,3.490984e-12);
   getdNdptHAGE27->SetSavedPoint(31,1.42937e-12);
   getdNdptHAGE27->SetSavedPoint(32,5.858449e-13);
   getdNdptHAGE27->SetSavedPoint(33,2.403452e-13);
   getdNdptHAGE27->SetSavedPoint(34,9.86912e-14);
   getdNdptHAGE27->SetSavedPoint(35,4.055922e-14);
   getdNdptHAGE27->SetSavedPoint(36,1.668201e-14);
   getdNdptHAGE27->SetSavedPoint(37,6.866511e-15);
   getdNdptHAGE27->SetSavedPoint(38,2.828366e-15);
   getdNdptHAGE27->SetSavedPoint(39,1.165818e-15);
   getdNdptHAGE27->SetSavedPoint(40,4.808473e-16);
   getdNdptHAGE27->SetSavedPoint(41,1.984499e-16);
   getdNdptHAGE27->SetSavedPoint(42,8.195006e-17);
   getdNdptHAGE27->SetSavedPoint(43,3.386029e-17);
   getdNdptHAGE27->SetSavedPoint(44,1.399793e-17);
   getdNdptHAGE27->SetSavedPoint(45,5.789737e-18);
   getdNdptHAGE27->SetSavedPoint(46,2.395884e-18);
   getdNdptHAGE27->SetSavedPoint(47,9.919185e-19);
   getdNdptHAGE27->SetSavedPoint(48,4.108477e-19);
   getdNdptHAGE27->SetSavedPoint(49,1.702443e-19);
   getdNdptHAGE27->SetSavedPoint(50,7.05738e-20);
   getdNdptHAGE27->SetSavedPoint(51,2.926759e-20);
   getdNdptHAGE27->SetSavedPoint(52,1.214217e-20);
   getdNdptHAGE27->SetSavedPoint(53,5.03924e-21);
   getdNdptHAGE27->SetSavedPoint(54,2.092125e-21);
   getdNdptHAGE27->SetSavedPoint(55,8.688774e-22);
   getdNdptHAGE27->SetSavedPoint(56,3.609709e-22);
   getdNdptHAGE27->SetSavedPoint(57,1.500113e-22);
   getdNdptHAGE27->SetSavedPoint(58,6.236041e-23);
   getdNdptHAGE27->SetSavedPoint(59,2.593121e-23);
   getdNdptHAGE27->SetSavedPoint(60,1.078602e-23);
   getdNdptHAGE27->SetSavedPoint(61,4.48766e-24);
   getdNdptHAGE27->SetSavedPoint(62,1.86765e-24);
   getdNdptHAGE27->SetSavedPoint(63,7.774705e-25);
   getdNdptHAGE27->SetSavedPoint(64,3.237292e-25);
   getdNdptHAGE27->SetSavedPoint(65,1.348299e-25);
   getdNdptHAGE27->SetSavedPoint(66,5.616856e-26);
   getdNdptHAGE27->SetSavedPoint(67,2.340456e-26);
   getdNdptHAGE27->SetSavedPoint(68,9.754492e-27);
   getdNdptHAGE27->SetSavedPoint(69,4.066335e-27);
   getdNdptHAGE27->SetSavedPoint(70,1.695483e-27);
   getdNdptHAGE27->SetSavedPoint(71,7.070865e-28);
   getdNdptHAGE27->SetSavedPoint(72,2.949433e-28);
   getdNdptHAGE27->SetSavedPoint(73,1.23052e-28);
   getdNdptHAGE27->SetSavedPoint(74,5.13477e-29);
   getdNdptHAGE27->SetSavedPoint(75,2.143055e-29);
   getdNdptHAGE27->SetSavedPoint(76,8.945885e-30);
   getdNdptHAGE27->SetSavedPoint(77,3.734989e-30);
   getdNdptHAGE27->SetSavedPoint(78,1.559657e-30);
   getdNdptHAGE27->SetSavedPoint(79,6.513903e-31);
   getdNdptHAGE27->SetSavedPoint(80,2.720969e-31);
   getdNdptHAGE27->SetSavedPoint(81,1.136776e-31);
   getdNdptHAGE27->SetSavedPoint(82,4.749991e-32);
   getdNdptHAGE27->SetSavedPoint(83,1.985072e-32);
   getdNdptHAGE27->SetSavedPoint(84,8.297051e-33);
   getdNdptHAGE27->SetSavedPoint(85,3.468435e-33);
   getdNdptHAGE27->SetSavedPoint(86,1.450122e-33);
   getdNdptHAGE27->SetSavedPoint(87,6.063662e-34);
   getdNdptHAGE27->SetSavedPoint(88,2.535852e-34);
   getdNdptHAGE27->SetSavedPoint(89,1.060644e-34);
   getdNdptHAGE27->SetSavedPoint(90,4.436816e-35);
   getdNdptHAGE27->SetSavedPoint(91,1.856213e-35);
   getdNdptHAGE27->SetSavedPoint(92,7.766717e-36);
   getdNdptHAGE27->SetSavedPoint(93,3.250121e-36);
   getdNdptHAGE27->SetSavedPoint(94,1.360232e-36);
   getdNdptHAGE27->SetSavedPoint(95,5.693463e-37);
   getdNdptHAGE27->SetSavedPoint(96,2.383358e-37);
   getdNdptHAGE27->SetSavedPoint(97,9.978153e-38);
   getdNdptHAGE27->SetSavedPoint(98,4.177903e-38);
   getdNdptHAGE27->SetSavedPoint(99,1.749496e-38);
   getdNdptHAGE27->SetSavedPoint(100,7.326774e-39);
   getdNdptHAGE27->SetSavedPoint(101,1e-12);
   getdNdptHAGE27->SetSavedPoint(102,100);
   getdNdptHAGE27->SetFillColor(19);
   getdNdptHAGE27->SetFillStyle(0);

   ci = TColor::GetColor("#ff0000");
   getdNdptHAGE27->SetLineColor(ci);
   getdNdptHAGE27->SetLineWidth(2);
   getdNdptHAGE27->SetChisquare(6.968264);
   getdNdptHAGE27->SetNDF(13);
   getdNdptHAGE27->SetParameter(0,0.93827);
   getdNdptHAGE27->SetParError(0,0);
   getdNdptHAGE27->SetParLimits(0,0.93827,0.93827);
   getdNdptHAGE27->SetParameter(1,0.860701);
   getdNdptHAGE27->SetParError(1,0.05985873);
   getdNdptHAGE27->SetParLimits(1,0,0);
   getdNdptHAGE27->SetParameter(2,17.3395);
   getdNdptHAGE27->SetParError(2,1.297965);
   getdNdptHAGE27->SetParLimits(2,0,0);
   getdNdptHAGE27->SetParameter(3,220053.4);
   getdNdptHAGE27->SetParError(3,125108.5);
   getdNdptHAGE27->SetParLimits(3,0,0);
   getdNdptHAGE27->SetParameter(4,-1);
   getdNdptHAGE27->SetParError(4,0);
   getdNdptHAGE27->SetParLimits(4,-1,-1);
   getdNdptHAGE27->SetParent(cent0_proton_AupLAu_200__9);
   cent0_proton_AupLAu_200__9->GetListOfFunctions()->Add(getdNdptHAGE27);

   ci = TColor::GetColor("#000099");
   cent0_proton_AupLAu_200__9->SetLineColor(ci);
   cent0_proton_AupLAu_200__9->SetMarkerStyle(20);
   cent0_proton_AupLAu_200__9->GetXaxis()->SetRange(0,17);
   cent0_proton_AupLAu_200__9->GetXaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_200__9->GetXaxis()->SetLabelSize(0.1);
   cent0_proton_AupLAu_200__9->GetXaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_200__9->GetXaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_200__9->GetYaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_200__9->GetYaxis()->SetLabelSize(0.1);
   cent0_proton_AupLAu_200__9->GetYaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_200__9->GetYaxis()->SetTitleOffset(0);
   cent0_proton_AupLAu_200__9->GetYaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_200__9->GetZaxis()->SetLabelFont(42);
   cent0_proton_AupLAu_200__9->GetZaxis()->SetLabelSize(0.035);
   cent0_proton_AupLAu_200__9->GetZaxis()->SetTitleSize(0.035);
   cent0_proton_AupLAu_200__9->GetZaxis()->SetTitleFont(42);
   cent0_proton_AupLAu_200__9->Draw("");
      tex = new TLatex(0.1,2,"p 200 GeV");
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
   part9->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
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
			/***************************************************
			JTEST (tests jacobian for different eta assumption)
			****************************************************/
/*
			Double_t Alert= 50;
			Double_t eta = .2; //This is not a fixed value!! .2 for BES is more likely
			Double_t Ja = (pt*cosh(eta))/(sqrt(pt*pt*cosh(eta)*cosh(eta)+mass*mass)); //with eta=1
	    Double_t comp = (Ja-J)/Ja;
	    if (comp < 0){
	      comp=comp*(-1.0);
	    }
	    comp=comp*100;
	    if (comp>Alert){
	      cout<<"JTEST FAIL"<<endl;
	      cout<<"Biswas code="<<J<<"|| With eta="<<Ja<<endl;
	    }
	    cout<<"%DIFF="<<comp<<endl;
			//j=j0+1/2(j0-j0^3)n^2+(1/24)(j0-10j0^3+9j0^5)n^4
*/
		//FIND ALICE NOTES!!!!!!!!!IN PYTHIA
			/***************************************************
			^^Delete above!!
			****************************************************/
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
	//Double_t dNdpt_normalized			= 2 * TMath::Pi() * pt * norm * dNdptOverpt+type*0.;
	Double_t dNdpt_normalized			=  norm * dNdptOverpt+type*0.;
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

// HAGEDORNSSSS
//----------------------------------------------------------------
Double_t getdNdptOverptIntegrandHAGE(Double_t* rad, Double_t* par){
	// (dN/dpt)/pt= r*dr*mt*I0((pt*sinh(rho))/T)*K1((mt*cosh(rho))/T)
	// rho=arctanh(beta); beta=betaMax*(r/R)^n
	//Double_t pT		= pt[0];
/*
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
	Double_t integrand = 
	//r*mT*TMath::BesselI0(avoidFPE)*TMath::BesselK1(bk1arg)+type*0.;
*/
	Double_t mass 		= par[0];// not mT
	Double_t pt			= par[1];
	Double_t T 	= par[2];
	Double_t A 		= par[3];
	Double_t n 			= par[4];
	Double_t type		= par[5];
	
	Double_t mT = TMath::Sqrt(mass*mass + pt*pt);
	Double_t integrand = (A/mT)*TMath::Power((1+(mT/n*T)),-n);

	

	return integrand;
}


Double_t getdNdptHAGE(Double_t* pT, Double_t* params){
	TF1* dNdptOverptIntegrandFuncHAGE = new TF1("integrandFunc",
									getdNdptOverptIntegrandHAGE,
									0, 1, 5 );

	Double_t pt		= pT[0];
	Double_t mass 	= params[0];// not mT
	Double_t A 	= params[1];
	Double_t T 	= params[2];
	Double_t n 		= params[3];
	Double_t type	= params[4];
	dNdptOverptIntegrandFuncHAGE->SetParameters(mass,pt,A,T,n);

	Double_t dNdptOverpt 	= dNdptOverptIntegrandFuncHAGE->Integral(0,1);
	// ^ normalized r goes from 0 to 1 instead of from 0 to R
	//Double_t dNdpt_normalized			= 2 * TMath::Pi() * pt *  dNdptOverpt+type*0.;
	Double_t dNdpt_normalized			=  dNdptOverpt+type*0.;
	gSystem->ProcessEvents();
	gROOT->Reset();
	return dNdpt_normalized;
}
Double_t getdNdptOverptIntegrandEXPO(Double_t* rad, Double_t* par){
	
	Double_t pt 		= par[0];// not mT
	Double_t A			= par[1];
	Double_t B 	= par[2];
	Double_t mass = par[3];
	Double_t type = par[4];
	Double_t integrand = A*TMath::Exp((-pt/B));

	return integrand;
}// end of method getdNdptOverptIntegrand
Double_t getdETdyIntegrandHAGE(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass  = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	Double_t type = par[4];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdptHAGE(myPt,par);
	//////cout<< "funcVal: " << funcVal<< "pt: "<< pt<< endl;
	Double_t integrand = funcVal*(TMath::Sqrt(pt*pt+mass*mass)+type*mass);

	return integrand;
}

// Function to return the integrand to be used
	// to calculate dET/dEta using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram:
Double_t getdETdEtaIntegrandHAGE(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	Double_t type = par[4];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdptHAGE(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal*(pt/TMath::Sqrt(pt*pt+mass*mass))*(TMath::Sqrt(pt*pt+mass*mass)+type*mass);

	return integrand;
}

// Function to return the integrand to be used
	// to calculate dET/dy using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram:
Double_t getdNdEtaIntegrandHAGE(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	//Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdptHAGE(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal*(pt/TMath::Sqrt(pt*pt+mass*mass));

	return integrand;
}

// Function to return the integrand to be used
	// to calculate dN/dy using Boltzmann-Gibbs Blast wave
	// fit to available d^2N/(dpt*dy) vs pt histogram:
Double_t getdNdyIntegrandHAGE(Double_t* myPt, Double_t* par){
	Double_t pt   = myPt[0]; // x-axis of integration
	Double_t mass = par[0];
	//Double_t beta = par[1];
	//Double_t temp = par[2];
	//Double_t n    = par[3];
	//Double_t norm = par[4];
	//Double_t type = par[5];
	//funcBGBW-> SetParameters(mass,beta,temp,n,norm);
	Double_t funcVal = getdNdptHAGE(myPt,par);
	//////////cout<< "funcVal: " << funcVal<< " pt: "<< pt<< endl;
	Double_t integrand = funcVal;

	return integrand;
}

// get npart and its error for the STAR BES data as per the published table
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
		if (en == 62.4){
			if (cent == "0"){
				Npart 		= 347;
				NpartErr 	= 3;
			}
			else if (cent == "1"){
				Npart 		= 294;
				NpartErr 	= 4;
			}
			else if (cent == "2"){
				Npart 		= 230;
				NpartErr	= 5;
			}
			else if (cent == "3"){
				Npart 		= 164;
				NpartErr 	= 5;
			}
			else if (cent == "4"){
				Npart 		= 114;
				NpartErr 	= 5;
			}
			else if (cent == "5"){
				Npart 		= 76;
				NpartErr 	= 5;
			}
			else if (cent == "6"){
				Npart 		= 48;
				NpartErr	= 5;
			}
			else if (cent == "7"){
				Npart 		= 28;
				NpartErr 	= 3;
			}
			else if (cent == "8"){
				Npart 		= 15;
				NpartErr 	= 2;
			}
		}
		if (en == 130){
			if (cent == "0"){
				Npart 		= 344;
				NpartErr 	= 3;
			}
			else if (cent == "1"){
				Npart 		= 289;
				NpartErr 	= 5;
			}
			else if (cent == "2"){
				Npart 		= 237;
				NpartErr	= 7;
			}
			else if (cent == "3"){
				Npart 		= 187;
				NpartErr 	= 8;
			}
			else if (cent == "4"){
				Npart 		= 141;
				NpartErr 	= 8;
			}
			else if (cent == "5"){
				Npart 		= 100;
				NpartErr 	= 9;
			}
			else if (cent == "6"){
				Npart 		= 61;
				NpartErr	= 8;
			}
			else if (cent == "7"){
				Npart 		= 23;
				NpartErr 	= 5;
			}
}
		if (en == 200){
		if (cent == "0"){
				Npart 		= 350;
				NpartErr 	= 3;
			}
			else if (cent == "1"){
				Npart 		= 299;
				NpartErr	= 4;
			}
			else if (cent == "2"){
				Npart 		= 234;
				NpartErr 	= 5;
			}


			if (cent == "3"){
					Npart 		= 168;
					NpartErr 	= 5;
				}
			else if (cent == "4"){
					Npart 		= 117;
					NpartErr 	= 5;
				}
			else if (cent == "5"){
					Npart 		= 78;
					NpartErr	= 5;
				}
			else if (cent == "6"){
					Npart 		= 49;
					NpartErr 	= 5;
				}
			else if (cent == "7"){
					Npart 		= 29;
					NpartErr 	= 4;
				}
			else if (cent == "8"){
					Npart 		= 16;
					NpartErr 	= 3;
				}
	}
	static Int_t npartAndErrArr[2];// first element is Npar, second Npar_err
	npartAndErrArr[0] = Npart;
	npartAndErrArr[1] = NpartErr;

	return npartAndErrArr;
}

// get npart and its error for the STAR BES data as per the published table
 // overloaded function. takes int cent instead of string cent as argument
Int_t* getNpartAndErr(Double_t en, int cent){// args energy and centrality
	Int_t Npart = 0;
	Int_t NpartErr = 0;
		if (en == 7.7){
			if (cent == 0){
				Npart 		= 337;
				NpartErr 	= 2;
			}
			else if (cent == 1){
				Npart 		= 290;
				NpartErr 	= 6;
			}
			else if (cent == 2){
				Npart 		= 226;
				NpartErr	= 8;
			}
			else if (cent == 3){
				Npart 		= 160;
				NpartErr 	= 10;
			}
			else if (cent == 4){
				Npart 		= 110;
				NpartErr 	= 11;
			}
			else if (cent == 5){
				Npart 		= 72;
				NpartErr 	= 10;
			}
			else if (cent == 6){
				Npart 		= 45;
				NpartErr	= 9;
			}
			else if (cent == 7){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == 8){
				Npart 		= 14;
				NpartErr 	= 4;
			}
		}
		if (en == 11.5){
			if (cent == 0){
				Npart 		= 338;
				NpartErr 	= 2;
			}
			else if (cent == 1){
				Npart 		= 291;
				NpartErr 	= 6;
			}
			else if (cent == 2){
				Npart 		= 226;
				NpartErr	= 8;
			}
			else if (cent == 3){
				Npart 		= 160;
				NpartErr 	= 9;
			}
			else if (cent == 4){
				Npart 		= 110;
				NpartErr 	= 10;
			}
			else if (cent == 5){
				Npart 		= 73;
				NpartErr 	= 10;
			}
			else if (cent == 6){
				Npart 		= 45;
				NpartErr	= 9;
			}
			else if (cent == 7){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == 8){
				Npart 		= 14;
				NpartErr 	= 4;
			}
		}
		if (en == 19.6){
			if (cent == 0){
				Npart 		= 338;
				NpartErr 	= 2;
			}
			else if (cent == 1){
				Npart 		= 289;
				NpartErr 	= 6;
			}
			else if (cent == 2){
				Npart 		= 225;
				NpartErr	= 9;
			}
			else if (cent == 3){
				Npart 		= 158;
				NpartErr 	= 10;
			}
			else if (cent == 4){
				Npart 		= 108;
				NpartErr 	= 11;
			}
			else if (cent == 5){
				Npart 		= 71;
				NpartErr 	= 10;
			}
			else if (cent == 6){
				Npart 		= 44;
				NpartErr	= 9;
			}
			else if (cent == 7){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == 8){
				Npart 		= 14;
				NpartErr 	= 5;
			}
		}
		if (en == 27){
			if (cent == 0){
				Npart 		= 343;
				NpartErr 	= 2;
			}
			else if (cent == 1){
				Npart 		= 299;
				NpartErr 	= 6;
			}
			else if (cent == 2){
				Npart 		= 234;
				NpartErr	= 9;
			}
			else if (cent == 3){
				Npart 		= 166;
				NpartErr 	= 11;
			}
			else if (cent == 4){
				Npart 		= 114;
				NpartErr 	= 11;
			}
			else if (cent == 5){
				Npart 		= 75;
				NpartErr 	= 10;
			}
			else if (cent == 6){
				Npart 		= 47;
				NpartErr	= 9;
			}
			else if (cent == 7){
				Npart 		= 27;
				NpartErr 	= 8;
			}
			else if (cent == 8){
				Npart 		= 14;
				NpartErr 	= 6;
			}
		}
		if (en == 39){
			if (cent == 0){
				Npart 		= 342;
				NpartErr 	= 2;
			}
			else if (cent == 1){
				Npart 		= 294;
				NpartErr 	= 6;
			}
			else if (cent == 2){
				Npart 		= 230;
				NpartErr	= 9;
			}
			else if (cent == 3){
				Npart 		= 162;
				NpartErr 	= 10;
			}
			else if (cent == 4){
				Npart 		= 111;
				NpartErr 	= 11;
			}
			else if (cent == 5){
				Npart 		= 74;
				NpartErr 	= 10;
			}
			else if (cent == 6){
				Npart 		= 46;
				NpartErr	= 9;
			}
			else if (cent == 7){
				Npart 		= 26;
				NpartErr 	= 7;
			}
			else if (cent == 8){
				Npart 		= 14;
				NpartErr 	= 5;
			}
		}
		if (en == 62.4){
			if (cent == 0){
				Npart 		= 347;
				NpartErr 	= 3;
			}
			else if (cent == 1){
				Npart 		= 294;
				NpartErr 	= 4;
			}
			else if (cent == 2){
				Npart 		= 230;
				NpartErr	= 5;
			}
			else if (cent == 3){
				Npart 		= 164;
				NpartErr 	= 5;
			}
			else if (cent == 4){
				Npart 		= 114;
				NpartErr 	= 5;
			}
			else if (cent == 5){
				Npart 		= 76;
				NpartErr 	= 5;
			}
			else if (cent == 6){
				Npart 		= 48;
				NpartErr	= 5;
			}
			else if (cent == 7){
				Npart 		= 28;
				NpartErr 	= 3;
			}
			else if (cent == 8){
				Npart 		= 15;
				NpartErr 	= 2;
			}
		}
		if (en == 130){
			if (cent == 0){
				Npart 		= 344;
				NpartErr 	= 3;
			}
			else if (cent == 1){
				Npart 		= 289;
				NpartErr 	= 5;
			}
			else if (cent == 2){
				Npart 		= 237;
				NpartErr	= 7;
			}
			else if (cent == 3){
				Npart 		= 187;
				NpartErr 	= 8;
			}
			else if (cent == 4){
				Npart 		= 141;
				NpartErr 	= 8;
			}
			else if (cent == 5){
				Npart 		= 100;
				NpartErr 	= 9;
			}
			else if (cent == 6){
				Npart 		= 61;
				NpartErr	= 8;
			}
			else if (cent == 7){
				Npart 		= 23;
				NpartErr 	= 5;
			}
}
		
		if (en == 200){
			if (cent == 0){
				Npart 		= 350;
				NpartErr 	= 3;
			}
			else if (cent == 1){
				Npart 		= 299;
				NpartErr	= 4;
			}
			else if (cent == 2){
				Npart 		= 234;
				NpartErr 	= 5;
			}


			else if (cent == 3){
					Npart 		= 168;
					NpartErr 	= 5;
				}
			else if (cent == 4){
					Npart 		= 117;
					NpartErr 	= 5;
				}
			else if (cent == 5){
					Npart 		= 78;
					NpartErr	= 5;
				}
			else if (cent == 6){
					Npart 		= 49;
					NpartErr 	= 5;
				}
			else if (cent == 7){
					Npart 		= 29;
					NpartErr 	= 4;
				}
			else if (cent == 8){
					Npart 		= 16;
					NpartErr 	= 3;
				}
		
		}
	static Int_t npartAndErrArr[2];// first element is Npart, second Npart_err
	npartAndErrArr[0] = Npart;
	npartAndErrArr[1] = NpartErr;

	return npartAndErrArr;
}
