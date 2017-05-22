/*
 * main.cpp
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main (){
	BinarySearch<int> search;

	search.insertItem(100);
	search.insertItem(10);
	search.insertItem(1);
	search.insertItem(11);
	search.insertItem(5);
	search.printAll();
	cout<<endl;              // 1 5 10 11 100

	search.deleteItem(10);
	search.printAll();       // 1 5 11 100
	cout<<endl;

	cout<<search.searchItem(11)<<endl;   // 11

	cout<<search.getCount()<<endl;      // 4
	return 0;
}
