#include"Person.h"

int main() {
	//���ŷ�
	Person p1;//Ĭ�Ϲ���
	Person p("���");//�вι���
	Person p2(p);

	//�ر�ע��
	//��ʹ��Ĭ�Ϲ��캯��ʱ����Ҫ�����ţ�����Person p()
	//Person p();
	//��ᱻ��Ϊһ����������

	//��ʽ��
	Person p3;//�޲�
	Person p4 = Person("HDJ");//�в�
	Person p5 = Person(p4);//��������

	Person("string");//�������󣬵�ǰ�н���֮�󣬻����������ա�
	//ע�������Ҫ�ÿ������캯����ʼ����������
	//Person(p5);//�ÿ������캯����ʼ�����������һ�����ԣ�����������Ϊ���Ǹ�����������������ظ����������

	//��ʽת����
	Person p6 = std::string("string");
	//�൱��
	//Person p6("string");
	Person p7 = p6;//�������죡
	
}