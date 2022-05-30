#include<stdio.h>
#include<string.h> 
int main()
{
	int n,m,i;
	char *x=0;
	scanf("%d",&n);
	char *p[n]={0};
	char a[n][1001]={0};
	getchar();
	for(i=0;i<n;i++)
	gets(a[i]);
	for(i=0;i<n;i++)
	p[i]=&a[i][0];
	for(m=0;m<n;m++)
	{
		for(i=0;i<n-1;i++)
	{
		if(strcmp(p[i],p[i+1])>0)
		{
			x=p[i];
			p[i]=p[i+1];
			p[i+1]=x;
		}
	}
	}
	for(i=0;i<n;i++)
	puts(p[i]);
	return 0;
}
//直接复制数组超时所以改变指针 
