#include<iostream>
using namespace std;

int main() {
	int two_d_arr[2][3] = {{ 1, 2, 3 }, { 4, 5, 6 }};

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 3;j++)
		{
			cout << two_d_arr[i][j] << " ";
		}
		cout << endl;
	}

	int arr[2][3] = { 1,2,3,4,5,6 };
	int arr1[2][2][2] = { 0 };

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			for (size_t k =0 ; k < 2; k++)
			{
				arr1[i][j][k] = i + j + k;
				cout << arr1[i][j][k] << " ";
			}
			cout <<'*';
		}
		cout << endl;
	}

}