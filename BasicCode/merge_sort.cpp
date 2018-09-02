#include<iostream>
#include<string>
using namespace std;
void sort(int *arr, int start_idx, int end_idx);
void merge(int *arr, int start_idx, int mid_idx, int end_idx);
//归并排序需要使用递归，逐层深入，直到找到只有一个元素的子数组(已经有序)，然后逐层返回，不断将相邻两个子数组合并。
//
//
//
int main()
{
	int arr[]={2,3,4,1,6,0,9,7,8,5,12,11};
	int num = sizeof(arr)/sizeof(int);

	sort(arr, 0, num-1);
	for(int i=0;i<12;i++)
		cout<<arr[i]<<' ';


	system("pause");
	return 0;
}

void sort(int *arr, int start_idx, int end_idx)
{
	if(end_idx>start_idx)//还没到只有一个元素的时候，则不断深入
	{
		int mid_idx = start_idx+(end_idx-start_idx)/2;
		sort(arr, start_idx, mid_idx);//对左右数组分别继续深入
		sort(arr, mid_idx+1, end_idx);
		merge(arr, start_idx, mid_idx, end_idx);//左右数组已经有序，开始合并，然后 函数结束，开始逐层返回
	}	
}

void merge(int *arr, int start_idx, int mid_idx, int end_idx)
{
	//合并的时候，需要定两个索引指向两边的子数组;
	//不断比较两个索引对应的元素的大小，小的进入一个临时数组，同时索引向后移动
	//一直某个子数组结尾，然后将另一个数组的所有元素一次性放进临时数组
	//最后把临时数组复制到arr


	int * tmp_arr=new int[end_idx-start_idx+1];//临时数组
	int tmp_arr_idx=0;//临时数组的索引
	int i=start_idx, j=mid_idx+1;
	while(i<=mid_idx && j<=end_idx)//i和j对应的子数组都不空时，持续将元素放进临时数组
	{
		if(arr[i]<arr[j])
		{
			tmp_arr[tmp_arr_idx]=arr[i];
			i++;
			tmp_arr_idx++;
		}
		else
		{
			tmp_arr[tmp_arr_idx]=arr[j];
			j++;
			tmp_arr_idx++;
		}
	}
	while(i<=mid_idx)//如果是j索引对应的子数组空了，则把i对应的子数组剩余的所有元素放进临时数组
	{
		tmp_arr[tmp_arr_idx]=arr[i];
		i++;
		tmp_arr_idx++;
	}
	while(j<=end_idx)
	{
		tmp_arr[tmp_arr_idx]=arr[j];
		j++;
		tmp_arr_idx++;
	}
	for(int i=start_idx; i<=end_idx; i++)//copy
	{
		arr[i]=tmp_arr[i-start_idx];
	}
	delete tmp_arr;
}