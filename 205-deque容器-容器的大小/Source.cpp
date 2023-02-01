#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

//dequeû��capacity����

//deque��С����
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
	string str=deq.empty()== true ? string("��deque") : string("�ǿ�deque");
	cout <<str << endl;
	
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	str=deq.empty() == true ? string("��deque") : string("�ǿ�deque");
	cout << str << endl;

	if (deq.empty())
	{
		cout << "��deque" << endl;
	}
	else
	{
		cout << "�ǿ�deque" << endl;
		cout << "Ԫ��������" << deq.size() << endl;
	}

	//����ָ����С
	deq.resize(15, 1);//ָ�����ֵΪ1

	PrintDeque(deq);

	deq.resize(5);
	PrintDeque(deq);
	
}

int main() {
	test();
}