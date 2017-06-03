/*
 * Main.cpp
 *
 *  Created on: 2017. 6. 3.
 *      Author: Cho
 *
 *      Title : Circular List's Algorithms
 */

#include "CircularList.h"

int main(){
	Circular<int> circular;

	circular.insertItemFront(1);    // 1
	circular.insertItemFront(2);    // 2 1
	circular.insertItemFront(3);    // 3 2 1
	circular.insertItemTail(4);     // 3 2 1 4
	circular.insertItemTail(5);     // 3 2 1 4 5
	circular.printAll();

	circular.deleteItemFront();     // 2 1 4 5
	circular.deleteItemTail();      // 2 1 4
	cout<<endl;
	circular.printAll();

	cout<<"size: "<<circular.getSize()<<endl;    // size: 3
	return 0;
}
