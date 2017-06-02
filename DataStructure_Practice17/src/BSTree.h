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
	string num;           // ���� ��ȣ
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
	void insert(string, string, int, int);   // N (�űԵ��� �԰�)
	void insertSell(string, string, int, int);   // �Ǹŵ��� ����Ʈ���� ����
	void remove(string);                    // D (���� ���)
	void plus(string, int);                // R (����� ��Ͽ� �ִ� ���� �԰�)
	bool sell(string, int);               // S (��� ���� �Ǹ�)
	Book search(string, bool&);                 // I (���� ��� ���� ��ȸ)
	void print();                    // P (���� ������ �������� ���)
private:
	Book* root;            // root
};

#endif /* BSTREE_H_ */
