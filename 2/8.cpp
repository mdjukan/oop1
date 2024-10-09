#include <cmath>
#include <iostream>
using namespace std;

void polar(double x, double y, double &r, double &fi) {
	r = sqrt(x*x + y*y);
	fi = atan2(y, x);
}

void polar(double x, double y, double *r, double *fi) {
	*r = sqrt(x*x + y*y);
	*fi = atan2(y, x);
}

int main() {
	double x, y;
	cin >> x >> y;

	/*
	double r, fi;
	polar(x, y, r, fi);
	cout << r << fi << endl;
	*/

	double r, fi;
	polar(x, y, &r, &fi);
	cout << r << fi << endl;
}
