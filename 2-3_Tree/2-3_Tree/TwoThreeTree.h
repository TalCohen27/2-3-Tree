#ifndef _TWO_THREE_TREE
#define _TWO_THREE_TREE


class TwoThreeNode;

#include "TwoThreeNode.h"



class TwoThreeTree{

	TwoThreeNode * root;

public:

	TwoThreeTree(){root = new TwoThreeNode(); root->isLeaf = false;}
	
	
	TwoThreeNode *find(TreeKey );			//find
	void insertData(TreeKey, string );		//insert
	void deleteData(TreeKey );				//delete
	
	void printKeys();
	void printData();

	void freeTree();


};


#endif