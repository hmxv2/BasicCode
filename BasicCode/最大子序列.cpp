//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_sum_sub_seq(int *a, int n, int *max_sums, int *the_sub_seq, int& sub_seq_length);

//最大子序列不是(注意，不是)求子序列中和最大的子序列，如果是这样的话只需要把非负数拿出来相加即可。
//最大子序列要求的应该是连续子序列中和最大的子序列

//按动态规划的思想，设定一个数组max_sums，记录当前元素结尾的连续子序列的最大和。
//初始值是每个元素自身的数值，递推式是针对每个i寻找max_sums[i-1]，和当前元素加起来，是否比max_sums[i]大，其实也就是max_sums[i-1]是否小于0
//只需要对数组扫描一遍，故复杂度O(n)

int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,-5,2,1,-7,9,6,22,-10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_sums=new int[n];//保存数组以当前为结尾的话最长子串的长度
	int* the_sub_seq=new int[n];//记下最长子串的具体构成
	int sub_seq_length;

	int max_sum = max_sum_sub_seq(a, n, max_sums, the_sub_seq, sub_seq_length);

	cout<<"max sum: "<<max_sum<<endl;

	for(int i=0;i<sub_seq_length;i++)
	{
		cout<<the_sub_seq[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_sum_sub_seq(int *a, int n, int *max_sums, int *the_sub_seq, int& sub_seq_length)
{
	int *last_idxs=new int[n];
	for(int i=0;i<n;i++)
	{
		max_sums[i]=a[i];
		the_sub_seq[i]=-1;
		last_idxs[i]=-1;
	}
	for (int i=1;i<n;i++)
	{
		if(max_sums[i-1]>=0)//上一个数大于等于0才可以累加到max_sums[i]上，不然的话max_sums[i]自身更大。
		{
			max_sums[i]=max_sums[i]+max_sums[i-1];
			last_idxs[i]=i-1;
		}
	}
	//完毕，复杂度O(n)
	int max_sum=max_sums[0];//最大的找出来
	int max_sum_idx=0;
	for (int i=0;i<n;i++)
	{
		//cout<<max_sums[i]<<' ';//debug
		if(max_sums[i]>max_sum)
		{
			max_sum=max_sums[i];
			max_sum_idx=i;
		}
	}
	//回溯出路径
	int last_idx=max_sum_idx;
	int sub_seq_length_=0;
	for(int i=0;i<n;i++)
	{
		the_sub_seq[i]=a[last_idx];
		last_idx = last_idxs[last_idx];

		sub_seq_length_++;
		if(last_idx==-1)
			break;
	}
	for(int i=0;i<(sub_seq_length_-1)/2.0;i++)
	{
		//swap
		int tmp=the_sub_seq[i];
		the_sub_seq[i]=the_sub_seq[sub_seq_length_-1-i];
		the_sub_seq[sub_seq_length_-1-i]=tmp;
	}
	//回溯完毕
	sub_seq_length = sub_seq_length_;
	return max_sum;
}
	