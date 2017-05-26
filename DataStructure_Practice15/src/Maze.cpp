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
	cin>>m>>n;          // �� �� �� �� ������ �Է� (��: m, ��: n)
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

	if(currentPosition.row+1 <= m-1)   // �Ʒ���
	{
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] == false){
			//cout<<"�Ʒ��� �̵�����"<<endl;
			nextPosition.row = currentPosition.row+1;
			nextPosition.col = currentPosition.col;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.row-1 >= 0){   // ����
		if(map[currentPosition.row-1][currentPosition.col] == 0 && visited[currentPosition.row-1][currentPosition.col] == false){
			//cout<<"���� �̵�����"<<endl;
			nextPosition.row = currentPosition.row-1;
			nextPosition.col = currentPosition.col;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.col+1 <= n-1){   // ������
		if(map[currentPosition.row][currentPosition.col+1] == 0 && visited[currentPosition.row][currentPosition.col+1] == false){
			//cout<<"������ �̵�����"<<endl;
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col+1;
			pathExistRecur(nextPosition);
		}
	}

	if(currentPosition.col-1 >= 0){    // ����
		if(map[currentPosition.row][currentPosition.col-1] == 0 && visited[currentPosition.row][currentPosition.col-1] == false){
			//cout<<"���� �̵�����"<<endl;
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col-1;
			pathExistRecur(nextPosition);
		}
	}
	return true;
}

int Maze::getCount(){return count;}
