#include <stdlib.h>
#include <stdio.h>

struct Node {
	int n;
	struct Node *next;
};

typedef struct Node Node;

Node *create_node(int n) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->n = n;
	node->next = NULL;
	return node;
}

Node *load_list() {
	int n;
	scanf("%d", &n);

	int val;
	scanf("%d", &val);
	Node *head = create_node(val);
	Node *tail = head;

	for (int i=1; i<n; i++) {
		scanf("%d", &val);
		Node *new_node = create_node(val);
		tail->next = new_node;
		tail = new_node;
	}

	return head;
}

void print_list(Node *head) {
	Node *current = head;
	while (current!=NULL) {
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}

Node *reversed(Node *head) {
	Node *current = head;
	Node *new_head = NULL;
	while (current!=NULL) {
		Node *n = current;
		current = current->next;

		n->next = new_head;
		new_head = n;
	}

	return new_head;
}

int main() {
	Node *head = load_list();
	Node *rev = reversed(head);
	print_list(rev);
}
