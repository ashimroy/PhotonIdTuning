#include "cstdlib"
#include "TSystem.h"
#include "TableWriter.C"
//#include "ErrScanning.C"
#include "ContourBuilder.C"
/*
#include <cstdlib>
#include <TSystem.h>
#include <TableWriter.C>
#include <ErrScanning.C>
#include <ContourBuilder.C>
*/

void runCont(){
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
  double Fin[7][3]= {0};
  double FinEr[7][3]= {0};
  double in,ein,ip,eip,ic,eic;

  cout<<"------------------------------------------------------------"<<endl;
  cout<<"Creating the bins and retrieving the effective area for each"<<endl;
  cout<<"-----------------------------------------------------------"<<endl;



  double emin = 0.0; 
  double emax = 1.0;
  ContourBuilder(1,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[0][0] = ic;
  Fin[0][1] = in;
  Fin[0][2] = ip;

  FinEr[0][0] = eic;
  FinEr[0][1] = ein;
  FinEr[0][2] = eip;

  emin =1; 
  emax =1.479;
  ContourBuilder(2,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[1][0] = ic;
  Fin[1][1] = in;
  Fin[1][2] = ip;
  FinEr[1][0] = eic;
  FinEr[1][1] = ein;
  FinEr[1][2] = eip;
  

 
  emin = 1.479;
  emax = 2.0;
  ContourBuilder(3,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[2][0] = ic;
  Fin[2][1] = in;
  Fin[2][2] = ip;
  FinEr[2][0] = eic;
  FinEr[2][1] = ein;
  FinEr[2][2] = eip;


  emin = 2.0;
  emax = 2.2;
  ContourBuilder(4,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[3][0] = ic;
  Fin[3][1] = in;
  Fin[3][2] = ip;
  FinEr[3][0] = eic;
  FinEr[3][1] = ein;
  FinEr[3][2] = eip;



  emin = 2.2;
  emax = 2.3;
  ContourBuilder(5,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[4][0] = ic;
  Fin[4][1] = in;
  Fin[4][2] = ip;
  FinEr[4][0] = eic;
  FinEr[4][1] = ein;
  FinEr[4][2] = eip;
  


  emin = 2.3;
  emax = 2.4;
  ContourBuilder(6,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[5][0] = ic;
  Fin[5][1] = in;
  Fin[5][2] = ip;
  FinEr[5][0] = eic;
  FinEr[5][1] = ein;
  FinEr[5][2] = eip;


  emin = 2.4;
  emax = 2.5;
  ContourBuilder(7,emin,emax,in,ein,ip,eip,ic,eic);
  Fin[6][0] = ic;
  Fin[6][1] = in;
  Fin[6][2] = ip;
  FinEr[6][0] = eic;
  FinEr[6][1] = ein;
  FinEr[6][2] = eip;


  for(int j  = 0; j < 4; j++)cout<<endl;
  cout<<"Derived the Effective areas --- "<<endl;
  for(int j  = 0; j < 4; j++)cout<<endl;

  TableWriter(Fin,FinEr);


  cout<<"WRITTING THE EFFECTIVE AREAS"<<endl;
  for(int j  = 0; j < 4; j++)cout<<endl;

  cout<<"----------------------------------------------------"<<endl;
  cout<<"Creating the Trees for the Cut Optimization"<<endl;
  for(int j  = 0; j < 4; j++)cout<<endl;

  
  cout<<"----------------------------------------------------"<<endl;



}
