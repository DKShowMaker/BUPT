#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
	{
		for(j=0;j<n-i;j=j+1)
		{
			printf(" ");
		}
		
		for(j=0;j<2*i-1;j=j+1)
		{
			printf("*");
		}
		
		printf("\n");
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=0;j<=i-1;j++)
		{
			printf(" ");
		}
		for(j=1;j<=2*(n-i)-1;j++)
		{
			printf("*");
		}
		printf("\n");
    }
    return 0;
}
