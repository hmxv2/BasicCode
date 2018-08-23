//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int max_length_increasing_sub_str(int *a, int n, int *max_lengths, int *max_length_sub_str);

//��ִ���������������еĲ�ͬ���ִ���Ҫ������һ�������п���������Ԫ�ؼ��
//��������������Ҫ��һЩ

//����̬�滮��˼�룬����һ������max_lengths��ʾ�Ե�ǰi��β�Ĵ�����Ĵ��ĳ��ȣ�
//��ʼ״̬��1������ʽ�ǶԵ�ǰ��i��Ԫ�أ��ҳ��ϸ�Ԫ���Ƿ�͵�ǰ���ɵ�����������Գ���+1
//Ȼ�������ɸѡ�����ġ�
//����һ�鼴�ɣ��ʸ÷������Ӷ�O(n)
//˳�㿼���½�·����������last_idxs��������ݳ��������С�Ӵ���ʲô

int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int* max_lengths=new int[n];//���������Ե�ǰΪ��β�Ļ���Ӵ��ĳ���
	int* max_length_sub_str=new int[n];//������Ӵ��ľ��幹��

	int max_length = max_length_increasing_sub_str(a, n, max_lengths, max_length_sub_str);

	cout<<"max length: "<<max_length<<endl;

	for(int i=0;i<max_length;i++)
	{
		cout<<max_length_sub_str[i]<<' ';
	}
	

	system("pause");
	return 0;
}

int max_length_increasing_sub_str(int *a, int n, int *max_lengths, int *max_length_sub_str)
{
	int *last_idxs = new int[n];

	for (int i=0;i<n;i++)//��ʼ��
	{
		last_idxs[i]=-1;
		max_length_sub_str[i]=-1;
		max_lengths[i]=1;
	}
	for(int i=1;i<n;i++)//�Ƚϼ򵥣�ֻ��Ҫ��ǰһ���Ƚϣ��ǵ����Ļ�������һ���Ļ�����+1
	{
		if(a[i]>a[i-1])
		{
			max_lengths[i]=max_lengths[i-1]+1;
			last_idxs[i]=i-1;
		}
	}
	//��ʼѰ�����ֵ�����ǳ������
	int max_length=max_lengths[0];
	int max_length_idx=0;
	for (int i=0;i<n;i++)
	{
		if (max_lengths[i]>max_length)
		{
			max_length=max_lengths[i];
			max_length_idx=i;
		}
	}
	//���ݳ���ִ�����ʼֵlast_idx�趨Ϊmax_length_idx��ֱ�ӣ�������
	int last_idx = max_length_idx;
	for(int i=max_length-1;i>=0;i--)
	{
		max_length_sub_str[i]=a[last_idx];
		last_idx = last_idxs[last_idx];
	}

	return max_length;
}