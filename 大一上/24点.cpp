#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,T;

	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		k=0;
		for(f=-1;f<=1;f++)
		{
			for(g=-1;g<=1;g++)
			{
				for(h=-1;h<=1;h++)
				{
					for(i=-1;i<=1;i++)
					{
						for(j=-1;j<=1;j++)
						{
							if(24==a*f+b*g+c*h+d*i+e*j)
							k++;	
						}
						
					}	
				} 
			}
		}
		if(k!=0)
		printf("YES\n");
		else
		printf("NO\n");
		T--;
	}
	return 0;
}
