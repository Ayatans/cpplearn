#include<iostream>
#include<string>
using namespace std;

// �̳з�ʽpublic protected private
// 
class Son1;
class Base1 {
public:
	int a;
	Base1() {
		a = 20;
	}
protected:
	int b;
private:
	int c=10;
};
class Son1 :public Base1 {
public:
	int d;
};
void test1() {
	cout << sizeof(Son1) << endl;
}

// ��̳�
class Base2 {
public:
	Base2() {
		e = 100;
		a = 40;
	}
	int e;
	int a;
};
class Son2 : public Base1, public Base2 {
public:
	int f;
	int g;
	Son2() {
		f = 300;
		g = 400;
	}
};
void test2() {
	Son2 s;
	cout << s.f << s.g << s.e << endl;
	cout << s.Base1::a << s.Base2::a << endl;	// ������ͬ������Ҫָ��������
}

// ���μ̳�
class Animal {
public:
	int age;
};
// ��̳� �Ӹ�virtual
class Sheep : virtual public Animal {

};
class Tuo : virtual	public Animal {

};
class Yangtuo : public Sheep, public Tuo {

};
void test3() {
	Yangtuo y;
	y.Sheep::age = 18;
	y.Tuo::age = 28;
	cout << y.age << endl;
}

int main() {
	//test1();
	
	//test2();

	test3();
}