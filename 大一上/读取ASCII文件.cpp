#include<stdio.h>
void task1(FILE *fileptr);
void task2(FILE *fileptr);
void task3(FILE *fileptr);
int main()
{
	FILE *fp=fopen("dict.txt","r");
	int n;
	scanf("%d",&n);
	if(n==1)
	task1(fp);
	if(n==2)
	task2(fp);
	if(n==3)
	task3(fp);
	fclose(fp);
	return 0;
} 
void task1(FILE *fileptr)
{
	int ch=fgetc(fileptr);
	int captial=0, lowercase=0, digit=0, others=0;
	while(ch!=EOF)
	{
		if(65<=ch&&ch<=90)
		captial=captial+1;
		else if(97<=ch&&ch<=122)
		lowercase=lowercase+1;
		else if(48<=ch&&ch<=57)
		digit=digit+1;
		else
		others=others+1;
		ch=fgetc(fileptr);
	}
	printf("Task1:\n");
	printf("capital: %d\n",captial);
	printf("lowercase: %d\n",lowercase);
	printf("digit: %d\n",digit);
	printf("others: %d\n",others);
}
void task2(FILE *fileptr)
{
	rewind(fileptr);
	int ch=fgetc(fileptr);
	int chara=0, line=1, max, min;
	while(ch!=10&&ch!=EOF)//累加第一行的字符数 
	{
		chara=chara+1;
		ch=fgetc(fileptr);
	}
	max=chara;
	min=chara;
	while(ch!=EOF)
	{ 
		chara=0;
		while(ch!=10&&ch!=EOF)
		{
			chara=chara+1;
			ch=fgetc(fileptr);
		}
		if(ch==10)
		line=line+1;
		if(chara>max)
		max=chara;
		if(chara<min&&chara!=0)
		min=chara;
		ch=fgetc(fileptr);
    }
	printf("Task2:\n");
	printf("line: %d\n",line);
	printf("%d characters in max line.\n",max);
	printf("%d characters in min line.\n",min);
}
void task3(FILE *fileptr)
{
	rewind(fileptr);
	int ch=fgetc(fileptr);
	int capital[26];
	int lowercase[26];
	int i,n,m;
	char c=65;//输出时的A或者a为起始值 
	for(i=0;i<26;i++)//数组初始化 
	{
		capital[i]=0;
		lowercase[i]=0;
	}
	while(ch!=EOF)
	{
		if(ch>=65&&ch<=90)
		{
			n=ch-65;
			capital[n]=capital[n]+1;
		} 
		else if(97<=ch&&ch<=122)
		{
			m=ch-97;
			lowercase[m]=lowercase[m]+1;
		}
		ch=fgetc(fileptr);
	}
	printf("Task3:\n");
	printf("CAPITAL:\n");
	for(i=0;i<26;i++)
	{
		printf("%c:%d\n",c,capital[i]);
		c=c+1;
	} 
	printf("LOWERCASE:\n");
	c=97;
	for(i=0;i<26;i++)
	{
		printf("%c:%d\n",c,lowercase[i]);
		c=c+1;
	}
}
