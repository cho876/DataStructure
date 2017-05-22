/*
 * Queue.h
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

using namespace std;

template <class T>
struct Node{
	T info;
	Node<T>* next;
};

template <class T>
class Queue{
public:
	Queue();
	~Queue();
	bool isEmpty();
	bool isFull();
	void insert(T item);
	void remove();
	T getRear();             // return rear's data
	T getFront();            // return front's data
	int getLength();         // return Node's count
	void printAll();

private:
	Node<T>* front;
	Node<T>* rear;
	int length;
};

template <class T>
Queue<T>::Queue(){
	front = rear = NULL;
	length = 0;
}

template <class T>
Queue<T>::~Queue(){

}

template <class T>
bool Queue<T>::isEmpty(){
	return length == 0;
}

template <class T>
bool Queue<T>::isFull(){
	try{
		Node<T>* newNode = new Node<T>();
		delete newNode;
		return false;
	}catch(std::exception){return true;}
}


template <class T>
void Queue<T>::insert(T item){
	if(isFull())
		return;

	Node<T>* newNode = new Node<T>();
	newNode->info = item;

	if(isEmpty()){                    // If front, rear == NULL, ....
		rear = front = newNode;
	}else{
		rear->next = newNode;
		rear = newNode;
	}
	newNode->next = NULL;
	length++;
}

template <class T>
void Queue<T>::remove(){
	if(isEmpty())
		return;

	Node<T>* temp = front;
	front = front->next;
	delete temp;
	length--;
}

template <class T>
T Queue<T>::getFront(){return front->info;}

template <class T>
T Queue<T>::getRear(){return rear->info;}

template <class T>
int Queue<T>::getLength(){return length;}

template <class T>
void Queue<T>::printAll(){
	if(isEmpty())
		return;

	Node<T>* location = front;
	while(location != NULL){
		cout<<location->info<<" ";
		location = location->next;
	}
}
#endif /* QUEUE_H_ */
