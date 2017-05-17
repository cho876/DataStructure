/*
 * test.cpp
 *
 *  Created on: 2017. 5. 15.
 *      Author: Cho
 */




#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num){
	int index = num.length()-1;

	if(index == 0)
		return atoi(num.substr(0,1).c_str());
	else{
		int output = atoi(num.substr(0,1).c_str());
		num.erase(num.begin());
		return sum(num) + output;
	}
}

int main(){
	string input;
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
