/*
 * 과제 내용
 *
 * 	1부터 n까지 번호가 붙여진 n명의 사람들이 시계방향으로 차례대로 원형테이블에 앉아 있다.
 * 	s와 j가 주어질 때, 번호가 s인 사람부터 시작하여 시계방향으로 j번째 사람을 제외시킨다.
 * 	그리고 제외된 사람 다음부터 시작하여 j번째 사람을 제외시킨다. 이 과정을 반복한다.
	n, s, j와 k(제외되는 사람들의 수)가 주어질 때, 제외되는 k명의 사람들의 번호를 차례대로 출력하는 프로그램을 작성하시오.
 */

#include <iostream>

using namespace std;

typedef int Itemtype;

struct Node{          // Node = 사람
	Itemtype info;    // 먼저 들어온 사람 순서대로 순번 저장
	Node* next;
};

class Circular{

	Node* tail;          // 원형 리스트의 가장 꼬리 부분을 가리키는 pointer
	Node* currentPos;    // 현재를 가리키는 pointer

public:
	Circular();      // 원형 리스트 생성자
	bool isEmpty();   // 원형 리스트가 비어있는지 확인
	void insertTail(Itemtype item);
	int remove(Itemtype item);         // item에 해당하는 Node 삭제
	void setStartPoint(int start);    // 처음 tail부터 start번째 Node(사람)로 이동
	Itemtype moveNode(int finish);   // 이후, finish번째 만큼 Node(사람) 계속 이동
};

Circular::Circular(){        // 원형 리스트 생성자
	tail = NULL;
	currentPos = NULL;
}


bool Circular::isEmpty(){    // 원형 리스트가 비어있는지 확인
	return tail == NULL;
}

void Circular::insertTail(Itemtype item){  // 원형 리스트의 후미부분에 item을 갖는 Node 삽입
	Node* newNode = new Node();   // 새로운 Node(사람) 생성
	newNode->info = item;     // Node(사람)의 info(순번) 지정

	if(tail == NULL){   // 만약 처음으로 삽입됐을 경우
		tail = newNode;    // 새로 생성된 Node가 tail이 되며
		tail->next = tail;   // 원형 리스트 이므로 tail의 next는 자기 자신을 가리키게 함
	}else{                             // 삽입하는 것이 처음이 아닐 경우
		newNode->next = tail->next;    // 새로 생성된 Node의 다음은 기존에 tail이 가리키던 next를 가리킴
		tail->next = newNode;         // 기존의 tail의 next는 새로 만든 Node를 가리키게 만듬
		tail = newNode;             // 이후, 새로 만든 newNode가 새롭게 tail로써 지정
	}
}

int Circular::remove(Itemtype item){     // item(순번)에 해당하는 값을 갖는 Node(사람)을 삭제
	Node* location = tail;        // location이라는 Node는 tail을 가리킴
	Node* temp = NULL;            // 제거할 Node를 가리키기 위한 포인터 변수
	int index = 0;
	while(location->next->info != item)   // 삭제한 후, 이전 Node와 다음 Node를 연결해야함으로
		location = location->next;        // 이전 노드를 기준으로 반복문 실행

	if(location->next == tail){           // info에 해당하는 값이 tail이 가리키는 값일 경우
		temp = tail;                     // Node를 제거하기 위해 만든 temp = tail
		location->next = tail->next;    // tail의 이전 노드의 next = 기존 tail의 next
		tail = location;               // tail은 기존의 tail의 이전 Node를 가리킴

	}else{                            // 삭제하고자 하는 노드가 tail이 아닐 경우
		temp = location->next;          // 해당 Node를 temp에 저장
		location->next = temp->next;    // 이전 Node와 삭제하고자 하는 Node의 다음 Node를 연결
	}

	currentPos = location->next;        // 삭제하고자하는 Node의 정보를 currentPos에 저장
	index = temp->info;                 // 순번을 반환하기 위한 index = 삭제하고자하는 Node의 info(순번)
	delete temp;                        // 제거하고자 했던 temp 값은 삭제
	return index;                       // 제거한 Node(사람)의 info(순번) 반환
}

void Circular::setStartPoint(int start){   // 초기 사용자 입력 값 중 몇번 째부터 시작하는지를 입력 시, 그 값만큼 jump시키기 위한 함수
	currentPos = tail;               // currentPos = tail->next(원형 리스트의 맨 앞)
	while(start>0){                        // start번 째부터 시작일 경우 start번 반복
		currentPos = currentPos->next;     // currentPos n번만큼 이동
		--start;
	}
}

Itemtype Circular::moveNode(int finish){   // start번째 부터 시작 이후, 계속해서 finish번 째만큼 넘어선 Node(사람)로 이동
	Node* location = currentPos;
	while(--finish>0)
		location = location->next;
	return location->info;
}

int main(){
	Circular circular;
	Itemtype input;
	int start, finish, cut;

	cin>>input;                     // 사용자로부터 몇 명을 삽입할건지 입력 받음
	for(int i=1; i<=input; i++){
	circular.insertTail(i);         // input만큼 원형 리스트 생성, 이 때, 매개변수 i는 순번에 해당
	}
	cin>>start>>finish>>cut;       // 이후, start번째부터 finish번째 만큼 넘어선 사람을 cut만큼 출력

	circular.setStartPoint(start);   // start번째부터에 해당하는 사람으로 이동
	while(cut){                      // cut 만큼 출력하는 것이므로 cut이 0이 될 때까지 반복
		cout<<circular.remove(circular.moveNode(finish))<<" ";    // finish만큼 이동한 사람을 삭제하고 그에 해당하는 순번 출력
		--cut;
	}
	return 0;
}
