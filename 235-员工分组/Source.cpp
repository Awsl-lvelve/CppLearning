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
		cout << "姓名：" << iter->GetName()<<" ";
		cout << "薪资：" << iter->GetSalary() << endl;
	}
	cout << endl;
}

void CreateWorker(vector<Worker>&v) {
	string name_seed="ABCDEFGHIJ";

	//for (string::iterator iter=name_seed.begin();
	//	iter!=name_seed.end();
	//	iter++)
	//{
	//	string name = "员工" + *iter;
	//	int salary = rand() % 10000+10000;
	//	Worker worker(name, salary);
	//	v.push_back(worker);
	//}

	for (int i = 0; i < 10; i++)
	{
		string name = string("员工") + name_seed[i];
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
		//产生随机部门编号
		int dep_id = rand() % 3;
		//将员工插入分组
		m.insert(make_pair(dep_id, w));
	}
}

void ShowMap(multimap<int,Worker>&m) {

	cout << "策划部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);//返回的是所有CEHUA的位置的迭代器？

	int count = m.count(CEHUA);//统计人数
	int index = 0;//multimap容器是有序的，用index控制重复量
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.GetName() << " ";
		cout << "薪水：" << pos->second.GetSalary() << " ";
	}
	cout << endl;

	cout << "美术部门" << endl;
	pos = m.find(MEISHU);//返回的是所有CEHUA的位置的迭代器？

	count = m.count(MEISHU);//统计人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.GetName() << " ";
		cout << "薪水：" << pos->second.GetSalary() << " ";
	}

	cout << endl;
	cout << "研发部门" << endl;
	pos = m.find(YANFA);//返回的是所有CEHUA的位置的迭代器？

	count = m.count(YANFA);//统计人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.GetName() << " ";
		cout << "薪水：" << pos->second.GetSalary() << " ";
	}

}

int main() {

	//创建员工
	vector<Worker>vec;
	CreateWorker(vec);

	//员工分组
	multimap<int, Worker>m;
	SetGroup(vec, m);
	ShowMap(m);


}
