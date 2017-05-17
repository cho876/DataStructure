/*
 * test.cpp
 *
 *  Created on: 2017. 5. 17.
 *      Author: Cho
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string sum(string num1, string num2){
	static int raise = 0;
	int num1_value, num2_value = 0;
	int total = 0;
	int extra = 0;
	char ccc[100] = {0};

	if((num1.length() == 0) && (num2.length() == 0))
		return "";

	else{
		if((num1.length() != 0) && (num2.length() == 0)){
			num2_value = 0;
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());
			num1.erase(num1.end()-1);
		}else if((num1.length() == 0) && (num2.length() != 0)){
			num1_value = 0;
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());
			num2.erase(num2.end()-1);
		}else{
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());
			num1.erase(num1.end()-1);
			num2.erase(num2.end()-1);
		}
		total = num1_value + num2_value + raise;

		if((num1.length() == 0) && (num2.length() == 0))
			extra = total;
		else{
			extra = total % 10;
			raise = total / 10;
		}
		string num3 = convertInt(extra);
    return sum(num1, num2) + num3;
	}
}

int main(){
	string input1;
	string input2;
	cin>>input1>>input2;

	cout<<sum(input1, input2)<<endl;

	return 0;
}



