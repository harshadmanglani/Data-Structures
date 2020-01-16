/*
 * Stack.cpp
 *
 *  Created on: 19-Dec-2019
 *      Author: f11
 */

#include "Stack.h"
#include <iostream>

template <class T>		//constructor
Stack<T>::Stack() {
}

template <class T>
bool Stack<T>::isempty()	//returns true if stack is empty
{
	if(base.isempty())
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::push(T val)	//push an element in the stack
{
	base.add_beg(val);
}

template <class T>
void Stack<T>::pop()//pop an element
{
	if(!(this->isempty()))
		base.set(base.del_beg());
	else
		return;
}
template <class T>
T Stack<T>::top()
{
	if(!(this->isempty()))
		return base.ret_first();
	else
		return '\0';
}

template <class T>
void Stack<T>::display()
{
	Stack<T> temp;
	if(this->isempty()) //&& this->top()!='+' && this->top()!='-' && this->top()!='*' && this->top()!='/' && this->top()!='(' && this->top()!=')' && this->top()!='^')
	{
	std::cout<<"Empty";
	return;
	}
	while(!this->isempty())
	{
		temp.push(top());
		this->pop();
//		std::cout<<this->top()<<" ";
//		this->pop();
	}
	while(!temp.isempty())
	{
		std::cout<<temp.top();
		this->push(temp.top());
		temp.pop();
	}
}

