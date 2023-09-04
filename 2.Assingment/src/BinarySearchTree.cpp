#include "BinarySearchTree.hpp"
#include <iostream>
#include <windows.h>

/** 
* @file BinarySearchTree.cpp
* @description: burasi da fonksyonlarin govdesi bulunuyor.
* @course 1.A grubu
* @assignment 2.Odev
* @date 28/7/2023   last update 9/8/2023
* @author Ehsanullah Shahriary
*/

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr), sumOfNodeValues(0){
    
    // Constructor...
}

TreeNode* BinarySearchTree::getRoot() {
    return root;
}

// Introduce a delay of 10 milliseconds...
void BinarySearchTree::delay(int milliseconds) {
    Sleep(milliseconds);
}

// Insert function...
void BinarySearchTree::insert(int value) {
    insertStackElement(root, value); // Call insertStackElement with root...
	allTreeRoots.push_back(root);    // Store the root node of the inserted tree...
    // Calculate and update the sum of node values...
    sumOfNodeValues += value;
}

void BinarySearchTree::insertStackElement(TreeNode*& node, int value) {
    if (node == nullptr) {
        node = new TreeNode(value);
        return;
    }

    if (value < node->value) {
        insertStackElement(node->left, value);
    } else if (value > node->value) {
        insertStackElement(node->right, value);
    }else{}
	
}

// Postorder Traversal and print ASCII...
void BinarySearchTree::postorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);

    // Display the ASCII representation of the numeric value...
    cout << char(node->value) << " ";
    // delay for10 milliseconds...
    delay(10);
}


// calculate heights of tree...
int BinarySearchTree::getHeight(TreeNode* node) {
    if (node == nullptr) {
        return -1; // Height of an empty tree is 0...
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// calculate value of nodes...
int BinarySearchTree::getSum(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->value + getSum(node->left) + getSum(node->right);
}

void BinarySearchTree::printMaxHeightTreePostorder() {
    int maxHeight = 0;
    TreeNode* maxTreeRoot = nullptr;

    for (TreeNode* root : allTreeRoots) { 
        int height = getHeight(root);
        if (height > maxHeight) {
            maxHeight = height;
            maxTreeRoot = root; // Update the root of the max height tree...
        }
    }

    postorderTraversal(maxTreeRoot);
    /// when printing line by line....
    cout << std::endl;

}





