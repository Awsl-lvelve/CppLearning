#include<iostream>
using namespace std;

void GetTotalScore(int arr[][3], int row, int col,string names[]) {
	for (size_t i = 0; i <row; i++)
	{
		int sum = 0;
		for (size_t j = 0; j < col; j++)
		{
			sum += arr[i][j];
		}
		cout << "��" << i + 1 << "λѧ����"<<names[i] << "���ܷ�Ϊ: " << sum << endl;
	}
}


int main() {
	int arr[3][3] = { {100,100,100},{90,50,100},{60,70,80} };

	string names[3] = { "����","����","����" };

	GetTotalScore(arr, 3, 3, names);





}