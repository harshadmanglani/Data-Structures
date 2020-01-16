/*
 * PriorityQ.cpp
 *
 *  Created on: 02-Jan-2020
 *      Author: f11
 */

#include "Priority_Q.h"

#include <iostream>

template<class T>
Priority_Q<T>::Priority_Q() {
front = NULL;
rear = NULL;
}
template<class T>
void Priority_Q<T>::enqueue(T data, int p)
{
		Node<T> *tmp;
		Node<T> *temp;
		temp = ret_front();
		tmp = this->getnode(tmp);
		tmp->priority = p;
		tmp->data = data;
		tmp->next = NULL;

		if(front == NULL || rear == NULL)
		{
			rear = tmp;
			front = rear;
		}
		else if(tmp->priority < front->priority)
		{
			tmp->next = front;
			front = tmp;
		}
		else
		{
			while(temp->next!= NULL && (tmp->priority >= temp->next->priority))
				temp = temp->next;

			if(tmp->next == NULL)
			{
				rear = tmp;
				tmp->next = temp;
			}
			tmp->next = temp->next;
			temp->next = tmp;
		}
}


template <class T>
void Priority_Q<T>::dequeue()		//dequeue
{
	//case 1: queue is empty
	if(front == NULL && rear == NULL)
		return;
	else
	{
		//case 2: queue is not empty
		//case 2.a: only one element
		if(front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{

			Node<T> *temp = front->next;
			delete front;
			front = temp;
		}
	}
}
template <class T>
Node<T>* Priority_Q<T>::ret_front()			//returns the last element of the queue
{
	return front;
}

template <class T>
bool Priority_Q<T>::isempty()
{
	if(front == NULL && rear == NULL)
		return true;
	else
		return false;
}

template <class T>
void Priority_Q<T>::disp()			//display the display
{
	std::cout<<std::endl;
	Node<T> *obj = front;
	std::cout<<obj->data;
	obj = obj->next;
	while(obj!=NULL)
	{
		std::cout<<std::endl<<obj->data;
		obj = obj->next;
	}
	std::cout<<std::endl;
}

template <class T>
Node<T>* Priority_Q<T>::getnode(Node<T> *head)
{
	head = new Node<T>;
	head->next = NULL;
	return head;
}
