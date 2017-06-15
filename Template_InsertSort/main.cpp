/*
 * main.cpp
 *
 *  Created on: 2017. 6. 15.
 *      Author: Cho
 */

#include "InsertSorting.h"

typedef int ItemType;

int main()
{
	InsertSort<ItemType> insertSor;      // ���� ���� ��ü ����

	int size;
	cout<<"Input Array's Size: ";
	cin>>size;

	ItemType *arr = new ItemType[size];

	for(int i=0; i<size; i++){
		cout<<"Input data ("<<i<<"): ";
		cin>>arr[i];
	}

	for(int j=0; j<size; j++)               // ù��° ���Һ��� ������ ���ұ��� ���� ���� ����
		insertSor.insertSort(arr, j);

	for(int k=0; k<size; k++)
		cout<<arr[k]<<" ";

	return 0;
}
