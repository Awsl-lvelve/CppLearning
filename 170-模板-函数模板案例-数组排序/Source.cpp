#include<iostream>
using namespace std;

template<class T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void SelectionSort(T arr[],int len) {
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶�ֵ�����ֵ���±�
		for (int j = i+1; j < len; j++)
		{
			if (arr[max] < arr[j]) {//�϶������ֵ���ȱ����������ֵ��С��˵��j�±�Ԫ�ز������������
				max = j;//�������ֵ�±�
			}
		}
		if (max!=i)
		{
			Swap(arr[i], arr[max]);
		}
	}
}

template<class T>
void PrintFunc(T arr[],int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

void test01() {
	//����char����
	char charArr[] = "badcfe";
	int len = sizeof(charArr) / sizeof(charArr[0]);

	SelectionSort(charArr, len);

	PrintFunc(charArr, len);


	int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	len = sizeof(intArr) / sizeof(intArr[0]);

	SelectionSort(intArr,len);

	PrintFunc(intArr, len);
}

int main() {
	test01();
}