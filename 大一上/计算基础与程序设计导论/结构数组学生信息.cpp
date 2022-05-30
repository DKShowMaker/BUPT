#include<stdio.h>
int main()
{
	struct student{
		char name[21];
		char id[21];
		int score[5];
		double average;
		int total;
	};
	int n,i,j;
	scanf("%d",&n);
	getchar();
	struct student stu[n];
	for(i=0;i<n;i++)
	{
		char name[21]={'\0'};
		char id[21]={'\0'};
		stu[i].total=0;
		gets(stu[i].name);
		gets(stu[i].id);
		for(j=0;j<5;j++)
		{
			scanf("%d",&stu[i].score[j]);
			stu[i].total=stu[i].total+stu[i].score[j];
		}
		stu[i].average=stu[i].total/5.00;
		getchar();
	}
	for(i=0;i<n;i++)
	{
		printf("Name:%s\n",stu[i].name);
		printf("ID:%s\n",stu[i].id);
		printf("Score:");
		for(j=0;j<5;j++)
		printf("%d ",stu[i].score[j]);
		printf("\n");
		printf("average:%.2lf total:%d\n",stu[i].average,stu[i].total);
		printf("\n");
	}
	return 0;
}
