#include "lib.hpp"
using namespace std;

int main ()
{
  //lettura dei dati
  vector<Entry> data = init ("dataset.txt");

  //funzione steepest descent
  double b0 = 0, w0x = 1, w0y = 1, b1 = 0, w1x = 1, w1y = 1;
  vector<neuron> NN;
  NN.push_back(neuron (w0x, w0y, b0, &sigmoid, 0));
  NN.push_back(neuron (w1x, w1y, b1, &sigmoid, 1));
  double t = .001; 
  double err = 0, oldErr = 1000;
  
  for (int j = 0; j < 100000; j++)
  {
    for(int i = 0; i < data.size(); i++) //ciclo che scorre tutti i punti
    {
      ChangeParameters (NN, data[i], t);
      err += error (NN, data[i]) / data.size();
    }
    //cout << "err_medio = " << err << endl;

    if (oldErr < err)
      t /= 2;
    
    oldErr = err;
    err = 0;
  }

  cout << "b0 = " << NN[0].get_b() << endl;
  cout << "W0x = " << NN[0].get_Wx() << endl;
  cout << "W0y = " << NN[0].get_Wy() << endl;
  cout << "b1 = " << NN[1].get_b() << endl;
  cout << "W1x = " << NN[1].get_Wx() << endl;
  cout << "W1y = " << NN[1].get_Wy() << endl;

  return 0;
}
