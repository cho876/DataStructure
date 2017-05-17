/*
 * test.cpp
 *
 *  Created on: 2017. 5. 17.
 *      Author: Cho
 */
#include <iostream>

using namespace std;

typedef int Itemtype;

struct Node{
	Itemtype info;
	Node* next;
};

class Circular{

	Node* tail;
	Node* currentPos;
	int length;

public:
	Circular();
	bool isEmpty();
	void insertTail(Itemtype item);
	int remove(Itemtype item);
	void setStartPoint(int start);
	Itemtype moveNode(int finish);
	Itemtype peek();
};

Circular::Circular(){
	tail = NULL;
	currentPos = NULL;
	length = 0;
}


bool Circular::isEmpty(){
	return tail == NULL;
}

void Circular::insertTail(Itemtype item){
	Node* newNode = new Node();
	newNode->info = item;

	if(tail == NULL){
		tail = newNode;
		tail->next = tail;
	}else{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

int Circular::remove(Itemtype item){
	Node* location = tail;
	Node* temp = NULL;
	int index = 0;
	while(location->next->info != item)
		location = location->next;
	if(location->next == tail){
		temp = location->next;
		location->next = tail->next;
		tail = location;
	}else{
		temp = location->next;
		location->next = temp->next;
	}
	currentPos = location->next;
	index = temp->info;
	delete temp;
	return index;
}

void Circular::setStartPoint(int start){
	currentPos = tail->next;
	while(start>0){
		currentPos = currentPos->next;
		--start;
	}
}

Itemtype Circular::moveNode(int finish){
	Node* location = currentPos;
	while(--finish>0)
		location = location->next;
	return location->info;
}

int main(){
	Circular circular;
	Itemtype input;
	int start, finish, cut;
	int index = 1;

	cin>>input;
	for(int i=0; i<input; i++){
	circular.insertTail(i);
	}
	cin>>start>>finish>>cut;

	circular.setStartPoint(start);
	while(cut){
		cout<<circular.remove(circular.moveNode(finish))<<" ";
		--cut;
	}
	return 0;
}
