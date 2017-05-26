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

void destroy(Book*& tree){
	while(tree != NULL){
		destroy(tree->leftChild);
		destroy(tree->rightChild);
		delete tree;
	}
}

BSTree::~BSTree(){
	destroy(root);
}

void insertRecur(Book*& tree, int num, string name, int price, int count){
	if(tree == NULL){
		tree = new Book();
		tree->num = num;
		tree->name = name;
		tree->price = price;
		tree->count = count;
	}else if(tree->num > num)
		insertRecur(tree->leftChild, num, name, price, count);
	else
		insertRecur(tree->rightChild, num, name, price, count);
}

void BSTree::insert(int num, string name, int price, int count){   // N (신규도서 입고)
	insertRecur(root, num, name, price, count);
}

void removeRecur(Book*& tree, int num){
	if(tree->num > num)
		removeRecur(tree->leftChild, num);
	else if(tree->num < num)
		removeRecur(tree->rightChild, num);
	else{
		Book* temp;
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
			tree->num = temp->num;
			tree->name = temp->name;
			tree->price = temp->price;
			tree->count = temp->count;
			removeRecur(tree->rightChild, tree->num);
		}
	}
}

void BSTree::remove(int num){                    // D (도서 폐기)
	removeRecur(root, num);
}

void plusRecur(Book*& tree, int num, int count){
	if(tree == NULL)
		cout<<"error: 2"<<endl;
	else{
		if(tree->num > num)
			plusRecur(tree->leftChild, num, count);
		else if(tree->num < num)
			plusRecur(tree->rightChild, num, count);
		else if(tree->num == num)
			tree->count += count;
	}
}

void BSTree::plus(int num, int count){                // R (재고도서 목록에 있는 도서 입고)
	plusRecur(root, num, count);
}

void sellRecur(Book*& tree, int num, int count){
	if(tree == NULL)
		cout<<"error: 2"<<endl;
	else{
		if(tree->num > num)
			plusRecur(tree->leftChild, num, count);
		else if(tree->num < num)
			plusRecur(tree->rightChild, num, count);
		else if(tree->num == num){
			if(tree->count < count)
				cout<<"error: 3"<<endl;
			else{
				tree->count -= count;
			}
		}
	}
}

void BSTree::sell(int num, int count){               // S (재고 도서 판매)
	sellRecur(root, num, count);
}

Book searchRecur(Book* tree, int num){
	if(tree->num > num)
		return searchRecur(tree->leftChild, num);
	else if(tree->num < num)
		return searchRecur(tree->rightChild, num);
	else{
		return *tree;
	}
}

Book BSTree::search(int num){                 // I (도서 재고 상태 조회)
	return searchRecur(root, num);
}

void printRecur(Book* tree){
	while(tree != NULL){
		printRecur(tree->leftChild);
		cout<<tree->num<<" "<<tree->name<<" "<<tree->price<<" "<<tree->count<<endl;
		printRecur(tree->rightChild);
	}
}

void BSTree::print(){                    // P (도서 재고상태 오름차순 출력)
	printRecur(root);
}
