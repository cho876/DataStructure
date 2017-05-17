#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int num;       // 도서 번호
	string name;   // 도서 이름
	int price;     // 가격
	int total;     // 수량
	Node* next;
};

class List
{
public:
   List();
   ~List();
   bool isEmpty() const;
   bool error1(int);       // error1 조건
   bool error2(int);       // error2 조건
   bool error3(int, int);     // error3 조건
   void insert(int, string, int, int);
   void remove(int);          // 도서 폐기
   void add(int, int);        // 재고도서 목록에 있는 도서 입고
   void sell(int, int);       // 도서 판매
   void find(int);            // 도서 재고 상태 조회
   void print();              // 현재 도서 목록 출력
   void _print();             // 판매 도서 목록 출력

private:
   Node* sellPtr;      // 판매목록을 위한 Node
   Node* topPtr;       // 재고목록을 위한 Node
   int length;
};

List::List(){
	length = 0;
	topPtr = NULL;
	sellPtr = NULL;
}
List::~List(){
	delete topPtr;
	delete sellPtr;
}

bool List::error1(int num){  // error1 조건
	Node* comp = topPtr;
	while(comp != NULL){
		if(comp->num == num){  // 신규도서가 재고도서 목록에 있을 경우
			return true;
		}
		comp = comp->next;
	}
	return false;
}

bool List::error2(int num){  // error2 조건
	Node* pre = topPtr;
	while(pre != NULL){
		if(pre->num == num)
			return false;
		pre = pre->next;
	}
	// 도서번호의 도서가 재고도서 목록에 없을 경우
	cout<<"error: 2"<<endl;
		return true;
}

bool List::error3(int num, int total){  // error3 조건
	Node* comp = topPtr;
	while(comp != NULL){
		if(comp->num == num){
			if(comp->total<total){  // 판매수량이 재고수량보다 많을 경우
				cout<<"error: 3"<<endl;
				return true;
			}
		}
		comp = comp->next;
	}
	return false;
}

// 도서번호 기준 오름차순으로 삽입
void List::insert(int num, string name, int price, int total){
	if(error1(num)){
		cout<<"error: 1"<<endl;
		return;
	}
	else{
		Node* location;
		Node* predLoc;
		Node* newNode;
		location = topPtr;
		predLoc = NULL;
		while(location != NULL){
			if (num > location->num){
				predLoc = location;
				location = location->next;
			}
			else
				break;
		}
		newNode = new Node;
		newNode->num = num;
		if (predLoc == NULL){
			newNode->name = name;
			newNode->price = price;
			newNode->total = total;
			newNode->next = topPtr;
			topPtr = newNode;
		}
		else{
			newNode->name = name;
			newNode->price = price;
			newNode->total = total;
			newNode->next = location;
			predLoc->next = newNode;
		}
		length++;
	}
}

void List::add(int num, int total){  // 재고도서 목록에 있는 도서 입고
	if(error2(num))
		return;
	else{
		Node* comp = topPtr;
		while(comp != NULL){
			if(comp->num == num){   // 목록에 있을 경우 추가
				comp->total += total;
				return;
			}
			comp = comp->next;
		}
	}
}

void List::sell(int num, int total){    // 도서 판매
	if(error2(num) || error3(num, total))
		return;
	else{
		Node* pre = topPtr;
		Node* sel = new Node;
		while(pre != NULL){
			if(pre->num == num){
				pre->total -= total;  // 판매할 경우 재고목록에서는 total 감소
				sel->num = pre->num;  // 판매목록에는 도서 정보 추가
				sel->name = pre->name;
				sel->price = pre->price;
				sel->total = total;
				sel->next = sellPtr;
				sellPtr = sel;
				return;
			}
			pre = pre->next;
		}
	}
}

void List::remove(int num){   // 도서 제거
	if(error2(num))
		return;
	else{
		Node* location = topPtr;
		Node*  tempLocation;
	     if (num == topPtr->num){
	    	 tempLocation = topPtr;
	    	 topPtr = topPtr->next;
		     }
		     else{
		    	 while(num != location->next->num)
		    		 location = location->next;
		        tempLocation = location->next;
		        location->next = location->next->next;
		     }
		     delete tempLocation;
		     length--;
		}
}

void List::find(int num){    // 도서 찾기
	if(error2(num))
		return;
	else{
		Node* pre = topPtr;
		while(pre != NULL){
			if(pre->num == num){
				cout<<pre->num<<" "<<pre->name<<" "<<pre->price
						<<" "<<pre->total<<endl;
				return;
			}
			pre = pre->next;
		}
	}
}

void List::print(){   // 재고목록 출력
	Node* pre = topPtr;
	while(pre != NULL){
		cout<<pre->num<<" "<<pre->name<<" "<<pre->price
				<<" "<<pre->total<<endl;
		pre = pre->next;
	}
}

void List::_print(){  // 판매목록 출력
	Node* pre = sellPtr;
	Node* post = sellPtr->next;
	while(pre != NULL){
		while(post != NULL){
			if(pre->num == post->num){
				pre->total += post->total;
			}
				post = post->next;
		}
		cout<<pre->num<<" "<<pre->name<<" "<<pre->price
				<<" "<<pre->total<<endl;
		pre = pre->next;
		post = pre;
	}
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
  List L;
  char command;  // 명령어
  int num;
  string name;
  int price;
  int total;

  cout<<"1"<<endl;
  while (1)
  {
     cin >> command;
     switch(command){

     case 'N': // 신규도서 입고
    	 cin>>num>>name>>price>>total;
    	 L.insert(num, name, price, total);
    	 break;

     case 'R': // 재고도서 목록에 있는 도서 입고
    	 cin >> num>>total;
    	 L.add(num, total);
    	  break;

     case 'S': // 재고도서 목록에 있는 도서를 판매함
    	 cin >> num>>total;
    	 L.sell(num, total);
    	  break;
     case 'D': // 도서 폐기
    	 cin >> num;
    	 L.remove(num);
    	 break;
     case 'I': // 도서의 재고 상태 조회
    	 cin >> num;
    	 L.find(num);
		 break;
     case 'P': // 도서재고 목록에 있는 모든 도서의 재고상태 출력
    	 L.print();
    	 break;
     case 'L': // 판매한 모든 도서의 판매정보 출력
    	 L._print();
    	 break;
     case 'Q': // 종료
    	 return 0;
     }
  }
}
