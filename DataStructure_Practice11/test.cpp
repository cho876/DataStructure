/*
 * 	아주 양의 정수(최대 100자리 정수)를 문자열로 읽어 들인 후, 이 수의 모든 자릿수를 더한 값을 출력하는 프로그램을 작성하시오.

	입력 예 1: 999999999999999999999
	출력 예 1: 189
 */

#include <iostream>

using namespace std;

int sum(int num){            // base case가 만족될 때까지 반복
	if(num/10 == 0)          // base case(num/10이 1의 자리 숫자가 나올 경우 그 값을 반환)
		return num;
	else                             // num이 1의 자리가 아닐 경우 재귀함수 실행
		return sum(num/10) + num%10;      // num%10 (num의 1의 자리 숫자) + sum(num/10) <- num의 1의 자릿 수를 계속해서 잘라냄
}
int main(){
	int input;                   // 사용자로부터 숫자 입력
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
