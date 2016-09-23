
#include "TwoThreeTree.h"


TwoThreeNode * TwoThreeTree::find(TreeKey inKey)
{
	
	
	return root->find(inKey);
	

}

void TwoThreeTree::insertData(TreeKey inKey, string item)
{
	

	TwoThreeNode * newNode = new TwoThreeNode(inKey, item);
	newNode->isLeaf = true;

	TwoThreeNode * brother = root->insertData(newNode);




	if(brother != NULL && root->numChildren == 2)
	{
		
		TwoThreeNode *rootSaver = root;

		root = new TwoThreeNode();
		root->isLeaf = false;
		root->numChildren = 2;

		root->mid = rootSaver;
		root->left = brother;

		root->min1 = root->left->min1;
		root->min2 = root->mid->min1;

	}

	
}

void TwoThreeTree::deleteData(TreeKey k)
{
	
	root->deleteData(k, NULL);

	if(root->numChildren == 1)				
	{
		
		TwoThreeNode *oldRoot = root;

		if(root->left != NULL)
			root = root->left;
		else if(root->mid != NULL)
			root = root->mid;
		else
			root = root->right;

		delete oldRoot;
		oldRoot = NULL;
		
	}


}

void TwoThreeTree::printKeys()
{
	if(root->left != NULL)
		root->left->printKeys();

	if(root->mid != NULL)
		root->mid->printKeys();

	if(root->right != NULL)
		root->right->printKeys();

	cout<<endl;
}

void TwoThreeTree::printData()
{
	if(root->left != NULL)
		root->left->printData();

	if(root->mid != NULL)
		root->mid->printData();

	if(root->right != NULL)
		root->right->printData();

	cout<<endl;
}

void TwoThreeTree::freeTree()
{
	root->freeTree();

}