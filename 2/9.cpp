#include <iostream>
#include <cmath>
using namespace std;

double P(double a, double b, double c) {
	if (a>0 && b>0 && c>0 && a<b+c && b<a+c && c<a+b) {
		double s = (a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	} else {
		return -1;
	}
}

double P(double a) {
	return P(a, a, a);
}

double P(double a, double b) {
	return P(a, b, b);
}

int main() {
	int k;
	cin >> k;

	double a, b, c;
	switch (k) {
		case 1:
			cin >> a >> b >> c;
			cout << P(a, b, c) << endl;
			break;
		case 2:
			cin >> a >> b;
			cout << P(a, b) << endl;
			break;
		case 3:
			cin >> a;
			cout << P(a) << endl;
	}
}
