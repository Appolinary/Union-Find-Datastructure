#include <stdio.h>
#include <stdlib.h>
#include "UnionFindDS.h"


int main(int argc, char ** argv){

	Node node1 = {.value = "A", .next = NULL, .head = NULL};
	Node node2 = {.value = "B", .next = NULL, .head = NULL};
	Node node3 = {.value = "C", .next = NULL, .head = NULL};
	Node node4 = {.value = "D", .next = NULL, .head = NULL};

	UnionFindDS ds = {.list = malloc(sizeof(UnionFindDS *) * 20), .size = 0};

	makeSet(&ds, &node1);
	makeSet(&ds, &node2);
	makeSet(&ds, &node3);
	makeSet(&ds, &node4);
	//printDS(ds);

	printf("===================================================================\n");

	unionSet(&ds, &node1, &node2);
	unionSet(&ds, &node2, &node3);
	unionSet(&ds, &node1, &node3);
	printDS(ds);

}
