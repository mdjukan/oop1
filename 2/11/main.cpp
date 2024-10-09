#include "rect_arr.h"
#include <iostream>
using namespace std;
using namespace Geometry;

int main() {
	RectArr a;
	read(a);

	RectArr b;

	copy(b, a);
	sort(a);

	print(a);
	print(b);

	delete_rect_arr(a);
	delete_rect_arr(b);
}
