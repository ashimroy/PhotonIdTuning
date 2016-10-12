void Comp(){

  //  TFile *f1 = new TFile("RelBarHBHV.root");
  TFile *f2 = new TFile("barh.root");
  
  /*
  f1->cd();
  TH1F *RELBAR =  Lpts->Clone();
  TH1F *RELBARb =  Lptb->Clone();
  */
  f2->cd();
  TH1F *sCA =  Lpts->Clone();
  TH1F *sCAb =  Lptb->Clone();




  TCanvas *c1 = new TCanvas("c1","",400,400);
  c1->cd();
  f2->cd();
  
  sCA->Draw();
  sCA->SetLineColor(kGray +3);
  sCA->SetMarkerColor(kGray +3);
  sCAb->SetLineColor(kGray +3);
  sCAb->SetMarkerColor(kGray +3);
  sCAb->Draw("same");
  
  /*
  RELBAR->Draw("same");
  RELBAR->SetLineColor(kRed  );
  RELBAR->SetMarkerColor(kRed  );
  RELBARb->SetLineColor(kRed  );
  RELBARb->SetMarkerColor(kRed  );

  RELBARb->Draw("same");
  */
  
  c1->SaveAs("Comp.png");





}
