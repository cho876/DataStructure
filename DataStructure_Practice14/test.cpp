/*
 * 	아주 큰 두 양의 정수(최대 100자리 정수)를 문자열로 읽어 들인 후, 이들 두 수를 더한 결과 값을 구하여(문자열로) 이를 출력하는 프로그램을 작성하시오.

	입력 예 1: 1234 999999999999999999999
	출력 예 1: 1000000000000000001233
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string convertInt(int number)                // 숫자를 문자열로 바꾸기 위한 함수
{
   stringstream ss;          //stringstream 생성
   ss << number;             // 매개변수로 받은 number stream에 추가
   return ss.str();          // stream의 내용을 string(문자열)으로 바꿔 반환
}

string sum(string num1, string num2){
	static int raise = 0;                  // 올림수를 위한 변수
	int num1_value, num2_value = 0;        // 각 문자열의  문자 하나하나를 가리키기 위한 변수
	int total = 0;                       // 두 숫자의 합을 넣기 위한 변수
	int extra = 0;

	if((num1.length() == 0) && (num2.length() == 0))     // 두 문자열의 크기가 모두 0이 될 경우 NULL 반환
		return "";

	else{
		if((num1.length() != 0) && (num2.length() == 0)){    // num1의 문자열은 남았지만 num2의 문자열은 남지 않았을 경우
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());  // num1의 가장 오른쪽 문자 하나를 숫자로 바꿔 저장
			num2_value = 0;                               // num2는 더이상 문자열이 없으므로 0으로 처리
			num1.erase(num1.end()-1);                     // num1의 가장 오른쪽 문자를 숫자로 변환해 저장했으므로 가장 오른쪽 문자 하나 삭제
		}
		else if((num1.length() == 0) && (num2.length() != 0)){   // num2의 문자열은 남았지만 num1의 문자열은 남지 않았을 경우
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());  // num2의 가장 오른쪽 문자 하나를 숫자로 바꿔 저장
			num1_value = 0;                               // num1는 더이상 문자열이 없으므로 0으로 처리
			num2.erase(num2.end()-1);                     // num2의 가장 오른쪽 문자를 숫자로 변환해 저장했으므로 가장 오른쪽 문자 하나 삭제
		}
		else{                                             // num1과 num2의 문자열이 모두 남아있을 경우
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());  // num1의 가장 오른쪽 문자 하나를 숫자로 바꿔 저장
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());  // num2의 가장 오른쪽 문자 하나를 숫자로 바꿔 저장
			num1.erase(num1.end()-1);                     // num1의 가장 오른쪽 문자를 숫자로 변환해 저장했으므로 가장 오른쪽 문자 하나 삭제
			num2.erase(num2.end()-1);                     // num2의 가장 오른쪽 문자를 숫자로 변환해 저장했으므로 가장 오른쪽 문자 하나 삭제
		}
		total = num1_value + num2_value + raise;        // total은 (num1의 변환 값과 num2의 변환값을 더한 값 + 올림수) 저장

		if((num1.length() == 0) && (num2.length() == 0))  // 현재 연산이 두 문자열 연산의 가장 마지막 부분을 처리하는 상황일 경우
			extra = total;                             // 현재 total 값 그대로 extra에 저장
		else{                                         // 아직 연산해야할 부분이 남았을 경우
			extra = total % 10;                       // extra는 total%10(1의 자리 숫자 값)만 받는다.
			raise = total / 10;                      // 9+1 = 10일 경우 0은 extra에 1은 raise(올림수)에 저장
		}
		string num3 = convertInt(extra);            // extra에 해당하는 숫자를 string으로 변환
    return sum(num1, num2) + num3;                 // 이후, base case에 충족할 때 까지 재귀 반복
	}
}

int main(){
	string input1;          // 더할 대상 1
	string input2;          // 더할 대상 2
	cin>>input1>>input2;

	cout<<sum(input1, input2)<<endl;

	return 0;
}
