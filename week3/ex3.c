#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
} linked_list;

void print_list(linked_list* list){
	for(Node* i = list->head; i; i = i->next){
		printf("%d ", i->data);
	}
	printf("\n");
}

void insert_node(linked_list* list, int index, int data){
	Node* right = malloc(sizeof(Node));
	right->data = data;
	if(index == 0){
		right->next = list->head;
		list->head = right;
	} else {
		Node* left = list->head;
		for(int i = 1; i < index; i++){
			left = left->next;
		}
		right->next = left->next;
		left->next = right;
	}
}

void delete_node(linked_list* list, int index){
	Node* node = list->head;
	if(index == 0){
		node = node->next;
		free(list->head);
		list->head = node;
	} else {
		for(int i = 1; i < index; i++){
			node = node->next;
		}
		Node* temp = node->next;
		node->next = node->next->next;
		free(temp);
	}
}

linked_list* make_empty_list(){
	linked_list* list = malloc(sizeof(linked_list));
	list->head = NULL;
	return list;
}

void main(){
	linked_list* list = make_empty_list();
	insert_node(list, 0, 1);
	insert_node(list, 0, 2);
	insert_node(list, 0, 10);
	insert_node(list, 0, 3);
	print_list(list);
	delete_node(list, 3);
	delete_node(list, 2);
	delete_node(list, 1);
	delete_node(list, 0);
	free(list);
}
