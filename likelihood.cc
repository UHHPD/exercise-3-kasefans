#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k) * exp(-mu) / tgamma(k + 1);
}

double prob(std::vector<int> daten, double mu) {
  double likelihood = 1;
  for (int k : daten){
    likelihood *= poisson(mu, k);
  }
  return likelihood;
}

double lambda(std::vector<int> daten, double mu){
  double ratio = 1;
  for (int k : daten){
    ratio *= poisson(mu, k) / poisson(k, k);
    }
  return ratio;
}
int main() {
  using namespace std;

  // Create vector of data.
  vector<int> daten;

  ifstream fin("datensumme.txt");
  int zahl;
  for (int i = 0; i < 234; ++i) {
    fin >> zahl;
    daten.push_back(zahl);
  }
  fin.close();

  // Print out prob for mu = 3.11538
  cout << "Likelihood for mu = 3.11538: " << prob(daten, 3.11538) << endl;

  // Write in file.
  ofstream fout("likelihood.txt");
  for (double mu = 0; mu <= 6; mu += 0.1){
    fout << mu << " " << prob(daten, mu) << endl;
  }
  fout.close();

  //Write file.
  ofstream f2out("nll.txt");
  for (double mu = 0; mu <= 6; mu += 0.1){
    f2out << mu << " " << -2*log(prob(daten, mu)) << endl;
  }
  f2out.close();

  //Write file.
  ofstream f3out("deltanll.txt");
  for (double mu = 0; mu <= 6; mu += 0.1){
    f3out << mu << " " << -2*log(prob(daten, mu)) + 2*log(prob(daten, 3.11538)) << endl;
  }
  f3out.close();

  //Compute likelihood ratio.
  cout << "-2*log(Likelihood ratio): " << -2*log(lambda(daten, 3.11538)) << endl;
  cout << "relative deviation: " << (-2*log(lambda(daten, 3.11538)) - 233) / sqrt(2*233) << endl;
  
  //TODO: Excersice b), c), d) create hist and answer questions b) - d)
}