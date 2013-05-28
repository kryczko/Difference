#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
string infile;
double unit;
int timestep;

cout << "Please enter the datafile: ";
cin >> infile;

ifstream datafile;
ofstream difference;

difference.open("difference.dat");


datafile.open(infile.c_str());

int i = 0;
double x[192], y[192], z[192], sum1(0), sum2(0), H1, H2;
char atom;
while (!datafile.eof())
{
  datafile >> atom >> x[i] >> y[i] >> z[i];
  i ++;
} 
for (int j = 0; j < 64; j ++)
{ 
  H1 = sqrt(pow(x[3*j]-x[3*j+2], 2) + pow(y[3*j]-y[3*j+2], 2) + pow(z[3*j]-z[3*j+2], 2));
  H2 = sqrt(pow(x[3*j+1]-x[3*j+2], 2) + pow(y[3*j+1]-y[3*j+2], 2) + pow(z[3*j+1]-z[3*j+2], 2));

  difference << H1 << "\t" << H2 << endl;
  sum1 += H1;
  sum2 += H2;
}

difference.close();
datafile.close();
return 0;
}	






