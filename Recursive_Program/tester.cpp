/*
 * Recursive_Factorial.cpp
 *
 *  Created on: 2017. 6. 3.
 *      Author: Cho
 */

#include <iostream>

using namespace std;

int GCD(int n1, int n2){         // GCD Recursive Algorithms
	if(n1 < n2)
		GCD(n2, n1);
	else{
		int result = n1 % n2;
		if(result == 0)
			return n2;
		else
			return GCD(n2, result);
	}
}

int Factorial(int n){            // Factorial Recursiva Algorithms
	if(n == 1)
		return 1;
	else{
		return n * Factorial(n-1);
	}
}

double SlowPower(double num, int power){      // �ŵ� ���� Recursive Algorithms
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

void Hanoii(int n, char from, char temp, char to){     // Hanoii Recursive Algorithms(���� 3�� ����)
	if(n == 1)
		cout<<"���� 1"<<"��"<<from<<"����"<<to<<"�� �ű��."<<endl;
	else{
		Hanoii(n-1, from, to, temp);
		cout<<"���� "<<n<<"��"<<from<<"����"<<to<<"�� �ű��."<<endl;
		Hanoii(n-1, temp, from, to);
	}
}

int main(){
	int num1, num2;
	cin>>num1>>num2;
	cout<<"GCD's value: "<<GCD(num1, num2)<<endl;

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