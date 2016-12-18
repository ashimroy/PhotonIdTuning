Copy the EA.txt file from the Eas directory and parse them into
the processor and aplly them to the isolations, before extracting the pt scalling.
Make sure the input file in the CutID.h file is correct one that you produce from merged pt sample

Excecute by:
root -l run_ParseEAs.C
Two files will be created. One for barrel and one for endcap and they contain the
trainning trees for the Galgorythm.. These two files will be used for next steps as input files.

you can also submit the jobs in condor. Modify the exec.csh and condor file for submitting the jobs in condor.

GA cuts optimization

Go to bar / end cap. Open the Reg.C file. Correct the input file to point to root file you created in the merged file that reads either as barrel or as End
Cap trees etc. Also here you specify the scaling (the values you got in the final step in Isopt) for the iso variables - in the input variables specification section
You need to specify the initial selection for the first step training. Open the Scr99.C script
make sure the input is correct and run. This will generate a txt file with preselection cuts for
the variables that include the 99.9% of the sample. The name of the txt file is 99per.txt
Then you need to run the TMVA with the Reg.C script. This takes half a day atleast, usually
20 hours and this of course depends on your sample. It is also the greatest factor for delays
since a mistake here can cost 20-40 hours + the extra 2 steps which are also a lot of hours too.

You ll need to use some kind of batch system to do this.

Once you have your scripts to push jobs into batch system, you just need to say 
root -l -b Reg.C

For FNAL condor batch system you need to modify the condor* and exec*.csh scripts.  
Once the job is done, a directory will be created with name weights. There an xml file lives
that has the cuts and the efficiencies for each of them .
Also an output file .root will be created with ROC curves and other training diagnostic plots.

Second step optimization

Now you need to extract the cuts of the previous optimization to use for the next one. To
do so you need to run the script Reader.C . There you need to make sure the input file is
correct and the efficiency you are reading is correct / the pt scaling of the variables. Running
this script will generate a txt file with pre selections for the next training.
Making sure again input files/ scaling in the RegM.C file. And the send that to the batch
system.

Run the reader again and extract the cuts from the 2nd training an input it to the 3rd RegT.C

The txt files created by the Reader.C in each step can then be used to make the table of
the cuts for the ID. You also need the efficienies and bckground rejection.

In the directory efc, copy the txt files with the cuts and the efficiency will be calculated by executing :
root -l Calculator_ef.C

This will create a txt with the efficiency and bck rejection for each working point.
Copy all the txt files from this directory to the tbw directory. And run the corresponding .C script.



