#include<iostream>
using namespace std;

class Test2
{
public:
	Test2() {
		a = 0;
		b = 0;
		cout << "无参数构造函数" << endl;
	}
	Test2(int m_a, int m_b){
		a = m_a;
		b = m_b;
		cout << "有参数构造函数" << endl;
	}
	Test2(int m_a) {
		a = m_a;
		cout << "有参数构造函数" << endl;
	}
	Test2(const Test2& obj) {
		
		cout << "赋值构造函数/拷贝构造函数" << endl;
	}
	
	~Test2()//析构函数 
	{
	}
private:
	int a;
	int b;

};

//给对象搭建一个舞台，研究对象完整的生命周期
void objectplay2()
{
	Test2 t1;//调用无参数构造函数

	//调用有参数构造函数3种方法
	//第一种
	Test2 t2_1(1, 2);

	//第二种（仅适用于一个参数）
	Test2 t2_2 = 2;//C++对等号操作符进行了功能性增强
	//逗号表达式最后一个值是这个表达式的值
	Test2 t2_22 = (3, 4);//实际上调用的也是一个参数的构造函数

	//第三种 直接调用构造函数完成t3对象的初始化
	//并不等同于t3-t2_2 (这里是赋值）初始化与赋值是两个概念
	//只会调用一次构造函数！！优化了
	Test2 t3 = t2_2;//这种方法会产生一个匿名对象
	//匿名对象的生命周期非常重要

int main()
{
	system("pause");
}

