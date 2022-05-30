#include<stdio.h>
int findArray(int *array,int element,int size);
int main()
{
	int n,m,*p1,x,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	int b[m];
	p1=a; 
	for(i=0;i<m;i++)
	scanf("%d",&b[i]);
	for(i=0;i<m;i++)
	{
		x=findArray(p1,b[i],n);
		if(n==1)
		printf("NULL\n");
		else if(x==-1)
		printf("NULL\n");
		else if(x==0)
		printf("%d\n",a[1]);
		else if(x==n-1)
		printf("%d\n",a[n-2]);
		else
		printf("%d %d\n",a[x-1],a[x+1]);
	}
	return 0;
}
int findArray(int *array,int element,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(element==array[i])
		return i;
	}
	return -1;
}
