/*
 * ���� ����
 *
  	  ������ ������ ������ ���� ���� ��ɾ ó���ϴ� ���α׷��� �ۼ��Ͻÿ�. �����ڴ� �й�����(���ڿ�)�� ������.

	��ɾ� ���

	N id  // �й��� id�� �л��� ������û�� ��
	C id  // �й��� id�� �л��� ������û�� �����
	S     // ���� �л����� ���
	P     // ���� �л����� �й�����(��������)��� ���
	Q     // ������
	��ɾ� �Է¿� �־ ������ ���ٰ� �����Ѵ�.
 */

#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string info;    // �й�
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
void List::print(){            // ������������ ���
	Node* pre = topPtr;
	Node* post = topPtr;
	while(pre != NULL){
		while(post != NULL){
			if(pre->info.compare(post->info)>0){     // ���� ���� ���� ������ Ŭ ���  swap
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

void List::insert(string id){     // ����Ʈ ����
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
  string command;  // ��ɾ�
  string st_id;       // �й�
  while (1)
  {
     cin >> command;
     if (command == "N")
     {
       cin >> st_id;
       L.insert(st_id);
     }
     else if (command == "C"){   // C�� ���� ��� �ش� �й� ���� ����
    	 cin >> st_id;
    	 L.remove(st_id);
     }
     else if (command == "S")   // S�� ���� ��� ���� ���� ���
    	 cout<<L.size()<<endl;

     else if (command == "P")  // P�� ���� ��� ������������ ��� �й� ���� ���
    	 L.print();
     else if (command == "Q")  // Q�� ���� ��� ���α׷� ����
       break;
  }
}
