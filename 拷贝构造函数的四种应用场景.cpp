#include<iostream>
using namespace std;

class Test3
{
public:
	Test3(int _a,int _b) {
		a = _a;
		b = _b;
		cout << "�в������캯��" << endl;
	}
	Test3(const Test3&obj) {
		a = obj.a + 100;
		b = obj.b + 100;
		cout << "�������캯��" << endl;
	}

	void print() {
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	
	~Test3()//�������� 
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


//�β���һ��Ԫ�أ���ʱ��ʼ�������һ�ο������캯��
void f(Location p) {
	cout << p.GexX() << endl;
}

//������ �ѵ�
//g��������һ��Ԫ��
//����1�������ķ���ֵ��һ��Ԫ�أ��������͵ģ������ص���һ���µ���������
    //���Ի������������Ŀ������캯����
//����2�����������ȥ����
	//��������������ʼ������һ��ͬ���͵Ķ�����ô��������ֱ��ת����������
	//�������������ֵ(=)������һ��ͬ���͵Ķ�����������ͱ�������
//������дC++����߾���Ϊ��Ҫ����һ���¶�����������
Location g() {
	Location a(4, 5);
	//���ʱ���ִ��һ�ο������캯��!
	return a; 
	//��������������һ�����캯��
}

void objectplay1()
{
	//��ֵ���캯������һ�������ʼ������һ������
	Test3 t1(1, 2);
	//��һ�ֵ��÷���
		//ע�⸳ֵ����:t2=t1 ������ÿ������캯��
		//�൱�ڸ��Ʋ������������Ϊ����������
	Test3 t2 = t1; //��t1����ʼ��t2

	//�ڶ��ֵ��÷���
	Test3 t3(t2); //���ŷ���ʼ��
}

void objectplay2() {
	Location a(1, 2);
	Location b(a);
	cout << "b�����Ѿ���ʼ�����" << endl;

	f(b);//bʵ��ȡֵ��ʼ���β�P�Ĺ��̵��л���ÿ������캯��
}

void objectplay3()
{
	//�������ˣ�����������������
	g();
}

void objectplay4()
{
	//����������ֱ�ӳ�ʼ��Ϊm
	//��ʱC++������ֱ�Ӱ�����������m����������û������ֱ�ӱ�Ϊm��û�е��ÿ������캯��
	//Location m = g(); //Ϊɶ�Ҳ���
	Location m2(1,2);
	m2 = g();//��Ϊ����������=��m2��������������

}


int main()
{
	//objectplay1();
	//objectplay2();
	objectplay4();
	system("pause");
}

