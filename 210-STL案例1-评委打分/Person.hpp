#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class NameType,class ScoreType>
class Person {
public:
	Person(NameType name, ScoreType score) {
		this->m_name = name; 
	this->m_score = score; };

	NameType GetName() { return this->m_name; }
	ScoreType GetScore() { return this->m_score; }

	void SetName(const NameType& name) { this->m_name = name; };
	void SetScore(const ScoreType& score) { this->m_score = score; }

private:
	NameType m_name;
	ScoreType m_score;
};

