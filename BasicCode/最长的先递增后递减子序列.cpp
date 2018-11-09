#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//���⣺����һ�����У�����{3,5,1,6,4,7,2}��Ҫ��ɾ�����ٵ�Ԫ��ʹ�����г�Ϊһ�����������½�������
//˼·����ֳ��������⣬һ��������������У�һ������ݼ������У�ԭ����ת������һ���ֽ�㣬ʹ��
//��ߵ�������ұߵݼ��������ֻҪ����һ�飬����ÿ��Ԫ�ض��Ƿֽ�㣬�Ƚ�һ�飬�ҳ���ġ�
//ʱ�临�Ӷȣ�������͵ݼ���������ҪO(n^2)�����������������������֮����ҪO(n)��������ҪO(n^2)
//�ռ临�Ӷȣ���Ҫһ����¼��������У���O(n)
void max_inc_sub_seq(int* arr, int n, int* result)//result�洢��������������г���
{
  for(int i=0;i<n;i++)
  {
    result[i]=1;//1
  }
  for(int i=1;i<n;i++)
  {
     int current_max=1;
     for(int j=0;j<i;j++)
     {
        if(arr[i]>arr[j])
        { 
           if(result[j]+1>current_max)
              current_max=result[j]+1;
        }
     }
     result[i]=current_max;
  }
        
}

void max_dec_sub_seq(int* arr, int n, int* result)//result�洢���еݼ������г���
{
  for(int i=0;i<n;i++)
  {
    result[i]=1;//��ʼ��Ϊ1����������Ԫ�ر�����һ��������
  }
  for(int i=n-1;i>=0;i--)
  {
     int current_max=1;
     for(int j=i+1;j<n;j++)
     {
        if(arr[i]>arr[j])
        { 
           if(result[j]+1>current_max)
              current_max=result[j]+1;
        }
     }
     result[i]=current_max;
  }
        
}

int solver(int* arr, int n)
{
  int max_len=0;
  int max_len_idx=0;
  
  int* max_inc=new int[n];
  int* max_dec=new int[n];
  max_inc_sub_seq(arr, n, max_inc);
  max_dec_sub_seq(arr, n, max_dec);
  /*
  for(int i=0;i<n;i++)
  {
	  cout<<max_inc[i]<<' '<<max_dec[i]<<endl;
  }
  */
  for(int i=0;i<n;i++)//����һ�����У��ж��ȵ�����ݼ��ĳ���֮�ͣ�ȡ���ֵ
  {
     if(max_inc[i]+max_dec[i]>max_len)
	 {
       max_len = max_inc[i]+max_dec[i];
	   max_len_idx = i;
	 }
  }
  
  //delete
  delete max_inc;
  delete max_dec;
  
  cout<<"max length: "<<max_len<<endl;
  cout<<"max length index: "<<max_len_idx<<endl;
  return max_len-1;//�����͵ݼ�����һ��Ԫ�أ���-1
}
int main()
{

	int arr[7]={3,5,1,6,4,7,2};
	solver(arr, 7);

	system("pause");

	return 0;
}