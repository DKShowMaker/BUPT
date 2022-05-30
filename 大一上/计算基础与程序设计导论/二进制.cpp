#include<stdio.h>
int main()
{
	double result,b;
	int p,l,a,n1,n2;
	l=0;
	b=0;
	result=0.0;
	p=1;
	scanf("%d",&n1);
	scanf("%d",&n2);
	a=0;
	if(n2=='\n')
	{
		while((n1/p)!=0)
		{
			p=p*10;
			l++;
			printf("%d 1\n",p);	
		}
	    while(l>=0)
		{
			a=(a+n1/(p/10))*2;
			n1=n1-a*(p/10);
			p=p/10;
			l--;
			printf("%d 1\n",l);	
		}
		printf("%d",a);
	}
	else
	{
		while(n1/p!=0)
		{
			p=p*10;
			l++;
			printf("%d 1\n",l);	
		}
	    while(l>=0)
		{
			a=(a+n1/(p/10))*2;
			n1=n1-a*(p/10);
			p=p/10;
			l--;
			printf("%d\n",l);	
		}
		p=1;
		l=0;
		while(n2/p!=0)
		{
			p=p*10;
			l++; 
		}
		while(l>=0)
		{
			b=(b+n2/(p/10))/2;
			n2=n2-b*(p/10);
			p=p/10;
			l--;
		}
		result=a+b;
		printf("%.6lf",result);
	}
	return 0;
}
/*´íÎó×ö·¨*/ 
