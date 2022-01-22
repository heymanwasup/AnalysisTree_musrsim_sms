#ifndef SimpleHistSVC_h
#define SimpleHistSVC_h
#include <map>
#include <string>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>

class SimpleHistSVC {
protected:
    std::map<std::string,TH1F *> histsDB_1d;
    std::map<std::string,TH2F *> histsDB_2d;
    std::string particleName;
    std::string detectorName;
    std::string processName;
    TFile *output_file;

public:
    SimpleHistSVC();
    ~SimpleHistSVC();
    void BookFillHist(std::string name, int nbins, float start, float end, float value, float weight=1.);
    void BookFillHist(std::string name, int nbinsX, float startX, float endX, int nbinsY, float startY, float endY,float x, float y, float weight=1., bool if_use_full_name = true);
    void BookFillCutHist(std::string name, int nbins, std::string cuts[], std::string label, float weight=1.);
    void BookFillCutHist(std::string name, int nbinsX, std::string cutsX[], int nbinsY, std::string cutsY[], std::string labelX, std::string labelY, float weight=1.);

    void SetParticleTag(std::string name);
    void SetDetectorTag(std::string name);
    void SetProcessTag(std::string name);

    std::string GetParticleTag();

    void Init();
    void InitNameSvc();
    void BookFile(TFile *file);
    void Write();

protected:
    std::string getFullName(std::string name);
};
#endif
