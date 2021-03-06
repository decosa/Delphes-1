#ifndef INLINE_MATHS
#define INLINE_MATHS

// This file is distributed with FastJet under the terms of the GNU
// General Public License (v2). Permission to do so has been granted
// by Lars Sonnenschein and the D0 collaboration (see COPYING for
// details)
//
// History of changes in FastJet compared tothe original version of
// inline_math.h
//
// 2011-12-13  Gregory Soyez  <soyez@fastjet.fr>
// 
//        * added license information
//
// 2011-10-06  Gregory Soyez  <soyez@fastjet.fr>
//
//        * put the code in the fastjet::d0runi namespace

#include <cmath>
#include <cerrno>
#include <fastjet/internal/base.hh>

FASTJET_BEGIN_NAMESPACE

//using namespace std;

namespace d0runi{
namespace inline_maths {

const double PI = fabs(acos(-1.));

const double TWOPI = 2*PI;


inline double sqr(double a) {
  return a*a;
}



inline double min(double a, double b) {
  return (a < b) ? a : b;
}



inline double delta_phi(double phi1, double phi2) {
  double dphi = min( double(fabs(phi1-phi2)), double(2.*PI-fabs(phi1-phi2)) );
  return (phi1 < phi2) ? -dphi : dphi;
}



inline double phi(double px, double py) {
  return atan2(py, px);
}



inline double y(double E, double pz) {
  errno=0;
  double y;
  //cout << "inline_maths: ";
  if (fabs(E-pz) == 0.) {
    //    cout << "Error in header mathe.h: division by 0 in function y!" <<  " p=" << p << " pz=" << pz << endl;
    //  exit(721);
    errno=721;
    y = 99999.;
  }
  else {
    y = 0.5*log((E+pz)/(E-pz));
  }
  //cout << "y: E=" << E << " pz=" << pz << " y=" << y << endl;
  return y;
}




inline double eta(double p, double pz) {
  errno=0;
  double eta;
  //cout << "inline_maths: ";
  if (fabs(p-pz) == 0.) {
    //    cout << "Error in header mathe.h: division by 0 in function eta!" <<  " p=" << p << " pz=" << pz << endl;
    //  exit(721);
    errno=721;
    eta = 99999.;
  }
  else {
    eta = 0.5*log((p+pz)/(p-pz));
  }
  //cout << "eta: p=" << p << " pz=" << pz << " eta=" << eta << endl;
  return eta;
}




 inline double eta(double px, double py, double pz) {
   errno=0;
   double eta;
  //cout << "inline_maths: ";
   double p = sqrt(px*px+py*py+pz*pz);
   if (fabs(p-pz) == 0.) {
    //    cout << "Error in header mathe.h: division by 0 in function eta!" <<  " p=" << p << " pz=" << pz << endl;
    //  exit(721);
    errno=721;
    eta = 99999.;
  }
  else {
    eta = 0.5*log((p+pz)/(p-pz));
  }
  //cout << "eta: p=" << p << " pz=" << pz << " eta=" << eta << endl;
  return eta;
}



 inline double eta(double theta) {
   double eta = -log(tan(theta/2.));
   
   return eta;
 }
 

 inline double theta(double eta) {
   double theta = 2.*atan(exp(-eta));
   
   return theta;
 }
 
 inline double theta(double px, double py, double pz) {
   double Eta = eta(px, py, pz);
   double theta = 2.*atan(exp(-Eta));
   
   return theta;
 }
 


} //end usename inline_maths
} //end usename d0runi

FASTJET_END_NAMESPACE


#endif
