/*
 * CircularList.h
 *
 *  Created on: 2017. 6. 3.
 *      Author: Cho
 */

#ifndef CIRCULARLIST_H_
#define CIRCULARLIST_H_

#include <iostream>

using namespace std;

template <class T>
struct Node{
	T data;
	Node<T>* next;
};

template <class T>
class Circular{
public:
	Circular();
	~Circular();
	bool isEmpty();
	bool isFull();
	void insertItemFront(T item);    // insert data in Front
	void insertItemTail(T item);     // insert data in Tail
	void deleteItemFront();          // delete data in Front
	void deleteItemTail();          // delete data in Tail
	T searchItem(T item);           // search data
	int getSize();                  // return List's size
	void printAll();               // print all List's data

private:
	Node<T>* tail;
	int size;
};

template <class T>
Circular<T>::Circular(){
	tail = NULL;
	size = 0;
}

template <class T>
Circular<T>::~Circular(){}

template <class T>
bool Circular<T>::isFull(){
	try{
		Node<T>* temp = new Node<T>();       // If create new Node, Not Full
		delete temp;
		return false;
	}catch(std::exception){return true;}    // else, Full
	return false;
}

template <class T>
bool Circular<T>::isEmpty(){
	return size == 0;               // If size is 0, Empty
}

template <class T>
void Circular<T>::insertItemFront(T item){
	if(isFull())
		cout<<"is Full"<<endl;

	else{
		Node<T>* newNode = new Node<T>();
		newNode->data = item;
		if(tail == NULL){                    // No data in Circular List
			tail = newNode;
			tail->next = tail;
		}else{                              // else, Insert data in Circular List's front location
			newNode->next = tail->next;
			tail->next = newNode;
		}
		size++;    // size++
	}
}

template <class T>
void Circular<T>::insertItemTail(T item){
	if(isFull())
		cout<<"is Full"<<endl;
	else{
		Node<T>* newNode = new Node<T>();           // No data in Circular List
		newNode->data = item;
		if(tail == NULL){
			tail = newNode;
			tail->next = tail;
		}else{                                 // else, Insert data in Circular List's tail location
			newNode->next = tail->next;
			tail->next = newNode;
			tail = newNode;             // change tail's location
		}
		size++;
	}
}

template <class T>
void Circular<T>::deleteItemFront(){
	if(isEmpty())
		cout<<"Is Empty"<<endl;

	else{
		Node<T>* temp = NULL;
		temp = tail->next;
		tail->next = temp->next;
		size--;
	}
}

template <class T>
void Circular<T>::deleteItemTail(){
	if(isEmpty())
		cout<<"Is Empty"<<endl;

	else{
		Node<T>* temp = NULL;
		Node<T>* loc = tail;
		while(loc->next != tail)
			loc = loc->next;
		temp = loc->next;
		loc->next = temp->next;
		tail = loc;
		size--;
	}
}

template <class T>
T Circular<T>::searchItem(T item){
	Node<T>* loc = tail;
	T key;
	bool found = false;
	do{
		if(loc->data == tail){         //If find search Item, found = true, return value
			item = loc->data;
			found = true;
			break;
		}else
			loc = loc->next;
	}while(loc != tail);

	if(found)                 // If found, return key value
		return key;
	else                    // else, return 0
		return 0;
}

template <class T>
int Circular<T>::getSize(){
	return size;
}

template <class T>
void Circular<T>::printAll(){
	Node<T>* loc = tail->next;      // print Front -> tail
	do{
		cout<<loc->data<<endl;
		loc = loc->next;
	}while(loc != tail->next);
}

#endif /* CIRCULARLIST_H_ */
