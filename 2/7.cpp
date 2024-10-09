#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME_LEN = 100;
const int MAX_LEN = 30;

bool lex_greater(char *s1, char *s2) {
	int i = 0;
	while (s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i]) {
		i ++;
	}

	if (s1[i]=='\0') {
		return false;
	}

	if (s2[i]=='\0') {
		return true;
	}

	return s1[i]>s2[i];
}

int main() {
	char **arr = new char*[MAX_LEN];
	int k = 0;

	while (true) {
		char *name = new char[MAX_NAME_LEN];

		cin.getline(name, MAX_NAME_LEN);

		if (strlen(name)==0) {
			delete []name;
			break;
		} else {
			char *tmp = new char[strlen(name)+1];
			strcpy(tmp, name);
			delete name;
			name = tmp;
		}

		arr[k] = name;
		k += 1;
	}

	for (int i=1; i<k; i++) {
		int j = i;
		while (j>0 && lex_greater(arr[j-1], arr[j])) {
			char *tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			j --;
		}
	}

	for (int i=0; i<k; i++) {
		cout << arr[i] << endl;
	}

	for (int i=0; i<k; i++) {
		delete arr[i];
	}

	delete []arr;
}
