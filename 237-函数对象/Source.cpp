#include<iostream>
using namespace std;

//�������󣨷º�����
//����������ʹ��ʱ����������ͨ�����������ã�Ҳ�����в����������з���ֵ
//��������Խ����ͨ�����ĸ����������������Լ���״̬
//�������������Ϊ��������

class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};


//����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01() {
	MyAdd myadd;
	cout << myadd(10, 10)<<endl;
}


class MyPrint {
public:
	void operator()(string test) {
		cout << test << endl;
		this->count_++;
	}
	MyPrint(int count):count_(count) {}
	MyPrint() { this->count_ = 0; }

	int count_;
};

void test02() {
	MyPrint print;
	print("Hello World");
	print("AnyThingPls");
	print("Whatever");
	cout << "���ô���:" << print.count_ << endl;
}

//����������Ϊ��������
void doPrint(MyPrint& print, string test) {
	print(test);
}

void test03() {
	MyPrint pt;
	string  str= "Say hello!";
	doPrint(pt, str);

}

int main() {
	//test01();
	//test02();
	test03();
}
