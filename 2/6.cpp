#include <iostream>
using namespace std;

int main() {
	char in;
	bool first_white = true;
	bool first_in_line = true;
	while (true) {
		in = cin.get();
		if (cin.eof()) {
			break;
		}

		if (in==' ' || in=='\t') {
			if (first_white && !first_in_line) {
				cout << ' ';
				first_white = false;
			}
		} else {
			if (in=='\n') {
				first_in_line = true;
			} else if (first_in_line) {
				first_in_line = false;
			}
			cout << in;
			first_white = true;
		}
	}
}
