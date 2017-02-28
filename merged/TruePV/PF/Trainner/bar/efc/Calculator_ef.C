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

void Calculator_ef(){

  ifstream tight; 
  ifstream medium; 
  ifstream loose; 
  ofstream outp; 

  tight.open("TightR.txt");
  medium.open("MediumR.txt");
  loose.open("LooseR.txt");
  outp.open("efBk.txt");

  double efL,efM,efT,bkL,bkM,bkT; 
  double IsoPcutL,IsoPcutM,IsoPcutT,IsoCcutL,IsoCcutM,IsoCcutT,IsoNcutL,IsoNcutM,IsoNcutT,SieiecutL,SieiecutM,SieiecutT,HoEcutL,HoEcutM,HoEcutT;

  if(tight.is_open()){
    while(!tight.eof()){
      
      tight>>SieiecutT>>IsoCcutT>>IsoNcutT>>IsoPcutT>>HoEcutT;
      break;
    }
  }
    
  if(medium.is_open()){
    while(!medium.eof()){
      
      medium>>SieiecutM>>IsoCcutM>>IsoNcutM>>IsoPcutM>>HoEcutM;
      break;

    }
  }


    
  if(loose.is_open()){
    while(!loose.eof()){
      
      loose>>SieiecutL>>IsoCcutL>>IsoNcutL>>IsoPcutL>>HoEcutL;
      break;

    }
  }
  //HoEcutL = 0.05;
  //HoEcutM = 0.05;
  //HoEcutT = 0.05;



  //Input file:
  TFile *fname = new TFile( "/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/AllPV/PF/Trainner/CutTMVABarrel90.root");
  //TFile *fname = new TFile( "/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/TruePV/PF/Trainner/CutTMVABarrel90.root");        
  //TFile *fname = new TFile( "/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/AllPV/PF/Isopt/CutTMVABarrel90_HPT.root"); 

  input = TFile::Open( fname );
  
  // --- Register the regression tree
  float Sie_ie,iso_P,iso_C,iso_N,to_e,weightXS,weighT;
  float Ppt; 
  int Pix;

  //Signal Tree
  t_S->SetBranchAddress("Sieie",&Sie_ie);
  t_S->SetBranchAddress("isoP",&iso_P);
  t_S->SetBranchAddress("isoC",&iso_C);
  t_S->SetBranchAddress("isoN",&iso_N);
  t_S->SetBranchAddress("ToE",&to_e);
  t_S->SetBranchAddress("weighT",&weighT);
  t_S->SetBranchAddress("Pix",&Pix);
  t_S->SetBranchAddress("Ppt",&Ppt);

  //Background Tree
  t_B->SetBranchAddress("Sieie",&Sie_ie);
  t_B->SetBranchAddress("isoP",&iso_P);
  t_B->SetBranchAddress("isoC",&iso_C);
  t_B->SetBranchAddress("isoN",&iso_N);
  t_B->SetBranchAddress("ToE",&to_e);  
 
  t_B->SetBranchAddress("weighT",&weighT);
  t_B->SetBranchAddress("Pix",&Pix);
  t_B->SetBranchAddress("Ppt",&Ppt);




  double LoosSEf = 0; 
  double TightSEf = 0; 
  double MediumSEf = 0; 

  
  double LoosBckR = 0; 
  double TightBckR = 0; 
  double MediumBckR = 0; 

  
  double totS = 0; 
  for(int i  = 0 ; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);
    if(Ppt < 15 || Ppt > 200 ) continue;

    double slopeP = 0.0047; 
    double slopeN = (0.0148*Ppt+0.000017*Ppt*Ppt); 


    totS = totS+ weighT; 


    //Calculating the Efficiencies for the Loose Set of Cuts 
    if((iso_P < IsoPcutL + slopeP*Ppt)&&(iso_N < IsoNcutL  + slopeN)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosSEf = LoosSEf + weighT;
    }
    
    if((iso_P < IsoPcutM +slopeP*Ppt)&&(iso_N < IsoNcutM + slopeN)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM ))){
       MediumSEf = MediumSEf + weighT;
    }
    
       if((iso_P < IsoPcutT +slopeP*Ppt)&&(iso_N < IsoNcutT + slopeN)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT ) ){
        TightSEf = TightSEf + weighT;
    }
    
  }

  double totB = 0; 
  for(int i  = 0 ; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    //  if(Pix == 1)continue;
    if(Ppt < 15  && Ppt > 200) continue;

    double slopeP = 0.0047; 
    double slopeN = (0.0148*Ppt+0.000017*Ppt*Ppt); 
    //double slopeP = 0.0034; 
    //double slopeN = (0.0139*Ppt+0.000025*Ppt*Ppt); 


    totB = totB+ weighT; 
   

    
    if((iso_P < IsoPcutL +Ppt*slopeP )&&(iso_N < IsoNcutL + slopeN)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosBckR = LoosBckR + weighT;
    }
    
       if((iso_P < IsoPcutM +slopeP*Ppt)&&(iso_N < IsoNcutM +slopeN)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM )){
	 MediumBckR = MediumBckR + weighT;
    }
    
       if((iso_P < IsoPcutT +  Ppt*slopeP)&&(iso_N < IsoNcutT + slopeN)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT )){
        TightBckR = TightBckR + weighT;
    }


  }// Eoff Back ground tree for Sig Back 


  


outp<<100*(LoosSEf/totS)<<" "<<100*(1 - LoosBckR/totB)<<" "<<100*(MediumSEf/totS)<<" "<<100*(1 - MediumBckR/totB)<<" "<<100*(TightSEf/totS)<<" "<<100*(1 - TightBckR/totB);



}
