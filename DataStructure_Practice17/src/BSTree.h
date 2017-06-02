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

struct Book{   //도서 정보
	string num;           // 도서 번호
	string name;       // 도서 이름
	int price;         // 도서 가격
	int count;         // 도서 수량
	Book* leftChild;
	Book* rightChild;     // 좌우 Child
};

class BSTree{
public:
	BSTree();      // 생성자
	~BSTree();     // 소멸자
	void insert(string, string, int, int);   // N (신규도서 입고)
	void insertSell(string, string, int, int);   // 판매도서 이진트리에 삽입
	void remove(string);                    // D (도서 폐기)
	void plus(string, int);                // R (재고도서 목록에 있는 도서 입고)
	bool sell(string, int);               // S (재고 도서 판매)
	Book search(string, bool&);                 // I (도서 재고 상태 조회)
	void print();                    // P (도서 재고상태 오름차순 출력)
private:
	Book* root;            // root
};

#endif /* BSTREE_H_ */
