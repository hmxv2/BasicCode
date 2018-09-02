#include<iostream>
using namespace std;

//网易2018春招的笔试题
/*
售票员在电影院门口卖票，一开始手里没有零钱可以找零。
票价是50元，A拿着100元，B拿着50元，现在A有m(m<20)人，B有n(n<20)人
售票员卖票找零必须从B手里拿零钱找给A。
针对具体的mn的值，问AB有多少种排列方式
*/
//此处所有的A都是同样的人，不考虑内部排序。

const int size=21;
void sell_ticket(int dp[][size]);
int f(int , int);
int main()
{
	int dp[21][21];

	sell_ticket(dp);

	cout<<dp[10][20]<<endl;
	cout<<f(10,20)<<endl;
	system("pause");
	return 0;
}
//递归方式
int f(int n, int m) //n是100元的
{  
    int g;  
    if (n==0) //100元的1个都没有，那么就只有50元的人就只有1种排法  
      g=1;  
    else if (n>m)  //100元的 人比50元的人还要多，则 没有排法  
      g=0;  
     else    //符合的情况下，从最后一个人看起，假如他是拿100元的  
            //那么前n+m-1个人中有n-1个人拿100元，m个拿50元,假如他是   
            // 拿50元的，那么前n+m-1个人中 m-1个拿50的，n个拿100的    
      g=f(n-1,m)+f(n,m-1);  
      return g;  
}  

//dp方式
void sell_ticket(int dp[][size]) //m是100元的
{  
	//初始化为0，除非n为0的时才初始化为1，因为100的没有人，所以50的可以构成排列
	for (int i=0;i<size; i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i==0)
				dp[i][j]=1;
			else
				dp[i][j]=0;
		}
	}
	//只有在50的人数大于等于100的人数时才有可能找零。
	for(int m=0;m<size;m++)
	{
		for(int n=0;n<size;n++)
		{
			if(m!=0 && m<=n)
			{
				dp[m][n]=dp[m-1][n]+dp[m][n-1];
				//在上一个状态转移过来，是两种情况：1，来的人是A，从f(m-1,n)转移，来的人是B，从f(m,n-1)转移。
			}
		}
	}
}