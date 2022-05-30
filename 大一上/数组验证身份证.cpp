#include<stdio.h>
int main()
{
	int T,sum,i;
	char c;
	long long a,d,p;
	scanf("%d",&T);
	int b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int e[11]={1,0,0,9,8,7,6,5,4,3,2};
	while(T>0)
	{
		p=10000000000000000;
		sum=0;
		scanf("%lld",&a);
		scanf("%c",&c);
		if(c=='\n')
		d=a/10;
		else
		d=a;
		for(i=0;i<17;i++)
		{
			sum=sum+(d/p)*b[i];
			d=d%p;
			p=p/10;
		}
		if(c=='\n'&&sum%11!=2)
		{
			if(e[sum%11]==a%10)
			printf("right\n");
			else
			printf("wrong\n");
		}
		else if(c=='\n'&&sum%11==2)
		printf("wrong\n");
		else
		{
			if(sum%11==2&&c=='X')
			printf("right\n");
			else
			printf("wrong\n");
		}
		T--;
	}
	return 0;
}
