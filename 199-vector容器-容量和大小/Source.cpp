#include<iostream>
#include<vector>
using namespace std;

//empty() 判断容器是否为空
//capacity() 容器容量
//size() 容器中元素数量
//reszie(int num) 重新指定容器长度为num。若边长，则填充默认值
//若变短，则超出num的元素被删除
//resize(int num,elem) 指定填充值

void printVec(vector<int>& ivec) {
	for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();
		iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void test01() {
	vector<int>v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVec(v1);

	if (v1.empty())
	{
		//为真，代表容器为空
		cout << "v1为空。" << endl;
	}
	else
	{
		cout << "v1不为空。" << endl;
		cout << "容量: " << v1.capacity() << endl;
		cout << "元素数量：" << v1.size() << endl;
	}

	//v1.resize(15);//如果从新指定的比原来场，默认用0填充
	//v1.resize(15, 100);
	v1.resize(5);
	printVec(v1); //如果从新指定的比原来短，超出部分会被删除

}

int main() {
	test01();
}