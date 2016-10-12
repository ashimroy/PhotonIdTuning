#include <cstdlib>
#include <TMath.h>


void Scr99(){


  TFile *f1 = new TFile("/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/ChEA_trainner/CutTMVAEndCap90.root");


  float ToE,Sie,IsoP,IsoC,IsoN,weighT,Ppt; 

  ofstream myfile; 
  myfile.open("99per.txt");

  t_S->SetBranchAddress("Ppt",&Ppt);
  t_S->SetBranchAddress("ToE",&ToE);
  t_S->SetBranchAddress("Sieie",&Sie);
  t_S->SetBranchAddress("isoP",&IsoP);
  t_S->SetBranchAddress("isoC",&IsoC);
  t_S->SetBranchAddress("isoN",&IsoN);
  //  t_S->SetBranchAddress("weighT",&weighT);

  weighT = 1;

  TH1F *HS = new TH1F("HS","sieie ",10000,0,0.5);
  TH1F *HH = new TH1F("HH","h over e ",10000,0,0.5);
  TH1F *HP = new TH1F("HP","photon  iso ",10000,0,205);
  TH1F *HC = new TH1F("HC","charge  iso ",10000,0,255);
  TH1F *HN = new TH1F("HN","neutral iso ",10000,0,75);

  TH1F *W = new TH1F("W","weights  ",3,0,3);

  // cout<<t_S->GetEntries()<<endl;

  double max_s,max_p,max_n,max_c,max_t; 
  max_s = 0; 
  max_p = 0; 
  max_c = 0; 
  max_n = 0; 
  max_t = 0; 
  double totS = 0; 
  for(int i = 0; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);

    if(Ppt < 20 ) continue;
    if(Ppt > 200 ) continue;
 
    if(Sie > max_s)max_s = Sie; 
    if(ToE > max_s)max_t = ToE; 
    

    if(weighT  == 0) cout<<weighT<<endl;
    
 
    totS += weighT;
    W->Fill(1.0,weighT);
    // cout<<weighT<<endl;
    HH->Fill(ToE,weighT);
    HS->Fill(Sie,weighT);
    
    double isoph = TMath::Max(IsoP - 0.0036*Ppt,0.0);
    double isoneu = TMath::Max(IsoN - (0.0153*Ppt+0.000016*Ppt*Ppt),0.0);

    //double isoph = TMath::Max(IsoP - 0.0034*Ppt,0.0);
    //double isoneu = TMath::Max(IsoN - (0.0139*Ppt+0.000025*Ppt*Ppt),0.0);

    if(isoph  > max_p)max_p = isoph; 
    if(IsoC   > max_c)max_c = IsoC; 
    if(isoneu > max_n)max_n = isoneu; 


    HP->Fill(isoph,weighT);
    HC->Fill(IsoC,weighT);
    HN->Fill(isoneu,weighT);
  }


  /*
  cout<<"p"<<max_p<<endl;
  cout<<"n"<<max_n<<endl;
  cout<<"c"<<max_c<<endl;
  cout<<"t"<<max_t<<endl;
  cout<<"s"<<max_s<<endl;
 
  */
  cout<<" totals  "<<totS<<endl;
  
  double xcsf=0; 
  double xchf=0; 
  double xcpf=0; 
  double xccf=0; 
  double xcnf=0; 
  
  
  int p1 = 0;
  int p2 = 0;
  int p3 = 0;
  int p4 = 0;
  int p5 = 0;
  /*
  cout<<"tOE"<<HH->Integral()<<" "<<totS<<endl;
  cout<<"pHOTON"<<HP->Integral()<<" "<<totS<<endl;
  cout<<"CHARGE"<<HC->Integral()<<" "<<totS<<endl;
  cout<<"nEUTRAL"<<HN->Integral()<<" "<<totS<<endl;
  cout<<"sIE"<<HS->Integral()<<" "<<totS<<endl;
  */

  double sie_b = 0; 
  double neu_b = 0; 
  double pho_b = 0; 
  double chg_b = 0; 
  double toe_b = 0; 

  for(int i = 1 ; i <= 10000; i++){
    double xcs = (i*0.5)/10000; 
    double xch = (i*0.5)/10000; 
    double xcp = (i*205.0)/10000; 
    double xcc = (i*255.0)/10000; 
    double xcn = (i*75.0)/10000; 
    

   sie_b += HS->GetBinContent(i);
   toe_b += HH->GetBinContent(i);
   pho_b += HP->GetBinContent(i);
   neu_b += HN->GetBinContent(i);
   chg_b += HC->GetBinContent(i);


   int bin = HS->FindBin(xcs);
   //cout<<i<<" "<<(HH->Integral(1,i))/(HH->Integral()*1.0)<<" "<<(HH->Integral(1,i))/(totS*1.0)<<endl;


   if(1.0*HS->Integral(1,i)/totS > 0.9999 && p1 == 0){
  
     p1 = 1;
     xcsf = xcs; 
 
   }

  bin = HH->FindBin(xch);
  // cout<<1.0*HH->Integral(1,i)/totS<<endl;
  if(1.0*HH->Integral(1,i)/totS > 0.9999 && p2 == 0){
 
    xchf = xch; 
    p2 =1;
  }
   bin = HP->FindBin(xcp);
   // cout<<1.0*HP->Integral(1,i)/totS<<endl;

   if(1.0*HP->Integral(1,i)/totS > 0.9999 && p3 == 0){
  
     xcpf = xcp; 
     p3 = 1; 
   }
  bin = HC->FindBin(xcc);
  if(1.0*HC->Integral(1,i)/totS > 0.9999 && p4 == 0){

    xccf = xcc; 
    p4 = 1; 
  }
  bin = HN->FindBin(xcn);
  //  cout<<1.0*HN->Integral(1,i)/totS<<" "<<p5<<endl;
  if(1.0*HN->Integral(1,i)/totS > 0.9999 && p5 == 0){

    p5 = 1;
    xcnf = xcn; 
  }
  }
  
  myfile<<xcsf<<endl;
  myfile<<xchf<<endl;
  myfile<<xccf<<endl;
  myfile<<xcnf<<endl;
  myfile<<xcpf<<endl;

  myfile.close();
  /*
  cout<<sie_b/totS<<endl;
  cout<<toe_b/totS<<endl;
  cout<<pho_b/totS<<endl;
  cout<<chg_b/totS<<endl;
  cout<<neu_b/totS<<endl;



  cout<<"Sie  :"<<xcsf<<endl;
  cout<<"HoE  :"<<xchf<<endl;
  cout<<"IsoP :"<<xcpf<<endl;
  cout<<"IsoC :"<<xccf<<endl;
  cout<<"IsoN :"<<xcnf<<endl;
  */
  TFile *f1 = new TFile("Vars.root","recreate");
  HS->Write();
  HH->Write();
  HP->Write();
  HC->Write();
  HN->Write();
  W->Write();
  


}
