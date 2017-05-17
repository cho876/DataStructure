#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num1, string num2){
	int num1_length = num1.length();
	if(num1_length == 0)
		return 0;
	else{
		int num1_output = atoi(num1.substr(0,1).c_str());
		int num2_output = atoi(num2.substr(0,1).c_str());
	    num1.erase(num1.begin());
		num2.erase(num2.begin());
		if(num1_output > num2_output)
	    	return 1;
		else if(num1_output < num2_output)
			return -1;
		else
			return sum(num1, num2);
	}
}

int main(){
	string input1;
	string input2;
	cin>>input1>>input2;

	if(input1.length() > input2.length())
		cout<<"1"<<endl;
	else if(input1.length() < input2.length())
		cout<<"-1"<<endl;
	else if(input1 == input2){
		cout<<"0"<<endl;
	}
	else
		cout<<sum(input1, input2)<<endl;
	return 0;
}
