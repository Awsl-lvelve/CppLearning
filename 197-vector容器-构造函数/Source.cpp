#include<iostream>
#include<vector>
using namespace std;
//���� ���������� aka��������
//����ͨ���������
//�����Ǿ�̬�ռ䣬vector���Զ�̬��չ
//��̬��չ��������ԭ�пռ�֮�������¿ռ䣬����Ѱ�Ҹ�����ڴ�ռ䣬��ԭʼ���ݿ������¿ռ�

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter=ivec.begin();
		iter!=ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test01() {
	vector<int>ivec;//Ĭ�Ϲ���

	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}

	printVec(ivec);

	//�����������ʽ
	vector<int>ivec1(ivec.begin(), ivec.end());
	printVec(ivec1);

	//n��elem����ʽ
	vector<int>ivec2(10, 100);//10 ��100
	printVec(ivec2);

	//��������
	vector<int>ivec3(ivec2);
	printVec(ivec3);

	//vector<int>ivec1({ 1,2,3,5,6 });//�вι���


}

int main() {
	test01();
}