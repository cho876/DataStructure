#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;         // ���� �ִ� ���� ���� : 100
class Stack{

	int top;                      // Stack�� ���� ���� index ��ȣ
	int data[MAX_SIZE];

public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(char ch);
	char pop();
	char peek();
};

inline void error(const char *message) {       // error �߻� �� ȣ��
            cout << message << endl;
            exit(1);
}

Stack::Stack(){	top = -1;}                  // top = -1�� �ʱ�ȭ

Stack::~Stack(){}

bool Stack::isEmpty(){return top == -1;}    // Stack�� ����ִ��� �Ǻ�

bool Stack::isFull(){return top == MAX_SIZE-1;}    // Stack�� ���� á���� �Ǻ�


void Stack::push(char ch){    // Stack�� ������ ���� ������ char�� ������ push
	if(isFull())
		error("���� Full");
	data[++top] = ch;
}

char Stack::pop(){    // Stack�� ������� �ʴٸ� ���� �ֻ��� ������ ��ȯ �� ����
	if(isEmpty())
		error("���� Empty");
	return data[top--];
}

char Stack::peek(){    // Stack�� ������� �ʴٸ� ���� �ֻ��� ������ ��ȯ
	if(isEmpty())
		error("���� Empty");
	return data[top];
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

