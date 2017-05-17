#include <iostream>
#include <cstring>
using namespace std;

struct Student* ascendingArray(int count, struct Student* array);

int getTotal(struct Student std);                    // 학생의 총점 구하는 함수
void get_APlus_Count(int, int, struct Student*);     // A+ 학생을 구하는 함수
void get_A0_Count(int, struct Student*);        // A0 학생을 구하는 함수
void get_BPlus_Count(int, struct Student*);     // B+ 학생을 구하는 함수
void get_B0_Count(int, struct Student*);        // B0 학생을 구하는 함수
void get_CPlus_Count(int, struct Student*);     // C+ 학생을 구하는 함수
void get_C0_Count(int, struct Student*);        // C0 학생을 구하는 함수
void get_DPlus_Count(int, struct Student*);     // D+ 학생을 구하는 함수
int get_F_Count(int, struct Student*);          // F 학생을 구하는 함수

void Rebuild(int stdCount, struct Student*);
void display(int, struct Student*);

struct Student{
	int id; // 학번
	int score; // 점수
	int abscentDays; // 결석일수
	int totalScore; // 총 점수
	char grade[3]; //학점
};

int main()
{
	int StudentCount;        // 총 학생수
	int StudentCount_change;  // F 학생을 제외한 학생수

	cin>>StudentCount;  // 학생 수 입력
    if(StudentCount<=0)
    	return 0;

	StudentCount_change = StudentCount;
	Student* stdList = new Student[StudentCount];   // Student 구조체 배열을 StudentCount 만큼 동적 할당


	for(int i=0; i<StudentCount; i++)
	{
		cin>>stdList[i].id>>stdList[i].score>>stdList[i].abscentDays;   // 학생 id, 점수, 결석일수 입력
		if(i>0)
		{
			for(int j=0; j<i; j++)
			{
				if(stdList[i].id == stdList[j].id)             // 동일 id 입력 시, 종료
					return 0;
			}
		}
		if(stdList[i].id<0 || stdList[i].score>100 || stdList[i].score<0 || stdList[i].abscentDays<0)  // id, 점수, 결석일 수 조건
			return 0;
	}
	for(int k=0; k<StudentCount; k++)
	{
		strcpy(stdList[k].grade, "D0");               // 학생들의 초기 학점을 'g'로 초기화
		stdList[k].totalScore = getTotal(stdList[k]);    // 각 학생들의 최종 점수를 getTotal함수에서 처리해서 반환
	}

	int F_count = get_F_Count(StudentCount, stdList);  // F 학점 학생들을 처리하고 F를 받은 학생들의 수를 F_count에 저장
	StudentCount_change -= F_count;     // 기존의 총 학생 수 - F를 받은 총 학생수 = StudentCount_change

	stdList = ascendingArray(StudentCount, stdList);     // 학생들의 점수를 내림차순을 처리

	get_APlus_Count(StudentCount_change, StudentCount, stdList);
    get_A0_Count(StudentCount, stdList);
	get_BPlus_Count(StudentCount, stdList);
	get_B0_Count(StudentCount, stdList);
	get_CPlus_Count(StudentCount, stdList);
    get_C0_Count(StudentCount, stdList);
	get_DPlus_Count(StudentCount, stdList);

	Rebuild(StudentCount, stdList);      // F 학점을 받은 학생들 처리 함수
	cout<<endl;
	display(StudentCount, stdList);      // 출력 창
	return 0;
}

int getTotal(struct Student std)    // 총 점수 : 성적 + (-2*결석일수)
{
	int total = 0;
	total = std.score + (-2*std.abscentDays);
	return total;
}

void get_APlus_Count(int StudentCount_change, int stdCount, struct Student* std)
{
	int same = 0;
	int std_count = 0;
	if(StudentCount_change == stdCount)         // F를 받은 학생을 제외한 학생이 존재하지 않을 경우
	{
		for(int j=1; j<stdCount; j++){
			if(std[j-1].totalScore != std[j].totalScore)     // 모든 학생들이 같은 점수가 아닐 경우 ++same
				++same;
		}
		if(same == 0){                                      // 모든 학생들이 점수가 같을 경우
			for(int k=0; k<stdCount;k++)                    // 모든 학생들의 학점 'A+'
				strcpy(std[k].grade,"A+");
		}
		else
			for(int i=0; i<(int)(stdCount*0.1+0.5);i++)    // 아닐 경우
						strcpy(std[i].grade,"A+");
	}
	else{                                           // F를 받은 학생을 제외한 학생이 존재할 경우
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
		if(strcmp(std[i].grade, "D0") == 0){     // 학점이 초기 값('D0')로 되어있는 학생들만 판별
			if(std_count<(int)(stdCount*0.25)-(int)(stdCount*0.1+0.5)){  // 상위 10% 미만 ~ 25% 이상일 경우
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
		if(strcmp(std[i].grade, "D0") == 0){     // 학점이 초기 값('D0')로 되어있는 학생들만 판별
			if(std_count<(int)(stdCount*0.4+0.5)-(int)(stdCount*0.25)){ // 상위 25% 미만 ~ 40% 이상일 경우
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
		if(strcmp(std[i].grade, "D0") == 0) {    // 학점이 초기 값('D0')로 되어있는 학생들만 판별
			if(std_count<(int)(stdCount*0.6)-(int)(stdCount*0.4+0.5)){  // 상위 40% 미만 ~ 60% 이상일 경우
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
		if(strcmp(std[i].grade, "D0") == 0){     // 학점이 초기 값('D0')로 되어있는 학생들만 판별
			if(std_count<(int)(stdCount*0.8+0.5)-(int)(stdCount*0.6)){  // 상위 60% 미만 ~ 80% 이상일 경우
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
		if(strcmp(std[i].grade, "D0") == 0){     // 학점이 초기 값('D0')로 되어있는 학생들만 판별
	        if(std_count<(int)(stdCount*0.9)-(int)(stdCount*0.8+0.5)){  // 상위 80% 미만 ~ 90% 이상일 경우
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
		if(strcmp(std[i].grade, "D0") == 0){     // 학점이 초기 값('D0')로 되어있는 학생들만 판별
	       	if(std_count<(int)(stdCount*0.95)-(int)(stdCount*0.9)){  // 상위 90% 미만 ~ 95% 이상일 경우
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
		if(std[i].abscentDays>16) {	++count;}   // 결석일 수가 16일을 넘을 시, count(=F를 받은 학생 수) 추가
	}
	return count;           // F를 받은 학생들 수 반환
}

struct Student* ascendingArray(int count, struct Student* array)    // 성적 기준 내림차순으로 정렬시키는 함수
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
			if(std[i].totalScore == std[i+1].totalScore)     // 점수가 같을 경우
				strcpy(std[i+1].grade, std[i].grade);       // 바로 위 학생의 학점과 동일한 학점을 반영
	}
	for(int j=0; j<stdCount; j++)	{
			if(std[j].abscentDays>16)                      // 결석일 수가 16일이 넘을 경우
				strcpy(std[j].grade, "F");                // F를 줌
	}
}

void display(int count, struct Student* std)
{
	for(int j=0; j<count; j++){                              // 총 점수가 같을 시, id가 낮은 순으로 출력
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
		cout<<std[i].id<<" "<<std[i].totalScore<<" "<<std[i].grade<<endl;  // 총 점수에 따른 결과 값 출력

}
