#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include<vector>

/** 
* @file BinarySearchTree.hpp
* @description: burasi da fonksyolarin adi bulunuyor.
* @course 1.A grubu
* @assignment 2.Odev
* @date 28/7/2023   last update 9/8/2023
* @author Ehsanullah Shahriary
*/


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    // Insert function...
    void insert(int value);
    void insertStackElement(TreeNode*& node, int value); // Declaration of insertStackElement...
    // Postorder Traversal and print ASCII...
    void postorderTraversal(TreeNode* node);
    // Introduce a delay of 10 milliseconds...
    void delay(int milliseconds);
    // calculate heights of tree...
	int getHeight(TreeNode* node);
    // calculate value of fnodes...
	int getSum(TreeNode* node);

	void printMaxHeightTreePostorder();
    TreeNode* getRoot();

private:
    TreeNode* root;
    std::vector<TreeNode*> allTreeRoots;
    int sumOfNodeValues;

};

#endif // BINARYSEARCHTREE_HPP
