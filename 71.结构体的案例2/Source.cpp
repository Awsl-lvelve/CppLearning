#include<iostream>
#include<string>

using namespace std;

struct Hero
{
	string name;
	int age;
	string gender;
};


void BubbleSort(Hero hArray[], int len) {
	for (size_t i = 0; i < len-1; i++)
	{
		for (size_t j = 0; j < len-1-i; j++)
		{
			if (hArray[j].age>hArray[j+1].age)
			{
				struct Hero temp = hArray[j];
				hArray[j] = hArray[j + 1];
				hArray[j + 1] = temp;
				
			}
		}
	}
};

void Print(Hero hArray[], int len) {
	for (size_t i = 0; i < len; i++)
	{
		cout << hArray[i].name << " " <<
			hArray[i].age << " " <<
			hArray[i].gender << endl;
	}
}

void AllocateSpace(string Hname[], int ages[], string gender[],Hero heros[],int len) {
	for (size_t i = 0; i < len; i++)
	{
		heros[i].name= Hname[i];
		heros[i].age = ages[i];
		heros[i].gender = gender[i];
	}
}

int main() {
	Hero hArray[5];

	string Names[] = { "Áõ±¸","¹ØÓð","ÕÅ·É","ÕÔÔÆ","õõ²õ" };

	int Ages[] = { 23, 22, 20, 21,19 };

	string Genders[] = { "ÄÐ","ÄÐ","ÄÐ","ÄÐ","Å®" };

	AllocateSpace(Names, Ages, Genders, hArray, 5);

	Print(hArray, 5);

	cout << endl;

	BubbleSort(hArray, 5);

	Print(hArray, 5);

}