#include <iostream>
using namespace std;


#define EXIT_CODE 9999

struct Node {
	int val;
	struct Node *next;
};

Node *load_list() {
	int val;
	Node *head = nullptr;
	Node *tail = nullptr;

	while (true) {
		cin >> val;
		if (val==EXIT_CODE) {
			break;
		}

		Node *new_node = new Node();
		new_node->val = val;
		new_node->next = nullptr;

		if (head==nullptr) {
			head = new_node;
			tail = new_node;
		} else {
			tail->next = new_node;
			tail = new_node;
		}
	}

	return head;
}

void delete_list(Node **head) {
	Node *current = *head;
	while (current!=nullptr) {
		Node *next = current->next;
		delete current;
		current = next;
	}

	*head = nullptr;
}

void print_list(Node *head) {
	Node *current = head;
	while (current!=nullptr) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

typedef struct Node Node;

int main() {
	Node *head = load_list();
	print_list(head);
	delete_list(&head);
}
