#include<stdio.h>
#include<string.h> 
int main()
{
	int n,i=0,j=1,a=0;
	scanf("%d",&n);
	getchar();
	char str[100001]={0};
	char *p[n]={0};
	char *x;
	scanf("%c",&str[0]);
	p[0]=&str[0];
	while(a<n)
	{
		i++;
		scanf("%c",&str[i]);
		if(str[i]=='\n')
		{
			a++;
			p[j]=&str[i+1];
			str[i]='\0';
			j++;
		}
	}
	for(a=0;a<n;a++)
	{
		for(i=0;i<n-1;i++)
		{
			if(strcmp(p[i],p[i+1])>0)
			{
				x=p[i];
				p[i]=p[i+1];
				p[i+1]=x;
			}
		}
	}
	for(i=0;i<n;i++)
	puts(p[i]);
	return 0;
}
