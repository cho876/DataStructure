/*
 * Maze.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "Maze.h"

Maze::Maze(){
	count = 0;
};

void Maze::createMap(){
	cin>>m>>n;          // 총 몇 행 몇 열인지 입력 (행: m, 열: n)
	map = new int*[m];
	visited = new bool*[n];
	for(int i=0; i<m; i++){
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	for(int row = 0; row<m; row++){
		for(int col = 0; col<n; col++)
			cin>>map[row][col];
	}
}

bool Maze::pathExist(Point source){
	for(int row=0; row<m; row++)
		for(int col=0; col<n; col++)
			visited[row][col] = false;

	if(map[source.row][source.col] == 1)
		return false;
	else{
		return pathExistRecur(source);
	}
}

bool Maze::pathExistRecur(Point currentPosition){
	//cout<<currentPosition.row<<" "<<currentPosition.col<<endl;
	++count;
	visited[currentPosition.row][currentPosition.col] = true;
	Point nextPosition;

	if(currentPosition.row+1 <= m-1)   // 아래쪽
	{
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] == false){
			//cout<<"아랫쪽 이동가능"<<endl;
			nextPosition.row = currentPosition.row+1;
			nextPosition.col = currentPosition.col;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.row-1 >= 0){   // 위쪽
		if(map[currentPosition.row-1][currentPosition.col] == 0 && visited[currentPosition.row-1][currentPosition.col] == false){
			//cout<<"윗쪽 이동가능"<<endl;
			nextPosition.row = currentPosition.row-1;
			nextPosition.col = currentPosition.col;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.col+1 <= n-1){   // 오른쪽
		if(map[currentPosition.row][currentPosition.col+1] == 0 && visited[currentPosition.row][currentPosition.col+1] == false){
			//cout<<"오른쪽 이동가능"<<endl;
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col+1;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.col-1 >= 0){    // 왼쪽
		if(map[currentPosition.row][currentPosition.col-1] == 0 && visited[currentPosition.row][currentPosition.col-1] == false){
			//cout<<"왼쪽 이동가능"<<endl;
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col-1;
			pathExistRecur(nextPosition);
		}
	}
	return true;
}

int Maze::getCount(){return count;}
