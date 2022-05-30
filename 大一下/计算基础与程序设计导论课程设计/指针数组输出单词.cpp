#include<stdio.h>
int main()
{
	int i,j;
	j=1;
	char str[10001]={0};
	char *ptr[1001]={0};
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		ptr[0]=&str[0];
		if(str[i-1]==' ')
		{
			str[i-1]='\0';
			ptr[j]=&str[i];
			j++;
		}
	}
	for(i=0;ptr[i]!='\0';i++)
	{
		printf("%s",ptr[i]);
		printf("\n");
	}
	return 0;
}
