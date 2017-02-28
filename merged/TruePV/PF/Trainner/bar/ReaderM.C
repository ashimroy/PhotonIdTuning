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

void ReaderM(){
  
  TMVA::Tools::Instance();  
  
  //ofstream myfileT; 
  //myfileT.open("TightR.txt");
  
  ofstream myfileM; 
  myfileM.open("MediumR.txt");
  
  //ofstream myfileL; 
  //myfileL.open("LooseR.txt");
  


  //Declaring the reader  
  //TString methodName = "Cut_Tight_r";
  //TString weightfile = "./weights/TMVAClassification_Cut_Tight_r.weights.xml";

  TString methodName = "Cut_Medium_r";
  TString weightfile = "./weights/TMVAClassification_Cut_Medium_r.weights.xml";

  //TString methodName = "Cut_Loose_r";
  //TString weightfile = "./weights/TMVAClassification_Cut_Loose_r.weights.xml";

  
  //// WARNING !!!!!!!!!!!!!!!!!! THE TIGHT SIGNAL EFF MUST BE CHANGED TO 70 %   

  
  TMVA::Reader *reader = new TMVA::Reader( "!Color" );
   
  float Sieie,ToE,isoC,isoN,isoP,pt;
  reader->AddVariable("Sieie",&Sieie);
  //reader->AddVariable("ToE",&ToE);
  reader->AddVariable( "isoC",&isoC );
  reader->AddVariable( "(isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) > 0 ) ? isoN-(0.0148*Ppt+0.000017*Ppt*Ppt) : 0.0 ",&isoN);
  reader->AddVariable( "(isoP-0.0047*Ppt > 2.5 ) ? isoP-0.0047*Ppt : 2.5 ",&isoP);
  reader->AddVariable("(ToE > 0.02) ? ToE : 0.02",&ToE);


  //reader->AddVariable( "(isoN-(0.014*Ppt+0.000019*Ppt*Ppt) > 0 )? isoN-(0.014*Ppt+0.000019*Ppt*Ppt): 0.0 ",&isoN);
  //reader->AddVariable( "(isoP-0.0053*Ppt > 0 ) ? isoP-0.0053*Ppt : 0.0 ",&isoP);

  

  reader->AddSpectator("Ppt",&pt);
  //reader->AddSpectator("ToE",&ToE);
  reader->BookMVA(methodName,weightfile); 


  TMVA::MethodCuts* mcuts = dynamic_cast<TMVA::MethodCuts*>(reader->FindCutsMVA(methodName) );
  std::vector<Double_t> cutsMin;
  std::vector<Double_t> cutsMax;
 
  /*
  double SEF =  0.90;   
  if(mcuts)mcuts->GetCuts(SEF, cutsMin, cutsMax ); 
  myfileL<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<" "<<endl;  
  */
 
  
  double SEF =  0.80;   
  if(mcuts)mcuts->GetCuts(SEF, cutsMin, cutsMax ); 
  //myfileM<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<endl;  
  myfileM<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<" "<<cutsMax[4]<<endl;  
  


  /*
  double SEF =  0.70;   
  if(mcuts)mcuts->GetCuts(SEF, cutsMin, cutsMax ); 
  myfileT<<" "<<cutsMax[0]<<" "<<cutsMax[1]<<" "<<cutsMax[2]<<" "<<cutsMax[3]<<" "<<endl;  
  */

  delete reader;



  //myfileL.close(); 
  myfileM.close(); 
  //myfileT.close(); 
  cout<<"DONE READING CUTS"<<endl;
  
}

