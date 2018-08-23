//
#include<iostream>
#include<string>
using namespace std;
int topK_based_quick_sort(int *arr, int start_idx, int end_idx, int topK);

//��Ҫѡ����K������֣����Կ���Ӧ����һ������ġ�
//����˼�����ڿ��ŵĻ����ϣ�ÿ��ѡһ����Ϊ֧�㣬ͨ�����ŵĹ���Ѱ�Ҹ�֧�����ȷλ�ã�Ȼ���жϵ�k����֧�����߻����ұߣ��Ӷ���ɼ�֦��

int topK_based_quick_sort(int *arr, int start_idx, int end_idx, int topK)
{
	int cur_idx=start_idx;
	int i=start_idx, j=end_idx;
	while(i!=j)
	{
		if(arr[cur_idx]>=arr[j])
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
				if(arr[i]>=arr[cur_idx])
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
	//�����ⲿ�ִ���Ϳ���һ�¡�
	if(cur_idx==topK)
	{
		return arr[cur_idx];
	}
	else if(cur_idx>topK)
	{
		if(start_idx!=cur_idx)//��Ϊstart<=cur����������ȣ���cur_idx-1���ٵ���start_idx��������Խ��
			topK_based_quick_sort(arr, start_idx, cur_idx-1, topK);//ע��˴�����ʲôcur_idx-topK����Ϊcur_idx��topK���Ǿ���λ��
	}
	else
	{
		if(cur_idx!=end_idx)//����ͬ��һ��if
			topK_based_quick_sort(arr, cur_idx+1, end_idx, topK);//ע��˴�����ʲôtopK-cur_idx����Ϊcur_idx��topK���Ǿ���λ��
	}
}

//test
int main()
{
	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	
	int topKth_idx=0;//topKth_idx=6���ʾ��7��
	int topKth_num = topK_based_quick_sort(a, 0, n-1, topKth_idx);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl<<topKth_num;
	system("pause");
	return 0;
}
