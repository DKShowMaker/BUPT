#include<stdio.h>
int judgeTriangle(int a,int b,int c);
int main()
{
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=judgeTriangle(a,b,c);
	if(d==-1)
	printf("It is not a triangle.");
	if(d==0)
	printf("It is a scalenous triangle.");
	if(d==1)
	printf("It is a right-angled triangle.");
	if(d==2)
	printf("It is an isosceles triangle.");
	if(d==3)
	printf("It is a equilateral triangle.");
	return 0;
}
int judgeTriangle(int a,int b,int c)
{
	int d;
	if(a+b>c&&a+c>b&&b+c>a)
	{
		if(a*a+b*b==c*c||a*a+c*c==b*b||c*c+b*b==a*a)
		d=1;
		else if(a==b&&b==c)
		d=3;
		else if((a==b&&b!=c)||(a==c&&b!=c)||(b==c&&a!=b))
		d=2;
		else
		d=0;
	}
	else
	d=-1;
	return d;
}
