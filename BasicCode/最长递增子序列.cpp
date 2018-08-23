//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_length_increasing_sub_seq(int *a, int n, int *max_lengths, int *max_length_sub_seq);

//����̬�滮��˼�룬����һ������max_lengths��ʾ�Ե�ǰi��β��������������еĳ��ȣ�
//��ʼ״̬��1������ʽ�ǶԵ�ǰ��i��Ԫ�أ��ҳ�i֮ǰ������max_lengthԪ���п��Ա���1��(�����ϵ�������)��
//Ȼ�������ɸѡ�����ġ��ʸ÷������Ӷ�n+n-1+n-2+...+1=O(nƽ��)
//˳�㿼���½�·����������last_idxs��������ݳ��������С��������ʲô
int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_lengths=new int[n];//���������Ե�ǰΪ��β�Ļ�������еĳ���
	int* max_length_sub_seq=new int[n];//����������еľ��幹��

	int max_length = max_length_increasing_sub_seq(a, n, max_lengths, max_length_sub_seq);

	cout<<"max length: "<<max_length<<endl;

	for(int i=0;i<max_length;i++)
	{
		cout<<max_length_sub_seq[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_length_increasing_sub_seq(int *a, int n, int *max_lengths, int *max_length_sub_seq)
{
	//max_lengths��ʾ�Ե�ǰi��β��������������еĳ���
	//����С���������б�����max_length_sub_seq�����У���󳤶�Ϊn����СΪ1������������ĳ���Ϊn�Ǻ��ʵġ�

	int *last_idxs = new int[n];//����һ����ÿ��������е��ϸ�Ԫ��idx��������������ݳ������������

	for(int i=0; i<n;i++)
	{
		last_idxs[i]=-1;//��ʼ����ʵ���Ǳ�Ҫ��
		max_length_sub_seq[i]=-1;//��ʼ����ʵ���Ǳ�Ҫ��
		max_lengths[i]=1;//��ʼ��Ϊ1���Ǻ���ģ�ÿ��Ԫ�������Լ�����һ������Ϊ1�ĵ���������
	}

	for(int i=0;i<n;i++)//���ڵ�ǰi�����֣�����֮ǰ������Ԫ�ؿ��Ƿ񹹳ɵ������������е��������
	{
		int cur_max_length=max_lengths[0];
		for(int j=0;j<i;j++)//֮ǰ��Ԫ����j��������j����С��i
		{
			if(a[j]<a[i])
			{
				if(max_lengths[j]+1>cur_max_length)//ʱ�̼���Ƿ������������������ǰ��β��������е���һ��index��ʲô��������
				{
					cur_max_length=max_lengths[j]+1;
					last_idxs[i]=j;
				}
			}
		}
		max_lengths[i]=cur_max_length;//�õ���ǰ��β�����е���������еĳ���
	}

	int max_length=max_lengths[0];
	int max_length_idx=0;
	for(int i=0;i<n;i++)//max_lengths�����������ҳ�����������
	{
		if(max_lengths[i]>max_length)
		{
			max_length=max_lengths[i];
			max_length_idx=i;
		}
	}
	//cout<<max_length_idx<<endl;
	//for(int i=0;i<n;i++)cout<<max_lengths[i]<<' ';//debug
	//cout<<endl;
	//for(int i=0;i<n;i++)cout<<last_idxs[i]<<' ';//debug
	
	int max_length_last_idx=max_length_idx;
	for(int i=max_length-1;i>=0;i--)//���ݳ�������Ǹ���ĵ���������
	{
		max_length_sub_seq[i]=a[max_length_last_idx];
		//cout<<i<<"i  "<<max_length_last_idx<<'a'<<endl;
		max_length_last_idx = last_idxs[max_length_last_idx];
		
	}
	
	delete last_idxs;//��Ҫ�ֶ��ͷŵ�

	return max_length;
}