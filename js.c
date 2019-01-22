#include<stdio.h>
#include<time.h>
#include<stdlib.h>
char getSignal(){    
    //获取运算符 
    char signal[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    return signal[rand()%4];
}
int random(double start, double end){    
	//获取随机数 
    return (int)(start+(end-start)*rand()/(RAND_MAX+ 1.0));
}
int getResult(int num1,int num2,char signal){
	//结果计算 
    int res;
    switch(signal)
    {
        case '+':
	        res=num1+num2;break;
	    case '-':
	        res=num1-num2;break;
	    case '*':
	        res=num1*num2;break;
	    case '/':
	        res=num1/num2;break;
	    default:
	        printf("运算符错误！\n");
    }
    return res;
}
int takeTest(){  
	//题目生成 
    int get;
    int num1,num2,a;
    char signal;
    srand((unsigned)time(NULL));
    signal=getSignal();
    num1=random(0,100);
    num2=random(1,100);
	if(signal=='-')
	{
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    if(signal=='/')
    {
        if(num2==0)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
    printf("%d%c%d=",num1,signal,num2);
    scanf("%d",&get);
    fflush(stdin);   //清空输入缓冲区
    if(getResult(num1,num2,signal)==get)
    {
    	printf("You're right!\n");
     	a=1;
	}
    else
    {
        printf("It's wrong!\n");
        printf("The right answer is: %d\n",getResult(num1,num2,signal));
        a=0;
    }
    return a;
}
int main() 
{
	int i,n,a,right=0;
    double percent;
    printf("Please enter the numbers of the test:");
    scanf("%d",&n);      
	for(i=0;i<n;i++)
 	{
  		a=takeTest();
    	right=right+a;
     }
     printf("Powerful!\n");
     printf("The number of right:%d\n",right);
     percent=((double)right*100.00)/(double)n;
     printf("The percent of right:%0.2f %%\n",percent);
}
 