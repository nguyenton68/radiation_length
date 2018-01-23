/* Jan 2018
 * Nguyen Ton
 * Purpose: calculate radiation length for 1st period
 * Input:
 * - Ice thickness
 * Output:
 * - Incoming and outgoing radiation length input to simulation 
 */
#include <iomanip.h>
#include <cmath>
void radlen()
{
  double x_he=94.32;
  double x_c=36.34;
  double x_be=65.19;
  double x_foam=43.79;
  double x_ice=36.1;
  double x_kapton=40.58;
  double x_glass = 26.8379;
  double x_he3 = 71.0736;
  double x_n2 = 37.9879;

  double rho_he=1.7*1e-4;
  double rho_c=1.933;
  double rho_be=1.848;
  double rho_foam=0.03186;
  double rho_ice=0.934;
  double rho_kapton=1.42;
  double rho_glass = 2.530;
  double rho_he3 = 0.937*1e-3;
  double rho_n2 = 0.8748*1e-4;

  double t_be=0.0127;
  double t_foam=2*1.5;
  double t_kapton=0.0254;
  double t_c=0.0254/2;
  double t_ice=1.0;//cm
  double t_he3_in = 19.25;
  double t_he3_out = 15.04;
  double t_he4_in = 24.65;
  double t_he4_out = 185.36;
  double t_n2_in =t_he3_in;
  double t_n2_out = t_he3_out;
  double t_glass_in = 0.0127;
  double t_glass_out = 0.0234;

  double t_he_in[3]={33.9,43.9,53.9};//up,center,down
  double t_c_in[3]={0.0254/2.,0.0254*3/2.,0.0254*5/2};
  double t_he_out[3]={210.4,200.4,190.4};
  cout<<"Multifoil"<<endl;
  for(int ii=0;ii<3;ii++){
    double inl=rho_be*t_be/x_be
      +rho_c*t_c_in[ii]/x_c
      +rho_he*t_he_in[ii]/x_he;
    
    double ave_i=rho_he*t_he_in[ii]+rho_c*t_c_in[ii]+rho_be*t_be;
    double outl=rho_he*t_he_out[ii]/x_he
      +rho_c*t_c/x_c
      +rho_foam*t_foam/x_foam
      +rho_kapton*t_kapton/x_kapton
      +rho_ice*t_ice/x_ice;
    double ave_o =rho_he*t_he_out[ii]+rho_c*t_c+rho_foam*t_foam+rho_kapton*t_kapton+rho_ice*t_ice;
    cout<<inl<<"\t"<<outl<<"\t"<<ave_i<<"\t"<<ave_o<<endl;
  }

  cout<<"Single foil"<<endl;
  for(int ii=0;ii<3;ii++){
    double inl=rho_be*t_be/x_be
      +rho_c*t_c/x_c
      +rho_he*t_he_in[ii]/x_he;
    
    double ave_i=rho_he*t_he_in[ii]+rho_c*t_c+rho_be*t_be;
    double outl=rho_he*t_he_out[ii]/x_he
      +rho_c*t_c/x_c
      +rho_foam*t_foam/x_foam
      +rho_kapton*t_kapton/x_kapton
      +rho_ice*t_ice/x_ice;
    double ave_o =rho_he*t_he_out[ii]+rho_c*t_c+rho_foam*t_foam+rho_kapton*t_kapton+rho_ice*t_ice;
    cout<<inl<<"\t"<<outl<<"\t"<<ave_i<<"\t"<<ave_o<<endl;
  }
  cout<<"*************************************************"<<endl;
  cout<<"*******************He3 target********************"<<endl;
  double he3_inl = rho_glass*t_glass_in/x_glass + rho_he3*t_he3_in/x_he3
    + rho_be*t_be/x_be + rho_n2*t_n2_in/x_n2
    + rho_he*t_he4_in/x_he;
  double he3_ave_in = rho_glass*t_glass_in + rho_he3*t_he3_in
    + rho_be*t_be + rho_n2*t_n2_in
    + rho_he*t_he4_in;
  double he3_outl = rho_glass*t_glass_out/x_glass + rho_foam*t_foam/x_foam
    + rho_kapton*t_kapton/x_kapton + rho_he*t_he4_out/x_he
    + rho_he3*t_he3_out/x_he3 + rho_n2*t_n2_out/x_n2 + rho_ice*t_ice/x_ice;
  double he3_ave_out = rho_glass*t_glass_out + rho_foam*t_foam
    + rho_kapton*t_kapton + rho_he*t_he4_out
    + rho_he3*t_he3_out + rho_n2*t_n2_out + rho_ice*t_ice;
  cout<<he3_inl<<"\t"<<he3_outl<<"\t"<<he3_ave_in<<"\t"<<he3_ave_out<<endl;

  cout<<"Kinematic calculation below "<<endl;
  double sin_sqr = sin(6*3.1415/(180.*2.0))**2;
  double Ebeam = 1.5;
  double Epr=Ebeam/(1+(2*Ebeam*sin_sqr)/11.178);
  double q2 = 4*Ebeam*Epr*sin_sqr;
  cout<<"Q2= "<<q2<<endl;
}
