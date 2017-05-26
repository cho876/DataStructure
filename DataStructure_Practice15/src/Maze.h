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
	int getRow();
	int getCol();
	int row;
	int col;

private:
};

class Maze{
public:
	Maze();
	void createMap();
	bool pathExist(Point source);
	bool pathExistRecur(Point currentPosition);
	int getCount();
private:
	int m;
	int n;
	int **map;
	bool **visited;
	int count;
};


#endif /* MAZE_H_ */
