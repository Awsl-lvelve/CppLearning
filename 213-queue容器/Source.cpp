#include<queue>
#include<string>
#include<iostream>
using namespace std;

//是FIFO

//队列元素，允许从一端新增元素，从另一端移除元素
//队列中只有头尾元素可以使用，所以不允许遍历
//队列中进数据，入队push
//对列中出数据，出队pop

class Person {
public:
	Person(string name, int age) :name(name), age(age) {};
	string name;
	int age;
};

void test01() {
	queue<Person>q;
	Person p1("UltramanNexus", 28);
	Person p2("UltramanZero", 87);
	Person p3("UltramanMax", 18);
	Person p4("UltramanAce", 197);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//查看
	cout << q.front().name << endl;
	cout << q.back().name << endl;

	//出队
	cout << q.size() << endl;
	while (!q.empty())
	{
		cout << q.front().name << endl;
		cout << q.back().name << endl;
		q.pop();
	}
	cout << q.size() << endl;

}



int main() {
	test01();
}