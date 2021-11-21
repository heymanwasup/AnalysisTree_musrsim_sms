#define t1_cxx
#include "t1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"

void t1::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      for(int nHit=0;nHit<det_n;nHit++) {
         //only interest at font cap detector               
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
   }
   histSvc->Write();

}