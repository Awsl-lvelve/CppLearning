#include<iostream>
#include<string>
using namespace std;


//�������̳еĸ�����һ����ģ��ʱ��������������ʱ������Ҫָ����������T������
//�����ָ�����������޷�Ϊ��������ڴ�
//��������ȷ����������ͣ���ô����Ҳ��Ҫ�����ģ��


template<class T>
class Base {
public:
	T m;
};


class Son :public Base<int> {

};

//��������ȷ����������ͣ���ô����Ҳ��Ҫ�����ģ��
template<class T1,class T2>
class Son1 :public Base {
	T2 obj;//T1�Ͷ�Ӧ�˸����е�T
};