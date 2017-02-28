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

void Plotter(){


  gROOT->ProcessLine(" .L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  TH1F *Letas = new TH1F("Letas","Loose Cut Efficiency Eta",100,-5,5);
  TH1F *Metas = new TH1F("Metas","Medium Cut Efficiency Eta",100,-5,5);
  TH1F *Tetas = new TH1F("Tetas","Tight Cut Efficiency Eta",100,-5,5); 

  TH1F *Lpts = new TH1F("Lpts","Loose Cut Efficiency pt",100,0,200);
  TH1F *Mpts = new TH1F("Mpts","Medium Cut Efficiency pt",100,0,200);
  TH1F *Tpts = new TH1F("Tpts","Tight Cut Efficiency pt",100,0,200); 

  TH1F *Lnvtxs = new TH1F("Lnvtxs","Loose Cut Efficiency vertices",100,0,100);
  TH1F *Mnvtxs = new TH1F("Mnvtxs","Medium Cut Efficiency vertices",100,0,100);
  TH1F *Tnvtxs = new TH1F("Tnvtxs","Tight Cut Efficiency vertices",100,0,100); 


  TH1F *Letab = new TH1F("Letab","Loose Cut b Efficiency Eta",100,-5,5);
  TH1F *Metab = new TH1F("Metab","Medium Cut b Efficiency Eta",100,-5,5);
  TH1F *Tetab = new TH1F("Tetab","Tight Cut b Efficiency Eta",100,-5,5); 


  TH1F *Lptb = new TH1F("Lptb","Loose Cut b Efficiency pt",100,0,200);
  TH1F *Mptb = new TH1F("Mptb","Medium Cut b Efficiency pt",100,0,200);
  TH1F *Tptb = new TH1F("Tptb","Tight Cut b Efficiency pt",100,0,200); 


  
  TH1F *Lnvtxb = new TH1F("Lnvtxb","Loose Cut b  Efficiency vertices",100,0,100);
  TH1F *Mnvtxb = new TH1F("Mnvtxb","Medium Cut b Efficiency vertices",100,0,100);
  TH1F *Tnvtxb = new TH1F("Tnvtxb","Tight Cut b Efficiency vertices",100,0,100); 


  TH1F *Sieaft  = new TH1F("Sieaft","Sieie cut only",100,0,200); 
  TH1F *ToEaft  = new TH1F("ToEaft","HoE cut only",100,0,200); 
  TH1F *IsoPaft = new TH1F("IsoPaft","IsoP cut only",100,0,200); 
  TH1F *IsoCaft = new TH1F("IsoCaft","IsoC cut only",100,0,200); 
  TH1F *IsoNaft = new TH1F("IsoNaft","IsoN cut only",100,0,200); 


  TH1F *Sieaft  = new TH1F("Sieaft","Sieie cut only",100,0,200); 
  TH1F *ToEaft  = new TH1F("ToEaft","HoE cut only",100,0,200); 
  TH1F *IsoPaft = new TH1F("IsoPaft","IsoP cut only",100,0,200); 
  TH1F *IsoCaft = new TH1F("IsoCaft","IsoC cut only",100,0,200); 
  TH1F *IsoNaft = new TH1F("IsoNaft","IsoN cut only",100,0,200); 


  TH1F *SieaftM  = new TH1F("SieaftM","Sieie cut only",100,0,200); 
  TH1F *ToEaftM  = new TH1F("ToEaftM","HoE cut only",100,0,200); 
  TH1F *IsoPaftM = new TH1F("IsoPaftM","IsoP cut only",100,0,200); 
  TH1F *IsoCaftM = new TH1F("IsoCaftM","IsoC cut only",100,0,200); 
  TH1F *IsoNaftM = new TH1F("IsoNaftM","IsoN cut only",100,0,200); 


  TH1F *SieaftT  = new TH1F("SieaftT","Sieie cut only",100,0,200); 
  TH1F *ToEaftT  = new TH1F("ToEaftT","HoE cut only",100,0,200); 
  TH1F *IsoPaftT = new TH1F("IsoPaftT","IsoP cut only",100,0,200); 
  TH1F *IsoCaftT = new TH1F("IsoCaftT","IsoC cut only",100,0,200); 
  TH1F *IsoNaftT = new TH1F("IsoNaftT","IsoN cut only",100,0,200); 


  TH1F *Sieaftb  = new TH1F("Sieaftb","Sieie cut only",100,0,200); 
  TH1F *ToEaftb  = new TH1F("ToEaftb","HoE cut only",100,0,200); 
  TH1F *IsoPaftb = new TH1F("IsoPaftb","IsoP cut only",100,0,200); 
  TH1F *IsoCaftb = new TH1F("IsoCaftb","IsoC cut only",100,0,200); 
  TH1F *IsoNaftb = new TH1F("IsoNaftb","IsoN cut only",100,0,200); 

  TH1F *SieaftN  = new TH1F("SieaftN","Sieie cut only",100,0,100); 
  TH1F *ToEaftN  = new TH1F("ToEaftN","HoE cut only",100,0,100); 
  TH1F *IsoPaftN = new TH1F("IsoPaftN","IsoP cut only",100,0,100); 
  TH1F *IsoCaftN = new TH1F("IsoCaftN","IsoC cut only",100,0,100); 
  TH1F *IsoNaftN = new TH1F("IsoNaftN","IsoN cut only",100,0,100); 

  TH1F *SieaftbN  = new TH1F("SieaftbN","Sieie cut only",100,0,100); 
  TH1F *ToEaftbN  = new TH1F("ToEaftbN","HoE cut only",100,0,100); 
  TH1F *IsoPaftbN = new TH1F("IsoPaftbN","IsoP cut only",100,0,100); 
  TH1F *IsoCaftbN = new TH1F("IsoCaftbN","IsoC cut only",100,0,100); 
  TH1F *IsoNaftbN = new TH1F("IsoNaftbN","IsoN cut only",100,0,100); 

  
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










  Letas->Divide(EffETALb,EffETA0,1.,1.,"B");
  Metas->Divide(EffETAMb,EffETA0,1.,1.,"B");
  Tetas->Divide(EffETATb,EffETA0,1.,1.,"B");
  
  Letab->Divide(EffETALb,EffETA0b,1.,1.,"B");
  Metab->Divide(EffETAMb,EffETA0b,1.,1.,"B");
  Tetab->Divide(EffETATb,EffETA0b,1.,1.,"B");
  

  Lpts->Divide(EffPTL,EffPT0,1.,1.,"B");
  Mpts->Divide(EffPTM,EffPT0,1.,1.,"B");
  Tpts->Divide(EffPTT,EffPT0,1.,1.,"B");

  
  Lptb->Divide(EffPTLb,EffPT0b,1.,1.,"B");
  Mptb->Divide(EffPTMb,EffPT0b,1.,1.,"B");
  Tptb->Divide(EffPTTb,EffPT0b,1.,1.,"B");

  Lnvtxs->Divide(EffNVTXL,EffNVTX0,1.,1.,"B");
  Mnvtxs->Divide(EffNVTXM,EffNVTX0,1.,1.,"B");
  Tnvtxs->Divide(EffNVTXT,EffNVTX0,1.,1.,"B");

  
  Lnvtxb->Divide(EffNVTXL,EffNVTX0b,1.,1.,"B");
  Mnvtxb->Divide(EffNVTXM,EffNVTX0b,1.,1.,"B");
  Tnvtxb->Divide(EffNVTXT,EffNVTX0b,1.,1.,"B");


  // the branch  out cuts 


  Sieaft->Divide(EffPTs,EffPT0,1.,1.,"B"); 
  ToEaft->Divide(EffPTt,EffPT0,1.,1.,"B");
  IsoPaft->Divide(EffPTp,EffPT0,1.,1.,"B");
  IsoCaft->Divide(EffPTc,EffPT0,1.,1.,"B");
  IsoNaft->Divide(EffPTn,EffPT0,1.,1.,"B");

  SieaftM->Divide(EffPTMs,EffPT0,1.,1.,"B"); 
  ToEaftM->Divide(EffPTMt,EffPT0,1.,1.,"B");
  IsoPaftM->Divide(EffPTMp,EffPT0,1.,1.,"B");
  IsoCaftM->Divide(EffPTMc,EffPT0,1.,1.,"B");
  IsoNaftM->Divide(EffPTMn,EffPT0,1.,1.,"B");

  SieaftT->Divide(EffPTTs,EffPT0,1.,1.,"B"); 
  ToEaftT->Divide(EffPTTt,EffPT0,1.,1.,"B");
  IsoPaftT->Divide(EffPTTp,EffPT0,1.,1.,"B");
  IsoCaftT->Divide(EffPTTc,EffPT0,1.,1.,"B");
  IsoNaftT->Divide(EffPTTn,EffPT0,1.,1.,"B");


  Sieaftb->Divide(EffPTbs,EffPT0b,1.,1.,"B"); 
  ToEaftb->Divide(EffPTbt,EffPT0b,1.,1.,"B");
  IsoPaftb->Divide(EffPTbp,EffPT0b,1.,1.,"B");
  IsoCaftb->Divide(EffPTbc,EffPT0b,1.,1.,"B");
  IsoNaftb->Divide(EffPTbn,EffPT0b,1.,1.,"B");


  
  SieaftN->Divide(EffNVTXs,EffNVTX0,1.,1.,"B"); 
  ToEaftN->Divide(EffNVTXt,EffNVTX0,1.,1.,"B");
  IsoPaftN->Divide(EffNVTXp,EffNVTX0,1.,1.,"B");
  IsoCaftN->Divide(EffNVTXc,EffNVTX0,1.,1.,"B");
  IsoNaftN->Divide(EffNVTXn,EffNVTX0,1.,1.,"B");


  SieaftbN->Divide(EffNVTXbs,EffNVTX0b,1.,1.,"B"); 
  ToEaftbN->Divide(EffNVTXbt,EffNVTX0b,1.,1.,"B");
  IsoPaftbN->Divide(EffNVTXbp,EffNVTX0b,1.,1.,"B");
  IsoCaftbN->Divide(EffNVTXbc,EffNVTX0b,1.,1.,"B");
  IsoNaftbN->Divide(EffNVTXbn,EffNVTX0b,1.,1.,"B");


  
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








  
  TCanvas *c1  = new TCanvas("c1","Medium",600,600);
  c1->Divide(2,2);

  c1->cd(1);
  Mnvtxs->Draw();
  Mnvtxs->GetYaxis()->SetRangeUser(0,1.0);
 
  Mnvtxs->GetXaxis()->SetRangeUser(0,50);
 
  Mnvtxs->GetXaxis()->SetTitle("# Nvtx");
  Mnvtxs->SetLineColor(kRed);
  Mnvtxs->SetMarkerColor(kRed);
  Mnvtxs->SetMarkerSize(0.5);
  Mnvtxb->SetMarkerSize(0.5);
  Mnvtxb->Draw("same");
  
  c1->cd(2);
  Mpts->Draw();
  Mpts->GetYaxis()->SetRangeUser(0,1.0);
 
  Mpts->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  Mpts->SetLineColor(kRed);
  Mpts->SetMarkerColor(kRed);
  Mpts->SetMarkerSize(0.5);
  Mptb->SetMarkerSize(0.5);
  Mptb->Draw("same");

  c1->cd(3);
  Metas->Draw();
  Metas->GetYaxis()->SetRangeUser(0,1.0);
  Metas->GetXaxis()->SetRangeUser(1.5,3.0);
 
  Metas->GetXaxis()->SetTitle("#eta");
  Metas->SetLineColor(kRed);
  Metas->SetMarkerColor(kRed);
  Metas->SetMarkerSize(0.5);
  Metab->SetMarkerSize(0.5);
  Metab->Draw("same");
  c1->SaveAs("MediumEffBck.png");

  TCanvas *c2  = new TCanvas("c2","Loose",600,600);
  c2->Divide(2,2);

  c2->cd(1);
  Lnvtxs->Draw();
  Lnvtxs->GetXaxis()->SetTitle("# Nvtx");
  Lnvtxs->GetYaxis()->SetRangeUser(0,1.0);
  Lnvtxs->GetXaxis()->SetRangeUser(0,50);

  Lnvtxs->SetLineColor(kRed);
  Lnvtxs->SetMarkerColor(kRed);
  Lnvtxs->SetMarkerSize(0.5);
  Lnvtxb->SetMarkerSize(0.5);
  Lnvtxb->Draw("esame");
  
  c2->cd(2);
  Lpts->Draw();
  Lpts->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  Lpts->GetYaxis()->SetRangeUser(0,1.0);
  Lpts->SetLineColor(kRed);
  Lpts->SetMarkerColor(kRed);
  Lpts->SetMarkerSize(0.5);
  Lptb->SetMarkerSize(0.5);
  Lptb->Draw("esame");



  c2->cd(3);
  Letas->Draw();
  Letas->GetXaxis()->SetTitle("#eta");
  Letas->GetYaxis()->SetRangeUser(0,1.0);
  Letas->GetXaxis()->SetRangeUser(1.5,3.0);
  
  Letas->SetLineColor(kRed);
  Letas->SetMarkerColor(kRed);
  Letas->SetMarkerSize(0.5);
  Letab->SetMarkerSize(0.5);

  Letab->Draw("esame");
  


  c2->SaveAs("LooseEffBck.png");




  TCanvas *c3  = new TCanvas("c3","Tight",600,600);
  c3->Divide(2,2);

  c3->cd(1);
  Tnvtxs->Draw();
  Tnvtxs->GetYaxis()->SetRangeUser(0,1.0);
  Tnvtxs->GetXaxis()->SetRangeUser(0,50);
 
  Tnvtxs->GetXaxis()->SetTitle("# Nvtx");
  Tnvtxs->SetLineColor(kRed);
  Tnvtxs->SetMarkerColor(kRed);
  Tnvtxs->SetMarkerSize(0.5);
  Tnvtxb->SetMarkerSize(0.5);

  Tnvtxb->Draw("esame");
  
  c3->cd(2);
  Tpts->Draw();
  Tpts->GetYaxis()->SetRangeUser(0,1.0);
  
  Tpts->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  Tpts->SetLineColor(kRed);
  Tpts->SetMarkerColor(kRed);
  Tpts->SetMarkerSize(0.5);
  Tptb->SetMarkerSize(0.5);
  Tptb->Draw("esame");



  c3->cd(3);
  Tetas->Draw();
  Tetas->GetYaxis()->SetRangeUser(0,1.0);
 
  Tetas->GetXaxis()->SetTitle("#eta");
  Tetas->GetXaxis()->SetRangeUser(1.5,3.0);
  Tetas->SetLineColor(kRed);
  Tetas->SetMarkerColor(kRed);
  Tetas->SetMarkerSize(0.5);
  Tetab->SetMarkerSize(0.5);

  Tetab->Draw("same");
  c3->SaveAs("TightEffBck.png");

 


  TCanvas *c10 = new TCanvas("c10","Branch Out Cuts",900,600);
  c10->Divide(3,2);
  
  c10->cd(1);  

  Sieaft->Draw();
  Sieaftb->Draw("same");
  Sieaft->SetMarkerSize(0.5);
  Sieaftb->SetMarkerSize(0.5);
  Sieaftb->SetMarkerColor(kRed);
  Sieaft->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  Sieaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
 
  c10->cd(2);
  ToEaft->Draw();
  ToEaftb->Draw("same");
  ToEaft->SetMarkerSize(0.5);
  ToEaftb->SetMarkerSize(0.5);
  ToEaftb->SetMarkerColor(kRed);
  ToEaft->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c10->cd(3);
  IsoPaft->Draw();
  IsoPaftb->Draw("same");
  IsoPaft->SetMarkerSize(0.5);
  IsoPaftb->SetMarkerColor(kRed);
  IsoPaftb->SetMarkerSize(0.5);
  IsoPaft->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c10->cd(4);
  IsoCaft->Draw();
  IsoCaftb->Draw("same");
  IsoCaft->SetMarkerSize(0.5);
  IsoCaftb->SetMarkerColor(kRed);
  IsoCaftb->SetMarkerSize(0.5);
  IsoCaft->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c10->cd(5);
  IsoNaft->Draw();
  IsoNaftb->Draw("same");
  IsoNaft->SetMarkerSize(0.5);
  IsoNaftb->SetMarkerSize(0.5);
  IsoNaftb->SetMarkerColor(kRed);
  IsoNaft->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c10->SaveAs("BranchOutCuts.png");

 
  TCanvas *c20 = new TCanvas("c20","Branch Out Cuts",900,600);
  c20->Divide(3,2);
  
  c20->cd(1);  

  Sieaft->Draw();
  SieaftM->Draw("same");
  SieaftT->Draw("same");
  Sieaft->SetMarkerSize(0.5);
  SieaftM->SetMarkerSize(0.5);
  SieaftT->SetMarkerSize(0.5);
 
  SieaftM->SetMarkerColor(kOrange -3);
  SieaftT->SetMarkerColor(kYellow);
  Sieaft->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  Sieaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
 
  c20->cd(2);
  
  ToEaft->Draw();
  ToEaftM->Draw("same");
  ToEaftT->Draw("same");
  ToEaft->SetMarkerSize(0.5);
  ToEaftM->SetMarkerSize(0.5);
  ToEaftT->SetMarkerSize(0.5);
 
  ToEaftM->SetMarkerColor(kOrange -3);
  ToEaftT->SetMarkerColor(kYellow);
  ToEaft->GetYaxis()->SetTitle("Only H over E Cut Efficiency");
  ToEaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c20->cd(3);

  IsoPaft->Draw();
  IsoPaftM->Draw("same");
  IsoPaftT->Draw("same");
  IsoPaft->SetMarkerSize(0.5);
  IsoPaftM->SetMarkerSize(0.5);
  IsoPaftT->SetMarkerSize(0.5);
 
  IsoPaftM->SetMarkerColor(kOrange -3);
  IsoPaftT->SetMarkerColor(kYellow);
  IsoPaft->GetYaxis()->SetTitle("Only Iso P Cut Efficiency");
  IsoPaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c20->cd(4);

  IsoCaft->Draw();
  IsoCaftM->Draw("same");
  IsoCaftT->Draw("same");
  IsoCaft->SetMarkerSize(0.5);
  IsoCaftM->SetMarkerSize(0.5);
  IsoCaftT->SetMarkerSize(0.5);
 
  IsoCaftM->SetMarkerColor(kOrange -3);
  IsoCaftT->SetMarkerColor(kYellow);
  IsoCaft->GetYaxis()->SetTitle("Only Iso P Cut Efficiency");
  IsoCaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c20->cd(5);
  
  IsoNaft->Draw();
  IsoNaftM->Draw("same");
  IsoNaftT->Draw("same");
  IsoNaft->SetMarkerSize(0.5);
  IsoNaftM->SetMarkerSize(0.5);
  IsoNaftT->SetMarkerSize(0.5);
 
  IsoNaftM->SetMarkerColor(kOrange -3);
  IsoNaftT->SetMarkerColor(kYellow);
  IsoNaft->GetYaxis()->SetTitle("Only Iso P Cut Efficiency");
  IsoNaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c20->SaveAs("BranchOutCutsSignalWP.png");

 

 









  
  TCanvas *c11 = new TCanvas("c11","Branch Out Cuts",900,600);
  c11->Divide(3,2);
  
  c11->cd(1);  

  SieaftN->Draw();
  SieaftbN->Draw("same");
  SieaftN->SetMarkerSize(0.5);
  SieaftbN->SetMarkerSize(0.5);
  SieaftbN->SetMarkerColor(kRed);
  SieaftN->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  SieaftN->GetXaxis()->SetTitle("# Nvtx");
 
  c11->cd(2);
  ToEaftN->Draw();
  ToEaftbN->Draw("same");
  ToEaftN->SetMarkerSize(0.5);
  ToEaftbN->SetMarkerSize(0.5);
  ToEaftbN->SetMarkerColor(kRed);
  ToEaftN->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaftN->GetXaxis()->SetTitle("# Nvtx");

  c11->cd(3);
  IsoPaftN->Draw();
  IsoPaftbN->Draw("same");
  IsoPaftN->SetMarkerSize(0.5);
  IsoPaftbN->SetMarkerColor(kRed);
  IsoPaftbN->SetMarkerSize(0.5);
  IsoPaftN->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaftN->GetXaxis()->SetTitle("# Nvtx");

  c11->cd(4);
  IsoCaftN->Draw();
  IsoCaftbN->Draw("same");
  IsoCaftN->SetMarkerSize(0.5);
  IsoCaftbN->SetMarkerColor(kRed);
  IsoCaftbN->SetMarkerSize(0.5);
  IsoCaftN->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaftN->GetXaxis()->SetTitle("# Nvtx");
  
  c11->cd(5);
  IsoNaftN->Draw();
  IsoNaftbN->Draw("same");
  IsoNaftN->SetMarkerSize(0.5);
  IsoNaftbN->SetMarkerSize(0.5);
  IsoNaftbN->SetMarkerColor(kRed);
  IsoNaftN->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaftN->GetXaxis()->SetTitle("# Nvtx");
  
  c11->SaveAs("BranchOutCutsNVTX.png");




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
  
  c12->SaveAs("BranchOutCutsEta.png");






}
