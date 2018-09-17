#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//希尔排序：升序版本
//首先复习下插入排序：以arr[0:i]为有序数组，将arr[i+1]插入到该有序
//数组中，直到i==n-1。插入排序每次需要移动元素，改为交换，代码简洁一点
//希尔排序：
//针对一个gap，调整arr使得arr[i], arr[i+gap], arr[i+2*gap], ... arr[i+k*gap]有序，其中i属于[0, gap-1]
//一般来说，gap初始化为n/2, 之后依次折半，直到0  (arr的长度n)
//以下shell_sort代码简洁但是易读性较差。
//


void shell_sort(int *arr, int n);
void insert_sort(int *arr, int n);
int main()
{
	const int n=10;
	int arr[n]={10, 2, 4, 1, 9, 5, 8, 6, 3, 7};
	shell_sort(arr, n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';

	//insert sort
	int arr2[n]={10, 2, 4, 1, 9, 5, 8, 6, 3, 7};
	insert_sort(arr2, n);
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr2[i]<<' ';


	system("pause");
}
void shell_sort(int *arr, int n)
{
	for(int gap=n/2;gap>0;gap/=2)//gap折半
	{
		for(int i=gap;i<n;i++)//i和j这两层循环和insert_sort道理一样，只是加了gap参数
		{
			for(int j=i-gap;j>=0&&arr[j]>arr[j+gap];j-=gap)
			{
				int tmp = arr[j+gap];
				arr[j+gap] = arr[j];
				arr[j] = tmp;
			}
		}
		//for(int i=0;i<n;i++)//for debugging
		//	cout<<arr[i]<<' ';
		//cout<<endl<<gap<<endl;
	}
}

void insert_sort(int *arr, int n)
{
	for(int i=0;i<n;i++)
		for(int j=i;j>0&&arr[j]<arr[j-1];j--)//交换版本，不移动，代码简洁
		{
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
}