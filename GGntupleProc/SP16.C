#define SP16_cxx
#include "SP16.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//Included by User
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <TMath.h>
#include <vector>
#include <TVector3.h>
#include <TProfile.h>
#include "TStopwatch.h"


void SP16::Loop(string outputfile, int ntotEvent, int nPrintEvent, double evtWeight)
{
  TStopwatch sw;
  sw.Start();

  //TFile *f1 = new TFile("outputfile.root","recreate");
  //TTree *t1 = new TTree("t1","EventsTree");

  cout<<"Output file : " << outputfile << endl;
  char *outfilename = const_cast<char*>(outputfile.c_str());
  TFile *f1 = new TFile(outfilename,"RECREATE");
  TTree *t1 = new TTree("t1","EventsTree");

  TH1D *MatchPhos = new TH1D("MatchPhos","# of matched photons in event",5,0,5);


  float Vtx,Vty,Vtz,MCVtx,MCVty,MCVtz,gedPhR9,gedPhEta,gedPhSCEta,gedPhPt,gedPhPhi,gedPhoIso,gedChgIso,gedNeuIso,gedPhTower,gedPhSieie,Rh,gedGenPt,gedPhweightXS,PhCITKChIso,PhCITKNeuIso,PhCITKPhoIso,PhPUPPIChIso,PhPUPPINeuIso,PhPUPPIPhoIso,gedPhIDMVA; 
  int gedPhPixSeed,NVtx,gedPhisPrompt,hascorrectPrimV,gedPhEleVeto; 
  

  //integer Branches
  t1->Branch("NVtx",&NVtx,"NVtx/I");
  t1->Branch("gedPhPixSeed",&gedPhPixSeed,"gedPhPixSeed/I");
  t1->Branch("gedPhisPrompt",&gedPhisPrompt,"gedPhisPrompt/I");
  t1->Branch("hascorrectPrimV",&hascorrectPrimV,"hascorrectPrimV/I");
  t1->Branch("gedPhEleVeto",&gedPhEleVeto,"gedPhEleVeto/I");

  //Float Branches
  t1->Branch("Vtx",&Vtx,"Vtx/F");
  t1->Branch("Vty",&Vty,"Vty/F");
  t1->Branch("Vtz",&Vtz,"Vtz/F");
  t1->Branch("MCVtx",&MCVtx,"MCVtx/F");
  t1->Branch("MCVty",&MCVty,"MCVty/F");
  t1->Branch("MCVtz",&MCVtz,"MCVtz/F");
  t1->Branch("gedPhR9",&gedPhR9,"gedPhR9/F");
  t1->Branch("Rh",&Rh,"Rh/F");
  t1->Branch("gedPhSCEta",&gedPhSCEta,"gedPhSCEta/F");
  t1->Branch("gedPhEta",&gedPhEta,"gedPhEta/F");
  t1->Branch("gedPhPhi",&gedPhPhi,"gedPhPhi/F");
  t1->Branch("gedPhPt",&gedPhPt,"gedPhPt/F");
  t1->Branch("gedPhSieie",&gedPhSieie,"gedPhSieie/F");
  t1->Branch("gedPhTower",&gedPhTower,"gedPhTower/F");
  t1->Branch("gedPhoIso",&gedPhoIso,"gedPhoIso/F");
  t1->Branch("gedChgIso",&gedChgIso,"gedChgIso/F");
  t1->Branch("gedNeuIso",&gedNeuIso,"gedNeuIso/F");
  t1->Branch("gedGenPt",&gedGenPt,"gedGenPt/F");
  t1->Branch("gedPhweightXS",&gedPhweightXS,"gedPhweightXS/F");
  t1->Branch("PhCITKChIso",&PhCITKChIso,"PhCITKChIso/F");
  t1->Branch("PhCITKNeuIso",&PhCITKNeuIso,"PhCITKNeuIso/F");
  t1->Branch("PhCITKPhoIso",&PhCITKPhoIso,"PhCITKPhoIso/F");
  t1->Branch("PhPUPPIChIso",&PhPUPPIChIso,"PhPUPPIChIso/F");
  t1->Branch("PhPUPPINeuIso",&PhPUPPINeuIso,"PhPUPPINeuIso/F");
  t1->Branch("PhPUPPIPhoIso",&PhPUPPIPhoIso,"PhPUPPIPhoIso/F");
  t1->Branch("gedPhIDMVA",&gedPhIDMVA,"gedPhIDMVA/F");

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;


   //double weightt1 = 1; //7180*0.038/(nentries*0.000103507);
   double weightt1 = evtWeight;
   cout<<"weight of  this sample "<<weightt1<<endl;  
   cout<<"total entries:"<<nentries<<endl;

   if (ntotEvent >= 0) nentries = ntotEvent; // number of events you want to process...
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (jentry % nPrintEvent == 0) std::cout << "  " << jentry  << "  Events Processed... " << std::endl;
      //if(jentry % 1000 == 0 ) cout<<jentry<<endl;
      int mPHOS = 0;
      int mto1st = 0;

      Vtx=vtx;
      Vty=vty;
      Vtz=vtz;
      
      MCVtx=(*mcVtx)[0];
      MCVty=(*mcVty)[0];
      MCVtz=(*mcVtz)[0];

      for(int ipho = 0; ipho < (*phoEt).size(); ipho++){
	double pEta = (*phoEta)[ipho]; 
	double pPhi = (*phoPhi)[ipho]; 
	Rh = rho;                            
        NVtx = nVtx;                                                            
	gedPhEleVeto = (*phoEleVeto)[ipho];                      
	gedPhR9 = (*phoR9)[ipho];
        gedPhPt = (*phoEt)[ipho];                                               
        gedPhEta = pEta;
	gedPhSCEta = (*phoSCEta)[ipho];
        gedPhPhi = pPhi;                                                        
        gedPhSieie = (*phoSigmaIEtaIEtaFull5x5)[ipho];                                 
        gedPhTower = (*phoHoverE)[ipho];                                      
        gedPhoIso = (*phoPFPhoIso)[ipho];                                       
        gedChgIso = (*phoPFChIso)[ipho];                                        
        gedNeuIso = (*phoPFNeuIso)[ipho];                                       
        gedPhPixSeed  = (*phohasPixelSeed)[ipho];                               
        gedPhweightXS = weightt1;       
	PhCITKChIso = (*phoCITKChIso)[ipho];
	PhCITKNeuIso = (*phoCITKNeuIso)[ipho];
	PhCITKPhoIso = (*phoCITKPhoIso)[ipho];
	PhPUPPIChIso = (*phoPUPPIChIso)[ipho];
	PhPUPPINeuIso = (*phoPUPPINeuIso)[ipho];
	PhPUPPIPhoIso = (*phoPUPPIPhoIso)[ipho];
	gedPhIDMVA = (*phoIDMVA)[ipho];
	int pass = 0;
	int phoispr = 0; 
	double genPt = -1;
	for(int imc = 0; imc < (*mcPID).size(); imc++){
	  if((*mcPt)[imc] < 15 ) continue;	  
	  if((*mcStatus)[imc] != 1)continue; 
	  if((*mcPID)[imc] != 22)continue;
	  if(TMath::Abs((*mcMomPID)[imc]) >  21 )continue;
	  pass++;

	  double meta = (*mcEta)[imc];
	  double mphi = (*mcPhi)[imc];	  
	  TVector3 mcphoton;
	  TVector3 recoPHOTOn;
	  mcphoton.SetPtEtaPhi(1.0,meta,mphi);
	  recoPHOTOn.SetPtEtaPhi(1.0,pEta,pPhi);			       
	  double DR = mcphoton.DrEtaPhi(recoPHOTOn);
	  double dp = fabs((*mcPt)[imc] - (*phoEt)[ipho] )/(*mcPt)[imc];
	  if(DR < 0.2 && dp < 0.2  ){
	    mPHOS++;
	    if(pass == 1 ){ 
	      genPt = (*mcPt)[imc];
	      phoispr = 1;
	    }
	  }
	}//EOF MC Particles loop 
	gedPhisPrompt = phoispr;
	gedGenPt = genPt; 
	t1->Fill();	
      }//EOF Photon Loop
      MatchPhos->Fill(mPHOS);
   }//EOF EVENT LOOP 
   MatchPhos->Write();
   t1->Write();
   f1->Close();

   cout<<outputfile<< " created ...."<<endl;

   sw.Stop();
   std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
   std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
