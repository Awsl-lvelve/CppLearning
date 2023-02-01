#include<map>
#include<iostream>
#include<string>
using namespace std;

void PrintMap(const map<int, int>& mp) {
	for (map<int, int>::const_iterator citer = mp.begin();
		citer != mp.end();
		citer++) {
		cout << "Key: " << citer->first << " ";
		cout << "Value: " << citer->second << endl;
	}
	cout << endl;
}

void CheckMap(const map<int, int>& mp) {
	if (!mp.empty())
	{
		cout << "�ǿ�" << endl;
		cout << "��С��" << mp.size() << endl;
	}
	else
	{
		cout << "��" << endl;
	}
}

void test() {
	map<int, int>mp1;
	mp1.insert(make_pair(1, 2));
	mp1.insert(pair<int, int>(11, 12));
	mp1.insert(map<int, int>::value_type(21, 22));
	mp1[4] = 40;//������ʹ�����ַ�ʽ���룬��Ϊ������ϰ�߻ᵼ������Ĵ���
	PrintMap(mp1);
	//cout << mp1[5] << endl;//map�в����ڼ�ֵΪ5�ģ�Ӧ�ô�ӡʧ�ܣ����Ǳ�����Ϊ�㴴�����µ�pair��Ĭ��valueֵ��0
	//PrintMap(mp1);

	mp1.erase(mp1.begin());
	PrintMap(mp1);
	//mp1.begin() = mp1.end();//�ƺ�����Ч�������������
	PrintMap(mp1);
}

int main() {
	test();
}
