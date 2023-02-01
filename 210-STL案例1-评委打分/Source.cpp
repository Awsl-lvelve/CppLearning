#include"Person.hpp"
#include<deque>
#include<vector>
#include<algorithm>
#include<ctime>

void createPerson(vector<Person<string,int>>&pvec) {
	string name_seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += name_seed[i];
		int score = 0;
		Person<string, int> p(name, score);
		pvec.push_back(p);
	}
}

void PrintDeq(deque<int>d) {
	for (auto c : d) {
		cout << c << " " << " ";
	}
	cout << endl;
}

void PrintVec(vector<Person<string, int>>&pvec) {
	for (vector<Person<string, int>>::iterator iter = pvec.begin();
		iter != pvec.end();
		iter++) {
		cout <<"姓名："<< iter->GetName() << " "
			<< "分数："<<iter->GetScore() << endl;
	}
	cout << endl;
}

//打分
void SetScore(vector<Person<string, int>>& pvec) {

	
	for (vector<Person<string, int>>::iterator iter=pvec.begin();
		iter!=pvec.end();
		iter++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		//去除最高分、最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator iter2 = d.begin();
			iter2 != d.end(); 
			iter2++) {
			sum += *iter2;
		}
		int avg = sum / d.size();
		iter->SetScore(avg);

		//cout << iter->GetName() << " ";
		//PrintDeq(d);
	}
	
}

void test() {
	//随机数种子


	vector<Person<string, int>>v;
	createPerson(v);
	PrintVec(v);
	SetScore(v);
	PrintVec(v);
}

int main() {
	srand((unsigned int)time);
	test();
}