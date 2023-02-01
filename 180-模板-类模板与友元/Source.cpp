#include"Person.hpp"

void test() {
	Person<string, int> p("UltramanNexus", 1998);
	PrintPerson(p);
	PrintPerson2(p);
}

int main() {
	test();
}