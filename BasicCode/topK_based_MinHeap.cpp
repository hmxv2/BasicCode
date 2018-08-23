//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int topK_based_min_heap(int *a, int n, int topKth_idx);

//需要选出第K大的数字,如果数组是事先确定的，则快排是一个好思路，如果数据是流的形式，则最小堆是一个更合适的思路。
//另外一个是快排会改变原数组，如果不复制原数组只能换最小堆这个思路。
//基本思想是维护一个最小堆，每次接受数据流的一个数，如果数据大于堆顶，则把堆顶替换掉，然后调整维持最小堆性质。
//所以最后形成的最小堆即是最大的K个数据，堆顶即是这K个数据中的最小的，即第K大。

//从零实现一个最小堆比较麻烦，借用STL的multiset来实现一下，不用set是因为set元素不可重复。
//set这一类数据结构是有序的，和python的set不同。所以删除和插入一个数之后堆都会自动调节为最小堆
//每次操作最小堆需要的时间是log(K)，因此最终复杂度是nlog(K)，如果K较小的话和快排做法也是差不多的。
int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int topKth_idx=3;//topKth_idx=6则表示第7大
	int topKth_num = topK_based_min_heap(a, n, topKth_idx);
	
	cout<<endl<<topKth_num;
	system("pause");
	return 0;
}

int topK_based_min_heap(int *a, int n, int topKth_idx)
{
	multiset<int> min_heap;
	multiset<int>::iterator heap_iter;//heap的头，即heap中的最小值
	for(int i=0;i<n;i++)
	{
		if(i<=topKth_idx)
		{
			min_heap.insert(a[i]);
		}
		else
		{
			heap_iter = min_heap.begin();
			if(a[i]>*heap_iter)	//大于堆头，应当进入到这K个的行列
			{
				min_heap.erase(heap_iter);
				min_heap.insert(a[i]);
			}
		}
	}
	return *min_heap.begin();
}