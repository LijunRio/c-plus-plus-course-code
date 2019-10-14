#include <iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "--构造函数----" << endl;
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		cout << "------------" << endl;
	}
	~ABCD() {
		cout << "--析构函数----" << endl;
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		cout << "------------" << endl;
	}
	int getA() {
		return this->a;
	}
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	MyE() :abcd_1(1, 2, 3), abcd_2(4, 5, 6), m(100) {
		cout << "MyE()" << endl;
	}
	MyE(const MyE & obj) :abcd_1(7, 8, 9), abcd_2(10, 11, 12), m(100) {
		cout << "MyE(const MyE & obj)" << endl;
	}
	~MyE() {
		cout << "~MyE()" << endl;
	}

public:
	ABCD abcd_1; //C++编译器不知道如何构造，需要初始化列表
	ABCD abcd_2;
	const int m;
};

int doThing(MyE my1) {
	cout << "doThing_my1.abcd_1.getA():  " << my1.abcd_1.getA() << endl;
	return 0;
}

int run2() {
	MyE my2;
	doThing(my2);
	return 0;
}

int run3() {
	cout << "run3 start...." << endl;
	//临时对象的生命周期
	ABCD abcd1(400, 500, 600); //这一句话一结束声明周期就结束
	//因为没人去接，所以立马就析构了

	//如果把匿名对象转换为另一个对象，那就不一样了转正了
	//ABCD abcd2 = ABCD(100, 200, 300);
	cout << "run3 end..." << endl;
	return 0;
}

int main()
{
	run3();
	system("pause");
	return 0;
}
