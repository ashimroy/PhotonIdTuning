#include <cstdlib>
#include <iostream> 
#include <map>
#include <string>
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/GeneticAlgorithm.h"
#include "TMVA/GeneticFitter.h"
#include "TMVA/IFitterTarget.h"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"

 
#include <sstream>
#include <string.h>
#include <fstream>

void EtaBranch(){


  gROOT->ProcessLine(" .L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  
  TH1F *SieaftE  = new TH1F("SieaftE","Sieie cut only",100,-5,5); 
  TH1F *ToEaftE  = new TH1F("ToEaftE","HoE cut only",100,-5,5); 
  TH1F *IsoPaftE = new TH1F("IsoPaftE","IsoP cut only",100,-5,5); 
  TH1F *IsoCaftE = new TH1F("IsoCaftE","IsoC cut only",100,-5,5); 
  TH1F *IsoNaftE = new TH1F("IsoNaftE","IsoN cut only",100,-5,5); 

  TH1F *SieaftbE  = new TH1F("SieaftbE","Sieie cut only",100,-5,5); 
  TH1F *ToEaftbE  = new TH1F("ToEaftbE","HoE cut only",100,-5,5); 
  TH1F *IsoPaftbE = new TH1F("IsoPaftbE","IsoP cut only",100,-5,5); 
  TH1F *IsoCaftbE = new TH1F("IsoCaftbE","IsoC cut only",100,-5,5); 
  TH1F *IsoNaftbE = new TH1F("IsoNaftbE","IsoN cut only",100,-5,5); 





  
  SieaftE->Divide(EffETAs,EffETA0,1.,1.,"B"); 
  ToEaftE->Divide(EffETAt,EffETA0,1.,1.,"B");
  IsoPaftE->Divide(EffETAp,EffETA0,1.,1.,"B");
  IsoCaftE->Divide(EffETAc,EffETA0,1.,1.,"B");
  IsoNaftE->Divide(EffETAn,EffETA0,1.,1.,"B");


  SieaftbE->Divide(EffETAbs,EffETA0b,1.,1.,"B"); 
  ToEaftbE->Divide(EffETAbt,EffETA0b,1.,1.,"B");
  IsoPaftbE->Divide(EffETAbp,EffETA0b,1.,1.,"B");
  IsoCaftbE->Divide(EffETAbc,EffETA0b,1.,1.,"B");
  IsoNaftbE->Divide(EffETAbn,EffETA0b,1.,1.,"B");







  TCanvas *c12 = new TCanvas("c12","Branch Out Cuts",900,600);
  c12->Divide(3,2);
  
  c12->cd(1);  

  SieaftE->Draw();
  SieaftbE->Draw("same");
  SieaftE->SetMarkerSize(0.5);
  SieaftbE->SetMarkerSize(0.5);
  SieaftbE->SetMarkerColor(kRed);
  SieaftE->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  SieaftE->GetXaxis()->SetTitle("#eta");
 
  c12->cd(2);
  ToEaftE->Draw();
  ToEaftbE->Draw("same");
  ToEaftE->SetMarkerSize(0.5);
  ToEaftbE->SetMarkerSize(0.5);
  ToEaftbE->SetMarkerColor(kRed);
  ToEaftE->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaftE->GetXaxis()->SetTitle("#eta");

  c12->cd(3);
  IsoPaftE->Draw();
  IsoPaftbE->Draw("same");
  IsoPaftE->SetMarkerSize(0.5);
  IsoPaftbE->SetMarkerColor(kRed);
  IsoPaftbE->SetMarkerSize(0.5);
  IsoPaftE->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaftE->GetXaxis()->SetTitle("#eta");

  c12->cd(4);
  IsoCaftE->Draw();
  IsoCaftbE->Draw("same");
  IsoCaftE->SetMarkerSize(0.5);
  IsoCaftbE->SetMarkerColor(kRed);
  IsoCaftbE->SetMarkerSize(0.5);
  IsoCaftE->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaftE->GetXaxis()->SetTitle("#eta");
  
  c12->cd(5);
  IsoNaftE->Draw();
  IsoNaftbE->Draw("same");
  IsoNaftE->SetMarkerSize(0.5);
  IsoNaftbE->SetMarkerSize(0.5);
  IsoNaftbE->SetMarkerColor(kRed);
  IsoNaftE->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaftE->GetXaxis()->SetTitle("#eta");
  
  c12->SaveAs("BranchOutCutsEtacomb.png");






}
