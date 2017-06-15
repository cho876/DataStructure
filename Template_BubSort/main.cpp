/*
 * main.cpp
 *
 *  Created on: 2017. 6. 15.
 *      Author: Cho
 */

#include "BubbleSort.h"

typedef int ItemType;

int main()
{
	BubbleSort<ItemType> bubble;
	int size;
	cout<<"Input Array's size: ";
	cin>>size;

	ItemType* arr = new ItemType[size];

	for(int i=0; i<size; i++){
		cout<<"Input data ("<<i<<"): ";
		cin>>arr[i];
	}

	bubble.BubSort(arr, size);

	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
