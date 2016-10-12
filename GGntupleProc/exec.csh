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
./SP16.exe root://cmsxrootd.fnal.gov//store/user/maravin/GGNTUPLE/DATA/V08_00_05_00/job_spring16_gjet_pt20_MGG_40to80_miniAOD.root gjet_pt20_MGG_40to80.root -10000 100000 1.0
./SP16.exe root://cmsxrootd.fnal.gov//store/user/maravin/GGNTUPLE/DATA/V08_00_05_00/job_spring16_gjet_pt20to40_MGG_80toInf_miniAOD.root gjet_pt20to40_MGG_80toInf.root -10000 100000 0.102369421
./SP16.exe root://cmsxrootd.fnal.gov//store/user/maravin/GGNTUPLE/DATA/V08_00_05_00/job_spring16_gjet_pt40_MGG_80toInf_miniAOD.root gjet_pt40_MGG_80toInf.root -10000 100000 0.1434955572
./SP16.exe root://cmsxrootd.fnal.gov//store/user/maravin/GGNTUPLE/DATA/V08_00_05_00/job_spring16_gjet_pt15to6000_miniAOD.root gjet_sp16_pt15to6000.root -10000 100000 1.0
