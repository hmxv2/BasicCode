#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//问题：现有一个序列，例如{3,5,1,6,4,7,2}，要求删除最少的元素使得序列成为一个先上升后下降的序列
//思路：拆分成两个问题，一个是最长递增子序列，一个是最长递减子序列，原问题转化成求一个分界点，使得
//左边递增最长，右边递减最长，所以只要遍历一遍，假设每个元素都是分界点，比较一遍，找出最长的。
//时间复杂度：最长递增和递减子序列需要O(n^2)，遍历发生在子序列求出来之后，需要O(n)，总体需要O(n^2)
//空间复杂度：需要一个记录结果的数列，故O(n)
void max_inc_sub_seq(int* arr, int n, int* result)//result存储所有最长递增子序列长度
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

void max_dec_sub_seq(int* arr, int n, int* result)//result存储所有递减子序列长度
{
  for(int i=0;i<n;i++)
  {
    result[i]=1;//初始化为1，即最起码元素本身构成一个子序列
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
  for(int i=0;i<n;i++)//遍历一遍序列，判断先递增后递减的长度之和，取最大值
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
  return max_len-1;//递增和递减公用一个元素，故-1
}
int main()
{

	int arr[7]={3,5,1,6,4,7,2};
	solver(arr, 7);

	system("pause");

	return 0;
}