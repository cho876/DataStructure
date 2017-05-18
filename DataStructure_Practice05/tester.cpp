/*
 * 	과제 내용
 *
 * 	입력으로 들어오는 괄호들 (,),{,},[,]에 대하여, 모든 괄호가 짝이 맞는 경우 1을 출력하고,
 * 	그렇지 않으면 괄호검사 알고리즘에 의하여 처음으로 발견된 (짝이 맞지 않은 괄호) 오류에 대하여, 다음 중 하나를 출력한다.

	)에 대응하는 (가 없을 경우: error 1
	}에 대응하는 {가 없을 경우: error 2
	]에 대응하는 [가 없을 경우: error 3
	(에 대응하는 )가 없을 경우: error 4
	{에 대응하는 }가 없을 경우: error 5
	[에 대응하는 ]가 없을 경우: error 6
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
		error("스택 Full");
	data[++top] = ch;
}

char Stack::pop(){
	if(isEmpty())
		error("스택 Empty");
	return data[top--];
}

char Stack::peek(){
	if(isEmpty())
		error("스택 Empty");
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
				if(bracket.isEmpty()){    // Stack이 비었을 경우 짝이 맞지 않는 우괄호 체크
					Check_R(symbol);
					balanced = false;
				}
				else{
				openSymbol = bracket.pop();
				balanced = isMatched(symbol, openSymbol);  // 불러드린 symbol(왼괄호)와 Stack에서 받아온 openSymbol(우괄호) 비교
				}
			}
	}
	if(!balanced)      // balanced가 맞지 않을 경우 종료
		return 0;
	else if(!bracket.isEmpty())    // 우괄호가 끝났지만 Stack이 비어있지 않을 경우 짝이 맞지 않는 왼괄호 체크
		Check_L(bracket.pop());
	else                            // 그 외의 경우 1 출력
		cout<<"1"<<endl;
	return 0;
}

bool isMatched(char symbol, char open){       // 서로 대응되는지 판별 함수
	if(symbol == ')')                    // 사용자로부터 읽어드린 값이 ')'일 경우
		return checkSmall_L(open);       // '소괄호'가 맞는지 판별

	else if(symbol == '}')               //           〃                        '}'일 경우
		return checkMedium_L(open);      // '중괄호'가 맞는지 판별

	else                                 //           〃                        ']'일 경우
		return checkBig_L(open);         // '대괄호'가 맞는지 판별
}

bool checkSmall_L(char open){        // '소괄호'인지 판별 함수
	if(open != '('){
		cout<<"error 1"<<endl;       // ')'에 대응하는 '('가 없을 경우 error1 출력
		return false;
	}
	return true;
}

bool checkMedium_L(char open){        // '중괄호'인지 판별 함수
	if(open != '{'){
		cout<<"error 2"<<endl;       // '}'에 대응하는 '{'가 없을 경우 error2 출력
		return false;
	}
	return true;
}

bool checkBig_L(char open){        // '대괄호'인지 판별 함수
	if(open != '['){
		cout<<"error 3"<<endl;       // ']'에 대응하는 '['가 없을 경우 error3 출력
		return false;
	}
	return true;
}

void Check_L(char symbol){        // 왼쪽 괄호 Check 함수
	if(symbol == '(')
		cout<<"error 4"<<endl;     // ')'에 대응하는 '('가 없을 경우 error4 출력
	else if(symbol == '{')
		cout<<"error 5"<<endl;     // '}'에 대응하는 '{'가 없을 경우 error5 출력
	else if(symbol == '[')
		cout<<"error 6"<<endl;     // ']'에 대응하는 '['가 없을 경우 error6 출력
}

void Check_R(char symbol){        // 왼쪽 괄호 Check 함수
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
