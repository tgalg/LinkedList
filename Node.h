/*
	@file Node.h
	@author Tommy Gallagher
	@date 09/26/15
	@Node header file
*/

#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>

class Node
{
	private:
	T m_value;				//value of type T
	Node<T>* m_previous;			//pointer to previous node
	Node<T>* m_next;			//pointer to next node
	
	public:
	Node();					//constructor	
	void setValue(T val);			//Node value setter
	int getValue()const;			//Node value getter
	void setPrevious(Node<T>* prev);	//prev node pointer setter
	Node<T>* getPrevious()const;		//prev node pointer getter
	void setNext(Node<T>* next);		//next node pointer setter
	Node<T>* getNext()const;		//next node pointer getter
};

#include "Node.hpp"
#endif
