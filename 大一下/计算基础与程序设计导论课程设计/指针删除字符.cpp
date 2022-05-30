#include<stdio.h>
#include<string.h>
void delcharfun(char *str,char ch);
int main()
{
	char str1[101],*p=str1;
	gets(str1);
	char ch1;
	scanf("%c",&ch1);
	delcharfun(p,ch1);
	return 0;
}
void delcharfun(char *str,char ch)
{
	int i,j;
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]==ch)
		{
			j=i;
			while(str[j]!='\0')
			{
				str[j]=str[j+1];
				j++;
			}
			i=-1;
		}
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		printf("%c",str[i]);
		i++;
	}
}
