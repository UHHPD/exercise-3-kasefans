#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

int main() {
    using namespace std;

    //Create vector with eleven entries.
    vector<int> zaehler(11);

    ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;

        //Add one to the counter for this value of n.
        zaehler[n_i] += 1;        
    }
    fin.close();

    //Print out of countings.
    for(unsigned int k = 0 ; k < zaehler.size() ; ++k) {
        cout << k << ":" << zaehler[k] << endl;

    //Write in file.
    ofstream fout("hist.txt");
    for(unsigned int k = 0 ; k < zaehler.size() ; ++k) {
        fout << k << " " << zaehler[k] << endl;}
    }
}