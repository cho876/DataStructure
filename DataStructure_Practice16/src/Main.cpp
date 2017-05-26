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
		if(command == "N"){
			cin>>st_id;
			L.insert(st_id);
		}else if(command == "C"){
			cin>>st_id;
			L.remove(st_id);
		}else if(command=="S")
			cout<<L.size()<<endl;
		else if(command == "P")
			L.print();
		else if (command=="Q")
			break;
	}
	return 0;
}
