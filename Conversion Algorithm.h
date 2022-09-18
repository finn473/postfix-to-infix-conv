//	Finn Alessandrino
//	144941
#pragma once
#include <iostream>

#include "Dynamic Stack Template.h"

template <class T>
class conversion : public linkedlist<T> {
public:
	bool isOperator(char c);
	int precedence(char c);
	std::string convertToPostfix(std::string infix);
};

template <class T>
bool conversion<T>::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%') {
		return true;
	}
	else return false;
}

template <class T>
int conversion<T>::precedence(char c) {
	switch (c) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	}
	return 0;
}

template <class T>
std::string conversion<T>::convertToPostfix(std::string infix) {
	std::string postfix;
	infix += ')';
	conversion::push('(');
	for (size_t i = 0; i < infix.size(); i++) {
		if (isdigit(infix[i])) {
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			conversion<T>::push('(');
		}
		else if (isOperator(infix[i])) {
			while (precedence(conversion<T>::stackTop()) >= precedence(infix[i])) {
				postfix += conversion<T>::stackTop();
				conversion<T>::pop();
			}
			conversion<T>::push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (conversion<T>::stackTop() != '(') {
				postfix += conversion<T>::stackTop();
				conversion<T>::pop();
			}
			conversion<T>::pop();
		}
	}
	return postfix;
}
