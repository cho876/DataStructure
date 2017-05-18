/*
 *  ���� ����
 *
 *  �л����� id(���� ����), ����(���� �ƴ� ����), �Ἦ�ϼ�(���� �ƴ� ����)�� �Է��Ͽ� �� �л��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 *  �Ἦ�ϼ��� x��� (-2*x)�� ������ �ݿ��Ѵ�. ��, �Ἦ�ϼ��� 16���� ũ�� ������ F�̴�.
 */
#include <iostream>
#include <cstring>
using namespace std;

struct Student* ascendingArray(int count, struct Student* array);

int getTotal(struct Student std);                    // �л��� ���� ���ϴ� �Լ�
void get_APlus_Count(int, int, struct Student*);     // A+ �л��� ���ϴ� �Լ�
void get_A0_Count(int, struct Student*);        // A0 �л��� ���ϴ� �Լ�
void get_BPlus_Count(int, struct Student*);     // B+ �л��� ���ϴ� �Լ�
void get_B0_Count(int, struct Student*);        // B0 �л��� ���ϴ� �Լ�
void get_CPlus_Count(int, struct Student*);     // C+ �л��� ���ϴ� �Լ�
void get_C0_Count(int, struct Student*);        // C0 �л��� ���ϴ� �Լ�
void get_DPlus_Count(int, struct Student*);     // D+ �л��� ���ϴ� �Լ�
int get_F_Count(int, struct Student*);          // F �л��� ���ϴ� �Լ�

void Rebuild(int stdCount, struct Student*);
void display(int, struct Student*);

struct Student{
	int id; // �й�
	int score; // ����
	int abscentDays; // �Ἦ�ϼ�
	int totalScore; // �� ����
	char grade[3]; //����
};

int main()
{
	int StudentCount;        // �� �л���
	int StudentCount_change;  // F �л��� ������ �л���

	cin>>StudentCount;  // �л� �� �Է�
    if(StudentCount<=0)
    	return 0;

	StudentCount_change = StudentCount;
	Student* stdList = new Student[StudentCount];   // Student ����ü �迭�� StudentCount ��ŭ ���� �Ҵ�


	for(int i=0; i<StudentCount; i++)
	{
		cin>>stdList[i].id>>stdList[i].score>>stdList[i].abscentDays;   // �л� id, ����, �Ἦ�ϼ� �Է�
		if(i>0)
		{
			for(int j=0; j<i; j++)
			{
				if(stdList[i].id == stdList[j].id)             // ���� id �Է� ��, ����
					return 0;
			}
		}
		if(stdList[i].id<0 || stdList[i].score>100 || stdList[i].score<0 || stdList[i].abscentDays<0)  // id, ����, �Ἦ�� �� ����
			return 0;
	}
	for(int k=0; k<StudentCount; k++)
	{
		strcpy(stdList[k].grade, "D0");               // �л����� �ʱ� ������ 'g'�� �ʱ�ȭ
		stdList[k].totalScore = getTotal(stdList[k]);    // �� �л����� ���� ������ getTotal�Լ����� ó���ؼ� ��ȯ
	}

	int F_count = get_F_Count(StudentCount, stdList);  // F ���� �л����� ó���ϰ� F�� ���� �л����� ���� F_count�� ����
	StudentCount_change -= F_count;     // ������ �� �л� �� - F�� ���� �� �л��� = StudentCount_change

	stdList = ascendingArray(StudentCount, stdList);     // �л����� ������ ���������� ó��

	get_APlus_Count(StudentCount_change, StudentCount, stdList);
    get_A0_Count(StudentCount, stdList);
	get_BPlus_Count(StudentCount, stdList);
	get_B0_Count(StudentCount, stdList);
	get_CPlus_Count(StudentCount, stdList);
    get_C0_Count(StudentCount, stdList);
	get_DPlus_Count(StudentCount, stdList);

	Rebuild(StudentCount, stdList);      // F ������ ���� �л��� ó�� �Լ�
	cout<<endl;
	display(StudentCount, stdList);      // ��� â
	return 0;
}

int getTotal(struct Student std)    // �� ���� : ���� + (-2*�Ἦ�ϼ�)
{
	int total = 0;
	total = std.score + (-2*std.abscentDays);
	return total;
}

void get_APlus_Count(int StudentCount_change, int stdCount, struct Student* std)
{
	int same = 0;
	int std_count = 0;
	if(StudentCount_change == stdCount)         // F�� ���� �л��� ������ �л��� �������� ���� ���
	{
		for(int j=1; j<stdCount; j++){
			if(std[j-1].totalScore != std[j].totalScore)     // ��� �л����� ���� ������ �ƴ� ��� ++same
				++same;
		}
		if(same == 0){                                      // ��� �л����� ������ ���� ���
			for(int k=0; k<stdCount;k++)                    // ��� �л����� ���� 'A+'
				strcpy(std[k].grade,"A+");
		}
		else
			for(int i=0; i<(int)(stdCount*0.1+0.5);i++)    // �ƴ� ���
						strcpy(std[i].grade,"A+");
	}
	else{                                           // F�� ���� �л��� ������ �л��� ������ ���
		for(int i = 0; i<stdCount; i++){
			if(std_count<(int)(stdCount*0.1+0.5)){
				strcpy(std[i].grade, "A+");
				++std_count;
			}
			else
				break;
		}
	}
}

void get_A0_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0){     // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
			if(std_count<(int)(stdCount*0.25)-(int)(stdCount*0.1+0.5)){  // ���� 10% �̸� ~ 25% �̻��� ���
	    	    strcpy(std[i].grade, "A0");     // 'A0'
	    	    ++std_count;
     	    }
			else
				break;
		}
	}
}

void get_BPlus_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0){     // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
			if(std_count<(int)(stdCount*0.4+0.5)-(int)(stdCount*0.25)){ // ���� 25% �̸� ~ 40% �̻��� ���
		          strcpy(std[i].grade, "B+");   // 'B+'
		          ++std_count;
            }
			else
				break;
		}
	}
}

void get_B0_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0) {    // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
			if(std_count<(int)(stdCount*0.6)-(int)(stdCount*0.4+0.5)){  // ���� 40% �̸� ~ 60% �̻��� ���
	         	strcpy(std[i].grade, "B0");    // 'B0'
	             ++std_count;
	       	}
			else
				break;
		}
	}
}


void get_CPlus_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0){     // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
			if(std_count<(int)(stdCount*0.8+0.5)-(int)(stdCount*0.6)){  // ���� 60% �̸� ~ 80% �̻��� ���
	    		strcpy(std[i].grade, "C+");     // 'C+'
                 ++std_count;
		   	}
			else
				break;
		}
	}
}

void get_C0_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0){     // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
	        if(std_count<(int)(stdCount*0.9)-(int)(stdCount*0.8+0.5)){  // ���� 80% �̸� ~ 90% �̻��� ���
	       		strcpy(std[i].grade, "C0");    // 'C0'
	   		    ++std_count;
	        }
			else
				break;
		}
	}
}

void get_DPlus_Count(int stdCount, struct Student* std)
{
	int std_count = 0;
	for(int i = 0; i<stdCount; i++){
		if(strcmp(std[i].grade, "D0") == 0){     // ������ �ʱ� ��('D0')�� �Ǿ��ִ� �л��鸸 �Ǻ�
	       	if(std_count<(int)(stdCount*0.95)-(int)(stdCount*0.9)){  // ���� 90% �̸� ~ 95% �̻��� ���
	   			strcpy(std[i].grade, "D+");    // 'D+'
	   		    ++std_count;
	      	}
			else
				break;
		}
	}
}

int get_F_Count(int stdCount, struct Student* std)
{
	int count = 0;
	for(int i = 0; i<stdCount; i++){
		if(std[i].abscentDays>16) {	++count;}   // �Ἦ�� ���� 16���� ���� ��, count(=F�� ���� �л� ��) �߰�
	}
	return count;           // F�� ���� �л��� �� ��ȯ
}

struct Student* ascendingArray(int count, struct Student* array)    // ���� ���� ������������ ���Ľ�Ű�� �Լ�
{
	for(int i = 0; i<count; i++){
		int max = i;
		for(int j = i; j<count; j++){
			if(array[max].totalScore<array[j].totalScore)
				max = j;
		}
		Student temp = array[i];
		array[i] = array[max];
		array[max] = temp;
	}
	return array;
}

void Rebuild(int stdCount, struct Student* std)
{
	for(int i=0; i<stdCount-1; i++)	{
			if(std[i].totalScore == std[i+1].totalScore)     // ������ ���� ���
				strcpy(std[i+1].grade, std[i].grade);       // �ٷ� �� �л��� ������ ������ ������ �ݿ�
	}
	for(int j=0; j<stdCount; j++)	{
			if(std[j].abscentDays>16)                      // �Ἦ�� ���� 16���� ���� ���
				strcpy(std[j].grade, "F");                // F�� ��
	}
}

void display(int count, struct Student* std)
{
	for(int j=0; j<count; j++){                              // �� ������ ���� ��, id�� ���� ������ ���
		for(int k=j+1; k<count; k++){
			if(std[j].totalScore == std[k].totalScore){
				if(std[j].id>std[k].id){
				    int temp = std[j].id;
				    std[j].id = std[k].id;
				    std[k].id = temp;
			    }
			}
			else break;
		}
	}

	for(int i=0; i<count; i++)
		cout<<std[i].id<<" "<<std[i].totalScore<<" "<<std[i].grade<<endl;  // �� ������ ���� ��� �� ���

}
