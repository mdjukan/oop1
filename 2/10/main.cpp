#include "list.h"
#include <iostream>
using namespace std;

int main() {
	List l = create_list();
	append(l, 1);
	append(l, 2);
	append(l, 3);
	append(l, 4);

 take_first(l);
 take_first(l);

	print_list(l); //3 4
	cout << length(l) << endl;
	append(l, 99);
	print_list(l);
	delete_list(l);
}
