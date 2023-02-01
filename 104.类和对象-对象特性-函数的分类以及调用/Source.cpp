#include"Person.h"

int main() {
	//括号法
	Person p1;//默认构造
	Person p("侯东江");//有参构造
	Person p2(p);

	//特别注意
	//在使用默认构造函数时，不要用括号，即：Person p()
	//Person p();
	//这会被视为一个函数声明

	//显式法
	Person p3;//无参
	Person p4 = Person("HDJ");//有参
	Person p5 = Person(p4);//拷贝构造

	Person("string");//匿名对象，当前行结束之后，会立即被回收。
	//注意事项：不要用拷贝构造函数初始化匿名对象
	//Person(p5);//用拷贝构造函数初始化匿名对象的一个尝试，编译器会认为这是个对象的声明，导致重复定义的问题

	//隐式转换法
	Person p6 = std::string("string");
	//相当于
	//Person p6("string");
	Person p7 = p6;//拷贝构造！
	
}