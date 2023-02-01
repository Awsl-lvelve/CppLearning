#include<iostream>
#include<string>
using namespace std;

void test() {
	string str = "abcdefgh";

	cout << str << endl;
	str.insert(1, "XYZ");

	cout << str << endl;

	str.erase(1, 3);
	cout << str << endl;
}

int main() {
	test();
}