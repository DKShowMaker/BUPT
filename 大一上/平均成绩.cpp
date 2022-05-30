#include<stdio.h>
int main()
{
	int n,i;
	double average,sum;
	sum=0;
	scanf("%d",&n);
	int score[n]={0};
	for(i=0;i<n;i++)
	{
		scanf("%d",&score[i]);
	}
	for(i=0;i<n;i++)
	sum=sum+score[i];
	average=sum/n;
	printf("%.2lf",average);
}
