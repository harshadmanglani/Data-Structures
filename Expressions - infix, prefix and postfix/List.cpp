/*
 * List.cpp
 *
 *  Created on: 19-Dec-2019
 *      Author: f11
 */
#include <iostream>
#include "List.h"

template <class T>
List<T>::List()			//constructor
{
	head = NULL;
}

template <class T>		//helper function
Node<T>* List<T>::getnode(Node<T> *head)
{
	head = new Node<T>;
	head->next = NULL;
	return head;
}


template <class T>		//returns true if list is empty
bool List<T>::isempty()
{
	if(head == NULL)
		return true;
	else
		return false;
}

template <class T>		//adds element at the beginning of the linked list
void List<T>::add_beg(T val)
{
	if(head != NULL)
	{
		Node<T> *temp;
		temp = getnode(temp);
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	else
	{
		head = getnode(head);
		head->data = val;
	}
}
template <class T>
void List<T>::set(Node <T>* ptr)		//sets new value to head pointer
{
    this->head = ptr;
}

template <class T>
void List<T>::add_end(T val)				//add element to the end of the list
{
	if(head != NULL)
	{
		Node<T> *temp1, *temp2;
		temp2 = getnode(temp2);
		temp1 = head;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		temp2->data = val;
		temp1->next = temp2;
		head = temp1;
	}
	else
	{
		head = getnode(head);
		head->data = val;
	}
}

template <class T>
Node<T>* List<T>::del_beg()			//delete an element from the beginning of the list
{
	if(head == NULL)
		{
//		std::cout<<"case 1 enter"<<std::endl;
		return NULL;
		}
	else if(head->next == NULL)
	{
//		std::cout<<"case 2 enter"<<std::endl;
		delete head;
		this->head = NULL;
		return NULL;
	}
//	std::cout<<"case 3 enter"<<std::endl;
	else{
	Node<T> *temp;
	temp = head->next;
	delete head;
	this->head = temp;
	return temp;
	}
//	std::cout<<"case 3 test"<<head->data<<std::endl;
}

template <class T>		//delete an element from the end of the list
void List<T>::del_end()
{
	if(head == NULL)
		return;
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
		return;
	}
		Node<T> *temp;
	temp = head;
	while(temp->next->next != NULL)
		temp = temp->next;
	delete temp->next;
	temp->next = NULL;
}

template <class T>
T List<T>::ret_first()		//return the first element of the list
{
	return head->data;
}
