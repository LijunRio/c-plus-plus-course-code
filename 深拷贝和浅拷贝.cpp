#include<iostream>
using namespace std;

class Name {
public:
	Name(const char*_p) {
		len = strlen(_p) + 1; //要加上结束字符
		p = (char*) malloc(len);
		strcpy_s(p, len, _p);	
	}
	~Name(){
		if (p!=NULL) {
			free(p);
			p = NULL;
			len = 0;
		}
	}
	//解决方案，手工的编写拷贝构造函数使用深拷贝
	//显示的写一个拷贝构造函数，不用C++编译器默认的拷贝构造函数，这样就解决了浅拷贝的问题。
	//手写拷贝构造函数深拷贝
	Name(const Name& obj1) {
		int len = obj1.len;
		p = (char*)malloc(len);
		strcpy_s(p, len, obj1.p);
	}

private:
	char *p;
	int len;//定义指针指向的内存空间有多长
};

void objplay() {
	Name obj1("abcdefg");//内存地址
	Name obj2 = obj1;
	Name obj3("obj3");
	//此时需要重载等号操作符
	obj3 = obj1;//等号操作：C++把对象1的属性拷贝成对象3的属性（也是浅拷贝！！）

}

int main()
{
	objplay();
	cout << "finish!" << endl;
	system("pause");
	return 0;
}
