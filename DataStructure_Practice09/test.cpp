#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int num;       // ���� ��ȣ
	string name;   // ���� �̸�
	int price;     // ����
	int total;     // ����
	Node* next;
};

class List
{
public:
   List();
   ~List();
   bool isEmpty() const;
   bool error1(int);       // error1 ����
   bool error2(int);       // error2 ����
   bool error3(int, int);     // error3 ����
   void insert(int, string, int, int);
   void remove(int);          // ���� ���
   void add(int, int);        // ����� ��Ͽ� �ִ� ���� �԰�
   void sell(int, int);       // ���� �Ǹ�
   void find(int);            // ���� ��� ���� ��ȸ
   void print();              // ���� ���� ��� ���
   void _print();             // �Ǹ� ���� ��� ���

private:
   Node* sellPtr;      // �ǸŸ���� ���� Node
   Node* topPtr;       // ������� ���� Node
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

bool List::error1(int num){  // error1 ����
	Node* comp = topPtr;
	while(comp != NULL){
		if(comp->num == num){  // �űԵ����� ����� ��Ͽ� ���� ���
			return true;
		}
		comp = comp->next;
	}
	return false;
}

bool List::error2(int num){  // error2 ����
	Node* pre = topPtr;
	while(pre != NULL){
		if(pre->num == num)
			return false;
		pre = pre->next;
	}
	// ������ȣ�� ������ ����� ��Ͽ� ���� ���
	cout<<"error: 2"<<endl;
		return true;
}

bool List::error3(int num, int total){  // error3 ����
	Node* comp = topPtr;
	while(comp != NULL){
		if(comp->num == num){
			if(comp->total<total){  // �Ǹż����� ���������� ���� ���
				cout<<"error: 3"<<endl;
				return true;
			}
		}
		comp = comp->next;
	}
	return false;
}

// ������ȣ ���� ������������ ����
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

void List::add(int num, int total){  // ����� ��Ͽ� �ִ� ���� �԰�
	if(error2(num))
		return;
	else{
		Node* comp = topPtr;
		while(comp != NULL){
			if(comp->num == num){   // ��Ͽ� ���� ��� �߰�
				comp->total += total;
				return;
			}
			comp = comp->next;
		}
	}
}

void List::sell(int num, int total){    // ���� �Ǹ�
	if(error2(num) || error3(num, total))
		return;
	else{
		Node* pre = topPtr;
		Node* sel = new Node;
		while(pre != NULL){
			if(pre->num == num){
				pre->total -= total;  // �Ǹ��� ��� ����Ͽ����� total ����
				sel->num = pre->num;  // �ǸŸ�Ͽ��� ���� ���� �߰�
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

void List::remove(int num){   // ���� ����
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

void List::find(int num){    // ���� ã��
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

void List::print(){   // ����� ���
	Node* pre = topPtr;
	while(pre != NULL){
		cout<<pre->num<<" "<<pre->name<<" "<<pre->price
				<<" "<<pre->total<<endl;
		pre = pre->next;
	}
}

void List::_print(){  // �ǸŸ�� ���
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
  char command;  // ��ɾ�
  int num;
  string name;
  int price;
  int total;

  cout<<"1"<<endl;
  while (1)
  {
     cin >> command;
     switch(command){

     case 'N': // �űԵ��� �԰�
    	 cin>>num>>name>>price>>total;
    	 L.insert(num, name, price, total);
    	 break;

     case 'R': // ����� ��Ͽ� �ִ� ���� �԰�
    	 cin >> num>>total;
    	 L.add(num, total);
    	  break;

     case 'S': // ����� ��Ͽ� �ִ� ������ �Ǹ���
    	 cin >> num>>total;
    	 L.sell(num, total);
    	  break;
     case 'D': // ���� ���
    	 cin >> num;
    	 L.remove(num);
    	 break;
     case 'I': // ������ ��� ���� ��ȸ
    	 cin >> num;
    	 L.find(num);
		 break;
     case 'P': // ������� ��Ͽ� �ִ� ��� ������ ������ ���
    	 L.print();
    	 break;
     case 'L': // �Ǹ��� ��� ������ �Ǹ����� ���
    	 L._print();
    	 break;
     case 'Q': // ����
    	 return 0;
     }
  }
}
