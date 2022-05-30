#include <stdio.h>
int main()
{
	char a,a1;
	int i;
	i=1;
	while(i==1)
	{
		scanf ("%c",&a);
		if(('a'<=a&&a<='w')||('A'<=a&&a<='W'))
		{
			a1=a+3;
			printf("%c",a1);
		}
	    if(a=='x')
	    {
	    	a1='a';
	    	printf("%c",a1);
		}
		if(a=='y')
		{
			a1='b';
			printf("%c",a1);
		}
		if(a=='z')
		{
			a1='c';
			printf("%c",a1);
		}
		if(a=='X')
	    {
	    	a1='A';
	    	printf("%c",a1);
		}
		if(a=='Y')
		{
			a1='B';
			printf("%c",a1);
		}
		if(a=='Z')
		{
			a1='C';
			printf("%c",a1);
		}
		
	    if(a=='\n')
	    {
	    	i=2;
		}
		
	}
	return 0;
}
