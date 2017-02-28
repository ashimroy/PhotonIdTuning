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

void PlotBuilder(){


  //Read the cuts: 


  ifstream tight;
  ifstream medium;
  ifstream loose;


  tight.open("TightR.txt");
  medium.open("MediumR.txt");
  loose.open("LooseR.txt");


  double isoCL,isoCM,isoCT;
  double isoPL,isoPM,isoPT;
  double isoNL,isoNM,isoNT;
  double sieL,sieM,sieT; 
  double hoeU = 0.05;

  if(tight.is_open()){
    while(!tight.eof()){
      tight>>sieT>>isoCT>>isoNT>>isoPT;
      break;
    }
  }

  
  if(medium.is_open()){
    while(!medium.eof()){
      medium>>sieM>>isoCM>>isoNM>>isoPM;
      break;
    }
  }


  if(loose.is_open()){
    while(!loose.eof()){
      loose>>sieL>>isoCL>>isoNL>>isoPL;
      break;
    }
  }

  //Read the Cuts. Now test them


  TH1F *EffNVTX0 = new TH1F("EffNVTX0","Signal Eff vs NVTX 0",100,0,100);
  TH1F *EffPT0   = new TH1F("EffPT0","Signal Eff vs PT 0",100,0,800);
  TH1F *EffETA0  = new TH1F("EffETA0","Signal Eff vs Eta 0",100,-5,5);
  TH1F *EffPHI0  = new TH1F("EffPHI0","Signal Eff vs PHI 0",100,-4,4);

  TH1F *EffNVTXL = new TH1F("EffNVTXL","Signal Eff vs NVTX L",100,0,100);
  TH1F *EffPTL   = new TH1F("EffPTL","Signal Eff vs PT L",100,0,800);
  TH1F *EffETAL  = new TH1F("EffETAL","Signal Eff vs Eta L",100,-5,5);
  TH1F *EffPHIL  = new TH1F("EffPHIL","Signal Eff vs PHI L",100,-4,4);
  
  TH1F *EffNVTXM = new TH1F("EffNVTXM","Signal Eff vs NVTX M",100,0,100);
  TH1F *EffPTM   = new TH1F("EffPTM","Signal Eff vs PT M",100,0,800);
  TH1F *EffETAM  = new TH1F("EffETAM","Signal Eff vs Eta M",100,-5,5);
  TH1F *EffPHIM  = new TH1F("EffPHIM","Signal Eff vs PHI M",100,-4,4);

  TH1F *EffNVTXT = new TH1F("EffNVTXT","Signal Eff vs NVTX T",100,0,100);
  TH1F *EffPTT   = new TH1F("EffPTT","Signal Eff vs PT T",100,0,800);
  TH1F *EffETAT  = new TH1F("EffETAT","Signal Eff vs Eta T",100,-5,5);
  TH1F *EffPHIT  = new TH1F("EffPHIT","Signal Eff vs PHI T",100,-4,4);

  TH1F *EffNVTX0b = new TH1F("EffNVTX0b","Signal Eff vs NVTX 0",100,0,100);
  TH1F *EffPT0b   = new TH1F("EffPT0b","Signal Eff vs PT 0",100,0,800);
  TH1F *EffETA0b  = new TH1F("EffETA0b","Signal Eff vs Eta 0",100,-5,5);
  TH1F *EffPHI0b  = new TH1F("EffPHI0b","Signal Eff vs PHI 0",100,-4,4);

  TH1F *EffNVTXLb = new TH1F("EffNVTXLb","Signal Eff vs NVTX L",100,0,100);
  TH1F *EffPTLb   = new TH1F("EffPTLb","Signal Eff vs PT L",100,0,800);
  TH1F *EffETALb  = new TH1F("EffETALb","Signal Eff vs Eta L",100,-5,5);
  TH1F *EffPHILb  = new TH1F("EffPHILb","Signal Eff vs PHI L",100,-4,4);
  
  TH1F *EffNVTXMb = new TH1F("EffNVTXMb","Signal Eff vs NVTX M",100,0,100);
  TH1F *EffPTMb   = new TH1F("EffPTMb","Signal Eff vs PT M",100,0,800);
  TH1F *EffETAMb  = new TH1F("EffETAMb","Signal Eff vs Eta M",100,-5,5);
  TH1F *EffPHIMb  = new TH1F("EffPHIMb","Signal Eff vs PHI M",100,-4,4);

  TH1F *EffNVTXTb = new TH1F("EffNVTXTb","Signal Eff vs NVTX T",100,0,100);
  TH1F *EffPTTb  = new TH1F("EffPTTb","Signal Eff vs PT T",100,0,800);
  TH1F *EffETATb  = new TH1F("EffETATb","Signal Eff vs Eta T",100,-5,5);
  TH1F *EffPHITb  = new TH1F("EffPHITb","Signal Eff vs PHI T",100,-4,4);

  // Branch out Cuts

   
  TH1F *EffNVTXs = new TH1F("EffNVTXs","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTs  = new TH1F("EffPTs","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAs  = new TH1F("EffETAs","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXt = new TH1F("EffNVTXt","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTt  = new TH1F("EffPTt","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAt  = new TH1F("EffETAt","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXc = new TH1F("EffNVTXc","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTc  = new TH1F("EffPTc","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAc  = new TH1F("EffETAc","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXn = new TH1F("EffNVTXn","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTn  = new TH1F("EffPTn","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAn  = new TH1F("EffETAn","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXp = new TH1F("EffNVTXp","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTp  = new TH1F("EffPTp","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAp  = new TH1F("EffETAp","Signal Eff vs PT T s",100,-5,5);


  TH1F *EffNVTXbs = new TH1F("EffNVTXbs","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTbs  = new TH1F("EffPTbs","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAbs  = new TH1F("EffETAbs","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXbt = new TH1F("EffNVTXbt","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTbt  = new TH1F("EffPTbt","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAbt  = new TH1F("EffETAbt","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXbc = new TH1F("EffNVTXbc","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTbc  = new TH1F("EffPTbc","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAbc  = new TH1F("EffETAbc","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXbn = new TH1F("EffNVTXbn","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTbn  = new TH1F("EffPTbn","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAbn  = new TH1F("EffETAbn","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffNVTXbp = new TH1F("EffNVTXbp","Signal Eff vs NVTX T s",100,0,100);
  TH1F *EffPTbp  = new TH1F("EffPTbp","Signal Eff vs PT T s",100,0,800);
  TH1F *EffETAbp  = new TH1F("EffETAbp","Signal Eff vs PT T s",100,-5,5);

  TH1F *EffPTMs  = new TH1F("EffPTMs","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTMt  = new TH1F("EffPTMt","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTMc  = new TH1F("EffPTMc","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTMp  = new TH1F("EffPTMp","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTMn  = new TH1F("EffPTMn","Signal Eff vs PT T s",100,0,800);


  TH1F *EffPTTs  = new TH1F("EffPTTs","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTTt  = new TH1F("EffPTTt","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTTc  = new TH1F("EffPTTc","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTTp  = new TH1F("EffPTTp","Signal Eff vs PT T s",100,0,800);
  TH1F *EffPTTn  = new TH1F("EffPTTn","Signal Eff vs PT T s",100,0,800);

 




  
  //Setting the Tree Branches

  TFile *finput = new TFile("../../../Isopt/CutTMVABarrel90_HPT.root");
  float Ppt,Peta,Pphi,isoP,isoC,isoN,sieie,toe,weight;
  int   nvtx; 
  
  //  weight = 1.0; 

  finput->cd();
  //Signal Tree                                                                 
  t_S->SetBranchAddress("Sieie",&sieie);
  t_S->SetBranchAddress("isoP",&isoP);
  t_S->SetBranchAddress("isoC",&isoC);
  t_S->SetBranchAddress("isoN",&isoN);
  t_S->SetBranchAddress("ToE",&toe);
  t_S->SetBranchAddress("weighT",&weight);
  t_S->SetBranchAddress("Nvtx",&nvtx);
  t_S->SetBranchAddress("Peta",&Peta);
  t_S->SetBranchAddress("Ppt",&Ppt);

  //Background Tree                                                                 
  t_B->SetBranchAddress("Sieie",&sieie);
  t_B->SetBranchAddress("isoP",&isoP);
  t_B->SetBranchAddress("isoC",&isoC);
  t_B->SetBranchAddress("isoN",&isoN);
  t_B->SetBranchAddress("ToE",&toe);
  t_B->SetBranchAddress("weighT",&weight);
  t_B->SetBranchAddress("Nvtx",&nvtx);
  t_B->SetBranchAddress("Peta",&Peta);
  t_B->SetBranchAddress("Ppt",&Ppt);


  
  EffNVTX0->Sumw2();
  EffPT0->Sumw2();
  EffETA0->Sumw2();
  EffPHI0->Sumw2();
  
  EffNVTXL->Sumw2();
  EffPTL->Sumw2();
  EffETAL->Sumw2();
  EffPHIL->Sumw2();
  
  EffNVTXM->Sumw2();
  EffPTM->Sumw2();
  EffETAM->Sumw2();
  EffPHIM->Sumw2();
  
  EffNVTXT->Sumw2();
  EffPTT->Sumw2();
  EffETAT->Sumw2();
  EffPHIT->Sumw2();
  
  
  EffNVTX0b->Sumw2();
  EffPT0b->Sumw2();
  EffETA0b->Sumw2();
  EffPHI0b->Sumw2();
  
  EffNVTXLb->Sumw2();
  EffPTLb->Sumw2();
  EffETALb->Sumw2();
  EffPHILb->Sumw2();
  
  EffNVTXMb->Sumw2();
  EffPTMb->Sumw2();
  EffETAMb->Sumw2();
  EffPHIMb->Sumw2();
  
  EffNVTXTb->Sumw2();
  EffPTTb->Sumw2();
  EffETATb->Sumw2();
  EffPHITb->Sumw2(); 

  
  EffNVTXs->Sumw2();
  EffPTs->Sumw2();
  EffETAs->Sumw2();
  
  EffNVTXt->Sumw2();
  EffPTt->Sumw2();
  EffETAt->Sumw2();
  
  EffNVTXc->Sumw2();
  EffPTc->Sumw2();
  EffETAc->Sumw2();
  
  EffNVTXn->Sumw2();
  EffPTn->Sumw2();
  EffETAn->Sumw2();

  EffNVTXp->Sumw2();
  EffPTp->Sumw2();
  EffETAp->Sumw2();

  
  EffNVTXbs->Sumw2();
  EffPTbs->Sumw2();
  EffETAbs->Sumw2();

  EffNVTXbt->Sumw2();
  EffPTbt->Sumw2();
  EffETAbt->Sumw2();

  EffNVTXbc->Sumw2();
  EffPTbc->Sumw2();
  EffETAbc->Sumw2();

  EffNVTXbn->Sumw2();
  EffPTbn->Sumw2();
  EffETAbn->Sumw2();

  EffNVTXbp->Sumw2();
  EffPTbp->Sumw2();
  EffETAbp->Sumw2();

      
  EffPTMs->Sumw2();
  EffPTMt->Sumw2();
  EffPTMc->Sumw2();
  EffPTMp->Sumw2();
  EffPTMn->Sumw2();
    
  EffPTTs->Sumw2();
  EffPTTt->Sumw2();
  EffPTTc->Sumw2();
  EffPTTp->Sumw2();
  EffPTTn->Sumw2();



  for(int i = 0; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);
    
    EffNVTX0->Fill(nvtx,weight);
    EffPT0->Fill(Ppt,weight);
    EffETA0->Fill(Peta,weight);

  
    //Loose Cut: 
    if((sieie  < sieL)&&
       (toe    < 0.05)&&
       (isoP-0.0047*Ppt < isoPL)&&
       (isoC   < isoCL)&&
       (isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) < isoNL)){
      
      EffNVTXL->Fill(nvtx,weight);
      EffPTL->Fill(Ppt,weight);
      EffETAL->Fill(Peta,weight);
    }
    
    //Medium Cut:
    if((sieie  < sieM)&&
       (toe    < 0.05)&&
       (isoP -0.0047*Ppt < isoPM)&&
       (isoC   < isoCM)&&
       (isoN- (0.0148*Ppt+0.000017*Ppt*Ppt) < isoNM)){
      EffNVTXM->Fill(nvtx,weight);
      EffPTM->Fill(Ppt,weight);
      EffETAM->Fill(Peta,weight);
    }
    //Tight Cut:
    if((sieie  < sieT)&&
       (toe    < 0.05)&&
       (isoP -0.0047*Ppt < isoPT)&&
       (isoC   < isoCT)&&
       (isoN - (0.0148*Ppt+0.000017*Ppt*Ppt) < isoNT)){
      EffNVTXT->Fill(nvtx,weight);
      EffPTT->Fill(Ppt,weight);
      EffETAT->Fill(Peta,weight);
    }
    //Branch out Cuts
    if(sieie  < sieL){
       EffNVTXs->Fill(nvtx,weight);
       EffPTs->Fill(Ppt,weight);
       EffETAs->Fill(Peta,weight);
       
    }
    if(toe    < 0.05){
      EffNVTXt->Fill(nvtx,weight);
      EffPTt->Fill(Ppt,weight);
      EffETAt->Fill(Peta,weight);
     
    }    
    if(isoP -0.0047*Ppt < isoPL){    
      EffNVTXp->Fill(nvtx,weight);
      EffPTp->Fill(Ppt,weight);
      EffETAp->Fill(Peta,weight);
     
    }    
    if(isoC   < isoCL){
      EffNVTXc->Fill(nvtx,weight);
      EffPTc->Fill(Ppt,weight);
      EffETAc->Fill(Peta,weight);
     
    }
    if(isoN-(0.0148*Ppt + 0.000017*Ppt*Ppt) < isoNL){
      EffNVTXn->Fill(nvtx,weight);
      EffPTn->Fill(Ppt,weight);
      EffETAn->Fill(Peta,weight);
     
    }

    //Branch out Cuts Medium
    if(sieie  < sieM){
       EffPTMs->Fill(Ppt,weight);
    }
    if(toe    < 0.05){
      EffPTMt->Fill(Ppt,weight);
    }    
    if(isoP -0.0047*Ppt < isoPM){    
      EffPTMp->Fill(Ppt,weight);
    }    
    if(isoC   < isoCM){
      EffPTMc->Fill(Ppt,weight);
    }
    if(isoN-(0.0148*Ppt + 0.000017*Ppt*Ppt) < isoNM){
      EffPTMn->Fill(Ppt,weight);
    }

    //Branch out Cuts Tight
    if(sieie  < sieT){
       EffPTTs->Fill(Ppt,weight);
    }
    if(toe    < 0.05){
      EffPTTt->Fill(Ppt,weight);
    }    
    if(isoP -0.0047*Ppt < isoPT){    
      EffPTTp->Fill(Ppt,weight);
    }    
    if(isoC   < isoCT){
      EffPTTc->Fill(Ppt,weight);
    }
    if(isoN-(0.0148*Ppt + 0.000017*Ppt*Ppt) < isoNT){
      EffPTTn->Fill(Ppt,weight);
    }





  }  


  //plots for Background 


  for(int i = 0; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    EffNVTX0b->Fill(nvtx,weight);
    EffPT0b->Fill(Ppt,weight);
    EffETA0b->Fill(Peta,weight);
  
    //Loose Cut: 
    if((sieie  < sieL)&&
       (toe    < 0.05)&&
       (isoP -0.0047*Ppt < isoPL)&&
       (isoC   < isoCL)&&
       (isoN-((0.0148*Ppt+0.000017*Ppt*Ppt)) < isoNL)){
      
      EffNVTXLb->Fill(nvtx,weight);
      EffPTLb->Fill(Ppt,weight);
      EffETALb->Fill(Peta,weight);
    }
    
    //Medium Cut:
    if((sieie  < sieM)&&
       (toe    < 0.05)&&
       (isoP -0.0047*Ppt < isoPM)&&
       (isoC   < isoCM)&&
       (isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) < isoNM)){
      EffNVTXMb->Fill(nvtx,weight);
      EffPTMb->Fill(Ppt,weight);
      EffETAMb->Fill(Peta,weight);
    }
    //Tight Cut:
    if((sieie  < sieT)&&
       (toe    < 0.05)&&
       (isoP -0.0047*Ppt < isoPT)&&
       (isoC   < isoCT)&&
       (isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) < isoNT)){
      EffNVTXTb->Fill(nvtx,weight);
      EffPTTb->Fill(Ppt,weight);
      EffETATb->Fill(Peta,weight);
    }
    //Branch out Cuts
    if(sieie  < sieL){
       EffNVTXbs->Fill(nvtx,weight);
       EffPTbs->Fill(Ppt,weight);
       EffETAbs->Fill(Peta,weight);
    }
    if(toe    < 0.05){
      EffNVTXbt->Fill(nvtx,weight);
      EffPTbt->Fill(Ppt,weight);
      EffETAbt->Fill(Peta,weight);
    }    
    if(isoP -0.0047*Ppt < isoPL){    
      EffNVTXbp->Fill(nvtx,weight);
      EffPTbp->Fill(Ppt,weight);
      EffETAbp->Fill(Peta,weight);
     }    
    if(isoC   < isoCL){
      EffNVTXbc->Fill(nvtx,weight);
      EffPTbc->Fill(Ppt,weight);
      EffETAbc->Fill(Peta,weight);
 
    }
    if(isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) < isoNL){
      EffNVTXbn->Fill(nvtx,weight);
      EffPTbn->Fill(Ppt,weight);
      EffETAbn->Fill(Peta,weight);
      
    }
  }



  TFile *f1 = new TFile("Eff1.root","recreate");
  f1->cd();
  EffNVTX0->Write();
  EffPT0->Write();
  EffETA0->Write();
  EffPHI0->Write();
  
  EffNVTXL->Write();
  EffPTL->Write();
  EffETAL->Write();
  EffPHIL->Write();
  
  EffNVTXM->Write();
  EffPTM->Write();
  EffETAM->Write();
  EffPHIM->Write();
  
  EffNVTXT->Write();
  EffPTT->Write();
  EffETAT->Write();
  EffPHIT->Write();


  EffNVTX0b->Write();
  EffPT0b->Write();
  EffETA0b->Write();
  EffPHI0b->Write();
  
  EffNVTXLb->Write();
  EffPTLb->Write();
  EffETALb->Write();
  EffPHILb->Write();
  
  EffNVTXMb->Write();
  EffPTMb->Write();
  EffETAMb->Write();
  EffPHIMb->Write();
  
  EffNVTXTb->Write();
  EffPTTb->Write();
  EffETATb->Write();
  EffPHITb->Write(); 


  EffNVTXs->Write();
  EffPTs->Write();
  EffETAs->Write();


  EffNVTXt->Write();
  EffPTt->Write();
  EffETAt->Write();
    
  EffNVTXc->Write();
  EffPTc->Write();
  EffETAc->Write();


  EffNVTXn->Write();
  EffPTn->Write();
  EffETAn->Write();
  

  EffNVTXp->Write();
  EffPTp->Write();
  EffETAp->Write();

  
  EffNVTXbs->Write();
  EffPTbs->Write();
  EffETAbs->Write();

  
  EffNVTXbt->Write();
  EffPTbt->Write();
  EffETAbt->Write();
  
  EffNVTXbc->Write();
  EffPTbc->Write();
  EffETAbc->Write();

  EffNVTXbn->Write();
  EffPTbn->Write();
  EffETAbn->Write();

  EffNVTXbp->Write();
  EffPTbp->Write(); 
  EffETAbp->Write();


    
  EffPTMs->Write();
  EffPTMt->Write();
  EffPTMc->Write();
  EffPTMp->Write();
  EffPTMn->Write();
    
  EffPTTs->Write();
  EffPTTt->Write();
  EffPTTc->Write();
  EffPTTp->Write();
  EffPTTn->Write();
  




  TFile *feta = new TFile("Eff1etaB.root","recreate");
  feta->cd();


  EffETA0->Write();
  EffETA0b->Write();


  EffETAs->Write();
  EffETAt->Write();
  EffETAc->Write();
  EffETAn->Write();
  EffETAp->Write();


  EffETAbs->Write();
  EffETAbt->Write();
  EffETAbc->Write();
  EffETAbn->Write();
  EffETAbp->Write();

 




}

