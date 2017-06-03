/*
 * Recursive_Factorial.cpp
 *
 *  Created on: 2017. 6. 3.
 *      Author: Cho
 */

#include <iostream>

using namespace std;


int Factorial(int n){            // Factorial Recursiva Algorithms
	if(n == 1)
		return 1;
	else{
		return n * Factorial(n-1);
	}
}

double SlowPower(double num, int power){      // 거듭 제곱 Recursive Algorithms
	if(power == 1)
		return num;
	else{
		return num * SlowPower(num, power-1);
	}
}

int Fibonacci(int n){              // Fibonacci Recursive Algorithms
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else{
		return Fibonacci(n-2) + Fibonacci(n-1);
	}
}

void Hanoii(int n, char from, char temp, char to){     // Hanoii Recursive Algorithms(막대 3개 기준)
	if(n == 1)
		cout<<"원판 1"<<"을"<<from<<"에서"<<to<<"로 옮긴다."<<endl;
	else{
		Hanoii(n-1, from, to, temp);
		cout<<"원판 "<<n<<"을"<<from<<"에서"<<to<<"로 옮긴다."<<endl;
		Hanoii(n-1, temp, from, to);
	}
}

int main(){
	int fac;
	cin>>fac;
	cout<<"Factorial's value: "<<Factorial(fac)<<endl;

	int num;
	int power;
	cin>>num>>power;
	cout<<"SlowPower's value: "<<SlowPower(num, power)<<endl;

	int fibo;
	cin>>fibo;
	cout<<"Fibonacci's value("<<fibo<<"): "<<Fibonacci(fibo)<<endl;

	cout<<"Hanoii Program "<<endl;
	Hanoii(3,'A','B','C');
	return 0;
}
