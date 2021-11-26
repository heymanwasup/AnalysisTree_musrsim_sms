#define t1_cxx
#include "t1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"
#include <iostream>

using namespace std;

//Make histograms about gmm study
bool t1::GmmStudy() {

    for(int nHit=0;nHit<det_n;nHit++) {
        //only interest at font cap detector
        if(det_ID[nHit]!=21) {
            continue;
        }

        if(PID_to_Name.find(det_VrtxParticleID[nHit])!=PID_to_Name.end()) {
            histSvc->SetParticleTag(PID_to_Name[det_VrtxParticleID[nHit]]);
        }
        else {
            histSvc->SetParticleTag("UnknownPID");
        }
        float angle_x = TMath::ATan(det_x[nHit]/det_z[nHit])*180/TMath::Pi();
        float theta = TMath::ACos(det_z[nHit] / TMath::Sqrt(TMath::Power(det_x[nHit], 2) + TMath::Power(det_y[nHit], 2))) * 180 / TMath::Pi();

        histSvc->BookFillHist("energy",1000,0,10000,det_kine[nHit]);
        histSvc->BookFillHist("angle_x",1000,-90,90,angle_x);
        histSvc->BookFillHist("theta", 1000, 0, 180, theta);
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
            histSvc->SetParticleTag(PID_to_Name[det_VrtxParticleID[nHit]]);
        }
        else {
            histSvc->SetParticleTag("UnknownPID");
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
            histSvc->SetParticleTag(PID_to_Name[det_VrtxParticleID[nHit]]);
        }
        else {
            histSvc->SetParticleTag("UnknownPID");
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
            histSvc->SetProcessTag(ProcessIDMapping[det_VrtxProcID[nHit]]);
        }
        else {
            histSvc->SetProcessTag("UnknownProd");
        }
        // histSvc->SetParticleTag("");
        histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit]);
        histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit]);
        histSvc->BookFillHist("xy",1000,-300,300,1000,-200,200,det_x[nHit],det_y[nHit]);
    }
    return true;
}

//Make histograms about irradiation study
//with real geometry
//250 MeV of eletron beams
//
bool t1::RealGeometryIrradiation()
{

    for(int nHit=0;nHit<det_n;nHit++) {
        if(PID_to_Name.find(det_VrtxParticleID[nHit])!=PID_to_Name.end()) {
            histSvc->SetParticleTag(PID_to_Name[det_VrtxParticleID[nHit]]);
        }
        else {
            histSvc->SetParticleTag("UnknownPID");
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
        else if(det_ID[nHit]==9) {
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
            histSvc->SetProcessTag(ProcessIDMapping[det_VrtxProcID[nHit]]);
        }
        else {
            histSvc->SetProcessTag("UnknownProcess");
        }
        histSvc->SetParticleTag("");
        histSvc->BookFillHist("energy",1000,0,500,det_kine[nHit]);
        histSvc->BookFillHist("edep",1000,0,500,det_edep[nHit]);
        histSvc->BookFillHist("xy",1000,-300,300,1000,-200,200,det_x[nHit],det_y[nHit]);
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

        if(jentry%100000==0) {
            cout << "processed " << jentry << "events" << endl;
        }

        nb = fChain->GetEntry(jentry);   nbytes += nb;

        histSvc->InitNameSvc();
        (this->*func_anlysis_method)();
    }
    histSvc->Write();
}