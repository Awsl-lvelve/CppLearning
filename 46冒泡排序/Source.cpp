#include<iostream>
using namespace std;


void Swap(int& i, int& j) {
	int temp = i;
	i = j;
	j = temp;
}

void BubbleSort(int arr[],int size) {
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}



int main() {
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	
	int length = sizeof(arr) / sizeof(arr[0]);

	for (size_t i = 0; i < length; i++)
	{
		if (i==length-1)
		{
			cout << arr[i] << endl;
			break;
		}
		else
		{
			cout << arr[i] << " ";
		}
	}

	BubbleSort(arr, length);

	for (size_t i = 0; i < length; i++)
	{
		if (i == length - 1)
		{
			cout << arr[i] << endl;
			break;
		}
		else
		{
			cout << arr[i] << " ";
		}
	}



}
