/*
 * InsertSorting.h
 *
 *  Created on: 2017. 6. 15.
 *      Author: Cho
 */

#ifndef INSERTSORTING_H_
#define INSERTSORTING_H_

#include <iostream>

using namespace std;

template <class T>
class InsertSort{                     // ���� ���� Ŭ����
public:
	void insertSort(int* arr, int targetIndex);
private:
	int changeIndex;
};

template <class T>
void InsertSort<T>::insertSort(int* arr, int targetIndex){    // targetIndex == �����ϰ����ϴ� ���� indexNum
	T target = arr[targetIndex];

	for(changeIndex = targetIndex-1; changeIndex>=0; changeIndex--){
		if(arr[changeIndex] > target)                             // ���� ���� ���� ���� target���� ���� Ŭ ���
			arr[changeIndex+1] = arr[changeIndex];           // ���� ���� ���� ���� ������ �ٲ�
		else
			break;                                 // ���� ���Ұ� ������Һ��� ���� ���� ��� sorting ����
	}
	arr[changeIndex+1] = target;           // ���������� �ٲ� ���ҿ� target �� ����
}

#endif /* INSERTSORTING_H_ */
