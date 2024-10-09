#include "list.h"
#include "list.h"
#include <iostream>
using namespace std;

List create_list() {
	List l;
	l.head = nullptr;
	l.tail = nullptr;
	return l;
}

bool empty(List &list) {
	return list.head==nullptr;
}

void append(List &list, int x) {
	Node *node = new Node;
	node->k = x;
	node->next = nullptr;

	if (empty(list)) {
		list.head = node;
		list.tail = node;
	} else {
		list.tail->next = node;
		list.tail = node;
	}
}

//pp lista nije prazna
int take_first(List &list) {
	Node *head = list.head;
	if (head->next==nullptr) {
		list.head = nullptr;
		list.tail = nullptr;
	} else {
		list.head = head->next;
	}

	int k = head->k;
	delete head;
	return k;
}

int length(List &list) {
	Node *current = list.head;
	int len = 0;
	while (current!=nullptr) {
		len += 1;
		current = current->next;
	}

	return len;
}

void delete_list(List &list) {
	Node *current = list.head;
	while (current!=nullptr) {
		Node *tmp = current;
		current = current->next;
		delete tmp;
	}
}

void print_list(List &list) {
	if (empty(list)) {
		cout << "list is empty" << endl;
		return;
	}

	Node *current = list.head;
	while (current!=nullptr) {
		cout << current->k << " ";
		current = current->next;
	}
	cout << endl;
}
