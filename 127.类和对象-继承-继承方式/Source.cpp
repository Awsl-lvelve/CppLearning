class A {
public:
	int a;
protected:
	int b;
private:
	int c;
};

//公共继承
class B :public A {
	//a public
	//b protected
	//c 不可访问
public:
	void Foo() {
		this->a = 10;//ok
		this->b = 10;//ok 不过子类中可以访问
		//this->c = 10; //不准访问
	}
};

void test01() {
	B b;
	b.a = 11;//ok
	//b.b = 111;//no 类外不能访问protected内容
}




//保护继承
class C :protected A {
	//a protected
	//b protected
	//c 不可访问
	void foo() {
		this->a = 11;
		this->b = 12;
	}

};

void test02() {
	C c;
	//c.a = 11;//no 类外不能访问protected内容
	//c.b = 111;//no 类外不能访问protected内容
}

//私有继承
class D :private A {
	//a private
	//b private
	//c 不可访问
};

void test03() {
	D d;
	//d.a//no 类外不能访问private的内容
	//d.b= 11;//no 类外不能访问private的内容
}