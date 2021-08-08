#pragma once
#include <iostream>
#include <string>

using namespace std;

class NumNode
{
public:
	int intNum;
	NumNode* leftChild;
	NumNode* rightChild;
	NumNode(int intNum);
};

