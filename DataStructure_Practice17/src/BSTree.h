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

struct Book{   //���� ����
	int num;           // ���� ��ȣ
	string name;       // ���� �̸�
	int price;         // ���� ����
	int count;         // ���� ����
	Book* leftChild;
	Book* rightChild;     // �¿� Child
};

class BSTree{
public:
	BSTree();      // ������
	~BSTree();     // �Ҹ���
	void insert(int, string, int, int);   // N (�űԵ��� �԰�)
	void insertSell(int, string, int, int);   // �Ǹŵ��� ����Ʈ���� ����
	void remove(int);                    // D (���� ���)
	void plus(int, int);                // R (����� ��Ͽ� �ִ� ���� �԰�)
	bool sell(int, int);               // S (��� ���� �Ǹ�)
	Book search(int);                 // I (���� ��� ���� ��ȸ)
	void print();                    // P (���� ������ �������� ���)
private:
	Book* root;            // root
};

#endif /* BSTREE_H_ */
