#include<stdio.h> 
void changeword(char vocabulary[][11]);
int main(void)
{
	char vocabulary[10][11];
	int i;
	FILE *fp=fopen("dict.dic","r");
	for(i=0;!feof(fp)&&i<10;i++)
    {
    	fgets(vocabulary[i],11,fp);
	}
	changeword(vocabulary);
	fclose(fp);
	return 0;
}
void changeword(char vocabulary[][11])
{
	char string[201];
	int i=0,j=0,n=0,sign=0,judge=1,decide=0;
	fgets(string,201,stdin);
	while(!feof(stdin))
	{    
		n=0;
		sign=0;
		while(string[n]!='\n')
		{
		    for(i=0;i<10&&vocabulary[i][0]!='\0'&&decide==0;i++)
		    {
			    for(j=0;vocabulary[i][j]!='\n'&&sign==1;j++)
			    {
			    	if(vocabulary[i][j]==string[n+sign])
				    sign++;
			    	else
				    judge=0; 
		    	}
			    if(judge==1)
		    	decide=1;	
			    else
			    {
				    judge=1;
				    sign=0;
			    } 
		    }
	    	if(decide==1)
	    	{
	    		printf("!@#$%%^&*");
		    	n=n+sign;
		    	sign=0;
		    	decide=0;
	    	}
	    	else
	    	{ 
	    	    printf("%c",string[n]);
		    	n++;
		    	sign=0;
	    	}
	    }
	    printf("\n");
	    fgets(string,201,stdin);
    }
}
