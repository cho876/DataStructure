/*
 * Maze.h
 *
 *  Created on: 2017. 5. 24.
 *      Author: Cho
 */

#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>

using namespace std;

class Point
{
public:
	int getRow();    // 현재 row 값 출력
	int getCol();    // 현재 column 값 출력
	int row;        // row 변수
	int col;        // col 변수

private:
};

class Maze{
public:
	Maze();     // 생성자
	void createMap();     // Map 생성 함수
	bool pathExist(Point source);    // 시작 점이 유효한 지 여부 확인 함수
	bool pathExistRecur(Point currentPosition);   // 시작 점 유효할 시 재귀를 통한 길 찾기 함수
	int getCount();     // 총 도달 가능 점 count 반환 함수
private:
	int m;     // 행
	int n;     // 열
	int **map;      // 0과 1을 통한 Map 생성을 위한 포인터 변수
	bool **visited;   // true와 false를 통해 왔던 길로 다시 못가도록 하기 위한 포인터 변수
	int count;     // 도달 가능 점 count 변수
};


#endif /* MAZE_H_ */
