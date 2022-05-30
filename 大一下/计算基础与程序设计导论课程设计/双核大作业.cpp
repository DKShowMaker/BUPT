#include<windows.h>
#include<process.h>
#include<stdio.h>
#include<math.h>
typedef struct threadArgument
{
	char filename[32];
	int  address;
	int  threadID;
}   THREADARGUMENT;
int code[128]={0};
int ir[2][1]={0},ip[2][1]={0},flag[2][1]={0};
int ax[2][8]={0};
int convert2(int [],int TYPE);//������ת��Ϊʮ���� 
int convert1(int [],int SIZE);//�ڴ������ݶ�����תʮ���� 
void transfer(int [],int SIZE,THREADARGUMENT *p);//���ݴ��� 
void add(int [],int SIZE,THREADARGUMENT *p);//�ӷ� 
void subtraction(int [],int SIZE,THREADARGUMENT *p);//���� 
void multi(int [],int SIZE,THREADARGUMENT *p);//�˷� 
void division(int [],int SIZE,THREADARGUMENT *p);//���� 
void And(int [],int SIZE,THREADARGUMENT *p);//�߼��� 
void OR(int [],int SIZE,THREADARGUMENT *p);//�߼��� 
void NOT(int [],int SIZE,THREADARGUMENT *p);//�߼��� 
void compare(int [],THREADARGUMENT *p);//�Ƚ� 
void jump(int [],THREADARGUMENT *p);//��ת 
void input(int [],int SIZE,THREADARGUMENT *p);//���� 
void output(int [],int SIZE,THREADARGUMENT *p);//��� 
void print();//����ڴ� 
void codes();//���������ڴ� 
int memory[2*16384][16]={0};
unsigned __stdcall FunProc (void* pArguments);
HANDLE hMutex1,hMutex2;
HANDLE hMutex;
int tickets=100;
unsigned __stdcall Fun1Proc (void* pArguments); 
unsigned __stdcall Fun2Proc (void* pArguments);
int main()
{
	int i,k=100;//kƱ��   
	HANDLE hThread1, hThread2;//���
	unsigned ThreadID1,ThreadID2;
	THREADARGUMENT th1,th2; 
	for(i=0;i<16;i++)//��Ʊ���浽16384 
	{
		memory[16384][15-i]=k%2;
		k=k/2;
	}
	hMutex1=CreateMutex(NULL,FALSE,NULL);//�ڴ���  
	hMutex2=CreateMutex(NULL,FALSE,NULL);//�����  
	th1.address=0;
	th1.threadID=0;
	strcpy(th1.filename,"dict1.dic");
	th2.address=256;
	th2.threadID=1;
	strcpy(th2.filename,"dict2.dic");
    hThread1=(HANDLE)_beginthreadex(NULL,0,FunProc,(void*)&th1,0,&ThreadID1);   
    hThread2=(HANDLE)_beginthreadex(NULL,0,FunProc,(void*)&th2,0,&ThreadID2);
    WaitForSingleObject(hThread1, INFINITE); 	
    CloseHandle(hThread1); 
    WaitForSingleObject(hThread2, INFINITE); 	
    CloseHandle(hThread2); 
    print();
    return 0;
}
unsigned __stdcall FunProc (void* pArguments)
{
	THREADARGUMENT *p;
	FILE *fp[2];
	p=(THREADARGUMENT *) pArguments;
	fp[p->threadID]=fopen(p->filename,"r");
	int n[32]={0};
	int ch=fgetc(fp[p->threadID]);
	int i=0,j=p->address,m=0,b=0,x=0,judge=1;
	while (ch!=EOF)
	{
		for(i=0;i<16;i++)
		{
			memory[j][i]=ch-48;
			ch=fgetc(fp[p->threadID]);
			if(ch==10)
			{
				ch=fgetc(fp[p->threadID]);
			}
		}
		j++;
	}//����������ڴ� 
	for(m=0,j=p->address;m<32;)
	{
		for(i=0;i<16;i++)
		{
			n[m]=memory[j][i];
			m++;
		}
		j=j+1;
	}
	b=convert2(n,1);
	while(judge==1)//�ж�ִ����������� 
	{
		ir[p->threadID][0]=convert1(n,32);
		ip[p->threadID][0]=ip[p->threadID][0]+4;
		if(b==0)
		judge=0;
		if(b==1)
		transfer(n,32,p);
		if(b==2)
		add(n,32,p);
		if(b==3)
		subtraction(n,32,p);
		if(b==4)
		multi(n,32,p);
		if(b==5)
		division(n,32,p);
		if(b==6)
	    And(n,32,p);
		if(b==7)
		OR(n,32,p);
		if(b==8)
		NOT(n,32,p);
		if(b==9)
		compare(n,p);
		if(b==10)
		jump(n,p);
		if(b==11)
		input(n,32,p);
		if(b==12)
		output(n,32,p);
		if(b==13)
		WaitForSingleObject(hMutex1,INFINITE);
		if(b==14)
		ReleaseMutex(hMutex1);
		if(b==15)
		Sleep(convert2(n,4));
		WaitForSingleObject(hMutex2,INFINITE);
		printf("id = %d\n",p->threadID+1);
		printf("ip = %d\n",ip[p->threadID][0]);
		printf("flag = %d\n",flag[p->threadID][0]);
		printf("ir = %d\n",ir[p->threadID][0]);
		printf("ax1 = %d ax2 = %d ax3 = %d ax4 = %d\n",ax[p->threadID][0],ax[p->threadID][1],ax[p->threadID][2],ax[p->threadID][3]);
		printf("ax5 = %d ax6 = %d ax7 = %d ax8 = %d\n",ax[p->threadID][4],ax[p->threadID][5],ax[p->threadID][6],ax[p->threadID][7]);
		ReleaseMutex(hMutex2);
		j=ip[p->threadID][0]/2+p->address;
		for(m=0;m<32;)
		{
			for(i=0;i<16;i++)
			{
				n[m]=memory[j][i];
				m++;
			}
			j++;
		}
		b=convert2(n,1);
	}
	printf("\n");
	fclose(fp[p->threadID]);//�ر��ļ� 
	_endthreadex(0);//�����߳� 
	return 0;
}
int convert1(int m[],int SIZE)//�ڴ������תʮ���� 
{
	int i=0,a=0;
	for(i=0;i<15;i++)
	a=a+m[15-i]*pow(2,i);
	return a;
}
int convert2(int n[],int TYPE)//������תʮ���� 
{
	int a=0,b=0,c=0,d=0,i=0,m=0;
	for(i=0;i<8;i++)
	m=m+n[7-i]*pow(2,i);
	a=m;//0-7λ 
	m=0;
	for(i=0;i<4;i++)//8-11λ 
	m=m+n[11-i]*pow(2,i);
	b=m;
	m=0;
	for(i=0;i<4;i++)//12-15λ 
	m=m+n[15-i]*pow(2,i);
	c=m;
	m=0;
	for(i=0;i<15;i++)//16-31λ 
	m=m+n[31-i]*pow(2,i);
	d=m-n[16]*pow(2,15);
	if(TYPE==1)
	return a;
	if(TYPE==2)
	return b;
	if(TYPE==3)
	return c;
	if(TYPE==4)
	return d; 
}
void transfer(int n[],int SIZE,THREADARGUMENT *p)//���ݴ��� 
{
	int a=0,i=0,b=0,c=0,temp=0,j=0,d=0;
	b=convert2(n,3);
	d=ax[p->threadID][b-1];
	if(b==0)//������������Ĵ���1-8
	{
		a=convert2(n,2);//�ж�����������Ĵ������ 
		temp=convert2(n,4);
		if(a>=1&&a<=4)
		{
			ax[p->threadID][a-1]=temp;
		}
		else
		{
			ax[p->threadID][a-1]=temp;
		}
	}
	else if(b>=5&&b<=8)//���������ڴ����Ĵ��� 
	{
		a=convert2(n,2);//�ж����ݼĴ��� 
		c=convert1(memory[ax[p->threadID][b-1]],16);
		ax[p->threadID][a-1]=c;
	}
	else if(1<=b&&b<=4)//�������ɼĴ��������ڴ� 
	{
		a=convert2(n,2);//�жϵ�ַ�Ĵ��� 
		for(i=0;i<16;i++)
		{
			memory[ax[p->threadID][a-1]][15-i]=d%2;
			d=d/2;
		}
	}
}
void add(int n[],int SIZE,THREADARGUMENT *p)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//���ݼĴ����� 
		temp=convert2(n,4);//��������ʮ���� 
		ax[p->threadID][a-1]=ax[p->threadID][a-1]+temp;
	}
	else
	{
		a=convert2(n,2);
		ax[p->threadID][a-1]=ax[p->threadID][a-1]+convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void subtraction(int n[], int SIZE,THREADARGUMENT *p)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//���ݼĴ����� 
		temp=convert2(n,4);//��������ʮ���� 
		ax[p->threadID][a-1]=ax[p->threadID][a-1]-temp;
	}
	else
	{
		a=convert2(n,2);
		ax[p->threadID][a-1]=ax[p->threadID][a-1]-convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void multi(int n[],int SIZE,THREADARGUMENT *p)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//���ݼĴ����� 
		temp=convert2(n,4);//��������ʮ���� 
		ax[p->threadID][a-1]=ax[p->threadID][a-1]*temp;
	}
	else
	{
		a=convert2(n,2);
		ax[p->threadID][a-1]=ax[p->threadID][a-1]*convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void division(int n[],int SIZE,THREADARGUMENT *p)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//���ݼĴ����� 
		temp=convert2(n,4);//��������ʮ���� 
		ax[p->threadID][a-1]=ax[p->threadID][a-1]/temp;
	}
	else
	{
		a=convert2(n,2);
		ax[p->threadID][a-1]=ax[p->threadID][a-1]/convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void  And(int n[],int SIZE,THREADARGUMENT *p)
{
	int a=0,temp=0,b=0;
	b=convert2(n,3);//��ַ�Ĵ��� 
	a=convert2(n,2);//���ݼĴ��� 
	if(b==0)
	{
		ax[p->threadID][a-1]=ax[p->threadID][a-1]&&temp;
	}
	else
	{
		ax[p->threadID][a-1]=ax[p->threadID][a-1]&&convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void OR(int n[],int SIZE,THREADARGUMENT *p)
{
	int a=0,temp=0,b=0;
	b=convert2(n,3);//��ַ�Ĵ��� 
	a=convert2(n,2);//���ݼĴ��� 
	if(b==0)
	{
		ax[p->threadID][a-1]=ax[p->threadID][a-1]||temp;
	}
	else
	{
		ax[p->threadID][a-1]=ax[p->threadID][a-1]||convert1(memory[ax[p->threadID][b-1]],16);
	}
}
void NOT(int n[],int SZIE,THREADARGUMENT *p)
{
	int a=0,temp=0,b=0,i;
	b=convert2(n,3);//��ַ�Ĵ��� 
	a=convert2(n,2);//���ݼĴ��� 
	if(b==0)
	{
		ax[p->threadID][a-1]=!ax[p->threadID][a-1];
	}
	else
	{
		temp=convert1(memory[ax[p->threadID][b-1]],16);
		memory[ax[p->threadID][b-1]][15]=!temp;
		for(i=0;i<15;i++)
		memory[ax[p->threadID][b-1]][i]=0;//����λ�ù��� 
	}
}
void compare(int n[],THREADARGUMENT *p)
{
	int a=0,b=0,temp;
	b=convert2(n,3);//��ַ�Ĵ��� 
	a=convert2(n,2);//���ݼĴ��� 
	if(b==0)
	{
		temp=convert2(n,4);
		if(ax[p->threadID][a-1]==temp)
		{
			flag[p->threadID][0]=0;
		}
		else if(ax[p->threadID][a-1]>temp)
		{
			flag[p->threadID][0]=1;
		}
		else 
		{
			flag[p->threadID][0]=-1;
		}
	}
	else
	{
		if(ax[p->threadID][a-1]==convert1(memory[ax[p->threadID][b-1]],16))
		{
			flag[p->threadID][0]=0;
		}
		else if(ax[p->threadID][a-1]>convert1(memory[ax[p->threadID][b-1]],16))
		{
			flag[p->threadID][0]=1;
		}
		else
		{
			flag[p->threadID][0]=-1;
		}
	}
}
void jump(int n[],THREADARGUMENT *p)
{
	int a=0,temp;
	a=convert2(n,3);
	temp=convert2(n,4);//������ 
	if(a==0)
	{
		ip[p->threadID][0]=ip[p->threadID][0]-4+temp;
	}
	if(a==1)
	{
		if(flag[p->threadID][0]==0)
		ip[p->threadID][0]=ip[p->threadID][0]-4+temp;
	} 
	if(a==2)
	{
	 	if(flag[p->threadID][0]==1)
	 	ip[p->threadID][0]=ip[p->threadID][0]-4+temp;
	}
	if(a==3)
	{
	 	if(flag[p->threadID][0]==-1)
	 	ip[p->threadID][0]=ip[p->threadID][0]-4+temp;
	}
}
void input(int n[],int SIZE,THREADARGUMENT *p)
{
	int a;
	a=convert2(n,2);
	printf("in:\n");
	scanf("%d",&ax[p->threadID][a-1]);
}
void output(int n[],int SIZE,THREADARGUMENT *p)
{
	int a;
	a=convert2(n,2);
	printf("out: %d\n",ax[p->threadID][a-1]);
}
void print()
{
	int i,x;
	codes();
	printf("codeSegment :\n");//�������� 
	for(x=0;x<128;)
	{
		for(i=0;i<8;i++)
		{
			printf("%d ",code[x]);
			x++;
		}
		printf("\n"); 
	}
	printf("\n");
	printf("dataSegment :\n");//������ݶ� 
	for(x=0;x<512;)
	{
		for(i=0;i<16;i++)
		{
			printf("%d ",convert1(memory[16384+x],16));
			x=x+2;
		}
		printf("\n");
	}
}
void codes()
{
	int y=0,i,m,x=0;
	int co[32]={0};
	while(x<128) 
	{
		for(m=0;m<32;)
		{
			for(i=0;i<16;i++)
			{
				co[m]=memory[y][i];
				m++;
			}
			y++;
		}//������η���һ���µ����� 
		for(i=0;i<32;i++)
		code[x]=code[x]+co[31-i]*pow(2,i);//��ɶ�����תʮ���� 
		x++;
	}
}
