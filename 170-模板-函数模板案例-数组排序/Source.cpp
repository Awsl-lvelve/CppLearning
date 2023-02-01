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
		int max = i;//认定值的最大值的下表
		for (int j = i+1; j < len; j++)
		{
			if (arr[max] < arr[j]) {//认定的最大值，比遍历出的最大值更小，说明j下表元素才是真正的最大
				max = j;//更新最大值下表
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
	//测试char数组
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