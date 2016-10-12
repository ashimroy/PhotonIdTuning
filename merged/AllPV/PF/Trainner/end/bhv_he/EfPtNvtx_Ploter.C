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

void EfPtNvtx_Ploter(){


  double IsoPcutL,IsoCcutL,IsoNcutL,SieiecutL,HoEcutL;



  ifstream loose; 
  loose.open("LooseR.txt");

  if(loose.is_open()){
    while(!loose.eof()){
      
      loose>>SieiecutL>>HoEcutL>>IsoCcutL>>IsoNcutL>>IsoPcutL;
      break;

    }
  }

  



  double IsoPcutM = 5.6;
  double IsoPcutT = 4.4;
  
  double IsoCcutM = 3.2;
  double IsoCcutT = 2.8;
  
  double IsoNcutM = 4;
  double IsoNcutT = 3.2;

   //donne siesie
  
  double SieiecutM = 0.00988;
  double SieiecutT = 0.00967;

  double HoEcutM = 0.063;
  double HoEcutT = 0.021;

  gROOT->ProcessLine(" .L tdrstyle.C");
  setTDRStyle();
  gStyle->SetOptStat(0);

  TH1F *Letas = new TH1F("Letas","Loose Cut Efficiency Eta",100,0,5);
  TH1F *Metas = new TH1F("Metas","Medium Cut Efficiency Eta",100,0,5);
  TH1F *Tetas = new TH1F("Tetas","Tight Cut Efficiency Eta",100,0,5); 

  TH1F *Lpts = new TH1F("Lpts","Loose Cut Efficiency pt",100,0,200);
  TH1F *Mpts = new TH1F("Mpts","Medium Cut Efficiency pt",100,0,200);
  TH1F *Tpts = new TH1F("Tpts","Tight Cut Efficiency pt",100,0,200); 

  TH1F *Lnvtxs = new TH1F("Lnvtxs","Loose Cut Efficiency vertices",100,0,100);
  TH1F *Mnvtxs = new TH1F("Mnvtxs","Medium Cut Efficiency vertices",100,0,100);
  TH1F *Tnvtxs = new TH1F("Tnvtxs","Tight Cut Efficiency vertices",100,0,100); 


  TH1F *Letab = new TH1F("Letab","Loose Cut b Efficiency Eta",100,0,5);
  TH1F *Metab = new TH1F("Metab","Medium Cut b Efficiency Eta",100,0,5);
  TH1F *Tetab = new TH1F("Tetab","Tight Cut b Efficiency Eta",100,0,5); 


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

  
  Letab->Divide(BckETAL,BckETA0,1.,1.,"B");
  Metab->Divide(BckETAM,BckETA0,1.,1.,"B");
  Tetab->Divide(BckETAT,BckETA0,1.,1.,"B");

  

  Lpts->Divide(EffPTL,EffPT0,1.,1.,"B");
  Mpts->Divide(EffPTM,EffPT0,1.,1.,"B");
  Tpts->Divide(EffPTT,EffPT0,1.,1.,"B");

  
  Lptb->Divide(BckPTL,BckPT0,1.,1.,"B");
  Mptb->Divide(BckPTM,BckPT0,1.,1.,"B");
  Tptb->Divide(BckPTT,BckPT0,1.,1.,"B");


  

  Lnvtxs->Divide(EffNVTXL,EffNVTX0,1.,1.,"B");
  Mnvtxs->Divide(EffNVTXM,EffNVTX0,1.,1.,"B");
  Tnvtxs->Divide(EffNVTXT,EffNVTX0,1.,1.,"B");

  
  Lnvtxb->Divide(BckNVTXL,BckNVTX0,1.,1.,"B");
  Mnvtxb->Divide(BckNVTXM,BckNVTX0,1.,1.,"B");
  Tnvtxb->Divide(BckNVTXT,BckNVTX0,1.,1.,"B");


  // the branch  out cuts 


  Sieaft->Divide(EffPTs,EffPT0,1.,1.,"B"); 
  ToEaft->Divide(EffPTt,EffPT0,1.,1.,"B");
  IsoPaft->Divide(EffPTp,EffPT0,1.,1.,"B");
  IsoCaft->Divide(EffPTc,EffPT0,1.,1.,"B");
  IsoNaft->Divide(EffPTn,EffPT0,1.,1.,"B");




  
  TCanvas *c1  = new TCanvas("c1","Medium",600,600);
  c1->Divide(2,2);

  c1->cd(1);
  Mnvtxs->Draw();
  Mnvtxs->GetYaxis()->SetRangeUser(0,1.0);
 
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

 


  TCanvas *c6 = new TCanvas("c6","Pt Spectrum ",600,600);
  c6->Divide(2,2);
  c6->cd(2);
  
  
  Ptw->Draw();
  
  Ptw->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c6->cd(1);
  Ptweight->Draw();
  Ptweight->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c6->Update();

  c6->SaveAs("flattening.png");


    l1 = new TLegend(0.4961983,0.6604796,0.6976886,0.8603222);
  l1->SetFillColor(0);
  l1->SetBorderSize(0);
  l1->SetTextSize(0.02);

  
  EffPTc1->Divide(EffPT0);
  EffPTc2->Divide(EffPT0);
  EffPTc3->Divide(EffPT0);
  EffPTc4->Divide(EffPT0);
  EffPTc5->Divide(EffPT0);
  
  
  
  
  TCanvas *c7 = new TCanvas("c7","Sequential Application of Cuts   ",400,400);
  c7->cd(1);
  
  
  EffPTc1->Draw();
  EffPTc1->GetYaxis()->SetRangeUser(0,1);

  EffPTc1->SetLineColor(kRed);
  l1->AddEntry(&EffPTc1," Sieie ","l");

  EffPTc2->Draw("same");
  EffPTc2->SetLineColor(kBlue);
  l1->AddEntry(&EffPTc2," H over E","l");


  EffPTc3->Draw("same");
  EffPTc3->SetLineColor(kGreen);
  l1->AddEntry(&EffPTc3," Iso P","l");


  EffPTc4->Draw("same");
  EffPTc4->SetLineColor(kMagenta);
  l1->AddEntry(&EffPTc4," Iso N","l");



  EffPTc5->Draw("same");
  EffPTc5->SetLineColor(kBlack);
  l1->AddEntry(&EffPTc5," Iso C","l");






  l1->Draw();
  c7->Update();
  c7->SaveAs("Sequential.png");




  TCanvas *c8 = new TCanvas("c8","Discriminants dependency on pt   ",900,900);
  c8->Divide(3,2);


  double xcl[2]={0};
  double ycl[2]={0};

  double xcm[2]={0};
  double ycm[2]={0};

  double xct[2]={0};
  double yct[2]={0};
  
  ycl[0] = SieiecutL; 
  ycl[1] = SieiecutL;
  yct[0] = SieiecutT; 
  yct[1] = SieiecutT;
  ycm[0] = SieiecutM; 
  ycm[1] = SieiecutM;




  xcl[0] = 0; 
  xcl[1] = 200;

  xct[0] = 0; 
  xct[1] = 200;

  xcm[0] = 0; 
  xcm[1] = 200;
 
  
  TGraph *cutsl = new TGraph(2,xcl,ycl);
  TGraph *cutsm = new TGraph(2,xcm,ycm);
  TGraph *cutst = new TGraph(2,xct,yct);



  c8->cd(1);

  TProfile *siep = SiePt->ProfileX(); 
  siep->Draw();
  siep->GetYaxis()->SetTitle("Sieie");
  siep->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  cutsl->Draw("same");
  cutsl->SetLineColor(kBlue);
  cutsm->Draw("same");
  cutsm->SetLineColor(kRed);
  cutst->Draw("same");
  cutst->SetLineColor(kBlack);

  c8->cd(2);
  
  ycl[0] = HoEcutL; 
  ycl[1] = HoEcutL;
  yct[0] = HoEcutT; 
  yct[1] = HoEcutT;
  ycm[0] = HoEcutM; 
  ycm[1] = HoEcutM;




  
  TGraph *cuttl = new TGraph(2,xcl,ycl);
  TGraph *cuttm = new TGraph(2,xcm,ycm);
  TGraph *cuttt = new TGraph(2,xct,yct);





  TProfile *toep = ToEPt->ProfileX(); 
  toep->Draw();
  toep->GetYaxis()->SetTitle("HoE  ");
  toep->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  
  cuttl->Draw("same");
  cuttl->SetLineColor(kBlue);
  cuttm->Draw("same");
  cuttm->SetLineColor(kRed);
  cuttt->Draw("same");
  cuttt->SetLineColor(kBlack);



  
  c8->cd(3);

  
  ycl[0] = IsoPcutL; 
  ycl[1] = IsoPcutL + 200*0.0027;
  yct[0] = IsoPcutT; 
  yct[1] = IsoPcutT;
  ycm[0] = IsoPcutM; 
  ycm[1] = IsoPcutM;





  TGraph *cutpl = new TGraph(2,xcl,ycl);
  TGraph *cutpm = new TGraph(2,xcm,ycm);
  TGraph *cutpt = new TGraph(2,xct,yct);




  TProfile *isopp = IsoPPt->ProfileX(); 
  isopp->Draw();
  isopp->GetYaxis()->SetTitle("IsoP");
  isopp->GetXaxis()->SetTitle("Pt GeVc^{-1}");


    
  cutpl->Draw("same");
  cutpl->SetLineColor(kBlue);
  cutpm->Draw("same");
  cutpm->SetLineColor(kRed);
  cutpt->Draw("same");
  cutpt->SetLineColor(kBlack);


  
  c8->cd(4);

  
  ycl[0] = IsoCcutL; 
  ycl[1] = IsoCcutL;
  yct[0] = IsoCcutT; 
  yct[1] = IsoCcutT;
  ycm[0] = IsoCcutM; 
  ycm[1] = IsoCcutM;



    TGraph *cutcl = new TGraph(2,xcl,ycl);
  TGraph *cutcm = new TGraph(2,xcm,ycm);
  TGraph *cutct = new TGraph(2,xct,yct);



  
  TProfile *isocp = IsoCPt->ProfileX(); 
  isocp->Draw();
  isocp->GetYaxis()->SetTitle("IsoC");
  isocp->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  
    
  cutcl->Draw("same");
  cutcl->SetLineColor(kBlue);
  cutcm->Draw("same");
  cutcm->SetLineColor(kRed);
  cutct->Draw("same");
  cutct->SetLineColor(kBlack);



  
  c8->cd(5);


  
  ycl[0] = IsoNcutL; 
  ycl[1] = IsoNcutL + 0.0043*200;
  yct[0] = IsoNcutT; 
  yct[1] = IsoNcutT;
  ycm[0] = IsoNcutM; 
  ycm[1] = IsoNcutM;




  TProfile *isonp = IsoNPt->ProfileX(); 
  isonp->Draw();
  isonp->GetYaxis()->SetTitle("IsoN");
  isonp->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  TGraph *cutnl = new TGraph(2,xcl,ycl);
  TGraph *cutnm = new TGraph(2,xcm,ycm);
  TGraph *cutnt = new TGraph(2,xct,yct);

  
  cutnl->Draw("same");
  cutnl->SetLineColor(kBlue);
  cutnm->Draw("same");
  cutnm->SetLineColor(kRed);
  cutnt->Draw("same");
  cutnt->SetLineColor(kBlack);





  
  c8->Update();
  c8->SaveAs("PtvsVars.png");



  TCanvas *c10 = new TCanvas("c10","Branch Out Cuts",900,900);
  c10->Divide(3,2);
  
  c10->cd(1);  

  Sieaft->Draw();
  Sieaft->SetMarkerSize(0.5);
  Sieaft->GetYaxis()->SetTitle("Only Sieie Cut Efficiency");
  Sieaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
 
  c10->cd(2);
  ToEaft->Draw();
  Sieaft->SetMarkerSize(0.5);
  ToEaft->GetYaxis()->SetTitle("Only HOE Cut Efficiency");
  ToEaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c10->cd(3);
  IsoPaft->Draw();
  IsoPaft->SetMarkerSize(0.5);
  IsoPaft->GetYaxis()->SetTitle("Only iso p Cut Efficiency");
  IsoPaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");

  c10->cd(4);
  IsoCaft->Draw();
  IsoCaft->SetMarkerSize(0.5);
  IsoCaft->GetYaxis()->SetTitle("Only iso c Cut Efficiency");
  IsoCaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c10->cd(5);
  IsoNaft->Draw();
  IsoNaft->SetMarkerSize(0.5);
  IsoNaft->GetYaxis()->SetTitle("Only iso n Cut Efficiency");
  IsoNaft->GetXaxis()->SetTitle("Pt GeVc^{-1}");
  
  c10->SaveAs("BranchOutCuts.png");


}
