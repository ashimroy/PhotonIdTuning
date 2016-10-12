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

void EfCOMP(){




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






  Letas->Divide(EffETAL,EffETA0,1.,1.,"B");
  Metas->Divide(EffETAM,EffETA0,1.,1.,"B");
  Tetas->Divide(EffETAT,EffETA0,1.,1.,"B");

  cout<<"Here"<<endl;
  
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

  
  Lnvtxb->Divide(EffNVTXLb,EffNVTX0b,1.,1.,"B");
  Mnvtxb->Divide(EffNVTXMb,EffNVTX0b,1.,1.,"B");
  Tnvtxb->Divide(EffNVTXTb,EffNVTX0b,1.,1.,"B");


  // the branch  out cuts 


  Sieaft->Divide(EffPTs,EffPT0,1.,1.,"B"); 
  ToEaft->Divide(EffPTt,EffPT0,1.,1.,"B");
  IsoPaft->Divide(EffPTp,EffPT0,1.,1.,"B");
  IsoCaft->Divide(EffPTc,EffPT0,1.,1.,"B");
  IsoNaft->Divide(EffPTn,EffPT0,1.,1.,"B");

  TCanvas *cpt = new TCanvas("cpt","Pt Eff",500,500);
  cpt->cd();
  Lpts->Draw();
  Lpts->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  Lpts->GetYaxis()->SetRangeUser(0,1.0);
  Lpts->SetLineColor(kGray + 3);
  Lpts->SetMarkerColor(kGray +3);
  Lpts->SetMarkerStyle(20);
  Lpts->SetMarkerSize(0.5);

  Mpts->Draw("esame");
  Mpts->SetMarkerColor(kOrange -3);
  Mpts->SetLineColor(kOrange -3);
  Mpts->SetMarkerStyle(20);
  Mpts->SetMarkerSize(0.5);
 
  Tpts->Draw("esame");
  Tpts->SetMarkerColor(kYellow);
  Tpts->SetLineColor(kYellow );
  Tpts->SetMarkerStyle(20);
  Tpts->SetMarkerSize(0.5);
     
  Lptb->SetLineColor(kAzure + 3);
  Lptb->SetMarkerColor(kAzure +3);
  Lptb->SetMarkerStyle(20);
  Lptb->SetMarkerSize(0.5);
  Lptb->Draw("esame");

  
  Mptb->SetLineColor(kAzure + 5);
  Mptb->SetMarkerColor(kAzure +5);
  Mptb->SetMarkerStyle(20);
  Mptb->SetMarkerSize(0.5);
  Mptb->Draw("esame");


  
  Tptb->SetLineColor(kAzure + 10);
  Tptb->SetMarkerColor(kAzure +10);
  Tptb->SetMarkerStyle(20);
  Tptb->SetMarkerSize(0.5);
  Tptb->Draw("esame");





 

  cpt->SaveAs("EfPT.png");

  TCanvas *ceta = new TCanvas("cpt","Pt Eff",500,500);
  ceta->cd();
  Letas->GetXaxis()->SetTitle("#eta");
  //Letas->GetXaxis()->SetRangeUser(-5,5);
  Letas->GetYaxis()->SetRangeUser(0,1.0);
  Letas->SetLineColor(kGray + 3);
  Letas->SetMarkerColor(kGray +3);
  Letas->SetMarkerStyle(20);
  Letas->SetMarkerSize(0.5);
  Letas->Draw();

  Letab->SetLineColor(kAzure + 3);
  Letab->SetMarkerColor(kAzure +3);
  Letab->SetMarkerStyle(20);
  Letab->SetMarkerSize(0.5);
  Letab->Draw("esame");

  
  Metab->SetLineColor(kAzure + 5);
  Metab->SetMarkerColor(kAzure +5);
  Metab->SetMarkerStyle(20);
  Metab->SetMarkerSize(0.5);
  Metab->Draw("esame");


  
  Tetab->SetLineColor(kAzure + 10);
  Tetab->SetMarkerColor(kAzure +10);
  Tetab->SetMarkerStyle(20);
  Tetab->SetMarkerSize(0.5);
  Tetab->Draw("esame");





  Metas->Draw("esame");
  Metas->SetMarkerColor(kOrange -3);
  Metas->SetLineColor(kOrange -3);
  Metas->SetMarkerStyle(20);
  Metas->SetMarkerSize(0.5);
  Tetas->Draw("esame");
  Tetas->SetMarkerColor(kYellow );
  Tetas->SetLineColor(kYellow );
  Tetas->SetMarkerStyle(20);
  Tetas->SetMarkerSize(0.5);
 

  ceta->SaveAs("EfETA.png");


  
  TCanvas *cnvtx = new TCanvas("cnvtx","Pt Eff",500,500);
  cnvtx->cd();
  Lnvtxs->GetXaxis()->SetTitle("Nvtx");
  Lnvtxs->GetYaxis()->SetRangeUser(0,1.0);
  Lnvtxs->GetXaxis()->SetRangeUser(0,50);
  Lnvtxs->SetLineColor(kGray +3 );
  Lnvtxs->SetMarkerColor(kGray +3 );
  Lnvtxs->SetMarkerStyle(20);
  Lnvtxs->SetMarkerSize(0.5);
  Lnvtxs->Draw();

  Mnvtxs->Draw("esame");
  Mnvtxs->SetMarkerColor(kOrange -3);
  Mnvtxs->SetLineColor(kOrange -3);
  Mnvtxs->SetMarkerStyle(20);
  Mnvtxs->SetMarkerSize(0.5);
  Tnvtxs->Draw("esame");
  Tnvtxs->SetMarkerColor(kYellow);
  Tnvtxs->SetMarkerSize(0.5);
  Tnvtxs->SetLineColor(kYellow);
  Tnvtxs->SetMarkerStyle(20);


  
  Lnvtxb->SetLineColor(kAzure + 3);
  Lnvtxb->SetMarkerColor(kAzure +3);
  Lnvtxb->SetMarkerStyle(20);
  Lnvtxb->SetMarkerSize(0.5);
  Lnvtxb->Draw("esame");

  
  Mnvtxb->SetLineColor(kAzure + 5);
  Mnvtxb->SetMarkerColor(kAzure +5);
  Mnvtxb->SetMarkerStyle(20);
  Mnvtxb->SetMarkerSize(0.5);
  Mnvtxb->Draw("esame");


  
  Tnvtxb->SetLineColor(kAzure + 10);
  Tnvtxb->SetMarkerColor(kAzure +10);
  Tnvtxb->SetMarkerStyle(20);
  Tnvtxb->SetMarkerSize(0.5);
  Tnvtxb->Draw("esame");






  cnvtx->Update();
  cnvtx->SaveAs("EfNVTX.png");







  /*
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

  Tetas->SetLineColor(kRed);
  Tetas->SetMarkerColor(kRed);
  Tetas->SetMarkerSize(0.5);
  Tetab->SetMarkerSize(0.5);

  Tetab->Draw("same");
  c3->SaveAs("TightEffBck.png");

  */



  TFile *f3 = new TFile("EtasB.root","recreate");
  f3->cd();
  Letas->Write();
  Metas->Write();
  Tetas->Write();

  Letab->Write();
  Metab->Write();
  Tetab->Write();








}

//  LocalWords:  ceta
