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
		if(command == "N"){    // N (삽입)
			cin>>st_id;
			L.insert(st_id);    // 해당 번호 학생 삽입
		}
		else if(command == "C"){   // C (삭제)
			cin>>st_id;
			L.remove(st_id);    // 해당 번호 학생 제거
		}
		else if(command=="S")    // S (크기 출력)
			cout<<L.size()<<endl;   // 총 학생 수 출력

		else if(command == "P")   // P (총 학생 정보 출력)
			L.print();          // 모든 학생 정보 출력 - 오름차순

		else if (command=="Q")    // Q (종료)
			break;
	}
	return 0;
}
