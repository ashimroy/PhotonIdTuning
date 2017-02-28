#!/bin/tcsh
echo "inside jobsubmit"
source /cvmfs/cms.cern.ch/cmsset_default.csh 
echo "sourced"
pwd
cd /uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/
cmsenv
cd ${_CONDOR_SCRATCH_DIR}
pwd
hostname
root -l -b RegM.C
cp -r weights/*.xml .
cp -r weights/*.C .
