/*
 * SelSort.h
 *
 *  Created on: 2017. 6. 11.
 *      Author: Cho
 */

#ifndef SELSORT_H_
#define SELSORT_H_

#include <iostream>

using namespace std;

template <class T>
class SelSort{
public:
	void selSort(T*, int);
private:
	int maxIndex;
};

template <class T>
void SelSort<T>::selSort(T *arr, int size){
	for(int i=size-1; i>0; i--){
		int maxIndex = 0;
		for(int j = i; j>0; j--){
			if(arr[maxIndex] < arr[j])       // 만약 다른 원소들 중 더 큰 값이 존재한다면
				maxIndex = j;                // maxIndex 변경
		}
		int temp = arr[i];                  // 맨 뒤 원소를 제일 큰 원소에 저장 후, 반복문 다시 시작
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

#endif /* SELSORT_H_ */
