#include <stdlib.h>
#include <stdio.h>
#define MAX 128

void redukcija(int niz[], const unsigned char maska[], int *n) {
	int *h = (int*)malloc(*n * sizeof(int));
	int k = 0;

	for (int i=0; i<*n; i++) {
		char m = maska[i/8];
		if((m>>(7-i%8))&1) {
			h[k] = niz[i];
			k++;
		}
	}

	for (int i=0; i<k; i++) {
		niz[i] = h[i];
	}

	*n = k;
	free(h);
}

int main() {
	int niz[MAX];
	int n;
	printf("Unesi broj elementa:\n");
	scanf("%d", &n);
	printf("Unesi elemente:\n");
	for (int i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}

	unsigned char maska[MAX/8];
	int n_maska = n%8==0 ? n/8 : n/8+1;
	printf("Unesi masku:\n");
	for (int i=0; i<n_maska; i++) {
		scanf("%hhx", &maska[i]);
	}

	redukcija(niz, maska, &n);

	for (int i=0; i<n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}
