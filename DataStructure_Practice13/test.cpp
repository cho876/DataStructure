#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num1, string num2){
	int length = num1.length();               // 이전의 여러 조건들의 결과 매개변수로 받은 두 문자열의 크기는 같으므로 num1이나 num2의 length은 같다
	if(length == 0)                        // 두 문자열의 길이가 0이 될 경우
		return 0;                          // 0 반환

	else{                                  // 두 문자열이 남아 있을 경우
		int num1_output = atoi(num1.substr(0,1).c_str());  // num1의 가장 왼쪽 문자를 숫자로 변환
		int num2_output = atoi(num2.substr(0,1).c_str());  // num2의 가장 왼쪽 문자를 숫자로 반환
	    num1.erase(num1.begin());                         // num1의 가장 왼쪽 문자를 삭제
		num2.erase(num2.begin());                         // num2의 가장 왼쪽 문자를 삭제
		if(num1_output > num2_output)                     // 문자를 숫자로 변환한 두 숫자 대소 비교 결과 num1의 변환 문자가 클 경우
	    	return 1;
		else if(num1_output < num2_output)                // num2의 변환 문자가 더 클 경우
			return -1;
		else                                             // 서로 같을 경우 다시 재귀 함수 실행
			return sum(num1, num2);
	}
}

int main(){
	string input1;                            // 비교 대상1
	string input2;                            // 비교 대상2
	cin>>input1>>input2;

	if(input1.length() > input2.length())         // 비교 대상 1이 비교 대상 2보다 길이가 클 경우
		cout<<"1"<<endl;                          // 1 출력
	else if(input1.length() < input2.length())    // 비교대상 2가 비교 대상 1보다 길이가 클 경우
		cout<<"-1"<<endl;                         // -1 출력
	else if(input1 == input2){                    // 비교 대상 1과 비교 대상 2의 값이 같을 경우
		cout<<"0"<<endl;                          // 0 출력
	}
	else                                         // 그 밖의 경우
		cout<<sum(input1, input2)<<endl;         // 재귀함수 실행
	return 0;
}
