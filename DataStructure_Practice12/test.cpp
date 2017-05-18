/*
 * 	아주 양의 정수(최대 100자리 정수)를 문자열로 읽어 들인 후, 이 수의 모든 자릿수를 더한 값을 출력하는 프로그램을 작성하시오.

	입력 예 1: 999999999999999999999
	출력 예 1: 189
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num){
	int index = num.length()-1;  // 문자열의 크기-1을 index에 저장

	if(index == 0)               // base case (index = 0  즉, num문자열이 하나 남았을 경우)
		return atoi(num.substr(0,1).c_str());    // 마지막 남은 문자열 하나 -> 정수형으로 바꿔 반환

	else{                                              // 문자열이 하나가 남기 전까지 반복
		int output = atoi(num.substr(0,1).c_str());    // 현재 문자열의 가장 왼쪽 문자 하나를 정수형으로 바꿔 output에 저장
		num.erase(num.begin());                        // num문자열의 가장 왼쪽 문자 하나 삭제
		return sum(num) + output;                      // 아까 저장해놓은 output + 재귀 함수 반복 (base case에 해당될 때까지)
	}
}

int main(){
	string input;        // 사용자로부터 숫자 입력 (문자열로 받음)
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
