/*
 * ���� ����
 *
 * 	1���� n���� ��ȣ�� �ٿ��� n���� ������� �ð�������� ���ʴ�� �������̺� �ɾ� �ִ�.
 * 	s�� j�� �־��� ��, ��ȣ�� s�� ������� �����Ͽ� �ð�������� j��° ����� ���ܽ�Ų��.
 * 	�׸��� ���ܵ� ��� �������� �����Ͽ� j��° ����� ���ܽ�Ų��. �� ������ �ݺ��Ѵ�.
	n, s, j�� k(���ܵǴ� ������� ��)�� �־��� ��, ���ܵǴ� k���� ������� ��ȣ�� ���ʴ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 */

#include <iostream>

using namespace std;

typedef int Itemtype;

struct Node{          // Node = ���
	Itemtype info;    // ���� ���� ��� ������� ���� ����
	Node* next;
};

class Circular{

	Node* tail;          // ���� ����Ʈ�� ���� ���� �κ��� ����Ű�� pointer
	Node* currentPos;    // ���縦 ����Ű�� pointer

public:
	Circular();      // ���� ����Ʈ ������
	bool isEmpty();   // ���� ����Ʈ�� ����ִ��� Ȯ��
	void insertTail(Itemtype item);
	int remove(Itemtype item);         // item�� �ش��ϴ� Node ����
	void setStartPoint(int start);    // ó�� tail���� start��° Node(���)�� �̵�
	Itemtype moveNode(int finish);   // ����, finish��° ��ŭ Node(���) ��� �̵�
};

Circular::Circular(){        // ���� ����Ʈ ������
	tail = NULL;
	currentPos = NULL;
}


bool Circular::isEmpty(){    // ���� ����Ʈ�� ����ִ��� Ȯ��
	return tail == NULL;
}

void Circular::insertTail(Itemtype item){  // ���� ����Ʈ�� �Ĺ̺κп� item�� ���� Node ����
	Node* newNode = new Node();   // ���ο� Node(���) ����
	newNode->info = item;     // Node(���)�� info(����) ����

	if(tail == NULL){   // ���� ó������ ���Ե��� ���
		tail = newNode;    // ���� ������ Node�� tail�� �Ǹ�
		tail->next = tail;   // ���� ����Ʈ �̹Ƿ� tail�� next�� �ڱ� �ڽ��� ����Ű�� ��
	}else{                             // �����ϴ� ���� ó���� �ƴ� ���
		newNode->next = tail->next;    // ���� ������ Node�� ������ ������ tail�� ����Ű�� next�� ����Ŵ
		tail->next = newNode;         // ������ tail�� next�� ���� ���� Node�� ����Ű�� ����
		tail = newNode;             // ����, ���� ���� newNode�� ���Ӱ� tail�ν� ����
	}
}

int Circular::remove(Itemtype item){     // item(����)�� �ش��ϴ� ���� ���� Node(���)�� ����
	Node* location = tail;        // location�̶�� Node�� tail�� ����Ŵ
	Node* temp = NULL;            // ������ Node�� ����Ű�� ���� ������ ����
	int index = 0;
	while(location->next->info != item)   // ������ ��, ���� Node�� ���� Node�� �����ؾ�������
		location = location->next;        // ���� ��带 �������� �ݺ��� ����

	if(location->next == tail){           // info�� �ش��ϴ� ���� tail�� ����Ű�� ���� ���
		temp = tail;                     // Node�� �����ϱ� ���� ���� temp = tail
		location->next = tail->next;    // tail�� ���� ����� next = ���� tail�� next
		tail = location;               // tail�� ������ tail�� ���� Node�� ����Ŵ

	}else{                            // �����ϰ��� �ϴ� ��尡 tail�� �ƴ� ���
		temp = location->next;          // �ش� Node�� temp�� ����
		location->next = temp->next;    // ���� Node�� �����ϰ��� �ϴ� Node�� ���� Node�� ����
	}

	currentPos = location->next;        // �����ϰ����ϴ� Node�� ������ currentPos�� ����
	index = temp->info;                 // ������ ��ȯ�ϱ� ���� index = �����ϰ����ϴ� Node�� info(����)
	delete temp;                        // �����ϰ��� �ߴ� temp ���� ����
	return index;                       // ������ Node(���)�� info(����) ��ȯ
}

void Circular::setStartPoint(int start){   // �ʱ� ����� �Է� �� �� ��� °���� �����ϴ����� �Է� ��, �� ����ŭ jump��Ű�� ���� �Լ�
	currentPos = tail;               // currentPos = tail->next(���� ����Ʈ�� �� ��)
	while(start>0){                        // start�� °���� ������ ��� start�� �ݺ�
		currentPos = currentPos->next;     // currentPos n����ŭ �̵�
		--start;
	}
}

Itemtype Circular::moveNode(int finish){   // start��° ���� ���� ����, ����ؼ� finish�� °��ŭ �Ѿ Node(���)�� �̵�
	Node* location = currentPos;
	while(--finish>0)
		location = location->next;
	return location->info;
}

int main(){
	Circular circular;
	Itemtype input;
	int start, finish, cut;

	cin>>input;                     // ����ڷκ��� �� ���� �����Ұ��� �Է� ����
	for(int i=1; i<=input; i++){
	circular.insertTail(i);         // input��ŭ ���� ����Ʈ ����, �� ��, �Ű����� i�� ������ �ش�
	}
	cin>>start>>finish>>cut;       // ����, start��°���� finish��° ��ŭ �Ѿ ����� cut��ŭ ���

	circular.setStartPoint(start);   // start��°���Ϳ� �ش��ϴ� ������� �̵�
	while(cut){                      // cut ��ŭ ����ϴ� ���̹Ƿ� cut�� 0�� �� ������ �ݺ�
		cout<<circular.remove(circular.moveNode(finish))<<" ";    // finish��ŭ �̵��� ����� �����ϰ� �׿� �ش��ϴ� ���� ���
		--cut;
	}
	return 0;
}
