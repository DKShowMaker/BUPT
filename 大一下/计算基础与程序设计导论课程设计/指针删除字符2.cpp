#include<stdio.h>
void delcharfun(char *str,char ch1);
int main()
{
	char str[101],ch1,*ptr=str;
	gets(str);
	scanf("%c",&ch1);
	delcharfun(ptr,ch1);
	return 0;
}
void delcharfun(char *str,char ch)
{
	int i=0,j;
	while(str[i]!='\0')
	{
		if(ch==str[i])
		{
			for(j=i;str[j]!='\0';j++)
			str[j]=str[j+1];
			i=-1;//从头再次判定 
		}
		i++;
	}
	puts(str);
}
