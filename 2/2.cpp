#include <iostream>
using namespace std;

int const MAX_LEN = 100;

int main() {
	int n;
	int A[MAX_LEN];

	cin >> n;
	if (n<=0 || n>MAX_LEN) {
		cout << "Ne odgovarajuca dimenzija niza!" << endl;
	} else  {
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}

		int s = 0;
		for (int i=0; i<n; i++) {
			s += A[i];
		}

		cout << "Zbir elemenata je: " << s << endl;
	}
}
