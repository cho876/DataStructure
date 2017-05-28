/*
 * Main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 *
 *      주제: 서점의 도서 재고관리 프로그램

	1) 재고 도서들은 이진탐색트리로 구현
  	  	  도서는 도서번호(string), 도서이름(공백이 없는 string), 가격(int), 수량(int) 정보를 가진다.
	2) 명령어 종류는 다음과 같다.
		•  N // 신규도서 입고
   	   	   	   입력: 도서번호, 도서이름, 가격, 입고수량
   	   	   	   입력 예: N 1111 DataStructures 20000 10
   	   	   	   유의사항: 신규도서가 재고도서 목록에 있을 경우 “error: 1” 출력
		•  R // 재고도서 목록에 있는 도서 입고
   	   	   	   입력: 도서번호, 입고수량
   	   	   	   입력 예: R 1111 3
   	   	   	   유의사항: 도서번호의 도서가 재고도서 목록에 없을 경우 “error: 2” 출력
		•  S // 재고도서 목록에 있는 도서를 판매함
   	   	   	   입력: 도서번호 판매수량
   	   	   	   입력 예: S 1111 2
   	   	   	   유의사항: 입력되는 도서번호가 재고도서 목록에 없을 경우, “error: 2” 출력하고, 판매수량이 재고수량보다 많을 경우 “error: 3” 출력
		•  D // 도서 폐기 (재고도서 목록에서 완전히 삭제함)
   	   	   	   입력: 도서번호
   	   	   	   입력 예: 1112
   	   	   	   유의사항: 입력되는 도서번호가 재고도서 목록에 없을 경우  “error: 2” 출력
		•  I // 도서의 재고 상태 조회
   	   	   	   입력 : 도서번호
   	   	   	   입력 예: 1111
   	   	   	   출력 : 입력된 도서번호의 재고 상태(도서번호 이름 가격 재고수량)를 출력
   	   	   	   ※ 재고 수량이 0인 경우도 출력함
   	   	   	   출력 예
   	   	   	   1111 DataStrctures 20000 11
   	   	   	   유의사항: 입력되는 도서번호가 도서재고 목록에 없을 경우 “error: 2” 출력
		•  P // 도서재고 목록에 있는 모든 도서의 재고상태(도서번호, 도서이름, 가격, 재고수량)를 도서번호 오름차순으로 출력
   	   	   	   ※ 재고 수량이 0인 도서도 출력함
   	   	   	   출력 예
   	   	   	   1111 DataStrctures 20000 11
   	   	   	   1112 Algorithms 18000 4
   ...
		•  L // 판매한 모든 도서의 판매정보(도서번호, 도서이름, 가격, 판매수량)를 도서번호 오름차순으로 출력
		•  종료(Q) //
   	   	   	   프로그램을 종료함
 */

#include "BSTree.h"


int main(){
	BSTree L;           // 도서관내 도서 Binary Tree
	BSTree SL;          // 판매 도서 Binary Tree
	Book B;             // 도서관내 도서 Structure
	Book SB;            // 판매 도서 Structure

	string command;
	int num, price, count;
	string name;

	while(1){
		cin>>command;
		if(command == "N"){                  // N (신규도서 입고)
			cin>>num>>name>>price>>count;
			L.insert(num, name, price, count);
		}
		else if(command == "R"){            // R (재고도서 목록에 있는 도서 입고)
			cin>>num>>count;
			L.plus(num, count);
		}else if(command == "S"){           // S (재고목록에 있는 ㄷ서 판매)
			cin>>num>>count;
			if(L.sell(num, count)){
				SB = L.search(num);
				SL.insertSell(SB.num, SB.name, SB.price, count);
			}
		}
		else if(command == "D"){           // D (도서 폐기)
			cin>>num;
			L.remove(num);
		}else if(command == "I"){          // I (도서의 재고 상태 조회)
			cin>>num;
			B = L.search(num);
			cout<<B.num<<" "<<B.name<<" "<<B.price<<" "<<B.count<<endl;
		}else if(command == "P"){          // P (도서 목록 재고상태 오름차순 출력)
			L.print();
		}else if(command == "L"){          // L (판매목록 오름차순 출력)
			SL.print();
		}
		else
			break;
	}
	return 0;
}
