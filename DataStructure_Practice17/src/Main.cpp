/*
 * Main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 *
 *      二쇱젣: �꽌�젏�쓽 �룄�꽌 �옱怨좉�由� �봽濡쒓렇�옩

	1) �옱怨� �룄�꽌�뱾�� �씠吏꾪깘�깋�듃由щ줈 援ы쁽
  	  	  �룄�꽌�뒗 �룄�꽌踰덊샇(string), �룄�꽌�씠由�(怨듬갚�씠 �뾾�뒗 string), 媛�寃�(int), �닔�웾(int) �젙蹂대�� 媛�吏꾨떎.
	2) 紐낅졊�뼱 醫낅쪟�뒗 �떎�쓬怨� 媛숇떎.
		��  N // �떊洹쒕룄�꽌 �엯怨�
   	   	   	   �엯�젰: �룄�꽌踰덊샇, �룄�꽌�씠由�, 媛�寃�, �엯怨좎닔�웾
   	   	   	   �엯�젰 �삁: N 1111 DataStructures 20000 10
   	   	   	   �쑀�쓽�궗�빆: �떊洹쒕룄�꽌媛� �옱怨좊룄�꽌 紐⑸줉�뿉 �엳�쓣 寃쎌슦 �쐃rror: 1�� 異쒕젰
		��  R // �옱怨좊룄�꽌 紐⑸줉�뿉 �엳�뒗 �룄�꽌 �엯怨�
   	   	   	   �엯�젰: �룄�꽌踰덊샇, �엯怨좎닔�웾
   	   	   	   �엯�젰 �삁: R 1111 3
   	   	   	   �쑀�쓽�궗�빆: �룄�꽌踰덊샇�쓽 �룄�꽌媛� �옱怨좊룄�꽌 紐⑸줉�뿉 �뾾�쓣 寃쎌슦 �쐃rror: 2�� 異쒕젰
		��  S // �옱怨좊룄�꽌 紐⑸줉�뿉 �엳�뒗 �룄�꽌瑜� �뙋留ㅽ븿
   	   	   	   �엯�젰: �룄�꽌踰덊샇 �뙋留ㅼ닔�웾
   	   	   	   �엯�젰 �삁: S 1111 2
   	   	   	   �쑀�쓽�궗�빆: �엯�젰�릺�뒗 �룄�꽌踰덊샇媛� �옱怨좊룄�꽌 紐⑸줉�뿉 �뾾�쓣 寃쎌슦, �쐃rror: 2�� 異쒕젰�븯怨�, �뙋留ㅼ닔�웾�씠 �옱怨좎닔�웾蹂대떎 留롮쓣 寃쎌슦 �쐃rror: 3�� 異쒕젰
		��  D // �룄�꽌 �룓湲� (�옱怨좊룄�꽌 紐⑸줉�뿉�꽌 �셿�쟾�엳 �궘�젣�븿)
   	   	   	   �엯�젰: �룄�꽌踰덊샇
   	   	   	   �엯�젰 �삁: 1112
   	   	   	   �쑀�쓽�궗�빆: �엯�젰�릺�뒗 �룄�꽌踰덊샇媛� �옱怨좊룄�꽌 紐⑸줉�뿉 �뾾�쓣 寃쎌슦  �쐃rror: 2�� 異쒕젰
		��  I // �룄�꽌�쓽 �옱怨� �긽�깭 議고쉶
   	   	   	   �엯�젰 : �룄�꽌踰덊샇
   	   	   	   �엯�젰 �삁: 1111
   	   	   	   異쒕젰 : �엯�젰�맂 �룄�꽌踰덊샇�쓽 �옱怨� �긽�깭(�룄�꽌踰덊샇 �씠由� 媛�寃� �옱怨좎닔�웾)瑜� 異쒕젰
   	   	   	   �� �옱怨� �닔�웾�씠 0�씤 寃쎌슦�룄 異쒕젰�븿
   	   	   	   異쒕젰 �삁
   	   	   	   1111 DataStrctures 20000 11
   	   	   	   �쑀�쓽�궗�빆: �엯�젰�릺�뒗 �룄�꽌踰덊샇媛� �룄�꽌�옱怨� 紐⑸줉�뿉 �뾾�쓣 寃쎌슦 �쐃rror: 2�� 異쒕젰
		��  P // �룄�꽌�옱怨� 紐⑸줉�뿉 �엳�뒗 紐⑤뱺 �룄�꽌�쓽 �옱怨좎긽�깭(�룄�꽌踰덊샇, �룄�꽌�씠由�, 媛�寃�, �옱怨좎닔�웾)瑜� �룄�꽌踰덊샇 �삤由꾩감�닚�쑝濡� 異쒕젰
   	   	   	   �� �옱怨� �닔�웾�씠 0�씤 �룄�꽌�룄 異쒕젰�븿
   	   	   	   異쒕젰 �삁
   	   	   	   1111 DataStrctures 20000 11
   	   	   	   1112 Algorithms 18000 4
   ...
		��  L // �뙋留ㅽ븳 紐⑤뱺 �룄�꽌�쓽 �뙋留ㅼ젙蹂�(�룄�꽌踰덊샇, �룄�꽌�씠由�, 媛�寃�, �뙋留ㅼ닔�웾)瑜� �룄�꽌踰덊샇 �삤由꾩감�닚�쑝濡� 異쒕젰
		��  醫낅즺(Q) //
   	   	   	   �봽濡쒓렇�옩�쓣 醫낅즺�븿
 */

#include "BSTree.h"

int main(){
	BSTree L;           // 재고목록 Binary Tree
	BSTree SL;          // 판매목록 Binary Tree
	Book B;             // 재고 책 정보 Structure
	Book SB;            // 판매 책 정보 Structure
	bool found = false;
	string command, num;
	int price, count;
	string name;

	while(1){
		cin>>command;
		if(command == "N"){                  // N (신규 도서 입고)
			cin>>num>>name>>price>>count;
			L.insert(num, name, price, count);
		}
		else if(command == "R"){            // R (재고도서 목록에 있는 도서 입고)
			cin>>num>>count;
			L.plus(num, count);
		}else if(command == "S"){           // S (재고도서 목록에 있는 도서 판매)
			cin>>num>>count;
			if(L.sell(num, count)){
				SB = L.search(num, found);
				SL.insertSell(SB.num, SB.name, SB.price, count);
			}
		}
		else if(command == "D"){           // D (도서 폐기)
			cin>>num;
			L.remove(num);
		}else if(command == "I"){          // I (도서 재고 상태 조회)
			cin>>num;
			B = L.search(num, found);
			if(found)
				cout<<B.num<<" "<<B.name<<" "<<B.price<<" "<<B.count<<endl;
		}else if(command == "P"){          // P (도서재고 목록에 있는 도서 상태 오름차순 출력)
			L.print();
		}else if(command == "L"){          // L (판매 목록 오름차순 출력)
			SL.print();
		}
		else
			break;
	}
	return 0;
}
