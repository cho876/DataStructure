/*
 * main.cpp
 *
 *  Created on: 2017. 6. 11.
 *      Author: Cho
 */

#include "SelSort.h"

typedef int Itemtype;

int main()
{
	SelSort<Itemtype> Sorting;

	int size;
	cout<<"Input Array's Size: ";
	cin>>size;

	Itemtype *arr = new Itemtype[size];

	for(int i=0; i<size; i++){
		cout<<"Input data ("<<i<<"): ";
		cin>>arr[i];
	}

	Sorting.selSort(arr, size);

	for(int j=0; j<size; j++)
		cout<<arr[j]<<" ";

	return 0;
}
