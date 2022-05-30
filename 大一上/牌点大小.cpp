#include<stdio.h>
#include<string.h>
int point(char c);
int main()
{
	int n,i,j,m,x;
	scanf("%d",&n);
	char a[n][30]={0},b[30]={0};
	int sum[n]={0};
	getchar();
	for(i=0;i<n;i++)
	{
		gets(a[i]);
	}
	for(i=0;i<n;i++)
	{
		j=0;
		while(a[i][j]!='\0')
		{
			sum[i]=sum[i]+point(a[i][j]);
			j++;
		}
	}
	for(m=0;m<n;m++)
	{
		for(i=0;i<n-1;i++)
	{
		if(sum[i]<sum[i+1])
		{
			strcpy(b,a[i]);
			strcpy(a[i],a[i+1]);
			strcpy(a[i+1],b);
			x=sum[i];
			sum[i]=sum[i+1];
			sum[i+1]=x;
		}
	}
	}
	for(i=0;i<n;i++)
	{
		puts(a[i]);
	}
	return 0;
}
int point(char c)
{
	if(c=='3'||c=='4'||c=='5')
	return 1;
	if(c=='6'||c=='7'||c=='8')
	return 2;
	if(c=='9'||c=='T')
	return 3;
	if(c=='J')
	return 4;
	if(c=='Q')
	return 5;
	if(c=='K')
	return 6;
	if(c=='A')
	return 8;
	if(c=='2')
	return 10;
	if(c=='B')
	return 15;
	if(c=='R')
	return 20;
}
