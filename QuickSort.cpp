//
#include<iostream>
#include<string>
using namespace std;
void quick_sort_core(int *arr, int start_idx, int end_idx);

//以升序为例：
//核心思想是将任意一个数移动到正确的位置上，即前面的数都小于该数，而后面的数都大于该数。
//每次的移动都必须是一个O(n)过程，需要实现O(lgn)次。
/*
具体的实现过程：
考虑到在具体的第i次移动时，总有前面的数都小于该数，或者后面的数都大于该数这两种情况之一。

每次移动的开始，拿第一个数为支点，从最末尾j开始检查，检查arr[j]是否小于支点，是则互换，
否则j--，然后从开头i开始检查，arr[i]是否大于支点，实则互换，否则i++，一直持续到i==j
*/
void quick_sort_core(int *arr, int start_idx, int end_idx)
{
	int cur_idx=start_idx;
	int i=start_idx, j=end_idx;
	while(i!=j)
	{
		if(arr[cur_idx]<=arr[j])
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
				if(arr[i]<=arr[cur_idx])
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

	if(start_idx!=cur_idx)//因为start<=cur，故如果不等，则cur_idx-1至少等于start_idx，即不会越界
		quick_sort_core(arr, start_idx, cur_idx-1);

	if(cur_idx!=end_idx)//道理同上一个if
		quick_sort_core(arr, cur_idx+1, end_idx);
}

//test
int main()
{
	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	

	quick_sort_core(a, 0, n-1);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';

	system("pause");
	return 0;
}
