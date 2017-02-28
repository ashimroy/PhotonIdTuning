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

void Etas(){





  TCanvas *ceta = new TCanvas("cpt","Pt Eff",500,500);
  ceta->cd();
  Letas->GetXaxis()->SetTitle("#eta");
  Letas->GetXaxis()->SetRangeUser(-3,3);                                                                
  //  Letas->GetYaxis()->SetRangeUser(-5,5);
  Letas->SetLineColor(kGray + 3);
  Letas->SetMarkerColor(kGray +3);
  Letas->SetMarkerStyle(20);
  Letas->Draw();

  Letab->SetLineColor(kAzure + 3);
  Letab->SetMarkerColor(kAzure +3);
  Letab->SetMarkerStyle(20);
  Letab->Draw("esame");


  
  Metab->SetLineColor(kAzure + 5);
  Metab->SetMarkerColor(kAzure +5);
  Metab->SetMarkerStyle(20);
  Metab->Draw("esame");



  Tetab->SetLineColor(kAzure + 10);
  Tetab->SetMarkerColor(kAzure +10);
  Tetab->SetMarkerStyle(20);
  Tetab->Draw("esame");




  Metas->Draw("esame");
  Metas->SetMarkerColor(kOrange -3);
  Metas->SetLineColor(kOrange -3);
  Metas->SetMarkerStyle(20);
  Tetas->Draw("esame");
  Tetas->SetMarkerColor(kYellow );
  Tetas->SetLineColor(kYellow );
  Tetas->SetMarkerStyle(20);
  ceta->Update();

  ceta->SaveAs("EfETA_all.png");





}
