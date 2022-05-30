#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char *a[],int x);
int main()
{
	int n,len,i;
	char **ptr,a[1001];
	scanf("%d",&n);
	getchar();
	ptr=(char **)malloc(sizeof(char *)*n);
	for(i=0;i<n;i++)
	{
		a[1001]='\0';
		gets(a);
		len=strlen(a);
		ptr[i]=(char *)malloc(sizeof(char)*(len+1));
		strcpy(ptr[i],a);
	} 
	sort(ptr,n);
	for(i=0;i<n;i++)
	{
		puts(ptr[i]);
	}
	for(i=0;i<n;i++)
	free(ptr[i]);
	free(ptr);
	ptr=NULL;
	return 0;
}
void sort(char *a[],int x)
{
	int i,m;
	char *temp;
	for(m=0;m<x;m++)
	{
		for(i=0;i<x-1;i++)
		{
			if(strcmp(a[i],a[i+1])>0)
			{
				temp=a[i+1];
				a[i+1]=a[i];
				a[i]=temp;
			}
		}
	}
}
