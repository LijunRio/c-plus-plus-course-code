#include <iostream>
using namespace std;
class A
{
public:
	A(int _a) { 
		a = _a; 
		cout << "构造函数： " << "a " << a << endl;
	}
	~A(){
		cout << "析构函数： " << "a " << a << endl;
	}

private:
	int a;
};

class B
{
public:
	//构造函数初始化列表 解决在B类中组合了一个其他类的对象，且该类对象使用了有参数构造函数
	//根据构造函数的调用规则，写了构造函数一定要用，所以没有初始化A
	//新的语法就是构造函数的初始化列表
	B(int _b1, int _b2):a1(1),a2(2),c(0){

	}
	B(int _b1, int _b2, int m, int n) :a1(m), a2(n),c(0) {
		b1 = _b1;
		b2 = _b2;
		cout << "B的构造函数" << endl;
	}
	~B()
	{
		cout << "B的析构函数" << endl;
	}

private:
	int b1;
	int b2;
	//在B类里面包含了A的元素，但是没有机会初始化A类，没有办法分配内存空间
	A a1; 
	A a2;
	const int c; //如果类的属性里面有一个const属性，那么一定要初始化
};

//先执行被组合对象的构造函数
//如果组合对象有多个，按照定义顺序，而不是按照初始化列表的顺序
//析构函数和构造函数的调用书序相反
// 额被组合对象的构造顺序预定义顺序有关系，与初始化列表顺序没有关系
void objplay() {
	//1 参数传递
	B obj(1, 2, 3, 4);
	//2 调用顺序
	cout << "finish" << endl;
}

int main()
{
	objplay();
	system("pause");
	return 0;
}