#include<iostream>
#include<deque>
#include<vector>
using namespace std;

//vector����ͷ�����롢ɾ������Ч�ʵ�
//deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
//vector����Ԫ�ص��ٶȱ�deque�죬��Ͷ��ߵ��ڲ�ʵ���й�


//deque����ԭ��
//deque�ڲ����п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
//�п���ά�����ǻ������ĵ�ַ��ʹ��deque������һƪ�������ڴ�ռ�

//deque����Ҳ�ǿ���֧��������ʵ�


//ֻ��������
void PrintDeque(const deque<int>& deq) {
	for (deque<int>::const_iterator iter = deq.begin();
		iter != deq.end();
		iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void test() {
	deque<int>deq;//Ĭ�Ϲ���
	
	vector<int>ivec;
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}
	deque<int>deq2(ivec.begin(), ivec.end());//���õ������������
	
	PrintDeque(deq2);

	deque<int>deq3(10,100);//10��100
	PrintDeque(deq3);
	
	deque<int>deq4(deq2);//��������
	
}
int main() {
	test();
}
