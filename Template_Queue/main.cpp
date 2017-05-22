/*
 * main.cpp
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#include "Queue.h"

int main()
{
	Queue<int> queue;

	queue.insert(1);
	queue.insert(2);
	queue.insert(3);
	queue.insert(4);
	queue.insert(5);
	queue.printAll();     // 1 2 3 4 5
	cout<<endl;

	queue.remove();
	queue.printAll();     // 2 3 4 5
	cout<<endl;

	cout<<queue.getFront()<<endl;    // 2
	cout<<queue.getRear()<<endl;     // 5
	cout<<queue.getLength()<<endl;   // total length = 4

	return 0;
}
