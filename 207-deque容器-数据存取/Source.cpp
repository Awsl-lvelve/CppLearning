#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;


void PrintDeque(const deque<int>& deq) {
	for (deque<int>::const_iterator iter = deq.begin();
		iter != deq.end();
		iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}


void test01() {
	deque<int>deq;
	for (int i = 1; i < 4; i++)
	{
		deq.push_back(i * 10);
	}
	PrintDeque(deq);

	deq.push_front(300);
	deq.push_front(200);

	//ͨ��[]����
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i] << " ";
	}
	cout << endl;

	//����ͷβԪ��
	cout <<"��Ԫ�أ�"<< deq.front() << endl;
	cout <<"βԪ�أ�"<< deq.back() << endl;



}

int main() {
	test01();
}