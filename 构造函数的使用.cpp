#include <iostream>
using namespace std;

class Test
{
public:
	Test()//�޲�������������
	{//��ɶ����Եĳ�ʼ������
		a = 10;
		p = (char *)malloc(100);
		strcpy_s(p, strlen("aaaabbbb") + 1, "aaaabbbb");//ע����strlen(temp)+1
		cout << "����������������ִ����" << endl;
	}

	void print()
	{
		cout << p << endl;
		cout << a << endl;
	}

	~Test()//�������� 
	{//�����Ͳ������ڴ�й©
		if (p != NULL)
		{
			free(p);
		}
		cout << "����������������������" << endl;
	}
private:
	int a;
	char *p;
};

//������һ����̨���о�������������������
void objectplay()
{
	Test t1; //����һ���ֲ�������������������Ϻ�
	//�ڴ潫�ᱻ���գ���ʱִ������������
	t1.print();//ʹ����

	Test t2;//Ҫ�Ƕ������������������󶼻���������͹��캯��
	//������ʱ���ش����Ķ�����ͷţ������ʱ���ش������ȹ���
	t2.print();
}

int main()
{
	objectplay();
	system("pause");

}