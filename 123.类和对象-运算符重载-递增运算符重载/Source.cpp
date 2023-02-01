#include<iostream>

class MyInteger
{
	friend std::ostream& operator<<(std::ostream& out, MyInteger myInt);
public:
	MyInteger()=default;
	MyInteger(int num) { this->m_num = num; }
	
	//前置递增
	//返回引用是为了返回本身，使得++(++a)结果正确，如果不是引用的话，那么不是对一个数据进行操作
	MyInteger& operator++() {
		++this->m_num;
		return *this;
	}
	
	//后置递增
	//使用占位参数，作为前置和后置的区分
	//只能用int 其他都不好使
	//前置递增返回的是引用，后置递增返回的是值
	MyInteger operator++(int) {
		//this->m_num++;
		//return *this;
		//先记录当前结果
		MyInteger temp = *this;
		//后 递增
		this->m_num++;
		//返回
		return temp;
	}

private:
	int m_num;
};

std::ostream& operator<<(std::ostream& out, MyInteger myInt) {
	out << "My_Int: " << myInt.m_num << std::endl;
	return out;
}

void test01() {
	MyInteger myint(10);
	std::cout << (++myint) << std::endl;

	
}

void test02() {
	MyInteger myint(10);
	std::cout << ++(++myint) << std::endl;
}

void test03() {
	MyInteger myint(10);
	std::cout << (++myint)++ << std::endl;
}

int main() {
	test01();
	test02();
	test03();
}
