#include<stdio.h>
int main()
{
	int i,j;
	
	char a;
	char st[101];
	scanf("%s",st);
	for(a='A';a<='Z';a++)
	{
		j=0;
		i=0;
		while(st[i]!='\0')
		{
			if(st[i]==a)
			j++;
			i++;
		}
		if(j!=0)
		printf("The character %c has presented %d times.\n",a,j);
	}
	for(a='a';a<='z';a++)
	{
		j=0;
		i=0;
		while(st[i]!='\0')
		{
			if(st[i]==a)
			j++;
			i++;
		}
		if(j!=0)
		printf("The character %c has presented %d times.\n",a,j);
	}
	return 0;
}
