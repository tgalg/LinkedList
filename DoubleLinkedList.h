/*
	@file DoubleLinkedList.h
	@author Tommy Gallagher
	@date 09/26/15
	@DoubleLinkedList header file
*/

#ifndef DLL_H
#define DLL_H
#include "Node.h"

template<typename T>

class DoubleLinkedList
{
	private:
	Node<T>* m_front;				//always point to first node
	Node<T>* m_back;				//always points to last node
	int m_size;					//size of list
	
	
	public:
	DoubleLinkedList();				//constructor
	~DoubleLinkedList();				//destructor
	bool isEmpty() const;				//determines if list size is 0
	int size() const;				//size constructor
	void pushFront(T value);			//push to front of list. m_front points to it
	void pushBack(T value);				//push to back of list. m_back points to it
	bool removeBack();				//removes back value. adjusts m_back
	bool removeFront();				//removes front value. adjusts m_front
	bool remove(T value);				//removes specific value. adjusts pointers
	void insertAhead(T listValue, T newValue) throw (std::runtime_error);	//inserts ahead of value
	void insertBehind(T listValue, T newValue) throw (std::runtime_error);	//inserts behind a value
	Node<T>* find(T value) const;			//finds a value in the list and returns ptr
	void printList() const;				//prints the list

};

#include "DoubleLinkedList.hpp"
#endif

