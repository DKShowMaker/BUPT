#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	if(m<0||n<0)
	printf("error");
	else if(m+n>7)
	{
		printf("error");
	} 
	else if(m+n==7)
	{
		if((n==0&&m>3)||(m==0&&n>3))
		printf("error");
		else 
		{
			if(m>n)
			printf("A win");
			if(m<n)
			printf("B win");
		}
	}
	else if(m+n<7)
	{
		if(m==0&&n==3)
		{
			printf("B win");
		}
		else if(m==3&&n==0)
		{
			printf("A win");
		}
		else if(m==0&&n>3)
		printf("error");
		else if(n==0&&m>3)
		printf("error");
		else 
		{
			printf("no result");
		}
	}
	return 0;
}
