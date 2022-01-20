#include "neuron.hpp"

class Entry
{
  double x;
  double y;
  vector<int> Y;

public:
  Entry () 
    {x = 0; y = 0;}
  Entry (double x_, double y_, vector<int> Y_) 
    {x = x_; y = y_; Y = Y_;}

  double get_x () { return x; }
  double get_y () { return y; }
  vector<int> get_Y () { return Y; }
};

void ChangeParameters (vector<neuron> &N, Entry data, double t)
{
  for (int i = 0; i < N.size(); i++)
  {
    double dEdb = t * 2 * (N[i].output(data.get_x(), data.get_y()) - static_cast<double>(data.get_Y()[N[i].get_type()])) * dsigmoid (N[i].get_b() + N[i].get_Wx() * data.get_x() + N[i].get_Wy() * data.get_y());
    double bnew = N[i].get_b() - dEdb;
    double Wxnew = N[i].get_Wx() - data.get_x() * dEdb;
    double Wynew = N[i].get_Wy() - data.get_y() * dEdb;
    
    neuron newN (Wxnew, Wynew, bnew, &sigmoid, N[i].get_type());
    N[i] = newN;
  }
}

double error (vector<neuron> NN, Entry data)
{
  double out = 0;
  for (int i = 0; i < NN.size(); i++)
  {
    out += pow (NN[i].output (data.get_x(), data.get_y()) - static_cast<double>(data.get_Y()[NN[i].get_type()]), 2);
  }
  return out;
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

    vector<int> a;
    for (int i = 0; i < 2; i++)
      a.push_back(c == i ? 1 : 0);
    
    data.push_back(Entry (x, y, a));
  }
  fin.close();

  return data;
}
