#include<iostream>
using namespace std;

class C1 //12
{
public:
	int i, j, k;//4*3=12
private:
};

class c2 //12
{
public:
	//��������ڵ�ַҲû�зŵ�����
	//������Ӧ���룬���ڴ�����
	int getK() const { return k; }
	void setK(int val) { k = val; }
private:
	int i, j, k; //���Էŵ�ջ���棬��ջ
	static int m; //û�зŵ�������
};

struct s1//12
{
	int i, j, k;
};

struct s2//12
{
	int i, j, k;
	static int m; //û�зŵ��ṹ������
};

void playobject() {
	cout << "c1: " << sizeof(C1) << endl;
	cout << "c2: " << sizeof(c2) << endl;
	cout << "s1: " << sizeof(s1) << endl;
	cout << "s2: " << sizeof(s2) << endl;
}

class Test
{
public:
	Test(int a,int b) { //Test(Test *this,int a,int b)
		this->a = a+10;
		this->b = b+10;
	}
	~Test() {
		cout << "����" << endl;
	}
	void printT() { 
		cout << "a: " << a << endl;
		cout << "this->b: " << this->b << endl;
	}
private:
	int a, b;
};


void playobject_this()
{
	Test t1(1, 2);
	t1.printT();//printT(&t1)
}

int main()
{
	playobject();
	//playobject_this();
	system("pause");
	return 0;
}
