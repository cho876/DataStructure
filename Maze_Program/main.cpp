/*
 * main.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: Cho
 */

/*
 * Project : 미로(Maze) 찾기 프로그램
 *
 *	- 미로를 찾는 과정을 재귀적으로 구현
	- 한 번 지나온 길은 다시 갈 수 없음.
	- 2차원 배열을 동적으로 입력 받음
	- 상, 하, 좌, 우 방향으로 이동 가능
	- 시작 지점과 목표 지점을 지정
	- 시작 지점과 목표 지점을 연결하는 길이 있는지 확인
	- 0은 갈 수 있는 길
	- 1은 갈 수 없는 길
 */

#include <iostream>
#include "Maze.h"

using namespace std;

int main(){
	Maze M;
	Point source, dest;
	M.createMap();
	cin>>source.row>>source.col>>dest.row>>dest.col;
	if(M.pathExist(source, dest)){
		cout<<"Found"<<endl;
	}
	else
		cout<<"No Found"<<endl;

	return 0;
}
