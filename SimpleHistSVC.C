#include "SimpleHistSVC.h"
#include <iostream>

std::string SimpleHistSVC::getFullName(std::string name) {

    std::string fullname = name;
    if(processName!="") fullname = processName + "_" + fullname;
    if(prodName!="") fullname = prodName + "_" + fullname;
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

void SimpleHistSVC::SetProcessTag(std::string name) {
    processName = name;
}

void SimpleHistSVC::SetDetectorTag(std::string name) {
    detectorName = name;
}

void SimpleHistSVC::SetProdTag(std::string name) {
    prodName = name;
}

void SimpleHistSVC::BookFillHist(std::string name, int nbins, float start, float end, float value) {
    std::string fullname = getFullName(name);
    std::map<std::string,TH1F*>::iterator itr = histsDB_1d.find(fullname);
    
    TH1F * hist;
    if(itr == histsDB_1d.end()) {
        
        hist = new TH1F(fullname.c_str(),fullname.c_str(),nbins,start,end);
        
        hist->SetDirectory(output_file);
        
        histsDB_1d[fullname] = hist;
    } else {
        hist = itr->second;
    }
    hist->Fill(value);
}

void SimpleHistSVC::BookFillHist(std::string name, int nbinsX, float startX, float endX, int nbinsY, float startY, float endY,float x, float y) {    
    std::string fullname = getFullName(name);
    
    auto itr = histsDB_2d.find(fullname);
    TH2F * hist;
    if(itr == histsDB_2d.end()) {
        hist = new TH2F(fullname.c_str(),fullname.c_str(),nbinsX,startX,endX,nbinsY,startY,endY);
        hist->SetDirectory(output_file);
        histsDB_2d[fullname] = hist;
    } else {
        hist = itr->second;
    }
    hist->Fill(x,y);
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
    processName = std::string("hist");
    detectorName = std::string("");
    
    histsDB_1d.clear();
    
    histsDB_2d.clear();
}

void SimpleHistSVC::InitNameSvc() {
    processName = std::string("");
    detectorName = std::string("");
    prodName = std::string("");
}