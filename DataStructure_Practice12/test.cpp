/*
 * 	���� ���� ����(�ִ� 100�ڸ� ����)�� ���ڿ��� �о� ���� ��, �� ���� ��� �ڸ����� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է� �� 1: 999999999999999999999
	��� �� 1: 189
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num){
	int index = num.length()-1;  // ���ڿ��� ũ��-1�� index�� ����

	if(index == 0)               // base case (index = 0  ��, num���ڿ��� �ϳ� ������ ���)
		return atoi(num.substr(0,1).c_str());    // ������ ���� ���ڿ� �ϳ� -> ���������� �ٲ� ��ȯ

	else{                                              // ���ڿ��� �ϳ��� ���� ������ �ݺ�
		int output = atoi(num.substr(0,1).c_str());    // ���� ���ڿ��� ���� ���� ���� �ϳ��� ���������� �ٲ� output�� ����
		num.erase(num.begin());                        // num���ڿ��� ���� ���� ���� �ϳ� ����
		return sum(num) + output;                      // �Ʊ� �����س��� output + ��� �Լ� �ݺ� (base case�� �ش�� ������)
	}
}

int main(){
	string input;        // ����ڷκ��� ���� �Է� (���ڿ��� ����)
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
