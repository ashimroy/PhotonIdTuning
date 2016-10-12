#include <cstdlib>
#include <TFile.h>
#include <TGraph.h>
#include <TH1F.h>


void ModCryst(){

  gStyle->SetOptStat(0);

  ifstream loose;
  loose.open("LooseR.txt");

  double efL,efM,efT,bkL,bkM,bkT;
  double IsoPcutL,IsoPcutM,IsoPcutT,IsoCcutL,IsoCcutM,IsoCcutT,IsoNcutL,IsoNcutM,IsoNcutT,SieiecutL,SieiecutM,SieiecutT,HoEcutL,HoEcutM,HoEcutT;


  if(loose.is_open()){
    while(!loose.eof()){
      loose>>SieiecutL>>HoEcutL>>IsoCcutL>>IsoNcutL>>IsoPcutL;
      break;
    }
  }

  double slopeP = 0.0010;
  double slopeN = 0.0025;
  
  TFile *f1 = new TFile("../../HPT_Barrel.root");

  TH1F *Mphi_s    = new TH1F("Mphi_s"," Sig ",10,0,1.0);
  TH1F *Mphi_sALL = new TH1F("Mphi_sALL"," Sig ",10,0,1.0);
  TH1F *Mphi_s20    = new TH1F("Mphi_s20"," Sig ",200,0,20.0);
  TH1F *Mphi_sALL20 = new TH1F("Mphi_sALL20"," Sig ",200,0,20.0);
  TH1F *Mphi_s20H    = new TH1F("Mphi_s20H"," Sig ",200,0,20.0);
  TH1F *Mphi_sALL20H = new TH1F("Mphi_sALL20H"," Sig ",200,0,20.0);
  TH1F *Mphi_sH    = new TH1F("Mphi_sH"," Sig ",10,0,1.0);
  TH1F *Mphi_sALLH = new TH1F("Mphi_sALLH"," Sig ",10,0,1.0);
  TH2D *IsoN_mCr  = new TH2D("IsoN_mCr","IsoN    ",10,0,1,450,0,45);
  TH2D *IsoN_mCrH = new TH2D("IsoN_mCrH","IsoN    ",10,0,1,450,0,45);
  TH2D *HOE_mCr  = new TH2D("HOE_mCr","  Hover E",10,0,1,450,0,4.5);
  TH2D *HOE_mCrH = new TH2D("HOE_mCrH"," H over E",10,0,1,450,0,4.5);
  TH1F *Mphi_D = new TH1F("Mphi_D"," Bck ",10,0,1.0);
  TH1F *Mphi_DH = new TH1F("Mphi_DH"," Bck ",10,0,1.0);



  float Ppt,Pphi,Peta,Sie_ie,iso_P,genPt,iso_C,iso_N,to_e,weightXS,weighT;
  int nvtx,Pix;
  //Signal Tree
  t_S->SetBranchAddress("Sieie",&Sie_ie);
  t_S->SetBranchAddress("isoP",&iso_P);
  t_S->SetBranchAddress("isoC",&iso_C);
  t_S->SetBranchAddress("isoN",&iso_N);
  t_S->SetBranchAddress("ToE",&to_e);
  t_S->SetBranchAddress("weighT",&weighT);
  t_S->SetBranchAddress("Nvtx",&nvtx);
  t_S->SetBranchAddress("Peta",&Peta);
  t_S->SetBranchAddress("Ppt",&Ppt);
  t_S->SetBranchAddress("Pphi",&Pphi);
  t_S->SetBranchAddress("genPt",&genPt);
  t_S->SetBranchAddress("Pix",&Pix);


  Mphi_s->Sumw2();
  Mphi_DH->Sumw2();
  Mphi_D->Sumw2();
  Mphi_sH->Sumw2();
  Mphi_sALL->Sumw2();
  Mphi_sALLH->Sumw2();


  int ent =  t_S->GetEntries();
  for(int i = 0; i < ent; i ++){

    t_S->GetEntry(i);

    if(Pix)continue;
    if(fabs(Peta) > 2.0) continue;

    double phi = Pphi*180.0/TMath::Pi();

    cout<<phi<<"  "<<fmod(phi,1) <<endl;

    Mphi_sALL->Fill(fabs(fmod(phi,1)));
    HOE_mCr->Fill(fabs(fmod(phi,1)),to_e);
    IsoN_mCr->Fill(fabs(fmod(phi,1)),iso_N - slopeN*Ppt);
    
    if(Ppt > 200 ){
      IsoN_mCrH->Fill((fmod(phi,1)),iso_N - slopeN*Ppt);
      Mphi_sALLH->Fill(fabs(fmod(phi,1)));
      HOE_mCrH->Fill(fabs(fmod(phi,1)),to_e);
    }
    
    if(iso_P < IsoPcutL+slopeP*Ppt){

      if(iso_N < IsoNcutL+slopeN*Ppt){
	if(iso_C < IsoCcutL){
	  if(to_e<HoEcutL){
	    if(Sie_ie < SieiecutL ){
	      Mphi_s->Fill(fabs(fmod(phi,1)));
	      if(Ppt > 200 )    Mphi_sH->Fill(fabs(fmod(phi,1)));
	    }
	  }
	}
      }
    }
  }
  Mphi_D->Divide(Mphi_s,Mphi_sALL,1.,1.,"B");
  Mphi_DH->Divide(Mphi_sH,Mphi_sALLH,1.,1.,"B");

  //Tracing Percentages

  double M1[10] = {0};

  double modC[10] = {0};
  double IsoN[10][450] = {0};
  double IsoNH[10][450] = {0};
 

  for(int i = 0; i < 10 ; i++){
    double xax = 0.1*i + 0.05;
    modC[i] = 0.1*i + 0.05; 
    double entr = 0;
    double entrH = 0;
    for(int j = 0; j < 450; j++){

      double isony = j*45.0/450.0 + 0.05;

     
      int bin = IsoN_mCr->FindBin(xax,isony);  

      entr = entr + IsoN_mCr->GetBinContent(bin);
      IsoN[i][j] = entr;
      
      bin = IsoN_mCrH->FindBin(xax,isony);  
      entrH = entrH + IsoN_mCrH->GetBinContent(bin);
      IsoNH[i][j] = entrH;

      
    }
  }


  double m90[10] ={0}; 
  double m90H[10] ={0};

  double m80[10] ={0}; 
  double m80H[10] ={0};

  double m70[10] ={0}; 
  double m70H[10] ={0};

 
  for(int i  = 0; i < 10; i++){
    
    int i70 = 0; 
    int i80 = 0; 
    int i90 = 0; 
    int i70H = 0; 
    int i80H = 0; 
    int i90H = 0; 

    for(int j = 0; j  < 450 ; j++){
      
      if(IsoN[i][j]*1.0/IsoN[i][449] > 0.70 && i70 == 0 ){
	i70++;
	m70[i] = j*45.0/450; 	
      }

      if(IsoNH[i][j]*1.0/IsoNH[i][449] > 0.70 && i70H == 0 ){
	i70H++;
	m70H[i] = j*45.0/450; 	
      }


      if(IsoN[i][j]*1.0/IsoN[i][449] > 0.80 && i80 == 0 ){
	i80++;
	m80[i] = j*45.0/450; 	
      }

      if(IsoNH[i][j]*1.0/IsoNH[i][449] > 0.80 && i80H == 0 ){
	i80H++;
	m80H[i] = j*45.0/450; 	
      }

      
      if(IsoN[i][j]*1.0/IsoN[i][449] > 0.90 && i90 == 0 ){
	i90++;
	m90[i] = j*45.0/450; 	
      }

      if(IsoNH[i][j]*1.0/IsoNH[i][449] > 0.90 && i90H == 0 ){
	i90H++;
	m90H[i] = j*45.0/450; 	
      }




    }
  }


  TCanvas *c1 = new TCanvas("c1","",1200,600);
  c1->Divide(2,1);
  c1->cd(1);

  Mphi_D->Draw();
  Mphi_D->SetTitle("All signal photons");
  Mphi_D->GetXaxis()->SetTitle("phi % cryst phi dimension");
  Mphi_D->GetYaxis()->SetRangeUser(0.5,1);
  c1->cd(2);
  Mphi_DH->Draw();
  Mphi_DH->SetTitle("200 +  pt photons");
  Mphi_DH->GetXaxis()->SetTitle("phi % cryst phi dimension");
  Mphi_DH->GetYaxis()->SetRangeUser(0.5,1);

  c1->SaveAs("Modulated.png");


  TCanvas *c2 = new TCanvas("c2","",1200,600);
  c2->Divide(2,1);
  c2->cd(1);
  IsoN_mCr->Draw("colz");
  IsoN_mCr->SetTitle("All photons");
  IsoN_mCr->GetXaxis()->SetTitle("phi % cryst phi dimension");
  IsoN_mCr->GetYaxis()->SetTitle(" Iso N");

  c2->cd(2);
  IsoN_mCrH->Draw("colz");
  IsoN_mCrH->SetTitle("200+ pt photons");
  IsoN_mCrH->GetXaxis()->SetTitle("phi % cryst phi dimension");
  IsoN_mCrH->GetYaxis()->SetTitle("Iso N ");


  c2->SaveAs("IsoNvsMod.png");

  TGraph *n90 = new TGraph(10,modC,m90);
  TGraph *n80 = new TGraph(10,modC,m80);
  TGraph *n70 = new TGraph(10,modC,m70);

  TGraph *n90H = new TGraph(10,modC,m90H);
  TGraph *n80H = new TGraph(10,modC,m80H);
  TGraph *n70H = new TGraph(10,modC,m70H);


  
  
  n90->SetMarkerColor(kMagenta);
  n80->SetMarkerColor(kRed);
  n70->SetMarkerColor(kBlue);

  n90H->SetMarkerColor(kMagenta);
  n80H->SetMarkerColor(kRed);
  n70H->SetMarkerColor(kBlue);


  
  
  n90->SetMarkerStyle(26);
  n80->SetMarkerStyle(26);
  n70->SetMarkerStyle(26);

  n90H->SetMarkerStyle(26);
  n80H->SetMarkerStyle(26);
  n70H->SetMarkerStyle(26);



  
  n90->SetMarkerSize(1);
  n80->SetMarkerSize(1);
  n70->SetMarkerSize(1);

  n90H->SetMarkerSize(1);
  n80H->SetMarkerSize(1);
  n70H->SetMarkerSize(1);






  TMultiGraph * NIso = new TMultiGraph(); 
  TMultiGraph * NIsoH = new TMultiGraph(); 


  NIso->Add(n90,"p");
  NIso->Add(n80,"p");
  NIso->Add(n70,"p");

  NIsoH->Add(n90H,"p");
  NIsoH->Add(n80H,"p");
  NIsoH->Add(n70H,"p");





  TCanvas *c3 = new TCanvas("c3","Contours for IsoN",1200,600);  
  c3->Divide(2,1);
  c3->cd(1);

  NIso->Draw("AP");
  NIso->SetTitle("All photons");
  NIso->GetXaxis()->SetTitle("photon crystal modular position");
  
  c3->cd(2);
  NIsoH->Draw("AP");
  NIsoH->SetTitle("200+ pt photons");
  NIsoH->GetXaxis()->SetTitle("photon crystal modular position");
  
  c3->SaveAs("Niso_contours.png");



  TCanvas *c4 = new TCanvas("c4"," h o e",1200,600);  
  c4->Divide(2,1);
  c4->cd(1);

  HOE_mCr->Draw("colz");
  HOE_mCr->SetTitle("All photons");
  HOE_mCr->GetXaxis()->SetTitle("phi % cryst phi dimension");
  HOE_mCr->GetYaxis()->SetTitle(" H over E");
  c4->cd(2);
  HOE_mCrH->Draw("colz");
  HOE_mCrH->SetTitle("200+ pt photons");
  HOE_mCrH->GetXaxis()->SetTitle("phi % cryst phi dimension");
  HOE_mCrH->GetYaxis()->SetTitle(" H over E");

  
  c4->SaveAs("HOE.png");

  





}
