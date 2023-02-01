#include<vector>
#include<map>
#include<iostream>
#include<string>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker {
public:
	Worker(string name,int salary):name_(name),salary_(salary){}

	string GetName()const { return this->name_; }
	int GetSalary()const { return this-> salary_; }

private:
	string name_;
	int salary_;
};


void Printer(const vector<Worker>& wvec) {
	for (vector<Worker>::const_iterator iter = wvec.begin();
		iter != wvec.end();
		iter++) {
		cout << "������" << iter->GetName()<<" ";
		cout << "н�ʣ�" << iter->GetSalary() << endl;
	}
	cout << endl;
}

void CreateWorker(vector<Worker>&v) {
	string name_seed="ABCDEFGHIJ";

	//for (string::iterator iter=name_seed.begin();
	//	iter!=name_seed.end();
	//	iter++)
	//{
	//	string name = "Ա��" + *iter;
	//	int salary = rand() % 10000+10000;
	//	Worker worker(name, salary);
	//	v.push_back(worker);
	//}

	for (int i = 0; i < 10; i++)
	{
		string name = string("Ա��") + name_seed[i];
		int salary = rand() % 10000 + 10000;
		Worker worker(name, salary);
		v.push_back(worker);
	}

	Printer(v);
}

void SetGroup(const vector<Worker>&v, multimap<int, Worker>& m)
{
	for (auto w:v)
	{
		//����������ű��
		int dep_id = rand() % 3;
		//��Ա���������
		m.insert(make_pair(dep_id, w));
	}
}

void ShowMap(multimap<int,Worker>&m) {

	cout << "�߻�����" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);//���ص�������CEHUA��λ�õĵ�������

	int count = m.count(CEHUA);//ͳ������
	int index = 0;//multimap����������ģ���index�����ظ���
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.GetName() << " ";
		cout << "нˮ��" << pos->second.GetSalary() << " ";
	}
	cout << endl;

	cout << "��������" << endl;
	pos = m.find(MEISHU);//���ص�������CEHUA��λ�õĵ�������

	count = m.count(MEISHU);//ͳ������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.GetName() << " ";
		cout << "нˮ��" << pos->second.GetSalary() << " ";
	}

	cout << endl;
	cout << "�з�����" << endl;
	pos = m.find(YANFA);//���ص�������CEHUA��λ�õĵ�������

	count = m.count(YANFA);//ͳ������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.GetName() << " ";
		cout << "нˮ��" << pos->second.GetSalary() << " ";
	}

}

int main() {

	//����Ա��
	vector<Worker>vec;
	CreateWorker(vec);

	//Ա������
	multimap<int, Worker>m;
	SetGroup(vec, m);
	ShowMap(m);


}
