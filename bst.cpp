#include "stdafx.h"
#include "bynary_tree.h"
#include <math.h>

using namespace std;


bst::bst()
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = 0;
}

bst::bst(int val)
{
	leftSubtree = NULL;
	rightSubtree = NULL;
	value = val;
}

bst::~bst()
{

}

void bst::addNode(bst *root, int key)
{
	if (key < root->value){

		if (root->leftSubtree){
			addNode(root->leftSubtree, key);
		}
		else{
			root->leftSubtree = new bst(key);
		}
	}

	if (key >= root->value){
		if (root->rightSubtree){
			addNode(root->rightSubtree, key);
		}
		else{
			root->rightSubtree = new bst(key);
		}
	}
}

void bst::addNodeWrapper(int key){
	addNode(this, key);
}

bst bst::find(bst *root, int key)
{
	if (!root) return NULL;
	if (key == root->value)
		return *root;
	if (key < root->value)
	{
		return (find(root->leftSubtree, key));
	}
	else
	{
		return find(root->rightSubtree, key);
	}

}


bst bst::delNode(bst *root, int key)
{
	bst *pv = root;
	if (pv == 0)
	{
		return NULL;
	}
	find(root, key);
	if (key<pv->value)
		*pv->leftSubtree = delNode(pv->leftSubtree, key);
	else
		if (key > pv->value)
		{
			*pv->rightSubtree = delNode(pv->rightSubtree, key);
		}
		else
			if (pv->leftSubtree != 0 && pv->rightSubtree != 0)
			{
				bst *r = pv;
				pv->value = minimumLeft(&r)->value;
				pv->rightSubtree = (delete(pv, (pv->rightSubtree))->value);
			}
			else
				if (pv->leftSubtree != 0)
				pv = pv->leftSubtree;
				else
				pv = pv->rightSubtree;
	return *pv;
}



bst bst::minimumLeft(bst *root)
{
	bst *pv = root;
	while (pv->leftSubtree)
		pv = pv -> leftSubtree;
	return *pv;

}
