/*
 * third.cpp
 *
 *  Created on: 2017. 3. 17.
 *      Author: Cho
 */

#include <iostream>

using namespace std;

int electricCharge(int month, int kwh);      // 청구요금 반환 함수
double getelect200(int kwh);                 // 전력량이 200이하일 경우의 kwh에 따른 기본 요금 반환
double getelect400(int kwh);                 // 전력량이 201~400일 경우의 kwh에 따른 기본 요금 반환
double getelectOver(int month, int kwh);      // 전력량이 400초과일 경우의 kwh에 따른 기본 요금 반환

int getTotal(int elect_pay);                  // 청구요금을 구하기 위한 공통된 식들 따로 저장 및 총 청구요금 반환 (electricCharge에서 받음)

int main()
{
	int month;    // 월 입력
	int pay;      // 사용량

	while(true)
	{
		cin>>month>>pay;
		if(month<13 && month>0 && pay>0)      // month: 1~12월, pay>0 일 경우 다음 명령어 수행
			break;
	}
    int result = electricCharge(month, pay);
	cout<<result<<endl;

	return 0;
}

int electricCharge(int month, int kwh)   // 청구요금 계산 함수
{

	double elect_Total = 0;    // 전력량 요금
	int total_pay = 0;        // 청구요금
	int elect_pay = 0;       // 전기 요금계

	if(kwh<=200)                         // 전력량이 200 이하일 경우
	{
		elect_pay = 910 + 93.3*kwh;
		return getTotal(elect_pay);
	}

	else                                 // 전력량이 200 초과일 경우
	{
		elect_Total = getelect200(200);
		kwh -= 200;
		if(kwh<=200)                        // 전력량이 400 이하일 경우
		{
			elect_Total += getelect400(kwh);
			elect_pay = 1600 + elect_Total;
			return getTotal(elect_pay);
		}
		else                                // 전력량이 400 초과일 경우
		{
			elect_Total += getelect400(200);
			kwh -= 200;
			elect_Total += getelectOver(month, kwh);
			elect_pay = 7300 + elect_Total;
			return getTotal(elect_pay);
		}
	}

    return total_pay;
}

double getelect200(int kwh) {return 93.3*kwh;}
double getelect400(int kwh) {return 187.9*kwh;}

double getelectOver(int month, int kwh)
{
	double elect_total = 0;

	if(month==7 || month==8 || month==12 || month==1 || month==2)  //동, 하계일 경우 (7,8월 / 12~2월)
	{
		if(kwh-600>0)                     // 사용 전력량이 1000kwh 이상일 경우
		{
			kwh -= 600;
			elect_total += 280.6 * 600;
			elect_total += 709.5 * kwh;    // 1000kwh 초과 전력량 요금은 709.5원으로 적용
			return elect_total;
		}
		else                            // 사용 전력량이 1000kwh 미만일 경우
			return 280.6 * kwh;
	}
	else
		return 280.6*kwh;
}

int getTotal(int elect_pay)
{
	int plus_pay = elect_pay*0.1+0.5;    // 부가 가치세
	int base_pay = elect_pay*0.037;      // 기반 요금
	base_pay *= 0.1;
	base_pay *= 10;
	int total_pay = elect_pay+plus_pay+base_pay;  // 청구요금
	total_pay *= 0.1;
	total_pay *= 10;
	return total_pay;
}



