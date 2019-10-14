#include <iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b,int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "ABCD�в������캯��"<< " a:" << a << " b:" << b << " c:" << c << endl;
	}
	~ABCD() {
		cout << "ABCD��������" << " a:" << a << " b:" << b << " c:" << c << endl;
	}
	int getA() {
		return this->a;
	}
private:
	int a;
	int b;
	int c;
};

//��һ������ʹ����һ���࣬��Ҫ��ʼ���б�
class MyE
{
public:
	MyE():abcd_1(1,2,3),abcd_2(4,5,6),m(100){
		cout << "MyE���޲������캯��" << endl;
	}
	MyE(const MyE & obj) :abcd_1(7, 8, 9), abcd_2(10, 11, 12), m(100) {
		cout << "MyE�Ŀ������캯��" << endl;
	}
	~MyE() {
		cout << "~MyE()" << endl;
	}

public:
	//����������ֻ�붨��˳���йأ����ʼ���б�˳���޹أ���
	ABCD abcd_2; //C++��������֪����ι��죬��Ҫ��ʼ���б�
	ABCD abcd_1;
	const int m; //����const���α�����ʱ��һ��Ҫ��ʼ���б�
};

// doThing(MyE my1)���ã���MyE���е���ABCD���е�getA()����
int doThing(MyE my1) {
	cout << "doThing_my1.abcd_1.getA():  " << my1.abcd_1.getA() << endl;
	return 0;
}

//����һ��MyE�ಢ����doThing����
int run2() {
	//�����޲������캯��
	MyE my2;
	//���ÿ������캯��
	doThing(my2);
	return 0;
}

int main()
{
	//����run2�����в���
	run2();
	system("pause");
	return 0;
}
