#include<iostream>
using namespace std;

//虽然这个版本的vs可以找到main()后的
//但是一般还是需要提前声明

int max(int a, int b);

int main() {

	int a = 10;
	int b = 20;
	cout<<max(a, b);


	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}