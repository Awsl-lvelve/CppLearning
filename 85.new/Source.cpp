#include<iostream>
using namespace std;



int* func()
{
	//在堆区创建数据
	int *p=new int(10);
	return p;
}

void test1() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	delete p;
	cout << *p << endl;//现在访问是异常的
}

void test2()
{
	int* p= new int[10];//返回的是首地址，所有可以用int*p接受

	for (int i = 0; i <10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<p[i]<<'\t';
	}

	delete[]p;//释放数组要这样做，不然会错误！


}



int main()
{
	
	test2();
	return 0;
}