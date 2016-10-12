void ModCryst(){


  ifstream tight;
  ifstream medium;
  ifstream loose;


  tight.open("TightR.txt");
  medium.open("MediumR.txt");
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

  TH1F *Mphi_s = new TH1F("Mphi_s"," Sig ",20,0,1.0);
  TH1F *Mphi_sALL = new TH1F("Mphi_sALL"," Sig ",20,0,1.0);

  TH1F *Mphi_sH = new TH1F("Mphi_sH"," Sig ",20,0,1.0);
  TH1F *Mphi_sALLH = new TH1F("Mphi_sALLH"," Sig ",20,0,1.0);



  TH1F *Mphi_D = new TH1F("Mphi_D"," Bck ",20,0,1.0);

  TH1F *Mphi_DH = new TH1F("Mphi_DH"," Bck ",20,0,1.0);

  float Ppt,Pphi,peta,Sie_ie,iso_P,genPt,iso_C,iso_N,to_e,weightXS,weighT;

  int nvtx,Pix;



  //Signal Tree

  t_S->SetBranchAddress("Sieie",&Sie_ie);
  t_S->SetBranchAddress("isoP",&iso_P);
  t_S->SetBranchAddress("isoC",&iso_C);
  t_S->SetBranchAddress("isoN",&iso_N);
  t_S->SetBranchAddress("ToE",&to_e);

  t_S->SetBranchAddress("weighT",&weighT);
  t_S->SetBranchAddress("Nvtx",&nvtx);
  t_S->SetBranchAddress("Peta",&peta);
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

    double phi = Pphi*180.0/TMath::Pi();

    Mphi_sALL->Fill(fabs(fmod(phi,1)));


    // cout<<fabs(fmod(phi,1))<<endl;




    if(Ppt > 200 ) Mphi_sALLH->Fill(fabs(fmod(phi,1)));


    if(iso_P < IsoPcutL+slopeP*Ppt){

	 if(iso_N < IsoNcutL+slopeN*Ppt){



	   if(iso_C < IsoCcutL){

	     if(to_e<HoEcutL){

	       if(Sie_ie < SieiecutL ){

		 Mphi_s->Fill(fabs(fmod(phi,1)));
		 if(Ppt > 200 )    Mphi_sH->Fill(fabs(fmod(phi,1)));

	       }}}}}

  }

  Mphi_D->Divide(Mphi_s,Mphi_sALL,1.,1.,"B");
  Mphi_DH->Divide(Mphi_sH,Mphi_sALLH,1.,1.,"B");


  TCanvas *c1 = new TCanvas("c1","",900,900);
  c1->Divide(2,1);
  c1->cd(1);
  Mphi_D->Draw();
  Mphi_D->GetXaxis()->SetTitle("phi % cryst phi dimension");

  c1->cd(2);
  Mphi_DH->Draw();
  Mphi_DH->GetXaxis()->SetTitle("phi % cryst phi dimension");

  c1->SaveAs("Modulated.png");




}
