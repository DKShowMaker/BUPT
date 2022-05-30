#include<stdio.h>
#include<math.h>
int main ()
{
	double x,p,result;
	int n;
	scanf ("%lf",&x);
	n=1;
	result=0;
	p=1;
	while(fabs(p)>=1e-8)
	{
		
		result=result+p;
		p=p*(x/n);
		n=n+1;
	}
	printf("%.4lf",result);

}
