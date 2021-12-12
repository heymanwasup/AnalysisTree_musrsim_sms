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
#include <iostream>

#define det_n_max 100


using namespace std;
// Header file for the classes stored in the TTree if any.

class t1 {
public:
   
    //Analysis functions
    bool GmmStudy();    
    bool RealGeometryIrradiation();
    bool RealGeometryGmm();
    bool RealGeometry_1p2GeV();   
 
    string GetParticleName(int PID);
    string GetProcessName(int ProcID);
    string GetDetectorName(int DetectorID);
    void FillHists(int nHit,float process_weight);
    void FillTimeInfo(string name,float hitTime,float weight);
 
    bool (t1::*func_anlysis_method)();
   
protected:
    map<int,string> PID_to_Name; //CC
    map<int,string> ProcessIDMapping; //CC

public :
    SimpleHistSVC  *histSvc; //!
    TFile          *f_out; //!


    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

    // Declaration of leaf types
    Int_t           runID;
    Int_t           eventID;
    Double_t        timeToNextEvent;

    Int_t           det_n;
    Int_t           det_ID[det_n_max];   //[det_n]
    Double_t        det_edep[det_n_max];   //[det_n]
    Double_t        det_edep_el[det_n_max];   //[det_n]
    Double_t        det_edep_pos[det_n_max];   //[det_n]
    Double_t        det_edep_gam[det_n_max];   //[det_n]
    Double_t        det_edep_mup[det_n_max];   //[det_n]
    Int_t           det_nsteps[det_n_max];   //[det_n]
    Double_t        det_length[det_n_max];   //[det_n]
    Double_t        det_time_start[det_n_max];   //[det_n]
    Double_t        det_time_end[det_n_max];   //[det_n]
    Double_t        det_x[det_n_max];   //[det_n]
    Double_t        det_y[det_n_max];   //[det_n]
    Double_t        det_z[det_n_max];   //[det_n]
    Double_t        det_kine[det_n_max];   //[det_n]
    Int_t           det_VrtxTrackID[det_n_max];   //[det_n]
    Int_t           det_VrtxParticleID[det_n_max];   //[det_n]

    Int_t           det_VrtxProcID[det_n_max];   //[det_n]

    Double_t        det_VvvKine[det_n_max];   //[det_n]
    Int_t           det_VvvProcID[det_n_max];   //[det_n]
    Int_t           det_VvvTrackID[det_n_max];   //[det_n]
    Int_t           det_VvvParticleID[det_n_max];   //[det_n]

    // List of branches
    TBranch        *b_runID;   //!
    TBranch        *b_eventID;   //!
    TBranch        *b_timeToNextEvent;   //!
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



    TBranch        *b_det_VrtxKine;   //!
    TBranch        *b_det_VrtxProcID;   //!
    TBranch        *b_det_VrtxTrackID;   //!
    TBranch        *b_det_VrtxParticleID;   //!
    TBranch        *b_det_VvvKine;   //!
    TBranch        *b_det_VvvProcID;   //!
    TBranch        *b_det_VvvTrackID;   //!
    TBranch        *b_det_VvvParticleID;   //!



    t1(TTree *tree,TFile *output_file);
    virtual ~t1();
    virtual Int_t    Cut(Long64_t entry);
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     Loop();
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);





};

#endif

#ifdef t1_cxx
t1::t1(TTree *tree,TFile *output_file) : fChain(0), f_out(output_file)
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
 
    ProcessIDMapping[1] = "DecayWithSpin";
    ProcessIDMapping[2] = "eIoni";
    ProcessIDMapping[3] = "eBrem";
    ProcessIDMapping[4] = "annihil";
    ProcessIDMapping[5] = "LowEnCompton";
    ProcessIDMapping[6] = "LowEnConversion";
    ProcessIDMapping[7] = "LowEnBrem";
    ProcessIDMapping[8] = "LowEnergyIoni";
    ProcessIDMapping[9] = "LowEnPhotoElec";
    ProcessIDMapping[10] = "RadioactiveDecay";
    ProcessIDMapping[11] = "muIoni";
    ProcessIDMapping[12] = "MuFormation";
    ProcessIDMapping[13] = "Decay";
    ProcessIDMapping[14] = "conv";
    ProcessIDMapping[15] = "compt";
    ProcessIDMapping[16] = "phot";
    
    ProcessIDMapping[17] = "dInelastic";
    ProcessIDMapping[18] = "electronNuclear";
    ProcessIDMapping[19] = "GammaToMuPair";
    ProcessIDMapping[20] = "hBertiniCaptureAtRest";
    ProcessIDMapping[21] = "hIoni";
    ProcessIDMapping[22] = "lambdaInelastic";
    ProcessIDMapping[23] = "muMinusCaptureAtRest";
    ProcessIDMapping[24] = "muonNuclear";
    ProcessIDMapping[25] = "nCapture";
    ProcessIDMapping[26] = "neutronInelastic";
    ProcessIDMapping[27] = "photonNuclear";
    ProcessIDMapping[28] = "pi-Inelastic";
    ProcessIDMapping[29] = "pi+Inelastic";
    ProcessIDMapping[30] = "protonInelastic";
    ProcessIDMapping[31] = "tInelastic";
    ProcessIDMapping[32] = "hadElastic";
 
    ProcessIDMapping[100] = "initialParticle";
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

    fChain->SetBranchAddress("det_kine", det_kine, &b_det_kine);
    fChain->SetBranchAddress("det_VrtxProcID", det_VrtxProcID, &b_det_VrtxProcID);
    fChain->SetBranchAddress("det_VvvKine", det_VvvKine, &b_det_VvvKine);
    fChain->SetBranchAddress("det_VvvProcID", det_VvvProcID, &b_det_VvvProcID);
    fChain->SetBranchAddress("det_VvvTrackID", det_VvvTrackID, &b_det_VvvTrackID);
    fChain->SetBranchAddress("det_VvvParticleID", det_VvvParticleID, &b_det_VvvParticleID);
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
