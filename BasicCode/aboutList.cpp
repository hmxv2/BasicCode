#include<iostream>
#include<string>
using namespace std;
//编写一个关于list的基本操作，便于其他应用使用
//例如方便调试反转链表

struct node
{
	int n;
	node *next;
};
class List
{
	public:
		node *root;
		node *tail;

		//
		List()//无参
		{
			root=new node;//需要先new一个实体出来，然后初始化为-1
			root->n = -1;
			root->next =NULL;
		}
		List(node* p)//重载
		{
			root=p;
		}
		//
		bool insert(node* p, int n)//在指定位置插入
		{
			node* tmp=root;
			while(tmp!=NULL)
			{
				if(tmp==p)
				{
					node* new_node = new node;
					new_node->n = n;
					p->next=new_node;
					new_node=tmp->next;
					return 1;
				}
				tmp=tmp->next;
			}
			return 0;
		}
		bool insert(int n)//tail insert
		{
			node* tmp=root;
			while(tmp->next!=NULL)
			{
				tmp=tmp->next;
			}
			tail = new node;
			tail->n=n;
			tail->next=NULL;
			tmp->next=tail;

			return 1;
		}
		void print_eles()//打印所有元素
		{
			node* tmp=root;
			while(tmp!=NULL)
			{
				cout<<tmp->n<<' ';
				tmp=tmp->next;
			}
			cout<<endl;
		}

};



node* reverse(node* head);int abs_(int n);
int main()
{
	List list;
	list.insert(10);
	list.insert(9);
	list.insert(4);
	list.print_eles();

	node* list_rev = reverse(list.root);
	List list2(list_rev);
	list2.print_eles();

	cout<<abs_(-10)<<' '<<abs_(33);
	system("pause");
	return 0;
}

node* reverse(node* head)
{
	if(head==NULL || head->next==NULL)
		return head;

	node* pre=NULL;
	node* now=head;
	node* nxt=head->next;
	while(nxt!=NULL)
	{
		now->next=pre;//cout<<"haha "<<now->n<<endl;//debug
		pre=now;
		now=nxt;
		nxt = nxt->next;
	}
	now->next = pre;//视上面循环怎么写而定
	return now;
}

