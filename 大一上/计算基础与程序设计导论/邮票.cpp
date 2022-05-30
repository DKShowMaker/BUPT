#include<stdio.h>
int main()
{
	int n,x,y;
	n=1;
	while(n!=-1)
	{
		scanf("%d",&n);
		if(n==-1)
		return 0;
		else if((n%8==0&&n>=8)||(n%8==6)||(n%8==2&&n/8>=2)||(n%8==4&&n/8>=1))
		{
		    if(n%8==0&&n>=8)
		    {
			    x=n/8;
				y=0;
				printf("%d %d\n",x,y);
		    }
			if(n%8==6) 
		    {
				x=(n-6)/8;
		    	y=1;
		    	printf("%d %d\n",x ,y);
		    }
			if(n%8==2&&n/8>=2)
		    {
				y=3;
				x=(n-18)/8;
		    	printf("%d %d\n",x,y);
	        }
	    	if(n%8==4&&n/8>=1)
	        {
	    	    x=n/8-1;
	    		y=2;
	    		printf("%d %d\n",x,y);
	 	    }
		}
		
		else
	    printf("-1\n");
	    
	}
	return 0;
}
