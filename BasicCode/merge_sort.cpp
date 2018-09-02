#include<iostream>
#include<string>
using namespace std;
void sort(int *arr, int start_idx, int end_idx);
void merge(int *arr, int start_idx, int mid_idx, int end_idx);
//�鲢������Ҫʹ�õݹ飬������룬ֱ���ҵ�ֻ��һ��Ԫ�ص�������(�Ѿ�����)��Ȼ����㷵�أ����Ͻ���������������ϲ���
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
	if(end_idx>start_idx)//��û��ֻ��һ��Ԫ�ص�ʱ���򲻶�����
	{
		int mid_idx = start_idx+(end_idx-start_idx)/2;
		sort(arr, start_idx, mid_idx);//����������ֱ��������
		sort(arr, mid_idx+1, end_idx);
		merge(arr, start_idx, mid_idx, end_idx);//���������Ѿ����򣬿�ʼ�ϲ���Ȼ�� ������������ʼ��㷵��
	}	
}

void merge(int *arr, int start_idx, int mid_idx, int end_idx)
{
	//�ϲ���ʱ����Ҫ����������ָ�����ߵ�������;
	//���ϱȽ�����������Ӧ��Ԫ�صĴ�С��С�Ľ���һ����ʱ���飬ͬʱ��������ƶ�
	//һֱĳ���������β��Ȼ����һ�����������Ԫ��һ���ԷŽ���ʱ����
	//������ʱ���鸴�Ƶ�arr


	int * tmp_arr=new int[end_idx-start_idx+1];//��ʱ����
	int tmp_arr_idx=0;//��ʱ���������
	int i=start_idx, j=mid_idx+1;
	while(i<=mid_idx && j<=end_idx)//i��j��Ӧ�������鶼����ʱ��������Ԫ�طŽ���ʱ����
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
	while(i<=mid_idx)//�����j������Ӧ����������ˣ����i��Ӧ��������ʣ�������Ԫ�طŽ���ʱ����
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