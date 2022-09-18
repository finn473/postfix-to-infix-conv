//	Finn Alessandrino
//	144941
#pragma once
#include <iostream>
template <class T>
struct stacknode {
	T data;
	stacknode<T>* next;
};

template <class T>
class linkedlist {
public:
	linkedlist() {							// Default Constructor
		top = NULL;
	}
	~linkedlist();							// Destructor

	void push(const T& newThing);			// Add new item to stack
	void pop();								// Pop top item of stack
	T stackTop();							// Print first item of stack
	void printStack() const;				// Print all elements in stack
	bool isEmpty();							// Check if stack is empty
protected:
	stacknode<T>* top;
};

template<class T>
linkedlist<T>::~linkedlist() {
	stacknode<T>* nodePtr = top;
	while (!isEmpty()) {
		top = top->next;
		delete nodePtr;
	}
}

template<class T>
void linkedlist<T>::push(const T& newThing) {
	stacknode<T>* newnode;
	newnode = new stacknode<T>;
	newnode->data = newThing;
	newnode->next = top;
	top = newnode;
}

template<class T>
void linkedlist<T>::pop() {
	stacknode<T>* nodePtr;
	if (isEmpty()) {
		std::cout << "Nothing to pop!" << std::endl;
	}
	else {
		nodePtr = top;
		top = top->next;
		delete nodePtr;
	}
}

template<class T>
T linkedlist<T>::stackTop() {
	if (isEmpty()) {
		std::cout << "Top is empty!" << std::endl;
	}
	else {
		return top->data;
	}
}

template<class T>
void linkedlist<T>::printStack() const {
	stacknode<T>* nodePtr;
	nodePtr = top;
	if (isEmpty()) {
		std::cout << "Nothing to print!" << std::endl;
	}
	else {
		while (nodePtr != NULL) {
			std::cout << nodePtr->data << " ";
			nodePtr = nodePtr->next;
		}
	}
}

template<class T>
bool linkedlist<T>::isEmpty() {
	if (linkedlist<T>::top == NULL) {
		return true;
	}
	else return false;
}
