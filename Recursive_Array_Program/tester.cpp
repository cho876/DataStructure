/*
 * tester.cpp
 *
 *  Created on: 2017. 6. 3.
 *      Author: Cho
 */

#include <iostream>

using namespace std;

int SumArray(int a[], int max){         // Array's total Sum
	if(max == 1)
		return a[0];
	else{
		return a[max-1] + SumArray(a, max-1);
	}
}

int SumArray(int a[], int from, int to){    // Array's sum (from ~ to)
	if(from == to){
		return a[from-1];
	}else{
		return a[from-1] + SumArray(a, from+1, to);
	}
}

int SearchByRecur(int a[], int front, int tail, int value){
	if(front > tail)
		return -1;
	else{
		int mid = (front+tail) / 2;
		if(a[mid] == value)
			return a[mid];
		else if(a[mid] < value)
			return SearchByRecur(a, mid+1, tail, value);
		else if(a[mid] > value)
			return SearchByRecur(a, front, mid-1, value);
	}
}

int SearchByIter(int a[], int max, int value){
	bool found = false;
	int front, tail, mid = 0;

	while(!found && front <= tail){
		mid = (front + tail) / 2;
		if(a[mid] == value)
			found = true;
		else if(a[mid] > value)
			tail = mid - 1;
		else if(a[mid] < value)
			front = mid + 1;
	}
	return value;
}

int main(){
	int max;
	int num;
	int value;

	cout<<"Array's size: ";
	cin>>max;
	cout<<"Find value: ";
	cin>>value;

	int* array = new int[max];

	for(int i=0; i<max; i++){
		cin>>num;
		array[i] = num;
	}
	cout<<"Sum of array: "<<SumArray(array, max)<<endl;
	cout<<"Sum of array (3~5)"<<SumArray(array, 3, 5)<<endl;
	cout<<"Search Value By Iter ("<<value<<"): "<<SearchByIter(array, max, value)<<endl;
	cout<<"Search Value By Recur ("<<value<<"): "<<SearchByRecur(array,0, max, value)<<endl;

	return 0;
}
