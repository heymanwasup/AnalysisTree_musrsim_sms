#include "t1.h"
#include "t1.h"
#include "TChain.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>


using namespace std;

void ShowUsage(string exe) {
    cout <<"Usage: \n "<< exe << " -i /path/to/input.root -o /path/to/output.root -m analysis_method"<<endl;
}

map<string,string> parse_argv(int argc,char *argv[]) {
    map<string,string> config;

    map<string,string> name_map = {{"-i","input"},{"-o","output"},{"-m","method"}};
    int n_arg = 1;
    while(n_arg<argc){
        if(name_map.find(argv[n_arg])!=name_map.end()){
            config[name_map[argv[n_arg]]] = argv[n_arg+1];
            n_arg += 2;
        }
        else {            
            cout << "unknown args: "<< argv[n_arg] << endl;
            ShowUsage(argv[0]);
            exit(1);
        }
    }
    for(auto itr : name_map) {
        if(config.find(itr.second)!=config.end()) {            
            cout << "Using " << itr.second << " : " << config.find(itr.second)->second << endl;
        }
        else {
            cout << "Args not assigned: " << itr.second << endl;
            ShowUsage(argv[0]);
            exit(1);
        }
    }
    return config;
}



int main(int argc,char *argv[]) {

    auto config = parse_argv(argc,argv);

    TFile * input_file = TFile::Open(config["input"].c_str());
    TTree * musr_tree = (TTree*)input_file->Get("t1");
    TFile * output_file = new TFile(config["output"].c_str(),"recreate");

    string method_name = config["method"];

    t1 myAna(musr_tree,output_file);

    //Book method before start event loop
    if(method_name == "GmmStudy") {
        myAna.func_anlysis_method = &t1::GmmStudy;
    }
    else if(method_name == "RealGeometryIrradiation") {
        myAna.func_anlysis_method = &t1::RealGeometryIrradiation;
    }
    else if (method_name == "RealGeometryGmm") {
        myAna.func_anlysis_method = &t1::RealGeometryGmm;
    }
    else if (method_name == "RealGeometry_1p2GeV") {
        myAna.func_anlysis_method = &t1::RealGeometry_1p2GeV; 
    }
    else {
        cout << "unknown method: " << method_name << endl;
        throw "main() : exception!";
    }

    myAna.Loop();
    output_file->Close();

    return 0;
}
