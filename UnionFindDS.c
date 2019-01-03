#include <stdio.h>
#include <stdlib.h>
#include "UnionFindDS.h"

void makeSet(UnionFindDS * ds, Node * node){
	//initialise a linked list and add this node as head
     LinkedList * list = malloc(sizeof(LinkedList)); 
     *list = (LinkedList){.head = NULL, .tail = NULL, .size = 0};
     addNode(list, node);

     //then need to add this to the new UNionDatastructure
     ds->list[ds->size] = list;
     ds->size++;
}

void removeSet(UnionFindDS * ds, Node * setRepresentative){

		//just point the head to null and deallocate it 
	int foundIndex = -1;
	for(int i = 0; i < ds->size; i++){
        if(ds->list[i] == setRepresentative->head){
        	foundIndex = i;
        }
	}


	if(foundIndex == -1){
		return;
	}

	for(int i = foundIndex; i < ds->size - 1; i++){
		ds->list[i] = ds->list[i + 1];
	}
	ds->list[ds->size - 1] = NULL;
	ds->size--;
}

void unionSet(UnionFindDS * ds, Node * nodeX, Node * nodeY){

	//if they have the same head then just return
	if(nodeX->head == nodeY->head){
		return;
	}


	removeSet(ds, nodeY);
	//removeSet(ds, nodeX);

     // LinkedList * list = malloc(sizeof(LinkedList)); 
    // *list = (LinkedList){.head = NULL, .tail = NULL, .size = 0};
	//add nodeY into nodeX;

	if(nodeX->head->head->next == NULL){ //ie if there is only one element in the set of NodeX
		//add nodeY into nodeX from nodeX head
		nodeX->head->head->next = nodeY->head->head;
		if(nodeY->head->tail == NULL){
			nodeX->head->tail = nodeY->head->head;
		}else{
			nodeX->head->tail = nodeY->head->tail;
		}
	}else{
		Node * start = nodeX->head->head->next;
		nodeX->head->head->next = nodeY->head->head;

		if(nodeY->head->tail == NULL){
			nodeY->head->tail = start;
			nodeY->head->head->next = nodeY->head->tail;
		}else{
		    nodeY->head->tail->next = start;
		}
	}

	Node * n = nodeY->head->head;

	while( n != NULL && n->head != nodeX->head){
		n->head = nodeX->head;
		n = n->next;
	}
	//makeSet(ds, nodeX);
}
LinkedList * findSet(UnionFindDS * ds, Node node){
      return node.head;
}

void printDS(UnionFindDS ds){

	for(int i = 0; i < ds.size; i++){
		printf("Set number %d : \n", i + 1);
		LinkedList * list = ds.list[i];
		printList(*list);
	}
}