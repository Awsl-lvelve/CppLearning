#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//����Ĭ������Ϊ����
//����֧��������ʵĵ�����������������ʹ��sort�㷨
//vector����Ҳ����ʹ��

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
	cout << "����֮ǰ��";
	PrintDeque(deq);
	sort(deq.begin(), deq.end());
	cout << "����֮��";
	PrintDeque(deq);
}

int main() {
	test();
}