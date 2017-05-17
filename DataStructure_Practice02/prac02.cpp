#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int);                   // 소수판별 함수
void find(int, vector<int> vlist);   // vlist 중 세개의 소수 찾아 출력하는 함수

int main()
{
	vector<int> vlist;        // 사용자 입력 값까지의 수들 중 소수 값 저장

	int num;
	cin>>num;
	if(num<=5 && num %2 ==0)     // 5보다 작거나 짝수일 경우 프로그램 종료
		return 0;

	for(int i=2; i<=num; i++)
	{
		if(isPrime(i))            // 소수일 경우 vlist에 저장
			vlist.push_back(i);
	}

	find(num, vlist);
	return 0;
}

bool isPrime(int n)
{
	int count=0;
	if(n == 0 || n == 1)           // 0 or 1 소수 아니므로 false 반환
		return false;
	for(int i=1; i<=n; i++)   // 1과 자기 자신을 제외한 다른 값으로 나눠떨어질 경우 false 반환
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

void find(int answer, vector<int> vlist)   // 세 개의 소수 출력
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
