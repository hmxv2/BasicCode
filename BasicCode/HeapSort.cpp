#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//堆排序：升序版本
//首先，最大堆是一个完全二叉树的形式（除了最后一层之外其余都有两个孩子节点，最后一层
//孩子节点从左到右满排列），故数据结构选用数组即可。
//建立堆的过程是，查找某个节点，判断其是否比孩子节点都大，不是则互换，然后判断孩子节点是否比他的孩子都大，以此类推
//建堆的过程最好是从底层开始。
//
//接下来是排序，即每次将堆顶和当前堆的最末尾互换，堆长度-1，然后将新堆重新调整为堆。循环该步骤直到堆为1

void heap_adjust(int *arr, int n, int dad);//key func
void heap_sort(int *arr, int n);
int main()
{
	const int arr_len=10;
	int arr[arr_len]={10, 3, 5, 2, 6, 1, 8, 4, 9, 7};

	heap_sort(arr, arr_len);

	for(int i=0;i<arr_len;i++)
		cout<<arr[i]<<' ';
	
	system("pause");
}

void heap_adjust(int *arr, int n, int dad)
{
	//dad: dad node index
	int lchild = dad*2+1;//left child
	int rchild = dad*2+2;//right child
	int child_max = lchild;
	if(lchild<n)//exist
	{
		if(rchild<n)
		{
			child_max = arr[lchild]>arr[rchild]?lchild:rchild;//get the bigger
		}
		if(arr[dad]<arr[child_max])//swap or not
		{
			int tmp=arr[dad];
			arr[dad]=arr[child_max];
			arr[child_max]=tmp;

			//make sure that the child is also the biggest in (child, child's lchild, child's right)
			heap_adjust(arr, n, child_max);
		}
	}
}
void heap_sort(int *arr, int n)
{
	//build heap firstly
	for(int i=n/2;i>=0;i--)//begin from the last node with child(s)
	{
		heap_adjust(arr, n, i);
	}
	//then start to pop the heap head and re-adjust the heap many times
	for(int i=n-1;i>=0;i--)
	{
		//swap:
		int tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;

		//and re-adjust
		heap_adjust(arr, i, 0);
	}
}