You need now to extract the scaling of the isolation variables with the pt in order to include
that into the input variables for the genetic algorithm.
To do so, you need to process the high flat in pt gamma jet sample (in my case was a 15
GeV to 6TeV sample.

Copy the EA.txt file from the Eas directory and parse them into
the processor and aplly them to the isolations, before extracting the pt scalling.
Make sure the input file in the CutID.h file is correct one that you produce from flat pt sample

Excecute by:
root -l run_ParseEAs.C
Two files will be created. One for barrel and one for endcap. These two files will be used for next steps as input files.

you can also submit the jobs in condor. Modify the exec.csh and condor file for submitting the jobs in condor.

Scalings are extracted for Neutral Iso and Photon Iso not the charged one. Bar and End are
separated. You have a a bar/end directories and neu/pho for each. You go to one of them and after you make sure the input
file (the files that you created in the previous step) in the script Ex.C is correct.
Excecute: root -l Ex.C


