/*
 * 	���� ū �� ���� ����(�ִ� 100�ڸ� ����)�� ���ڿ��� �о� ���� ��, �̵� �� ���� ���� ��� ���� ���Ͽ�(���ڿ���) �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է� �� 1: 1234 999999999999999999999
	��� �� 1: 1000000000000000001233
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string convertInt(int number)                // ���ڸ� ���ڿ��� �ٲٱ� ���� �Լ�
{
   stringstream ss;          //stringstream ����
   ss << number;             // �Ű������� ���� number stream�� �߰�
   return ss.str();          // stream�� ������ string(���ڿ�)���� �ٲ� ��ȯ
}

string sum(string num1, string num2){
	static int raise = 0;                  // �ø����� ���� ����
	int num1_value, num2_value = 0;        // �� ���ڿ���  ���� �ϳ��ϳ��� ����Ű�� ���� ����
	int total = 0;                       // �� ������ ���� �ֱ� ���� ����
	int extra = 0;

	if((num1.length() == 0) && (num2.length() == 0))     // �� ���ڿ��� ũ�Ⱑ ��� 0�� �� ��� NULL ��ȯ
		return "";

	else{
		if((num1.length() != 0) && (num2.length() == 0)){    // num1�� ���ڿ��� �������� num2�� ���ڿ��� ���� �ʾ��� ���
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());  // num1�� ���� ������ ���� �ϳ��� ���ڷ� �ٲ� ����
			num2_value = 0;                               // num2�� ���̻� ���ڿ��� �����Ƿ� 0���� ó��
			num1.erase(num1.end()-1);                     // num1�� ���� ������ ���ڸ� ���ڷ� ��ȯ�� ���������Ƿ� ���� ������ ���� �ϳ� ����
		}
		else if((num1.length() == 0) && (num2.length() != 0)){   // num2�� ���ڿ��� �������� num1�� ���ڿ��� ���� �ʾ��� ���
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());  // num2�� ���� ������ ���� �ϳ��� ���ڷ� �ٲ� ����
			num1_value = 0;                               // num1�� ���̻� ���ڿ��� �����Ƿ� 0���� ó��
			num2.erase(num2.end()-1);                     // num2�� ���� ������ ���ڸ� ���ڷ� ��ȯ�� ���������Ƿ� ���� ������ ���� �ϳ� ����
		}
		else{                                             // num1�� num2�� ���ڿ��� ��� �������� ���
			num1_value = atoi(num1.substr(num1.length()-1,1).c_str());  // num1�� ���� ������ ���� �ϳ��� ���ڷ� �ٲ� ����
			num2_value = atoi(num2.substr(num2.length()-1,1).c_str());  // num2�� ���� ������ ���� �ϳ��� ���ڷ� �ٲ� ����
			num1.erase(num1.end()-1);                     // num1�� ���� ������ ���ڸ� ���ڷ� ��ȯ�� ���������Ƿ� ���� ������ ���� �ϳ� ����
			num2.erase(num2.end()-1);                     // num2�� ���� ������ ���ڸ� ���ڷ� ��ȯ�� ���������Ƿ� ���� ������ ���� �ϳ� ����
		}
		total = num1_value + num2_value + raise;        // total�� (num1�� ��ȯ ���� num2�� ��ȯ���� ���� �� + �ø���) ����

		if((num1.length() == 0) && (num2.length() == 0))  // ���� ������ �� ���ڿ� ������ ���� ������ �κ��� ó���ϴ� ��Ȳ�� ���
			extra = total;                             // ���� total �� �״�� extra�� ����
		else{                                         // ���� �����ؾ��� �κ��� ������ ���
			extra = total % 10;                       // extra�� total%10(1�� �ڸ� ���� ��)�� �޴´�.
			raise = total / 10;                      // 9+1 = 10�� ��� 0�� extra�� 1�� raise(�ø���)�� ����
		}
		string num3 = convertInt(extra);            // extra�� �ش��ϴ� ���ڸ� string���� ��ȯ
    return sum(num1, num2) + num3;                 // ����, base case�� ������ �� ���� ��� �ݺ�
	}
}

int main(){
	string input1;          // ���� ��� 1
	string input2;          // ���� ��� 2
	cin>>input1>>input2;

	cout<<sum(input1, input2)<<endl;

	return 0;
}
