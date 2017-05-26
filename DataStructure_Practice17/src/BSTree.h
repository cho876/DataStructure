/*
 * BSTree.h
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include <string>

using namespace std;

struct Book{
	int num;
	string name;
	int price;
	int count;
	Book* leftChild;
	Book* rightChild;
};

class BSTree{
public:
	BSTree();
	~BSTree();
	void insert(int, string, int, int);   // N (신규도서 입고)
	void remove(int);                    // D (도서 폐기)
	void plus(int, int);                // R (재고도서 목록에 있는 도서 입고)
	void sell(int, int);               // S (재고 도서 판매)
	Book search(int);                 // I (도서 재고 상태 조회)
	void print();                    // P (도서 재고상태 오름차순 출력)
private:
	Book* root;
};

#endif /* BSTREE_H_ */
