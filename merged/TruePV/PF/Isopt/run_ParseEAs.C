#include <stdlib>
#include <TSystem.h>


void run_ParseEAs(){
  //-----------------Macro Describtion----------------------------------------------------------
  //
  // This macro wraps the whole procedure in a single shell. 
  // Initialy it caluclates the effective areas -macros (AreaCalc.C + Fitter.C) 
  // and then feed them in a Tree Maker, that makes a Tree with the variables of interest 
  // separated to background/signal and weight based on the pt, for possible MVA techinques 
  // and to derive the cuts. 
  // This file to run, needs the full construction of the CUTID class and also the extra macros
  // for each of the specified process. 
  //
  //--------------------------------------------------------------------------------------------

  gSystem->CompileMacro("CutID.C");
  
  CutID t; 
  
  // here you declare the number of eta  bins 
  double Fin[7][3]= {0};


  ifstream myfile; 
  myfile.open("EA.txt");


  cout<<"------------------------------------------------------------"<<endl;
  cout<<"                   Reading the EAS "<<endl;
  cout<<"-----------------------------------------------------------"<<endl;

  
  int i = 0; 
  if(myfile.is_open()){
    while(!myfile.eof()){
      double iC,iN,iP;      
      myfile>>iC>>iN>>iP;
      Fin[i][0] = iC; 
      Fin[i][1] = iN; 
      Fin[i][2] = iP; 




      cout<<i<<" "<<iC<<" "<<iN<<" "<<iP<<endl;
      i++;
      if( i > 6) goto conti; 

    }
  }

 conti:
  
  cout<<"----------------------Barrel--------------"<<endl;
  t.CutBasedID(1,Fin);
  cout<<"----------------------End Cap--------------"<<endl;
  t.CutBasedID(2,Fin);

  



}
