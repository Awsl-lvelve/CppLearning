#include<stack>
#include<iostream>
#include<string>
using namespace std;

//stackջ������ȳ���

//stack�������б�����Ϊ
//�����Ƿ��ʱ��㷨����ջֻ��ջ��Ԫ�ز��ܱ�����
//ջ�����ж������Ƿ�Ϊ��

//ջ���Է����Ƿ�Ϊ��
//ջ���Է���Ԫ������

void test() {
	stack<int>i_stack;

	i_stack.push(10);//��ջ
	i_stack.push(20);
	i_stack.push(30);
	i_stack.push(40);
	cout << "ջ��Ԫ�أ�" << i_stack.top() << endl;//ջ��Ԫ��

	i_stack.pop();//��ջ
	i_stack.top();//ջ��Ԫ��
	i_stack.emplace(1);//?
	i_stack.size();//Ԫ������
	i_stack.empty();//Ϊ�գ�
	
}

int main() {
	test();
}