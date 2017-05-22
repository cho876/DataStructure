/*
 * BinarySearch.h
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#include <iostream>

using namespace std;

template <class T>
struct BSNode{
	T info;
	BSNode<T>* rightNext;
	BSNode<T>* leftNext;
};

template <class T>
class BinarySearch{
public:
	BinarySearch();
	~BinarySearch();
	void insertItem(T item);      // Create data
	void deleteItem(T item);      // Remove data
	T searchItem(T item);         // Find data
	int getCount();               // Return total Nods's count
	void printAll();              // Print all Nodes (오름차순)

private:
	BSNode<T>* root;              // For indicate root
	int nodeCount;                // For count total Nodes
};

template <class T>
BinarySearch<T>::BinarySearch(){
	root = NULL;
	nodeCount = 0;
}

template <class T>
BinarySearch<T>::~BinarySearch(){
	Destroy(root);
}

template <class T>
void Destroy(BSNode<T>*& tree){
	if(tree != NULL){
		Destroy(tree->leftNext);
		Destroy(tree->rightNext);
		delete tree;
	}
}

template <class T>
void BinarySearch<T>::insertItem(T item){
	insert(root, item);
	nodeCount++;
}

template <class T>
void insert(BSNode<T>*& tree, T item){
	if(tree == NULL){
		tree = new BSNode<T>;
		tree->info = item;
		tree->leftNext = NULL;
		tree->rightNext = NULL;
	}else if(item > tree->info)
		insert(tree->rightNext, item);
	else
		insert(tree->leftNext, item);
}

template <class T>
void BinarySearch<T>::deleteItem(T item){
	remove(root, item);
	nodeCount--;
}

template <class T>
void remove(BSNode<T>*& tree, T item){
	if(item > tree->info)
		remove(tree->rightNext, item);
	else if(item < tree->info)
		remove(tree->leftNext, item);
	else{
		BSNode<T>* temp;
		if(tree->leftNext == NULL){
			temp = tree;
			tree = tree->rightNext;
			delete temp;
		}else if(tree->rightNext == NULL){
			temp = tree;
			tree = tree->leftNext;
			delete temp;
		}else{
			temp = tree->rightNext;
			while(temp->leftNext != NULL)
				temp = temp->leftNext;
			tree->info = temp->info;
			remove(tree->rightNext, tree->info);
		}
	}
}

template <class T>
T BinarySearch<T>::searchItem(T item){
	return search(root, item);
}

template <class T>
T search(BSNode<T>* tree, T item){
	T returnValue;

	if(tree == NULL)
		cout<<"tree hasn't data"<<endl;
	else if(item > tree->info)
		return search(tree->rightNext, item);
	else if(item < tree->info)
		return search(tree->leftNext, item);
	else
		returnValue = item;

	return returnValue;
}

template <class T>
void BinarySearch<T>::printAll(){
	printTree(root);
}

template <class T>
void printTree(BSNode<T>*& tree){
	BSNode<T>* location = tree;
	if(location != NULL){
		printTree(location->leftNext);
		cout<<tree->info<<" ";
		printTree(location->rightNext);
	}
}

template <class T>
int BinarySearch<T>::getCount(){
	return nodeCount;
}
#endif /* BINARYSEARCH_H_ */
