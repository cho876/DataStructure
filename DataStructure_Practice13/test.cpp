#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int sum(string num1, string num2){
	int length = num1.length();               // ������ ���� ���ǵ��� ��� �Ű������� ���� �� ���ڿ��� ũ��� �����Ƿ� num1�̳� num2�� length�� ����
	if(length == 0)                        // �� ���ڿ��� ���̰� 0�� �� ���
		return 0;                          // 0 ��ȯ

	else{                                  // �� ���ڿ��� ���� ���� ���
		int num1_output = atoi(num1.substr(0,1).c_str());  // num1�� ���� ���� ���ڸ� ���ڷ� ��ȯ
		int num2_output = atoi(num2.substr(0,1).c_str());  // num2�� ���� ���� ���ڸ� ���ڷ� ��ȯ
	    num1.erase(num1.begin());                         // num1�� ���� ���� ���ڸ� ����
		num2.erase(num2.begin());                         // num2�� ���� ���� ���ڸ� ����
		if(num1_output > num2_output)                     // ���ڸ� ���ڷ� ��ȯ�� �� ���� ��� �� ��� num1�� ��ȯ ���ڰ� Ŭ ���
	    	return 1;
		else if(num1_output < num2_output)                // num2�� ��ȯ ���ڰ� �� Ŭ ���
			return -1;
		else                                             // ���� ���� ��� �ٽ� ��� �Լ� ����
			return sum(num1, num2);
	}
}

int main(){
	string input1;                            // �� ���1
	string input2;                            // �� ���2
	cin>>input1>>input2;

	if(input1.length() > input2.length())         // �� ��� 1�� �� ��� 2���� ���̰� Ŭ ���
		cout<<"1"<<endl;                          // 1 ���
	else if(input1.length() < input2.length())    // �񱳴�� 2�� �� ��� 1���� ���̰� Ŭ ���
		cout<<"-1"<<endl;                         // -1 ���
	else if(input1 == input2){                    // �� ��� 1�� �� ��� 2�� ���� ���� ���
		cout<<"0"<<endl;                          // 0 ���
	}
	else                                         // �� ���� ���
		cout<<sum(input1, input2)<<endl;         // ����Լ� ����
	return 0;
}
