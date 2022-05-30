#include <stdio.h>
#include<math.h>
int main()
{
	int a;
	int b;
	int c;
	double S,W;
	double area;
	scanf("%d%d%d",&a,&b,&c);
	S=(a+b+c)/2.0;
	
	if(a+b>c&&a+c>b&&b+c>a)
	{
		W=S*(S-a)*(S-b)*(S-c);
		area=sqrt(W);
		printf("%.3lf",area);
	}
	else
	printf("The egdes cannot make up of a triangle.");
	
	return 0;
}
