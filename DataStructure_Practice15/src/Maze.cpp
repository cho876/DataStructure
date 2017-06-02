/*
 * Maze.cpp
 *
 *  Created on: 2017. 5. 26.
 *      Author: Cho
 */

#include "Maze.h"

Maze::Maze(){   // ������
	count = 0;
};

void Maze::createMap(){        // Map ���� �Լ�
	cin>>m>>n;           // �� �� �� �� ������ �Է� (��: m, ��: n)
	map = new int*[m];         // ����� �Է� (��)��ŭ map ���� (0���� �ʱ�ȭ)
	visited = new bool*[m];    // ����� �Է� (��)��ŭ visited ���� (false�� �ʱ�ȭ)
	for(int i=0; i<m; i++){
		map[i] = new int[n];      // ����� �Է� (��)��ŭ map ���� (0���� �ʱ�ȭ)
		visited[i] = new bool[n]; // ����� �Է� (��)��ŭ visited ���� (false���� �ʱ�ȭ)
	}

	for(int row = 0; row<m; row++){      // ����ڰ� ���� ��� ���� �°� �� 0�� 1�� ���� �� ����
		for(int col = 0; col<n; col++)
			cin>>map[row][col];            // (0: ������ �� �ִ� �� / 1: ������ �� ���� ��)
	}
}

bool Maze::pathExist(Point source){      // ���� ���� ��ȿ�� �� ���� Ȯ�� �Լ�
	if(source.row > m-1 || source.col > n-1 || source.row<0 || source.col<0)       // ���� ������ ����� ���� �������� �� ���
		return false;

	for(int row=0; row<m; row++)
		for(int col=0; col<n; col++)
			visited[row][col] = false;    // �Դ� ���� üũ�ϴ� visited �迭�� ��� ���� false�� ����

	if(map[source.row][source.col] == 1)  // ���� ����ڰ� �Է��� ���� ���� 1(������ �� ���� ��)�� ��� false ��ȯ
		return false;
	else{                                // �̿��� ��� ����Լ��� �̵�
		return pathExistRecur(source);
	}
}

bool Maze::pathExistRecur(Point currentPosition){     // ��͸� ���� �� ã�� �Լ�
	++count;      // ��ȿ�� ���� ��, count ����
	visited[currentPosition.row][currentPosition.col] = true;  // ���� ���� visited�� true�� �ٲ������ν� �ٽ� ���� ������ ���� ���ϵ��� ����
	Point nextPosition;   // ���� Point�� �����ϱ� ���� ��ü

	if(currentPosition.row+1 <= m-1){   // �Ʒ������� �̵�
		// ���� �����κ��� �Ʒ��� ���� 0(���� ������ ��)�̸�, false(�Դ����� �ƴ� ��)�� ���
		if(map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] == false){
			nextPosition.row = currentPosition.row+1;   // ���� row = ���� row + 1
			nextPosition.col = currentPosition.col;     // col�� �״�� (�Ʒ��� �̵��ϹǷ�)
			pathExistRecur(nextPosition);    // �ٽ� ���
		}
	}

	if(currentPosition.row-1 >= 0){   // �������� �̵�
		// ���� �����κ��� ���� ���� 0(���� ������ ��)�̸�, false(�Դ����� �ƴ� ��)�� ���
		if(map[currentPosition.row-1][currentPosition.col] == 0 && visited[currentPosition.row-1][currentPosition.col] == false){
			nextPosition.row = currentPosition.row-1;   // ���� row = ���� row - 1
			nextPosition.col = currentPosition.col;     // col�� �״�� (���� �̵��ϹǷ�)
			pathExistRecur(nextPosition);    // �ٽ� ���
		}
	}

	if(currentPosition.col+1 <= n-1){   // ���������� �̵�
		// ���� �����κ��� ������ ���� 0(���� ������ ��)�̸�, false(�Դ����� �ƴ� ��)�� ���
		if(map[currentPosition.row][currentPosition.col+1] == 0 && visited[currentPosition.row][currentPosition.col+1] == false){
			nextPosition.row = currentPosition.row;   // row�� �״�� (���������� �̵��ϹǷ�)
			nextPosition.col = currentPosition.col+1;   // ���� col = ���� col + 1
			pathExistRecur(nextPosition);   // �ٽ� ���
		}
	}

	if(currentPosition.col-1 >= 0){    // �������� �̵�
		// ���� �����κ��� ���� ���� 0(���� ������ ��)�̸�, false(�Դ����� �ƴ� ��)�� ���
		if(map[currentPosition.row][currentPosition.col-1] == 0 && visited[currentPosition.row][currentPosition.col-1] == false){
			nextPosition.row = currentPosition.row;     // row�� �״�� (�������� �̵��ϹǷ�)
			nextPosition.col = currentPosition.col-1;   // ���� col = ���� col - 1
			pathExistRecur(nextPosition);   // �ٽ� ���
		}
	}
	return true;
}

int Maze::getCount(){return count;}      // �� ���� ���� �� count ��ȯ �Լ�


