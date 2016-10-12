void ISOp(){


  t_S->Draw("isoP>>h1(100,0,10)");
  t_B->Draw("isoP>>h2(100,0,10)");
  
  h1->SetLineColor(kRed);

  TCanvas *c2 = new TCanvas("c2","",400,400);
  c2->cd()->SetLogy();
  h1->Draw();
  h1->GetXaxis()->SetTitle("EA cor IsoP");
  h1->Draw();
  h2->Draw("same");

  c2->SaveAs("IsolationP.png");

  

}
