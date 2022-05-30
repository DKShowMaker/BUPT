#include<stdio.h>
int main()
{
	int T,x,y,x1,y1,n;
	scanf("%d",&T);
	while(T>0)
	{
		scanf("%d:%d",&x,&y);
		scanf("%d:%d",&x1,&y1);
		if(x1>x)
		n=(x1-x)*60+(y1-y);
		if(x==x1&&y>y1)
		n=24*60+y1-y;
		if(x==x1&&y<=y1)
		n=y1-y;
		if(x1<x)
		n=(24-x+x1)*60+(y1-y);
		printf("%d\n",n);
		T--;
	}
	return 0;
}
