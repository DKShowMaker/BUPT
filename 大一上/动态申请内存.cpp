#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*a,i;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);//a��һ��ָ������Ŀռ���׵�ַ����a��
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	a[i]=-a[i]*10;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	free(a);
	a=NULL;
	return 0; 
	
}
