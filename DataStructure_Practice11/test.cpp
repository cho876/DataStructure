/*
 * 	���� ���� ����(�ִ� 100�ڸ� ����)�� ���ڿ��� �о� ���� ��, �� ���� ��� �ڸ����� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	�Է� �� 1: 999999999999999999999
	��� �� 1: 189
 */

#include <iostream>

using namespace std;

int sum(int num){            // base case�� ������ ������ �ݺ�
	if(num/10 == 0)          // base case(num/10�� 1�� �ڸ� ���ڰ� ���� ��� �� ���� ��ȯ)
		return num;
	else                             // num�� 1�� �ڸ��� �ƴ� ��� ����Լ� ����
		return sum(num/10) + num%10;      // num%10 (num�� 1�� �ڸ� ����) + sum(num/10) <- num�� 1�� �ڸ� ���� ����ؼ� �߶�
}
int main(){
	int input;                   // ����ڷκ��� ���� �Է�
	cin>>input;

	cout<<sum(input)<<endl;
	return 0;
}
