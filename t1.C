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

bool t1::GmmStudy_PaperGeo() {

   for (int nHit=0; nHit<det_n; nHit++){
      switch (det_ID[nHit]) {
         case 22: // BackDet1
            if (det_edep_mup[nHit] > 0 && det_edep_mun[nHit] > 0) histSvc->BookFillHist("gmm_pair_count",  1, 0, 1, 0, 1.0, false);
            if (det_edep_mup[nHit] > 0){  // mu+
               histSvc->BookFillHist("mu_p_count", 1, 0, 1, 0, 1.0, false);
            }
            if (det_edep_mun[nHit] > 0) {  // mu-
               histSvc->BookFillHist("mu_n_count", 1, 0, 1, 0, 1.0, false);
            }
            break;
         case 23: // BackDet2
            if (det_edep_mup[nHit] > 0){
               histSvc->SetParticleTag("mu_p");

               float angle_degree = TMath::ATan(det_y[nHit] / 1000.) * 180 / 3.141592653;
               histSvc->BookFillHist("energy", 1000, 0, 10000, det_kine_mup[nHit]);
               histSvc->BookFillHist("angle", 1000, -90, 90, angle_degree);
               histSvc->BookFillHist("energy_angle", 100, 0, 10000, 250, -90, 90, det_kine_mup[nHit], angle_degree);
            }
            if (det_edep_mun[nHit] > 0){
               histSvc->SetParticleTag("mu_n");

               float angle_degree = TMath::ATan(det_y[nHit] / 1000.) * 180 / 3.141592653;
               histSvc->BookFillHist("energy", 1000, 0, 10000, det_kine_mun[nHit]);
               histSvc->BookFillHist("angle", 1000, -90, 90, angle_degree);
               histSvc->BookFillHist("energy_angle", 100, 0, 10000, 250, -90, 90, det_kine_mun[nHit], angle_degree);
            }
            if (det_edep_mup[nHit] > 0 && det_edep_mun[nHit] > 0)
               histSvc->BookFillHist("mu_p&n_energy", 1000, 0, 10000, 1000, 0, 10000, det_kine_mup[nHit], det_kine_mun[nHit], 1.0, false);
            break;
      }
   }
   return true;
}

bool t1::MoreParticles(){
   for (int i=0; i<det_n; i++){
      if (det_ID[i] != 22 || det_edep_mup[i] == 0) continue;

      histSvc->BookFillHist("mup_kine", 5000, 0, 500, det_kine_mup[i], 1.0, false);
      if (det_kine_mup[i] < 4.5 && det_kine_mup[i] > 3.5){
         if(PID_to_Name.find(det_VrtxPrtParticleID[i])!=PID_to_Name.end()) {
            histSvc->SetParticleTag(PID_to_Name[det_VrtxPrtParticleID[i]]);
         }
         else {
            histSvc->SetParticleTag(std::to_string(det_VrtxPrtParticleID[i]));
         }
         histSvc->BookFillHist("prt_3.5-4.5_count", 1, 0, 1, 0);
         histSvc->BookFillHist("tot_3.5-4.5_count", 1, 0, 1, 0, 1, false);
      }
      if (det_kine_mup[i] < 150 && det_kine_mup[i] > 120){
         if(PID_to_Name.find(det_VrtxPrtParticleID[i])!=PID_to_Name.end()) {
            histSvc->SetParticleTag(PID_to_Name[det_VrtxPrtParticleID[i]]);
         }
         else {
            histSvc->SetParticleTag(std::to_string(det_VrtxPrtParticleID[i]));
         }
         histSvc->BookFillHist("prt_120-150_count", 1, 0, 1, 0);
         histSvc->BookFillHist("tot_120-150_count", 1, 0, 1, 0, 1, false);
      }
   }
   return true;
}

bool t1::mac_9098() {
    for (int i=0; i<det_n; i++) {
        if (det_ID[i] != 22 || det_edep_mup[i] == 0) continue;

        bool flag = false;
        for (int j=0; j<mup_n; j++){
            if (det_VrtxTrackID[i] == mup_TrackID[j]) {
                std::cout << "Find!" << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << "ERROR! Track not found! Track ID: " << det_VrtxTrackID[i] << std::endl;
            return false;
        }
    }
    return true;
}

bool t1::mac_9097() {
    for (int i=0; i<det_n; i++){
        if (det_ID[i] != 22 || det_edep_mup[i] == 0) continue;

        histSvc->BookFillHist("mup_kine", 5000, 0, 500, det_kine_mup[i], 1.0, false);
        histSvc->BookFillHist("mup_cnt", 1, 0, 1, 0, 1.0, false);
        if (det_kine_mup[i] < 4.5 && det_kine_mup[i] > 3.5){
            if(PID_to_Name.find(det_VrtxPrtParticleID[i])!=PID_to_Name.end()) {
                histSvc->SetParticleTag(PID_to_Name[det_VrtxPrtParticleID[i]]);
            }
            else {
                histSvc->SetParticleTag(std::to_string(det_VrtxPrtParticleID[i]));
            }
            histSvc->BookFillHist("prt_3.5-4.5_count", 1, 0, 1, 0);
            histSvc->BookFillHist("tot_3.5-4.5_count", 1, 0, 1, 0, 1, false);

            bool flag = false;
            for (int j=0; j<mup_n; j++){
                if (det_VrtxTrackID[i] == mup_TrackID[j]){
//                    std::cout << mup_GenposX[j] << " " << mup_GenposY[j] << " " << mup_GenposZ[j] << std::endl;
//                    histSvc->BookFill3dHist("mup_3.5-4.5_genpos", 600, -60, 60, 600, -60, 60, 1500, -150, 150, mup_GenposX[j], mup_GenposY[j], mup_GenposZ[j], 1,
//                                            false);
                    histSvc->BookFillHist("mup_3.5-4.5_genposZ", 3000, -50, 50, mup_GenposZ[j], 1, false);
                    double r = sqrt(pow(mup_GenposX[j],2) + pow(mup_GenposY[j], 2));
                  histSvc->BookFillHist("mup_3.5-4.5_genposRZ", 3000, -60, 60, 3000, -50, 50, r, mup_GenposZ[j], 1, false);
                  //   if (mup_GenposZ[j] < -9.9 && mup_GenposZ[j] > -10.1) std::cout << "CHECK: posZ is: " << mup_GenposZ[j] << std::endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                std::cout << "ERROR! Track not found! Track ID: " << det_VrtxTrackID[i] << std::endl;
            }
        }
        if (det_kine_mup[i] < 3 && det_kine_mup[i] > 1){
            if(PID_to_Name.find(det_VrtxPrtParticleID[i])!=PID_to_Name.end()) {
                histSvc->SetParticleTag(PID_to_Name[det_VrtxPrtParticleID[i]]);
            }
            else {
                histSvc->SetParticleTag(std::to_string(det_VrtxPrtParticleID[i]));
            }
            histSvc->BookFillHist("prt_1-3_count", 1, 0, 1, 0);
            histSvc->BookFillHist("tot_1-3_count", 1, 0, 1, 0, 1, false);

            bool flag = false;
            for (int j=0; j<mup_n; j++){
                if (det_VrtxTrackID[i] == mup_TrackID[j]){
//                    std::cout << mup_GenposX[j] << " " << mup_GenposY[j] << " " << mup_GenposZ[j] << std::endl;
//                    histSvc->BookFill3dHist("mup_3.5-4.5_genpos", 600, -60, 60, 600, -60, 60, 1500, -150, 150, mup_GenposX[j], mup_GenposY[j], mup_GenposZ[j], 1,
//                                            false);
                    histSvc->BookFillHist("mup_1-3_genposZ", 3000, -50, 50, mup_GenposZ[j], 1, false);
                  //   if (mup_GenposZ[j] < -9.9 && mup_GenposZ[j] > -10.1) std::cout << "CHECK: posZ is: " << mup_GenposZ[j] << std::endl;
                    double r = sqrt(pow(mup_GenposX[j],2) + pow(mup_GenposY[j], 2));
                  histSvc->BookFillHist("mup_1-3_genposRZ", 3000, -60, 60, 3000, -50, 50, r, mup_GenposZ[j], 1, false);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                std::cout << "ERROR! Track not found! Track ID: " << det_VrtxTrackID[i] << std::endl;
            }
        }

        if (det_kine_mup[i] < 150 && det_kine_mup[i] > 120){
            if(PID_to_Name.find(det_VrtxPrtParticleID[i])!=PID_to_Name.end()) {
                histSvc->SetParticleTag(PID_to_Name[det_VrtxPrtParticleID[i]]);
            }
            else {
                histSvc->SetParticleTag(std::to_string(det_VrtxPrtParticleID[i]));
            }
            histSvc->BookFillHist("prt_120-150_count", 1, 0, 1, 0);
            histSvc->BookFillHist("tot_120-150_count", 1, 0, 1, 0, 1, false);

            bool flag = false;
            for (int j=0; j<mup_n; j++){
                if (det_VrtxTrackID[i] == mup_TrackID[j]){
//                std::cout << mup_GenposX[j] << " " << mup_GenposY[j] << " " << mup_GenposZ[j] << std::endl;
//                histSvc->BookFill3dHist("mup_120-150_genpos", 600, -60, 60, 600, -60, 60, 1500, -150, 150, mup_GenposX[j], mup_GenposY[j], mup_GenposZ[j], 1,
//                                        false);
                    histSvc->BookFillHist("mup_120-150_genposZ", 1500, -150, 150, mup_GenposZ[j], 1, false);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                std::cout << "ERROR! Track not found! Track ID: " << det_VrtxTrackID[i] << std::endl;
            }
        }


    }
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

      if(jentry%1000==0) {
         cout << "processed " << jentry << " events" << endl;
      }

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      bool flag = (this->*func_anlysis_method)();
//      if (!flag){
//          std::cout << "Event: " << jentry << std::endl;
//      }
   }
   histSvc->Write();
}
