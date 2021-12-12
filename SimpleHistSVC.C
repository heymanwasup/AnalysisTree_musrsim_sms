#include "SimpleHistSVC.h"
#include <iostream>
#include <algorithm>

int FoundLabelPosition(int nlabels, std::string cuts[], std::string label) {    
    auto itr = std::find(cuts,cuts+nlabels,label);
    int index = nlabels - 1;
    if(itr != cuts+nlabels) {
        index = std::distance(cuts,itr);
    }
    return index;
}

std::string SimpleHistSVC::getFullName(std::string name) {

    std::string fullname = name;
    if(particleName!="") fullname = particleName + "_" + fullname;
    if(processName!="") fullname = processName + "_" + fullname;
    if(detectorName!="") fullname = detectorName + "_" + fullname;

    return fullname;

}

SimpleHistSVC::SimpleHistSVC() {
    Init();
}

SimpleHistSVC::~SimpleHistSVC() {
    // std::cout << "call ~SimpleHistSVC()" << std::endl;
    // for(auto itr : histsDB_1d) {
    //     delete (itr.second);        
    // }
    histsDB_1d.clear();
    // std::cout<< "2d:" << histsDB_2d.size() << std::endl;
    // for(auto itr : histsDB_2d) {
    //     delete (itr.second);        
    // }
    histsDB_2d.clear();
}

void SimpleHistSVC::SetParticleTag(std::string name) {
    particleName = name;
}

void SimpleHistSVC::SetDetectorTag(std::string name) {
    detectorName = name;
}

void SimpleHistSVC::SetProcessTag(std::string name) {
    processName = name;
}

void SimpleHistSVC::BookFillHist(std::string name, int nbins, float start, float end, float value, float weight) {
    std::string fullname = getFullName(name);
    std::map<std::string,TH1F*>::iterator itr = histsDB_1d.find(fullname);
    
    TH1F * hist;
    if(itr == histsDB_1d.end()) {        
        hist = new TH1F(fullname.c_str(),fullname.c_str(),nbins,start,end);
        hist->Sumw2();        
        hist->SetDirectory(output_file);
        
        histsDB_1d[fullname] = hist;
    } else {
        hist = itr->second;
    }
    // std::cout << fullname << " " << value << "   " << weight << std::endl;
    hist->Fill(value,weight);
}

void SimpleHistSVC::BookFillHist(std::string name, int nbinsX, float startX, float endX, int nbinsY, float startY, float endY,float x, float y, float weight) {
    std::string fullname = getFullName(name);
    
    auto itr = histsDB_2d.find(fullname);
    TH2F * hist;
    if(itr == histsDB_2d.end()) {
        hist = new TH2F(fullname.c_str(),fullname.c_str(),nbinsX,startX,endX,nbinsY,startY,endY);
        hist->Sumw2();        
        hist->SetDirectory(output_file);

        histsDB_2d[fullname] = hist;
    } else {
        hist = itr->second;
    }
    hist->Fill(x,y,weight);
}

void SimpleHistSVC::BookFillCutHist(std::string name,int nbins, std::string cuts[], std::string label, float weight) {
    std::string fullname = std::string("Cutflow_1D_") + name;
    auto itr = histsDB_1d.find(fullname);
    TH1F * hist;
    if(itr == histsDB_1d.end()) {
        
        hist = new TH1F(fullname.c_str(),fullname.c_str(),nbins,-0.5,nbins-0.5);
        hist->Sumw2();
        for(int i=0;i<nbins;i++) {
            hist->GetXaxis()->SetBinLabel(i+1,cuts[i].c_str());
        }
        hist->SetDirectory(output_file);
        
        histsDB_1d[fullname] = hist;
    } else {
        hist = itr->second;
    }
    
    hist->Fill(FoundLabelPosition(nbins,cuts,label), weight);
}

void SimpleHistSVC::BookFillCutHist(std::string name, int nbinsX, std::string cutsX[], int nbinsY, std::string cutsY[], std::string labelX, std::string labelY, float weight) {
    std::string fullname = std::string("Cutflow_2D_") + name;
    auto itr = histsDB_2d.find(fullname);
    
    TH2F * hist;
    if(itr == histsDB_2d.end()) {
        hist = new TH2F(fullname.c_str(),fullname.c_str(),nbinsX,-0.5,nbinsX-0.5,nbinsY,-0.5,nbinsY-0.5);
        hist->Sumw2();
        for(int i=0;i<nbinsX;i++) {
            hist->GetXaxis()->SetBinLabel(i+1,cutsX[i].c_str());
        }
        for(int j=0;j<nbinsY;j++) {
            hist->GetYaxis()->SetBinLabel(j+1,cutsY[j].c_str());
        }
        hist->SetDirectory(output_file);
        
        histsDB_2d[fullname] = hist;
    } else {
        hist = itr->second;
    }

    hist->Fill(FoundLabelPosition(nbinsX,cutsX,labelX), FoundLabelPosition(nbinsY,cutsY,labelY), weight);
}


void SimpleHistSVC::BookFile(TFile *file) {
    output_file = file;
}

void SimpleHistSVC::Write() {
    for(auto itr : histsDB_1d) {
        (itr.second)->Write();
    }
    
    for(auto itr : histsDB_2d) {
        (itr.second)->Write();        
    }    
}

void SimpleHistSVC::Init() {
    InitNameSvc();
    
    histsDB_1d.clear();    
    histsDB_2d.clear();
}

void SimpleHistSVC::InitNameSvc() {
    particleName = std::string("");
    detectorName = std::string("");
    processName = std::string("");
}