
void ROCcomp(){


  gStyle->SetOptStat(0);

  TFile *f1 = new TFile("../BAR/Loose_w_scaled.root");
  f1->cd("Method_Cuts/Cut_Loose_r");
  TH1F *SC = MVA_Cut_Loose_r_trainingRejBvsS->Clone();

  
  TFile *f2 = new TFile("../BAR_REL/Loose_w_scaled.root");
  f2->cd("Method_Cuts/Cut_Loose_r");
  TH1F *REL = MVA_Cut_Loose_r_trainingRejBvsS->Clone();

  SC->SetLineColor(kGray +3);
  REL->SetLineColor(kRed);

  

  TCanvas *c1  = new TCanvas("c1","",600,600);
  c1->cd()->SetGrid();

  SC->Draw();
  SC->GetXaxis()->SetTitle("Signal Efficiency"); 
  SC->GetYaxis()->SetTitle("Background Rejection");
  REL->Draw("same");
  c1->SaveAs("ROCcomP.png");





}

