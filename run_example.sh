#! /bin/bash
inputDir=/home/chencheng/musrsim-sms/build/run/data/
./main.exe -i ${inputDir}/musr_1000_Laser.root -o output_musr_1000_Laser.root -m RealGeometryIrradiation
echo "Finished"
