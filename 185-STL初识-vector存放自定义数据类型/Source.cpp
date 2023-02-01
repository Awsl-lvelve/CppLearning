#include"Person.hpp"


void test() {
	vector<Person<string,int>>pvec;

	//生成person，并添加到容器
	for (int i = 0; i < 16; i++)
	{
		Person<string, int> p;

		p.SetAge(i + 10);//设置年龄

		string str = "Name" + to_string(i + 1);//生成姓名
		p.SetName(str);

		pvec.push_back(p);
	}

	//for (int i = 0; i < pvec.size(); i++)
	//{
	//	cout << pvec[i];
	//}

	for (vector<Person<string,int>>::iterator iter=pvec.begin(); 
		iter!=pvec.end();
		iter++)
	{
		cout << *iter;
	}

	/*for (auto p : pvec) {
		cout << p;
	}*/

	/*for (vector<Person<string,int>>::iterator iter;iter<pvec.end(); iter++)
	{
		cout << *iter;
	}*/

	

}

int main() {
	test();
}