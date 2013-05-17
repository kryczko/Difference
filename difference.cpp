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
cout << "What is value of the unit cell: ";
cin >> unit;
cout << "How many timesteps: ";
cin >> timestep;
ifstream datafile;
ofstream difference;

difference.open("difference.dat");


datafile.open(infile.c_str());

int i = 0;

double x_data[3*timestep], y_data[3*timestep], z_data[3*timestep];
double H1_x[timestep], H2_x[timestep], H1_y[timestep], H2_y[timestep], H1_z[timestep], H2_z[timestep], H1[timestep], H2[timestep];

while (!datafile.eof())
{
  datafile >> x_data[i] >> y_data[i] >> z_data[i];
  
  i ++;
}
for (int n = 0; n <= timestep - 1; n ++)
{  
  H1_x[n] = x_data[3*n + 1] - x_data[3*n];
  H2_x[n] = x_data[3*n + 2] - x_data[3*n];
  H1_y[n] = y_data[3*n + 1] - y_data[3*n];
  H2_y[n] = y_data[3*n + 2] - y_data[3*n];
  H1_z[n] = z_data[3*n + 1] - z_data[3*n];
  H2_z[n] = z_data[3*n + 2] - z_data[3*n];
  
  H1[n] =unit* sqrt( H1_x[n]*H1_x[n] + H1_y[n]*H1_y[n] + H1_z[n]*H1_z[n]);
  H2[n] =unit* sqrt( H2_x[n]*H2_x[n] + H2_y[n]*H2_y[n] + H2_z[n]*H2_z[n]);
  
  difference << H1[n] << "\t" << H2[n] << endl;   	  

}



difference.close();
datafile.close();
return 0;
}	






