#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "TH2.h"
#include "TRandom.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"
#include "TFile.h"
#include "TTree.h"
#include "TH2D.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

using namespace TMVA;

void ReaderL(){
  // LIST OF THINGS TO CHNAGE IN TIME IN THIS FILE
  // 0 THE SLOPES OF PT SCALING !
  // 1 THE NAME OF THE FILE THAT IS GENERATED - MEDIUM LOOSE TIGHT ETC
  // 2 THE REQUIRED efficiency 80 90 etc
  // 3 The input weight file name
  // 4 the output file at the end of this document 



  
  TMVA::Tools::Instance();  
  
  ofstream myfileL; 
  myfileL.open("LooseR.txt");
  

  //Declaring the reader  
  TString methodName = "Cuts_Loose_r";
  TString weightfile = "./weights/TMVAClassification_Cut_Loose_r.weights.xml";    

  TMVA::Reader *reader = new TMVA::Reader( "!Color" );
  float Sieie,ToE,isoC,isoN,isoP,pt;
  reader->AddVariable("Sieie",&Sieie);
  reader->AddVariable( "isoC",&isoC );
  reader->AddVariable( "(isoN-(0.0163*Ppt+0.000014*Ppt*Ppt) > 0 ) ? isoN-(0.0163*Ppt+0.000014*Ppt*Ppt) : 0.0 ",&isoN );
  reader->AddVariable( "(isoP-0.0034*Ppt > 3.5 ) ? isoP-0.0034*Ppt : 3.5 ",&isoP );  
  reader->AddVariable( "(ToE > 0.02) ? ToE : 0.02",&ToE);
 
  reader->AddSpectator("Ppt",&pt);
  //reader->AddSpectator("ToE",&ToE);

  reader->BookMVA(methodName,weightfile); 


  TMVA::MethodCuts* mcuts = dynamic_cast<TMVA::MethodCuts*>(reader->FindCutsMVA(methodName) );
  std::vector<Double_t> cutsMin;
  std::vector<Double_t> cutsMax;
  
  
  double SEF =  0.90;   
  if(mcuts)mcuts->GetCuts(SEF, cutsMin, cutsMax ); 
  //myfileL<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<" "<<endl;  
  myfileL<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<" "<<cutsMax[4]<<" "<<endl;  
  

  delete reader;
  myfileL.close();
  cout<<"DONE READING CUTS"<<endl;
  
}

