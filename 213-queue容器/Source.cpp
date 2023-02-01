#include<queue>
#include<string>
#include<iostream>
using namespace std;

//��FIFO

//����Ԫ�أ������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
//������ֻ��ͷβԪ�ؿ���ʹ�ã����Բ��������
//�����н����ݣ����push
//�����г����ݣ�����pop

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

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//�鿴
	cout << q.front().name << endl;
	cout << q.back().name << endl;

	//����
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