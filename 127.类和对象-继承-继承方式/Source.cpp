class A {
public:
	int a;
protected:
	int b;
private:
	int c;
};

//�����̳�
class B :public A {
	//a public
	//b protected
	//c ���ɷ���
public:
	void Foo() {
		this->a = 10;//ok
		this->b = 10;//ok ���������п��Է���
		//this->c = 10; //��׼����
	}
};

void test01() {
	B b;
	b.a = 11;//ok
	//b.b = 111;//no ���ⲻ�ܷ���protected����
}




//�����̳�
class C :protected A {
	//a protected
	//b protected
	//c ���ɷ���
	void foo() {
		this->a = 11;
		this->b = 12;
	}

};

void test02() {
	C c;
	//c.a = 11;//no ���ⲻ�ܷ���protected����
	//c.b = 111;//no ���ⲻ�ܷ���protected����
}

//˽�м̳�
class D :private A {
	//a private
	//b private
	//c ���ɷ���
};

void test03() {
	D d;
	//d.a//no ���ⲻ�ܷ���private������
	//d.b= 11;//no ���ⲻ�ܷ���private������
}