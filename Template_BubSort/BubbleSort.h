/*
 * BubbleSort.h
 *
 *  Created on: 2017. 6. 15.
 *      Author: Cho
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <iostream>

using namespace std;

template <class T>
class BubbleSort{
public:
	void BubSort(T* arr, int size);

private:
	bool isSorted;
};

template <class T>
void BubbleSort<T>::BubSort(T* arr, int size){
	for(int i=size-1; i>0; i--){
		isSorted = true;
		for(int j=0; j<i; j++){
			if(arr[j] > arr[j+1]){
				isSorted = false;
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(isSorted)
			return;
	}
}
#endif /* BUBBLESORT_H_ */
