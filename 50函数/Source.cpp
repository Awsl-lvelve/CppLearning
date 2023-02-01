#include<iostream>
using namespace std;

double GetSum(int a, int b) {
	return a + b;
}

int main() {
	int a = 5;
	int b = 5;
	cout << GetSum(a, b) << endl;

	return 0;
}