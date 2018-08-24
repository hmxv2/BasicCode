//
#include<iostream>
#include<string>
using namespace std;

int get_max_substring_size(const string& s1, const string& s2);
int get_max_subseq_size(const string& s1, const string& s2);


//最长公共子串， LCS(i,j)定义：公共子串满足s1以i结尾，s2以j结尾。
//怎么定义是很重要，如果定义成s1以i结尾，s2以j结尾的串拥有的公共子串的最大长度，则复杂。
//状态转移方程：LCS(i,j)=LCS(i-1,j-1)+1, if s1(i)==s2(j), 否则LCS(i,j)=0
//状态转移方程比较容易想，此处更聪明的是初始值的设计。
//正常思维的话，需要对LCS(i,0)，遍历一遍s1，寻找s1[i]和s2[0]相等的地方，相等则赋值为1，不等则0，LCS(0,j)同理。
//但是如果转换角度，LCS(i,j)设计大一个维度，则可以将LCS(i,-1)和LCS(-1,j)确定为0，然后直接开始状态方程，干脆明了。

//最长公共子序列，此处放在一起比较一下
//LCS(i,j)定义：公共子序列满足s1以i结尾，s2以j结尾，定义依然重要。
//不同之处在于子序列的状态转移方程
//状态转移方程：LCS(i,j)=LCS(i-1,j-1)+1, if s1(i)==s2(j), 否则LCS(i,j)=max(LCS(i-1,j), LCS(i,j-1)), 可见，具有“延续性”
//初始值的设计同上。

int main()
{
	string s1="abcefgkjk";
	string s2="abcfgkefgk";
	
	cout<<get_max_substring_size(s1,s2)<<endl;
	
	cout<<get_max_subseq_size(s1, s2)<<endl;
	//
	system("pause");
	return 0;
}
/*
贴一下debug过程的输出结果，更容易看懂，本质上这是一个在s1，s2的两个长度维度上的一一比对，
结合递推规律很容易理解下面的矩阵。

    a b c f g k e f g k
  0 0 0 0 0 0 0 0 0 0 0
a 0 1 0 0 0 0 0 0 0 0 0
b 0 0 2 0 0 0 0 0 0 0 0
c 0 0 0 3 0 0 0 0 0 0 0
e 0 0 0 0 0 0 0 1 0 0 0
f 0 0 0 0 1 0 0 0 2 0 0
g 0 0 0 0 0 2 0 0 0 3 0
k 0 0 0 0 0 0 3 0 0 0 4
j 0 0 0 0 0 0 0 0 0 0 0
k 0 0 0 0 0 0 1 0 0 0 1
4
    a b c f g k e f g k
  0 0 0 0 0 0 0 0 0 0 0
a 0 1 1 1 1 1 1 1 1 1 1
b 0 1 2 2 2 2 2 2 2 2 2
c 0 1 2 3 3 3 3 3 3 3 3
e 0 1 2 3 3 3 3 4 4 4 4
f 0 1 2 3 4 4 4 4 5 5 5
g 0 1 2 3 4 5 5 5 5 6 6
k 0 1 2 3 4 5 6 6 6 6 7
j 0 1 2 3 4 5 6 6 6 6 7
k 0 1 2 3 4 5 6 6 6 6 7

*/


int get_max_substring_size(const string& s1, const string& s2)
{
	int s1_length=s1.length();
	int s2_length=s2.length();
	//LCS矩阵大小是(s_length+1)*(s_length+1)，长宽均比字符串大1
	int **lcs=new int*[s1_length+1];
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i]=new int[s2_length+1];
	}
	//根据dp初始化条件，初始化lcs第一行和第一列
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i][0]=0;
	}
	for(int i=0;i<s2_length+1;i++)
		lcs[0][i]=0;


	//填充lcs接下来的行和列
	for(int i=1;i<s1_length+1;i++)
	{
		for(int j=1;j<s2_length+1;j++)
		{
			if((s1[i-1]==s2[j-1]))//lcs[1][1]对应的是取字符串第一个的情况
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				
			}
			else
			{
				lcs[i][j]=0;
			}
		}
	}
	//max
	int max_match_substring=0;
	for(int i=0;i<s1_length+1;i++)
	{
		for(int j=0;j<s2_length+1;j++)
		{
			if(lcs[i][j]>max_match_substring)
				max_match_substring=lcs[i][j];
		}
	}
	//debug
	
	for(int i=0;i<s1_length+1;i++)
	{
		if(i==0)
		{
			cout<<"    ";
			for(int j=0;j<s2_length;j++)
			{
				cout<<s2[j]<<" ";
			}
			cout<<endl<<"  ";
		}
		if(i>=1)
		{
			cout<<s1[i-1]<<" ";
		}
		for(int j=0;j<s2_length+1;j++)
		{
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}
	//手动释放，共s1_length+1个指针
	for(int i=0;i<s1_length+1;i++)
	{
		delete lcs[i];
	}

	return max_match_substring;
}

//公共子序列
int get_max_subseq_size(const string& s1, const string& s2)
{
	int s1_length=s1.length();
	int s2_length=s2.length();
	//LCS矩阵大小是(s_length+1)*(s_length+1)，长宽均比字符串大1
	int **lcs=new int*[s1_length+1];
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i]=new int[s2_length+1];
	}
	//根据dp初始化条件，初始化lcs第一行和第一列
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i][0]=0;
	}
	for(int i=0;i<s2_length+1;i++)
		lcs[0][i]=0;


	//填充lcs接下来的行和列
	for(int i=1;i<s1_length+1;i++)
	{
		for(int j=1;j<s2_length+1;j++)
		{
			if((s1[i-1]==s2[j-1]))//lcs[1][1]对应的是取字符串第一个的情况
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				
			}
			else
			{
				lcs[i][j]=lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];//取两个中的最大
			}
		}
	}
	//max，其实可以把max的寻找放在上面一起执行的
	int max_match_subseq=0;//初始值可以是0
	for(int i=0;i<s1_length+1;i++)
	{
		for(int j=0;j<s2_length+1;j++)
		{
			if(lcs[i][j]>max_match_subseq)
				max_match_subseq=lcs[i][j];
		}
	}
	//debug
	
	for(int i=0;i<s1_length+1;i++)
	{
		if(i==0)
		{
			cout<<"    ";
			for(int j=0;j<s2_length;j++)
			{
				cout<<s2[j]<<" ";
			}
			cout<<endl<<"  ";
		}
		if(i>=1)
		{
			cout<<s1[i-1]<<" ";
		}
		for(int j=0;j<s2_length+1;j++)
		{
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}
	

	return max_match_subseq;

}