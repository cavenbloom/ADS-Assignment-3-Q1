#include "BST.h"

void BST::insert(NumNode* newNode)
{
    //IF the root is NULL(tree is empty), then make this student the root
    if (root == NULL)
    {
        root = newNode;
        return; //exit function early, we are done here
    }

    //some pointers to help us navigate the tree to find where to put the new student
    NumNode* current = root; //current node we're pointing at
    NumNode* parent = NULL; //parent of current (node visitored last time)

    while (true)//infinite loop
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
        //if new students studentID is less then the student at current node, then go down LEFT
        if (newNode->intNum < current->intNum)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our new Student :D
            if (current == NULL)
            {
                //done, stick student here
                parent->leftChild = newNode;
                return; //done, bail
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            //if current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newNode;
                return;
            }
        }
    }
}

void BST::show(NumNode* p) {

    Q1OutputTXT.open("output-q1a2.txt");
    // base case 
    if (root == NULL)
        return;

    // create an empty queue for level order traversal 
    queue<LevelNode> q;

    // Enqueue Root and initialize height
    q.push(LevelNode(root, 0));

    int previousOutputLevel = -1;

    while (q.empty() == false) {

        // print front of queue and remove it from queue 
        LevelNode NumNode = q.front();
        if (NumNode.level != previousOutputLevel) {

            Q1OutputTXT << endl;
            Q1OutputTXT << NumNode.level << " : ";
            previousOutputLevel = NumNode.level;
        }

        Q1OutputTXT << NumNode.num->intNum << " ";
        q.pop();

        // enqueue left child 
        if (NumNode.num->leftChild != NULL)
            q.push(LevelNode(NumNode.num->leftChild, NumNode.level + 1));

        // enqueue right child 
        if (NumNode.num->rightChild != NULL)
            q.push(LevelNode(NumNode.num->rightChild, NumNode.level + 1));
    }
}