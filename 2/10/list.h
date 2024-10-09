#ifndef LIST_H
#define LIST_H

struct Node {
	int k;
	struct Node *next;
};

typedef struct Node Node;

struct List {
	Node *head, *tail;
};

typedef struct List List;

List create_list();
bool empty(List &list);
void append(List &list, int x);
int take_first(List &list);
int length(List &list);
void delete_list(List &list);
void print_list(List &list);

#endif //LIST_H
