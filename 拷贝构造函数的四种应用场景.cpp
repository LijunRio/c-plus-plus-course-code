#include<iostream>
using namespace std;

class Test3
{
public:
	Test3(int _a,int _b) {
		a = _a;
		b = _b;
		cout << "有参数构造函数" << endl;
	}
	Test3(const Test3&obj) {
		a = obj.a + 100;
		b = obj.b + 100;
		cout << "拷贝构造函数" << endl;
	}

	void print() {
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	
	~Test3()//析构函数 
	{
	}
private:
	int a;
	int b;

};


class Location {
public:
	Location(int _x, int _y) {
		x = _x;
		y = _y;
	}
	Location(Location &obj) {
		x = obj.x + 10;
		y = obj.y + 10;
	}
	~Location() {
		cout << "an object destroyed." << endl;
	}
	int GexX() { return x; } int GetY() { return y; }
private:
	int x;
	int y;
};


//形参是一个元素，此时初始化会调用一次拷贝构造函数
void f(Location p) {
	cout << p.GexX() << endl;
}

//第四种 难点
//g函数返回一个元素
//结论1：函数的返回值是一个元素（复杂类型的），返回的是一个新的匿名对象
    //所以会调用匿名对象的拷贝构造函数！
//结论2：匿名对象的去和留
	//如果用匿名对象初始化宁外一个同类型的对象，那么匿名对象直接转成有名对象
	//如果用匿名对象赋值(=)给宁外一个同类型的对象，匿名对象就被析构。
//你这样写C++设计者就认为你要返回一个新对象（匿名对象）
Location g() {
	Location a(4, 5);
	//这个时候会执行一次拷贝构造函数!
	return a; 
	//紧接着他析构了一个构造函数
}

void objectplay1()
{
	//赋值构造函数：用一个对象初始化另外一个对象
	Test3 t1(1, 2);
	//第一种调用方法
		//注意赋值操作:t2=t1 不会调用拷贝构造函数
		//相当于复制操作及可以理解为操作符重载
	Test3 t2 = t1; //用t1来初始化t2

	//第二种调用方法
	Test3 t3(t2); //括号法初始化
}

void objectplay2() {
	Location a(1, 2);
	Location b(a);
	cout << "b对象已经初始化完毕" << endl;

	f(b);//b实参取值初始化形参P的过程当中会调用拷贝构造函数
}

void objectplay3()
{
	//又析构了，析构的是匿名对象
	g();
}

void objectplay4()
{
	//把匿名对象直接初始化为m
	//此时C++编译器直接把匿名对象变成m，匿名函数没被析构直接变为m，没有调用拷贝构造函数
	//Location m = g(); //为啥我不行
	Location m2(1,2);
	m2 = g();//因为匿名对象是=给m2，匿名对象被析构

}


int main()
{
	//objectplay1();
	//objectplay2();
	objectplay4();
	system("pause");
}

