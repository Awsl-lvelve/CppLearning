#include"PersonImple.cpp"
//直接包含person类实现的cpp文件

void test() {
	Person<string, int>p("Ultraman", 20000);
	p.ShowPerson();
}

int main() {
	test();
}