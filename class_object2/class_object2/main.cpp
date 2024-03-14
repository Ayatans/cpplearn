#include<iostream>
#include<string>
using namespace std;

// 运算符重载
// 成员函数重载+
class Person {
public:
	int a;
	int b;
	//Person operator+ (Person &p) {
	//	Person t;
	//	t.a = this->a + p.a;
	//	t.b = this->b + p.b;
	//	return t;
	//}
};
// 全局函数重载 和上面的成员函数重载二选一存在。
Person operator+(Person& p1, Person& p2) {
	Person t;
	t.a = p1.a + p2.a;
	t.b = p1.b + p2.b;
	return t;
}
// 运算符重载也可以发生函数重载，适配其他的数据类型
Person operator+(Person& p1, int n) {
	Person t;
	t.a = p1.a + n;
	t.b = p1.b + n;
	return t;
}
void test1() {
	Person p1,p2,p3;
	p1.a = 10;
	p1.b = 20;
	p2.a = 15;
	p2.b = 25;
	// 成员函数本质调用的是
	//p3 = p1.operator+(p2);
	// 全局函数本质调用的是
	//p3 = operator+(p1, p2);
	p3 = p1 + p2;
	Person p4 = p1 + 233;
	cout << p3.a << "  " << p3.b << endl;
	cout << p4.a << "  " << p4.b << endl;
}

// 左移运算符重载
class Person2 {
public:

	int a;
	int b;
};
ostream& operator<<(ostream &cout, Person2 &p) {
	cout << p.a << "  " << p.b << endl;
	// return cout是为了链式编程的思想，否则下面cout不能输出多个，也不能输出endl
	return cout;
}
void test2() {
	Person2 p;
	p.a = 10;
	p.b = 20;
	cout << p << endl;
}

// 递增运算符重载
class myInt {
	friend ostream& operator<<(ostream& cout, myInt& i);
public:
	myInt() {
		n = 0;
	}
	// 重载前置++运算符，这里返回n也行，不知道区别在哪？
	// 这里如果不返回引用，那么在多次进行++时 ++(++i1)，会导致
	// 不是对同一个对象进行++，而是新复制了一个对象。
	// 返回引用是为了始终对一个数据进行++
	myInt& operator++() {
		n++;
		return *this;
	}
	// 重载后置++运算符 传参里加个int，编译器就知道是后置运算符重载 
	// int代表占位参数。后置++返回的是值，因为不能返回局部对象的引用
	// 因此前置++ -- 比后置要快！
	// 注意，(a++)++不管什么数据类型都不能实现
	myInt operator++(int) {
		myInt t = *this;
		n++;
		return t;
	}
private:
	int n;
};
ostream& operator<<(ostream& cout, myInt& i) {
	cout << i.n;
	return cout;
}
void test3() {
	myInt i1;
	cout << ++(++i1) << endl;
	cout << i1 << endl;
	myInt i2;
	i2++;
	// 这里因为i2++返回的不是引用而是值，所以不能直接用上面的
	// 左移重载，要把第二个参数以值的形式传递
	cout << i2 << endl;
}

// 赋值运算符重载
class Person3 {
public:
	Person3(int age) {
		this->age = new int(age);
	}
	~Person3() {
		if (age != NULL) {
			delete age;
			cout << "delete done" << endl;
		}
	}
	int* age;
	// 返回引用才是返回了真正的自身。函数有返回保证可以链式赋值
	Person3& operator=(Person3 &p) {	
		// 先判断是否有属性在堆区，如果有先释放干净
		if (age != NULL) {
			delete age;
			age = NULL;
		}
		age = new int(*p.age); // 深拷贝
		return *this;
	}
};
void test4() {
	Person3 p1(18);
	Person3 p2(20), p3(30);
	p3 = p2 = p1;

	cout << *p1.age << endl;
	cout << *p2.age << endl;
	cout << *p3.age << endl;
}

// 关系运算符重载
class Person4 {
public:
	Person4(string s, int a) {
		name = s;
		age = a;
	}
	bool operator==(Person4& p) {
		if (name == p.name && age == p.age) return true;
		else return false;
	}

	string name;
	int age;
};
void test5() {
	Person4 p1("john", 18), p2("john", 18);
	bool r = p1 == p2;
	cout << r << endl;
}

// 函数调用运算符重载
class myPrint {
public:
	void operator()(string test) {
		cout << test << endl;
	}
};
class myAdd {
public:
	int operator()(int n1,int n2) {
		return n1 + n2;
	}
};
void test6() {
	myPrint m1;
	m1("hello");
	myAdd m2;
	int c = m2(3, 4);
	cout << c << endl;
	// 匿名函数对象 myAdd() 类名+() 当前行执行完立即释放
	cout << myAdd()(10, 5) << endl;
}

int main() {
	// 运算符重载
	// 成员函数重载+
	// test1();

	// 左移运算符重载
	// test2();

	// 递增运算符重载
	// test3();

	// 赋值运算符重载
	//test4();

	// 关系运算符重载
	//test5();
	
	// 函数调用运算符重载
	test6();
}