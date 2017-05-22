/*
 * main.cpp
 *
 *  Created on: 2017. 5. 22.
 *      Author: Cho
 */

#include "Stack.h"
#include <string>

int main(){
	Stack<string> stack;

	stack.push("A");       // insert A
	stack.push("B");       // insert B
	stack.push("C");       // insert C

	stack.printAll();      // C B A
	cout<<endl;

	stack.pop();           // delete C
	stack.printAll();      // B A
	cout<<endl;

	cout<<stack.peek()<<endl;  // B
	return 0;
}
