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

struct Student{
	string st_id;
	Student* leftChild;
	Student* rightChild;
};

class BSTree{
public:
	BSTree();
	~BSTree();
	void insert(string);
	void remove(string);
	int size() const;
	void print();

private:
	Student* root;
};



#endif /* BSTREE_H_ */
