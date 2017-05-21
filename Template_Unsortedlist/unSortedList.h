#ifndef UNSORTEDLIST_H_
#define UNSORTEDLIST_H_

#include <iostream>

using namespace std;

//typedef int ItemType;
template <class ItemType>
struct Node{
	ItemType info;
	Node<ItemType>* next;
};

template <class ItemType>
class unSortedList{
public:
	unSortedList();
	~unSortedList();
	bool isEmpty();
	bool isFull();
	void insertItem(ItemType item);        // Node insert
	void removeItem(ItemType item);        // Node remove
	ItemType getItem(ItemType item, bool found);       // get Node->infp
	int getLength();                       // get total Length
	void printAll();

private:
	Node<ItemType>* head;
	int length;
};

template <class ItemType>
unSortedList<ItemType>::unSortedList(){
	head = NULL;
	length = 0;
}

template <class ItemType>
unSortedList<ItemType>::~unSortedList(){
	Node<ItemType>* temp;

	while(head != NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <class ItemType>
bool unSortedList<ItemType>::isEmpty(){
	return head == NULL;                   // If head == NUll, return true else false;
}

template <class ItemType>
bool unSortedList<ItemType>::isFull(){
	try{
		Node<ItemType>* temp;               // If you can create new Node, return false;
		delete temp;
		return false;
	}catch(std::exception e){              // If you can't create new Node, return true;
		return true;
	}
}

template <class ItemType>
void unSortedList<ItemType>::insertItem(ItemType item){
	if(isFull())
		return;

	Node<ItemType>* newNode;
	newNode = new Node<ItemType>();
	newNode->info = item;
	newNode->next = head;
	head = newNode;
	length++;
}

template <class ItemType>
void unSortedList<ItemType>::removeItem(ItemType item){
	if(isEmpty())
		return;

	Node<ItemType>* location = head;
	Node<ItemType>* target = NULL;          // target Node (perpose: remove)

	if(head->info == item){           // If head->info == item, remove head & head = head->next (change)
			target = head;
			head = head->next;
	}else{
		while(location->next->info != item)
			location = location->next;
		target = location->next;
		location->next = target->next;
	}
	delete target;
	length--;
}

template <class ItemType>
ItemType unSortedList<ItemType>::getItem(ItemType item, bool found){
	if(isEmpty())
		return 0;

	Node<ItemType>* location = head;

	while(location != NULL && !found){
		if(location->info == item){
			found = true;
			return location->info;
		}else
			location = location->next;
	}
	return location->info;
}

template <class ItemType>
int unSortedList<ItemType>::getLength(){
	return length;
}

template <class ItemType>
void unSortedList<ItemType>::printAll(){
	Node<ItemType>* location = head;

	while(location != NULL){
		cout<<location->info<<" ";
		location = location->next;
	}
}
#endif /* UNSORTEDLIST_H_ */
