#include<iostream>
using namespace std;

class Base
{
public :
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son :public Base
{
public:
	int m_d;
};

void test() {
	Son s;
	/// <summary>
	/// 父类中所有非静态成员属性都会被子类继承下去
	/// 父类私有成员属性 是被编译器给屏蔽了，所以子类是访问不到的，但是确实被继承下去了
	/// 
	/// </summary>
	cout << "sizeof son s is " << sizeof(s) << endl;
}

/// <summary>
/// 利用开发对象命令提示工具：
/// step 1:跳转盘符
/// step 2:跳转文件路径 cd 具体路径之下
/// step 3：查看命名
/// step 4：cl reportSingleClass类名 文件名
/// </summary>
/// <returns></returns>

int main() {
	test();
}
