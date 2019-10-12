#include <iostream>
using namespace std;

class Test
{
public:
	Test()//无参数，析构函数
	{//完成对属性的初始化工作
		a = 10;
		p = (char *)malloc(100);
		strcpy_s(p, strlen("aaaabbbb") + 1, "aaaabbbb");//注意是strlen(temp)+1
		cout << "我是析构函数，被执行了" << endl;
	}

	void print()
	{
		cout << p << endl;
		cout << a << endl;
	}

	~Test()//析构函数 
	{//这样就不会有内存泄漏
		if (p != NULL)
		{
			free(p);
		}
		cout << "我是析构函数，被调用了" << endl;
	}
private:
	int a;
	char *p;
};

//给对象搭建一个舞台，研究对象完整的生命周期
void objectplay()
{
	Test t1; //这是一个局部变量，当函数运行完毕后
	//内存将会被回收，此时执行了析构函数
	t1.print();//使用它

	Test t2;//要是定义两个对象，两个对象都会调用析构和构造函数
	//析构的时候县创建的对象后释放，构造的时候县创建的先构造
	t2.print();
}

int main()
{
	objectplay();
	system("pause");

}