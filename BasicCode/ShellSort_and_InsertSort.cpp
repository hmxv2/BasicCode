#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//ϣ����������汾
//���ȸ�ϰ�²���������arr[0:i]Ϊ�������飬��arr[i+1]���뵽������
//�����У�ֱ��i==n-1����������ÿ����Ҫ�ƶ�Ԫ�أ���Ϊ������������һ��
//ϣ������
//���һ��gap������arrʹ��arr[i], arr[i+gap], arr[i+2*gap], ... arr[i+k*gap]��������i����[0, gap-1]
//һ����˵��gap��ʼ��Ϊn/2, ֮�������۰룬ֱ��0  (arr�ĳ���n)
//����shell_sort�����൫���׶��Խϲ
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
	for(int gap=n/2;gap>0;gap/=2)//gap�۰�
	{
		for(int i=gap;i<n;i++)//i��j������ѭ����insert_sort����һ����ֻ�Ǽ���gap����
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
		for(int j=i;j>0&&arr[j]<arr[j-1];j--)//�����汾�����ƶ���������
		{
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
}