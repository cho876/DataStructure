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
	Maze M;         // Map
	Point source;   // ���� ��
	M.createMap();   // Map ����
	cin>>source.row>>source.col;    // ���� ��ġ ����
	M.pathExist(source);           // ���� ��ġ���� ���� ���� ��ġ ���� Count
	cout<<M.getCount()<<endl;     // �� Count ���� ���
	return 0;
}


