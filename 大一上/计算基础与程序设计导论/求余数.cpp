#include<stdio.h>
int main()
{
	int a,c,d;
	while(a!=-1)
	{
		scanf("%d%d",&a,&d);
		c=a/d;
		printf("%d\n",a-c*d);
	}
	return 0;
}
