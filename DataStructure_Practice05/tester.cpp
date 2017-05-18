/*
 * 	���� ����
 *
 * 	�Է����� ������ ��ȣ�� (,),{,},[,]�� ���Ͽ�, ��� ��ȣ�� ¦�� �´� ��� 1�� ����ϰ�,
 * 	�׷��� ������ ��ȣ�˻� �˰��� ���Ͽ� ó������ �߰ߵ� (¦�� ���� ���� ��ȣ) ������ ���Ͽ�, ���� �� �ϳ��� ����Ѵ�.

	)�� �����ϴ� (�� ���� ���: error 1
	}�� �����ϴ� {�� ���� ���: error 2
	]�� �����ϴ� [�� ���� ���: error 3
	(�� �����ϴ� )�� ���� ���: error 4
	{�� �����ϴ� }�� ���� ���: error 5
	[�� �����ϴ� ]�� ���� ���: error 6
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

class Stack{
	int top;
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

inline void error(const char *message) {
            cout << message << endl;
            exit(1);
}
Stack::Stack(){	top = -1;}

Stack::~Stack(){}

bool Stack::isEmpty(){return top == -1;}

bool Stack::isFull(){return top == MAX_SIZE-1;}


void Stack::push(char ch){
	if(isFull())
		error("���� Full");
	data[++top] = ch;
}

char Stack::pop(){
	if(isEmpty())
		error("���� Empty");
	return data[top--];
}

char Stack::peek(){
	if(isEmpty())
		error("���� Empty");
	return data[top];
}

bool isLeftBracket(char);
bool isRightBracket(char);
bool isMatched(char, char);
void Check_R(char);
void Check_L(char);
bool checkSmall_L(char);
bool checkMedium_L(char);
bool checkBig_L(char);

int main()
{
	Stack bracket;
	bool balanced = true;
	char symbol;
	char openSymbol;


	while(cin.get(symbol) && balanced){
			if(isLeftBracket(symbol)){
				bracket.push(symbol);
			}
			else if(isRightBracket(symbol))
			{
				if(bracket.isEmpty()){    // Stack�� ����� ��� ¦�� ���� �ʴ� ���ȣ üũ
					Check_R(symbol);
					balanced = false;
				}
				else{
				openSymbol = bracket.pop();
				balanced = isMatched(symbol, openSymbol);  // �ҷ��帰 symbol(�ް�ȣ)�� Stack���� �޾ƿ� openSymbol(���ȣ) ��
				}
			}
	}
	if(!balanced)      // balanced�� ���� ���� ��� ����
		return 0;
	else if(!bracket.isEmpty())    // ���ȣ�� �������� Stack�� ������� ���� ��� ¦�� ���� �ʴ� �ް�ȣ üũ
		Check_L(bracket.pop());
	else                            // �� ���� ��� 1 ���
		cout<<"1"<<endl;
	return 0;
}

bool isMatched(char symbol, char open){       // ���� �����Ǵ��� �Ǻ� �Լ�
	if(symbol == ')')                    // ����ڷκ��� �о�帰 ���� ')'�� ���
		return checkSmall_L(open);       // '�Ұ�ȣ'�� �´��� �Ǻ�

	else if(symbol == '}')               //           ��                        '}'�� ���
		return checkMedium_L(open);      // '�߰�ȣ'�� �´��� �Ǻ�

	else                                 //           ��                        ']'�� ���
		return checkBig_L(open);         // '���ȣ'�� �´��� �Ǻ�
}

bool checkSmall_L(char open){        // '�Ұ�ȣ'���� �Ǻ� �Լ�
	if(open != '('){
		cout<<"error 1"<<endl;       // ')'�� �����ϴ� '('�� ���� ��� error1 ���
		return false;
	}
	return true;
}

bool checkMedium_L(char open){        // '�߰�ȣ'���� �Ǻ� �Լ�
	if(open != '{'){
		cout<<"error 2"<<endl;       // '}'�� �����ϴ� '{'�� ���� ��� error2 ���
		return false;
	}
	return true;
}

bool checkBig_L(char open){        // '���ȣ'���� �Ǻ� �Լ�
	if(open != '['){
		cout<<"error 3"<<endl;       // ']'�� �����ϴ� '['�� ���� ��� error3 ���
		return false;
	}
	return true;
}

void Check_L(char symbol){        // ���� ��ȣ Check �Լ�
	if(symbol == '(')
		cout<<"error 4"<<endl;     // ')'�� �����ϴ� '('�� ���� ��� error4 ���
	else if(symbol == '{')
		cout<<"error 5"<<endl;     // '}'�� �����ϴ� '{'�� ���� ��� error5 ���
	else if(symbol == '[')
		cout<<"error 6"<<endl;     // ']'�� �����ϴ� '['�� ���� ��� error6 ���
}

void Check_R(char symbol){        // ���� ��ȣ Check �Լ�
	if(symbol == ')')
		cout<<"error 1"<<endl;
	else if(symbol == '}')
		cout<<"error 2"<<endl;
	else if(symbol == ']')
		cout<<"error 3"<<endl;

}

bool isLeftBracket(char ch){
	if((ch == '(') || (ch == '{') || (ch == '['))
		return true;
	else
		return false;
}

bool isRightBracket(char ch){
	if((ch == ')') || (ch == '}') || (ch == ']'))
		return true;
	else
		return false;
}
