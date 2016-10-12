//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul 21 10:33:25 2014 by ROOT version 5.34/10
// from TTree t1/EventsTree
// found on file: ../CompatV.root
//////////////////////////////////////////////////////////

#ifndef CutID_h
#define CutID_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>



// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class CutID {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   
   Int_t           NVtx;
 

   Float_t         Rh;


   Float_t         gedPhEta;
   Float_t         gedGenPt;
   Float_t         gedPhPhi;
   Float_t         gedPhPt;
   Float_t         gedPhSieie;

   Float_t         gedPhTower;
   Int_t           gedPhisPrompt;
   Float_t         gedPhoIso;
   Float_t         gedChgIso;
   Float_t         gedNeuIso;
   Float_t         PhPUPPIPhoIso;
   Float_t         PhPUPPIChIso;
   Float_t         PhPUPPINeuIso;
   Int_t           gedPhPixSeed;
   Float_t         gedPhweightXS;
   


   // List of branches

   TBranch        *b_Rh;
   TBranch        *b_NVtx;

   TBranch        *b_gedPhEta; //!
   TBranch        *b_gedGenPt;    //!
   TBranch        *b_gedPhPhi;   //!
   TBranch        *b_gedPhPt;   //!
   TBranch        *b_gedPhSieie;

   TBranch        *b_gedPhTower;   //!
   TBranch        *b_gedPhisPrompt;   //!
   TBranch        *b_gedPhoIso;   //!
   TBranch        *b_gedChgIso;   //!
   TBranch        *b_gedNeuIso;   //!
   TBranch        *b_PhPUPPIPhoIso;   //!
   TBranch        *b_PhPUPPIChIso;   //!
   TBranch        *b_PhPUPPINeuIso;   //!
   TBranch        *b_gedPhPixSeed;   //!
   TBranch        *b_gedPhweightXS;

   CutID(TTree *tree=0);
   virtual ~CutID();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   //   virtual void     SaCH(int reg);
   virtual void     ArCalc(double e_min,double e_max,int bin);
   virtual void     CutBasedID(int reg,double EFFAr[7][3]);
};

#endif

#ifdef CutID_cxx
CutID::CutID(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("sp15_4th.root");
     TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/spring16_gjets_25ns.root");
     //TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("isopt/pt15to6000_25ns.root");
      if (!f || !f->IsOpen()) {
	//f = new TFile("sp15_4th.root");
         f = new TFile("/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/spring16_gjets_25ns.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
}

CutID::~CutID()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CutID::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CutID::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CutID::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("Rh", &Rh, &b_Rh);

   fChain->SetBranchAddress("gedPhEta", &gedPhEta, &b_gedPhEta);
  
   fChain->SetBranchAddress("gedGenPt", &gedGenPt, &b_gedGenPt);
  

   fChain->SetBranchAddress("gedPhPhi", &gedPhPhi, &b_gedPhPhi);
   fChain->SetBranchAddress("gedPhPt", &gedPhPt, &b_gedPhPt);
   fChain->SetBranchAddress("gedPhSieie", &gedPhSieie, &b_gedPhSieie);

   fChain->SetBranchAddress("gedPhTower", &gedPhTower, &b_gedPhTower);
   fChain->SetBranchAddress("gedPhisPrompt", &gedPhisPrompt, &b_gedPhisPrompt);
   fChain->SetBranchAddress("gedPhoIso", &gedPhoIso, &b_gedPhoIso);
   fChain->SetBranchAddress("gedChgIso", &gedChgIso, &b_gedChgIso);
   fChain->SetBranchAddress("gedNeuIso", &gedNeuIso, &b_gedNeuIso);
   fChain->SetBranchAddress("PhPUPPIPhoIso", &PhPUPPIPhoIso, &b_PhPUPPIPhoIso);
   fChain->SetBranchAddress("PhPUPPIChIso", &PhPUPPIChIso, &b_PhPUPPIChIso);
   fChain->SetBranchAddress("PhPUPPINeuIso", &PhPUPPINeuIso, &b_PhPUPPINeuIso);
   fChain->SetBranchAddress("gedPhPixSeed", &gedPhPixSeed, &b_gedPhPixSeed);
   fChain->SetBranchAddress("gedPhweightXS", &gedPhweightXS, &b_gedPhweightXS);
   Notify();
}

Bool_t CutID::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CutID::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CutID::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CutID_cxx
