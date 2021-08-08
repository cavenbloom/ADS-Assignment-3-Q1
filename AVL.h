#pragma once
#include "BST.h"

//AVL is self balancing binary search tree
//AVL - Adelson, Velski & Landis
class AVL : public BST
{
public:
	bool displayRotations = true;

	//works out height of sub tree
	int height(NumNode* node);

	//difference between left and right sub trees
	int difference(NumNode* node);

	//ROTATIONS
	//return: new parent of subtree
	//parameter: current parent of sub tree
	//right branch, right child
	NumNode* RRrotation(NumNode* parent);
	//left branch, left child
	NumNode* LLrotation(NumNode* parent);
	//left branch, right child
	NumNode* LRrotation(NumNode* parent);
	//right branch, left child
	NumNode* RLrotation(NumNode* parent);

	//BALANCE
	//balances a tree structure where parent is the middle top node
	//returns new parent after balancing(rotations)
	NumNode* balance(NumNode* parent);

	//INSERT
	//recursive insert that considers parent a sub tree
	//this insert also balances itself
	//returns the new root node of the tree
	NumNode* insertAVL(NumNode* parent, NumNode* newNum);

	//overriding insert from parent
	void insert(NumNode* newNum);
};

