#include<stdio.h>
int main()
{
	char a[2];
	char *p=a;
	gets(a);
	printf("%s",*p);
	return 0;
}
