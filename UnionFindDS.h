#ifndef _UNION_FIND_DS_H_
#define _UNION_FIND_DS_H_

#include "Node.h"
#include "LinkedList.h"


typedef struct UnionFindDS_t {
	LinkedList ** list;
	int size;
}UnionFindDS;

void makeSet(UnionFindDS * ds, Node * node);
void unionSet(UnionFindDS * ds, Node * nodeX, Node * nodeY);
LinkedList * findSet(UnionFindDS * ds, Node node);
void printDS(UnionFindDS ds);
void removeSet(UnionFindDS * ds, Node * setRepresentative);

#endif