#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//排序：默认排序为升序
//对于支持随机访问的迭代器容器，都阔以使用sort算法
//vector容器也可以使用

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
	deq.push_back(15);
	deq.push_back(210);
	deq.push_back(-488);
	deq.push_back(414);
	cout << "排序之前：";
	PrintDeque(deq);
	sort(deq.begin(), deq.end());
	cout << "排序之后：";
	PrintDeque(deq);
}

int main() {
	test();
}