#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,i,e,j;
	char str1[101]={0};
	char str2[101]={0};
	gets(str1);
	gets(str2);
	i=0;
	j=0;
	d=0;
	while(str2[i]!='\0')
	{
		i++;
	}
	e=i-1;
	while(str1[j]!='\0')
	{
		j++;
	}
	char str3[i+1]={0};
	for(a=0;a<=j-i;a++)
	{
		e=e-i+1;
		for(b=0;b<i;b++)
		{
			str3[b]=str1[e];
			e++;
		}
		c=strcmp(str2,str3);
		if(c==0)
		d++; 
	}
	printf("%d",d);
	return 0;
}
