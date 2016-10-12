#include <iostream>
#include <fstream>

void TableWriter(double EAB[7][3]){

  ofstream myfile; 
  
  myfile.open("Effective_areas.txt");
  

  myfile<<"| *bin* | *EA charged hadrons* | *EA neutral hadrons* | *EA photons* |"<<endl;
  myfile<<"| abs(&eta;)<1.0|"<< EAB[0][0] <<"|"<< EAB[0][1] <<"|"<< EAB[0][2] <<"|"<<endl;
  myfile<<"| 1.0<abs(&eta;)<1.479 |"<<  EAB[1][0] <<" | "<< EAB[1][1] <<"|"<< EAB[1][2] <<"|"<<endl;
  myfile<<"| 1.479<abs(&eta;)<2.0|"<< EAB[2][0] <<" | "<< EAB[2][1]<<" | "<< EAB[2][2]<<" | "<<endl;
  myfile<<"| 2.0 <abs(&eta;) < 2.2 |"<<EAB[3][0]<<" | "<< EAB[3][1]<<" | "<< EAB[3][2] <<" | "<<endl;
  myfile<<"| 2.2 <abs(&eta;) < 2.3 |"<<EAB[4][0]<<" | "<< EAB[4][1]<<" | "<< EAB[4][2] <<" | "<<endl;
  myfile<<"| 2.3 <abs(&eta;) < 2.4 |"<<EAB[5][0]<<" | "<< EAB[5][1]<<" | "<< EAB[5][2] <<" | "<<endl;
  myfile<<"| abs(&eta;) > 2.4 |"<<EAB[6][0]<<" | "<< EAB[6][1]<<" | "<< EAB[6][2] <<" | "<<endl;

  myfile.close();


  ofstream myfile2;  
  myfile2.open("EA.txt");
  myfile2<<EAB[0][0]<<" "<<EAB[0][1]<<" "<<EAB[0][2]<<endl;
  myfile2<<EAB[1][0]<<" "<<EAB[1][1]<<" "<<EAB[1][2]<<endl;
  myfile2<<EAB[2][0]<<" "<<EAB[2][1]<<" "<<EAB[2][2]<<endl;
  myfile2<<EAB[3][0]<<" "<<EAB[3][1]<<" "<<EAB[3][2]<<endl;
  myfile2<<EAB[4][0]<<" "<<EAB[4][1]<<" "<<EAB[4][2]<<endl;
  myfile2<<EAB[5][0]<<" "<<EAB[5][1]<<" "<<EAB[5][2]<<endl;
  myfile2<<EAB[6][0]<<" "<<EAB[6][1]<<" "<<EAB[6][2]<<endl;
  myfile2.close();




}
