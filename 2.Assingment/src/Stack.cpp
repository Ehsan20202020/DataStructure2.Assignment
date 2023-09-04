#include "Stack.hpp"
#include <iostream>
#include <fstream>

/** 
* @file Stack.cpp
* @description: burasi da fonksyonlarin govdesi bulunuyor.
* @course 1.A grubu
* @assignment 2.Odev
* @date 28/7/2023   last update 9/8/2023
* @author Ehsanullah Shahriary
*/

Stack::Stack() : topNode(nullptr) {
    // Constructor
}

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}
bool Stack::empty() const {
    return (topNode == nullptr);
}

bool Stack::isEmpty() const{
	return topNode ==nullptr;
}
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
}

int Stack::top() const {
    if (topNode != nullptr) {
        return topNode->value;
    }
    // Return a value for an empty stack...
    return -1;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        return -1; // Return a default value or handle the error as needed...
    }

    Node* temp = topNode;
    int poppedValue = temp->value; // Store the popped value..
    topNode = topNode->next;
    delete temp;

    return poppedValue; // Return the popped value...
}







