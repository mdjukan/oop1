#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {
	private:
	int f, l;
	int size;
	int *data;
	public:
	Queue(int size) : size(size) {
		data = new int[size];
		f = -1;
		l = -1;
	}

	Queue(const Queue &q) {
		cout << "COPY CONSTRUCTOR CALLED" << endl;
		size = q.size;
		data = new int[size];
		f = q.f;
		l = q.l;
		for (int i=0; i<size; i++) {
			data[i] = q.data[i];
		}
	}

	Queue(Queue &&q) {
		cout << "MOVE CONSTRUCTOR CALLED" << endl;
		size = q.size;
		data = q.data;
		q.data = nullptr;
	}

	~Queue() {
		delete []data;
	}

	bool empty() {
		return f==-1;
	}

	int firstFree() {
		return (l+1)%size;
	}

	bool full() {
		return f==firstFree();
	}

	void put(int x) {
		if (empty()) {
			data[0] = x;
			f = 0;
			l = 0;
		} else if (full()) {
			cout << "put in a full queue!" << endl;
			exit(EXIT_FAILURE);
		} else {
			l = firstFree();
			data[l] = x;
		}
	}

	int get() {
		if (empty()) {
			cout << "get on a empty queue!";
			exit(EXIT_FAILURE);
		} else {
			int first = data[f];
			if(l==f) {
				l = -1;
				f = -1;
			} else {
				f = (f+1)%size;
			}

			return first;
		}
	}

	void clear() {
		l = -1;
		f = -1;
	}

	void print() {
		if (empty()) {
			cout << "queue is empty!" << endl;
		} else {
			int current = f;
			while (current!=l) {
				cout << data[current] << " ";
				current = (current+1)%size;
			}
			cout << data[current] << endl;
		}
	}
};

Queue make_rvalue(Queue q) {
	q.put(12);
	return q;
}

void do_nothing(Queue q) {
	cout << "bla!" << endl;
}

int main() {
	Queue q(10);
	q.put(1);
	q.put(2);
	q.put(3);
	q.print();

	//Queue q1 = make_rvalue(q);
	do_nothing(q);

	q.get();
	q.print();
	q.get();
	q.print();
	q.get();
	q.print();

	q.get(); //exit
	q.print();
}
