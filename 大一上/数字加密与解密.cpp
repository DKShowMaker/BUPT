#include<stdio.h>
int main()
{
	int n,f,a,b,c,d,r,s;
	scanf("%d%d",&n,&f);
	a=n/1000;
	b=(n-a*1000)/100;
	c=(n-a*1000-b*100)/10;
	d=n%10;
	r=0;
	s=0;
	if(f==1)
	{
		a=(a+7)%10;
		b=(b+7)%10;
		c=(c+7)%10;
		d=(d+7)%10;
		r=a;
		a=c;
		c=r;
		s=b;
		b=d;
		d=s;
		printf("After encrypting the number is %d%d%d%d",a,b,c,d);
		
	}
	if(f==0)
	{
		a=(a+3)%10;
		b=(b+3)%10;
		c=(c+3)%10;
		d=(d+3)%10;
		r=a;
		a=c;
		c=r;
		s=b;
		b=d;
		d=s;
		printf("After decrypting the number is %d%d%d%d",a,b,c,d);
	}
	return 0;
}
