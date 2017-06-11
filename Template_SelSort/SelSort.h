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
			if(arr[maxIndex] < arr[j])       // ���� �ٸ� ���ҵ� �� �� ū ���� �����Ѵٸ�
				maxIndex = j;                // maxIndex ����
		}
		int temp = arr[i];                  // �� �� ���Ҹ� ���� ū ���ҿ� ���� ��, �ݺ��� �ٽ� ����
		arr[i] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

#endif /* SELSORT_H_ */
