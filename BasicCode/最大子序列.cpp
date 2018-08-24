//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_sum_sub_seq(int *a, int n, int *max_sums, int *the_sub_seq, int& sub_seq_length);

//��������в���(ע�⣬����)���������к����������У�����������Ļ�ֻ��Ҫ�ѷǸ����ó�����Ӽ��ɡ�
//���������Ҫ���Ӧ���������������к�����������

//����̬�滮��˼�룬�趨һ������max_sums����¼��ǰԪ�ؽ�β�����������е����͡�
//��ʼֵ��ÿ��Ԫ���������ֵ������ʽ�����ÿ��iѰ��max_sums[i-1]���͵�ǰԪ�ؼ��������Ƿ��max_sums[i]����ʵҲ����max_sums[i-1]�Ƿ�С��0
//ֻ��Ҫ������ɨ��һ�飬�ʸ��Ӷ�O(n)

int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,-5,2,1,-7,9,6,22,-10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_sums=new int[n];//���������Ե�ǰΪ��β�Ļ���Ӵ��ĳ���
	int* the_sub_seq=new int[n];//������Ӵ��ľ��幹��
	int sub_seq_length;

	int max_sum = max_sum_sub_seq(a, n, max_sums, the_sub_seq, sub_seq_length);

	cout<<"max sum: "<<max_sum<<endl;

	for(int i=0;i<sub_seq_length;i++)
	{
		cout<<the_sub_seq[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_sum_sub_seq(int *a, int n, int *max_sums, int *the_sub_seq, int& sub_seq_length)
{
	int *last_idxs=new int[n];
	for(int i=0;i<n;i++)
	{
		max_sums[i]=a[i];
		the_sub_seq[i]=-1;
		last_idxs[i]=-1;
	}
	for (int i=1;i<n;i++)
	{
		if(max_sums[i-1]>=0)//��һ�������ڵ���0�ſ����ۼӵ�max_sums[i]�ϣ���Ȼ�Ļ�max_sums[i]�������
		{
			max_sums[i]=max_sums[i]+max_sums[i-1];
			last_idxs[i]=i-1;
		}
	}
	//��ϣ����Ӷ�O(n)
	int max_sum=max_sums[0];//�����ҳ���
	int max_sum_idx=0;
	for (int i=0;i<n;i++)
	{
		//cout<<max_sums[i]<<' ';//debug
		if(max_sums[i]>max_sum)
		{
			max_sum=max_sums[i];
			max_sum_idx=i;
		}
	}
	//���ݳ�·��
	int last_idx=max_sum_idx;
	int sub_seq_length_=0;
	for(int i=0;i<n;i++)
	{
		the_sub_seq[i]=a[last_idx];
		last_idx = last_idxs[last_idx];

		sub_seq_length_++;
		if(last_idx==-1)
			break;
	}
	for(int i=0;i<(sub_seq_length_-1)/2.0;i++)
	{
		//swap
		int tmp=the_sub_seq[i];
		the_sub_seq[i]=the_sub_seq[sub_seq_length_-1-i];
		the_sub_seq[sub_seq_length_-1-i]=tmp;
	}
	//�������
	sub_seq_length = sub_seq_length_;
	return max_sum;
}
	