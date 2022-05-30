#include<stdio.h>
int main()
{
	int i;
	int b[7]={100,50,20,10,5,2,1}; 
	int a[7]={0};
	int n;
	scanf("%d",&n);
	a[0]=n/100;
	n=n-n/100*100;
	a[1]=n/50;
	n=n-n/50*50;
	a[2]=n/20;
	n=n-n/20*20;
	a[3]=n/10;
	n=n-n/10*10;
	a[4]=n/5;
	n=n-n/5*5;
	a[5]=n/2;
	a[6]=(n%2);
	for(i=0;i<7;i++)
	{
		if(a[i]!=0)
		printf("%d:%d\n",b[i],a[i]);
	}
	return 0;
}
