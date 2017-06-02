/*
 * BSTree.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

BSTree::BSTree(){   // 생성자
	root = NULL;
}

void destroy(Student*& tree){       // 재귀함수 (소멸)
	if(tree != NULL){                // 모든 root가 제거되기 전까지
		destroy(tree->leftChild);           // 왼쪽 root 제거
		destroy(tree->rightChild);          // 오른쪽 root 제거
		delete tree;                        // 가운데 root 제거     (LRV - postorder)
	}
}

BSTree::~BSTree(){       // 소멸자
	destroy(root);   // 재귀함수 (소멸)
}

void insertRecur(Student*& tree, string id){   // 재귀함수 (삽입)
	if(tree == NULL){               // leaf 하위에 도달할 경우
		tree = new Student();       // new 생성자를 통한 Student 객체 생성
		tree->leftChild = NULL;
		tree->rightChild = NULL;    // 좌우 Child = NULL
		tree->st_id = id;           // 매개변수로 받은 id 저장
	}
	else if(id > tree->st_id)           // 삽입하고자 하는 id가 root의 id보다 클 경우
		insertRecur(tree->rightChild, id);      // rightChild로 이동
	else                                // 삽입하고자 하는 id가 root의 id보다 작을 경우
		insertRecur(tree->leftChild, id);       // leftChild로 이동
}

void BSTree::insert(string id){    // 삽입  기능 함수
	insertRecur(root, id);      // 재귀함수 (삽입)
}

void removeRecur(Student*& tree, string id){    // 재귀함수 (삭제)
	if(id > tree->st_id)                     // 제거하고자 하는 id가 root의 id보다 클 경우
		removeRecur(tree->rightChild, id);      // rightChild로 이동

	else if(id < tree->st_id)                // 제거하고자 하는 id가 root의 id보다 작을 경우
		removeRecur(tree->leftChild, id);       // leftChild로 이동

	else{                                   // 제거하고자 하는 id와 root의 id가 일치할 경우
		Student* temp;            // 제거하고자 하는 Student를 담을 포인터 변수 생성
		if(tree->leftChild == NULL){          // 제거하고자 하는 root의 leftChild가 없을 경우
			temp = tree;                  // 제거하고자 하는 root를 temp에 담은 뒤
			tree = tree->rightChild;            // root를 root의 rightChild로 재설정
			delete temp;                  // 제거하고자 하는 root 제거
		}
		else if(tree->rightChild == NULL){     // 제거하고자 하는 root의 rightChild가 없을 경우
			temp = tree;                  // 제거하고자 하는 root를 temp에 담은 뒤
			tree = tree->leftChild;             // root를 root의 leftChild로 재설정
			delete temp;                   // 제거하고자 하는 root 제거
		}
		else{                             // 제거하고자 하는 root의 좌우 child가 모두 있을 경우
			temp = tree->rightChild;          // temp는 현재 root의 rightChild를 가리키도록 함
			while(temp->leftChild != NULL)      // rightChild를 가리키는 temp의 leftChild가 NULL이 아닐 때까지
				temp = temp->leftChild;       // temp를 leftChild로 이동
			tree->st_id = temp->st_id;       // 가장 leftChild의 값을 제거하고자 하는 root의 값으로 대체
			removeRecur(tree->rightChild, tree->st_id);    // 재귀함수 (삭제) 실행
		}
	}
}

void BSTree::remove(string id){   // 삭제 기능 함수
	removeRecur(root, id);    // 재귀함수 (삭제)
}

void printRecur(Student* tree){    // 재귀함수 (출력) - 오름차순
	if(tree == NULL){}
	else{                      // root가 NULL이 아니라면
		printRecur(tree->leftChild);      // 가장 왼쪽 root 출력
		cout<<tree->st_id<<" ";           // 가운데 root 출력
		printRecur(tree->rightChild);     // 오른쪽 root 출력       (LVR - inorder)
	}
}

void BSTree::print(){      // 출력 기능 함수
	printRecur(root);   // 재귀함수 (출력)
	cout<<endl;
}

int sizeRecur(Student* tree){    // 재귀함수 (크기 반환)
	if(tree == NULL)   // root가 0이라면 0 반환
		return 0;
	else{              // 최상위 root를 기준으로 모든 leftChild, rightChild를 더한 후 반환
		return 1 + sizeRecur(tree->leftChild) +	sizeRecur(tree->rightChild);
	}

}
int BSTree::size() const{    // 총 Node 수 반환 함수
	return sizeRecur(root);    // 재귀함수(크기 반환)
}


