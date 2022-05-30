#include<stdio.h>
#include<stdlib.h> 
int BinarySearch(int *a,int n,int key);
int main()
{
	int n,m,*p,x,a,i;
	scanf("%d",&n);
	scanf("%d",&m);
	p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	scanf("%d",&p[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a);
		x=BinarySearch(p,n,a);
		printf("%d ",x); 
	}
	printf("\n");
	return 0;
}
int BinarySearch(int *a,int n,int key)
{
	int i,left=0,right=n;
	while(left<=right)
	{
		if(key<a[(left+right)/2])
		{
			right=(left+right)/2-1;
		}
		else if(key>a[(left+right)/2])
		left=(left+right)/2+1;
		else
		return (left+right)/2;
	}
	return -1;
}
