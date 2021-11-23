//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 18 11:12:45 2021 by ROOT version 6.24/06
// from TTree t1/a simple Tree with simple variables
// found on file: musr_1003_gmm1e5_10GeV_1cm.root
//////////////////////////////////////////////////////////

#ifndef t1_h
#define t1_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "SimpleHistSVC.h"
#include <map>
#include <string>


using namespace std;
// Header file for the classes stored in the TTree if any.

class t1 {
public :
   SimpleHistSVC  *histSvc; //!
   TFile        *f_out; //!

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runID;
   Int_t           eventID;
   Double_t        timeToNextEvent;
   Double_t        BFieldAtDecay_Bx;
   Double_t        BFieldAtDecay_By;
   Double_t        BFieldAtDecay_Bz;
   Double_t        BFieldAtDecay_B3;
   Double_t        BFieldAtDecay_B4;
   Double_t        BFieldAtDecay_B5;
   Double_t        muIniTime;
   Double_t        muIniPosX;
   Double_t        muIniPosY;
   Double_t        muIniPosZ;
   Double_t        muIniMomX;
   Double_t        muIniMomY;
   Double_t        muIniMomZ;
   Double_t        muIniPolX;
   Double_t        muIniPolY;
   Double_t        muIniPolZ;
   Int_t           muDecayDetID;
   Double_t        muDecayPosX;
   Double_t        muDecayPosY;
   Double_t        muDecayPosZ;
   Double_t        muDecayTime;
   Double_t        muDecayPolX;
   Double_t        muDecayPolY;
   Double_t        muDecayPolZ;
   Double_t        muTargetMomX;
   Double_t        muTargetMomY;
   Double_t        muTargetMomZ;
   Double_t        posIniMomX;
   Double_t        posIniMomY;
   Double_t        posIniMomZ;
   Int_t           det_n;
   Int_t           det_ID[5];   //[det_n]
   Double_t        det_edep[5];   //[det_n]
   Double_t        det_edep_el[5];   //[det_n]
   Double_t        det_edep_pos[5];   //[det_n]
   Double_t        det_edep_gam[5];   //[det_n]
   Double_t        det_edep_mup[5];   //[det_n]
   Int_t           det_nsteps[5];   //[det_n]
   Double_t        det_length[5];   //[det_n]
   Double_t        det_time_start[5];   //[det_n]
   Double_t        det_time_end[5];   //[det_n]
   Double_t        det_x[5];   //[det_n]
   Double_t        det_y[5];   //[det_n]
   Double_t        det_z[5];   //[det_n]
   Double_t        det_kine[5];   //[det_n]
   Int_t           det_VrtxTrackID[5];   //[det_n]
   Int_t           det_VrtxParticleID[5];   //[det_n]

   // List of branches
   TBranch        *b_runID;   //!
   TBranch        *b_eventID;   //!
   TBranch        *b_timeToNextEvent;   //!
   TBranch        *b_BFieldAtDecay;   //!
   TBranch        *b_muIniTime;   //!
   TBranch        *b_muIniPosX;   //!
   TBranch        *b_muIniPosY;   //!
   TBranch        *b_muIniPosZ;   //!
   TBranch        *b_muIniMomX;   //!
   TBranch        *b_muIniMomY;   //!
   TBranch        *b_muIniMomZ;   //!
   TBranch        *b_muIniPolX;   //!
   TBranch        *b_muIniPolY;   //!
   TBranch        *b_muIniPolZ;   //!
   TBranch        *b_muDecayDetID;   //!
   TBranch        *b_muDecayPosX;   //!
   TBranch        *b_muDecayPosY;   //!
   TBranch        *b_muDecayPosZ;   //!
   TBranch        *b_muDecayTime;   //!
   TBranch        *b_muDecayPolX;   //!
   TBranch        *b_muDecayPolY;   //!
   TBranch        *b_muDecayPolZ;   //!
   TBranch        *b_muTargetMomX;   //!
   TBranch        *b_muTargetMomY;   //!
   TBranch        *b_muTargetMomZ;   //!
   TBranch        *b_posIniMomX;   //!
   TBranch        *b_posIniMomY;   //!
   TBranch        *b_posIniMomZ;   //!
   TBranch        *b_det_n;   //!
   TBranch        *b_det_ID;   //!
   TBranch        *b_det_edep;   //!
   TBranch        *b_det_edep_el;   //!
   TBranch        *b_det_edep_pos;   //!
   TBranch        *b_det_edep_gam;   //!
   TBranch        *b_det_edep_mup;   //!
   TBranch        *b_det_nsteps;   //!
   TBranch        *b_det_length;   //!
   TBranch        *b_det_time_start;   //!
   TBranch        *b_det_time_end;   //!
   TBranch        *b_det_x;   //!
   TBranch        *b_det_y;   //!
   TBranch        *b_det_z;   //!
   TBranch        *b_det_kine;   //!
   TBranch        *b_det_VrtxTrackID;   //!
   TBranch        *b_det_VrtxParticleID;   //!

   t1(TTree *tree,TFile *output_file);
   virtual ~t1();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool GmmStudy(); //CC
   bool IrradiationStudy(); //CC
   map<int,string> PID_to_Name; //CC
   


};

#endif

#ifdef t1_cxx
t1::t1(TTree *tree,TFile *output_file) : fChain(0),f_out(output_file)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("musr_1003_gmm1e5_10GeV_1cm.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("musr_1003_gmm1e5_10GeV_1cm.root");
      }
      f->GetObject("t1",tree);

   }
   Init(tree);
   histSvc = new SimpleHistSVC();
   histSvc->BookFile(f_out);
   //sed -e 's/\[.*\]//g; s/^/PID_to_Name\[/g;s/ /\] = \"/g; s/$/\"\;/g' PID.txt  |sort -u 
   PID_to_Name[1000010020] = "deuteron";
   PID_to_Name[1000010030] = "triton";
   PID_to_Name[1000020030] = "He3";
   PID_to_Name[1000020040] = "alpha";
   PID_to_Name[1000030040] = "Li4";
   PID_to_Name[1000030060] = "Li6";
   PID_to_Name[1000030070] = "Li7";
   PID_to_Name[1000040070] = "Be7";
   PID_to_Name[1000040080] = "Be8";
   PID_to_Name[1000040090] = "Be9";
   PID_to_Name[1000040100] = "Be10";
   PID_to_Name[1000050090] = "B9";
   PID_to_Name[1000050100] = "B10";
   PID_to_Name[1000050109] = "B10";
   PID_to_Name[1000050110] = "B11";
   PID_to_Name[1000060110] = "C11";
   PID_to_Name[1000060120] = "C12";
   PID_to_Name[1000060130] = "C13";
   PID_to_Name[1000070130] = "N13";
   PID_to_Name[1000090180] = "F18";
   PID_to_Name[1000100200] = "Ne20";
   PID_to_Name[1000100210] = "Ne21";
   PID_to_Name[1000100220] = "Ne22";
   PID_to_Name[1000110229] = "Na22";
   PID_to_Name[1000110230] = "Na23";
   PID_to_Name[1000120240] = "Mg24";
   PID_to_Name[1000120250] = "Mg25";
   PID_to_Name[1000120259] = "Mg25";
   PID_to_Name[1000120260] = "Mg26";
   PID_to_Name[1000130260] = "Al26";
   PID_to_Name[1000130269] = "Al26";
   PID_to_Name[1000130270] = "Al27";
   PID_to_Name[2112] = "neutron";
   PID_to_Name[-211] = "pi-";
   PID_to_Name[211] = "pi+";
   PID_to_Name[2212] = "proton";
   PID_to_Name[13] = "mu_m";
   PID_to_Name[-13] = "mu_p";
   PID_to_Name[11] = "e_m";
   PID_to_Name[-11] = "e_p";
   PID_to_Name[22] = "gamma";

}

t1::~t1()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   delete histSvc;

}

Int_t t1::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t t1::LoadTree(Long64_t entry)
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

void t1::Init(TTree *tree)
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

   fChain->SetBranchAddress("runID", &runID, &b_runID);
   fChain->SetBranchAddress("eventID", &eventID, &b_eventID);
   fChain->SetBranchAddress("timeToNextEvent", &timeToNextEvent, &b_timeToNextEvent);
   fChain->SetBranchAddress("BFieldAtDecay", &BFieldAtDecay_Bx, &b_BFieldAtDecay);
   fChain->SetBranchAddress("muIniTime", &muIniTime, &b_muIniTime);
   fChain->SetBranchAddress("muIniPosX", &muIniPosX, &b_muIniPosX);
   fChain->SetBranchAddress("muIniPosY", &muIniPosY, &b_muIniPosY);
   fChain->SetBranchAddress("muIniPosZ", &muIniPosZ, &b_muIniPosZ);
   fChain->SetBranchAddress("muIniMomX", &muIniMomX, &b_muIniMomX);
   fChain->SetBranchAddress("muIniMomY", &muIniMomY, &b_muIniMomY);
   fChain->SetBranchAddress("muIniMomZ", &muIniMomZ, &b_muIniMomZ);
   fChain->SetBranchAddress("muIniPolX", &muIniPolX, &b_muIniPolX);
   fChain->SetBranchAddress("muIniPolY", &muIniPolY, &b_muIniPolY);
   fChain->SetBranchAddress("muIniPolZ", &muIniPolZ, &b_muIniPolZ);
   fChain->SetBranchAddress("muDecayDetID", &muDecayDetID, &b_muDecayDetID);
   fChain->SetBranchAddress("muDecayPosX", &muDecayPosX, &b_muDecayPosX);
   fChain->SetBranchAddress("muDecayPosY", &muDecayPosY, &b_muDecayPosY);
   fChain->SetBranchAddress("muDecayPosZ", &muDecayPosZ, &b_muDecayPosZ);
   fChain->SetBranchAddress("muDecayTime", &muDecayTime, &b_muDecayTime);
   fChain->SetBranchAddress("muDecayPolX", &muDecayPolX, &b_muDecayPolX);
   fChain->SetBranchAddress("muDecayPolY", &muDecayPolY, &b_muDecayPolY);
   fChain->SetBranchAddress("muDecayPolZ", &muDecayPolZ, &b_muDecayPolZ);
   fChain->SetBranchAddress("muTargetMomX", &muTargetMomX, &b_muTargetMomX);
   fChain->SetBranchAddress("muTargetMomY", &muTargetMomY, &b_muTargetMomY);
   fChain->SetBranchAddress("muTargetMomZ", &muTargetMomZ, &b_muTargetMomZ);
   fChain->SetBranchAddress("posIniMomX", &posIniMomX, &b_posIniMomX);
   fChain->SetBranchAddress("posIniMomY", &posIniMomY, &b_posIniMomY);
   fChain->SetBranchAddress("posIniMomZ", &posIniMomZ, &b_posIniMomZ);
   fChain->SetBranchAddress("det_n", &det_n, &b_det_n);
   fChain->SetBranchAddress("det_ID", det_ID, &b_det_ID);
   fChain->SetBranchAddress("det_edep", det_edep, &b_det_edep);
   fChain->SetBranchAddress("det_edep_el", det_edep_el, &b_det_edep_el);
   fChain->SetBranchAddress("det_edep_pos", det_edep_pos, &b_det_edep_pos);
   fChain->SetBranchAddress("det_edep_gam", det_edep_gam, &b_det_edep_gam);
   fChain->SetBranchAddress("det_edep_mup", det_edep_mup, &b_det_edep_mup);
   fChain->SetBranchAddress("det_nsteps", det_nsteps, &b_det_nsteps);
   fChain->SetBranchAddress("det_length", det_length, &b_det_length);
   fChain->SetBranchAddress("det_time_start", det_time_start, &b_det_time_start);
   fChain->SetBranchAddress("det_time_end", det_time_end, &b_det_time_end);
   fChain->SetBranchAddress("det_x", det_x, &b_det_x);
   fChain->SetBranchAddress("det_y", det_y, &b_det_y);
   fChain->SetBranchAddress("det_z", det_z, &b_det_z);
   fChain->SetBranchAddress("det_kine", det_kine, &b_det_kine);
   fChain->SetBranchAddress("det_VrtxTrackID", det_VrtxTrackID, &b_det_VrtxTrackID);
   fChain->SetBranchAddress("det_VrtxParticleID", det_VrtxParticleID, &b_det_VrtxParticleID);
   Notify();
}

Bool_t t1::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void t1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t t1::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef t1_cxx
