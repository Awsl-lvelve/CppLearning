#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//vector对于头部插入、删除数据效率低
//deque相对而言，对头部的插入删除速度会比vector快
//vector访问元素的速度比deque快，这和二者的内部实现有关


//deque工作原理
//deque内部有中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//中控器维护的是缓冲区的地址，使得deque容器像一篇连续的内存空间

//deque容器也是可以支持随机访问的


//只读迭代器
void PrintDeque(const deque<int>& deq) {
	for (deque<int>::const_iterator iter = deq.begin();
		iter != deq.end();
		iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void test() {
	deque<int>deq;//默认构造
	
	vector<int>ivec;
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}
	deque<int>deq2(ivec.begin(), ivec.end());//利用迭代器组成区间
	
	PrintDeque(deq2);

	deque<int>deq3(10,100);//10个100
	PrintDeque(deq3);
	
	deque<int>deq4(deq2);//拷贝构造
	
}
int main() {
	test();
}
