objects = main.o 
SP16.exe : $(objects)
	g++ -o SP16.exe $(objects) `root-config --libs`
main.o : main.C SP16.h SP16.C
	g++ -Wall -Wno-deprecated `root-config --cflags` main.C -c
clean :
	rm SP16.exe $(objects)
