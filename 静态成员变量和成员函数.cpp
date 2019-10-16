#include <iostream>
using namespace std;

class Test
{
public:
	int addC() { c++; };
	void printC() { cout << "c: " << c << endl; }
	//静态成员函数
	//在静态成员函数中能调用普通成员属性或者普通成员函数吗？
	//静态函数里面不能使用普通成员变量
	static int getC() { 
		return c; 
		//静态成员函数里面能使用静态成员变量
		//但是普通成员变量静态函数无法使用
		//因为编译器不知道是哪个类的变量
		//而静态成员是属于所有类的，所以可以使用
		//cout << "a: " << a << endl;
	}
private:
	int a;
	int b;
	//静态成员变量
	static int c;
};
int Test::c = 10;

void objectplay1() {
	Test t1, t2, t3;
	//c的值一改变，所有都改变
	t1.printC();
	t2.addC();
	t3.printC();
	//静态成员函数的调用方法
	t3.getC();
	Test::getC();
}

int main()
{
	system("pause");
}