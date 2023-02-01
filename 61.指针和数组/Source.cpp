#include<iostream>
using namespace std;

int main() {
	int arr[5] = { 1,2,3,4,5 };

	int* p = arr;//arr就是数组首地址

	//通过指针遍历数组
	for (size_t i = 0; i < 5; i++)
	{
		cout << *p << endl;
		p++;//指针偏移
	}




}