#include<stdio.h>
int countBinary(int n);
int main()
{
	int n,m;
	scanf("%d",&n);
	m=countBinary(n);
	printf("%d",m);
	return 0;
}
int countBinary(int n)
{
	if(n<2)
	return 1;
	else
	return 1+countBinary(n/2);
}
