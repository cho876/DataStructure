/*
 * Maze.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: Cho
 */

#include "Maze.h"

Maze::Maze(){}

void Maze::createMap()
{
	cin>>m>>n;               // 행: m, 열: n
	map = new int*[m];           // 실제 맵을 0과 1을 통해 생성 (경로 설정)
	visited = new bool*[m];      // 실제 맵을 true와 false를 통해 생성 (지나간 경로를 체크하기 위함)
	for(int i=0; i<m; i++){
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	for(int row = 0; row<m; row++){
		for(int col=0;col<n; col++)
			cin>>map[row][col];            // 실제 맵 내의 경로 설정 (0: 지나갈 수 있는 길, 1: 지나갈 수 없는 길
	}
}

bool Maze::pathExist(Point source, Point dest){
	for(int row=0; row<m; row++){
		for(int col=0; col<n; col++)
			visited[row][col] = false;             // visited의 초기 값: 모두 false
	}

	if(map[source.row][source.col]==1 || map[dest.row][dest.col]==1)  // 시작 지점과 목표지점을 입력함에 있어 경로가 될 수 없는 지점을 입력했을 시
		return false;
	else                                         // 시작 지점과 목표지점이 경로 상에 있다면 실행
		return pathExistRecur(source, dest);
}

bool Maze::pathExistRecur(Point currentPosition, Point dest)
{
	cout<<currentPosition.row <<" "<<currentPosition.col <<endl;   // 거쳐가는 모든 경로 출력
	visited[currentPosition.row][currentPosition.col] = true;
	Point nextPosition;
	if(currentPosition.row == dest.row && currentPosition.col==dest.col)   // 목표지점에 도착할 시, true
		return true;

	if(currentPosition.col+1<=n-1){   // 오른쪽
		if(map[currentPosition.row][currentPosition.col+1]==0 && visited[currentPosition.row][currentPosition.col+1]==false){
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col+1;    // currentPosition 오른쪽으로 1칸 이동
			if(pathExistRecur(nextPosition, dest)){
				return true;
			}
		}
	}
	if(currentPosition.row-1>=0){    // 위 쪽
		if(map[currentPosition.row-1][currentPosition.col]==0 && visited[currentPosition.row-1][currentPosition.col]==false){
			nextPosition.row = currentPosition.row-1;   // currentPosition 위쪽으로 1칸 이동
			nextPosition.col = currentPosition.col;
			if(pathExistRecur(nextPosition, dest))
				return true;
		}
	}

	if(currentPosition.row+1<=m-1){  // 아래
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col]==false){
			nextPosition.row = currentPosition.row+1;   // currentPosition 아래쪽로 1칸 이동
			nextPosition.col = currentPosition.col;
			if(pathExistRecur(nextPosition, dest))
				return true;
		}
	}

	if(currentPosition.col-1>=0){   // 왼쪽
			if(map[currentPosition.row][currentPosition.col-1]==0 && visited[currentPosition.row][currentPosition.col-1]==false){
				nextPosition.row = currentPosition.row;
				nextPosition.col = currentPosition.col-1;   // currentPosition 왼쪽으로 1칸 이동
				if(pathExistRecur(nextPosition, dest)){
					return true;
				}
			}
	}
	return false;
}
