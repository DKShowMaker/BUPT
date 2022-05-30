#include<stdio.h>
int main()
{
	int n,bai,ge,shi,n2;
	scanf ("%d",&n);
	if (n%10==0)
	printf("The number cannot be changed.");
	else
	{
		bai=n/100;
		ge=n%10;
		shi=(n-bai*100-ge)/10;
		n2=ge*100+shi*10+bai;
		printf("%d",n2);
		
	}
	return 0;
 } 
 
