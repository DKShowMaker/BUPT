#include<stdio.h>
int BinarySearch(int b[],int n,int key);
int main()
{
	int n,m,i,x,y;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		y=BinarySearch(a,n,x);
		printf("%d ",y);
	}
	printf("\n");
	return 0;
}
int BinarySearch(int b[],int n,int key)
{
	int left,right,mid;
	left=0;
	right=n-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(b[mid]<key)
		left=mid+1;
		else if(b[mid]>key)
		right=mid-1;
		else
		return mid;
	}
	mid=-1;
	return mid;
}
