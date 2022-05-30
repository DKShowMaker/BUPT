#include<stdio.h>
int main()
{
	int n,m,a,i,b,c,c1,c2,c3,c4,c5;
	scanf("%d%d",&n,&m);
	i=1;
	b=0;
	while(i<=n)
	{
	    a=i/m;
		c1=i/10000;
	    c2=(i-c1*10000)/1000;
	    c3=(i-c1*10000-c2*1000)/100;
		c4=(i-c1*10000-c2*1000-c3*100)/10;
		c5=i%10;
		c=c1*c1+c2*c2+c3*c3+c4*c4+c5*c5;
		if(a==c)
		{
		    printf("%d ",i);
		    b=b+1;
		    if(b%5==0)
		    printf("\n");
		}	
		i=i+1;
	}  
	return 0;
 } 
 /*已知一个整数n，打印1—n所有除以m后所得商正好是它的各个数字平方和的数。*/
