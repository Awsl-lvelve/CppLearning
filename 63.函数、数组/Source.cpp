#include<iostream>
using namespace std;

void BubbleSort(int* arr, int len) {
	for (size_t i = 0; i < len-1; i++)
	{
		for (size_t j = 0; j < len-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
		}
	}
}

void PrintArray(int* arr, int len) {
	for (size_t i = 0; i < len; i++)
	{
		cout << *arr << endl;
		arr++;
	}
}


int main() {
	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	BubbleSort(arr, 10);
	PrintArray(arr, 10);

}