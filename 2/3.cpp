#include <iostream>
using namespace std;

void sort(int *A, int n) {
	for (int i=0; i<n; i++) {
		int min = i;
		for (int j=i+1; j<n; j++) {
			if (A[min] > A[j]) {
				min = j;
			}
		}

		int t = A[i];
		A[i] = A[min];
		A[min] = t;
	}
}

int main() {
	int n;
	cout << "Unesi dimenziju niza:";
	cin >> n;

	int *A = new int[n];
	cout << "Unesi elemente niza:";
	for (int i=0; i<n; i++) {
		cin >> A[i];
	}

	sort(A, n);

	for (int i=0; i<n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	delete [] A;
}
