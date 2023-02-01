#include<iostream>
using namespace std;

//class Java
//{
//public:
//	void header() { cout << "Header" << endl; }
//	void Class() { cout << "JAVA PYTHON...." << endl; }
//	void Content() { cout << "JAVA" << endl; }
//};
//
//class Cpp
//{
//public:
//	void header() { cout << "Header" << endl; }
//	void Class() { cout << "JAVA PYTHON...." << endl; }
//	void Content() { cout << "C++" << endl; }
//};
//
//class Python
//{
//public:
//	void header() { cout << "Header" << endl; }
//	void Class() { cout << "JAVA PYTHON...." << endl; }
//	void Content() { cout << "Python" << endl; }
//};

//void test() {
//	Java ja;
//	ja.header();
//	ja.Class();
//	ja.Content();
//
//	Cpp cp;
//	cp.header();
//	cp.Class();
//	cp.Content();
//
//	Python py;
//	py.header();
//	py.Class();
//	py.Content();
//}

class Base
{
public:
	void header() { cout << "Header" << endl; }
	void Class() { cout << "JAVA¡¢ PYTHON...." << endl; }
};

class Java :public Base {
public :
	void Content() {
		cout << "Java" << endl;
	}
};

class Cpp :public Base {
public:
	void Content() {
		cout << "CPP "<< endl;
	}
};

void test() {
	Java ja;
	ja.header();
	ja.Class();
	ja.Content();

	Cpp cp;
	cp.header(); 
	cp.Class();
	cp.Content();
}


int main() {
	test();
}