#define t1_cxx
#include "t1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"
#include <iostream>

using namespace std;

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

bool t1::RealGeometry_1p2GeV()
{   
   for(int nHit=0;nHit<det_n;nHit++) {      
      histSvc->InitNameSvc();
      float process_weight = 1.0;
      // if(det_VrtxProcID[nHit]==19) { // Gamma mumu process xsection nomalize to 1
      //     process_weight = 1e-3;
      // }
      string detectorName = GetDetectorName(det_ID[nHit]);
      string particleName = GetParticleName(det_VrtxParticleID[nHit]);
      string parentParticleName = GetParticleName(det_VvvParticleID[nHit]);
      string processName = GetProcessName(det_VrtxProcID[nHit]);
      string parentProcessName = GetProcessName(det_VvvProcID[nHit]);

      if(detectorName=="") continue;

      //(detector)_(variable)
      histSvc->SetDetectorTag(detectorName);      
      FillHists(nHit,process_weight);

      //(detector)_(particle)_(variable)
      histSvc->SetProcessTag(particleName);
      FillHists(nHit,process_weight);

      //(detector)_(process)_(particle)_(variable)
      histSvc->SetProdTag(processName);      
      FillHists(nHit,process_weight);

      //(detector)_(process)_(particle)_From_(parent)_(variable)
      histSvc->SetProcessTag(particleName+"_From_"+parentParticleName);
      FillHists(nHit,process_weight);

      //(detector)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProdTag("From_"+parentProcessName);      
      FillHists(nHit,process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProdTag(processName+"_From_"+parentProcessName);
      FillHists(nHit,process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_(variable)      
      histSvc->SetProcessTag(particleName);
      FillHists(nHit,process_weight);


      //(detector)_From_(parent process)_(particle)_(variable)
      histSvc->SetProdTag("From_"+parentProcessName);
      FillHists(nHit,process_weight);

      //(detector)_From_(parent process)_(variable)
      histSvc->SetProcessTag("");
      FillHists(nHit,process_weight);

      //(detector)_(process)_(variable)
      histSvc->SetProdTag(processName);
      FillHists(nHit,process_weight);
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
         histSvc->SetProcessTag(PID_to_Name[det_VrtxParticleID[nHit]]);
      }
      else {
         histSvc->SetProcessTag("UnknownPID");
      }

      float angle_degree = TMath::ATan(det_y[nHit]/200.)*180/3.141592653;

      histSvc->BookFillHist("energy",1000,0,10000,det_kine[nHit]);
      histSvc->BookFillHist("angle",1000,-90,90,angle_degree);
   }
   return true;
}

//Make histograms about irradiation study
//250 MeV of eletron beams injected into a Cu target with 3mm of thickness
//then continued with a Al plate with 1cm thickness
bool t1::IrradiationStudy()
{
   
   for(int nHit=0;nHit<det_n;nHit++) {
      if(PID_to_Name.find(det_VrtxParticleID[nHit])!=PID_to_Name.end()) {         
         histSvc->SetProcessTag(PID_to_Name[det_VrtxParticleID[nHit]]);
      }
      else {
         histSvc->SetProcessTag("UnknownPID");
      }

      if(det_VrtxParticleID[nHit]==22) {
         // cout << "gamma e = " << det_kine[nHit] << endl;
      }

      //Injected electrons distributions
      if(det_ID[nHit]==20) {
         histSvc->SetDetectorTag("Injected");                  
      }
      //After Cu plate
      else if(det_ID[nHit]==21) {
         histSvc->SetDetectorTag("AfterCu");
      }
      //After Al plate
      else if(det_ID[nHit]==24) {
         histSvc->SetDetectorTag("AfterAl");
      }
      //our scintillator
      else if(det_ID[nHit]==22) {
         histSvc->SetDetectorTag("Detector");
      }
      else {
         continue;
      }

      // float angle_degree = TMath::ATan(det_y[nHit]/200.)*180/3.141592653;

      histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit]);
      histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit]);
      // histSvc->BookFillHist("angle",1000,-90,90,angle_degree);
      histSvc->BookFillHist("xy",100,-20,20,100,-20,20,det_x[nHit],det_y[nHit]);      
   }
   return true;
}


//Gmumu study based on real geometry
bool t1::RealGeometryGmm()
{
   //mu_p and mu_m share a same vertex, so only draw once per event
   // bool vertexKineDraw = false; 
   for(int nHit=0;nHit<det_n;nHit++) {

      if(PID_to_Name.find(det_VrtxParticleID[nHit])!=PID_to_Name.end()) {
         histSvc->SetProcessTag(PID_to_Name[det_VrtxParticleID[nHit]]);
      }
      else {
         histSvc->SetProcessTag("UnknownPID");
         cout << "UnknownParticle "<< det_VrtxParticleID[nHit] << endl;
      }

      //DRZ1 monitering the injected electrons
      if(det_ID[nHit]==4) {
         histSvc->SetDetectorTag("DRZ1");
      }

      //DRZ2 monitering the electron beams after magnets
      else if(det_ID[nHit]==7) {
         histSvc->SetDetectorTag("DRZ2");
      }
      //Out scintillator
      else if(det_ID[nHit]==10) {
         histSvc->SetDetectorTag("Detector");
      }
      else {
         continue;
      }

      // float angle_degree = TMath::ATan(det_y[nHit]/200.)*180/3.141592653;

      histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit]);
      histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit]);      
      histSvc->BookFillHist("xy",1000,-300,300,1000,-200,200,det_x[nHit],det_y[nHit]);


      if(ProcessIDMapping.find(det_VrtxProcID[nHit])!=ProcessIDMapping.end()) {
         histSvc->SetProdTag(ProcessIDMapping[det_VrtxProcID[nHit]]);
      }
      else {
         histSvc->SetProdTag("UnknownProd");  
      }
      // histSvc->SetProcessTag("");
      histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit]);
      histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit]);
      histSvc->BookFillHist("xy",1000,-300,300,1000,-200,200,det_x[nHit],det_y[nHit]);      
   }
   return true;
}


void t1::FillTimeInfo(string name,float hitTime,float weight)
{
 
   //0~100 micro second
   histSvc->BookFillHist("time"+name,1000,0,100,hitTime,weight);
   //0~1 micro second
   if(hitTime<=1.) {
      histSvc->BookFillHist("time_small"+name,1000,0,1,hitTime,weight);
   }
   //0~0.1 micro second
   if(hitTime<=0.1) {
      histSvc->BookFillHist("time_tiny"+name,1000,0,0.1,hitTime,weight);
   }
}


void t1::FillHists(int nHit,float process_weight)
{  
      float hitTime = (det_time_start[nHit] + det_time_end[nHit]) * 0.5;
      FillTimeInfo("",hitTime,process_weight);
      FillTimeInfo("_edep",hitTime,process_weight*det_edep[nHit]);
      histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit],process_weight);
      histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit],process_weight);
      histSvc->BookFillHist("xy",1000,-300,300,1000,-200,200,det_x[nHit],det_y[nHit],process_weight);
}

bool t1::RealGeometryIrradiation()
{
   
   for(int nHit=0;nHit<det_n;nHit++) {
      histSvc->InitNameSvc();
      float process_weight = 1.0;
      // if(det_VrtxProcID[nHit]==19) { // Gamma mumu process xsection nomalize to 1
      //     process_weight = 1e-3;
      // }
      string detectorName = GetDetectorName(det_ID[nHit]);
      string particleName = GetParticleName(det_VrtxParticleID[nHit]);
      string parentParticleName = GetParticleName(det_VvvParticleID[nHit]);
      string processName = GetProcessName(det_VrtxProcID[nHit]);
      string parentProcessName = GetProcessName(det_VvvProcID[nHit]);

      if(detectorName=="") continue;

      //(detector)_(variable)
      histSvc->SetDetectorTag(detectorName);      
      FillHists(nHit,process_weight);

      //(detector)_(particle)_(variable)
      histSvc->SetProcessTag(particleName);
      FillHists(nHit,process_weight);

      //(detector)_(process)_(particle)_(variable)
      histSvc->SetProdTag(processName);      
      FillHists(nHit,process_weight);

      //(detector)_(process)_(particle)_From_(parent)_(variable)
      histSvc->SetProcessTag(particleName+"_From_"+parentParticleName);
      FillHists(nHit,process_weight);

      //(detector)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProdTag("From_"+parentProcessName);      
      FillHists(nHit,process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_From_(parent)_(variable)      
      histSvc->SetProdTag(processName+"_From_"+parentProcessName);
      FillHists(nHit,process_weight);

      //(detector)_(process)_From_(parent process)_(particle)_(variable)
      histSvc->SetProcessTag(particleName);
      FillHists(nHit,process_weight);


      //(detector)_From_(parent process)_(particle)_(variable)
      histSvc->SetProdTag("From_"+parentProcessName);
      FillHists(nHit,process_weight);

      //(detector)_From_(parent process)_(variable)
      histSvc->SetProcessTag("");
      FillHists(nHit,process_weight);

      //(detector)_(process)_(variable)
      histSvc->SetProdTag(processName);
      FillHists(nHit,process_weight);
   }
   return true;
}

void t1::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   // for (Long64_t jentry=0; jentry<100000;jentry++) {
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