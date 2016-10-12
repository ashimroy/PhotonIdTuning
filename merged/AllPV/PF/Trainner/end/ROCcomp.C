#include <TFile.h>
#include <cstdlib>
#include <TH1F.h>

void ROCcomp(){

  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);


  TFile *fLoose = new TFile("Loose_w_END_scaled.root");
  TFile *fTight  = new TFile("Tight_w_END_scaled.root");
  TFile *fMedium  = new TFile("Medium_w_END_scaled.root");

  TCanvas *c1 = new TCanvas("c1","ROC Curves Comparison",600,600);
  c1->cd()->SetGrid();

  fTight->cd("Method_Cuts/Cut_Tight_r");
  MVA_Cut_Tight_r_trainingRejBvsS->Draw();
  MVA_Cut_Tight_r_trainingRejBvsS->SetLineColor(kMagenta);
  MVA_Cut_Tight_r_trainingRejBvsS->GetXaxis()->SetTitle("Signal Efficiency"); 
  MVA_Cut_Tight_r_trainingRejBvsS->GetYaxis()->SetTitle("Background Rejection");
  
  fMedium->cd("Method_Cuts/Cut_Medium_r");
  MVA_Cut_Medium_r_trainingRejBvsS->Draw("same");
  MVA_Cut_Medium_r_trainingRejBvsS->SetLineColor(kBlue);


  
  fLoose->cd("Method_Cuts/Cut_Loose_r");
  MVA_Cut_Loose_r_trainingRejBvsS->Draw("same");
  MVA_Cut_Loose_r_trainingRejBvsS->SetLineColor(kBlack);
  
  leg = new TLegend(0.2,0.2,0.5,0.4);
  leg->SetBorderSize(0);
  leg->AddEntry("MVA_Cut_Tight_r_trainingRejBvsS","Tight","l");
  leg->AddEntry("MVA_Cut_Medium_r_trainingRejBvsS","Medium","l");
  leg->AddEntry("MVA_Cut_Loose_r_trainingRejBvsS","Loose","l");
  leg->Draw();

  c1->SaveAs("ROCs_train.png");



}
