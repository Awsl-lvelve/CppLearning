#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void PrintDeque(const deque<int>& deq) {
	for (deque<int>::const_iterator iter = deq.begin();
		iter != deq.end();
		iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void test() {
	deque<int>deq1;

	for (int i = 0; i < 10; i++)
	{
		deq1.push_back(i);
	}
	PrintDeque(deq1);

	deque<int>deq2;
	deq2 = deq1;
	PrintDeque(deq2);

	deque<int>deq3;
	deq3.assign(deq1.begin(), deq1.end());
	PrintDeque(deq3);

	deque<int>deq4;
	deq4.assign(10, 100);
	PrintDeque(deq4);	
}

int main() {
	test();
 }