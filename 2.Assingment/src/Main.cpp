#include "Stack.hpp"
#include "BinarySearchTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream> // Include this for std::istringstream
#include <memory>

using namespace std;

/** 
* @file Stack.hpp
* @description: burasi da fonksyonlarin govdesi bulunuyor.
* @course 1.A grubu
* @assignment 2.Odev
* @date 28/7/2023   last update 9/8/2023
* @author Ehsanullah Shahriary
*/


int main() {
    ifstream inputFile("veriler2.txt");
    if (!inputFile) {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    // Maximum number of lines...
    const int maxLines = 1000; 
    Stack*** stackArray = new Stack**[maxLines]{}; // Dynamic array of pointers to stacks...
    int lineNumber = 0;
    int stackCount = 0;
	
	// Create an array of BSTs for the line...
    BinarySearchTree** bstArray = new BinarySearchTree*[stackCount]{};
	
    // Initialize maxHeight to no valid ...
	int maxHeight = -1; 
    // Initialize the root of the tree with maximum height...
    BinarySearchTree* maxTree = nullptr; 
    // Initialize the BST with maximum sum of node values for the current line...
    BinarySearchTree* maxSumTree = nullptr; 

    string line;
    while (getline(inputFile, line)) {
        if (lineNumber >= maxLines) {
            cerr << "Exceeded maximum number of lines" << endl;
            break;
        }

        // Create an array of stacks for the line...
        stackArray[lineNumber] = new Stack*[line.size()]{}; 
        stackCount = 0; // Reset stackCount for the new line...
        int currentMaxHeight = -1; // Initialize the maximum height for the current line...
        

        istringstream iss(line);
        int number;
        while (iss >> number) {
            if (number >= 0 && number <= 256) {
                if (stackCount == 0 || (number % 2 == 0 && number > stackArray[lineNumber][stackCount - 1]->top())) {
                    stackArray[lineNumber][stackCount] = new Stack(); // Create a new stack for the line...
                    // Push the number onto the newly created stack...
                    stackArray[lineNumber][stackCount]->push(number); 
                    stackCount++;
                } else {
                    // Push the number onto the existing stack...
                    stackArray[lineNumber][stackCount - 1]->push(number);
                }
            }
        }


        bool isNewMaxTree = false;
        for (int i = 0; i < stackCount; i++) {
            Stack* stack = stackArray[lineNumber][i];
			// Create a new BST for this stack...
            BinarySearchTree* bst = new BinarySearchTree();
            while (!stack->empty()) {
                int poppedValue = stack->pop();
                bst->insert(poppedValue);
            }
			// store the pointer in bstArray...
            bstArray[i] = bst;

            int sumOfNodes = bstArray[i]->getSum(bst->getRoot());
            int treeHeight = bstArray[i]->getHeight(bst->getRoot());
            
            if(treeHeight > currentMaxHeight){
                currentMaxHeight = treeHeight;
                maxHeight = treeHeight; // Update the overall maximum height...
                delete maxTree; // Clean up memory for the previous maxTree...
                maxTree = bstArray[i]; // Update the tree with for the current line...
                maxSumTree = nullptr; // Reset maxSumTree...
            }
            // treeHeight is equal...
            else if(treeHeight == currentMaxHeight){
                // If heights are equal, update maxSumTree with the tree that has the largest sum of node values...
                if (!maxSumTree || sumOfNodes > maxSumTree->getSum(maxSumTree->getRoot())) {
                    delete maxSumTree; // Clean up memory for the previous maxSumTree...
                   maxSumTree = bstArray[i]; // Update maxSumTree with the tree with the largest sum of node values...
                }
                // If total values are also equal...
                else if (sumOfNodes == maxSumTree->getSum(maxSumTree->getRoot())) {
                    // If total values are also equal, the tree created first will be the maxHeight...
                    delete bstArray[i]; // Clean up memory for this BST since it's not the maximum height or sum...
                    isNewMaxTree = true;
                }
                else {
                    delete bstArray[i]; // Clean up memory for this BST since it's not the maximum height or sum...
                    bstArray[i] = nullptr; // Reset bstArray[i] without deleting the object...
                }
                }else{
                    delete bstArray[i]; // Clean up memory for this BST...
                    bstArray[i] = nullptr; // Reset bstArray[i] without deleting the object...
                }
                
        }

        // Print the maximum height for the current line. I AM USING FOR TEST...
        //cout << "Maximum Height for line " << lineNumber + 1 << ": " << currentMaxHeight << endl;
        
        if (maxSumTree && !isNewMaxTree) {
            // it is for testing...
            //cout << "Postorder Traversal for tree...";
            maxSumTree->printMaxHeightTreePostorder();
            cout << endl;
        }else if (maxTree) {
            // it is for testing...
            //cout << "Postorder Traversal for tree...";
            maxTree->printMaxHeightTreePostorder();
            cout << std::endl;
        }
		
		lineNumber++; // Move to the next line
    }

    
	// Cleanup memory...
    for (int i = 0; i < lineNumber; i++) {
		int actualStackCount = 0; // Keep track of the actual number of stacks created for this line...
		while (stackArray[i][actualStackCount] != nullptr) {
			delete stackArray[i][actualStackCount];
			actualStackCount++;
		}
		delete[] stackArray[i];
	}
	
	delete[] stackArray;
    delete maxTree; // Clean up memory for the maxTree...

    inputFile.close();

    return 0;


}


