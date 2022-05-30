#include<stdio.h>
main()
{    int a, * aPtr; /*aPtr是一个指向整数的指针*/
      a=7; aPtr=&a;
    printf("The address of a is %p\n"
    	"The value of aPtr is %p\n\n", &a, aPtr );
    printf("The value of a is %d\n"
    	"The value of *aPtr is %d\n\n", a, *aPtr );
} 

