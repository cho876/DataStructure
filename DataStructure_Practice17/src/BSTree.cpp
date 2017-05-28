/*
 * BSTree.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

BSTree::BSTree(){     // ������
	root = NULL;
}

void destroy(Book*& tree){            // �Ҹ���
	while(tree != NULL){                // ��� root�� ���ŵǱ� ������
		destroy(tree->leftChild);           // ���� root ����
		destroy(tree->rightChild);          // ������ root ����
		delete tree;                        // ��� root ����     (LRV - postorder)
	}
}

BSTree::~BSTree(){       // �Ҹ���
	destroy(root);   // ����Լ� (�Ҹ�)
}

void insertRecur(Book*& tree, int num, string name, int price, int count){   // ��� �Լ� (����)
	if(tree == NULL){               // leaf ������ ������ ���
		tree = new Book();        // new �����ڸ� ���� Book ��ü ����
		tree->num = num;          // ���� ���� ��ȣ ����
		tree->name = name;        // ���� ���� �̸� ����
		tree->price = price;      // ���� ���� ���� ����
		tree->count = count;      // ���� ���� ���� ����
	}else if(tree->num > num)         //  ���� root�� ���� ��ȣ > �����ϰ��� �ϴ� ���� ��ȣ�� ���
		insertRecur(tree->leftChild, num, name, price, count);     // leftChild�� �̵� �� ���
	else if(tree->num < num)          // ���� root�� ������ȣ < �����ϰ��� �ϴ� ���� ��ȣ�� ���
		insertRecur(tree->rightChild, num, name, price, count);    // rightChild�� �̵� �� ���
	else
		cout<<"error: 1"<<endl;    // �����ϰ��� �ϴ� ���� ��ȣ�� ���� ������ �̹� ������ ���
}

void BSTree::insert(int num, string name, int price, int count){   // N (�űԵ��� �԰�)
	insertRecur(root, num, name, price, count);   // ��� �Լ� (����) ����
}
void plusRecur(Book*& tree, int num, int count){   // ��� �Լ� (�߰�)
	if(tree == NULL)         // ������ȣ�� ������ ����� ��Ͽ� ���� ���
		cout<<"error: 2"<<endl;
	else{                    // ���� ��ȣ�� ������ ����� ��Ͽ� ���� ���
		if(tree->num > num)        // ���� root�� ���� ��ȣ > �߰��ϰ��� �ϴ� ���� ��ȣ�� ���
			plusRecur(tree->leftChild, num, count);   // leftChild�� �̵� �� ���
		else if(tree->num < num)     // ���� root�� ���� ��ȣ < �߰��ϰ��� �ϴ� ���� ��ȣ�� ���
			plusRecur(tree->rightChild, num, count);  // rightChild�� �̵� �� ���
		else if(tree->num == num){       // �߰��ϰ��� �ϴ� ���� ��ȣ ã���� ���
			tree->count += count;        // ���� ���� �߰�
		}
	}
}

void insertSellRecur(Book*& tree, int num, string name, int price, int count){     // ��� �Լ�(�Ǹ� ���� ����)
	if(tree == NULL){               // leaf ������ ������ ���
		tree = new Book();        // new �����ڸ� ���� Book ��ü ����
		tree->num = num;          // ���� ���� ��ȣ ����
		tree->name = name;        // ���� ���� �̸� ����
		tree->price = price;      // ���� ���� ���� ����
		tree->count = count;      // ���� ���� ���� ����
	}else if(tree->num > num)         //  ���� root�� ���� ��ȣ > �����ϰ��� �ϴ� ���� ��ȣ�� ���
		insertSellRecur(tree->leftChild, num, name, price, count);      // leftChild�� �̵� �� ���
	else if(tree->num < num)          // ���� root�� ������ȣ < �����ϰ��� �ϴ� ���� ��ȣ�� ���
		insertSellRecur(tree->rightChild, num, name, price, count);     // rightChild�� �̵� �� ���
	else                              // �����ϰ��� �ϴ� ���� ��ȣ�� ���� ������ �̹� ������ ���
		plusRecur(tree, num, count);   // ���� ������ �߰�
}

void BSTree::insertSell(int num, string name, int price, int count){   // �Ǹŵ� ���� ����
	insertSellRecur(root, num, name, price, count);     // ��� �Լ�(�Ǹ� ���� ����) ����
}

void removeRecur(Book*& tree, int num){     // ��� �Լ�(����)
	if(tree->num > num)              // ���� root�� ���� ��ȣ > �����ϰ��� �ϴ� ���� ��ȣ�� ���
		removeRecur(tree->leftChild, num);     // leftChild�� �̵� �� ���

	else if(tree->num < num)         // ���� root�� ���� ��ȣ < �����ϰ��� �ϴ� ���� ��ȣ�� ���
		removeRecur(tree->rightChild, num);    // rightChild�� �̵� �� ���

	else{                            // �����ϰ��� �ϴ� ���� ��ȣ�� ã�� ���
		Book* temp;
		if(tree->leftChild == NULL){          // �����ϰ��� �ϴ� root�� leftChild�� NULL�� ���
			temp = tree;          // temp = �����ϰ��� �ϴ� root
			tree = tree->rightChild;   // ���� root = ���� root�� rightChild�� �̵�
			delete temp;          // �ش� root ����
		}
		else if(tree->rightChild == NULL){    // �����ϰ��� �ϴ� root�� rightChild�� NULL�� ���
			temp = tree;          // temp = �����ϰ��� �ϴ� root
			tree = tree->leftChild;     // ���� root = ���� root�� leftChild�� �̵�
			delete temp;          // �ش� root ����
		}
		else{                     // �����ϰ��� �ϴ� root�� leftChild�� rightChild�� ��� ���� ���
			temp = tree->rightChild;           // temp = ���� root�� rightChild
			while(temp->leftChild != NULL)            // rightChild�� �̵��� temp�� leftChild�� NULL�� ������ �̵�
				temp = temp->leftChild;
			tree->num = temp->num;            // ���� leftChild�� ���� tree�� ����
			tree->name = temp->name;
			tree->price = temp->price;
			tree->count = temp->count;
			removeRecur(tree->rightChild, tree->num);   // ����Լ� (����)
		}
	}
}

void BSTree::remove(int num){                    // D (���� ���)
	removeRecur(root, num);     //��� �Լ� (����) ����
}



void BSTree::plus(int num, int count){                // R (����� ��Ͽ� �ִ� ���� �԰�)
	plusRecur(root, num, count);    // ��� �Լ�(�߰�) ����
}

bool sellRecur(Book*& tree, int num, int count){      // ����Լ� (�Ǹ�)
	if(tree == NULL){
		cout<<"error: 2"<<endl;   // �Էµ� ���� ��ȣ�� ����Ͽ� ���� ���
		return false;
	}
	else{
		if(tree->num > num)    //  ���� root�� ���� ��ȣ > �����ϰ��� �ϴ� ���� ��ȣ�� ���
			return sellRecur(tree->leftChild, num, count);    // leftChild�� �̵� �� ���

		else if(tree->num < num)    //  ���� root�� ���� ��ȣ < �����ϰ��� �ϴ� ���� ��ȣ�� ���
			return sellRecur(tree->rightChild, num, count);   // rightChild�� �̵� �� ���

		else if(tree->num == num){           // �Ǹ��ϰ��� �ϴ� ������ ����Ͽ��� ã�� ���
			if(tree->count < count){        // �Ǹż����� ���������� ���� ���
				cout<<"error: 3"<<endl;
				return false;
			}
			else{                       // ��� ���� ���� ��, �Ǹ� ��, count ����
				tree->count -= count;
				return true;
			}
		}
	}
	return true;
}

bool BSTree::sell(int num, int count){               // S (��� ���� �Ǹ�)
	return sellRecur(root, num, count);    // ����Լ�(�Ǹ�) ����
}

Book searchRecur(Book* tree, int num){         // ����Լ� (�˻�)
	if(tree == NULL){}
	else if(tree->num > num)         //  ���� root�� ���� ��ȣ > �����ϰ��� �ϴ� ���� ��ȣ�� ���
		return searchRecur(tree->leftChild, num);    // leftChild�� �̵� �� ���
	else if(tree->num < num)         //  ���� root�� ���� ��ȣ < �����ϰ��� �ϴ� ���� ��ȣ�� ���
		return searchRecur(tree->rightChild, num);   // rightChild�� �̵� �� ���
	else
		return *tree;            // �˻� ��� Book ���� ��ȯ
}

Book BSTree::search(int num){                 // I (���� ��� ���� ��ȸ)
	return searchRecur(root, num);    // ��� �Լ�(�˻�) ����
}

void printRecur(Book* tree){            // ����Լ� (���) - ��������
	if(tree == NULL){}
	else{
		printRecur(tree->leftChild);           // Left ���
		cout<<tree->num<<" "<<tree->name<<" "<<tree->price<<" "<<tree->count<<endl;    // ��� ���
		printRecur(tree->rightChild);          // right ���     (LVR - inorder)
	}
}

void BSTree::print(){                    // P (���� ������ �������� ���)
	printRecur(root);          // ����Լ� (���) ����
}

