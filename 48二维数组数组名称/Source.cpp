#include<iostream>
using namespace std;

//用途
//1.查看二维数组所用的空间
//2.获取二维数组的首地址

int main() {
	int arr[2][3] = { 1,2,3,4,5,6 };

	cout << "占用内存空间大小" << endl;
	cout << sizeof(arr) << endl;
	cout << "元素数目" << endl;
	cout << sizeof(arr) / sizeof(arr[0][0]) << endl;
	cout << "一行元素占空间" << endl;
	cout << sizeof(arr[0]) << endl;
	cout << "单个元素所占空间" << endl;
	cout << sizeof(arr[0][0]) << endl;
	cout << "行的数目" << endl;
	cout << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "列的数目" << endl;
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	cout << "二维数组首地址" << endl;
	cout << &arr << endl;
	cout << "第一个元素的首地址" << endl;
	cout << &arr[0][0] << endl;
	cout << "第一行首地址" << endl;
	cout << &arr[0] << endl;
	cout << "第二行元素首地址" << endl;
	cout << &arr[1] << endl;


}