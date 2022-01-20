#include "neuron.hpp"
class Entry
{
  double x;
  double y;
  int Y0;
  int Y1;

public:
  Entry () 
    {x = 0; y = 0; Y0 = -1; Y1 = -1;}
  Entry (double x_, double y_, int Y0_, int Y1_) 
    {x = x_; y = y_; Y0 = Y0_; Y1 = Y1_;}

  double get_x () { return x; }
  double get_y () { return y; }
  int get_Y0 () { return Y0; }
  int get_Y1 () { return Y1; }
};

void ChangeParameters (neuron &N, double Y, Entry data, double t)
{
  //non passare più Y ma guardare type
  double dEdb = t * 2 * (N.output(data.get_x(), data.get_y()) - static_cast<double>(Y)) * dsigmoid (N.get_b() + N.get_Wx() * data.get_x() + N.get_Wy() * data.get_y());
  double bnew = N.get_b() - dEdb;
  double Wxnew = N.get_Wx() - data.get_x() * dEdb;
  double Wynew = N.get_Wy() - data.get_y() * dEdb;
  
  N = neuron (Wxnew, Wynew, bnew, &sigmoid);
}

double error (neuron N0,  Entry data)
{
  return pow (N0.output (data.get_x(), data.get_y()) - static_cast<double>(data.get_Y0()), 2)/* + pow (N1.output (data.get_x(), data.get_y()) - static_cast<double>(data.get_Y1()), 2)*/;
}

vector<Entry> init (const char* filename)
{
  vector<Entry> data;
  double x, y;
  int c;

  ifstream fin(filename);
  while (!fin.eof())
  {
    fin >> x; 
    fin >> y; 
    fin >> c;

    data.push_back(Entry (x, y, c == 0 ? 1 : 0, c == 0 ? 0 : 1));
  }
  fin.close();

  return data;
}
