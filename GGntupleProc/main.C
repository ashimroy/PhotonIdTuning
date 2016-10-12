#include "SP16.C"
#include "TROOT.h"
#include <algorithm>


int main(int argc, const char *argv[]){
  //int main(){
  gROOT->ProcessLine("#include <vector>");
  //gROOT->ProcessLine("#include <map>");
  /*

  MyAnalyzer m(argv[1]);
  
  string outfile = argv[3];
  long int nTotEvt = atof(argv[4]);
  long int nPrintEvt = atof(argv[5]);

  MyAnalyzer m(argv[1],argv[2]);
  */
  //m.Loop(outfile,nTotEvt,nPrintEvt);

  string outfile = argv[2];
  long int nTotEvt = atof(argv[3]);
  long int nPrintEvt = atof(argv[4]);
  double evtWt = atof(argv[5]);
  SP16 m(argv[1]);
  m.Loop(outfile,nTotEvt,nPrintEvt,evtWt);
  //m.Loop();
}
