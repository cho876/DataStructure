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

struct Student{     // 학생 정보
	string st_id;        // 학번
	Student* leftChild;   // 왼쪽 연결 포인터
	Student* rightChild;   // 오른쪽 연결 포인터
};

class BSTree{    // Binary Search tree
public:
	BSTree();    // 생성자
	~BSTree();   // 소멸자
	void insert(string);    // 삽입 함수
	void remove(string);    // 제거 함수
	int size() const;       // 총 크기 반환 함수
	void print();           // 총 data 출력 함수 (오름차순)

private:
	Student* root;        // root 저장 변수
};

#endif /* BSTREE_H_ */
