#include"PersonImple.cpp"
//ֱ�Ӱ���person��ʵ�ֵ�cpp�ļ�

void test() {
	Person<string, int>p("Ultraman", 20000);
	p.ShowPerson();
}

int main() {
	test();
}