#include<stdio.h>
#include<string.h>
int main()
{
	struct student{ 
	
		char name[21]={'\0'};
		char id[21]={'\0'};
		int score[5]={0};
	}stu;
	int i,a,m;
	double average,total=0;
	gets(stu.name);
	gets(stu.id);
	for(i=0;i<5;i++)
	scanf("%d",&stu.score[i]);
	for(m=0;m<5;m++)
	{
		for(i=0;i<4;i++)
		{
			if(stu.score[i]<stu.score[i+1])
			{
				a=stu.score[i+1];
				stu.score[i+1]=stu.score[i];
				stu.score[i]=a;
			}
		}
	}
	for(i=0;i<5;i++)
	total=total+stu.score[i];
	average=total/5;
	printf("Name:%s\n",stu.name);
	printf("ID:%s\n",stu.id);
	printf("Score:%d ",stu.score[0]);
	printf("%d ",stu.score[1]);
	printf("%d ",stu.score[2]);
	printf("%d ",stu.score[3]);
	printf("%d\n",stu.score[4]);
	printf("average:%.2lf total:%.0lf",average,total);
	return 0;
}
