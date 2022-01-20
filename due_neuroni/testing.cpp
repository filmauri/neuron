#include <iostream>
#include <fstream>
#include "lib.hpp"
using namespace std;

int main ()
{
  vector<Entry> data = init ("test.txt");

  double b0 = -0.0462517, Wx0 = 10.778, Wy0 = -22.6447, b1 = 0.0464245, Wx1 = -10.7872, Wy1 = 22.663;

  neuron N0(Wx0, Wy0, b0, &sigmoid, 0);
  neuron N1(Wx1, Wy1, b1, &sigmoid, 1);

  ofstream fout ("result.txt");
  int count = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if ((data[i].get_Y()[0] == 1 && N0.output(data[i].get_x(), data[i].get_y()) > N1.output(data[i].get_x(), data[i].get_y())) || (data[i].get_Y()[0] == 0 && N0.output(data[i].get_x(), data[i].get_y()) < N1.output(data[i].get_x(), data[i].get_y())))
      count++;
    fout << data[i].get_Y()[0] << " " << data[i].get_Y()[1] << (N0.output(data[i].get_x(), data[i].get_y()) < N1.output(data[i].get_x(), data[i].get_y()) ? " 0 1" : " 1 0") << endl;
  }

  cout << "efficienza: " << static_cast<double>(count) / static_cast<double>(data.size()) * 100. << "% " << endl;

  return 0;
}