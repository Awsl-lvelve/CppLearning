#include<iostream>
using namespace std;

//��ӡ���ݵĺ���
void ShowValue(const int& ref) {
	cout << ref << endl;
}


int main() {
	//�������ã������βΣ���ֹ�����
	int a = 10;
	
	//int& ref = 10;//�����ǲ��е�
	const int& ref = 10;//�����ǿ��Ե�
	//������ int temp=10�� const int&ref=temp;
	//����const�ͷ�ֹ�޸��β�
	ShowValue(ref);
	

	


}