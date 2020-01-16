/*
 * PriorityQ.h
 *
 *  Created on: 02-Jan-2020
 *      Author: f11
 */

#ifndef PRIORITY_Q_H_
#define PRIORITY_Q_H_
#include <iostream>

template <class T>
struct Node
{
	T data;
	int priority;
	Node<T> *next;
};

template <class T>
class Priority_Q{
	Node<T> *front;
	Node<T> *rear;
public:
	Priority_Q();
	void enqueue(T data, int p);
	Node<T>* getnode(Node<T> *head);
	void dequeue();
	bool isempty();
	void disp();
	Node<T>* ret_front();
};

#endif /* PRIORITY_Q_H_ */
