#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "point.h"
using std::cin, std::cout, std::endl;

namespace Geometry {
	void hello() {
		cout << "hello" << endl;
	}

	struct Rect {
		Point A, C;
	};

	typedef struct Rect Rect;

	void create(Rect &r, double xA, double yA, double xC, double yC) {
		create(r.A, xA, yA);
		create(r.C, xC, yC);
	}

	void read(Rect &r) {
		read(r.A);
		read(r.C);
	}

	void print(const Rect &r) {
		cout << "[";
		print(r.A);
		cout << ", ";
		print(r.C);
		cout << "]";
	}

	double area(const Rect &r) {
		double w = abs(r.A.x - r.C.x);
		double h = abs(r.A.y - r.C.y);
		return w*h;
	}
}
#endif //RECT_H
