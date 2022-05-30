#include<stdio.h>
int main()
{
	int T,N,a,max,max2;
	scanf("%d",&T);
	while(T>0)
	{
		max=1;
		max2=0;
		scanf("%d",&N);
		while(N>0)
		{
			scanf("%d",&a);
			if(a>max)
			{
				max2=max;
				max=a;
			} 
			else if(a>max2)
			max2=a;
			N--;
		}
		printf("%d %d\n",max,max2);
		T--;
	}
	return 0;
}
