/*
 * ���� ����
 *
 *  ������ ���ᱸ��(linked stack)�� �����ϰ�,
 *  	�̸� �̿��Ͽ� ���� 4�� ������  ���α׷��� �ۼ��Ͻÿ�.
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef char ItemType;

struct Node
{
	ItemType info;
	Node *next;
};

class Stack{
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	void push(ItemType ch);
	ItemType pop();
	ItemType peek();

private:
	Node *topPtr;
};

inline void error(const char *message) {       // error �߻� �� ȣ��
            cout << message << endl;
            exit(1);
}

Stack::Stack(){	topPtr = NULL;}

Stack::~Stack(){delete topPtr;}

bool Stack::isEmpty() const {return topPtr == NULL;}    // Stack�� ����ִ��� �Ǻ�

void Stack::push(ItemType item){    // Stack�� ������ ���� ������ char�� ������ push
	Node *newNode;
	newNode = new Node;
	newNode->info = item;
	newNode->next = topPtr;
	topPtr = newNode;
}

char Stack::pop(){    // Stack�� ������� �ʴٸ� ���� �ֻ��� ������ ��ȯ �� ����
	if(isEmpty())
		error("���� Empty");
    ItemType item;
	Node  *tempPtr;
    item = topPtr->info;
    tempPtr = topPtr;
	topPtr = topPtr ->next;
	delete tempPtr;
    return item;

}

char Stack::peek(){    // Stack�� ������� �ʴٸ� ���� �ֻ��� ������ ��ȯ
	if(isEmpty())
		error("���� Empty");
	return topPtr->info;
}

bool isLeftBracket(char);     // ���� ��ȣ���� �Ǻ� �Լ�
bool isRightBracket(char);    // ������ ��ȣ���� �Ǻ� �Լ�
bool isMatched(char, char);   // ���� ��ȣ�� ������ ��ȣ�� �����ϴ��� �Ǻ� �Լ�

int main()
{
	char symbol;         // ����ڷκ��� �Է� ���� ��
	Stack bracket;        // ��ȣ���� ���� �����Ǵ��� �Ǻ�
	bool balanced = true;
	char openSymbol;     // Stack�� �׿��ִ� ��


	while(cin.get(symbol) && balanced){     // ����ڷκ��� �Է¹��� ���� �ְ� ��ȣ���� ����ؼ� �����ϸ� �ݺ�
		if(isLeftBracket(symbol))        // �Է� ���� ���� ���� ��ȣ���� �Ǻ�
			bracket.push(symbol);
		else if(isRightBracket(symbol))     // �Է� ���� ���� ������ ��ȣ���� �Ǻ�
		{
			if(bracket.isEmpty())         // ������ ��ȣ�� ������ ���� ��ȣ�� ���� ���
				balanced = false;
			else{
				openSymbol = bracket.pop();
				balanced = isMatched(symbol, openSymbol);    // ������ ��ȣ�� ���� ��ȣ ��
			}
		}
	}

	if(!balanced)     // balanced�� false ��, �������� ���� ä�� ���� ��� -1 ���
		cout<<"-1"<<endl;
	else if(bracket.isEmpty())     // Stack�� ���� ������� ��� ��, ��� ��ȣ�� ���� �� ��� 1 ���
		cout<<"1"<<endl;
	else                       // �� ���� ������ ��� ��� -1 ���
		cout<<"-1"<<endl;
	return 0;
}

bool isMatched(char right, char left){    // ���� ��ȣ�� ������ ��ȣ�� �����ϴ��� �Ǻ� �Լ�
	return (((left == '(') && right == ')') ||
			((left == '{') && right == '}') ||
			((left == '[') && right == ']'));
}

bool isLeftBracket(char ch){             // ���� ��ȣ���� �Ǻ� �Լ�
	if((ch == '(') || (ch == '{') || (ch == '['))
		return true;
	else
		return false;
}

bool isRightBracket(char ch){           // ������ ��ȣ���� �Ǻ� �Լ�
	if((ch == ')') || (ch == '}') || (ch == ']'))
			return true;
		else
			return false;
}




