/*
 * main.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 *
 *      ����: �̷� ����
 *
		- �̷ο��� ������ġ�κ��� �����¿�� ���鼭 ���� ������ ��� ��ġ�� ������ ���ϴ� ���α׷��� �ۼ�
 *
 */

#include <iostream>
#include "Maze.h"

using namespace std;

int main(){
	Maze M;
	Point source;
	M.createMap();
	cin>>source.row>>source.col;
	M.pathExist(source);
	cout<<M.getCount()<<endl;
	return 0;
}


