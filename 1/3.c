#include <stdio.h>
#include <stdlib.h>

struct Set {
	int n;
	int *data;
};
typedef struct Set Set;

Set create_set(int n) {
	Set s;
	s.n = n;
	s.data = (int*)malloc(n * sizeof(int));
	return s;
}

Set intersection(Set s1, Set s2) {
	int max_size = s1.n < s2.n ? s1.n : s2.n;
	Set r = create_set(max_size);

	int k = 0;
	for (int i=0; i<s1.n; i++) {
		for (int j=0; j<s2.n; j++) {
			if (s1.data[i]==s2.data[j]) {
				r.data[k] = s1.data[i];
				k += 1;
				break;
			}
		}
	}

	r.n = k;
	return r;
}

int main() {
	int n1;
	scanf("%d", &n1);
	Set s1 = create_set(n1);
	for (int i=0; i<n1; i++) {
		scanf("%d", &(s1.data[i]));
	}

	int n2;
	scanf("%d", &n2);
	Set s2 = create_set(n2);
	for (int i=0; i<n2; i++) {
		scanf("%d", &(s2.data[i]));
	}

	Set r = intersection(s1, s2);

	for (int i=0; i<r.n; i++) {
		printf("%d ", r.data[i]);
	}
	printf("\n");
}
