#include<string>
#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
//问题：针对一个序列和一个给定的定值，找出序列中的两个元素之和等于给定定值的所有组合。
//方案1：两层循环，时间复杂度O(n^2),空间复杂度O(1)
//方案2：先将序列元素放进hash_map，然后一次遍历，查找定值-当前元素的差是否在hash_map中，时间复杂度O(n)，空间复杂度O(n)
//方案3：先排序，然后找某个元素是否在序列中，使用二分查找，时间复杂度O(nlogn)，空间复杂度取决于使用的排序算法

bool bi_search(int* arr, int start, int end, int target)//递归版本
{
	if(end-start>=1)
	{
		int mid_idx = start+(end-start)/2;
		if(arr[mid_idx]>target)
			bi_search(arr, start, mid_idx-1, target);
		else if(arr[mid_idx]<target)
			bi_search(arr, mid_idx+1, end, target);
		else
			return 1;
	}
	else
	{
		if(arr[start]==target)
			return 1;
		else
			return 0;
	}
}
bool bi_search_not_rec(int* arr, int start_, int end_, int target)//非递归版本
{
	int start=start_,end=end_;
	while(end-start>=0)
	{
		int mid_idx = start+(end-start)/2;
		if(arr[mid_idx]>target)
		{
			end = mid_idx-1;
		}
		else if(arr[mid_idx]<target)
		{
			start=mid_idx+1;
		}
		else
			return 1;
	}
	return 0;
}
void solver(int* arr, int n, int the_sum, vector<int>& add1, vector<int>& add2)//
{
  for(int i=0;i<n;i++)
  {
    int target = the_sum-arr[i];
    if(bi_search_not_rec(arr, i+1, n, target))//只搜索后面的，避免例如5=2+3和3+2这种重复
    {
      add1.push_back(arr[i]);//保存
      add2.push_back(target);
    }
  }
}

int main()
{
	int arr[10]={0,2,3,4,6,6,7,8,8,9};
	vector<int> add1, add2;
	solver(arr, 10, 8, add1, add2);
	for(int i=0;i<add1.size();i++)
	{
		cout<<add1[i]<<' '<<add2[i]<<endl;
	}

	system("pause");
	return 0;
}