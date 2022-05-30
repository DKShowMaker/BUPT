#include<stdio.h>
int main()
{
	int n,p,l,a,i,b;
	scanf("%d",&n);
	p=10;
	l=1;
	a=0;
	i=1;
	b=n;
	while(n/p!=0)
	{
		p=p*10;
		l++; 
	}
	while(l>0)
	{
		a=a+b/(p/10)*i;
		b=b-(b/(p/10))*(p/10);
		l--;
		p=p/10;
		i=i*10;
	}
	
	if(a==n)
	printf("Yes");
	else
	printf("No");
	return 0;
}
/*一个数翻转后相等*/ 
