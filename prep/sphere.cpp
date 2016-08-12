#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.141592654;
const int nSample = 5000;
double irand(int min, int max);
int writeData(const vector<double>&x, const vector<double>&y, const vector<double>&z);

int main()
{
	srand( (unsigned)time( NULL ) );

	vector<double> x(nSample), y(nSample), z(nSample);

	double theta = 0, phi = 0;
	for(int i = 0; i < nSample; i++) {
		theta = 2*PI*irand(0,1);
		// corrrect
		phi = acos(2*irand(0,1)-1.0);
		// incorrect
		//phi = PI*irand(0,1);
		x[i] = cos(theta)*sin(phi);
		y[i] = sin(theta)*sin(phi);
		z[i] = cos(phi);
	}

	writeData(x, y, z);

	return 0;
}

// generate random number for the range (min, max)
double irand(int min, int max)
{
    return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min) + min;
}

// write Cartesian coordinates (xyz)
int writeData(const vector<double>&x, const vector<double>&y, const vector<double>&z)
{
	ofstream ofs("sample.csv");

	if( ! ofs )	{
		cout << "Error opening file for output" << endl ;
		return -1 ;
	}

	for(int i = 0; i < nSample; i++) {
		ofs << x[i] << ',' << y[i]<< ',' << z[i]<< endl ;
	}

	ofs.close() ;
	return 0;
}
