/*
 * Main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"

int main(){
	BSTree L;
	string command;
	string st_id;

	while(1){
		cin>>command;
		if(command == "N"){    // N (����)
			cin>>st_id;
			L.insert(st_id);    // �ش� ��ȣ �л� ����
		}
		else if(command == "C"){   // C (����)
			cin>>st_id;
			L.remove(st_id);    // �ش� ��ȣ �л� ����
		}
		else if(command=="S")    // S (ũ�� ���)
			cout<<L.size()<<endl;   // �� �л� �� ���

		else if(command == "P")   // P (�� �л� ���� ���)
			L.print();          // ��� �л� ���� ��� - ��������

		else if (command=="Q")    // Q (����)
			break;
	}
	return 0;
}
