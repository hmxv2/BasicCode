//
#include<iostream>
#include<string>
using namespace std;
void quick_sort_core(int *arr, int start_idx, int end_idx);

//������Ϊ����
//����˼���ǽ�����һ�����ƶ�����ȷ��λ���ϣ���ǰ�������С�ڸ�������������������ڸ�����
//ÿ�ε��ƶ���������һ��O(n)���̣���Ҫʵ��O(lgn)�Ρ�
/*
�����ʵ�ֹ��̣�
���ǵ��ھ���ĵ�i���ƶ�ʱ������ǰ�������С�ڸ��������ߺ�����������ڸ������������֮һ��

ÿ���ƶ��Ŀ�ʼ���õ�һ����Ϊ֧�㣬����ĩβj��ʼ��飬���arr[j]�Ƿ�С��֧�㣬���򻥻���
����j--��Ȼ��ӿ�ͷi��ʼ��飬arr[i]�Ƿ����֧�㣬ʵ�򻥻�������i++��һֱ������i==j
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

	if(start_idx!=cur_idx)//��Ϊstart<=cur����������ȣ���cur_idx-1���ٵ���start_idx��������Խ��
		quick_sort_core(arr, start_idx, cur_idx-1);

	if(cur_idx!=end_idx)//����ͬ��һ��if
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
