/*
 * 과제 내용
 *
 * 입력으로 들어오는 괄호들은 (,),{,},[,]이다. 이들 괄호가 모두 짝이 맞는 경우 1을 출력하고, 그렇지 않으면 -1을 출력하는 프로그램을 작성하시오.
 * 입력되는 괄호들은 여러 줄에 걸려 있을 수 있다.
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;         // 스택 최대 저장 공간 : 100
class Stack{

	int top;                      // Stack의 가장 상위 index 번호
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

inline void error(const char *message) {       // error 발생 시 호출
            cout << message << endl;
            exit(1);
}

Stack::Stack(){	top = -1;}                  // top = -1로 초기화

Stack::~Stack(){}

bool Stack::isEmpty(){return top == -1;}    // Stack이 비어있는지 판별

bool Stack::isFull(){return top == MAX_SIZE-1;}    // Stack이 가득 찼는지 판별


void Stack::push(char ch){    // Stack이 가득차 있지 않으면 char형 데이터 push
	if(isFull())
		error("스택 Full");
	data[++top] = ch;
}

char Stack::pop(){    // Stack이 비어있지 않다면 현재 최상위 데이터 반환 및 제거
	if(isEmpty())
		error("스택 Empty");
	return data[top--];
}

char Stack::peek(){    // Stack이 비어있지 않다면 현재 최상위 데이터 반환
	if(isEmpty())
		error("스택 Empty");
	return data[top];
}

bool isLeftBracket(char);     // 왼쪽 괄호인지 판별 함수
bool isRightBracket(char);    // 오른쪽 괄호인지 판별 함수
bool isMatched(char, char);   // 왼쪽 괄호와 오른쪽 괄호가 대응하는지 판별 함수

int main()
{
	char symbol;         // 사용자로부터 입력 받을 값
	Stack bracket;        // 괄호들이 서로 대응되는지 판별
	bool balanced = true;
	char openSymbol;     // Stack에 쌓여있는 값


	while(cin.get(symbol) && balanced){     // 사용자로부터 입력받은 값이 있고 괄호들이 계속해서 대응하면 반복
		if(isLeftBracket(symbol))        // 입력 받은 값이 왼쪽 괄호인지 판별
			bracket.push(symbol);
		else if(isRightBracket(symbol))     // 입력 받은 값이 오른쪽 괄호인지 판별
		{
			if(bracket.isEmpty())         // 오른쪽 괄호는 있지만 왼쪽 괄호가 없을 경우
				balanced = false;
			else{
				openSymbol = bracket.pop();
				balanced = isMatched(symbol, openSymbol);    // 오른쪽 괄호와 왼쪽 괄호 비교
			}
		}
	}

	if(!balanced)     // balanced가 false 즉, 대응되지 않은 채로 끝날 경우 -1 출력
		cout<<"-1"<<endl;
	else if(bracket.isEmpty())     // Stack에 값이 비어있을 경우 즉, 모든 괄호가 대응 될 경우 1 출력
		cout<<"1"<<endl;
	else                       // 그 외의 나머지 경우 모두 -1 출력
		cout<<"-1"<<endl;
	return 0;
}

bool isMatched(char right, char left){    // 왼쪽 괄호와 오른쪽 괄호가 대응하는지 판별 함수
	return (((left == '(') && right == ')') ||
			((left == '{') && right == '}') ||
			((left == '[') && right == ']'));
}

bool isLeftBracket(char ch){             // 왼쪽 괄호인지 판별 함수
	if((ch == '(') || (ch == '{') || (ch == '['))
		return true;
	else
		return false;
}

bool isRightBracket(char ch){           // 오른쪽 괄호인지 판별 함수
	if((ch == ')') || (ch == '}') || (ch == ']'))
			return true;
		else
			return false;
}

