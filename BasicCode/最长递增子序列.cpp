//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_length_increasing_sub_seq(int *a, int n, int *max_lengths, int *max_length_sub_seq);

//按动态规划的思想，设立一个数组max_lengths表示以当前i结尾的序列中最长子序列的长度；
//初始状态是1，递推式是对当前第i个元素，找出i之前的所有max_length元素中可以被加1的(即符合递增条件)，
//然后从中再筛选出最大的。故该方法复杂度n+n-1+n-2+...+1=O(n平方)
//顺便考虑下将路径记下来，last_idxs，方便回溯出具体的最小子序列是什么
int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_lengths=new int[n];//保存数组以当前为结尾的话最长子序列的长度
	int* max_length_sub_seq=new int[n];//记下最长子序列的具体构成

	int max_length = max_length_increasing_sub_seq(a, n, max_lengths, max_length_sub_seq);

	cout<<"max length: "<<max_length<<endl;

	for(int i=0;i<max_length;i++)
	{
		cout<<max_length_sub_seq[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_length_increasing_sub_seq(int *a, int n, int *max_lengths, int *max_length_sub_seq)
{
	//max_lengths表示以当前i结尾的序列中最长子序列的长度
	//将最小递增子序列保存在max_length_sub_seq数组中，最大长度为n，最小为1，故数组申请的长度为n是合适的。

	int *last_idxs = new int[n];//开创一个将每个最长子序列的上个元素idx存起来，方便回溯出具体的子序列

	for(int i=0; i<n;i++)
	{
		last_idxs[i]=-1;//初始化其实不是必要的
		max_length_sub_seq[i]=-1;//初始化其实不是必要的
		max_lengths[i]=1;//初始化为1才是合理的，每个元素至少自己构成一个长度为1的递增子序列
	}

	for(int i=0;i<n;i++)//对于当前i的数字，检查和之前的所有元素看是否构成递增，则考虑所有递增中最长的
	{
		int cur_max_length=max_lengths[0];
		for(int j=0;j<i;j++)//之前的元素用j来索引，j明显小于i
		{
			if(a[j]<a[i])
			{
				if(max_lengths[j]+1>cur_max_length)//时刻检查是否最长，存起来。包括当前结尾的最长子序列的上一个index是什么都记下来
				{
					cur_max_length=max_lengths[j]+1;
					last_idxs[i]=j;
				}
			}
		}
		max_lengths[i]=cur_max_length;//拿到当前结尾的序列的中最长子序列的长度
	}

	int max_length=max_lengths[0];
	int max_length_idx=0;
	for(int i=0;i<n;i++)//max_lengths数组中最大的找出来即是所求
	{
		if(max_lengths[i]>max_length)
		{
			max_length=max_lengths[i];
			max_length_idx=i;
		}
	}
	//cout<<max_length_idx<<endl;
	//for(int i=0;i<n;i++)cout<<max_lengths[i]<<' ';//debug
	//cout<<endl;
	//for(int i=0;i<n;i++)cout<<last_idxs[i]<<' ';//debug
	
	int max_length_last_idx=max_length_idx;
	for(int i=max_length-1;i>=0;i--)//回溯出具体的那个最长的递增子序列
	{
		max_length_sub_seq[i]=a[max_length_last_idx];
		//cout<<i<<"i  "<<max_length_last_idx<<'a'<<endl;
		max_length_last_idx = last_idxs[max_length_last_idx];
		
	}
	
	delete last_idxs;//需要手动释放掉

	return max_length;
}