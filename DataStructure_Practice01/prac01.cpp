/*
 *  ���� ����
 *
 *  ���ÿ�(����) ���� ����� ���� ��뷮�� �� �־��� ��, û����ݰ踦 ���ϴ� ���α׷��� �ۼ�
 */

#include <iostream>

using namespace std;

int electricCharge(int month, int kwh);      // û����� ��ȯ �Լ�
double getelect200(int kwh);                 // ���·��� 200������ ����� kwh�� ���� �⺻ ��� ��ȯ
double getelect400(int kwh);                 // ���·��� 201~400�� ����� kwh�� ���� �⺻ ��� ��ȯ
double getelectOver(int month, int kwh);      // ���·��� 400�ʰ��� ����� kwh�� ���� �⺻ ��� ��ȯ

int getTotal(int elect_pay);                  // û������� ���ϱ� ���� ����� �ĵ� ���� ���� �� �� û����� ��ȯ (electricCharge���� ����)

int main()
{
	int month;    // �� �Է�
	int pay;      // ��뷮

	while(true)
	{
		cin>>month>>pay;
		if(month<13 && month>0 && pay>0)      // month: 1~12��, pay>0 �� ��� ���� ��ɾ� ����
			break;
	}
    int result = electricCharge(month, pay);
	cout<<result<<endl;

	return 0;
}

int electricCharge(int month, int kwh)   // û����� ��� �Լ�
{

	double elect_Total = 0;    // ���·� ���
	int total_pay = 0;        // û�����
	int elect_pay = 0;       // ���� ��ݰ�

	if(kwh<=200)                         // ���·��� 200 ������ ���
	{
		elect_pay = 910 + 93.3*kwh;
		return getTotal(elect_pay);
	}

	else                                 // ���·��� 200 �ʰ��� ���
	{
		elect_Total = getelect200(200);
		kwh -= 200;
		if(kwh<=200)                        // ���·��� 400 ������ ���
		{
			elect_Total += getelect400(kwh);
			elect_pay = 1600 + elect_Total;
			return getTotal(elect_pay);
		}
		else                                // ���·��� 400 �ʰ��� ���
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

	if(month==7 || month==8 || month==12 || month==1 || month==2)  //��, �ϰ��� ��� (7,8�� / 12~2��)
	{
		if(kwh-600>0)                     // ��� ���·��� 1000kwh �̻��� ���
		{
			kwh -= 600;
			elect_total += 280.6 * 600;
			elect_total += 709.5 * kwh;    // 1000kwh �ʰ� ���·� ����� 709.5������ ����
			return elect_total;
		}
		else                            // ��� ���·��� 1000kwh �̸��� ���
			return 280.6 * kwh;
	}
	else
		return 280.6*kwh;
}

int getTotal(int elect_pay)
{
	int plus_pay = elect_pay*0.1+0.5;    // �ΰ� ��ġ��
	int base_pay = elect_pay*0.037;      // ��� ���
	base_pay *= 0.1;
	base_pay *= 10;
	int total_pay = elect_pay+plus_pay+base_pay;  // û�����
	total_pay *= 0.1;
	total_pay *= 10;
	return total_pay;
}



