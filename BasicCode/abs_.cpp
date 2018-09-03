#include<iostream>
#include<string>
using namespace std;
//
int abs_(int n);
int abs__(int n);
int main()
{

	cout<<abs_(-10)<<' '<<abs_(33)<<endl;

	system("pause");
	return 0;
}

int abs_(int n)//不使用>, <, if等条件语句
{
	/*
	1->-1, 即1对应于-1
	0-> 1, 即0对应于 1
	因为不能用大于小于号，故只能利用编码中用来表示0 和1的信息，即int类型的第31位
	1表示负数，0表示正数，只需要将这两个数字映射成-1和1，即可作为参数n的一个修正系数，返回n的绝对值
	两点确定一条直线，映射关系是y=-2x+1
	*/
	//cout<<sizeof(n)<<" bytes"<<endl;
	unsigned int sign = (n>>(8*sizeof(n)-1))&(0x01);//有的机器上int可能只有2 bytes
	//cout<<sign<<endl;
	return (-2*sign+1)*n;
}
int abs__(int n)
{
	/*
	另一个思路是直接修改整数n的符号位，直接取为0
	但是实际上，位运算操作的是数字的补码，故该思路难以直接进行，从下面的例子可以看出，实际和理想的差别很大。
	*/
	unsigned char a=0x7f;//(1<<7);
	char b=-2;
	//此处的原码是10000010，补码是11111110，a的补码是原码自身，
	//所以b&a就是0111110，这是正数，不需要再进行转换原码来了，即答案是126
	cout<<int(a)<<' '<<(b&a)<<' '<<~a<<endl;

	return 0;
}