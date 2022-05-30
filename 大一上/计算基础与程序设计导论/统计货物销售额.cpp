#include<stdio.h>
int main()
{
	int n,d,b,i,j;
	float c;
	scanf("%d",&n);
	float a[6][5]={0};
	while(n>0)
	{
		scanf("%d%d%f",&d,&b,&c);
		a[b-1][d-1]=a[b-1][d-1]+c;
		n--;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		a[i][4]=a[i][j]+a[i][4];
	}
	for(j=0;j<4;j++)
	{
		for(i=0;i<5;i++)
		a[5][j]=a[5][j]+a[i][j];
	}
	for(j=0;j<4;j++)
	a[5][4]=a[5][j]+a[5][4];
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		printf("%.1f	",a[i][j]);
		printf("\n");
	}
	return 0;
}
