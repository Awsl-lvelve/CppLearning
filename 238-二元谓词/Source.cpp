#include<iostream>
using namespace std;
#include<vector>

//ν�ʣ�
//����ֵΪbool���͵ķº���Ϊν��
//���operator()����һ��������ΪһԪν��
//���operator()��������������ôΪ��Ԫν��

class GreatFive {
	bool operator()(int v) {
		if (v > 5) return true;
		else return false;
	}
};

void test01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//GreatFive() ����һ��������������
	vector<int>::iterator iter= find_if(v.begin(), v.end(), GreatFive());
	if (iter==v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴���5��" <<*iter<< endl;
	}
}