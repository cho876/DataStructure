/*
 * Main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "BSTree.h"


int main(){
	BSTree L;
	Book B;
	string command;
	int num, price, count;
	string name;

	while(1){
		cin>>command;
		if(command == "N"){
			cin>>num>>name>>price>>count;
			L.insert(num, name, price, count);
		}
		else if(command == "R"){
			cin>>num>>count;
			L.plus(num, count);
		}else if(command == "S"){
			cin>>num>>count;
			L.sell(num, count);
		}else if(command == "D"){
			cin>>num;
			L.remove(num);
		}else if(command == "I"){
			cin>>num;
			B = L.search(num);
			cout<<B.num<<" "<<B.name<<" "<<B.price<<" "<<B.count<<endl;
		}else if(command == "P"){
			L.print();
		}else if(command == "Q"){
			break;
		}
	}
	return 0;
}
