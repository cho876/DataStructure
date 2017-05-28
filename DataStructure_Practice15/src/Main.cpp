/*
 * main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 *
 *      주제: 미로 문제
 *
		- 미로에서 시작위치로부터 상하좌우로 가면서 도달 가능한 모든 위치의 개수를 구하는 프로그램을 작성
 *
 */

#include <iostream>
#include "Maze.h"

using namespace std;

int main(){
	Maze M;         // Map
	Point source;   // 시작 점
	M.createMap();   // Map 생성
	cin>>source.row>>source.col;    // 시작 위치 지정
	M.pathExist(source);           // 시작 위치부터 도달 가능 위치 갯수 Count
	cout<<M.getCount()<<endl;     // 총 Count 갯수 출력
	return 0;
}


