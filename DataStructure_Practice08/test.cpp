/*
 * 과제 내용
 *
  	  교과목 수강자 관리를 위한 다음 명령어를 처리하는 프로그램을 작성하시오. 수강자는 학번정보(문자열)를 가진다.

	명령어 양식

	N id  // 학번이 id인 학생이 수강신청을 함
	C id  // 학번이 id인 학생이 수강신청을 취소함
	S     // 수강 학생수를 출력
	P     // 수강 학생들을 학번순서(오름차순)대로 출력
	Q     // 끝내기
	명령어 입력에 있어서 오류는 없다고 가정한다.
 */

#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string info;    // 학번
	Node* next;
};

class List
{
public:
   List();
   ~List();
   bool isEmpty() const;
   void insert(string);
   void remove(string);
   int size() const;
   void print();

private:
   Node* topPtr;
   int length;
};

List::List(){
	length = 0;
	topPtr = NULL;
}
List::~List(){
	delete topPtr;
}

int List::size() const {return length;}

bool List::isEmpty() const{
	return topPtr == NULL;
}
void List::print(){            // 오름차순으로 출력
	Node* pre = topPtr;
	Node* post = topPtr;
	while(pre != NULL){
		while(post != NULL){
			if(pre->info.compare(post->info)>0){     // 이전 값이 이후 값보다 클 경우  swap
				string temp = pre->info;
				pre->info = post->info;
				post->info = temp;
			}
			post = post->next;
		}
		cout<<pre->info<<" ";
		pre = pre->next;
		post = pre;
	}
	cout<<endl;
}

void List::insert(string id){     // 리스트 삽입
	Node* loc;
	loc = new Node;
	loc->info = id;
	loc->next = topPtr;
	topPtr = loc;
	length++;
}

void List::remove(string id){
	Node*  location = topPtr;
	Node*  tempLocation;

	if (id == topPtr->info){
		tempLocation = topPtr;
	    topPtr = topPtr->next;
	}
	else{
		while(id != location->next->info)
			location = location->next;

		tempLocation = location->next;
	    location->next = location->next->next;
	}
	delete tempLocation;
	length--;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
  List L;
  string command;  // 명령어
  string st_id;       // 학번
  while (1)
  {
     cin >> command;
     if (command == "N")
     {
       cin >> st_id;
       L.insert(st_id);
     }
     else if (command == "C"){   // C를 누를 경우 해당 학번 정보 삭제
    	 cin >> st_id;
    	 L.remove(st_id);
     }
     else if (command == "S")   // S를 누를 경우 원소 갯수 출력
    	 cout<<L.size()<<endl;

     else if (command == "P")  // P를 누를 경우 오름차순으로 모든 학번 정보 출력
    	 L.print();
     else if (command == "Q")  // Q를 누를 경우 프로그램 종료
       break;
  }
}
