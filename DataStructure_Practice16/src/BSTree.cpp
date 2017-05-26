/*
 * BSTree.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

BSTree::BSTree(){
	root = NULL;
}

void destroy(Student*& tree){
	while(tree != NULL){
		destroy(tree->leftChild);
		destroy(tree->rightChild);
		delete tree;
	}
}

BSTree::~BSTree(){
	destroy(root);
}

void insertRecur(Student*& tree, string id){
	if(tree == NULL){
		tree = new Student();
		tree->leftChild = NULL;
		tree->rightChild = NULL;
		tree->st_id = id;
	}
	else if(id > tree->st_id)
		insertRecur(tree->rightChild, id);
	else
		insertRecur(tree->leftChild, id);
}

void BSTree::insert(string id){
	insertRecur(root, id);
}

void removeRecur(Student*& tree, string id){
	if(id > tree->st_id)
		removeRecur(tree->rightChild, id);
	else if(id < tree->st_id)
		removeRecur(tree->leftChild, id);
	else{
		Student* temp;
		if(tree->leftChild == NULL){
			temp = tree;
			tree = tree->rightChild;
			delete temp;
		}else if(tree->rightChild == NULL){
			temp = tree;
			tree = tree->leftChild;
			delete temp;
		}else{
			temp = tree->rightChild;
			while(temp->leftChild != NULL)
				temp = temp->leftChild;
			tree->st_id = temp->st_id;
			removeRecur(tree->rightChild, tree->st_id);
		}
	}
}

void BSTree::remove(string id){
	removeRecur(root, id);
}

void printRecur(Student* tree){
	if(tree == NULL){}
	else{
		printRecur(tree->leftChild);
		cout<<tree->st_id<<" ";
		printRecur(tree->rightChild);
	}
}

void BSTree::print(){
	printRecur(root);
	cout<<endl;
}

int sizeRecur(Student* tree){
	if(tree == NULL)
		return 0;
	else{
		return 1 + sizeRecur(tree->leftChild) +	sizeRecur(tree->rightChild);
	}

}
int BSTree::size() const{
	return sizeRecur(root);
}
