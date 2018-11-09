#include<string>
#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
//���⣺���һ�����к�һ�������Ķ�ֵ���ҳ������е�����Ԫ��֮�͵��ڸ�����ֵ��������ϡ�
//����1������ѭ����ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(1)
//����2���Ƚ�����Ԫ�طŽ�hash_map��Ȼ��һ�α��������Ҷ�ֵ-��ǰԪ�صĲ��Ƿ���hash_map�У�ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
//����3��������Ȼ����ĳ��Ԫ���Ƿ��������У�ʹ�ö��ֲ��ң�ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�ȡ����ʹ�õ������㷨

bool bi_search(int* arr, int start, int end, int target)//�ݹ�汾
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
bool bi_search_not_rec(int* arr, int start_, int end_, int target)//�ǵݹ�汾
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
    if(bi_search_not_rec(arr, i+1, n, target))//ֻ��������ģ���������5=2+3��3+2�����ظ�
    {
      add1.push_back(arr[i]);//����
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