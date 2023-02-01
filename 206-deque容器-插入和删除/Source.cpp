#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

//����
//���˲���
//push_back
//push_front
//pop_back
//pop_front

//ָ��λ�ò���
//insert(pos,elem)
//insert(pos,n,elem)
//insert(pos,beg,end)

//������� clear
//erase(beg,end)
//erase(pos)



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
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}

	//β��
	deq.push_back(10);
	deq.push_back(11);
	PrintDeque(deq);

	//ͷ��
	deq.push_front(100);
	deq.push_front(200);
	PrintDeque(deq);

	//βɾ
	deq.pop_back();
	deq.pop_back();
	PrintDeque(deq);

	//ͷɾ
	deq.pop_front();
	deq.pop_front();
	PrintDeque(deq);
}

void test02() {
	deque<int>deq;
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	deq.insert(deq.begin(),1000);
	PrintDeque(deq);
	deq.insert(deq.begin(), 2, 10000);
	PrintDeque(deq);


	deque<int>deq2;
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i*15);
	}
	
	deq.insert(deq.begin(), deq2.begin(), deq2.end());
	PrintDeque(deq);

}

void test03() {
	deque<int>deq;
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	
	//ɾ��
	deque<int>::iterator iter2 = deq.begin();
	iter2++;
	deq.erase(iter2);

	//��������ɾ��
	deq.erase(deq.begin(), deq.end());

	//���
	deq.clear();

}

int main() {
	test03();
}