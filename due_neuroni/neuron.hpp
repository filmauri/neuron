#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

double sigmoid (double x)
  { return 1. / (1. + pow(M_E, -x));}

double dsigmoid (double x)
  { return pow(M_E, -x) / pow((1. + pow(M_E, -x)), 2) ;}

class neuron
{
  double Wx, Wy; 
  double b; 
  double (*f) (double); //funzione di attivazione
  int type; //dice se è un neurone di tipo 0 o 1

public:
  neuron () 
    { Wx = 0; Wy = 0; b = 0; f = 0; type = -1;}
  neuron (double Wx_, double Wy_, double b_, double (*f_) (double), int type_)
    { Wx = Wx_; Wy = Wy_, b = b_; f = f_; type = type_; }
    
  double get_Wx () {return Wx;}
  double get_Wy () {return Wy;}
  double get_b () {return b;}
  int get_type () {return type;}
  
  double output (double x, double y) { return f (b + Wx * x + Wy * y); }
};