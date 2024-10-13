#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

const int INIT_CAP = 1;
const int CAP_FACT = 2;

class Set {
	int size, cap, *data;
public:
	Set() {
		size = 0;
		cap = INIT_CAP;
		data = new int[cap];
	}

	~Set() {
		delete []data;
	}

	Set(const Set &s) {
		size = s.size;
		cap = s.cap;
		data = new int[cap];
		for (int i=0; i<size; i++) {
			data[i] = s.data[i];
		}
	}

	void increse_cap() {
		cout << "increse_cap" << endl;
		cap *= CAP_FACT;
		int *old_data = data;
		data = new int[cap];
		for (int i=0; i<size; i++) {
			data[i] = old_data[i];
		}
		delete old_data;
	}

	void add(int x) {
		if (size==0) {
			data[0] = x;
		} else {
			if (size==cap) {
				increse_cap();
			}

			for (int i=0; i<size; i++) {
				if (x==data[i]) {
					return;
				}
			}

			int i = size;
			data[i] = x;
			while (i>0 && data[i-1]>data[i]) {
				swap(data[i-1], data[i]);
				i -= 1;
			}
		}
		size += 1;
	}

	bool contains(int x) const {
		for (int i=0; i<size; i++) {
			if (data[i]==x) {
				return true;
			}
		}

		return false;
       	}

	friend Set set_union(const Set &s1, const Set &s2);
	friend Set set_inter(const Set &s1, const Set &s2);
	friend Set set_diff(const Set &s1, const Set &s2);
	friend ostream& operator<<(ostream &out, const Set &s);
};

ostream& operator<<(ostream &out, const Set &s) {
	if (s.size==0) {
		out << "set is empty";
	} else {
		out << "{" << s.data[0];
		for (int i=1; i<s.size; i++) {
			out << ", " << s.data[i];
		}
		out << "}";
	}

	return out;
}

Set set_union(const Set &s1, const Set &s2) {
	Set r = s1;
	for (int i=0; i<s2.size; i++) {
		r.add(s2.data[i]);
	}

	return r;
}

Set set_inter(const Set &s1, const Set &s2) {
	Set r;
	for (int i=0; i<s1.size; i++) {
		if (s2.contains(s1.data[i])) {
			r.add(s1.data[i]);
		}
	}

	return r;
}

Set set_diff(const Set &s1, const Set &s2) {
	Set r;
	for (int i=0; i<s1.size; i++) {
		if (!s2.contains(s1.data[i])) {
			r.add(s1.data[i]);
		}
	}

	return r;
}

int main() {
	Set s1;
	s1.add(1);
	s1.add(2); 
	s1.add(3);	

	Set s2;
	s2.add(2);
	s2.add(3);
	s2.add(4);

	cout << set_union(s1, s2) << endl;
	cout << set_inter(s1, s2) << endl;
	cout << set_diff(s1, s2) << endl;
}
