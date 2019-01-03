#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Node.h"

typedef struct LinkedList_t{

	Node * head; //the head
	Node * tail; //the tail
	int size;

}LinkedList;


void addNode(LinkedList * list, Node * node);
void removeNode(LinkedList * list, Node node);
void printList(LinkedList list);

#endif