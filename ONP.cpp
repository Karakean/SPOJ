#include <iostream>
#include <ctype.h>
struct Node {
	Node* next;
	char value;
};
void push(Node** top, char val) {
	Node* new_node;
	new_node = new Node();
	new_node->value = val;
	if ((*top) == nullptr) {
		(*top) = new_node;
		(*top)->next = nullptr;
	}
	else {
		new_node->next = (*top);
		(*top) = new_node;
	}
}
void pop(Node** top){
	while (1) {
		printf("%c", (*top)->value);
		if ((*top)->next == nullptr)
			break;
		else {
			(*top) = (*top)->next;
			if ((*top)->value == '(') {
				*top = (*top)->next;
				break;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		Node* top = nullptr;
		std::string tmp;
		int i = 0;
		std::cin >> tmp;
		while (tmp[i]!='\0') {
			if (tmp[i] == ')') {
				pop(&top);
			}
			else if (!isalpha(tmp[i]))
				push(&top, tmp[i]);
			else
				printf("%c", tmp[i]);
			++i;
		}
		printf("\n");
	}
}
