//
#include<iostream>
#include<string>
using namespace std;

int get_max_substring_size(const string& s1, const string& s2);
int get_max_subseq_size(const string& s1, const string& s2);


//������Ӵ��� LCS(i,j)���壺�����Ӵ�����s1��i��β��s2��j��β��
//��ô�����Ǻ���Ҫ����������s1��i��β��s2��j��β�Ĵ�ӵ�еĹ����Ӵ�����󳤶ȣ����ӡ�
//״̬ת�Ʒ��̣�LCS(i,j)=LCS(i-1,j-1)+1, if s1(i)==s2(j), ����LCS(i,j)=0
//״̬ת�Ʒ��̱Ƚ������룬�˴����������ǳ�ʼֵ����ơ�
//����˼ά�Ļ�����Ҫ��LCS(i,0)������һ��s1��Ѱ��s1[i]��s2[0]��ȵĵط��������ֵΪ1��������0��LCS(0,j)ͬ��
//�������ת���Ƕȣ�LCS(i,j)��ƴ�һ��ά�ȣ�����Խ�LCS(i,-1)��LCS(-1,j)ȷ��Ϊ0��Ȼ��ֱ�ӿ�ʼ״̬���̣��ɴ����ˡ�

//����������У��˴�����һ��Ƚ�һ��
//LCS(i,j)���壺��������������s1��i��β��s2��j��β��������Ȼ��Ҫ��
//��֮ͬ�����������е�״̬ת�Ʒ���
//״̬ת�Ʒ��̣�LCS(i,j)=LCS(i-1,j-1)+1, if s1(i)==s2(j), ����LCS(i,j)=max(LCS(i-1,j), LCS(i,j-1)), �ɼ������С������ԡ�
//��ʼֵ�����ͬ�ϡ�

int main()
{
	string s1="abcefgkjk";
	string s2="abcfgkefgk";
	
	cout<<get_max_substring_size(s1,s2)<<endl;
	
	cout<<get_max_subseq_size(s1, s2)<<endl;
	//
	system("pause");
	return 0;
}
/*
��һ��debug���̵��������������׿���������������һ����s1��s2����������ά���ϵ�һһ�ȶԣ�
��ϵ��ƹ��ɺ������������ľ���

    a b c f g k e f g k
  0 0 0 0 0 0 0 0 0 0 0
a 0 1 0 0 0 0 0 0 0 0 0
b 0 0 2 0 0 0 0 0 0 0 0
c 0 0 0 3 0 0 0 0 0 0 0
e 0 0 0 0 0 0 0 1 0 0 0
f 0 0 0 0 1 0 0 0 2 0 0
g 0 0 0 0 0 2 0 0 0 3 0
k 0 0 0 0 0 0 3 0 0 0 4
j 0 0 0 0 0 0 0 0 0 0 0
k 0 0 0 0 0 0 1 0 0 0 1
4
    a b c f g k e f g k
  0 0 0 0 0 0 0 0 0 0 0
a 0 1 1 1 1 1 1 1 1 1 1
b 0 1 2 2 2 2 2 2 2 2 2
c 0 1 2 3 3 3 3 3 3 3 3
e 0 1 2 3 3 3 3 4 4 4 4
f 0 1 2 3 4 4 4 4 5 5 5
g 0 1 2 3 4 5 5 5 5 6 6
k 0 1 2 3 4 5 6 6 6 6 7
j 0 1 2 3 4 5 6 6 6 6 7
k 0 1 2 3 4 5 6 6 6 6 7

*/


int get_max_substring_size(const string& s1, const string& s2)
{
	int s1_length=s1.length();
	int s2_length=s2.length();
	//LCS�����С��(s_length+1)*(s_length+1)����������ַ�����1
	int **lcs=new int*[s1_length+1];
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i]=new int[s2_length+1];
	}
	//����dp��ʼ����������ʼ��lcs��һ�к͵�һ��
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i][0]=0;
	}
	for(int i=0;i<s2_length+1;i++)
		lcs[0][i]=0;


	//���lcs���������к���
	for(int i=1;i<s1_length+1;i++)
	{
		for(int j=1;j<s2_length+1;j++)
		{
			if((s1[i-1]==s2[j-1]))//lcs[1][1]��Ӧ����ȡ�ַ�����һ�������
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				
			}
			else
			{
				lcs[i][j]=0;
			}
		}
	}
	//max
	int max_match_substring=0;
	for(int i=0;i<s1_length+1;i++)
	{
		for(int j=0;j<s2_length+1;j++)
		{
			if(lcs[i][j]>max_match_substring)
				max_match_substring=lcs[i][j];
		}
	}
	//debug
	
	for(int i=0;i<s1_length+1;i++)
	{
		if(i==0)
		{
			cout<<"    ";
			for(int j=0;j<s2_length;j++)
			{
				cout<<s2[j]<<" ";
			}
			cout<<endl<<"  ";
		}
		if(i>=1)
		{
			cout<<s1[i-1]<<" ";
		}
		for(int j=0;j<s2_length+1;j++)
		{
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}
	//�ֶ��ͷţ���s1_length+1��ָ��
	for(int i=0;i<s1_length+1;i++)
	{
		delete lcs[i];
	}

	return max_match_substring;
}

//����������
int get_max_subseq_size(const string& s1, const string& s2)
{
	int s1_length=s1.length();
	int s2_length=s2.length();
	//LCS�����С��(s_length+1)*(s_length+1)����������ַ�����1
	int **lcs=new int*[s1_length+1];
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i]=new int[s2_length+1];
	}
	//����dp��ʼ����������ʼ��lcs��һ�к͵�һ��
	for(int i=0;i<s1_length+1;i++)
	{
		lcs[i][0]=0;
	}
	for(int i=0;i<s2_length+1;i++)
		lcs[0][i]=0;


	//���lcs���������к���
	for(int i=1;i<s1_length+1;i++)
	{
		for(int j=1;j<s2_length+1;j++)
		{
			if((s1[i-1]==s2[j-1]))//lcs[1][1]��Ӧ����ȡ�ַ�����һ�������
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				
			}
			else
			{
				lcs[i][j]=lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1];//ȡ�����е����
			}
		}
	}
	//max����ʵ���԰�max��Ѱ�ҷ�������һ��ִ�е�
	int max_match_subseq=0;//��ʼֵ������0
	for(int i=0;i<s1_length+1;i++)
	{
		for(int j=0;j<s2_length+1;j++)
		{
			if(lcs[i][j]>max_match_subseq)
				max_match_subseq=lcs[i][j];
		}
	}
	//debug
	
	for(int i=0;i<s1_length+1;i++)
	{
		if(i==0)
		{
			cout<<"    ";
			for(int j=0;j<s2_length;j++)
			{
				cout<<s2[j]<<" ";
			}
			cout<<endl<<"  ";
		}
		if(i>=1)
		{
			cout<<s1[i-1]<<" ";
		}
		for(int j=0;j<s2_length+1;j++)
		{
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}
	

	return max_match_subseq;

}