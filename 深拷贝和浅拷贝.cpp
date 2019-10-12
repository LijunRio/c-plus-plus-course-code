#include<iostream>
using namespace std;

class Name {
public:
	Name(const char*_p) {
		len = strlen(_p) + 1; //Ҫ���Ͻ����ַ�
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
	//����������ֹ��ı�д�������캯��ʹ�����
	//��ʾ��дһ���������캯��������C++������Ĭ�ϵĿ������캯���������ͽ����ǳ���������⡣
	//��д�������캯�����
	Name(const Name& obj1) {
		int len = obj1.len;
		p = (char*)malloc(len);
		strcpy_s(p, len, obj1.p);
	}

private:
	char *p;
	int len;//����ָ��ָ����ڴ�ռ��ж೤
};

void objplay() {
	Name obj1("abcdefg");//�ڴ��ַ
	Name obj2 = obj1;
	Name obj3("obj3");
	//��ʱ��Ҫ���صȺŲ�����
	obj3 = obj1;//�ȺŲ�����C++�Ѷ���1�����Կ����ɶ���3�����ԣ�Ҳ��ǳ����������

}

int main()
{
	objplay();
	cout << "finish!" << endl;
	system("pause");
	return 0;
}
