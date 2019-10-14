#include <iostream>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b,int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "ABCD有参数构造函数"<< " a:" << a << " b:" << b << " c:" << c << endl;
	}
	~ABCD() {
		cout << "ABCD析构函数" << " a:" << a << " b:" << b << " c:" << c << endl;
	}
	int getA() {
		return this->a;
	}
private:
	int a;
	int b;
	int c;
};

//在一个类中使用另一个类，需要初始化列表
class MyE
{
public:
	MyE():abcd_1(1,2,3),abcd_2(4,5,6),m(100){
		cout << "MyE的无参数构造函数" << endl;
	}
	MyE(const MyE & obj) :abcd_1(7, 8, 9), abcd_2(10, 11, 12), m(100) {
		cout << "MyE的拷贝构造函数" << endl;
	}
	~MyE() {
		cout << "~MyE()" << endl;
	}

public:
	//构造与析构只与定义顺序有关，与初始化列表顺序无关！！
	ABCD abcd_2; //C++编译器不知道如何构造，需要初始化列表
	ABCD abcd_1;
	const int m; //存在const修饰变量的时候一定要初始化列表
};

// doThing(MyE my1)作用：在MyE类中调用ABCD类中的getA()方法
int doThing(MyE my1) {
	cout << "doThing_my1.abcd_1.getA():  " << my1.abcd_1.getA() << endl;
	return 0;
}

//创建一个MyE类并调用doThing函数
int run2() {
	//调用无参数构造函数
	MyE my2;
	//调用拷贝构造函数
	doThing(my2);
	return 0;
}

int main()
{
	//分析run2的运行步骤
	run2();
	system("pause");
	return 0;
}
