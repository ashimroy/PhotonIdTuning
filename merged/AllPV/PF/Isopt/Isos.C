void Isos(int reg){
 
  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  if(reg == 1) TFile *f1 = new TFile("CutTMVABarrel90.root");
  if(reg == 2) TFile *f1 = new TFile("CutTMVAEndCap90.root");


  f1->cd();
   t_S->Draw("ToE>>hhoe_s(100,0,0.1)","weighT*(Ppt > 15 && Ppt < 200   )");
  
  if(reg == 1){
    
    t_S->Draw("Sieie>>hsigm_s(100,0,0.02)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
    
    t_S->Draw("(isoN-(0.014*Ppt+0.000019*Ppt*Ppt))>>hisoN_s(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
    t_S->Draw("(isoP - 0.0053*Ppt  )>>hisoP_s(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200  )");
  }else{

    t_S->Draw("Sieie>>hsigm_s(200,0.01,0.05)","weighT*(Ppt > 15 && Ppt < 200  && ToE <0.05  ) ");
 
    t_S->Draw("(isoN-(0.0139*Ppt+0.000025*Ppt*Ppt) )>>hisoN_s(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
    t_S->Draw("(isoP -  0.0034*Ppt )>>hisoP_s(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200  && ToE <0.05 )");
    
  }
  t_S->Draw("isoC>>hisoC_s(60,0,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");

  // Background

   t_B->Draw("ToE>>hhoe_b(100,0,0.1)","weighT*(Ppt > 15 && Ppt < 200)");
  
  if(reg == 1){
  
    t_B->Draw("Sieie>>hsigm_b(100,0,0.02)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
 
    t_B->Draw("isoN-(0.014*Ppt+0.000019*Ppt*Ppt)>>hisoN_b(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
    t_B->Draw("(isoP - 0.0053*Ppt )>>hisoP_b(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
  }else{

    t_B->Draw("Sieie>>hsigm_b(200,0.01,0.05)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
  
    t_B->Draw("isoN-(0.0139*Ppt+0.000025*Ppt*Ppt)>>hisoN_b(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE < 0.05  )");
    t_B->Draw("isoP - 0.0034*Ppt >>hisoP_b(1000,-4,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");
  }
  t_B->Draw("isoC>>hisoC_b(60,0,6)","weighT*(Ppt > 15 && Ppt < 200 && ToE <0.05  )");


  
  double entries; 
  entries = hsigm_s->GetEntries();
  hsigm_s->Scale(1./entries);

  entries = hhoe_s->GetEntries();
  hhoe_s->Scale(1./entries);

  entries = hisoN_s->GetEntries();
  hisoN_s->Scale(1./entries);

  entries = hisoC_s->GetEntries();
  hisoC_s->Scale(1./entries);

  entries = hisoP_s->GetEntries();
  hisoP_s->Scale(1./entries);

  entries = hsigm_b->GetEntries();
  hsigm_b->Scale(1./entries);

  entries = hhoe_b->GetEntries();
  hhoe_b->Scale(1./entries);

  entries = hisoN_b->GetEntries();
  hisoN_b->Scale(1./entries);

  entries = hisoC_b->GetEntries();
  hisoC_b->Scale(1./entries);

  entries = hisoP_b->GetEntries();
  hisoP_b->Scale(1./entries);





  
  TCanvas *c1 = new TCanvas("c1","Variables",800,400);
  c1->Divide(2,1);
  
  
  c1->cd(1);

  hisoN_s->Draw();
  hisoN_s->SetLineColor(kRed);
  hisoN_s->SetFillColor(kRed);
  //hisoN_s->SetFillStyle(3001);

  hisoN_s->GetXaxis()->SetTitle("Iso N rho corrected pt scaled");
  hisoN_b->Draw("same");

  c1->cd(2)->SetLogy();

  hisoP_s->Draw();
  hisoP_s->SetLineColor(kRed);
  hisoP_s->SetFillColor(kRed);
  //hisoP_s->SetFillStyle(3001);

  hisoP_s->GetXaxis()->SetTitle("Iso P rho corrected pt scaled");
  hisoP_b->Draw("same");


  if(reg == 1) c1->SaveAs("IsoVarsB.png");
  if(reg == 2) c1->SaveAs("IsoVarsE.png");



}
