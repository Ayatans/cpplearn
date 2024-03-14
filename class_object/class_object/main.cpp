#include<iostream>
#include<string>
#include"Point.h"
#include"Yuan.h"
using namespace std;

const double PI = 3.1415926;

class Circle {
	//����Ȩ�� ����Ȩ��public
public:
	int r;
	double cal_perim() {
		return 2 * PI * r;
	}
};

class Student {
public:
	string name;
	int id;
	// ����Ϊ�����Ը�ֵ 
	void setname(string s) {
		name = s;
	}
	void setid(int i) {
		id = i;
	}
	void show() {
		cout << name << '\t' << id << endl;
	}
};

// ����Ȩ��
class Person {
public:
	string name;
protected:
	string car;
private:
	int psw;
public:
	void fun() {
		cout << name << car << psw << endl;
	}
};

// �����г�Ա������Ϊ˽��
class Person1 {
private:
	string name;
	int age=18;
	string lover;
public:
	void setname(string s) {
		name = s;
	}
	string getname() {
		return name;
	}
	int getage() {
		return age;
	}
	void setage(int i) {
		if (0 > i || i > 150) {
			age = 18;
			cout << "Too much!" << endl;
			return;
		}
		else {
			age = i;
		}
	}
	void setlover(string s) {
		lover = s;
	}
	void show() {
		cout << name << endl;
		cout << age << endl;
		cout << lover << endl;
	}
};

// ��ϰ������
class Cube {
private:
	int h;
	int w;
	int l;
public:
	void seth(int a) {
		h = a;
	}
	void setl(int a) {
		l = a;
	}
	void setw(int a) {
		w = a;
	}
	int geth() {
		return h;
	}
	int getl() {
		return l;
	}
	int getw() {
		return w;
	}
	int getarea() {
		return (h * w + h * l + w * l) * 2;
	}
	int getvol() {
		return h * w * l;
	}
	bool isSameWith(Cube &c1) {
		if (c1.getl() == l && c1.geth() == h && c1.getw() == w) return true;
		else return false;
	}
};

bool isCubeSame(Cube &c1, Cube &c2) { // ���ô��ݣ���ֹ����һ�ݵ��ڴ���
	if (c1.getl() == c2.getl() && c1.getw() == c2.getw() && c1.geth() == c2.geth()) return true;
	else return false;
}

// ��ϰ ��Բ��ϵ
int pointcirclerelation(Yuan a, Point b) {
	int d = pow(a.getcenter().getx() - b.getx(), 2);
	d += pow(a.getcenter().gety() - b.gety(), 2);
	int r2 = pow(a.getr(), 2);
	if (d > r2)	return 2;
	else if (d == r2) return 1;
	else return 0;
}

//  ���캯�� ��������
class Person2 {
public:
	// ��ͨ���캯��
	Person2() {
		cout << "�޲ι��캯������" << endl;
	}

	Person2(int a) {
		age = a;
		cout << "�вι��캯������" << endl;
	}

	// �������캯��
	Person2(const Person2 &p) {
		age = p.age;
		cout << "�������캯������" << endl;
	}

	~Person2() {
		cout << "������������" << endl;
	}
private:
	int age;

};
// ���캯��3�ֵ���
void test01() {
	Person2 p;	// Ĭ�ϵ��ù��캯��
	Person2 p1(10);	// ���ŷ������вι���
	Person2 p2(p1); // ���ŷ����ÿ�������

	Person2 p3 = Person2(10);	// ��ʾ�������вι���
	Person2 p4 = Person2(p3);	// ��ʾ�����ÿ�������
	Person2(10); // �������󣬵�ǰ��ִ�н���������������ա���Ҫ�ÿ�����������ʼ��һ����������

	Person2 p5 = 10;	// ��ʽת���������вι��죬�൱�� Person2 p5=Person2(10);
	Person2 p6 = p5;	// ��ʽת�������ÿ�������
}
// �������캯����ֵ���ݸ�����ʱ�ᱻ����
void dowork(Person2 p) {}
void test2() {
	Person2 p;
	dowork(p);
}
Person2 dowork2() {
	Person2 p;
	return p;
}
void test3() {
	Person2 p = dowork2();
}

// ��ǳ����
class Person3 {
public:
	Person3() {
		cout << "�޲ι��캯������" << endl;
	}

	Person3(int a, int hei) {
		age = a;
		h = new int(hei);	// ������һ���µ�hei
		cout << "�вι��캯������" << endl;
	}

	// �������캯��
	Person3(const Person3& p) {
		age = p.age;
		h = new int (*p.h);	// ���
		cout << "�������캯������" << endl;
	}

	~Person3() {
		// ���������ٵ����ݽ����ͷ�
		if (h != NULL) {
			delete h;
			h = NULL;
		}
		cout << "������������" << endl;
	}
	int age;
	int* h;
};
void test4() {
	Person3 p1(16, 160);
	cout << p1.age << *p1.h << p1.h << endl;
	Person3 p2(p1);
	cout << p2.age << *p2.h << p2.h << endl;
}

// ��ʼ���б�
class Person4 {
public:
	int a;
	int b;
	int c;
	// �����ĳ�ʼ���б�
	//Person4() : a(10), b(20), c(30) {
	//	cout << "" << endl;
	//}
	// �����вι��촴���ĳ�ʼ���б�
	Person4(int a, int b, int c) : a(a), b(b), c(c) {

	}
};
void test5() {
	Person4 p1(10,20,40);
	cout << p1.a << endl;
	cout << p1.b << endl;
	cout << p1.c << endl;
}

// ������Ϊ������ĳ�Ա
class A {
public:
	A(int a) {
		aa = a;
		cout << "constrct A" << endl;
	}
	~A() {
		cout << "destroy A" << endl;
	}
	int aa;
};
class B {
public:
	B(int tx, int ta):x(tx), a1(ta) {
		cout << "constrct B" << endl;
	}
	~B() {
		cout << "destroy B" << endl;
	}
	A a1;
	int x;
};
void test6() {
	B b1(10, 5);
	cout << b1.x << '\t' << b1.a1.aa << endl;
}

// ��̬��Ա����
class Person5 {
public:
	static int age;	// ��������
private:
	static int psw; 
};
int Person5::age = 19;	// �����ʼ��
int Person5::psw = 1998;	// �����ʼ�� �����ɷ���
void test7() {
	Person5 p1;
	cout << p1.age << endl;
	Person5 p2;
	p2.age = 200;
	cout << p1.age << endl;
	cout << p2.age << endl; // ����ͬһ������
	cout << Person5::age << endl; // ͨ���������ʾ�̬��Ա����
}

// ��̬��Ա���� 
class Person6 {
public:
	static void func() {
		age = 18;
		cout << "diaoyong func" << endl;
	}
	static int age;

};
int Person6::age = 100;
void test8() {
	// 2�ֵ��÷�ʽ
	Person6 p;
	cout << p.age << endl;
	p.func();
	Person6::func();
	cout << p.age << endl;
	
}

// ��Ա�����ͳ�Ա�����ֿ��洢
class Person7 {
	int age;	// �Ǿ�̬��Ա������������Ķ�����
	static int h;	// ��̬��Ա������������Ķ�����
	void func(){ }	// �Ǿ�̬��Ա������������Ķ�����
	static void func2(){ }	// ��̬��Ա������������Ķ�����
};
int Person7::h = 180;
void test9() {
	Person7 p;
	cout << sizeof(p) << endl;
}

// thisָ��
class Person8 {
public:
	int age;
	Person8 (int age) {
		this->age = age;
	}
	Person8& addage(Person8 p) {
		this->age += p.age;
		// thisΪָ������ָ�룬��*this���Ǳ��塣��ϣ���ܽ��յ�ָ��ͬһ��p2��ָ�룬���Է��ر���Ҫ�����÷�ʽ����
		// ����������õķ�ʽ���أ��൱�ڷ�����p2��ͬ����һ���ڴ洦��Person��ֻ��age����20������ô�����ļ����������p2��û�й�ϵ��
		// �����ֵ��ʽ���أ���Person8 ����ô�ᴴ��һ���µĶ��󷵻أ����ÿ������캯�������÷�ʽ���ض��󲻻ᴴ���¶���
		return *this;
	}
};
void test10() {
	Person8 p(18);
	cout << p.age << endl;
	Person8 p1(10);
	Person8 p2(20);
	// ��ʽ���˼��
	p2.addage(p1).addage(p1).addage(p1);
	cout << p2.age << endl;
}

// ��ָ����ó�Ա����
class Person9 {
public:
	void showclassname() {
		cout << "this is Person9" << endl;
	}

	void showage() {
		// ����ÿ�ε���ʱ��ʵ��this->age������ָ��û��ʵ�壬
		// ����һ����Ƶ����ó�Ա�����ͻᱨ�����Կ����ж���
		if (this == NULL) {
			return;
		}
		cout << age << endl;
	}

	int age;
};
void test11() {
	Person9* p = NULL;
	p->showclassname();
	p->showage();
}

// ������ ������
class Person10 {
public:
	int m_age;
	mutable int m_h;
	void show() const {
		// �ں�����Ӹ�const���Ͳ����������޸���ͨ��Ա�����ˡ�
		// m_age = 100; 
		// �������޸�mutable�ĳ�Ա����
		m_h = 180;
		cout << m_h << endl;
	}
	void func() {
		cout << m_age << m_h << endl;
	}
};
void test12() {
	Person10 p;
	p.show();
	const Person10 p2;	// ������
	// ������Ҳ���ܸ���ͨ��Ա���ԣ������Ը�mutable�� 
	// p2.m_age = 18;
	p2.m_h = 190;
	p2.show();
	// ������ֻ�ܵ��ó�����
	//p2.func();
}

// ��Ԫ
// ȫ�ֺ�������Ԫ
class Building {
	// ����ȫ�ֺ���Ϊ��Ԫ
	friend void goodfriend(Building* b);
public:
	Building() {
		livingroom = "keting";
		bedroom = "woshi";
	}
	string livingroom;
private:
	string bedroom;

};
void goodfriend(Building* b) {
	cout << b->livingroom << endl;
	cout << b->bedroom << endl;
}
void test13() {
	Building b;
	goodfriend(&b);
}
// ������Ԫ
class Building2;
class Youyuan {
public:
	Youyuan();
	void visit();

	Building2* building;
};
class Building2 {
	// �����Ϊ��Ԫ
	friend class Youyuan;
public:
	Building2();
	string livingroom;
private:
	string bedroom;
};
// ����д���ڵĳ�Ա����
Building2::Building2() {
	livingroom = "keting";
	bedroom = "woshi";
}
Youyuan::Youyuan() {
	building = new Building2;
}
void Youyuan::visit() {
	cout << "visiting " << building->livingroom << endl;
	cout << "visiting " << building->bedroom << endl;
}
void test14() {
	Youyuan y1;
	y1.visit();
}
// ��Ա��������Ԫ
class Building3;
class Youyuan2 {
public:
	Youyuan2();
	void visit();	// ���Է���private
	void visit2();	// �����Է���private

	Building3* building;
};
class Building3 {
	friend void Youyuan2::visit();
public:
	Building3();
	string livingroom;
private:
	string bedroom;
};
Building3::Building3() {
	livingroom = "keting";
	bedroom = "woshi";
}
Youyuan2::Youyuan2() {
	building = new Building3;
}
void Youyuan2::visit() {
	cout << "visiting " << building->livingroom << endl;
	cout << "visiting " << building->bedroom << endl;
}
void Youyuan2::visit2() {
	cout << "visiting " << building->livingroom << endl;
	//cout << "visiting " << building->bedroom << endl;
}
void test15() {
	Youyuan2 yy;
	yy.visit();
	yy.visit2();
}

int main() {
	//Circle c1; // ʵ������ͨ��һ��������������
	//c1.r = 10;
	//cout << c1.cal_perim() << endl;

	//Student s1;
	//s1.setid(1001);
	//s1.setname("John");
	//s1.show();

	// ����Ȩ��
	//Person p1;
	//p1.name = 'john';
	//// p1.car='benz'; // �޷�����
	//// p1.psw=123456;
	
	// �����г�Ա������Ϊ˽��
	//Person1 p2;
	//p2.setname("John");
	//cout << p2.getname() << endl;
	//p2.setage(23);
	//cout << p2.getage() << endl;
	//p2.setlover("Judy");
	//p2.show();

	// ��ϰ������
	//Cube c2;
	//c2.seth(10);
	//c2.setl(10);
	//c2.setw(10);
	//cout << "area:  " << c2.getarea() << endl;
	//cout << "volume:  " << c2.getvol() << endl;
	//Cube c3;
	//c3.seth(10);
	//c3.setl(10);
	//c3.setw(10);

	//cout << isCubeSame(c2, c3) << endl;
	//cout << c2.isSameWith(c3) << endl;

	// ��ϰ��Բ��ϵ
	//Yuan c4;
	//c4.setr(10);
	//Point center;
	//center.setx(10);
	//center.sety(0);
	//c4.setcenter(center);

	//Point p;
	//p.setx(10);
	//p.sety(11);
	//int rela = pointcirclerelation(c4, p);
	//cout << rela << endl;

	////  ���캯�� ��������
	//Person2 p1;	// ��������ʱ�͵��ù��캯�����ֲ�������ջ��������������ͷţ������������������

	// ���캯�����ͺ͵���
	//test01();

	//test2();
	//test3();

	// ��ǳ����
	//test4();

	// ��ʼ���б�
	//test5();

	// �����Ա
	//test6();

	// ��̬��Ա����
	//test7();

	// ��̬��Ա����
	//test8();

	// ��Ա�����ͳ�Ա�����ֿ��洢
	//test9();

	// thisָ��
	//test10();

	// ��ָ����ó�Ա����
	//test11();

	//������ ������
	//test12();

	// ȫ�ֺ�������Ԫ
	// test13();

	// ������Ԫ
	// test14();

	// ��Ա��������Ԫ
	test15();
	
	system("pause");
	return 0;
}