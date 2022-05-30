#include<stdio.h>
#include<string.h>
char *locatesubstr(char *s1,char *s2,int length);
int main()
{
	char str1[501]={0},str2[501]={0},*p1,*p2,*s3;
	int i=0,l=0;
	p1=str1;
	p2=str2;
	gets(str1);
	gets(str2);
	while(str2[l]!='\0')
	l++;
	s3=locatesubstr(p1,p2,l);
	if(s3!=NULL)
	printf("%s",s3);
	else
	printf("NULL!"); 
	return 0;
}
char *locatesubstr(char *s1,char *s2,int length)
{
	int i,j,x,d;
	x=0;
	char str[length+1]={0};
	i=0;
	while(s1[i]!='\0')
	{
		d=i;
		for(j=0;j<length;j++)
		{
			str[j]=s1[d];
			d++;
		}
		if(strcmp(str,s2)==0)
		return &s1[i];
		else
		x=-1;
		i++;
	}
	if(x==-1)
	return NULL;
}
