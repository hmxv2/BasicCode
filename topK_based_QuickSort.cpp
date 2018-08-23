//
#include<iostream>
#include<string>
using namespace std;
int topK_based_quick_sort(int *arr, int start_idx, int end_idx, int topK);

//需要选出第K大的数字，所以快排应该是一个降序的。
//基本思想是在快排的基础上，每次选一个数为支点，通过快排的过程寻找该支点的正确位置，然后判断第k大在支点的左边还是右边，从而完成剪枝。

int topK_based_quick_sort(int *arr, int start_idx, int end_idx, int topK)
{
	int cur_idx=start_idx;
	int i=start_idx, j=end_idx;
	while(i!=j)
	{
		if(arr[cur_idx]>=arr[j])
			j--;
		else
		{
			//cout<<"j: "<<j<<','<<arr[j]<<endl;
			int tmp=arr[cur_idx];
			arr[cur_idx]=arr[j];
			arr[j]=tmp;

			cur_idx=j;

			while(i<cur_idx)
			{
				if(arr[i]>=arr[cur_idx])
				{
					i++;
				}
				else
				{
					//cout<<"i: "<<j<<','<<arr[j]<<endl;
					int tmp=arr[cur_idx];
					arr[cur_idx]=arr[i];
					arr[i]=tmp;

					cur_idx=i;

					break;
				}
			}
		}
	}
	//以上这部分代码和快排一致。
	if(cur_idx==topK)
	{
		return arr[cur_idx];
	}
	else if(cur_idx>topK)
	{
		if(start_idx!=cur_idx)//因为start<=cur，故如果不等，则cur_idx-1至少等于start_idx，即不会越界
			topK_based_quick_sort(arr, start_idx, cur_idx-1, topK);//注意此处不是什么cur_idx-topK，因为cur_idx和topK都是绝对位置
	}
	else
	{
		if(cur_idx!=end_idx)//道理同上一个if
			topK_based_quick_sort(arr, cur_idx+1, end_idx, topK);//注意此处不是什么topK-cur_idx，因为cur_idx和topK都是绝对位置
	}
}

//test
int main()
{
	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	
	int topKth_idx=0;//topKth_idx=6则表示第7大
	int topKth_num = topK_based_quick_sort(a, 0, n-1, topKth_idx);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl<<topKth_num;
	system("pause");
	return 0;
}
