// << 即为左移运算符
#include<iostream>



class Person
{
	friend std::ostream& operator<<(std::ostream& out, Person& p);
public:
	Person() = default;
	Person(int a, int b) {
		this->_A = a;
		this->_B = b;
	};

	//这样的等价形式是 p.operator<<p1,不符合cout<<p的形式
	//所以利用成员函数是实现不了目的的
	/*Person& operator<<(Person& rhs) {
		std::cout << this->_A << std::endl;
		std::cout << this->_B << std::endl;
		return *this;
	}*/

private:
	int _A;
	int _B;
};

std::ostream& operator<<(std::ostream& out, Person& p) {
	out << "_A: " << p._A << " " << "_B: " << p._B << std::endl;
	return out;
}



void test() {
	Person p(10,10);

	std::cout << p << "Hello World" << std::endl;
}

int main() {
	test();
}