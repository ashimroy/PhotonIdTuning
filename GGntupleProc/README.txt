Run the following command:
make // it will produce SP16.exe
./SP16.exe inputfilename outputfilename Tot#ofEventsWantToProcess #ofEventsGapToPrint EventWeight // if the input file is in the different directory then give the filename with correct path

Example:
./SP16.exe /eos/uscms/store/user/maravin/GGNTUPLE/DATA/V08_00_05_00/job_spring16_gjet_pt20to40_MGG_80toInf_miniAOD.root gjet_pt20to40_MGG_80toInf.root -10000 100000 0.102369421
or
./SP16.exe job_spring16_gjet_pt20to40_MGG_80toInf_miniAOD.root gjet_pt20to40_MGG_80toInf.root -10000 100000 0.102369421
or
./SP16.exe ../../ntuple/job_spring16_gjet_pt20to40_MGG_80toInf_miniAOD.root gjet_pt20to40_MGG_80toInf.root -10000 100000 0.102369421


Do for the all pt bin samples(i.e. pt 20t040, 40to80 etc, not pt 15to6000) and then merge the files into one.

For flat pt sample (15to6000) event weight is 1.0 and do not merge with the pt bin sample. It will use later for isolation pt scaling study.

Event weight is calculated using the following formula:
Event weight = Cross Section * Filter Efficiency / Total Entries

For example you can go to the link
https://docs.google.com/spreadsheets/d/1NsMM_iGeKjt3sxCNxArPF-gJwglkn5Zxs3p4OHkrA9Q/edit


