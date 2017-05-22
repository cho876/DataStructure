/*
 * Stack.h
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

using namespace std;

template <class T>
struct Node{
	T item;
	Node<T>* next;
};

template <class T>
class Stack{
public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(T item);           // Insert data
	void pop();                  // Delete data
	T peek();                    // return top's data
	int getLength();             // return length
	void printAll();             // Print All of the Node's data

private:
	Node<T>* top;
	int length;
};

template <class T>
Stack<T>::Stack(){
	length = 0;
	top = NULL;
}

template <class T>
Stack<T>::~Stack(){
	Node<T>* temp = NULL;

	while(top != NULL){
		temp = top;
		top = top->next;
		delete temp;
	}
}

template <class T>
bool Stack<T>::isEmpty(){
	return top == NULL;
}

template <class T>
bool Stack<T>::isFull(){
	try{
		Node<T>* newNode = new Node<T>();
		delete newNode;
		return false;
	}catch(std::exception){return true;}
}

template <class T>
void Stack<T>::push(T item){
	if(isFull())
		return;

	Node<T>* newNode = new Node<T>();
	newNode->item = item;

	if(top == NULL)                   // If top is NULl, ...
		newNode->next = NULL;
	else
		newNode->next = top;

	top = newNode;
	length++;
}

template <class T>
void Stack<T>::pop(){
	if(isEmpty()){
		cout<<"pop ½ÇÇà"<<endl;
		return;
	}
	Node<T>* temp = top;
	top = top->next;
	delete temp;
	length--;
}

template <class T>
T Stack<T>::peek(){
	if(isEmpty())
		return NULL;

	return top->item;
}

template <class T>
int Stack<T>::getLength(){
	return length;
}

template <class T>
void Stack<T>::printAll(){
	if(isEmpty())
		return;

	Node<T>* location = top;
	while(location != NULL){
		cout<<location->item<<" ";
		location = location->next;
	}
}
#endif /* STACK_H_ */
