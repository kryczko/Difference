#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
string infile;
int number;
double lattice;
//main menu
cout << "Please enter the datafile: ";
cin >> infile;
cout << "How many atoms: ";
cin >> number;
cout << "Please enter the lattice constants in the x, y and z direction respectively separated by a space: ";
cin >> lattice;

ifstream datafile;
ofstream difference;

difference.open("difference.xyz");

difference << number*3 << "\n\n";

datafile.open(infile.c_str());

int i = 0;
double distance, distancex1, distancex2, distancey1, distancey2, distancez1, distancez2, x[number], y[number], z[number];
char atoms[number];
//read the xyz file
while (!datafile.eof())
{
  datafile >> atoms[i] >> x[i] >> y[i] >> z[i];
  i ++;
} 
//loop to find the distance between atoms
for (int i = 0; i < number; i ++)
{
  for (int j = -1; j < 2; j ++)
  { 
    if (j != 0 )
    {
   // difference << atoms[i] << "\t" << j*lattice + x[i] << "\t" << y[i] << "\t" << z[i] << endl;
    difference << atoms[i] << "\t" << x[i] << "\t" << j*lattice + y[i] << "\t" << z[i] << endl;
   // difference << atoms[i] << "\t" << x[i] << "\t" << y[i] << "\t" << j*lattice + z[i] << endl;
    }
    if (j == 0 )
    {
      difference << atoms[i] << "\t" << x[i] << "\t" << y[i] << "\t" << z[i] << endl;
    }   
}
} 

/*
  for (int j = 0; j < number; j ++)
  {
    if (i != j)
    {

       distance = sqrt( pow( x[i] - x[j], 2) + pow( y[i] - y[j], 2) + pow( z[i] - z[j], 2));
     
       distancex1 = sqrt( pow( x[i] - (-lattice_x + x[j], 2) + pow( y[i] - y[j], 2) + pow( z[i] - z[j], 2));
       
       distancex2 = sqrt( pow( x[i] - (lattice_x + x[j]), 2) + pow( y[i] - y[j], 2) + pow( z[i] - z[j], 2));
       
       distancey1 = sqrt( pow( x[i] - x[j], 2) + pow( y[i] - (-lattice_y + y[j]), 2) + pow( z[i] - z[j], 2));  
       
       distancey2 = sqrt( pow( x[i] - x[j], 2) + pow( y[i] - (lattice_y + y[j]), 2) + pow( z[i] - z[j], 2));

       distancez1 = sqrt( pow( x[i] - x[j], 2) + pow( y[i] - y[j], 2) + pow( z[i] - (-lattice_z + z[j]), 2));

       distancez2 = sqrt( pow( x[i] - x[j], 2) + pow( y[i] - y[j], 2) + pow( z[i] - (lattice_z + z[j]), 2));       

       difference << distance1 << "\t" << distance2 <<  endl;
    }
  }
}
*/
difference.close();
datafile.close();
return 0;
}	






