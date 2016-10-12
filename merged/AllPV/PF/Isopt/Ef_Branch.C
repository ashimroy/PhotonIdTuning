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

void Ef_Branch(){


  gROOT->ProcessLine(" .L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  TH1F *IsoPaftl = new TH1F("IsoPaftl","IsoP cut only",100,0,100); 
  TH1F *IsoPaftlb = new TH1F("IsoPaftlb","IsoP cut only",100,0,100); 
  

  //Pt dependency

  IsoPaftl->Divide(EffNp,EffN0,1.,1.,"B");
  IsoPaftlb->Divide(EffNpb,EffN0b,1.,1.,"B");


  TCanvas *c10 = new TCanvas("c10","Branch Out Cuts",900,600);
  c10->Divide(3,2);

  IsoPaftl->Draw();


  IsoPaftlb->Draw("same");

  IsoPaftl->SetLineColor(kRed);
  IsoPaftl->SetMarkerColor(kRed);


  IsoPaftl->SetMarkerSize(0.5);
  IsoPaftl->GetYaxis()->SetTitle("Only iso P Cut Efficiency");
  IsoPaftl->GetXaxis()->SetTitle("Nvtx");
  
  c10->Update();
  c10->SaveAs("LCheck.png");


}
