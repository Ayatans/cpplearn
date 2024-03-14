#include<iostream>
#include<string>
#include"Point.h"
#include"Yuan.h"
using namespace std;

const double PI = 3.1415926;

class Circle {
	//访问权限 公共权限public
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
	// 用行为给属性赋值 
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

// 访问权限
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

// 将所有成员属性设为私有
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

// 练习立方体
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

bool isCubeSame(Cube &c1, Cube &c2) { // 引用传递，防止拷贝一份到内存里
	if (c1.getl() == c2.getl() && c1.getw() == c2.getw() && c1.geth() == c2.geth()) return true;
	else return false;
}

// 练习 点圆关系
int pointcirclerelation(Yuan a, Point b) {
	int d = pow(a.getcenter().getx() - b.getx(), 2);
	d += pow(a.getcenter().gety() - b.gety(), 2);
	int r2 = pow(a.getr(), 2);
	if (d > r2)	return 2;
	else if (d == r2) return 1;
	else return 0;
}

//  构造函数 析构函数
class Person2 {
public:
	// 普通构造函数
	Person2() {
		cout << "无参构造函数调用" << endl;
	}

	Person2(int a) {
		age = a;
		cout << "有参构造函数调用" << endl;
	}

	// 拷贝构造函数
	Person2(const Person2 &p) {
		age = p.age;
		cout << "拷贝构造函数调用" << endl;
	}

	~Person2() {
		cout << "析构函数调用" << endl;
	}
private:
	int age;

};
// 构造函数3种调用
void test01() {
	Person2 p;	// 默认调用构造函数
	Person2 p1(10);	// 括号法调用有参构造
	Person2 p2(p1); // 括号法调用拷贝构造

	Person2 p3 = Person2(10);	// 显示法调用有参构造
	Person2 p4 = Person2(p3);	// 显示法调用拷贝构造
	Person2(10); // 匿名对象，当前行执行结束后会立即被回收。不要用拷贝构造来初始化一个匿名对象

	Person2 p5 = 10;	// 隐式转换法调用有参构造，相当于 Person2 p5=Person2(10);
	Person2 p6 = p5;	// 隐式转换法调用拷贝构造
}
// 拷贝构造函数在值传递给函数时会被调用
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

// 深浅拷贝
class Person3 {
public:
	Person3() {
		cout << "无参构造函数调用" << endl;
	}

	Person3(int a, int hei) {
		age = a;
		h = new int(hei);	// 堆区开一个新的hei
		cout << "有参构造函数调用" << endl;
	}

	// 拷贝构造函数
	Person3(const Person3& p) {
		age = p.age;
		h = new int (*p.h);	// 深拷贝
		cout << "拷贝构造函数调用" << endl;
	}

	~Person3() {
		// 将堆区开辟的数据进行释放
		if (h != NULL) {
			delete h;
			h = NULL;
		}
		cout << "析构函数调用" << endl;
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

// 初始化列表
class Person4 {
public:
	int a;
	int b;
	int c;
	// 定死的初始化列表
	//Person4() : a(10), b(20), c(30) {
	//	cout << "" << endl;
	//}
	// 根据有参构造创建的初始化列表
	Person4(int a, int b, int c) : a(a), b(b), c(c) {

	}
};
void test5() {
	Person4 p1(10,20,40);
	cout << p1.a << endl;
	cout << p1.b << endl;
	cout << p1.c << endl;
}

// 对象作为其他类的成员
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

// 静态成员变量
class Person5 {
public:
	static int age;	// 类内声明
private:
	static int psw; 
};
int Person5::age = 19;	// 类外初始化
int Person5::psw = 1998;	// 类外初始化 但不可访问
void test7() {
	Person5 p1;
	cout << p1.age << endl;
	Person5 p2;
	p2.age = 200;
	cout << p1.age << endl;
	cout << p2.age << endl; // 共享同一份数据
	cout << Person5::age << endl; // 通过类名访问静态成员变量
}

// 静态成员函数 
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
	// 2种调用方式
	Person6 p;
	cout << p.age << endl;
	p.func();
	Person6::func();
	cout << p.age << endl;
	
}

// 成员变量和成员函数分开存储
class Person7 {
	int age;	// 非静态成员变量是属于类的对象上
	static int h;	// 静态成员变量不属于类的对象上
	void func(){ }	// 非静态成员函数不属于类的对象上
	static void func2(){ }	// 静态成员函数不属于类的对象上
};
int Person7::h = 180;
void test9() {
	Person7 p;
	cout << sizeof(p) << endl;
}

// this指针
class Person8 {
public:
	int age;
	Person8 (int age) {
		this->age = age;
	}
	Person8& addage(Person8 p) {
		this->age += p.age;
		// this为指向对象的指针，则*this就是本体。但希望能接收到指向同一个p2的指针，所以返回本体要用引用方式返回
		// 如果不用引用的方式返回，相当于返回与p2不同的另一个内存处的Person（只是age都是20），那么后续的加年龄操作与p2就没有关系了
		// 如果以值形式返回，即Person8 ，那么会创建一个新的对象返回，利用拷贝构造函数。引用方式返回对象不会创建新对象。
		return *this;
	}
};
void test10() {
	Person8 p(18);
	cout << p.age << endl;
	Person8 p1(10);
	Person8 p2(20);
	// 链式编程思想
	p2.addage(p1).addage(p1).addage(p1);
	cout << p2.age << endl;
}

// 空指针调用成员函数
class Person9 {
public:
	void showclassname() {
		cout << "this is Person9" << endl;
	}

	void showage() {
		// 这里每次调用时其实是this->age，但空指针没有实体，
		// 所以一旦设计到调用成员变量就会报错。所以可以判断下
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

// 常函数 常对象
class Person10 {
public:
	int m_age;
	mutable int m_h;
	void show() const {
		// 在函数后加个const，就不可以用来修改普通成员变量了。
		// m_age = 100; 
		// 但可以修改mutable的成员属性
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
	const Person10 p2;	// 常对象
	// 常对象也不能改普通成员属性，但可以改mutable的 
	// p2.m_age = 18;
	p2.m_h = 190;
	p2.show();
	// 常对象只能调用常函数
	//p2.func();
}

// 友元
// 全局函数做友元
class Building {
	// 声明全局函数为友元
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
// 类作友元
class Building2;
class Youyuan {
public:
	Youyuan();
	void visit();

	Building2* building;
};
class Building2 {
	// 添加类为友元
	friend class Youyuan;
public:
	Building2();
	string livingroom;
private:
	string bedroom;
};
// 类外写类内的成员函数
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
// 成员函数作友元
class Building3;
class Youyuan2 {
public:
	Youyuan2();
	void visit();	// 可以访问private
	void visit2();	// 不可以访问private

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
	//Circle c1; // 实例化，通过一个类来创建对象
	//c1.r = 10;
	//cout << c1.cal_perim() << endl;

	//Student s1;
	//s1.setid(1001);
	//s1.setname("John");
	//s1.show();

	// 访问权限
	//Person p1;
	//p1.name = 'john';
	//// p1.car='benz'; // 无法访问
	//// p1.psw=123456;
	
	// 将所有成员属性设为私有
	//Person1 p2;
	//p2.setname("John");
	//cout << p2.getname() << endl;
	//p2.setage(23);
	//cout << p2.getage() << endl;
	//p2.setlover("Judy");
	//p2.show();

	// 练习立方体
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

	// 练习点圆关系
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

	////  构造函数 析构函数
	//Person2 p1;	// 创建对象时就调用构造函数，局部变量在栈区，程序结束会释放，还会调用析构函数。

	// 构造函数类型和调用
	//test01();

	//test2();
	//test3();

	// 深浅拷贝
	//test4();

	// 初始化列表
	//test5();

	// 对象成员
	//test6();

	// 静态成员变量
	//test7();

	// 静态成员函数
	//test8();

	// 成员变量和成员函数分开存储
	//test9();

	// this指针
	//test10();

	// 空指针调用成员函数
	//test11();

	//常函数 常对象
	//test12();

	// 全局函数作友元
	// test13();

	// 类作友元
	// test14();

	// 成员函数作友元
	test15();
	
	system("pause");
	return 0;
}