// rotatation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

vector<double> rotate(const vector<double> v, const vector<double> n, double theta)
{


	double cos_theta = cos(theta);
	double sin_theta = sin(theta);

	vector<double> cross = { n[1] * v[2] - n[2] * v[1],n[2] * v[0] - n[0] * v[2],n[0] * v[1] - n[1] * v[0] };
	double dot = v[0] * n[0] + v[1] * n[1] + v[2] * n[2];

	vector<double> term1 = { v[0] * cos_theta,v[1] * cos_theta, v[2] * cos_theta };
	vector<double> term2 = { cross[0] * sin_theta, cross[1] * sin_theta, cross[2] * sin_theta };
	vector<double> term3 = { n[0] * dot * (1 - cos_theta), n[1] * dot * (1 - cos_theta), n[2] * dot * (1 - cos_theta) };

	vector<double> rotated = { term1[0] + term2[0] + term3[0],term1[1] + term2[1] + term3[1], term1[2] + term2[2] + term3[2] };


	return rotated;
}
int main()
{	
	vector<double> v = { 1,0,0 };
	vector<double> n = { 0,1,0 };
	vector<double> rotated = rotate(v, n, 3.14159/6);
	cout << rotated[0] << " " << rotated[1] << " " << rotated[2] << endl;
	int a;
	cin >> a;
    return 0;
}

