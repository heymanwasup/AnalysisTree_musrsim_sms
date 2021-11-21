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




int main(int argc,char *argv[]) {
    TFile * input_file = TFile::Open(argv[1]);
    TTree * musr_tree = (TTree*)input_file->Get("t1");

    TFile * output_file = new TFile(argv[2],"recreate");
    t1 myAna(musr_tree,output_file);
    myAna.Loop();
    output_file->Close();

    return 0;
}
