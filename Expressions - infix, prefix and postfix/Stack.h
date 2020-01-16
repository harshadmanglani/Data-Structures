/*
 * Stack.h
 *
 *  Created on: 19-Dec-2019
 *      Author: f11
 */

#ifndef STACK_H_
#define STACK_H_
#include "List.h"

template <class T>
class Stack {
	List<T> base;
public:
	Stack();
	void display();
	void push(T val);
	void pop();
	T top();
	bool isempty();
};

#endif /* STACK_H_ */
