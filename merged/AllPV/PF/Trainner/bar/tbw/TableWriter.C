#include <iostream>
#include <fstream>

void TableWriter(){

  
  double efL  = 0 ; 
  double efM  = 0; 
  double efT  = 0; 
  
  double bkL  = 0 ; 
  double bkM  = 0; 
  double bkT  = 0; 
  


  double Sie[3] = {0};
  double HoE[3]  = {0.05,0.05,0.05};
  double iC[3]   = {0};
  double iN[3]   = {0};
  double iP[3]   = {0};


  double slopeP = 0.0010; 
  double slopeN = 0.0025;



  ofstream myfile; 
  myfile.open("Cuts_Barrel.txt");

  ifstream Lc; 
  Lc.open("LooseR.txt");
  ifstream Mc; 
  Mc.open("MediumR.txt");
  ifstream Tc; 
  Tc.open("TightR.txt");


  ifstream efBk; 
  efBk.open("efBk.txt");

  if(efBk.is_open()){
    while(!efBk.eof()){
      efBk>>efL>>bkL>>efM>>bkM>>efT>>bkT;
      break;
    }
  }


  

  if(Lc.is_open()){
    while(!Lc.eof()){
      Lc>>Sie[0]>>iC[0]>>iN[0]>>iP[0];
      break;
    }
  }

  if(Mc.is_open()){
    while(!Mc.eof()){
      Mc>>Sie[1]>>iC[1]>>iN[1]>>iP[1];
      break;
    }
  }

  if(Tc.is_open()){
    while(!Tc.eof()){
      Tc>>Sie[2]>>iC[2]>>iN[2]>>iP[2];
      break;
    }
  }

  myfile<<"| *BARREL* | *Loose ("<<efL <<"%)* | *Medium ("<<efM<<"%)* | *Tight ("<<efT<<"%)* |"<<endl;
  myfile<<"| *Background Rejection* | *Loose ("<<bkL <<"%)* | *Medium ("<<bkM<<"%)* | *Tight ("<<bkT<<"%)* |"<<endl;
  // myfile<<"| Has Pixel Seed | No | No | No |"<<endl;
  myfile<<"| HoverE|"<<HoE[0]<<" | "<<HoE[1]<<"| "<<HoE[2]<<" | "<<endl;
  myfile<<"| %$\sigma_{i\eta i\eta}$% |"<< Sie[0]<<"|"<<Sie[1]<<" | "<<Sie[2]<<" | "<<endl;
  myfile<<"| Rho corrected [[EgammaPFBasedIsolation][PF charged hadron isolation]] |"<<iC[0]<<"|"<< iC[1]<<" | "<<iC[2] <<"|"<<endl;
  myfile<<"| Rho corrected [[EgammaPFBasedIsolation][PF neutral hadron isolation]] | "<<iN[0]<<" + "<<slopeN<<"*pho_pt" <<" |"<<iN[1]<<" + "<<slopeN<<"*pho_pt" <<" | "<<iN[2]<<" + "<<slopeN<<"*pho_pt"<<" |"<<endl;
  myfile<<"| Rho corrected [[EgammaPFBasedIsolation][PF photon isolation]] |"<<iP[0]<<" + "<<slopeP<<"*pho_pt"<<" | "<<iP[1]<<" + "<<slopeP<<"*pho_pt"<<" | "<<iP[2]<<" + "<<slopeP<<"*pho_pt"<<" | "<<endl;

  myfile.close();
}
