#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=2;i<=n-1;i++)
	{
		j=n%i;
		if(j==0)
		{
			printf("not");
			return 0;
		} 
		
	}
	printf("%d",n);
	return 0;
}
