#include<iostream>
using namespace std;

//��;
//1.�鿴��ά�������õĿռ�
//2.��ȡ��ά������׵�ַ

int main() {
	int arr[2][3] = { 1,2,3,4,5,6 };

	cout << "ռ���ڴ�ռ��С" << endl;
	cout << sizeof(arr) << endl;
	cout << "Ԫ����Ŀ" << endl;
	cout << sizeof(arr) / sizeof(arr[0][0]) << endl;
	cout << "һ��Ԫ��ռ�ռ�" << endl;
	cout << sizeof(arr[0]) << endl;
	cout << "����Ԫ����ռ�ռ�" << endl;
	cout << sizeof(arr[0][0]) << endl;
	cout << "�е���Ŀ" << endl;
	cout << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "�е���Ŀ" << endl;
	cout << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	cout << "��ά�����׵�ַ" << endl;
	cout << &arr << endl;
	cout << "��һ��Ԫ�ص��׵�ַ" << endl;
	cout << &arr[0][0] << endl;
	cout << "��һ���׵�ַ" << endl;
	cout << &arr[0] << endl;
	cout << "�ڶ���Ԫ���׵�ַ" << endl;
	cout << &arr[1] << endl;


}