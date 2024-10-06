#include <stdio.h>
#define MAX 100

double scalar(double *a, double *b, int i, int n) {
	if (i==n) {
		return 0;
	}

	return a[i]*b[i] + scalar(a, b, i+1, n);
}

int main() {
	int n;
	scanf("%d", &n);

	double a[MAX];
	double b[MAX];

	for (int i=0; i<n; i++) {
		scanf("%lf", &a[i]);
	}

	for (int i=0; i<n; i++) {
		scanf("%lf", &b[i]);
	}

	printf("%lf\n", scalar(a, b, 0, n));
}

