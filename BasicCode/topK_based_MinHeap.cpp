//
#include<iostream>
#include<string>
#include<set>
using namespace std;

int topK_based_min_heap(int *a, int n, int topKth_idx);

//��Ҫѡ����K�������,�������������ȷ���ģ��������һ����˼·�����������������ʽ������С����һ�������ʵ�˼·��
//����һ���ǿ��Ż�ı�ԭ���飬���������ԭ����ֻ�ܻ���С�����˼·��
//����˼����ά��һ����С�ѣ�ÿ�ν�����������һ������������ݴ��ڶѶ�����ѶѶ��滻����Ȼ�����ά����С�����ʡ�
//��������γɵ���С�Ѽ�������K�����ݣ��Ѷ�������K�������е���С�ģ�����K��

//����ʵ��һ����С�ѱȽ��鷳������STL��multiset��ʵ��һ�£�����set����ΪsetԪ�ز����ظ���
//set��һ�����ݽṹ������ģ���python��set��ͬ������ɾ���Ͳ���һ����֮��Ѷ����Զ�����Ϊ��С��
//ÿ�β�����С����Ҫ��ʱ����log(K)��������ո��Ӷ���nlog(K)�����K��С�Ļ��Ϳ�������Ҳ�ǲ��ġ�
int main()
{

	//function call
	const int n=10;
	int a[n]={3,0,5,2,1,7,9,6,22,10};
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	cout<<endl;

	int topKth_idx=3;//topKth_idx=6���ʾ��7��
	int topKth_num = topK_based_min_heap(a, n, topKth_idx);
	
	cout<<endl<<topKth_num;
	system("pause");
	return 0;
}

int topK_based_min_heap(int *a, int n, int topKth_idx)
{
	multiset<int> min_heap;
	multiset<int>::iterator heap_iter;//heap��ͷ����heap�е���Сֵ
	for(int i=0;i<n;i++)
	{
		if(i<=topKth_idx)
		{
			min_heap.insert(a[i]);
		}
		else
		{
			heap_iter = min_heap.begin();
			if(a[i]>*heap_iter)	//���ڶ�ͷ��Ӧ�����뵽��K��������
			{
				min_heap.erase(heap_iter);
				min_heap.insert(a[i]);
			}
		}
	}
	return *min_heap.begin();
}