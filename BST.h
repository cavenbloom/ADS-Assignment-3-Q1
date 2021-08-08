#pragma once
#include "NumNode.h"
#include <queue>
#include <fstream>

//Binary Search Tree
//root node sort of acting as center
//everything smaller then root, is stored on left branch somewhere
//everything else to the right
class BST
{
public:
	NumNode* root = NULL;
	virtual void insert(NumNode* newNum);

	void show(NumNode* p);

    fstream Q1OutputTXT;
};

// LevelNode helps with getting what level the numbers on the tree are on 
class LevelNode {
public:
    NumNode* num;
    int level;

    LevelNode(NumNode* num, int level) {

        this->num = num;
        this->level = level;
    }
};