#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct STUDENT_STRU
{
	char name[10];
	unsigned int Math_score;
	unsigned int English_score; 
	unsigned int total_score;
};

//����ÿ��ѧ���ܳɼ�������total_score������
void Totalscore(struct STUDENT_STRU a[], int stunum)
{
	for(int i = 0; i <= stunum; i++)
	{
		a[i].total_score=a[i].English_score + a[i].Math_score;
	}
}

//ʹ�ü�ѡ�����򷨶�ѧ���ܳɼ���������
//����low��highΪ������������±귶Χ
void SelectSort(struct STUDENT_STRU a[], int low, int high)
{
//�����벹ȫ����
	int length = high+1;
	int min;
	int pCurrent;
	int p;
	for(p=0;p<length;p++){
		min = p;
		for(pCurrent=min;pCurrent<length;pCurrent++){
			if(a[pCurrent].total_score<a[min].total_score){
				min = pCurrent;
			}
		}
		struct STUDENT_STRU Temp = a[p];
		a[p] = a[min];
		a[min] = Temp;
	}
}

int main()
{
	int  i;
	int stuNum;
	struct STUDENT_STRU StudentStru[10];
	
	printf("Please input the number of items to be sorted��\n");
	scanf("%d", &stuNum);
	
	printf("Please input the name and score of the students��\n");
	for(i = 0; i < stuNum; i++)
	{
		scanf("%s%d %d",StudentStru[i].name,
&StudentStru[i].Math_score, &StudentStru[i].English_score);
	}

	Totalscore(StudentStru, stuNum-1);

	printf("\n");

SelectSort(StudentStru, 0, stuNum-1);
	printf("\n");

	printf("The items sorted by total score are as follows��\n");
	//��ӡ������
	for (i = 0; i < stuNum; i++)
	{
		printf("%s %d\n", StudentStru[i].name, StudentStru[i].total_score);
	}
	
	return 0;
}

