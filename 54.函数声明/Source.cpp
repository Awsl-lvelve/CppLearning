#include<iostream>
using namespace std;

//��Ȼ����汾��vs�����ҵ�main()���
//����һ�㻹����Ҫ��ǰ����

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