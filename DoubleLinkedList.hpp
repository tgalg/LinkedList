/*
	@file DoubleLinkedList.hpp
	@author Tommy Gallagher
	@date 09/26/15
	@DoubleLinkedList implementation
*/

#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_size=0;
	m_front=nullptr;
	m_back=nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{


Node<T>* ptr=m_front;
Node<T>* temp;
while(ptr != NULL)
{
	temp = ptr->getNext();
	delete ptr;
	ptr=temp;
}


}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if(m_size==0)
	{
		return(true);
	}else{
		return(false);
	}
}

template<typename T>
int DoubleLinkedList<T>::size() const
{
	return m_size;
}

template<typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
Node<T>* temp=nullptr;

if(m_size == 0)
{
	m_front=new Node<T>();
	m_front -> setValue(value);
	m_back=m_front;
	m_size=m_size+1;
	
}else if(m_size > 0)
{
	m_size++;
	temp=new Node<T>();
	temp -> setPrevious(nullptr);
	temp -> setNext(m_front);
	temp -> setValue(value);
	m_front=temp;
	
}

}

template<typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
Node<T>* temp=nullptr;
Node<T>* traverse=nullptr;
Node<T>* ptr=nullptr;
if(m_size == 0)
{
	m_front=new Node<T>();
	m_front -> setValue(value);
	m_back=m_front;
	m_size=m_size+1;
}
else if(m_size == 1){

	temp=new Node<T>();
	temp->setValue(value);
	traverse=m_front;
	traverse -> setNext(temp);
	m_back = traverse -> getNext();
	m_size++;
	
}
else 
{
	m_size++;
	traverse=m_front;
	while(traverse->getNext()!=nullptr)
	{
	ptr=traverse;
	traverse=traverse->getNext();
	}
	temp=new Node<T>();
	temp->setValue(value);
	traverse -> setPrevious(ptr);
	traverse->setNext(temp);
	m_back = traverse -> getNext();
	
}
}

template<typename T>
bool DoubleLinkedList<T>::removeBack()
{
Node<T>* temp=nullptr;
Node<T>* traverse=nullptr;
Node<T>* ptr=nullptr;
if(isEmpty())
{
	return(false);
}
else if(m_front -> getNext() == nullptr)
{
	delete m_front;
	m_front=nullptr;
	return(true);
}
else
{
	m_size--;
	temp=m_front;
	traverse=m_front -> getNext();
	while(traverse -> getNext() != nullptr)
	{
	ptr=temp;
	temp=traverse;
	traverse=traverse -> getNext();
	}
	delete traverse;
	traverse = nullptr;
	temp -> setPrevious(ptr);
	temp -> setNext(nullptr);
	m_back = temp;
	return(true);
	}
}

template<typename T>
bool DoubleLinkedList<T>::removeFront()
{
Node<T>* temp=nullptr;
if(isEmpty())
{
	return(false);
}
else
{
	m_size--;
	temp=m_front;
	m_front=m_front -> getNext();
	delete temp;
	temp =nullptr;
	return(true);
	}
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value)
{
Node<T>* t1=find(value);
Node<T>* t2=m_front;
Node<T>* t3=nullptr;

if(isEmpty() || t1==nullptr){

return(false);

}else if(t1==m_front){

return(removeFront());

}else if(t1==m_back){

return(removeBack());

}else{

while(t2 -> getNext() != t1)
{
	t2 = t2 -> getNext();
		
}
t3 = t1 -> getNext();
t1 -> setNext(t3);
t2 -> setNext(t3);
t3 -> setPrevious(t2);
delete t1;
t1=nullptr;
m_size--;
return(true);
}
return(false);
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
Node<T>* t1=find(listValue);
Node<T>* t2=m_front;
Node<T>* t3=nullptr;


cout << "Attempting to insert " << newValue << " ahead of " << listValue << "\n";
if(isEmpty()){

	throw runtime_error("List is empty.");

}
if(t1==nullptr){

	throw runtime_error("Value not on list.");
}
if(t1==m_front){

pushFront(newValue);
cout << newValue << " inserted ahead of " << listValue;
m_size++;

}else{

while(t2 -> getNext() != t1)
{
	t2 = t2 -> getNext();
		
}
t3 = new Node<T>();
t3 -> setValue(newValue);
t3 -> setPrevious(t2);
t3 -> setNext(t1);
t2 -> setNext(t3);
t1 -> setPrevious(t3);

m_size++;

cout << newValue << " inserted ahead of " << listValue;
}



}

template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
Node<T>* t1=find(listValue);
Node<T>* t2=m_front;
Node<T>* t3=nullptr;


cout << "Attempting to insert " << newValue << " behind " << listValue << "\n";
if(isEmpty()){

	throw runtime_error("List is empty.");

}
if(t1==nullptr){

	throw runtime_error("Value not on list.");
}
if(t1==m_back){

pushBack(newValue);
cout << newValue << " inserted behind " << listValue;
m_size++;

}else{
t1=t1 -> getNext();
while(t2 -> getNext() != t1)
{
	t2 = t2 -> getNext();
		
}
t3 = new Node<T>();
t3 -> setValue(newValue);
t3 -> setPrevious(t2);
t3 -> setNext(t1);
t2 -> setNext(t3);

m_size++;

cout << newValue << " inserted behind " << listValue;
}



}

template<typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
Node<T>* temp=nullptr;
Node<T>* traverse=nullptr;
traverse=m_front;
if(isEmpty())
{
	return(temp);
} 
while(traverse != nullptr)
{
	if(traverse -> getValue() == value)
	{
	return(traverse);
	}
	traverse = traverse -> getNext();
}
return(temp);
}

template<typename T>
void DoubleLinkedList<T>::printList() const
{

	Node<T>* traverse=nullptr;
	traverse=m_front;
	while(traverse != nullptr)
	{
	std::cout << traverse -> getValue() << "\n";
	traverse = traverse -> getNext();
	}
}

