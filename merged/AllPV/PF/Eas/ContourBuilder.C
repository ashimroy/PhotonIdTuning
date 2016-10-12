#include <TMath.h>
#include <cstdlib>
#include <TRandom.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TGraphErrors.h>

#include <vector>
#include <new>
#include "sstream"
#include <string>
#include <fstream>
#include <iostream>




void ContourBuilder(int bin,double minEta,double maxEta,double & in,double & ein,double & ip,double & eip,double  & ic,double  & eic){

  ostringstream fword; 
  fword << bin;
  string b_name = fword.str();
  string Pngg = "Iso_vsRho"+b_name+".png";
  char const *PNGName = Pngg.c_str();



  
  //  TFile *f1 = new TFile("../spring16_gjets_25ns.root");
  TFile *f1 = new TFile("/uscms_data/d3/asroy/PhotonIdTuning/CMSSW_7_3_5/src/CutBasedPhoID2016/merged/spring16_gjets_25ns.root");
  float rho,ppt,peta,Sie_ie,iso_P,iso_C,iso_N,to_e;
  int nvtx,isprmt;
  gStyle->SetOptStat(0);

  //Signal Tree                                                                        
  t1->SetBranchAddress("gedPhPt",&ppt);
  t1->SetBranchAddress("gedPhEta",&peta);
  t1->SetBranchAddress("gedNeuIso",&iso_N);
  t1->SetBranchAddress("gedChgIso",&iso_C);
  t1->SetBranchAddress("gedPhoIso",&iso_P);
  t1->SetBranchAddress("gedPhisPrompt",&isprmt);
  t1->SetBranchAddress("Rh",&rho);




  TH2F *isoNrho = new TH2F("isoNrho","Iso neutral hadrons vs #rho",30,0,30,2000,0,200);
  TH2F *isoPrho = new TH2F("isoPrho","Iso Photon vs #rho",30,0,30,2000,0,200);
  TH2F *isoCrho = new TH2F("isoCrho","Iso Charge hadrons vs #rho",30,0,30,2000,0,200);


  for(int i  = 0; i < t1->GetEntries();i++){
  //  for(int i  = 0; i < 10000000;i++){
    t1->GetEntry(i);
    if( i % 100000 == 0) cout<<"i"<<100*(1.0*i/(1.0*t1->GetEntries()))<<endl;

    if(fabs(peta) > maxEta ) continue;
    if(isprmt == 0 ) continue;
    if(fabs(peta) < minEta ) continue;
    if(ppt < 15 ) continue;
    if(ppt > 200 ) continue;

  
   
    isoNrho->Fill(rho,iso_N);
    isoPrho->Fill(rho,iso_P);
    isoCrho->Fill(rho,iso_C);

  }

  cout<<"Builded the 2d HISTOGRAM"<<endl;
  TH2F *hisN = isoNrho->Clone();
  TH2F *hisP = isoPrho->Clone();
  TH2F *hisC = isoCrho->Clone();
  int dim = hisN->GetXaxis()->GetNbins(); 

  cout<<"ENTRIS PER HISTO GAM TON HISTO TOU"<<endl;
  cout<<hisN->GetEntries()<<endl;
  cout<<hisP->GetEntries()<<endl;
  cout<<hisC->GetEntries()<<endl;




  double * cutVn; 
  double * errVHn; 
  double * errVLn; 
  double * bincn; 
  double * bincerHn; 
  double * bincerLn; 

  double * cutVp; 
  double * errVHp; 
  double * errVLp; 
  double * bincp; 
  double * bincerHp; 
  double * bincerLp; 

  double * cutVc; 
  double * errVHc; 
  double * errVLc; 
  double * bincc; 
  double * bincerHc; 
  double * bincerLc; 

  cutVp  = new double[dim];
  errVHp  = new double[dim];
  errVLp  = new double[dim];
  bincp  = new double[dim]; 
  bincerHp= new double[dim];
  bincerLp= new double[dim];

  
  cutVc  = new double[dim];
  errVHc  = new double[dim];
  errVLc  = new double[dim];
  bincc  = new double[dim]; 
  bincerHc= new double[dim];
  bincerLc= new double[dim];



  cutVn  = new double[dim];
  errVHn  = new double[dim];
  errVLn  = new double[dim];
  bincn  = new double[dim]; 
  bincerHn= new double[dim];
  bincerLn= new double[dim];


  
  for(int i  = 1; i <= dim ; i++){
    double xval = 0; 
    double errXH = 0; 
    double errXL = 0; 
    
    r21 = hisN->ProjectionY(" ",i,i+1," ");
    TH1F *h1 = r21->Clone();

    if(h1->GetEntries() > 10000 ) ErrCalc(h1,i,0.90,xval,errXL,errXH);
    cout<<"bin :"<<i<<" "<<xval<<"- "<<errXL<<"+ " << errXH<<endl;
    cutVn[i-1]   = xval; 
    errVLn[i-1]   = errXL; 
    errVHn[i-1]   = errXH;
    bincn[i-1] = hisN->GetXaxis()->GetBinCenter(i);
    bincerLn[i-1] = 0.0;
    bincerHn[i-1] = 0.0;
    
    xval = 0; 
    errXH = 0; 
    errXL = 0; 
    

    r22 = hisP->ProjectionY(" ",i,i+1," ");
    TH1F *h2 = r22->Clone();
    if( h2->GetEntries() > 0) ErrCalc(h2,i,0.90,xval,errXL,errXH);
   
    cout<<"bin :"<<i<<" "<<xval<<"-"<<errXL<<"+ " << errXH<<endl;
    cutVp[i-1]   = xval; 
    errVLp[i-1]   = errXL; 
    errVHp[i-1]   = errXH;
    bincp[i-1] = hisP->GetXaxis()->GetBinCenter(i);
    bincerLp[i-1] = 0.0;
    bincerHp[i-1] = 0.0;

    xval = 0; 
    errXH = 0; 
    errXL = 0; 
    
    r23 = hisC->ProjectionY(" ",i,i+1," ");
    TH1F *h3 = r23->Clone();
    if(  h3->GetEntries() > 0)ErrCalc(h3,i,0.90,xval,errXL,errXH);
    cout<<"bin :"<<i<<" "<<xval<<"-"<<errXL<<"+ " << errXH<<endl;
    cutVc[i-1]   = xval; 
    errVLc[i-1]   = errXL; 
    errVHc[i-1]   = errXH;
    bincc[i-1] = hisC->GetXaxis()->GetBinCenter(i);
    bincerLc[i-1] = 0.0;
    bincerHc[i-1] = 0.0;

  }
  


  TGraphAsymmErrors * IsoNvsrho = new TGraphAsymmErrors(dim,bincn,cutVn,bincerLn,bincerHn,errVLn,errVHn);
  TGraphAsymmErrors * IsoPvsrho = new TGraphAsymmErrors(dim,bincp,cutVp,bincerLp,bincerHp,errVLp,errVHp);
  TGraphAsymmErrors * IsoCvsrho = new TGraphAsymmErrors(dim,bincc,cutVc,bincerLc,bincerHc,errVLc,errVHc);
  
  TF1 *fnn = new TF1("fnn","[0]*x + [1]",5,20);
  TF1 *fnp = new TF1("fnp","[0]*x + [1]",5,20);
  TF1 *fnc = new TF1("fnc","[0]*x + [1]",5,20);


  IsoNvsrho->Fit("fnn","R");
  IsoPvsrho->Fit("fnp","R");
  IsoCvsrho->Fit("fnc","R");

  in = fnn->GetParameter(0);
  ip = fnp->GetParameter(0);
  ic = fnc->GetParameter(0);
  
  ein = fnn->GetParError(0);
  eip = fnp->GetParError(0);
  eic = fnc->GetParError(0);

  gStyle->SetOptFit(1);
  TCanvas *c3 = new TCanvas("c3","Iso vs Pt",1200,400);
  c3->Divide(3,1);
  c3->cd(1);
  IsoNvsrho->SetMarkerStyle(24); 
  IsoNvsrho->SetMarkerSize(0.4);
  IsoNvsrho->Draw("AP");
  IsoNvsrho->GetXaxis()->SetTitle("#rho");
  IsoNvsrho->GetYaxis()->SetTitle("Neutral Isolation 95% Contour ");

  c3->cd(2); 
  IsoPvsrho->SetMarkerStyle(24); 
  IsoPvsrho->SetMarkerSize(0.4);
  IsoPvsrho->Draw("AP");
  IsoPvsrho->GetXaxis()->SetTitle("#rho");
  IsoPvsrho->GetYaxis()->SetTitle("Photon Isolation 95% Contour ");
  
  c3->cd(3); 
  IsoCvsrho->SetMarkerStyle(24); 
  IsoCvsrho->SetMarkerSize(0.4);
  IsoCvsrho->Draw("AP");
  IsoCvsrho->GetXaxis()->SetTitle("#rho");
  IsoCvsrho->GetYaxis()->SetTitle("Charge Isolation 95% Contour ");
  
  c3->SaveAs(PNGName);


}



void ErrCalc(TH1F *HIST,int binxn,double perc,double & X_val, double & errXL,double & errXH){
  

  cout<<binxn<<endl;

  TH1F *h1 = HIST->Clone();
  int arsize = h1->GetXaxis()->GetNbins(); 
  
  double *eff; 
  double *eff_err; 
  double *cutV; 
  double *cutV_err; 
  
  eff      = new double[arsize];
  cutV     = new double[arsize];
  eff_err  = new double[arsize];
  cutV_err = new double[arsize];
  h1->Draw();
  int tot = h1->GetEntries();
  float tot_nz = tot - h1->GetBinContent(1);
  // cout<<tot<<endl;
    int integ = 0; 
    for(int i  = 1; i < (h1->GetXaxis()->GetNbins() + 1); i++){ 
      double xCut = h1->GetXaxis()->GetBinLowEdge(i); 
      integ += h1->GetBinContent(i); 
     

      if(integ != 0 && tot != 0 ){ 
	eff[i -1] = (integ*1.0/tot);
	//eff_err[i -1] = ((integ*1.0/tot)*sqrt(pow(sqrt(tot)/tot,2) + pow(sqrt(integ)/integ,2) )); 
	eff_err[i -1] = sqrt ( eff[i-1] * ( 1 - eff[i-1] ) / tot_nz ) ; 
      }else{
	eff_err[i -1] = 0.0; 
	eff[i -1] = 0.0;
      }
      
      cutV[i -1] = (xCut);
      cutV_err[i - 1] = 0;
      //  cout<<"bin :"<<i<<"  % :"<<integ*1.0/tot<<" cut val :"<<xCut <<endl;
    }


    gStyle->SetOptStat(1);
    //Now draw the resulting curve 
    TCanvas *c1 = new TCanvas("c1","The Eff- cut value plot",1200,600);
    
    c1->Divide(2,1);

    c1->cd(1);
    double x[2] = {h1->GetXaxis()->GetBinCenter(1),h1->GetXaxis()->GetBinCenter(arsize)};
    double y[2] = {perc,perc};

    TGraph *lineP =  new TGraph(2,x,y); 
    lineP->SetLineColor(kRed);

    TGraphErrors *efC = new TGraphErrors(arsize ,cutV,eff,cutV_err,eff_err);
    efC->SetMarkerStyle(20);
    efC->SetMarkerSize(0.5);
    
    //   efC->Draw("AP");
    efC->GetXaxis()->SetTitle("Cut Value");
    efC->GetYaxis()->SetTitle("Efficiency");

    TMultiGraph *GRPhs = new TMultiGraph(); 
    GRPhs->Add(lineP,"l");
    GRPhs->Add(efC,"p");

    GRPhs->Draw("APL");

    c1->cd(2);

    h1->Draw();

    //  c1->SaveAs(graphname);
   
    double * err_up; 
    double * err_down; 
    err_up = new double [arsize];
    err_down = new double [arsize];
        
    for(int i = 0;  i < arsize ; i++){
      err_up[i] = eff[i] + eff_err[i];
      err_down[i] = eff[i] - eff_err[i];
    }
    
    int xc = 0; 
    for(int i = 0; i < arsize; i++){
      if( eff[i] > perc ){ 
	xc = i; 
	break;
      }
    }
    
    X_val = cutV[xc];
    
    //Here we now extrapolate. 
    
    int up = -99;
    int down = -99;
    for( int i  = 0; i < arsize ; i++){
      if( err_up [i] > perc){ up = i;
        break;
      }
    }
    for( int i  = 0; i < arsize ; i++){
      if( err_down [i] > perc){
        down = i;
        break;
      }
    }
    

    double Usl   = 0;
    double Ustom = 0;
    double err_1 = 0;
    double Dsl   = 0;
    double Dstom = 0;
    double err_2 = 0;
    if(up != -99  ){
      if(err_up[up] > 0.0 && err_up[up-1] > 0.0 && (cutV[up] - cutV[up-1]) > 0.0){
	double Usl   = (err_up[up] - err_up[up-1])/(cutV[up] - cutV[up-1]);
	if(fabs(Usl) > 0.0){ 
	double Ustom = err_up[up] - Usl*cutV[up];
	err_1 = (perc - Ustom)/Usl;
	}
      }
    }    
    
    if(down != -99){
      if(err_up[down] > 0.0 && err_down[down-1] > 0.0 && (cutV[down] - cutV[down-1]) > 0.0){
	
	double Dsl   = (err_down[down] - err_down[down-1])/(cutV[down] - cutV[down-1]);
	if( Dsl > 0.0){
	  double Dstom = err_down[down] - Dsl*cutV[down];
	  err_2 = (perc - Dstom)/Dsl;
	}
      }
    }
      
    


    



    //checking case that the lines do not cross ! 

    if(up == -99){
      errXL = 0 ; //X_val - 0;


  //   errXL = X_val - h1->GetXaxis()->GetBinCenter(1);
    }else{
      errXL = X_val - err_1;
    }

    if(down == -99){
      
      // errXL = ( h1->GetXaxis()->GetBinCenter(arsize) - X_val );
      int dif = 0; 
      for(int i = 0; i < arsize; i++){
	if(eff[i] >  0.98){
	  dif = i; 
	  break; 
	}
      }
      // errXH = (cutV[dif] - X_val );
      errXH = 200 - X_val;


    }else{
       errXH = err_2 - X_val;
    }


    


    //Deleting all the dynamical arrays

    
    delete[] eff;
    delete[] cutV;

    delete[] eff_err;
    delete[] cutV_err;

    delete[] err_up; 
    delete[] err_down; 
    
    // endd:
    // if(h1->GetEntries() == 0)  cout<<"Empty histo"<<endl;

}
