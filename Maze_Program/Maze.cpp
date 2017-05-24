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
	cin>>m>>n;               // ��: m, ��: n
	map = new int*[m];           // ���� ���� 0�� 1�� ���� ���� (��� ����)
	visited = new bool*[m];      // ���� ���� true�� false�� ���� ���� (������ ��θ� üũ�ϱ� ����)
	for(int i=0; i<m; i++){
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	for(int row = 0; row<m; row++){
		for(int col=0;col<n; col++)
			cin>>map[row][col];            // ���� �� ���� ��� ���� (0: ������ �� �ִ� ��, 1: ������ �� ���� ��
	}
}

bool Maze::pathExist(Point source, Point dest){
	for(int row=0; row<m; row++){
		for(int col=0; col<n; col++)
			visited[row][col] = false;             // visited�� �ʱ� ��: ��� false
	}

	if(map[source.row][source.col]==1 || map[dest.row][dest.col]==1)  // ���� ������ ��ǥ������ �Է��Կ� �־� ��ΰ� �� �� ���� ������ �Է����� ��
		return false;
	else                                         // ���� ������ ��ǥ������ ��� �� �ִٸ� ����
		return pathExistRecur(source, dest);
}

bool Maze::pathExistRecur(Point currentPosition, Point dest)
{
	cout<<currentPosition.row <<" "<<currentPosition.col <<endl;   // ���İ��� ��� ��� ���
	visited[currentPosition.row][currentPosition.col] = true;
	Point nextPosition;
	if(currentPosition.row == dest.row && currentPosition.col==dest.col)   // ��ǥ������ ������ ��, true
		return true;

	if(currentPosition.col+1<=n-1){   // ������
		if(map[currentPosition.row][currentPosition.col+1]==0 && visited[currentPosition.row][currentPosition.col+1]==false){
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col+1;    // currentPosition ���������� 1ĭ �̵�
			if(pathExistRecur(nextPosition, dest)){
				return true;
			}
		}
	}
	if(currentPosition.row-1>=0){    // �� ��
		if(map[currentPosition.row-1][currentPosition.col]==0 && visited[currentPosition.row-1][currentPosition.col]==false){
			nextPosition.row = currentPosition.row-1;   // currentPosition �������� 1ĭ �̵�
			nextPosition.col = currentPosition.col;
			if(pathExistRecur(nextPosition, dest))
				return true;
		}
	}

	if(currentPosition.row+1<=m-1){  // �Ʒ�
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col]==false){
			nextPosition.row = currentPosition.row+1;   // currentPosition �Ʒ��ʷ� 1ĭ �̵�
			nextPosition.col = currentPosition.col;
			if(pathExistRecur(nextPosition, dest))
				return true;
		}
	}

	if(currentPosition.col-1>=0){   // ����
			if(map[currentPosition.row][currentPosition.col-1]==0 && visited[currentPosition.row][currentPosition.col-1]==false){
				nextPosition.row = currentPosition.row;
				nextPosition.col = currentPosition.col-1;   // currentPosition �������� 1ĭ �̵�
				if(pathExistRecur(nextPosition, dest)){
					return true;
				}
			}
	}
	return false;
}
