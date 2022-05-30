#include<stdio.h>
void SelectSort(int [],int x,int y); 
int findMin(int data[], int startLoc, int endLoc) ;
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		SelectSort(a,n,i);
		printf("\n");
	}
	return 0;
}
void SelectSort(int b[],int x,int y)
{
	int min,r,i;
	min=findMin(b,y,x-1);
	if(y!=min)
	{
		r=b[y];
		b[y]=b[min];
		b[min]=r;
	}
	for(i=0;i<x;i++)
	printf("%d ",b[i]);
}
int findMin(int data[], int startLoc, int endLoc)
{
	int min,i;
	min=startLoc;
	for(i=startLoc+1;i<=endLoc;i++)
	{
		if(data[i]<data[min])
		min=i;
	}
	return min;
}
