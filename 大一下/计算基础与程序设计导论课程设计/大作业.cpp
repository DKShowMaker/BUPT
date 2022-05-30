#include<stdio.h>
#include<math.h>
int ax1[4]={0};//数据寄存器 
int ax5[4]={0};//地址寄存器 
int memory[2*16384][16]={0};//模拟内存 
int ip=0,ir=0,flag=0;//程序计数器 指令寄存器 标志寄存器  
int convert2(int [],int TYPE);//二进制转换为十进制 
int convert1(int [],int SIZE);//内存中数据二进制转十进制 
int code[128]={0};
void transfer(int [],int SIZE);//数据传送 
void add(int [],int SIZE);//加法 
void subtraction(int [],int SIZE);//减法 
void multi(int [],int SIZE);//乘法 
void division(int [],int SIZE);//除法 
void And(int [],int SIZE);//逻辑与 
void OR(int [],int SIZE);//逻辑或 
void NOT(int [],int SIZE);//逻辑否 
void compare(int [],int SIZE);//比较 
void jump(int [],int SIZE);//跳转 
void input(int [],int SIZE);//输入 
void output(int [],int SIZE);//输出 
void codes();//计算代码段内存 
void print();//输出内存 
int main()
{
	FILE *fp=fopen("dict.dic","r");
	int n[32]={0},code[128]={0},co[32]={0};
	int ch=fgetc(fp);
	int i=0,j=0,l=0,a=0,b=0,m=0,x=0,y=2,judge=1;
	while (ch!=EOF)
	{
		for(i=0;i<16;i++)
		{
			memory[j][i]=ch-48;
			ch=fgetc(fp);
			if(ch==10)
			{
				ch=fgetc(fp);
			}
		}
		j++;
	}//将代码存入内存 
	for(m=0,j=0;m<32;)
	{
		for(i=0;i<16;i++)
		{
			n[m]=memory[j][i];
			m++;
		}
		j=j+1;
	}
	b=convert2(n,1);
	while(judge==1)//判断执行命令的类型 
	{
		ir=convert1(n,32);
		ip=ip+4;
		if(b==0)
		judge=0;
		if(b==1)
		transfer(n,32);
		if(b==2)
		add(n,32);
		if(b==3)
		subtraction(n,32);
		if(b==4)
		multi(n,32);
		if(b==5)
		division(n,32);
		if(b==6)
	    And(n,32);
		if(b==7)
		OR(n,32);
		if(b==8)
		NOT(n,32);
		if(b==9)
		compare(n,32);
		if(b==10)
		jump(n,32);
		if(b==11)
		input(n,32);
		if(b==12)
		output(n,32);
		printf("ip = %d\n",ip);
		printf("flag = %d\n",flag);
		printf("ir = %d\n",ir);
		printf("ax1 = %d ax2 = %d ax3 = %d ax4 = %d\n",ax1[0],ax1[1],ax1[2],ax1[3]);
		printf("ax5 = %d ax6 = %d ax7 = %d ax8 = %d\n",ax5[0],ax5[1],ax5[2],ax5[3]);
		j=ip/2;
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
	print();
	return 0;
}
int convert1(int m[],int SIZE)//内存二进制转十进制 
{
	int i=0,a=0;
	for(i=0;i<15;i++)
	a=a+m[15-i]*pow(2,i);
	return a;
}
int convert2(int n[],int TYPE)//二进制转十进制 
{
	int a=0,b=0,c=0,d=0,i=0,m=0;
	for(i=0;i<8;i++)
	m=m+n[7-i]*pow(2,i);
	a=m;//0-7位 
	m=0;
	for(i=0;i<4;i++)//8-11位 
	m=m+n[11-i]*pow(2,i);
	b=m;
	m=0;
	for(i=0;i<4;i++)//12-15位 
	m=m+n[15-i]*pow(2,i);
	c=m;
	m=0;
	for(i=0;i<15;i++)//16-31位 
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
void transfer(int n[],int SIZE)//数据传送 
{
	int a=0,i=0,b=0,c=0,temp=0,j=0,d=0;
	b=convert2(n,3);
	d=ax1[b-1];
	if(b==0)//将立即数存入寄存器1-8
	{
		a=convert2(n,2);//判断立即数存入寄存器序号 
		temp=convert2(n,4);
		if(a>=1&&a<=4)
		{
			ax1[a-1]=temp;
		}
		else
		{
			ax5[a-5]=temp;
		}
	}
	else if(b>=5&&b<=8)//将数据由内存存入寄存器 
	{
		a=convert2(n,2);//判断数据寄存器 
		c=convert1(memory[ax5[b-5]],16);
		ax1[a-1]=c;
	}
	else if(1<=b&&b<=4)//将数据由寄存器存入内存 
	{
		a=convert2(n,2);//判断地址寄存器 
		for(i=0;i<16;i++)
		{
			memory[ax5[a-5]][15-i]=d%2;
			d=d/2;
		}
	}
}
void add(int n[],int SIZE)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//数据寄存器几 
		temp=convert2(n,4);//将立即数十进制 
		ax1[a-1]=ax1[a-1]+temp;
	}
	else
	{
		a=convert2(n,2);
		ax1[a-1]=ax1[a-1]+convert1(memory[ax5[b-5]],16);
	}
}
void subtraction(int n[], int SIZE)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//数据寄存器几 
		temp=convert2(n,4);//将立即数十进制 
		ax1[a-1]=ax1[a-1]-temp;
	}
	else
	{
		a=convert2(n,2);
		ax1[a-1]=ax1[a-1]-convert1(memory[ax5[b-5]],16);
	}
}
void multi(int n[],int SIZE)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//数据寄存器几 
		temp=convert2(n,4);//将立即数十进制 
		ax1[a-1]=ax1[a-1]*temp;
	}
	else
	{
		a=convert2(n,2);
		ax1[a-1]=ax1[a-1]*convert1(memory[ax5[b-5]],16);
	}
}
void division(int n[],int SIZE)
{
	int a=0,i,b,temp;
	b=convert2(n,3);
	if(b==0)
	{
		a=convert2(n,2);//数据寄存器几 
		temp=convert2(n,4);//将立即数十进制 
		ax1[a-1]=ax1[a-1]/temp;
	}
	else
	{
		a=convert2(n,2);
		ax1[a-1]=ax1[a-1]/convert1(memory[ax5[b-5]],16);
	}
}
void  And(int n[],int SIZE)
{
	int a=0,temp=0,b=0;
	b=convert2(n,3);//地址寄存器 
	a=convert2(n,2);//数据寄存器 
	if(b==0)
	{
		ax1[a-1]=ax1[a-1]&&temp;
	}
	else
	{
		ax1[a-1]=ax1[a-1]&&convert1(memory[ax5[b-5]],16);
	}
}
void OR(int n[],int SIZE)
{
	int a=0,temp=0,b=0;
	b=convert2(n,3);//地址寄存器 
	a=convert2(n,2);//数据寄存器 
	if(b==0)
	{
		ax1[a-1]=ax1[a-1]||temp;
	}
	else
	{
		ax1[a-1]=ax1[a-1]||convert1(memory[ax5[b-5]],16);
	}
}
void NOT(int n[],int SZIE)
{
	int a=0,temp=0,b=0,i;
	b=convert2(n,3);//地址寄存器 
	a=convert2(n,2);//数据寄存器 
	if(b==0)
	{
		ax1[a-1]=!ax1[a-1];
	}
	else
	{
		temp=convert1(memory[ax5[b-5]],16);
		memory[ax5[b-5]][15]=!temp;
		for(i=0;i<15;i++)
		memory[ax5[b-5]][i]=0;//其余位置归零 
	}
}
void compare(int n[],int SIZE)
{
	int a=0,b=0,temp;
	b=convert2(n,3);//地址寄存器 
	a=convert2(n,2);//数据寄存器 
	if(b==0)
	{
		temp=convert2(n,4);
		if(ax1[a-1]==temp)
		{
			flag=0;
		}
		else if(ax1[a-1]>temp)
		{
			flag=1;
		}
		else 
		{
			flag=-1;
		}
	}
	else
	{
		if(ax1[a-1]==convert1(memory[ax5[b-5]],16))
		{
			flag=0;
		}
		else if(ax1[a-1]>convert1(memory[ax5[b-5]],16))
		{
			flag=1;
		}
		else
		{
			flag=-1;
		}
	}
}
void jump(int n[],int SIZE)
{
	int a=0,temp;
	a=convert2(n,3);
	temp=convert2(n,4);//立即数 
	if(a==0)
	{
		ip=ip-4+temp;
	}
	if(a==1)
	{
		if(flag==0)
		ip=ip-4+temp;
	} 
	if(a==2)
	{
	 	if(flag==1)
	 	ip=ip-4+temp;
	}
	if(a==3)
	{
	 	if(flag==-1)
	 	ip=ip-4+temp;
	}
}
void input(int n[],int SIZE)
{
	int a;
	a=convert2(n,2);
	printf("in:\n");
	scanf("%d",&ax1[a-1]);
}
void output(int n[],int SIZE)
{
	int a;
	a=convert2(n,2);
	printf("out: %d\n",ax1[a-1]);
}
void print()//输出内存 
{
	codes();
	int x,i;
	printf("codeSegment :\n");//输出代码段 
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
	printf("dataSegment :\n");//输出数据段 
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
void codes()//计算代码段内存 
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
		}//将代码段放入一个新的数组 
		for(i=0;i<32;i++)
		code[x]=code[x]+co[31-i]*pow(2,i);//完成二进制转十进制 
		x++;
	}
}
