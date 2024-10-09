#ifndef POINT_H
#define POINT_H

#include <iostream>
using std::cin, std::cout, std::endl;

namespace Geometry {
	struct Point {
		double x, y;
	};

	typedef struct Point Point;

	void create(Point &p, double x=0, double y=0) {
		p.x = x;
		p.y = y;
	}

	void read(Point &p) {
		double x, y;
		cin >> x >> y;
		create(p, x, y);
	}

	void print(const Point &p) {
		cout << "(" << p.x << ", " << p.y << ")";
	}

	const Point ORG = {0, 0}, JED = {1, 1};
}

#endif
