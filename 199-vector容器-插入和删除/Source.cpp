#include<iostream>
#include<vector>
using namespace std;

//push_back(elem)
//pop_back()
//insert(const_iterator pos,ele)
//inset



void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void test() {
	vector<int>v1;
	for (int i = 1; i < 6; i++)
	{
		v1.push_back(i * 10);//β��
	}

	printVec(v1);
	v1.pop_back();//βɾ
	printVec(v1);

	//����
	v1.insert(v1.begin(), 10000);//ͨ������������
	printVec(v1);

	v1.insert(v1.begin(), 2, 111111);
	printVec(v1);

	//ɾ��
	v1.erase(v1.begin());
	//v1.erase(v1.begin(), v1.end());//���������
	v1.clear();
	printVec(v1);

}

int main() {
	test();
}