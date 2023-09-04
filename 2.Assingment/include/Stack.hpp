#ifndef STACK_HPP
#define STACK_HPP
#include <string>

/** 
* @file Stack.hpp
* @description: burasi da fonksyonlarin adi bulunuyor.
* @course 1.A grubu
* @assignment 2.Odev
* @date 28/7/2023   last update 9/8/2023
* @author Ehsanullah Shahriary
*/

class Stack {
public:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };
    
    Stack();
    ~Stack();
    void push(int value);
    int top() const;
    int pop();
    bool empty() const;
	bool isEmpty() const;
    void processFile(const std::string& filename);
	// Public method to get the top node...
    Node* getTopNode() const {
        return topNode;
    }
	
private:
    
    Node* topNode;
};	

#endif // STACK_HPP
