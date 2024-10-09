#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX_NAME_LEN = 100;
const int MAX_LEN = 30;

int main() {
	string *arr = new string[MAX_LEN];
	int k = 0;

	string s;
	while (true) {
		getline(cin, s);

		if (s=="") {
			break;
		}

		arr[k++] = s;
		//string(string &s) -> njegovu kopiju
	}

	for (int i=1; i<k; i++) {
		int j = i;
		while (j>0 && arr[j-1]>arr[j]) {
			string tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			j --;
		}
	}

	for (int i=0; i<k; i++) {
		cout << arr[i] << endl;
	}

	delete []arr;
}
