#ifndef _TWO_THREE_NODE
#define _TWO_THREE_NODE




#include <iostream>
using namespace std;
#include <string>


#define DELETED  -1				//for the record
enum{goLeft, goMiddle, goRight};


typedef int TreeKey;

class TwoThreeNode
{

	//for inner nodes
	TwoThreeNode *left, *mid, *right;
	bool isLeaf;
	int numChildren;

	TreeKey min1, min2, min3;

	//for leaves
	TreeKey key;
	string Data;

public:

	//c'tors
	TwoThreeNode(TreeKey _key, string _Data):key(_key), Data(_Data), left(NULL), mid(NULL), right(NULL), numChildren(0){};
	TwoThreeNode():left(NULL), mid(NULL), right(NULL), numChildren(0){}
	
	TwoThreeNode *find(TreeKey );

	TwoThreeNode * insertData(TwoThreeNode *);

	TwoThreeNode * deleteData(TreeKey, TwoThreeNode * );
	

	void printKeys();
	void printData();



	int findPath(TwoThreeNode *);
	int findPath(TreeKey );

	void updateMins(TwoThreeNode *);
	void updateMins(TreeKey );

	bool isLastLevel();
	void insertInPlace(TwoThreeNode *);
	TwoThreeNode * splitOnInsert(TwoThreeNode *);

	TwoThreeNode *notLastLevel(TwoThreeNode *);

	TreeKey getLeftMin(){return min1;}
	TreeKey getMidMin (){return min2;}
	TreeKey getRightMin(){return min3;}

	void swapMins(TreeKey , TreeKey );
	void swapLeaves(TwoThreeNode *, TwoThreeNode *);

	string getData(){return Data;}

	void twoChildrenLeft();
	void borrowFromUncle(TwoThreeNode *);
	void transferToUncle(TwoThreeNode *);
	

	void freeTree();

	friend class TwoThreeTree;
	
	

};


#endif