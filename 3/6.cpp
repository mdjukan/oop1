#include <iostream>
using namespace std;

const int Vmax = 10;
class Cuboid {
	private:
		int a, b, c;
		Cuboid(int a, int b, int c) : a(a), b(b), c(c) {}
	public:
		static int V;
		Cuboid(const Cuboid&) = delete;
		int volume() {
			return a*b*c;
		}

		static Cuboid *create(int a, int b, int c) {
			if (a*b*c+V>Vmax) {
				return nullptr;
			} else {
				Cuboid *cub = new Cuboid(a, b, c);
				V += cub->volume();
				return cub;
		       	}
		}

		~Cuboid() {
			V -= volume();
		}

		friend ostream& operator<<(ostream &out, Cuboid *c);
};

int Cuboid::V = 0;

ostream& operator<<(ostream &out, Cuboid *c) {
	out << "(" << c->a << ", " << c->b << ", " << c->c << ")";
	return out;
}

int main() {
	Cuboid *c = Cuboid::create(1, 1, 1);
	cout << c << endl;

	Cuboid *c1 = Cuboid::create(10, 10, 10);
	cout << boolalpha << (c1==nullptr) << endl;
}
