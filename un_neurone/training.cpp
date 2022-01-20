#include "lib.hpp"
using namespace std;

int main ()
{
  //lettura dei dati
  vector<Entry> data = init ("dataset.txt");

  //funzione steepest descent
  double b0 = 0, w0x = 1, w0y = 1;
  neuron N0(w0x, w0y, b0, &sigmoid);
  
  double t = .001; 
  double err = 0, oldErr = 1000;
  
  for (int j = 0; j < 100000; j++)
  {
    for(int i = 0; i < data.size(); i++) //ciclo che scorre tutti i punti
    {
      ChangeParameters (N0, data[i].get_Y0(), data[i], t);
      err += error (N0, data[i]) / data.size(); 

    }
    cout << "err_medio = " << err << endl;
    if (oldErr < err)
      t /= 2;

    oldErr = err;
    err = 0;
  }

  cout << "\nb0 = " << N0.get_b() << endl;
  cout << "W0x = " << N0.get_Wx() << endl; 
  cout << "W0y = " << N0.get_Wy() << endl; 

  return 0;
}