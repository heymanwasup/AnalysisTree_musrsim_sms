#! /bin/bash
inputDir=/home/chencheng/musrsim-sms/build/run/data/Nov.21.2021/
echo ${1}
source  /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh
cd /home/chencheng/AnalysisTree_musrsim_sms
./main.exe ${inputDir}/musr_1003_${1}.root     output_musr_1003_${1}.root
echo "Finished"
