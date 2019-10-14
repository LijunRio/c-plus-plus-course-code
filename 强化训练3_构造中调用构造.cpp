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
		//在构造函数里面调用了构造函数
		MyTest(a, b, 100); //把100初始化C
		//但是没有人去接，匿名对象立即被析构了，和这个本来想要的对象完全没关系
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
	//c是一个乱码
	cout << "c: " << t1.getC << endl;
	system("pause");
	return 0;
}