#ifndef RECT_ARR_H
#define RECT_ARR_H
#include "rect.h"

namespace Geometry {
	struct RectArr {
		int n;
		Rect *arr;
	};

	typedef struct RectArr RectArr;

	void create(RectArr &a) {
		a.n = 0;
		a.arr = nullptr;
	}

	void read(RectArr &a) {
		int n;
		cout << "Enter lenght:";
		cin >> n;

		a.n = n;
		a.arr = new Rect[n];

		for (int i=0; i<n; i++) {
			cout << "[" << i+1 << "]";
			cout << "xA, yA, xC, yC? ";
			read(a.arr[i]);
		}
	}

	void print(const RectArr &a) {
		for (int i=0; i<a.n; i++) {
			cout << "[" << i+1 << "]";
			print(a.arr[i]);
			cout << endl;
		}
	}

	void delete_rect_arr(RectArr &a) {
		delete []a.arr;
		create(a);
	}

	void copy(RectArr &dest, const RectArr &src) {
		dest.arr = new Rect[src.n];
		dest.n = src.n;
		for (int i=0; i<dest.n; i++) {
			dest.arr[i] = src.arr[i];
		}
	}

	//bubble sort
	//xy
	//x<y -> poredak je dobar, ne radim nist
	//x>y -> poreadk nije dobar, menjam im mesta
	//maksimum nasao na poslenjoj poziciji
	void sort(RectArr &a) {
		for (int i=0; i<a.n-1; i++) {
			for (int j=0; j<a.n-i-1; j++) {
				if (area(a.arr[j])>area(a.arr[j+1])) {
					Rect tmp = a.arr[j];
					a.arr[j] = a.arr[j+1];
					a.arr[j+1] = tmp;
				}
			}
		}
	}
}
#endif //RECT_ARR_H
