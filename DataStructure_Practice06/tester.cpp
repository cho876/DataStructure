/*
 * 	���� ����
 * 	�Է����� ������ ��ȣ���� (,),{,},[,]�̴�. ��ȣ�� ¦�� �´� ��� 1�� ����ϰ�,
	�׷��� ������ ��ȣ�˻� �˰��� ���Ͽ� ó������ �߰ߵ� (¦�� ���� ���� ��ȣ) ������ ���Ͽ�, ���� �� �ϳ��� ����Ѵ�. (�������� xx�� yy�� ���� ������)

	)�� �����ϴ� (�� ���� ��� error 1: ) at position yy in line xx
	}�� �����ϴ� {�� ���� ��� error 2: } at position yy in line xx
	]�� �����ϴ� [�� ���� ��� error 3: ] at position yy in line xx
	(�� �����ϴ� )�� ���� ��� error 4: ( at position yy in line xx
	{�� �����ϴ� }�� ���� ��� error 5: { at position yy in line xx
	[�� �����ϴ� ]�� ���� ��� error 6: ( at position yy in line xx
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Parenthesis{
	char paren;     // ��ȣ
	int position;   // ���� ��ġ
	int line_no;    // ���� ��ȣ
};

const int MAX_SIZE = 100;

class Stack{
	int top;
	Parenthesis data[MAX_SIZE];  // Data�� ����ü ���·� �����Ѵ�.

public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(struct Parenthesis);
	struct Parenthesis pop();
	struct Parenthesis peek();
};

inline void error(const char *message) {
            cout << message << endl;
            exit(1);
}

Stack::Stack(){	top = -1;}

Stack::~Stack(){}

bool Stack::isEmpty(){return top == -1;}

bool Stack::isFull(){return top == MAX_SIZE-1;}


void Stack::push(struct Parenthesis parenth){
	if(isFull())
		error("���� Full");
	data[++top] = parenth;
}

struct Parenthesis Stack::pop(){
	if(isEmpty())
		error("���� Empty");
	return data[top--];
}

struct Parenthesis Stack::peek(){
	if(isEmpty())
		error("���� Empty");
	return data[top];
}

bool isLeftBracket(char);        // �ް�ȣ���� �Ǻ�
bool isRightBracket(char);       // ���ȣ���� �Ǻ�
bool isMatched(struct Parenthesis, struct Parenthesis);   // �ް�ȣ�� ���ȣ �������� �Ǻ�
void Check_R(struct Parenthesis);             // ���ȣ�� ���� üũ
void Check_L(struct Parenthesis);             // �ް�ȣ�� ���� üũ
bool checkSmall_L(struct Parenthesis, struct Parenthesis);    // �Ұ�ȣ���� üũ
bool checkMedium_L(struct Parenthesis, struct Parenthesis);   // �߰�ȣ���� üũ
bool checkBig_L(struct Parenthesis, struct Parenthesis);      // ���ȣ���� üũ

int main()
{
	Parenthesis parent = {0,0,1};   // ����ü �ʱ�ȭ
	Stack bracket;
	bool balanced = true;
	struct Parenthesis openSymbol;

	while(cin.get(parent.paren) && balanced){
			++parent.position;                     // �� �� ����
			if(isLeftBracket(parent.paren)){
				bracket.push(parent);
			}
			else if(isRightBracket(parent.paren))
			{
				if(bracket.isEmpty()){
					Check_R(parent);
					balanced = false;
				}
				else{
				openSymbol = bracket.pop();
				balanced = isMatched(parent, openSymbol);
				}
			}
			else if(parent.paren == '\n'){     // �о�帰 ���ڰ� '\n'�� ���
				parent.position = 0;          // �� �� 0���� �ʱ�ȭ
				++parent.line_no;            // �� �� 1 ����
			}
	}
	if(!balanced)
		return 0;
	else if(!bracket.isEmpty())
		Check_L(bracket.pop());
	else
		cout<<"1"<<endl;
	return 0;
}

bool isMatched(struct Parenthesis parent, struct Parenthesis open){
	if(parent.paren == ')')
		return checkSmall_L(parent, open);
	else if(parent.paren == '}')
		return checkMedium_L(parent, open);
	else
		return checkBig_L(parent, open);
}

bool checkSmall_L(struct Parenthesis parent, struct Parenthesis compare){
	if(compare.paren != '('){
		cout<<"error 1: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
		return false;
	}
	return true;
}

bool checkMedium_L(struct Parenthesis parent, struct Parenthesis compare){
	if(compare.paren != '{'){
		cout<<"error 2: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
		return false;
	}
	return true;
}

bool checkBig_L(struct Parenthesis parent, struct Parenthesis compare){
	if(compare.paren != '['){
		cout<<"error 3: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
		return false;
	}
	return true;
}

void Check_L(struct Parenthesis parent){
	if(parent.paren == '(')
		cout<<"error 4: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
	else if(parent.paren == '{')
		cout<<"error 5: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
	else if(parent.paren == '[')
		cout<<"error 6: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
}

void Check_R(struct Parenthesis parent){
	if(parent.paren == ')')
		cout<<"error 1: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
	else if(parent.paren == '}')
		cout<<"error 2: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;
	else if(parent.paren == ']')
		cout<<"error 3: "<<parent.paren<<" at position "<<parent.position<<" in line "<<parent.line_no<<endl;

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


