/*
 * main.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: Cho
 */

/*
 * Project : �̷�(Maze) ã�� ���α׷�
 *
 *	- �̷θ� ã�� ������ ��������� ����
	- �� �� ������ ���� �ٽ� �� �� ����.
	- 2���� �迭�� �������� �Է� ����
	- ��, ��, ��, �� �������� �̵� ����
	- ���� ������ ��ǥ ������ ����
	- ���� ������ ��ǥ ������ �����ϴ� ���� �ִ��� Ȯ��
	- 0�� �� �� �ִ� ��
	- 1�� �� �� ���� ��
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
