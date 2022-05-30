#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,i,j,d,sum,x,c;
	scanf("%d%d%d",&a,&b,&c);
	i=a;
	d=0;
	x=0;
	sum=0;
	while (a<=i&&i<=b)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			{
				sum=sum+j;
			}
		
		}
		if(fabs(i-sum)<=c)
		{
			printf("%d	",i);
			x++;
			d++;
		}
		
		if(d%5==0)
		printf("\n");
		i++;
		sum=0;
	}
	if(x==0)
	printf("There is no proper number in the interval.");
	return 0;
}
