#include<stdio.h>
void InsertSort(int [],int x,int a);
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		InsertSort(a,n,i);
		printf("\n");
	}
	return 0;
}
void InsertSort(int b[],int x,int a)
{
	int i,j,k,r,min;
		for(j=a;j>0;j--)
		{
			if(b[j]<b[j-1])
			{
				r=b[j];
				b[j]=b[j-1];
				b[j-1]=r;
			}
		}
	for(i=0;i<x;i++)
	printf("%d ",b[i]);
}
