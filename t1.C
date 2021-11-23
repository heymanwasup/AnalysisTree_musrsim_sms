#define t1_cxx
#include "t1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"
#include <iostream>

using namespace std;
//Make histograms about gmm  study
bool t1::GmmStudy() {
   //only interest at font cap detector               
   for(int nHit=0;nHit<det_n;nHit++) {
      if(det_ID[nHit]!=22) {
         continue;
      }         
      
      //Currently we only interest at mu-/mu+/gamma      
      if(det_VrtxParticleID[nHit]==13) {
         histSvc->SetProcessTag("mu_m");  
      }
      else if(det_VrtxParticleID[nHit]==-13) {
         histSvc->SetProcessTag("mu_p");
      }
      else if(det_VrtxParticleID[nHit]==22) {
         histSvc->SetProcessTag("gamma");
      }
      else {
         continue;
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
         // cout << "particle " << endl;
         histSvc->SetProcessTag(PID_to_Name[det_VrtxParticleID[nHit]]);
      }
      else {
         histSvc->SetProcessTag("UnknownPID");
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

void t1::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      histSvc->InitNameSvc();
      // GmmStudy();
      IrradiationStudy();
      
   }
   histSvc->Write();

}