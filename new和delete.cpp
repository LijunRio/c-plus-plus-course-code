#include <iostream>
using namespace std;

class Test
{
public:
	Test(int _a) {
		a = _a;
		cout << "���캯��" << endl;
	}
	~Test() {
		cout << "��������" << endl;
	}

private:
	int a;
};

// new��delete�Ļ����﷨
void objplay1()
{
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	int *p2 = new int;//�����������
	*p = 20;

	int *p3 = new int(30);

	//c���Է�������
	int *pArray_1 = (int*)malloc(sizeof(int) * 10);
	pArray_1[0] = 1;
	free(pArray_1);

	//C++��������
	int *pArray_2 = new int[10];
	pArray_2[1] = 2;
	delete[] pArray_2; //������Ҫ[]

	//�������
	//	new���Զ���ִ�����͹��캯����delete��ִ�������������
	//	C����
	Test *pT1 = (Test *)malloc(sizeof(Test));
	free(pT1);
	//C++
	Test *pT2 = new Test(10);
	delete pT2;
}

// malloc free ����C���Եĺ�,ֻ������ɾ���ڴ��С�����������Ĺ��캯����������
// new	delete ����C++�Ĳ�������new��delete���������ڴ��ɾ���ڴ棬������ù��캯�����������������ǻ��ʼ������
// ��malloc������ڴ������delete�ͷ��� �������͡� ������������� �Զ�������
// ��new������ڴ������free�ͷ��� �������͡� ������������� �Զ�������

void objplay2() {
	int *p = (int *)malloc(sizeof(int));
	*p = 10;

	int *p2 = new int;//�����������
	*p = 20;
	int *p3 = new int(30);
}


int main()
{
	
	system("pause");
	return 0;
}