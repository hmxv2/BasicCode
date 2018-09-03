#include<iostream>
#include<string>
using namespace std;
//��дһ������list�Ļ�����������������Ӧ��ʹ��
//���緽����Է�ת����

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
		List()//�޲�
		{
			root=new node;//��Ҫ��newһ��ʵ�������Ȼ���ʼ��Ϊ-1
			root->n = -1;
			root->next =NULL;
		}
		List(node* p)//����
		{
			root=p;
		}
		//
		bool insert(node* p, int n)//��ָ��λ�ò���
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
		void print_eles()//��ӡ����Ԫ��
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
	now->next = pre;//������ѭ����ôд����
	return now;
}

