#include"MyArray.hpp"
#include"Person.h"

void test() {
	MyArray<int> arr(100);

	for (int i = 0; i < 50; i++)
	{
		arr.PushBack(i);
	}

	cout << arr << endl;

	arr.PushBack(1001);
	cout << arr;

}


void test02() {
	MyArray<Person>parr(19);
	for (int i = 0; i < 16; i++)
	{
		Person p;
		p.SetAge(i + 10);//��������
		string str = "Name" + to_string(i+1);//��������
		p.SetName(str);

		parr.PushBack(p);
	}
	cout << parr << endl;

	cout << "������" << parr.GetCapacity() << endl;
	cout << "Ԫ��������" << parr.GetElemNum() << endl;
	cout << "............................" << endl;

	for (int i = 0; i < 10; i++)
	{
		parr.PopBack();
	}

	cout << parr;

	cout << "������" << parr.GetCapacity() << endl;
	cout << "Ԫ��������" << parr.GetElemNum() << endl;
}



int main() {
	//test();
	test02();
}