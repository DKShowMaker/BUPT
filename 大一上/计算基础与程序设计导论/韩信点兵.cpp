#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	i=n-1;
	do
	{
		i++;
	}
	while(((i-1)%5!=0)||((i-5)%6!=0)||((i-6)%7!=0)||((i-10)%11!=0));
	printf("%d",i);
	return 0;
}
