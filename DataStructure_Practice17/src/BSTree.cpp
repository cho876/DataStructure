/*
 * BSTree.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

BSTree::BSTree(){     // 생성자
	root = NULL;
}

void destroy(Book*& tree){            // 소멸자
	while(tree != NULL){                // 모든 root가 제거되기 전까지
		destroy(tree->leftChild);           // 왼쪽 root 제거
		destroy(tree->rightChild);          // 오른쪽 root 제거
		delete tree;                        // 가운데 root 제거     (LRV - postorder)
	}
}

BSTree::~BSTree(){       // 소멸자
	destroy(root);   // 재귀함수 (소멸)
}

void insertRecur(Book*& tree, int num, string name, int price, int count){   // 재귀 함수 (삽입)
	if(tree == NULL){               // leaf 하위에 도달할 경우
		tree = new Book();        // new 생성자를 통한 Book 객체 생성
		tree->num = num;          // 삽입 도서 번호 저장
		tree->name = name;        // 삽입 도서 이름 저장
		tree->price = price;      // 삽입 도서 가격 저장
		tree->count = count;      // 삽입 도서 수량 저장
	}else if(tree->num > num)         //  현재 root의 도서 번호 > 삽입하고자 하는 도서 번호일 경우
		insertRecur(tree->leftChild, num, name, price, count);     // leftChild로 이동 및 재귀
	else if(tree->num < num)          // 현재 root의 도서번호 < 삽입하고자 하는 도서 번호일 경우
		insertRecur(tree->rightChild, num, name, price, count);    // rightChild로 이동 및 재귀
	else
		cout<<"error: 1"<<endl;    // 삽입하고자 하는 도서 번호와 같은 도서가 이미 존재할 경우
}

void BSTree::insert(int num, string name, int price, int count){   // N (신규도서 입고)
	insertRecur(root, num, name, price, count);   // 재귀 함수 (삽입) 실행
}
void plusRecur(Book*& tree, int num, int count){   // 재귀 함수 (추가)
	if(tree == NULL)         // 도서번호의 도서가 재고도서 목록에 없을 경우
		cout<<"error: 2"<<endl;
	else{                    // 도서 번호의 도서가 재고도서 목록에 있을 경우
		if(tree->num > num)        // 현재 root의 도서 번호 > 추가하고자 하는 도서 번호일 경우
			plusRecur(tree->leftChild, num, count);   // leftChild로 이동 및 재귀
		else if(tree->num < num)     // 현재 root의 도서 번호 < 추가하고자 하는 도서 번호일 경우
			plusRecur(tree->rightChild, num, count);  // rightChild로 이동 및 재귀
		else if(tree->num == num){       // 추가하고자 하는 도서 번호 찾았을 경우
			tree->count += count;        // 도서 수량 추가
		}
	}
}

void insertSellRecur(Book*& tree, int num, string name, int price, int count){     // 재귀 함수(판매 도서 저장)
	if(tree == NULL){               // leaf 하위에 도달할 경우
		tree = new Book();        // new 생성자를 통한 Book 객체 생성
		tree->num = num;          // 삽입 도서 번호 저장
		tree->name = name;        // 삽입 도서 이름 저장
		tree->price = price;      // 삽입 도서 가격 저장
		tree->count = count;      // 삽입 도서 수량 저장
	}else if(tree->num > num)         //  현재 root의 도서 번호 > 삽입하고자 하는 도서 번호일 경우
		insertSellRecur(tree->leftChild, num, name, price, count);      // leftChild로 이동 및 재귀
	else if(tree->num < num)          // 현재 root의 도서번호 < 삽입하고자 하는 도서 번호일 경우
		insertSellRecur(tree->rightChild, num, name, price, count);     // rightChild로 이동 및 재귀
	else                              // 삽입하고자 하는 도서 번호와 같은 도서가 이미 존재할 경우
		plusRecur(tree, num, count);   // 도서 수량만 추가
}

void BSTree::insertSell(int num, string name, int price, int count){   // 판매된 도서 저장
	insertSellRecur(root, num, name, price, count);     // 재귀 함수(판매 도서 저장) 실행
}

void removeRecur(Book*& tree, int num){     // 재귀 함수(제거)
	if(tree->num > num)              // 현재 root의 도서 번호 > 삽입하고자 하는 도서 번호일 경우
		removeRecur(tree->leftChild, num);     // leftChild로 이동 및 재귀

	else if(tree->num < num)         // 현재 root의 도서 번호 < 삽입하고자 하는 도서 번호일 경우
		removeRecur(tree->rightChild, num);    // rightChild로 이동 및 재귀

	else{                            // 제거하고자 하는 도서 번호를 찾을 경우
		Book* temp;
		if(tree->leftChild == NULL){          // 제거하고자 하는 root의 leftChild가 NULL일 경우
			temp = tree;          // temp = 제거하고자 하는 root
			tree = tree->rightChild;   // 현재 root = 현재 root의 rightChild로 이동
			delete temp;          // 해당 root 제거
		}
		else if(tree->rightChild == NULL){    // 제거하고자 하는 root의 rightChild가 NULL일 경우
			temp = tree;          // temp = 제거하고자 하는 root
			tree = tree->leftChild;     // 현재 root = 현재 root의 leftChild로 이동
			delete temp;          // 해당 root 제거
		}
		else{                     // 제거하고자 하는 root의 leftChild와 rightChild가 모두 있을 경우
			temp = tree->rightChild;           // temp = 현재 root의 rightChild
			while(temp->leftChild != NULL)            // rightChild로 이동한 temp의 leftChild가 NULL일 때까지 이동
				temp = temp->leftChild;
			tree->num = temp->num;            // 가장 leftChild의 정보 tree에 저장
			tree->name = temp->name;
			tree->price = temp->price;
			tree->count = temp->count;
			removeRecur(tree->rightChild, tree->num);   // 재귀함수 (삭제)
		}
	}
}

void BSTree::remove(int num){                    // D (도서 폐기)
	removeRecur(root, num);     //재귀 함수 (삭제) 실행
}



void BSTree::plus(int num, int count){                // R (재고도서 목록에 있는 도서 입고)
	plusRecur(root, num, count);    // 재귀 함수(추가) 실행
}

bool sellRecur(Book*& tree, int num, int count){      // 재귀함수 (판매)
	if(tree == NULL){
		cout<<"error: 2"<<endl;   // 입력된 도서 번호가 재고목록에 없을 경우
		return false;
	}
	else{
		if(tree->num > num)    //  현재 root의 도서 번호 > 삽입하고자 하는 도서 번호일 경우
			return sellRecur(tree->leftChild, num, count);    // leftChild로 이동 및 재귀

		else if(tree->num < num)    //  현재 root의 도서 번호 < 삽입하고자 하는 도서 번호일 경우
			return sellRecur(tree->rightChild, num, count);   // rightChild로 이동 및 재귀

		else if(tree->num == num){           // 판매하고자 하는 도서를 재고목록에서 찾을 경우
			if(tree->count < count){        // 판매수량이 재고수량보다 많을 경우
				cout<<"error: 3"<<endl;
				return false;
			}
			else{                       // 모든 조건 만족 시, 판매 후, count 감소
				tree->count -= count;
				return true;
			}
		}
	}
	return true;
}

bool BSTree::sell(int num, int count){               // S (재고 도서 판매)
	return sellRecur(root, num, count);    // 재귀함수(판매) 실행
}

Book searchRecur(Book* tree, int num){         // 재귀함수 (검색)
	if(tree == NULL){}
	else if(tree->num > num)         //  현재 root의 도서 번호 > 삽입하고자 하는 도서 번호일 경우
		return searchRecur(tree->leftChild, num);    // leftChild로 이동 및 재귀
	else if(tree->num < num)         //  현재 root의 도서 번호 < 삽입하고자 하는 도서 번호일 경우
		return searchRecur(tree->rightChild, num);   // rightChild로 이동 및 재귀
	else
		return *tree;            // 검색 결과 Book 정보 반환
}

Book BSTree::search(int num){                 // I (도서 재고 상태 조회)
	return searchRecur(root, num);    // 재귀 함수(검색) 실행
}

void printRecur(Book* tree){            // 재귀함수 (출력) - 오름차순
	if(tree == NULL){}
	else{
		printRecur(tree->leftChild);           // Left 출력
		cout<<tree->num<<" "<<tree->name<<" "<<tree->price<<" "<<tree->count<<endl;    // 가운데 출력
		printRecur(tree->rightChild);          // right 출력     (LVR - inorder)
	}
}

void BSTree::print(){                    // P (도서 재고상태 오름차순 출력)
	printRecur(root);          // 재귀함수 (출력) 실행
}

