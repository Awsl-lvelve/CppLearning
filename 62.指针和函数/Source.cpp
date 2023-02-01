#include<iostream>
using namespace std;

void Swap(int* a,int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 100;
	int b = 200;

	Swap(&a, &b);

	cout << a << " " << b << endl;
	
}