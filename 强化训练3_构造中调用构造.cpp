#include <iostream>
using namespace std;

class MyTest
{
public:
	MyTest(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	MyTest(int a, int b) {
		this->a = a;
		this->b = b;
		//�ڹ��캯����������˹��캯��
		MyTest(a, b, 100); //��100��ʼ��C
		//����û����ȥ�ӣ��������������������ˣ������������Ҫ�Ķ�����ȫû��ϵ
	}
	~MyTest() {
		cout << "~MyTest(): " << " a:" << a << " b:" << b << " c:" << c << endl;
	}
	
	int getC() {
		return c;
	}
	void setC(int val) { c = val; }

private:
	int a;
	int b;
	int c;
};

int main() 
{
	MyTest t1(2, 3);
	//c��һ������
	cout << "c: " << t1.getC << endl;
	system("pause");
	return 0;
}