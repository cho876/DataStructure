#include <iostream>

using namespace std;

int sum(int num){
	if(num/10 == 0)
		return num;
	else
		return sum(num/10) + num%10;
}
int main(){
	int input;
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
