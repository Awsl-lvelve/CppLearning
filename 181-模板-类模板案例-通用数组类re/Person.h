#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& out, Person& person);
public:
	Person();
	Person(string name, int age);

	void SetName(string& name);
	void SetAge(int age);

private:
	string m_Name;
	int m_Age;
};

ostream& operator<<(ostream& out, Person& person) {
	out << "ÐÕÃû£º" << person.m_Name << "\t" << "ÄêÁä£º" << person.m_Age;
	return out;
}


Person::Person() {
	this->m_Name = "";
	this->m_Age = 0;
}

Person::Person(string name, int age) {
	this->m_Name = name;
	this->m_Age = age;
}

void Person::SetName(string& name) {
	this->m_Name = name;
}

void Person::SetAge(int age)
{
	this->m_Age = age;
}