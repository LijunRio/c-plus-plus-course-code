#include <iostream>
using namespace std;

class Test
{
public:
	Test(int _a) {
		a = _a;
		cout << "构造函数" << endl;
	}
	~Test() {
		cout << "析构函数" << endl;
	}

private:
	int a;
};

// new和delete的基本语法
void objplay1()
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	int *p2 = new int;//分配基础类型
	*p = 20;

	int *p3 = new int(30);

	//c语言分配数组
	int *pArray_1 = (int*)malloc(sizeof(int) * 10);
	pArray_1[0] = 1;
	free(pArray_1);

	//C++分配数组
	int *pArray_2 = new int[10];
	pArray_2[1] = 2;
	delete[] pArray_2; //数组是要[]

	//分配对象
	//	new能自动的执行类型构造函数，delete能执行类的析构函数
	//	C语言
	Test *pT1 = (Test *)malloc(sizeof(Test));
	free(pT1);
	//C++
	Test *pT2 = new Test(10);
	delete pT2;
}

// malloc free 属于C语言的函,只会分配和删除内存大小，不会调用类的构造函数和析构数
// new	delete 属于C++的操作符，new和delete不光会分配内存和删除内存，还会调用构造函数和析构函数，就是会初始化对象
// 用malloc分配的内存可以用delete释放吗？ 基础类型√ 基础类型数组√ 自定义对象√
// 用new分配的内存可以用free释放吗？ 基础类型√ 基础类型数组√ 自定义对象√

void objplay2() {
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	int *p2 = new int;//分配基础类型
	*p = 20;
	int *p3 = new int(30);
}


int main()
{
	
	system("pause");
	return 0;
}