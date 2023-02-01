#include<iostream>
#include<string>
using namespace std;


//子类所继承的父类是一个类模板时，子类在声明的时候，现需要指定出父类中T的类型
//如果不指定，编译器无法为子类分配内存
//如果想灵活确定父类的类型，那么子类也需要变成类模板


template<class T>
class Base {
public:
	T m;
};


class Son :public Base<int> {

};

//如果想灵活确定父类的类型，那么子类也需要变成类模板
template<class T1,class T2>
class Son1 :public Base {
	T2 obj;//T1就对应了父类中的T
};