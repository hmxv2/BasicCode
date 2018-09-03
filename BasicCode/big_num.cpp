#include<iostream>
#include<string>
#include<Vector>
#include<cmath>
using namespace std;
class big_num
{
public:
	bool positive_num;
	int* num;
	int place;
	//default
	big_num(){}
	~big_num(){}
	//copy
	big_num(big_num& bn)
	{
		positive_num=bn.positive_num;
		place=bn.place;
		num=new int[place];
		for(int i=0;i<place;i++)
		{
			num[i]=bn.num[i];
		}

	}
	//constuct from string
	big_num(string s)
	{
		if(s[0]=='-')
		{
			positive_num=0;
			place=s.length()-1;
			num=new int[place];
			for(unsigned int i=1;i<s.length();i++)
			{
				num[i-1]=int(s[i]-48);
			}
		}
		else
		{
			positive_num=1;
			place=s.length();
			num=new int[place];
			//cout<<"place:  "<<place<<endl;
			for(unsigned int i=0;i<s.length();i++)
			{
				//cout<<s[i]-48<<endl;
				num[i]=int(s[i]-48);
			}
		}
	}
	//from int data type
	big_num(int n)
	{
		if(n<0)
			positive_num=0;
		else
			positive_num=1;
		int tmp_n=abs(n);
		for(int i=1;;i++)
		{
			if(tmp_n<10)
			{
				place=i;
				break;
			}
			else
			{
				tmp_n=tmp_n/10;
			}
		}
		num=new int[place];
		tmp_n=abs(n);
		for(int i=place-1;i>=0;i--)
		{
			num[i]=tmp_n%10;
			tmp_n=tmp_n/10;
		}

	}
	void multi_single(int m,int position, big_num& re)
	{
		int carry=0;
		string result="";
		for(int i=this->place-1;i>=0;i--)
		{
			int tmp=this->num[i]*m+carry;
			carry=tmp/10;
			result=char(tmp%10+48)+result;
		}
		if(carry!=0)
			result=char(carry+48)+result;
		for(int i=0;i<position;i++)
			result=result+'0';
		//cout<<result<<endl;
		re=big_num(result);
	}
	void plus(big_num& bn, big_num& re)
	{
		int carry=0;
		string result="";
		int theta_len=this->place-bn.place;
		//cout<<this->place<<" "<<bn.place<<endl;
		//cout<<"the_len:  "<<theta_len<<endl;
		for(int i=bn.place-1;i>=0;i--)
		{
			//cout<<"i:  "<<this->num[i+theta_len]<<endl;
			int tmp=this->num[i+theta_len]+bn.num[i]+carry;
			result=char(tmp%10+48)+result;
			carry=tmp/10;
		}
		for(int i=theta_len-1;i>=0;i--)
		{
			int tmp=this->num[i]+carry;
			result=char(tmp%10+48)+result;
			carry=tmp/10;
		}
		re=big_num(result);
	}

	string multi(big_num& bn)
	{
		big_num result;
		this->multi_single(bn.num[bn.place-1],0, result);
		for(int i=bn.place-2;i>=0;i--)
		{
			//cout<<"single:  "<<bn.num[i]<<endl;
			big_num tmp;
			this->multi_single(bn.num[i],bn.place-1-i, tmp);
			tmp.plus(result,result);
		}
		string s="";
		for(int i=result.place-1;i>=0;i--)
		{
			s=char(result.num[i]+48)+s;
		}
		if(this->positive_num^bn.positive_num)
		{
			s='-'+s;
		}
		return s;

	}

};
int main()
{
	string a="-123412341234",b="432143214321";
	big_num p1=big_num(a);
	big_num p2=big_num(b);
	//
	string s=p1.multi(p2);
	cout<<s<<endl;

	//
	long long k=123412341234;
	long long kk=432143214321;
	cout<<sizeof(int)<<" "<<sizeof(long)<<" "<<sizeof(long long)<<endl;
	cout<<k*kk<<endl;
	/*
	//eg:calculate 100!
	big_num fra("1");
	string str_fra;
	for(int n=100;n>=1;n--)
	{
		big_num tmp(n);
		str_fra=fra.multi(tmp);
		fra=big_num(str_fra);
	}
	cout<<str_fra<<endl;
	*/
	system("pause");
	return 0;
}

