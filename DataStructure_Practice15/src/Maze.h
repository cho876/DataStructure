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
	int getRow();    // ���� row �� ���
	int getCol();    // ���� column �� ���
	int row;        // row ����
	int col;        // col ����

private:
};

class Maze{
public:
	Maze();     // ������
	void createMap();     // Map ���� �Լ�
	bool pathExist(Point source);    // ���� ���� ��ȿ�� �� ���� Ȯ�� �Լ�
	bool pathExistRecur(Point currentPosition);   // ���� �� ��ȿ�� �� ��͸� ���� �� ã�� �Լ�
	int getCount();     // �� ���� ���� �� count ��ȯ �Լ�
private:
	int m;     // ��
	int n;     // ��
	int **map;      // 0�� 1�� ���� Map ������ ���� ������ ����
	bool **visited;   // true�� false�� ���� �Դ� ��� �ٽ� �������� �ϱ� ���� ������ ����
	int count;     // ���� ���� �� count ����
};


#endif /* MAZE_H_ */
