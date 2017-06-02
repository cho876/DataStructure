/*
 * BSTree.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

BSTree::BSTree(){   // ������
	root = NULL;
}

void destroy(Student*& tree){       // ����Լ� (�Ҹ�)
	if(tree != NULL){                // ��� root�� ���ŵǱ� ������
		destroy(tree->leftChild);           // ���� root ����
		destroy(tree->rightChild);          // ������ root ����
		delete tree;                        // ��� root ����     (LRV - postorder)
	}
}

BSTree::~BSTree(){       // �Ҹ���
	destroy(root);   // ����Լ� (�Ҹ�)
}

void insertRecur(Student*& tree, string id){   // ����Լ� (����)
	if(tree == NULL){               // leaf ������ ������ ���
		tree = new Student();       // new �����ڸ� ���� Student ��ü ����
		tree->leftChild = NULL;
		tree->rightChild = NULL;    // �¿� Child = NULL
		tree->st_id = id;           // �Ű������� ���� id ����
	}
	else if(id > tree->st_id)           // �����ϰ��� �ϴ� id�� root�� id���� Ŭ ���
		insertRecur(tree->rightChild, id);      // rightChild�� �̵�
	else                                // �����ϰ��� �ϴ� id�� root�� id���� ���� ���
		insertRecur(tree->leftChild, id);       // leftChild�� �̵�
}

void BSTree::insert(string id){    // ����  ��� �Լ�
	insertRecur(root, id);      // ����Լ� (����)
}

void removeRecur(Student*& tree, string id){    // ����Լ� (����)
	if(id > tree->st_id)                     // �����ϰ��� �ϴ� id�� root�� id���� Ŭ ���
		removeRecur(tree->rightChild, id);      // rightChild�� �̵�

	else if(id < tree->st_id)                // �����ϰ��� �ϴ� id�� root�� id���� ���� ���
		removeRecur(tree->leftChild, id);       // leftChild�� �̵�

	else{                                   // �����ϰ��� �ϴ� id�� root�� id�� ��ġ�� ���
		Student* temp;            // �����ϰ��� �ϴ� Student�� ���� ������ ���� ����
		if(tree->leftChild == NULL){          // �����ϰ��� �ϴ� root�� leftChild�� ���� ���
			temp = tree;                  // �����ϰ��� �ϴ� root�� temp�� ���� ��
			tree = tree->rightChild;            // root�� root�� rightChild�� �缳��
			delete temp;                  // �����ϰ��� �ϴ� root ����
		}
		else if(tree->rightChild == NULL){     // �����ϰ��� �ϴ� root�� rightChild�� ���� ���
			temp = tree;                  // �����ϰ��� �ϴ� root�� temp�� ���� ��
			tree = tree->leftChild;             // root�� root�� leftChild�� �缳��
			delete temp;                   // �����ϰ��� �ϴ� root ����
		}
		else{                             // �����ϰ��� �ϴ� root�� �¿� child�� ��� ���� ���
			temp = tree->rightChild;          // temp�� ���� root�� rightChild�� ����Ű���� ��
			while(temp->leftChild != NULL)      // rightChild�� ����Ű�� temp�� leftChild�� NULL�� �ƴ� ������
				temp = temp->leftChild;       // temp�� leftChild�� �̵�
			tree->st_id = temp->st_id;       // ���� leftChild�� ���� �����ϰ��� �ϴ� root�� ������ ��ü
			removeRecur(tree->rightChild, tree->st_id);    // ����Լ� (����) ����
		}
	}
}

void BSTree::remove(string id){   // ���� ��� �Լ�
	removeRecur(root, id);    // ����Լ� (����)
}

void printRecur(Student* tree){    // ����Լ� (���) - ��������
	if(tree == NULL){}
	else{                      // root�� NULL�� �ƴ϶��
		printRecur(tree->leftChild);      // ���� ���� root ���
		cout<<tree->st_id<<" ";           // ��� root ���
		printRecur(tree->rightChild);     // ������ root ���       (LVR - inorder)
	}
}

void BSTree::print(){      // ��� ��� �Լ�
	printRecur(root);   // ����Լ� (���)
	cout<<endl;
}

int sizeRecur(Student* tree){    // ����Լ� (ũ�� ��ȯ)
	if(tree == NULL)   // root�� 0�̶�� 0 ��ȯ
		return 0;
	else{              // �ֻ��� root�� �������� ��� leftChild, rightChild�� ���� �� ��ȯ
		return 1 + sizeRecur(tree->leftChild) +	sizeRecur(tree->rightChild);
	}

}
int BSTree::size() const{    // �� Node �� ��ȯ �Լ�
	return sizeRecur(root);    // ����Լ�(ũ�� ��ȯ)
}


