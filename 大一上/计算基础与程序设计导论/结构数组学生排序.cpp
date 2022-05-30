#include<stdio.h>
#include<string.h>
int main()
{
	struct student{
		char name[21];
		int score;
	};
	int n,i,m;
	scanf("%d",&n);
	getchar();
	struct student stu[n];
	struct student a;
	for(i=0;i<n;i++)
	{
		scanf("%s",&stu[i].name);
		scanf("%d",&stu[i].score);
	}
	for(m=0;m<n;m++)
	{
		for(i=0;i<n-1;i++)
		{
			if(stu[i].score<stu[i+1].score)
			{
				a=stu[i];
				stu[i]=stu[i+1];
				stu[i+1]=a; 
			}
			else if(stu[i].score==stu[i+1].score)
			{
				if(strcmp(stu[i].name,stu[i+1].name)>0)
				{
					a=stu[i];
					stu[i]=stu[i+1];
					stu[i+1]=a;
				}
			}
		}	
	}
	for(i=0;i<n;i++)
	{
		printf("Name:%s\n",stu[i].name);
		printf("total:%d\n",stu[i].score);
		printf("\n"); 
	}
	return 0;
}
