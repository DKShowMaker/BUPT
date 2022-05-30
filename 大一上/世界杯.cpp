#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct team{
		char name[21];
		int jinqiu;
		int shiqiu;
		int score;
	};
typedef struct team TEAM;
int Comp(TEAM *p1,TEAM *p2);
void Swap(TEAM *p1,TEAM *p2);
void Sort(TEAM *teams,int n) ;
int main()
{
	TEAM team[4];
	int i;
	for(i=0;i<4;i++)
	{
		scanf("%s%d%d%d",&team[i].name,&team[i].jinqiu,&team[i].shiqiu,&team[i].score);
		getchar();
	}
	Sort(team,4);
	for(i=0;i<4;i++)
	printf("%s\n",team[i].name);
	return 0;
}
void Sort(TEAM *teams,int n) 
{
	int i,m;
	for(m=0;m<n;m++)
	{
		for(i=0;i<n-1;i++)
		{
			if(Comp(teams+i,teams+i+1)==1)
			{
				Swap(teams+i,teams+i+1);
			}
		}
	}
}
int Comp(TEAM *p1,TEAM *p2)
{
	if((*p1).score>(*p2).score)
	return 0;
	else if((*p1).score==(*p2).score)
	{
		if(((*p1).jinqiu-(*p1).shiqiu)>((*p2).jinqiu-(*p2).shiqiu))
		return 0;
		else if(((*p1).jinqiu-(*p1).shiqiu)==((*p2).jinqiu-(*p2).shiqiu))
		{
			if((*p1).jinqiu>(*p2).jinqiu)
			return 0;
			else
			return 1;
		}
		else
		return 1;
	}
	else
	return 1;
}
void Swap(TEAM *p1,TEAM *p2)
{
	TEAM temp=*p1;
	*p1=*p2;
	*p2=temp;
}
