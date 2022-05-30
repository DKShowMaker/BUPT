#include<stdio.h>
#include<math.h>
double kf(int n,double x);
int main()
{
	int T,n;
	double x,y;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d%lf",&n,&x);
		y=kf(n,x);
		printf("%.3lf\n",y);
		T--;
	}
	return 0;
}
double kf(int n,double x)
{
	double y; 
	if(n==1)
	{
		y=sqrt(1+x);
		return y;
	}
	else
	{
		y=sqrt(n+kf(n-1,x));
		return y;
	}
}

