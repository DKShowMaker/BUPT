#include<stdio.h>
int main()
{
	int i;
	char st1[101];
	scanf("%s",st1);
	char st2[101];
	scanf("%s",st2);
	char st3[101];
	scanf("%s",st3);
	i=0;
	while(st1[i]!='\0')
	{
		if(st1[i]=='Z')
		st1[i]='A';
		else if(st1[i]=='z')
		st1[i]='a';
		else 
		st1[i]=st1[i]+1;
		i++;
	}
	i=0;
	while(st1[i]!='\0')
	{
		if('A'<=st1[i]&&st1[i]<='Z')
		st1[i]=st2[st1[i]-65];
		if('a'<=st1[i]&&st1[i]<='z')
		st1[i]=st3[st1[i]-97];
		i++;
	}
	puts(st1);
	return 0;
}
