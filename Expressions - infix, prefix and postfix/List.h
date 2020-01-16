/*
 * List.h
 *
 *  Created on: 19-Dec-2019
 *      Author: f11
 */

#ifndef LIST_H_
#define LIST_H_

template <class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class List {
	Node<T> *head;
public:
	List();
	Node<T>* getnode(Node<T> *head);
	bool isempty();
	T ret_first();
	void add_end(T val);
	void add_beg(T val);
	void del_end();
	void set(Node<T>*);
	Node<T>* del_beg();
};

#endif /* LIST_H_ */
