/*
 * 	���� ����
 *
 * 	5���� ū Ȧ���� �־��� ��, �� ���� �� �Ҽ��� ������ ǥ���� �� �ִ����� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
 *	���� �Ҽ��� ���� �� ����� �� �ִ�.
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int);                   // �Ҽ��Ǻ� �Լ�
void find(int, vector<int> vlist);   // vlist �� ������ �Ҽ� ã�� ����ϴ� �Լ�

int main()
{
	vector<int> vlist;        // ����� �Է� �������� ���� �� �Ҽ� �� ����

	int num;
	cin>>num;
	if(num<=5 && num %2 ==0)     // 5���� �۰ų� ¦���� ��� ���α׷� ����
		return 0;

	for(int i=2; i<=num; i++)
	{
		if(isPrime(i))            // �Ҽ��� ��� vlist�� ����
			vlist.push_back(i);
	}

	find(num, vlist);
	return 0;
}

bool isPrime(int n)
{
	int count=0;
	if(n == 0 || n == 1)           // 0 or 1 �Ҽ� �ƴϹǷ� false ��ȯ
		return false;
	for(int i=1; i<=n; i++)   // 1�� �ڱ� �ڽ��� ������ �ٸ� ������ ���������� ��� false ��ȯ
	{
		if(n % i == 0)
		{
			++count;
			if(count>2)
				return false;
		}
	}
	return true;
}

void find(int answer, vector<int> vlist)   // �� ���� �Ҽ� ���
{
	for(int i=0; i<vlist.size();i++)
	{
		for(int j = i; j<vlist.size(); j++)
		{
			for(int k = j; k<vlist.size(); k++)
			{
				if(vlist[i]+vlist[j]+vlist[k] == answer)
				{
					 cout<<vlist[i]<<" "<<vlist[j]<<" "<<vlist[k]<<endl;
					 return;
				}
			}
		}
	}
	cout<<"0"<<endl;
}
