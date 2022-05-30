#include <stdio.h>
#include<math.h>
int main()
{
	char a1;
	char a2;
	char a3;
	
	
	scanf("%c%c%c",&a1,&a2,&a3);
	if ((('a'<=a1&&a1<='z')||('A'<=a1&&a1<='Z'))&&(('a'<=a2&&a2<='z')||('A'<=a2&&a2<='Z'))&&(('a'<=a3&&a3<='z')||('A'<=a3&&a3<='Z')))
	{
	  if ((a1-a2==1||a1-a2==-1)&&(a2-a3==1||a2-a3==-1))
	  printf("Yes");
	  else
	  printf("No");
    }
	else
	printf("No");
	return 0;
}


