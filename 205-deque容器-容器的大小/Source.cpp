#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

//deque没有capacity方法

//deque大小操作
//deque.empyt()
//deque.size()
//deque.resize()
//deque.resize()

void PrintDeque(const deque<int>& deq) {
	for (deque<int>::const_iterator iter = deq.begin();
		iter != deq.end();
		iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void test() {
	deque<int>deq;
	string str=deq.empty()== true ? string("空deque") : string("非空deque");
	cout <<str << endl;
	
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	str=deq.empty() == true ? string("空deque") : string("非空deque");
	cout << str << endl;

	if (deq.empty())
	{
		cout << "空deque" << endl;
	}
	else
	{
		cout << "非空deque" << endl;
		cout << "元素数量：" << deq.size() << endl;
	}

	//重新指定大小
	deq.resize(15, 1);//指定填充值为1

	PrintDeque(deq);

	deq.resize(5);
	PrintDeque(deq);
	
}

int main() {
	test();
}