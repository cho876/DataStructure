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
class InsertSort{                     // 삽입 정렬 클래스
public:
	void insertSort(int* arr, int targetIndex);
private:
	int changeIndex;
};

template <class T>
void InsertSort<T>::insertSort(int* arr, int targetIndex){    // targetIndex == 삽입하고자하는 원소 indexNum
	T target = arr[targetIndex];

	for(changeIndex = targetIndex-1; changeIndex>=0; changeIndex--){
		if(arr[changeIndex] > target)                             // 만약 이전 원소 값이 target보다 값이 클 경우
			arr[changeIndex+1] = arr[changeIndex];           // 원소 값을 이전 원소 값으로 바꿈
		else
			break;                                 // 이전 원소가 현재원소보다 값이 작을 경우 sorting 종료
	}
	arr[changeIndex+1] = target;           // 마지막으로 바꾼 원소에 target 값 저장
}

#endif /* INSERTSORTING_H_ */
