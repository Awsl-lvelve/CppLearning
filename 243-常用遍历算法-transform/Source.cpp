#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

//��ֵ�º�����
class Transform {
public:
	int operator()(const int&v) { return v; }
};

//��ӡ�º���
class Print {
public:
	void operator()(const int&v) {
		cout << v << " ";
	}
};


void test01() {
	vector<int>ivec;

	for (int i = 0; i < 10; i++) {
		ivec.push_back(rand() % 100);
	}//���Ԫ��

	vector<int>vTarget;
	vTarget.resize(ivec.size());//����׼���ռ䣡

	//tranform(v1.beg,v1.end,v2.beg,Func);
	//������ֵ���ѣ�����TransForm���ص��ǲ�������
	transform(ivec.begin(), ivec.end(), vTarget.begin(), Transform());
	//��ӡ�º���
	for_each(ivec.begin(), ivec.end(), Print());
}

int main() {
	test01();
}