#include <iostream>
#include <fstream>
#include "lib.hpp"
using namespace std;

int main ()
{
  vector<Entry> data = init ("test.txt");

  double b = -0.0462517, Wx = 10.778, Wy = -22.6447;

  neuron N(Wx, Wy, b, &sigmoid);
  
  ofstream fout ("result.txt");
  int count = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if ((data[i].get_Y0() == 1 && N.output(data[i].get_x(), data[i].get_y()) > 0.5 ) || (data[i].get_Y0() == 0 && N.output(data[i].get_x(), data[i].get_y()) < 0.5))
      count++;
    
    fout << data[i].get_Y0() << " " << data[i].get_Y1() << (N.output(data[i].get_x(), data[i].get_y()) > 0.5 ? " 0 1" : " 1 0") << endl;
  }

  cout << "efficienza: " << static_cast<double>(count) / static_cast<double>(data.size()) * 100. << "% " << endl;

  return 0;
}
