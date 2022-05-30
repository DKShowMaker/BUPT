#include<stdio.h>
FILE *movefp(FILE *fileptr,int linestart);
void del(FILE *startptr,FILE *endptr);
int main()
{
	FILE *fp=fopen("dict.dic","r");
	FILE *curptr=NULL,*endptr=NULL;
	int n,linestart=6,lineend=0,array[5],i;
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		array[i]=fgetc(fp);
	}
	lineend=lineend+array[n-1];
	if(n>=2)
	linestart=array[n-2]+1;
	curptr=movefp(fp,linestart);
	endptr=movefp(curptr,lineend);
	del(curptr,endptr);
	return 0;
} 
FILE *movefp(FILE *fileptr,int linestart)
{
	int ch=fgetc(fileptr),line=1;
	while(line<=linestart-1)
	{
		if(ch==10)
		line++;
		ch=fgetc(fileptr);
	}
}
void del(FILE *startptr,FILE *endptr)
{
	int ch=fgetc(startptr);
	while(startptr!=endptr)
	{
		if(ch==47)
		{
			ch=fgetc(startptr);
			if(ch==47)
			{
				while(ch!=10)
				ch=fgetc(startptr);
				if(ch==10)
				ch=fgetc(startptr);
			}
			else if(ch==42)
			{
				while(ch!=42)
				ch=fgetc(startptr);
				if(ch==42)
				{
					ch=fgetc(startptr);
					while(ch!=47&&startptr!=endptr)
					ch=fgetc(startptr);
					if(ch==47)
					ch=fgetc(startptr);
				}
			}
			else
			{
				printf("%c",ch);
				ch=fgetc(startptr);
			}
		}
		printf("%c",ch);
		ch=fgetc(startptr);
	}
}
