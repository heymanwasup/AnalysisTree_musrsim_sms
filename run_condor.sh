#! /bin/bash
# inputDir=/home/chencheng/musrsim-sms/build/run/data/Nov.21.2021/
# inputDir=/home/chencheng/musrsim-sms/build/run/data/DataForAna/
inputDir=/home/chencheng/musrsim-sms/build/run/data/
source  /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh
cd /home/chencheng/AnalysisTree_musrsim_sms
# ./main.exe -i ${inputDir}/musr_0_${1}_${2}.root -o ./output/output_musr_1000_${1}_${2}.root -m RealGeometryIrradiation
./main.exe -i ${inputDir}/musr_0_${1}_${2}.root -o ./output/output_musr_1000_${1}_${2}.root -m RealGeometry_1p2GeV
# ./main.exe -i ${inputDir}/musr_1000_${1}.root -o output_musr_1000_${1}.root -m RealGeometryGmm
echo "Finished"