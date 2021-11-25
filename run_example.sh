#! /bin/bash
inputDir=/home/chencheng/musrsim-sms/build/run/data/Nov.25.2021/
./main.exe -i ${inputDir}/musr_1000_Laser.root -o output_musr_1000_Laser.root -m RealGeometryIrradiation
echo "Finished"
