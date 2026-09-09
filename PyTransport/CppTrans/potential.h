//#This file is part of PyTransport.

//#PyTransport is free software: you can redistribute it and/or modify
//#it under the terms of the GNU General Public License as published by
//#the Free Software Foundation, either version 3 of the License, or
//#(at your option) any later version.

//#PyTransport is distributed in the hope that it will be useful,
//#but WITHOUT ANY WARRANTY; without even the implied warranty of
//#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//#GNU General Public License for more details.

//#You should have received a copy of the GNU General Public License
//#along with PyTransport.  If not, see <http://www.gnu.org/licenses/>.

// This file contains a prototype of the potential.h file of PyTransport -- it is edited by the PyTransScripts module

#ifndef POTENTIAL_H  // Prevents the class being re-defined
#define POTENTIAL_H


#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

// #Rewrite
// Potential file rewriten at Mon Jul 24 09:54:20 2023

class potential
{
private:
	int nF; // field number
	int nP; // params number which definFs potential
    
    
public:
	// flow constructor
	potential()
	{
// #FP
nF=1;
nP=4;

//        p.resize(nP);
        
// pdef

    }
	
    //void setP(vector<double> pin){
    //    p=pin;
    //}
	//calculates V()
	double V(vector<double> f, vector<double> p)
	{
		double sum ;
        
// Pot
  sum=0.5*std::pow(f[0], 2)*std::pow(p[0], 2)*(p[1]*std::tanh((f[0] - p[2])/p[3]) + 1.0);
         return sum;
	}
	
	//calculates V'()
	vector<double> dV(vector<double> f, vector<double> p)
	{
		vector<double> sum(nF,0.0);
	
// dPot
  double x0 = std::pow(p[0], 2);
  double x1 = 1.0/p[3];
  double x2 = std::tanh(x1*(f[0] - p[2]));

 sum[0]=0.5*std::pow(f[0], 2)*p[1]*x0*x1*(1 - std::pow(x2, 2)) + 1.0*f[0]*x0*(p[1]*x2 + 1.0);
        
		return sum;
	}
    
	// calculates V''
	vector<double> dVV(vector<double> f, vector<double> p)
	{
		vector<double> sum(nF*nF,0.0);
		
// ddPot
  double x0 = 1.0/p[3];
  double x1 = std::tanh(x0*(f[0] - p[2]));
  double x2 = p[1]*x1;
  double x3 = std::pow(p[0], 2);
  double x4 = 1.0*x3;
  double x5 = 1 - std::pow(x1, 2);

 sum[0]=-std::pow(f[0], 2)*x2*x4*x5/std::pow(p[3], 2) + 2.0*f[0]*p[1]*x0*x3*x5 + x4*(x2 + 1.0);
     
        return sum;
	}
    
	// calculates V'''
	vector<double> dVVV(vector<double> f, vector<double> p)
	{
        vector<double> sum(nF*nF*nF,0.0);
// dddPot
  double x0 = std::pow(p[0], 2);
  double x1 = 1.0/p[3];
  double x2 = std::tanh(x1*(f[0] - p[2]));
  double x3 = std::pow(x2, 2);
  double x4 = 1 - x3;
  double x5 = p[1]*x0;
  double x6 = std::pow(f[0], 2);
  double x7 = std::pow(p[3], -3);

 sum[0]=-6.0*f[0]*x2*x4*x5/std::pow(p[3], 2) + 3.0*p[1]*x0*x1*x4 + 2.0*p[1]*x0*x3*x4*x6*x7 - 1.0*std::pow(x4, 2)*x5*x6*x7;
       
        return sum;
	}
    
    int getnF()
    {
        return nF;
    }
    
    int getnP()
    {
        return nP;
    }

};
#endif