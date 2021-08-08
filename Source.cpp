#include <iostream>
#include <string>
#include <fstream> // File reading/writing library
#include <vector> // For array storage
#include <queue>
#include "BST.h"
#include "AVL.h"

using namespace std;

int main() {

	ifstream Q1InputTXT;
	fstream Q1OutputTXT;

	Q1InputTXT.open("input-q1a2.txt");
	{

		// ====================== INPUT 
		// Opening up input file, reading it.
		// Int and string to hold data input of the .txt file
		int firstLineIn;
		vector<int> treeNum;
		int numberOfNumbers;
		AVL avl;

		Q1OutputTXT.open("output-q1a2.txt");

		if (Q1InputTXT.is_open()) 
		{
		// Storing the numbers
			Q1InputTXT >> numberOfNumbers;
			cout << numberOfNumbers << endl;

			for (int i = 0; i < numberOfNumbers; i++) 
			{
				int temp;
				Q1InputTXT >> temp;
				treeNum.push_back(temp);
				avl.AVL::insert(new NumNode(temp));
			}

			for (int i = 0; i < treeNum.size(); i++) 
			{
				cout << treeNum[i] << " ";
			}

			avl.show(avl.root);

		}
		else if (!Q1InputTXT.is_open())
		{
			cout << "Error, file not found." << endl;
			char errmsg[128];
			strerror_s(errmsg, 128, errno);
			printf("Error: %s\n", errmsg);
		}

	}

	// Close the files afterward.
	Q1InputTXT.close();
	Q1OutputTXT.close();

}