/*
 * 	과제 내용
 * 	입력으로 들어오는 괄호들은 (,),{,},[,]이다. 괄호가 짝이 맞는 경우 1을 출력하고,
	그렇지 않으면 괄호검사 알고리즘에 의하여 처음으로 발견된 (짝이 맞지 않은 괄호) 오류에 대하여, 다음 중 하나를 출력한다. (다음에서 xx와 yy는 양의 정수임)

	)에 대응하는 (가 없을 경우 error 1: ) at position yy in line xx
	}에 대응하는 {가 없을 경우 error 2: } at position yy in line xx
	]에 대응하는 [가 없을 경우 error 3: ] at position yy in line xx
	(에 대응하는 )가 없을 경우 error 4: ( at position yy in line xx
	{에 대응하는 }가 없을 경우 error 5: { at position yy in line xx
	[에 대응하는 ]가 없을 경우 error 6: ( at position yy in line xx
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Parenthesis{
	char paren;     // 괄호
	int position;   // 문자 위치
	int line_no;    // 라인 번호
};

const int MAX_SIZE = 100;

class Stack{
	int top;
	Parenthesis data[MAX_SIZE];  // Data를 구조체 형태로 저장한다.

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
		error("스택 Full");
	data[++top] = parenth;
}

struct Parenthesis Stack::pop(){
	if(isEmpty())
		error("스택 Empty");
	return data[top--];
}

struct Parenthesis Stack::peek(){
	if(isEmpty())
		error("스택 Empty");
	return data[top];
}

bool isLeftBracket(char);        // 왼괄호인지 판별
bool isRightBracket(char);       // 우괄호인지 판별
bool isMatched(struct Parenthesis, struct Parenthesis);   // 왼괄호와 우괄호 대응관계 판별
void Check_R(struct Parenthesis);             // 우괄호의 종류 체크
void Check_L(struct Parenthesis);             // 왼괄호의 종류 체크
bool checkSmall_L(struct Parenthesis, struct Parenthesis);    // 소괄호인지 체크
bool checkMedium_L(struct Parenthesis, struct Parenthesis);   // 중괄호인지 체크
bool checkBig_L(struct Parenthesis, struct Parenthesis);      // 대괄호인지 체크

int main()
{
	Parenthesis parent = {0,0,1};   // 구조체 초기화
	Stack bracket;
	bool balanced = true;
	struct Parenthesis openSymbol;

	while(cin.get(parent.paren) && balanced){
			++parent.position;                     // 행 수 증가
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
			else if(parent.paren == '\n'){     // 읽어드린 문자가 '\n'일 경우
				parent.position = 0;          // 행 수 0으로 초기화
				++parent.line_no;            // 열 수 1 증가
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


