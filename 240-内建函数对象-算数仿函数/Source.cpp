#include<iostream>
#include<vector>
#include<functional>

using namespace std;

//negate 

//plus 

void test01() {
	negate<int>n;
	cout<<n(50)<<endl;
}

void test02() {
	plus<int>p;
	cout << p(10, 20) << endl;
}

int main() {
	test01();
	test02();

}