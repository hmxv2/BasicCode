//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_length_increasing_sub_str(int *a, int n, int *max_lengths, int *max_length_sub_str);

//最长字串，和最长递增子序列的不同是字串需要连接在一起，子序列可以有其他元素间隔
//相对最长递增子序列要简单一些

//按动态规划的思想，设立一个数组max_lengths表示以当前i结尾的串中最长的串的长度；
//初始状态是1，递推式是对当前第i个元素，找出上个元素是否和当前构成递增，是则可以长度+1
//然后从中再筛选出最大的。
//遍历一遍即可，故该方法复杂度O(n)
//顺便考虑下将路径记下来，last_idxs，方便回溯出具体的最小子串是什么

int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_lengths=new int[n];//保存数组以当前为结尾的话最长子串的长度
	int* max_length_sub_str=new int[n];//记下最长子串的具体构成

	int max_length = max_length_increasing_sub_str(a, n, max_lengths, max_length_sub_str);

	cout<<"max length: "<<max_length<<endl;

	for(int i=0;i<max_length;i++)
	{
		cout<<max_length_sub_str[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_length_increasing_sub_str(int *a, int n, int *max_lengths, int *max_length_sub_str)
{
	int *last_idxs = new int[n];

	for (int i=0;i<n;i++)//初始化
	{
		last_idxs[i]=-1;
		max_length_sub_str[i]=-1;
		max_lengths[i]=1;
	}
	for(int i=1;i<n;i++)//比较简单，只需要和前一个比较，是递增的话则在上一个的基础上+1
	{
		if(a[i]>a[i-1])
		{
			max_lengths[i]=max_lengths[i-1]+1;
			last_idxs[i]=i-1;
		}
	}
	//开始寻找最大值，都是常规操作
	int max_length=max_lengths[0];
	int max_length_idx=0;
	for (int i=0;i<n;i++)
	{
		if (max_lengths[i]>max_length)
		{
			max_length=max_lengths[i];
			max_length_idx=i;
		}
	}
	//回溯出最长字串，起始值last_idx设定为max_length_idx简单直接，代码简洁
	int last_idx = max_length_idx;
	for(int i=max_length-1;i>=0;i--)
	{
		max_length_sub_str[i]=a[last_idx];
		last_idx = last_idxs[last_idx];
	}

	return max_length;
}