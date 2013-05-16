#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
ifstream datafile;
ofstream difference;

difference.open("difference.dat");


datafile.open("coordinates");

int i = 0;

double x_data[600], y_data[600], z_data[600];
double H1_x[200], H2_x[200], H1_y[200], H2_y[200], H1_z[200], H2_z[200], H1[200], H2[200];

while (!datafile.eof())
{
  datafile >> x_data[i] >> y_data[i] >> z_data[i];
  
  i ++;
}
for (int n = 0; n <= 199; n ++)
{  
  H1_x[n] = x_data[3*n + 1] - x_data[3*n];
  H2_x[n] = x_data[3*n + 2] - x_data[3*n];
  H1_y[n] = y_data[3*n + 1] - y_data[3*n];
  H2_y[n] = y_data[3*n + 2] - y_data[3*n];
  H1_z[n] = z_data[3*n + 1] - z_data[3*n];
  H2_z[n] = z_data[3*n + 2] - z_data[3*n];
  
  H1[n] =8* sqrt( H1_x[n]*H1_x[n] + H1_y[n]*H1_y[n] + H1_z[n]*H1_z[n]);
  H2[n] =8* sqrt( H2_x[n]*H2_x[n] + H2_y[n]*H2_y[n] + H2_z[n]*H2_z[n]);
  
  difference << H1[n] << "\t" << H2[n] << endl;   	  

}



difference.close();
datafile.close();
return 0;
}	






