#include<stdio.h>
int main()
{
	int a,b,i;
	b=0;
	a=0;
	i=0;
	char st[101];
	scanf("%s",st);
	while(st[i]!='\0'&&a>=b)
	{
		if(st[i]=='(')
		a=a+1;
		if(st[i]==')')
		b++;
		i++;
	}
	if(a==b)
	printf("parentheses match!");
	else
	printf("parentheses do not match!");
	return 0;
}
