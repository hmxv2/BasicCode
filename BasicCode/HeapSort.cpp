#include<string>
#include<iostream>
#include<ctime>
using namespace std;
//����������汾
//���ȣ�������һ����ȫ����������ʽ���������һ��֮�����඼���������ӽڵ㣬���һ��
//���ӽڵ�����������У��������ݽṹѡ�����鼴�ɡ�
//�����ѵĹ����ǣ�����ĳ���ڵ㣬�ж����Ƿ�Ⱥ��ӽڵ㶼�󣬲����򻥻���Ȼ���жϺ��ӽڵ��Ƿ�����ĺ��Ӷ����Դ�����
//���ѵĹ�������Ǵӵײ㿪ʼ��
//
//�����������򣬼�ÿ�ν��Ѷ��͵�ǰ�ѵ���ĩβ�������ѳ���-1��Ȼ���¶����µ���Ϊ�ѡ�ѭ���ò���ֱ����Ϊ1

void heap_adjust(int *arr, int n, int dad);//key func
void heap_sort(int *arr, int n);
int main()
{
	const int arr_len=10;
	int arr[arr_len]={10, 3, 5, 2, 6, 1, 8, 4, 9, 7};

	heap_sort(arr, arr_len);

	for(int i=0;i<arr_len;i++)
		cout<<arr[i]<<' ';
	
	system("pause");
}

void heap_adjust(int *arr, int n, int dad)
{
	//dad: dad node index
	int lchild = dad*2+1;//left child
	int rchild = dad*2+2;//right child
	int child_max = lchild;
	if(lchild<n)//exist
	{
		if(rchild<n)
		{
			child_max = arr[lchild]>arr[rchild]?lchild:rchild;//get the bigger
		}
		if(arr[dad]<arr[child_max])//swap or not
		{
			int tmp=arr[dad];
			arr[dad]=arr[child_max];
			arr[child_max]=tmp;

			//make sure that the child is also the biggest in (child, child's lchild, child's right)
			heap_adjust(arr, n, child_max);
		}
	}
}
void heap_sort(int *arr, int n)
{
	//build heap firstly
	for(int i=n/2;i>=0;i--)//begin from the last node with child(s)
	{
		heap_adjust(arr, n, i);
	}
	//then start to pop the heap head and re-adjust the heap many times
	for(int i=n-1;i>=0;i--)
	{
		//swap:
		int tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;

		//and re-adjust
		heap_adjust(arr, i, 0);
	}
}