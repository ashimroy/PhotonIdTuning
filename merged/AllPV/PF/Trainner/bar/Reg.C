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

//#include "TMVARegGui.C"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"

using namespace TMVA;


void Reg(){
  
  TMVA::Tools::Instance();
  std::cout << "==> Start TMVARegression" << std::endl;
    
  ifstream myfile; 
  myfile.open("/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/ChEA_trainner/subset_sample/bar/99per.txt");


  ostringstream xcS,xcH,xcP,xcC,xcN;  
  double xS,xC,xN,xP;

  if(myfile.is_open()){
    while(!myfile.eof()){
      myfile>>xS>>xC>>xN>>xP;
    }
  }

  xcS<<xS;
  xcC<<xC;
  xcN<<xN;
  xcP<<xP;

  //Output file 
  TString outfileName( "Loose_w_BAR_scaled.root" );
  TFile* outputFile = TFile::Open( outfileName, "RECREATE" );
  
  //Declaring the factory
  TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile, 
					      "!V:!Silent:Color:DrawProgressBar" );
  //Declaring Input Variables 
  factory->AddVariable( "Sieie",'F');
  factory->AddVariable( "isoC",'F' );
  factory->AddVariable( "(isoN-(0.0143*Ppt+0.000017*Ppt*Ppt) > 0 ) ? isoN-(0.0143*Ppt+0.000017*Ppt*Ppt) : 0.0 ",'F' );
  factory->AddVariable( "(isoP-0.0046*Ppt > 0 ) ? isoP-0.0046*Ppt : 0.0 ",'F' );

  //factory->AddVariable( "(isoN-(0.014*Ppt+0.000019*Ppt*Ppt) > 0 ) ? isoN-(0.014*Ppt+0.000019*Ppt*Ppt) : 0.0 ",'F' );
  //factory->AddVariable( "(isoP-0.0053*Ppt > 0 ) ? isoP-0.0053*Ppt : 0.0 ",'F' );
  
  factory->AddSpectator( "Ppt",'F' );
  factory->AddSpectator( "ToE",'F' );
  
  //TString fname = "../../CutTMVABarrel90.root";
  TString fname = "/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/ChEA_trainner/CutTMVABarrel90.root";
  input = TFile::Open( fname );
  
  // --- Register the regression tree
  TTree *signal = (TTree*)input->Get("t_S");
  TTree *background = (TTree*)input->Get("t_B");
  
  //Just Some more settings
   Double_t signalWeight      = 1.0; 
   Double_t backgroundWeight  = 1.0; 

   // You can add an arbitrary number of regression trees
   factory->AddSignalTree( signal, signalWeight );
   factory->AddBackgroundTree( background , backgroundWeight );
 
   TCut mycuts ="Ppt>15   && Ppt < 200 && ToE < 0.05";
   TCut mycutb ="Ppt>15   && Ppt < 200 && ToE < 0.05";
   //factory->PrepareTrainingAndTestTree(mycuts,mycutb,""); 
   //factory->PrepareTrainingAndTestTree(mycuts,mycutb,"nTrain_Signal=300000:nTrain_Background=300000:nTest_Signal=300000:nTest_Background=300000");
   factory->PrepareTrainingAndTestTree(mycuts,mycutb,"nTrain_Signal=5000000:nTrain_Background=5000000:nTest_Signal=5000000:nTest_Background=5000000");
   //factory->PrepareTrainingAndTestTree(mycuts,mycutb,"nTrain_Signal=1000:nTrain_Background=1000:nTest_Signal=1000:nTest_Background=1000");
   //nTrain_Signal=3000:nTrain_Background=6000:nTest_Signal=3000:nTest_Background=3000");

   factory->SetBackgroundWeightExpression("weighT");
   factory->SetSignalWeightExpression("weighT");

   TString methodName = "Cut_Loose_r";
   TString methodOptions ="!H:!V:FitMethod=GA:EffMethod=EffSEl"; 
   methodOptions +=":VarProp[0]=FMin:VarProp[1]=FMin:VarProp[2]=FMin:VarProp[3]=FMin";
   //   methodOptions +=":VarProp[0]=FMax:VarProp[1]=FMax:VarProp[2]=FMax:VarProp[3]=FMax";
  
   methodOptions +=":CutRangeMax[0]="+xcS.str(); 
   methodOptions +=":CutRangeMax[1]="+xcC.str();
   methodOptions +=":CutRangeMax[2]="+xcN.str();
   methodOptions +=":CutRangeMax[3]="+xcP.str();
   //   methodOptions +=":CutRangeMax[4]="+xcP.str(); //!!!!!!!!!!
   //   methodOptions +=":CutRangeMin[0]=0.0";
   //methodOptions +=":CutRangeMin[1]=-5.0";
   //methodOptions +=":CutRangeMin[2]=-5.0";
   //methodOptions +=":CutRangeMin[3]=-5.0";
   // methodOptions +=":CutRangeMin[4]=-1.0";

   //************
   factory->BookMethod(TMVA::Types::kCuts,methodName,methodOptions);
   factory->TrainAllMethods();
   factory->TestAllMethods();
   factory->EvaluateAllMethods();    
   
   // --------------------------------------------------------------
   // Save the output
   outputFile->Close();



   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVARegression is done!" << std::endl;      
   delete factory;

}
