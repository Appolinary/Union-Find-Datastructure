#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void addNode(LinkedList * list, Node * node){

	if(list->head == NULL){
		list->head = node;

		//make the head of the new node the head of the list
		list->head->head = list;
		return;
	}


	if(list->tail == NULL){
		list->tail = node;
		list->head->next = list->tail;

		//make the head of the new node the head of the list
		list->head->next->head = list;
		return;
	}

    list->tail->next = node;

    //make the head of the new node to the list head
    list->tail->next->head = list;

    list->tail = list->tail->next;
}

void removeNode(LinkedList * list, Node node){

}

void printList(LinkedList  list){

	Node * node = list.head;
	while(node){
		printf("(value: %s , head: %s)-> ", node->value, node->head->head->value);
		node = node->next;
	}
	printf("\n");

}