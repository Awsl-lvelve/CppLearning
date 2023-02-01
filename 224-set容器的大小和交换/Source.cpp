#include<set>
#include<iostream>
using namespace std;

void PrintSet(const set<int>& iset) {
	for (set<int>::const_iterator citer = iset.begin();
		citer != iset.end();
		citer++)
	{
		cout << *citer << " ";
	}
	cout << endl;
}

void test01() {
	set<int>s1;

	s1.insert(19);
	s1.insert(84);
	s1.insert(1);
	s1.insert(9);
	s1.insert(8);
	s1.insert(4);
	s1.insert(1984);

	//set容器不允许resize

	set<int>s2;

	s2.insert(13);
	s2.insert(87);
	s2.insert(98);
	s2.insert(489);
	s2.insert(999);
	s2.insert(123);
	s2.insert(3090);

	cout<<s1.size()<<endl;
	cout<<s1.max_size()<<endl;
	
	cout << "交换之前："<<endl;
	PrintSet(s1);
	PrintSet(s2);

	cout << "交换之后：" << endl;
	swap(s1, s2);
	PrintSet(s1);
	PrintSet(s2);


}

int main() {
	test01();
}