#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

double r (double x)
{
    return x / 2;
}

int main ()
{
    srand (time (NULL));
    vector<double> X, Y;
    vector<double> C;

    ofstream fout ("dati.txt");
    for (int i = 0; i < 200; i++)
    {
        X.push_back((double)rand() / RAND_MAX);
        Y.push_back((double)rand() / RAND_MAX);
        if (Y[i] < r(X[i]))
            C.push_back(0);
        else
            C.push_back(1);

        fout << X[i] << " " << Y[i] << " " << C[i] << endl;
    }

    ofstream graph;
    graph.open ("graph.plt");
    graph << "set palette model RGB defined ( 0 'blue', 1 'orange' )" <<endl;
    graph << "set title 'Classificatore binario' " <<endl;
	graph << "plot x / 2, 'dati.txt' u 1:2:( $3 == 0 ? 0 : 1 ) w points palette"  <<endl; 
	system("gnuplot graph.plt -plot");

    
    return 0;

}