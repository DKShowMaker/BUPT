#include<stdio.h>
int main()
{
	long long int n,m,i,cut,x,length,total1=0,total2=0;
	scanf("%lld%lld",&n,&m);
	long long int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		total1=total1+a[i];
	}
	length=total1/n;
	cut=m/n;
	x=length-cut+3;
	for(i=0;i<n;i++)
	{
		if(a[i]>x) 
		total2=total2+a[i]-x;
	}
	while(total2<m)
	{
		total2=0;
		x=x-1;
		for(i=0;i<n;i++)
		{
			if(a[i]>x) 
			total2=total2+a[i]-x;
		}
	}	
	printf("%lld\n",total2);
	return 0;
}

