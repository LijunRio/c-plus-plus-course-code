#include <iostream>
using namespace std;

class Test
{
public:
	int addC() { c++; };
	void printC() { cout << "c: " << c << endl; }
	//��̬��Ա����
	//�ھ�̬��Ա�������ܵ�����ͨ��Ա���Ի�����ͨ��Ա������
	//��̬�������治��ʹ����ͨ��Ա����
	static int getC() { 
		return c; 
		//��̬��Ա����������ʹ�þ�̬��Ա����
		//������ͨ��Ա������̬�����޷�ʹ��
		//��Ϊ��������֪�����ĸ���ı���
		//����̬��Ա������������ģ����Կ���ʹ��
		//cout << "a: " << a << endl;
	}
private:
	int a;
	int b;
	//��̬��Ա����
	static int c;
};
int Test::c = 10;

void objectplay1() {
	Test t1, t2, t3;
	//c��ֵһ�ı䣬���ж��ı�
	t1.printC();
	t2.addC();
	t3.printC();
	//��̬��Ա�����ĵ��÷���
	t3.getC();
	Test::getC();
}

int main()
{
	system("pause");
}