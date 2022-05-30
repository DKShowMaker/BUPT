#include<stdio.h>
int main()
{
	int n,r,i;
	scanf("%d",&n);
	int A[n];
	int B[n];
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	for(i=0;i<n;i++)
	scanf("%d",&B[i]);
	for(i=0;i<n;i++)
	{
		r=A[B[i]];
		A[B[i]]=A[i];
		A[i]=r;
	}
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}
