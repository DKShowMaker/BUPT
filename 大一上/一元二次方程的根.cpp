#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d,x1,x2,m,n;
	scanf("%f%f%f",&a,&b,&c);
	d=b*b-4*a*c;
	if (fabs(a-0)<=1e-6)
	printf("The equation is not quadratic.");
	else if(fabs(d-0)<=1e-6)
	{
		x1=-b/(2*a);
	    printf("The equation has two equal roots:%.4f.",x1);
	}
	else if(a!=0&&d>0)
	{
		x1=(-b+sqrt(d))/(2*a);
		x2=(-b-sqrt(d))/(2*a);
		if (x1>x2)
		printf("The equation has two distinct real roots: %.4f and %.4f.",x1,x2);
		if (x1<x2)
		printf("The equation has two distinct real roots: %.4f and %.4f.",x2,x1);
	}
	else if (a>0&&d<0)
	{
		d=-d;
		m=-b/(2*a);
		n=sqrt(d)/(2*a);
		
		printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.",m,n,m,n);
	}
	else if (a<0&&d<0)
	{
		d=-d;
		m=-b/(2*a);
		n=sqrt(d)/(2*a);
		
		printf("The equation has two complex roots: %.4f-%.4fi and %.4f+%.4fi.",m,n,m,n);
	}
	return 0;
}

