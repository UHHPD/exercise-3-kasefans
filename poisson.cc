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

    //Close output file.
    fout.close();

    //function that computes poisson probability.
    double poisson(double mu, int k) {
        double pow(double mu, double k) * double exp(- double mu) / double tgamma(double k + 1);
    }

    //Write in file.
    ofstream f2out("histpoi.txt");
    
    for(unsigned int k = 0 ; k < zaehler.size() ; ++k) {
        f2out << k << " " << zaehler[k] << zaehler[k]*poisson(k, 3.11538) << endl;
    }
    //Close output file.
    f2out.close();
    }
}