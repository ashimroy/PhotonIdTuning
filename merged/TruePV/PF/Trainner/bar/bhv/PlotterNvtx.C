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

void PlotterNvtx(){


  gROOT->ProcessLine(" .L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  TFile *f11 = TFile::Open("Eff1.root");

  //Loose
  TH1F *SieaftNvtxL  = new TH1F("SieaftNvtxL","Sieie cut only",100,0,100); 
  TH1F *ToEaftNvtxL  = new TH1F("ToEaftNvtxL","HoE cut only",100,0,100); 
  TH1F *IsoPaftNvtxL = new TH1F("IsoPaftNvtxL","IsoP cut only",100,0,100); 
  TH1F *IsoCaftNvtxL = new TH1F("IsoCaftNvtxL","IsoC cut only",100,0,100); 
  TH1F *IsoNaftNvtxL = new TH1F("IsoNaftNvtxL","IsoN cut only",100,0,100); 

  TH1F *SieaftbNvtxL  = new TH1F("SieaftbNvtxL","Sieie cut only",100,0,100); 
  TH1F *ToEaftbNvtxL  = new TH1F("ToEaftbNvtxL","HoE cut only",100,0,100); 
  TH1F *IsoPaftbNvtxL = new TH1F("IsoPaftbNvtxL","IsoP cut only",100,0,100); 
  TH1F *IsoCaftbNvtxL = new TH1F("IsoCaftbNvtxL","IsoC cut only",100,0,100); 
  TH1F *IsoNaftbNvtxL = new TH1F("IsoNaftbNvtxL","IsoN cut only",100,0,100); 

  SieaftNvtxL->Divide(EffNVTXs,EffNVTX0,1.,1.,"B"); 
  ToEaftNvtxL->Divide(EffNVTXt,EffNVTX0,1.,1.,"B");
  IsoPaftNvtxL->Divide(EffNVTXp,EffNVTX0,1.,1.,"B");
  IsoCaftNvtxL->Divide(EffNVTXc,EffNVTX0,1.,1.,"B");
  IsoNaftNvtxL->Divide(EffNVTXn,EffNVTX0,1.,1.,"B");

  SieaftbNvtxL->Divide(EffNVTXbs,EffNVTX0b,1.,1.,"B"); 
  ToEaftbNvtxL->Divide(EffNVTXbt,EffNVTX0b,1.,1.,"B");
  IsoPaftbNvtxL->Divide(EffNVTXbp,EffNVTX0b,1.,1.,"B");
  IsoCaftbNvtxL->Divide(EffNVTXbc,EffNVTX0b,1.,1.,"B");
  IsoNaftbNvtxL->Divide(EffNVTXbn,EffNVTX0b,1.,1.,"B");

  
  TCanvas *c11 = new TCanvas("c11","Branch Out Cuts",900,600);
  c11->Divide(3,2);
  
  c11->cd(1);  
  SieaftNvtxL->Draw();
  SieaftbNvtxL->Draw("same");
  SieaftNvtxL->SetMarkerSize(0.5);
  SieaftbNvtxL->SetMarkerSize(0.5);
  SieaftbNvtxL->SetMarkerColor(kRed);
  SieaftNvtxL->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  SieaftNvtxL->GetXaxis()->SetTitle("# Nvtx");
 
  c11->cd(2);
  ToEaftNvtxL->Draw();
  ToEaftbNvtxL->Draw("same");
  ToEaftNvtxL->SetMarkerSize(0.5);
  ToEaftbNvtxL->SetMarkerSize(0.5);
  ToEaftbNvtxL->SetMarkerColor(kRed);
  ToEaftNvtxL->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaftNvtxL->GetXaxis()->SetTitle("# Nvtx");

  c11->cd(3);
  IsoPaftNvtxL->Draw();
  IsoPaftbNvtxL->Draw("same");
  IsoPaftNvtxL->SetMarkerSize(0.5);
  IsoPaftbNvtxL->SetMarkerColor(kRed);
  IsoPaftbNvtxL->SetMarkerSize(0.5);
  IsoPaftNvtxL->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaftNvtxL->GetXaxis()->SetTitle("# Nvtx");

  c11->cd(4);
  IsoCaftNvtxL->Draw();
  IsoCaftbNvtxL->Draw("same");
  IsoCaftNvtxL->SetMarkerSize(0.5);
  IsoCaftbNvtxL->SetMarkerColor(kRed);
  IsoCaftbNvtxL->SetMarkerSize(0.5);
  IsoCaftNvtxL->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaftNvtxL->GetXaxis()->SetTitle("# Nvtx");
  
  c11->cd(5);
  IsoNaftNvtxL->Draw();
  IsoNaftbNvtxL->Draw("same");
  IsoNaftNvtxL->SetMarkerSize(0.5);
  IsoNaftbNvtxL->SetMarkerSize(0.5);
  IsoNaftbNvtxL->SetMarkerColor(kRed);
  IsoNaftNvtxL->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaftNvtxL->GetXaxis()->SetTitle("# Nvtx");
  
  c11->SaveAs("BranchOutCutsNVTXLWP.png");




  //Medium
  TH1F *SieaftNvtxM  = new TH1F("SieaftNvtxM","Sieie cut only",100,0,100); 
  TH1F *ToEaftNvtxM  = new TH1F("ToEaftNvtxM","HoE cut only",100,0,100); 
  TH1F *IsoPaftNvtxM = new TH1F("IsoPaftNvtxM","IsoP cut only",100,0,100); 
  TH1F *IsoCaftNvtxM = new TH1F("IsoCaftNvtxM","IsoC cut only",100,0,100); 
  TH1F *IsoNaftNvtxM = new TH1F("IsoNaftNvtxM","IsoN cut only",100,0,100); 

  TH1F *SieaftbNvtxM  = new TH1F("SieaftbNvtxM","Sieie cut only",100,0,100); 
  TH1F *ToEaftbNvtxM  = new TH1F("ToEaftbNvtxM","HoE cut only",100,0,100); 
  TH1F *IsoPaftbNvtxM = new TH1F("IsoPaftbNvtxM","IsoP cut only",100,0,100); 
  TH1F *IsoCaftbNvtxM = new TH1F("IsoCaftbNvtxM","IsoC cut only",100,0,100); 
  TH1F *IsoNaftbNvtxM = new TH1F("IsoNaftbNvtxM","IsoN cut only",100,0,100); 

  SieaftNvtxM->Divide(EffNVTXMs,EffNVTX0,1.,1.,"B"); 
  ToEaftNvtxM->Divide(EffNVTXMt,EffNVTX0,1.,1.,"B");
  IsoPaftNvtxM->Divide(EffNVTXMp,EffNVTX0,1.,1.,"B");
  IsoCaftNvtxM->Divide(EffNVTXMc,EffNVTX0,1.,1.,"B");
  IsoNaftNvtxM->Divide(EffNVTXMn,EffNVTX0,1.,1.,"B");

  SieaftbNvtxM->Divide(EffNVTXMbs,EffNVTX0b,1.,1.,"B"); 
  ToEaftbNvtxM->Divide(EffNVTXMbt,EffNVTX0b,1.,1.,"B");
  IsoPaftbNvtxM->Divide(EffNVTXMbp,EffNVTX0b,1.,1.,"B");
  IsoCaftbNvtxM->Divide(EffNVTXMbc,EffNVTX0b,1.,1.,"B");
  IsoNaftbNvtxM->Divide(EffNVTXMbn,EffNVTX0b,1.,1.,"B");

  
  TCanvas *c22 = new TCanvas("c22","Branch Out Cuts",900,600);
  c22->Divide(3,2);
  
  c22->cd(1);  
  SieaftNvtxM->Draw();
  SieaftbNvtxM->Draw("same");
  SieaftNvtxM->SetMarkerSize(0.5);
  SieaftbNvtxM->SetMarkerSize(0.5);
  SieaftbNvtxM->SetMarkerColor(kRed);
  SieaftNvtxM->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  SieaftNvtxM->GetXaxis()->SetTitle("# Nvtx");
 
  c22->cd(2);
  ToEaftNvtxM->Draw();
  ToEaftbNvtxM->Draw("same");
  ToEaftNvtxM->SetMarkerSize(0.5);
  ToEaftbNvtxM->SetMarkerSize(0.5);
  ToEaftbNvtxM->SetMarkerColor(kRed);
  ToEaftNvtxM->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaftNvtxM->GetXaxis()->SetTitle("# Nvtx");

  c22->cd(3);
  IsoPaftNvtxM->Draw();
  IsoPaftbNvtxM->Draw("same");
  IsoPaftNvtxM->SetMarkerSize(0.5);
  IsoPaftbNvtxM->SetMarkerColor(kRed);
  IsoPaftbNvtxM->SetMarkerSize(0.5);
  IsoPaftNvtxM->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaftNvtxM->GetXaxis()->SetTitle("# Nvtx");

  c22->cd(4);
  IsoCaftNvtxM->Draw();
  IsoCaftbNvtxM->Draw("same");
  IsoCaftNvtxM->SetMarkerSize(0.5);
  IsoCaftbNvtxM->SetMarkerColor(kRed);
  IsoCaftbNvtxM->SetMarkerSize(0.5);
  IsoCaftNvtxM->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaftNvtxM->GetXaxis()->SetTitle("# Nvtx");
  
  c22->cd(5);
  IsoNaftNvtxM->Draw();
  IsoNaftbNvtxM->Draw("same");
  IsoNaftNvtxM->SetMarkerSize(0.5);
  IsoNaftbNvtxM->SetMarkerSize(0.5);
  IsoNaftbNvtxM->SetMarkerColor(kRed);
  IsoNaftNvtxM->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaftNvtxM->GetXaxis()->SetTitle("# Nvtx");

  c22->SaveAs("BranchOutCutsNVTXMWP.png");



  //Tight
  TH1F *SieaftNvtxT  = new TH1F("SieaftNvtxT","Sieie cut only",100,0,100); 
  TH1F *ToEaftNvtxT  = new TH1F("ToEaftNvtxT","HoE cut only",100,0,100); 
  TH1F *IsoPaftNvtxT = new TH1F("IsoPaftNvtxT","IsoP cut only",100,0,100); 
  TH1F *IsoCaftNvtxT = new TH1F("IsoCaftNvtxT","IsoC cut only",100,0,100); 
  TH1F *IsoNaftNvtxT = new TH1F("IsoNaftNvtxT","IsoN cut only",100,0,100); 

  TH1F *SieaftbNvtxT  = new TH1F("SieaftbNvtxT","Sieie cut only",100,0,100); 
  TH1F *ToEaftbNvtxT  = new TH1F("ToEaftbNvtxT","HoE cut only",100,0,100); 
  TH1F *IsoPaftbNvtxT = new TH1F("IsoPaftbNvtxT","IsoP cut only",100,0,100); 
  TH1F *IsoCaftbNvtxT = new TH1F("IsoCaftbNvtxT","IsoC cut only",100,0,100); 
  TH1F *IsoNaftbNvtxT = new TH1F("IsoNaftbNvtxT","IsoN cut only",100,0,100); 

  SieaftNvtxT->Divide(EffNVTXTs,EffNVTX0,1.,1.,"B"); 
  ToEaftNvtxT->Divide(EffNVTXTt,EffNVTX0,1.,1.,"B");
  IsoPaftNvtxT->Divide(EffNVTXTp,EffNVTX0,1.,1.,"B");
  IsoCaftNvtxT->Divide(EffNVTXTc,EffNVTX0,1.,1.,"B");
  IsoNaftNvtxT->Divide(EffNVTXTn,EffNVTX0,1.,1.,"B");

  SieaftbNvtxT->Divide(EffNVTXTbs,EffNVTX0b,1.,1.,"B"); 
  ToEaftbNvtxT->Divide(EffNVTXTbt,EffNVTX0b,1.,1.,"B");
  IsoPaftbNvtxT->Divide(EffNVTXTbp,EffNVTX0b,1.,1.,"B");
  IsoCaftbNvtxT->Divide(EffNVTXTbc,EffNVTX0b,1.,1.,"B");
  IsoNaftbNvtxT->Divide(EffNVTXTbn,EffNVTX0b,1.,1.,"B");

  
  TCanvas *c33 = new TCanvas("c33","Branch Out Cuts",900,600);
  c33->Divide(3,2);
  
  c33->cd(1);  
  SieaftNvtxT->Draw();
  SieaftbNvtxT->Draw("same");
  SieaftNvtxT->SetMarkerSize(0.5);
  SieaftbNvtxT->SetMarkerSize(0.5);
  SieaftbNvtxT->SetMarkerColor(kRed);
  SieaftNvtxT->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  SieaftNvtxT->GetXaxis()->SetTitle("# Nvtx");
 
  c33->cd(2);
  ToEaftNvtxT->Draw();
  ToEaftbNvtxT->Draw("same");
  ToEaftNvtxT->SetMarkerSize(0.5);
  ToEaftbNvtxT->SetMarkerSize(0.5);
  ToEaftbNvtxT->SetMarkerColor(kRed);
  ToEaftNvtxT->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaftNvtxT->GetXaxis()->SetTitle("# Nvtx");

  c33->cd(3);
  IsoPaftNvtxT->Draw();
  IsoPaftbNvtxT->Draw("same");
  IsoPaftNvtxT->SetMarkerSize(0.5);
  IsoPaftbNvtxT->SetMarkerColor(kRed);
  IsoPaftbNvtxT->SetMarkerSize(0.5);
  IsoPaftNvtxT->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaftNvtxT->GetXaxis()->SetTitle("# Nvtx");

  c33->cd(4);
  IsoCaftNvtxT->Draw();
  IsoCaftbNvtxT->Draw("same");
  IsoCaftNvtxT->SetMarkerSize(0.5);
  IsoCaftbNvtxT->SetMarkerColor(kRed);
  IsoCaftbNvtxT->SetMarkerSize(0.5);
  IsoCaftNvtxT->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaftNvtxT->GetXaxis()->SetTitle("# Nvtx");
  
  c33->cd(5);
  IsoNaftNvtxT->Draw();
  IsoNaftbNvtxT->Draw("same");
  IsoNaftNvtxT->SetMarkerSize(0.5);
  IsoNaftbNvtxT->SetMarkerSize(0.5);
  IsoNaftbNvtxT->SetMarkerColor(kRed);
  IsoNaftNvtxT->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaftNvtxT->GetXaxis()->SetTitle("# Nvtx");

  c33->SaveAs("BranchOutCutsNVTXTWP.png");
}
