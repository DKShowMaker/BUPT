#include<stdio.h>
int main()
{

	const float pi=3.14159;/*���������Ƽ�ʹ��*/ 
	double r;
	double s;
	double d;
	scanf("%lf",&r);
	s=pi*r*r;
	d=2*pi*r;
	
	printf("The perimeter is %.4lf,the area is %.4lf.",d,s);
}

