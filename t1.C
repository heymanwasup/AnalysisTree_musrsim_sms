#define t1_cxx
#include "t1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"
#include <iostream>

using namespace std;


#define LEN(A) sizeof(A)/sizeof(A[0])

bool t1::RealGeometryIrradiation()
{
   string particles[] = {"e_m", "e_p", "mu_m", "m_p", "gamma", "pi+", "pi-", "proton", "neutron", "deuteron", "others"};
   string processes[] = {"electronNuclear", "photonNuclear", "compt", "conv", "eBrem", "eIoni", "annihil", "GammaToMuPair", "initialParticle", "Decay", "neutronInelastic", "protonInelastic", "hadElastic","nCapture", "others"};
   for(int nHit=0;nHit<det_n;nHit++) {
      histSvc->InitNameSvc();
      float process_weight = 1.0;

      string detectorName = GetDetectorName(det_ID[nHit]);
      string particleName = GetParticleName(det_VrtxParticleID[nHit]);
      string parentParticleName = GetParticleName(det_VvvParticleID[nHit]);
      string processName = GetProcessName(det_VrtxProcID[nHit]);
      string parentProcessName = GetProcessName(det_VvvProcID[nHit]);

      if(detectorName=="") continue;

      //Fill cutflow/categories info
      if(detectorName=="Detector") {
         histSvc->BookFillCutHist("Detector_Particle_vs_ParentParticle", LEN(particles), particles, LEN(particles), particles,
                                  particleName, parentParticleName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_Process", LEN(particles), particles, LEN(processes), processes,
                                  particleName, processName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  particleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_ParentParticle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  parentParticleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_Process_vs_ParentProcess", LEN(processes), processes, LEN(processes), processes,
                                  processName, parentProcessName, process_weight);
      }

      //(detector)_(variable)
      histSvc->SetDetectorTag(detectorName);
      FillHists(nHit, process_weight);

      //(detector)_(particle)_(variable)
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_From_(parent)_(variable)
      histSvc->SetParticleTag(particleName+"_From_"+parentParticleName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(particle)_From_(parent)_(variable)
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_From_(parent)_(variable)
      histSvc->SetProcessTag(processName+"_From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_(variable)
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);


      //(detector)_From_(parent process)_(particle)_(variable)
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(variable)
      histSvc->SetParticleTag("");
      FillHists(nHit, process_weight);

      //(detector)_(process)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);
   }
   return true;
}

bool t1::RealGeometry_1p2GeV()
{
   string particles[] = {"e_m", "e_p", "mu_m", "m_p", "gamma", "pi+", "pi-", "proton", "neutron", "deuteron", "others"};
   string processes[] = {"electronNuclear", "photonNuclear", "compt", "conv", "eBrem", "eIoni", "annihil", "GammaToMuPair", "initialParticle", "Decay", "neutronInelastic", "protonInelastic", "hadElastic","nCapture", "others"};

   for(int nHit=0;nHit<det_n;nHit++) {
      histSvc->InitNameSvc();
      float process_weight = 1.0;

      string detectorName = GetDetectorName(det_ID[nHit]);
      string particleName = GetParticleName(det_VrtxParticleID[nHit]);
      string parentParticleName = GetParticleName(det_VvvParticleID[nHit]);
      string processName = GetProcessName(det_VrtxProcID[nHit]);
      string parentProcessName = GetProcessName(det_VvvProcID[nHit]);

      if(detectorName=="") continue;

      //Fill cutflow/categories info
      if(detectorName=="Detector") {
         histSvc->BookFillCutHist("Detector_Particle_vs_ParentParticle", LEN(particles), particles, LEN(particles), particles,
                                  particleName, parentParticleName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_Process", LEN(particles), particles, LEN(processes), processes,
                                  particleName, processName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  particleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_ParentParticle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  parentParticleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_Process_vs_ParentProcess", LEN(processes), processes, LEN(processes), processes,
                                  processName, parentProcessName, process_weight);
      }

      //(detector)_(variable)
      histSvc->SetDetectorTag(detectorName);
      FillHists(nHit, process_weight);

      //(detector)_(particle)_(variable)
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_From_(parent)_(variable)
      histSvc->SetParticleTag(particleName+"_From_"+parentParticleName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProcessTag(processName+"_From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_(variable)      
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);


      //(detector)_From_(parent process)_(particle)_(variable)
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(variable)
      histSvc->SetParticleTag("");
      FillHists(nHit, process_weight);

      //(detector)_(process)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);
   }
   return true;
}

bool t1::RealGeometryGmm()
{
   string particles[] = {"e_m", "e_p", "mu_m", "m_p", "gamma", "pi+", "pi-", "proton", "neutron", "deuteron", "others"};
   string processes[] = {"electronNuclear", "photonNuclear", "compt", "conv", "eBrem", "eIoni", "annihil", "GammaToMuPair", "initialParticle", "Decay", "neutronInelastic", "protonInelastic", "hadElastic","nCapture", "others"};

   for(int nHit=0;nHit<det_n;nHit++) {
      histSvc->InitNameSvc();
      float process_weight = 1.0;
      if(det_VrtxProcID[nHit]==19 || det_VvvProcID[nHit]==19) { // Gamma mumu process xsection nomalize
         process_weight = 1e-3;
      }
      string detectorName = GetDetectorName(det_ID[nHit]);
      string particleName = GetParticleName(det_VrtxParticleID[nHit]);
      string parentParticleName = GetParticleName(det_VvvParticleID[nHit]);
      string processName = GetProcessName(det_VrtxProcID[nHit]);
      string parentProcessName = GetProcessName(det_VvvProcID[nHit]);

      if(detectorName=="") continue;

      //Fill cutflow/categories info
      if(detectorName=="Detector") {
         histSvc->BookFillCutHist("Detector_Particle_vs_ParentParticle", LEN(particles), particles, LEN(particles), particles,
                                  particleName, parentParticleName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_Process", LEN(particles), particles, LEN(processes), processes,
                                  particleName, processName, process_weight);

         histSvc->BookFillCutHist("Detector_Particle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  particleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_ParentParticle_vs_ParentProcess", LEN(particles), particles, LEN(processes), processes,
                                  parentParticleName, parentProcessName, process_weight);

         histSvc->BookFillCutHist("Detector_Process_vs_ParentProcess", LEN(processes), processes, LEN(processes), processes,
                                  processName, parentProcessName, process_weight);
      }

      //(detector)_(variable)
      histSvc->SetDetectorTag(detectorName);
      FillHists(nHit, process_weight);

      //(detector)_(particle)_(variable)
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_(particle)_From_(parent)_(variable)
      histSvc->SetParticleTag(particleName+"_From_"+parentParticleName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProcessTag(processName+"_From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_(variable)      
      histSvc->SetParticleTag(particleName);
      FillHists(nHit, process_weight);


      //(detector)_From_(parent process)_(particle)_(variable)
      histSvc->SetProcessTag("From_"+parentProcessName);
      FillHists(nHit, process_weight);

      //(detector)_From_(parent process)_(variable)
      histSvc->SetParticleTag("");
      FillHists(nHit, process_weight);

      //(detector)_(process)_(variable)
      histSvc->SetProcessTag(processName);
      FillHists(nHit, process_weight);
   }
   return true;
}

//Make histograms about gmm study
bool t1::GmmStudy() {

   for(int nHit=0;nHit<det_n;nHit++) {
      //only interest at font cap detector
      if(det_ID[nHit]!=22) {
         continue;
      }

      if(PID_to_Name.find(det_VrtxParticleID[nHit])!=PID_to_Name.end()) {
         histSvc->SetParticleTag(PID_to_Name[det_VrtxParticleID[nHit]]);
      }
      else {
         histSvc->SetParticleTag("UnknownPID");
      }
      float angle_degree = TMath::ATan(det_y[nHit]/200.)*180/3.141592653;

      histSvc->BookFillHist("energy", 1000, 0, 10000, det_kine[nHit]);
      histSvc->BookFillHist("angle", 1000, -90, 90, angle_degree);
      histSvc->BookFillHist("energy_angle",100,0,10000, 250, -90, 90, det_kine[nHit], angle_degree);
   }
   return true;
}


string t1::GetParticleName(int PID)
{
   string particleName;
   if(PID_to_Name.find(PID)!=PID_to_Name.end()) {
      particleName = PID_to_Name[PID];
   }
   else {
      particleName = "UnknownPID";
      cout << "UnknownParticle "<< PID << endl;
   }
   return particleName;
}

string t1::GetProcessName(int ProcID)
{
   string processName;
   if(ProcessIDMapping.find(ProcID)!=ProcessIDMapping.end()) {
      processName = ProcessIDMapping[ProcID];
   }
   else {
      cout << "UnknownProcess "<< ProcID << endl;
      processName = "UnknownProcess";
   }
   return processName;
}

//Be careful of detector definitions in Geant4 mac file
string t1::GetDetectorName(int DetectorID)
{
   string detectorName;
   //DRZ1 monitering the injected electrons
   if(DetectorID==4) {
      detectorName = "DRZ1";
   }
      //DRZ2 monitering the electron beams after magnets
   else if(DetectorID==7) {
      detectorName = "DRZ2";
   }
      //Out scintillator
   else if(DetectorID==9) {
      detectorName = "Detector";
   }
   else {
      detectorName = "";
   }
   return detectorName;
}




void t1::FillTimeInfo(string name, float hitTime, float weight)
{

   //0~100 micro second
   histSvc->BookFillHist("time"+name, 1000, 0, 100, hitTime, weight);
   //0~1 micro second
   if(hitTime<=1.) {
      histSvc->BookFillHist("time_small"+name, 1000, 0, 1, hitTime, weight);
   }
   //0~0.1 micro second
   if(hitTime<=0.1) {
      histSvc->BookFillHist("time_tiny"+name, 1000, 0, 0.1, hitTime, weight);
   }
}


void t1::FillHists(int nHit, float process_weight)
{
   float hitTime = (det_time_start[nHit] + det_time_end[nHit]) * 0.5;
   FillTimeInfo("", hitTime, process_weight);
   FillTimeInfo("_edep", hitTime, process_weight*det_edep[nHit]);
   histSvc->BookFillHist("energy", 1000, 0, 500, det_kine[nHit], process_weight);
   histSvc->BookFillHist("edep", 1000, 0, 500, det_edep[nHit], process_weight);
   histSvc->BookFillHist("xy", 1000, -300, 300, 1000, -200, 200, det_x[nHit], det_y[nHit], process_weight);
}



void t1::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      if(jentry%100000==0) {
         cout << "processed " << jentry << " events" << endl;
      }

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      (this->*func_anlysis_method)();
   }
   histSvc->Write();
}
