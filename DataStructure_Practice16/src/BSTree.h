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

struct Student{     // �л� ����
	string st_id;        // �й�
	Student* leftChild;   // ���� ���� ������
	Student* rightChild;   // ������ ���� ������
};

class BSTree{    // Binary Search tree
public:
	BSTree();    // ������
	~BSTree();   // �Ҹ���
	void insert(string);    // ���� �Լ�
	void remove(string);    // ���� �Լ�
	int size() const;       // �� ũ�� ��ȯ �Լ�
	void print();           // �� data ��� �Լ� (��������)

private:
	Student* root;        // root ���� ����
};

#endif /* BSTREE_H_ */
