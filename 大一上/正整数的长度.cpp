#include<stdio.h>
int getDigit(long long n);
int main()
{
	long long x;
	int l;
	scanf("%lld",&x);
	l=getDigit(x);
	if(l==1)
	printf("The integer %lld has 1 digit.",x);
	else
	printf("The integer %lld has %d digits.",x,l);
	return 0;
}
int getDigit(long long n)
{
	int l;
	long long p;
	p=1;
	l=0;
	while(n/p!=0)
	{
		p=p*10;
		l++;
	}
	return l;
}
