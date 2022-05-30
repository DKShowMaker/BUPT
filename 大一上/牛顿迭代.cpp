#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	double x3,x2,r,x1;
	x1=1;
	r=1;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x2=x1-(a*x1*x1*x1+b*x1*x1+c*x1+d)/(3*a*x1*x1+2*b*x1+c);
	
	while(r>1e-5)
	{
		
		x3=x2-(a*x2*x2*x2+b*x2*x2+c*x2+d)/(3*a*x2*x2+2*b*x2+c);
		
		r=fabs(x3-x2);
		x2=x3;
		
	}
	printf("%lf",x3);
	return 0;
}
