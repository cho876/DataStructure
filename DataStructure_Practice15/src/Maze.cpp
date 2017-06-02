/*
 * Maze.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "Maze.h"

Maze::Maze(){   // 생성자
	count = 0;
};

void Maze::createMap(){        // Map 생성 함수
	cin>>m>>n;           // 총 몇 행 몇 열인지 입력 (행: m, 열: n)
	map = new int*[m];         // 사용자 입력 (행)만큼 map 생성 (0으로 초기화)
	visited = new bool*[m];    // 사용자 입력 (행)만큼 visited 생성 (false로 초기화)
	for(int i=0; i<m; i++){
		map[i] = new int[n];      // 사용자 입력 (열)만큼 map 생성 (0으로 초기화)
		visited[i] = new bool[n]; // 사용자 입력 (열)만큼 visited 생성 (false으로 초기화)
	}

	for(int row = 0; row<m; row++){      // 사용자가 직접 행과 열에 맞게 끔 0과 1을 통해 길 생성
		for(int col = 0; col<n; col++)
			cin>>map[row][col];            // (0: 지나갈 수 있는 길 / 1: 지나갈 수 없는 길)
	}
}

bool Maze::pathExist(Point source){      // 시작 점이 유효한 지 여부 확인 함수
	if(source.row > m-1 || source.col > n-1 || source.row<0 || source.col<0)       // 맵의 범위를 벗어나는 곳을 목적지로 할 경우
		return false;

	for(int row=0; row<m; row++)
		for(int col=0; col<n; col++)
			visited[row][col] = false;    // 왔던 길을 체크하는 visited 배열의 모든 원소 false로 지정

	if(map[source.row][source.col] == 1)  // 만약 사용자가 입력한 시작 점이 1(지나갈 수 없는 길)의 경우 false 반환
		return false;
	else{                                // 이외의 경우 재귀함수로 이동
		return pathExistRecur(source);
	}
}

bool Maze::pathExistRecur(Point currentPosition){     // 재귀를 통한 길 찾기 함수
	++count;      // 유효한 길일 시, count 증가
	visited[currentPosition.row][currentPosition.col] = true;  // 현재 점의 visited를 true로 바꿔줌으로써 다시 현재 점으로 오지 못하도록 차단
	Point nextPosition;   // 다음 Point를 지정하기 위한 객체

	if(currentPosition.row+1 <= m-1){   // 아래쪽으로 이동
		// 현재 점으로부터 아랫쪽 점이 0(도달 가능한 점)이며, false(왔던길이 아닌 점)일 경우
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] == false){
			nextPosition.row = currentPosition.row+1;   // 다음 row = 현재 row + 1
			nextPosition.col = currentPosition.col;     // col은 그대로 (아래로 이동하므로)
			pathExistRecur(nextPosition);    // 다시 재귀
		}
	}

	if(currentPosition.row-1 >= 0){   // 위쪽으로 이동
		// 현재 점으로부터 위쪽 점이 0(도달 가능한 점)이며, false(왔던길이 아닌 점)일 경우
		if(map[currentPosition.row-1][currentPosition.col] == 0 && visited[currentPosition.row-1][currentPosition.col] == false){
			nextPosition.row = currentPosition.row-1;   // 다음 row = 현재 row - 1
			nextPosition.col = currentPosition.col;     // col은 그대로 (위로 이동하므로)
			pathExistRecur(nextPosition);    // 다시 재귀
		}
	}

	if(currentPosition.col+1 <= n-1){   // 오른쪽으로 이동
		// 현재 점으로부터 오른쪽 점이 0(도달 가능한 점)이며, false(왔던길이 아닌 점)일 경우
		if(map[currentPosition.row][currentPosition.col+1] == 0 && visited[currentPosition.row][currentPosition.col+1] == false){
			nextPosition.row = currentPosition.row;   // row는 그대로 (오른쪽으로 이동하므로)
			nextPosition.col = currentPosition.col+1;   // 다음 col = 현재 col + 1
			pathExistRecur(nextPosition);   // 다시 재귀
		}
	}

	if(currentPosition.col-1 >= 0){    // 왼쪽으로 이동
		// 현재 점으로부터 왼쪽 점이 0(도달 가능한 점)이며, false(왔던길이 아닌 점)일 경우
		if(map[currentPosition.row][currentPosition.col-1] == 0 && visited[currentPosition.row][currentPosition.col-1] == false){
			nextPosition.row = currentPosition.row;     // row는 그대로 (왼쪽으로 이동하므로)
			nextPosition.col = currentPosition.col-1;   // 다음 col = 현재 col - 1
			pathExistRecur(nextPosition);   // 다시 재귀
		}
	}
	return true;
}

int Maze::getCount(){return count;}      // 총 도달 가능 점 count 반환 함수


