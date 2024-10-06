#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int partition(int *A, int p, int q) {
	//pivot je q
	//[p,i) <
	//[i,j) >=
	//<<<<>>>>????????????q
	//<<<<<<<<<<<<q>>>>>>>>
	//            i   j
	//ako > -> j++
	//ako < swap(i,j), i++, j++
	//while j<q
	//swap(i, q)
	//return i
	int i=p, j=p;
	while (j<q) {
		if (A[j]>=A[q]) {
			j ++;
		} else {
			swap(A[i], A[j]);
			i ++;
			j ++;
		}
	}

	swap(A[i], A[q]);
	return i;
}

//[p,q]
void quick_sort(int *A, int p, int q) {
	if (p>=q) {
		return;
	}

	int i = partition(A, p, q);

	//<<<<<<<<i>>>>>>
	//[p,i-1] [i+1, q]
	quick_sort(A, p, i-1);
	quick_sort(A, i+1, q);
}

int main() {
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i=0; i<n; i++) {
		A[i] = rand() % MAX;
	}

	quick_sort(A, 0, n-1);

	for (int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;
}
