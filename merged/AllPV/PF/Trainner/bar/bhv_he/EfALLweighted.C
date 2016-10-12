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

void EfALLweighted(){
  
  
  ifstream tight; 
  ifstream medium; 
  ifstream loose; 
  

  tight.open("TightR.txt");
  medium.open("MediumR.txt");
  loose.open("LooseR.txt");


  double efL,efM,efT,bkL,bkM,bkT; 
  double IsoPcutL,IsoPcutM,IsoPcutT,IsoCcutL,IsoCcutM,IsoCcutT,IsoNcutL,IsoNcutM,IsoNcutT,SieiecutL,SieiecutM,SieiecutT,HoEcutL,HoEcutM,HoEcutT;

  HoEcutL = 0.05; 
  HoEcutM = 0.05; 
  HoEcutT = 0.05; 

  
  if(tight.is_open()){
    while(!tight.eof()){
      
      tight>>SieiecutT>>IsoCcutT>>IsoNcutT>>IsoPcutT;
      break;
    }
  }
    
  if(medium.is_open()){
    while(!medium.eof()){
      
      medium>>SieiecutM>>IsoCcutM>>IsoNcutM>>IsoPcutM;
      break;

    }
  }
    
  

  if(loose.is_open()){
    while(!loose.eof()){
      
      loose>>SieiecutL>>IsoCcutL>>IsoNcutL>>IsoPcutL;
      break;

    }
  }

  cout<<"Cuts loose "<<endl;
  cout<<SieiecutL<<endl;
  //  cout<<HoEcutL<<endl;
  cout<<IsoCcutL<<endl;
  cout<<IsoNcutL<<endl;
  cout<<IsoPcutL<<endl;




  //OLD ENDCAP CUTS 

  double OisCL = 2.6;
  double OisCM = 1.5; 
  double OisCT = 0.7; 
  
  double OisPL = 1.3; 
  double OisPM = 0.7; 
  double OisPT = 0.5; 

  double OisNL = 3.5; 
  double OisNM = 1.0; 
  double OisNT = 0.4; 

  double OtL = 0.05; 
  double OtM = 0.05; 
  double OtT = 0.05; 

  double OsL = 0.012; 
  double OsM = 0.011; 
  double OsT = 0.011; 


  Double_t  bin_lows[107] ={0}; 

  for(int i =0; i < 107; i++){

    if(i <= 100 ){
      bin_lows[i] = i*2.0;
      cout<<i<<"  " <<i*2<<endl;
    }

    if(i > 100 ){
      bin_lows[i] = (i - 100.0  + 1)*100.0 + 100.0;
      
      cout<<i <<"  "<<(i - 100.0 + 1 )*100.0 + 100.0<<endl;

    }
  }
  
  TH1F *pTt = new TH1F("pTt","pT range",105,bin_lows);
  TH1F *EffPT0   = new TH1F("EffPT0","Signal Eff vs PT 0",105,bin_lows);


  

  TH1F *EffNVTX0 = new TH1F("EffNVTX0","Signal Eff vs NVTX 0",100,0,100);
  TH1F *EffETA0  = new TH1F("EffETA0","Signal Eff vs Eta 0",100,0,5);

  TH1F *EffNVTXM  = new TH1F("EffNVTXM","Signal Eff vs NVTX",100,0,100);
  TH1F *EffPTM    = new TH1F("EffPTM","Signal Eff vs PT",105,bin_lows);
  TH1F *EffETAM   = new TH1F("EffETAM","Signal Eff vs Eta",100,0,5);

  TH1F *EffNVTXL  = new TH1F("EffNVTXL","Signal Eff vs NVTX",100,0,100);
  TH1F *EffPTL    = new TH1F("EffPTL","Signal Eff vs PT",105,bin_lows);
  TH1F *EffETAL  = new TH1F("EffETAL","Signal Eff vs Eta",100,0,5);

  TH1F *EffNVTXT  = new TH1F("EffNVTXT","Signal Eff vs NVTX",100,0,100);
  TH1F *EffPTT    = new TH1F("EffPTT","Signal Eff vs PT",105,bin_lows);
  TH1F *EffETAT   = new TH1F("EffETAT","Signal Eff vs Eta",100,0,5);

  TH1F *BckNVTX0 = new TH1F("BckNVTX0","Bck Rej vs NVTX 0",100,0,100);
  TH1F *BckPT0   = new TH1F("BckPT0","Bck Rej vs PT 0",105,bin_lows);
  TH1F *BckETA0  = new TH1F("BckETA0","Bck Rej vs Eta",100,0,5);

  TH1F *BckNVTXL = new TH1F("BckNVTXL","Bck Rej vs NVTX",100,0,100);
  TH1F *BckPTL   = new TH1F("BckPTL","Bck Rej vs PT",105,bin_lows);
  TH1F *BckETAL  = new TH1F("BckETAL","Bck Rej vs Eta",100,0,5);

  TH1F *BckNVTXM = new TH1F("BckNVTXM","Bck Rej vs NVTX",100,0,100);
  TH1F *BckPTM   = new TH1F("BckPTM","Bck Rej vs PT",105,bin_lows);
  TH1F *BckETAM  = new TH1F("BckETAM","Bck Rej vs Eta",100,0,5);

  TH1F *BckNVTXT = new TH1F("BckNVTXT","Bck Rej vs NVTX",100,0,100);
  TH1F *BckPTT   = new TH1F("BckPTT","Bck Rej vs PT",105,bin_lows);
  TH1F *BckETAT  = new TH1F("BckETAT","Bck Rej vs Eta",100,0,5);


  TH1F *EffPTs  = new TH1F("EffPTs","Signal Eff sIEIE vs PT ",105,bin_lows);
  TH1F *EffPTt   = new TH1F("EffPTt","Signal Eff hOE   vs PT ",105,bin_lows);
  TH1F *EffPTp   = new TH1F("EffPTp","Signal Eff ISOp  vs PT ",105,bin_lows);
  TH1F *EffPTc   = new TH1F("EffPTc","Signal Eff ISOc  vs PT ",105,bin_lows);
  TH1F *EffPTn   = new TH1F("EffPTn","Signal Eff ISON  vs PT ",105,bin_lows);


  TH1F *EffPTc1   = new TH1F("EffPTc1","Signal Eff vs PT c1",105,bin_lows);
  TH1F *EffPTc2   = new TH1F("EffPTc2","Signal Eff vs PT c2",105,bin_lows);
  TH1F *EffPTc3   = new TH1F("EffPTc3","Signal Eff vs PT c3",105,bin_lows);
  TH1F *EffPTc4   = new TH1F("EffPTc4","Signal Eff vs PT c4",105,bin_lows);
  TH1F *EffPTc5   = new TH1F("EffPTc5","Signal Eff vs PT c5",105,bin_lows);

  TH1F *Ptweight   = new TH1F("Ptweight"," weight pt for both samples",105,bin_lows);
  TH1F *Ptw   = new TH1F("Ptw"," weight pt for both samples",105,bin_lows);
  TH1F *PtweightB   = new TH1F("PtweightB"," weight pt for both samples BACK",105,bin_lows);
  TH1F *PtwB   = new TH1F("PtwB"," weight pt for both samples BACK",105,bin_lows);

  TH2D *SiePt   = new TH2D("SiePt","Sieie vs PT ",105,bin_lows,1000,0,0.1);
  TH2D *ToEPt   = new TH2D("ToEPt","Toe vs PT   ",105,bin_lows,5000,0,5);
  TH2D *IsoPPt   = new TH2D("IsoPPt","IsoP vs PT ",105,bin_lows,100000,0,100);
  TH2D *IsoCPt   = new TH2D("IsoCPt","IsoC vs PT ",105,bin_lows,100000,0,100);
  TH2D *IsoNPt   = new TH2D("IsoNPt","IsoN vs PT ",105,bin_lows,100000,0,100);



  Input file:
  TFile *f400 = new TFile( "../../../CutTMVABarrel90_HPT.root");
  //TFile *f400 = new TFile( "../../../isopt/Sample_15to6000/CutTMVABarrel_HPT15to6000.root");
    

  // --- Register the regression tree
  float Ppt,peta,Sie_ie,iso_P,genPt,iso_C,iso_N,to_e,weightXS,weighT;

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
  t_S->SetBranchAddress("genPt",&genPt);
  t_S->SetBranchAddress("Pix",&Pix);

  //Background Tree
  t_B->SetBranchAddress("Sieie",&Sie_ie);
  t_B->SetBranchAddress("isoP",&iso_P);
  t_B->SetBranchAddress("isoC",&iso_C);
  t_B->SetBranchAddress("isoN",&iso_N);
  t_B->SetBranchAddress("ToE",&to_e);

  t_B->SetBranchAddress("weighT",&weighT);
  t_B->SetBranchAddress("Nvtx",&nvtx);
  t_B->SetBranchAddress("Peta",&peta);
  t_B->SetBranchAddress("Ppt",&Ppt);
  t_B->SetBranchAddress("Pix",&Pix);



  EffNVTX0->Sumw2();
  EffPT0->Sumw2();
  EffETA0->Sumw2();
  
  EffNVTXT->Sumw2();
  EffPTT->Sumw2();
  EffETAT->Sumw2();
  
  EffNVTXM->Sumw2();
  EffPTM->Sumw2();
  EffETAM->Sumw2();
  
  EffNVTXL->Sumw2();
  EffPTL->Sumw2();
  EffETAL->Sumw2();
  
  BckNVTX0->Sumw2();
  BckPT0->Sumw2();
  BckETA0->Sumw2();
  
  BckNVTXT->Sumw2();
  BckPTT->Sumw2();
  BckETAT->Sumw2();
  
  BckNVTXM->Sumw2();
  BckPTM->Sumw2();
  BckETAM->Sumw2();
  
  BckNVTXL->Sumw2();
  BckPTL->Sumw2();
  BckETAL->Sumw2();

  
  EffPTc1->Sumw2();
  EffPTc2->Sumw2();
  EffPTc3->Sumw2();
  EffPTc4->Sumw2();
  EffPTc5->Sumw2();


  EffPTs->Sumw2();
  EffPTt->Sumw2();
  EffPTp->Sumw2();
  EffPTc->Sumw2();
  EffPTn->Sumw2();







  //here starts the actuall evealuation of the efficiencies weighted in pt
  double LoosSEf = 0; 
  double TightSEf = 0; 
  double MediumSEf = 0; 


  double LoosBckR = 0; 
  double TightBckR = 0; 
  double MediumBckR = 0; 
  double totS = 0; 
  for(int i  = 0 ; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);



    double slopeP = 0.0053; 
    double slopeN = 0.014*Ppt  + 0.000019*Ppt*Ppt;


    //    if(Ppt > 200 ) cout<< "!!!"<<endl;
   
    
    if(Ppt > 200)      weighT = 1.0 ;
        EffPT0->Fill(Ppt, weighT);



    //    if(Pix==1) continue;
    if(Ppt < 20 ) continue;
    totS = totS+ weighT ; 


    pTt->Fill(Ppt);

    Ptw->Fill(Ppt, weighT);
    EffNVTX0->Fill(nvtx, weighT);
    EffETA0->Fill(peta, weighT);


    SiePt->Fill(Ppt,Sie_ie, weighT); 
    ToEPt->Fill(Ppt,to_e, weighT);
    IsoPPt->Fill(Ppt,iso_P, weighT);
    IsoCPt->Fill(Ppt,iso_C, weighT);
    IsoNPt->Fill(Ppt,iso_N, weighT);




    //bRANCH OUT cuts

    if( Sie_ie < SieiecutL ){ 


      EffPTs->Fill(Ppt, weighT);
      
    }

    if( to_e<HoEcutL ){
	EffPTt->Fill(Ppt, weighT);

    }
   
    if( (iso_P < IsoPcutL + slopeP*Ppt ) ){
	  EffPTp->Fill(Ppt, weighT);
    }

    
    if( (iso_N < IsoNcutL + slopeN ) ){
	  EffPTn->Fill(Ppt, weighT);
    }

    if( (iso_C < IsoCcutL  ) ){
	  EffPTc->Fill(Ppt, weighT);
    }








    //Sequential APplication of Cuts


    if( Sie_ie < SieiecutL  ){ 
      EffPTc1->Fill(Ppt, weighT);
      if( to_e<HoEcutL ){
	EffPTc2->Fill(Ppt, weighT);
	if( (iso_P < IsoPcutL +slopeP*Ppt) ){
	  EffPTc3->Fill(Ppt, weighT);
	  if( (iso_N < IsoNcutL +slopeN) ){
	    EffPTc4->Fill(Ppt, weighT);
	    if(  iso_C < IsoCcutL  ){
	      EffPTc5->Fill(Ppt, weighT);
	    }
	  }
	}
      }
    }
   

    
    //Calculating the Efficiencies for the Loose Set of Cuts 
    if((iso_P < IsoPcutL+slopeP*Ppt)&&(iso_N < IsoNcutL+slopeN)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosSEf = LoosSEf +  weighT;
      
      EffNVTXL->Fill(nvtx, weighT);
      EffPTL->Fill(Ppt, weighT);
      EffETAL->Fill(peta, weighT);
            
    }
    
    if((iso_P < IsoPcutM+slopeP*Ppt)&&(iso_N < IsoNcutM+slopeN)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM )){
      MediumSEf = MediumSEf +  weighT;
      
      EffNVTXM->Fill(nvtx, weighT);
      EffPTM->Fill(Ppt, weighT);
      EffETAM->Fill(peta, weighT);
      
      
    }
    
    if((iso_P < IsoPcutT + slopeP*Ppt)&&(iso_N < IsoNcutT + slopeN)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT )){
      TightSEf = TightSEf +  weighT;
      
      
      EffNVTXT->Fill(nvtx, weighT);
      EffPTT->Fill(Ppt, weighT);
      EffETAT->Fill(peta, weighT);
      
      
    }
    
  }
  




  double totB = 0; 
  for(int i  = 0 ; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    
    if(Ppt > 200 )  weighT = 1;

    //  if(Pix==1) continue;
    if(Ppt < 20 ) continue;
    totB = totB+  weighT;


    PtwB->Fill(Ppt,weighT);

    double weight = weighT;
    BckNVTX0->Fill(nvtx, weighT);
    BckPT0->Fill(Ppt, weighT);
    BckETA0->Fill(peta, weighT);    
 
    //Calculating the Efficiencies for the Loose Set of Cuts 
    if((iso_P < IsoPcutL+slopeP*Ppt)&&(iso_N < IsoNcutL + slopeN)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosBckR = LoosBckR +  weighT;
      
      BckNVTXL->Fill(nvtx, weighT);
      BckPTL->Fill(Ppt, weighT);
      BckETAL->Fill(peta, weighT);    
      
    }
    
    if((iso_P < IsoPcutM+slopeP*Ppt)&&(iso_N < IsoNcutM+slopeN)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM )){
      MediumBckR = MediumBckR +  weighT;
      
      BckNVTXM->Fill(nvtx, weighT);
      BckPTM->Fill(Ppt, weighT);
      BckETAM->Fill(peta, weighT);    
      
      
    }
    
    if((iso_P < IsoPcutT+slopeP*Ppt)&&(iso_N < IsoNcutT+slopeN)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT )){
      TightBckR = TightBckR +  weighT;
      
      BckNVTXT->Fill(nvtx, weighT);
      BckPTT->Fill(Ppt, weighT);
      BckETAT->Fill(peta,weighT);    
      
      
    }
    
    
  }// Eoff Back ground tree for Sig Back 




  TFile *f1_0 = new TFile("EffStudiesLIN.root","RECREATE");
  f1_0->cd();

  
  
  
  
  
  
  
  
  
  EffNVTX0->Write();
  EffPT0->Write(); 
  EffETA0->Write();
  
  EffNVTXT->Write();
  EffPTT->Write(); 
  EffETAT->Write();
  
  EffNVTXM->Write();
  EffPTM->Write(); 
  EffETAM->Write();
  
  EffNVTXL->Write();
  EffPTL->Write(); 
  EffETAL->Write();
  
  BckNVTX0->Write();
  BckPT0->Write(); 
  BckETA0->Write();
    
  BckNVTXT->Write();
  BckPTT->Write(); 
  BckETAT->Write();
  
  BckNVTXM->Write();
  BckPTM->Write(); 
  BckETAM->Write();
  
  BckNVTXL->Write();
  BckPTL->Write(); 
  BckETAL->Write();
  
  
  EffPTc1->Write(); 
  EffPTc2->Write();
  EffPTc3->Write();
  EffPTc4->Write();
  EffPTc5->Write();
  
  
  SiePt->Write(); 
  ToEPt->Write(); 
  IsoPPt->Write();
  IsoCPt->Write();
  IsoNPt->Write();
  
  EffPTs->Write();
  EffPTt->Write();
  EffPTp->Write();
  EffPTc->Write();
  EffPTn->Write();

  PtweightB->Write();
  PtwB->Write();
  Ptw->Write();
  Ptweight->Write();

  pTt->Write();


}
