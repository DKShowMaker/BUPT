#include<stdio.h>
int main()
{
	int a,b,c,x,y,z;
	scanf("%d%d%d",&a,&b,&c);
	for(x=0;x<=1000;x++)
	{
		for(y=0;y<=1000;y++)
		{
			if(a*x+b*y==c)
			z++;
		}
	}
	printf("%d",z);
	return 0;
}
