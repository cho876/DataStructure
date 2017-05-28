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
	void insert(int, string, int, int);   // N (�űԵ��� �԰�)
	void insertSell(int, string, int, int);   // �Ǹŵ��� ����Ʈ���� ����
	void remove(int);                    // D (���� ���)
	void plus(int, int);                // R (����� ��Ͽ� �ִ� ���� �԰�)
	bool sell(int, int);               // S (��� ���� �Ǹ�)
	Book search(int);                 // I (���� ��� ���� ��ȸ)
	void print();                    // P (���� ������ �������� ���)
	void print_sell();              // L (���� �ǸŸ�� �������� ���)
private:
	Book* root;
	Book* sell_root;
};

#endif /* BSTREE_H_ */
