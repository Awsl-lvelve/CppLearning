#include"header.h"

int Sum(int arr[], int length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum;
}