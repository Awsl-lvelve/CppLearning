#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void test01() {
	vector<vector<int>>twoDvec;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	//twoDvec.push_back(v1);
	//twoDvec.push_back(v2);
	//twoDvec.push_back(v3);
	//twoDvec.push_back(v4);
	//twoDvec.push_back(v5);放前面是空的？为甚么？？？

	for (int i = 1; i < 6; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
		v5.push_back(i+4);
	}

	twoDvec.push_back(v1);
	twoDvec.push_back(v2);
	twoDvec.push_back(v3);
	twoDvec.push_back(v4);
	twoDvec.push_back(v5);//放后面是好的

	//int i = 1;
	//int j = 1;
	//for (vector<vector<int>>::iterator iter = twoDvec.begin();
	//	iter < twoDvec.end(); 
	//	iter++)
	//{
	//	//傻了吧唧的，这里面是空的
	//	for (vector<int>::iterator iter2=(*iter).begin();
	//		iter2 != (*iter).end();
	//		iter2++)
	//	{
	//		//*iter2 = i * j;
	//		(*iter).push_back(i * j);
	//		j++;
	//	}
	//	i++;
	//}
	/*for (auto c:twoDvec)
	{
		for (auto d:c)
		{
			cout << d << "\t";
		}
	}*/
	//for (vector<vector<int>>::iterator iter = twoDvec.begin();
	//	iter < twoDvec.end();
	//	iter++)
	//{
	//	for (vector<int>::iterator iter2 = (*iter).begin();
	//		iter2 != (*iter).end();
	//		iter2++)
	//	{
	//		cout << *iter2<<" ";
	//	}
	//	cout << endl;
	//}

	//遍历方法
	/*for (auto c : twoDvec) {
		for (auto d:c)
		{
			cout << d << "\t";
		}
		cout << endl;
	}*/

	for (vector<vector<int>>::iterator iter = twoDvec.begin();
		iter != twoDvec.end();
		iter++) {
		for (vector<int>::iterator iter2 = (*iter).begin();
			iter2 != (*iter).end();
			iter2++
			) {
			cout << *iter2 << " ";
		}
		cout << endl;
	}

}

int main() {
	test01();
}
