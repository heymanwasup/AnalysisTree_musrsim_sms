#! /bin/bash
inputDir=/home/chencheng/musrsim-sms/build/run/data/

JobID=${3}
InputFile=${inputDir}/musr_0_${1}_${3}.root
OutputFile=./output/output_musr_1000_${1}_${3}.root
Analysis=${2}

echo "Job ID        : "${JobID}
echo "Input file    : "${InputFile}
echo "Output file   : "${OutputFile}
echo "Run analysis  : "${Analysis}
echo "Running on    : "${hostname}

source  /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh
cd /home/chencheng/AnalysisTree_musrsim_sms
./main.exe -i ${InputFile} -o ${OutputFile} -m ${Analysis}

echo "Finished"