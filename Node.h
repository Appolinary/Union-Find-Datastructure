#ifndef _NODE_H_
#define _NODE_H_

typedef struct LinkedList_t LinkedList;

typedef struct Node_t{
	char * value;
	struct Node_t * next;
	LinkedList * head;
}Node;



#endif