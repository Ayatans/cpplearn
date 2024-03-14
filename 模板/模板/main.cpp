#include<iostream>
#include<string>
using namespace std;
//#include"person.hpp"	// 类模板成员函数分文件实现
#include"MyArray.hpp"

// 函数模板
// 实现两个整型/浮点型交换的函数，除了针对整型和浮点型甚至未来的其他类型
// 分别写一个函数外，可用函数模板
template<typename T>	// 声明一个模板告诉编译器后面代码中紧跟着的T不要报错，T为通用数据类型
void myswap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}
void test1() {
	int a = 20;
	int b = 10;
	// 两种方法用函数模板
	// 1 自动类型推导
	myswap(a, b);
	// 2 显示指定类型
	myswap<int>(a, b);
	cout << a << b << endl;
}

// 函数模板案例：封装一个排序函数，对不同数据类型的数组从大到小选择排序，char，int数组
template<class T>
void mysort(T arr[], int len) {
	for (int i = 0; i < len; ++i) {
		int max = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			myswap(arr[i], arr[max]);
		}
	}
}

template<class T>
void printarr(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void test2() {
	char a1[] = "badcfe";
	int b1[] = { 3,1,4,7,2,5 };
	int lena1 = sizeof(a1)/sizeof(char);
	int lenb1 = sizeof(b1) / sizeof(int);
	mysort(a1,lena1);
	printarr(a1, lena1);
	mysort(b1, lenb1);
	printarr(b1, lenb1);
}

class Person {
public:
	Person(string n, int a) {
		this->name = n;
		this->age = a;
	}
	string name;
	int age;
};

template<class T>
bool mycompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

// 利用具体化的Person实现，可以优先调用
template<> bool mycompare(Person& p1, Person& p2) {
	if (p1.name == p2.name && p1.age==p2.age) {
		return true;
	}
	else {
		return false;
	}
}

void test3() {
	Person p1("john", 10);
	Person p2("Tom", 20);
	bool ret = mycompare(p1, p2);
	if (ret) {
		cout << "same" << endl;
	}
	else {
		cout << "diff" << endl;
	}
	
}

// 类模板
template<class nametype, typename agetype>
class Ren {
public:
	Ren(nametype n, agetype a) {
		this->name = n;
		this->age = a;
	}
	nametype name;
	agetype age;
};

void test4() {
	Ren<string, int> p1("Tom", 10);
	Ren<string, int> p2("John", 20);
	cout << p1.name << ' ' << p1.age << endl;
}

// 类模板对象做函数参数
template<class T1, class T2>
class Person2 {
public:
	Person2(T1 n, T2 a) {
		this->name = n;
		this->age = a;
	}

	void showP2() {
		cout << this->name << ' ' << this->age << endl;
	}
	T1 name;
	T2 age;
};
// 1 指定传入类型
void print1(Person2<string, int>& p) {	// 注意是引用传递
	p.showP2();
}

void test5() {
	Person2<string, int> p1("John", 100);
	print1(p1);

}

// 2 参数模板化
template<class T1, class T2>
void print2(Person2<T1, T2>& p) {
	p.showP2();
	cout << typeid(T1).name() << " " << typeid(T2).name() << endl;
}

void test6() {
	Person2<string, int> p1("John", 100);
	print2(p1);
}


// 3 整个类模板化
template<class T>
void print3(T &p) {
	p.showP2();
	cout << typeid(T).name() << endl;
}

void test7() {
	Person2<string, int> p1("John", 100);
	print3(p1);
}

// 类模板与继承
template<class T>
class Base {
public:
	T m;
};
class Son1 :public Base<int> {

};
template<class T1, class T2>
class Son2 :public Base<T1> {
public:
	T2 o;
};
void test8() {
	Son2<int ,string> s;
	s.o = "ste";
	s.m = 35;
	cout << s.o << " " << s.m << endl;

}


// 类模板成员函数的类外实现
template<class T1, class T2>
class Person3 {
public:
	Person3(T1 name, T2 age);
	void showPerson3();
	T1 names;
	T2 ages;
};
// 构造函数的类外实现
template<class T1, class T2>
Person3<T1, T2>::Person3(T1 name, T2 age) {
	this->names = name;
	this->ages = age;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person3<T1, T2>::showPerson3() {
	cout << this->names << " " << this->ages << endl;
}
void test9() {
	Person3<string, int> s("tom", 29);
	s.showPerson3();
}

// 类模板分文件编写 见开头头文件

// 类模板与友元
// 通过全局函数打印Person4信息

// 类外实现需要先让编译器知道这个函数
template<class T1, class T2>
class Person4;

template<class T1, class T2>
void showP4out(Person4<T1, T2> p) {
	cout << p.name << " " << p.age << endl;
}

template<class T1, class T2>
class Person4 {
	// 全局函数 类内实现 （有friend是全局函数，否则默认是private成员函数）
	friend void showP4(Person4<T1, T2> p) {
		cout << p.name << " " << p.age << endl;
	}
	// 全局函数 类外实现 类内先声明，加一个空模板的参数列表，并在前面先声明；或者这里声明时加template<class T1, class T2>
	//template<class T1, class T2>
	friend void showP4out<>(Person4<T1, T2> p);
public:
	Person4(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};

void test10() {
	Person4<string, int> p("tom", 18);
	showP4(p);
	showP4out(p);
}


// 案例：实现一个通用的数组类
//可以对内置数据类型以及自定义数据类型的数据进行存储
//将数组中的数据存储到堆区
//构造函数中可以传入数组的容量
//提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
//提供尾插法和尾删法对数组中的数据进行增加和删除
//可以通过下示的方式访问数组中的元素
//可以获取数组中当前元素个数和数组的容量

class P5 {
public:
	// 用户提供有参构造后编译器不会提供默认无参构造，不写的话会报错
	P5() {};
	P5(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test11() {
	MyArray <int>arr1(5);
	MyArray <int>arr2(arr1);
	MyArray <int>arr3(100);
	arr3 = arr1;
	for (int i = 0; i < 5; i++) {
		arr1.PushBack(i);

	}
	for (int i = 0; i < arr1.getSize(); i++) {
		cout << arr1[i] << endl;
	}
	cout << "size:" << arr1.getSize() << endl;
	cout << "capacity:" << arr1.getCapacity() << endl;
	arr1.PopBack();
	cout << "size:" << arr1.getSize() << endl;
	cout << "capacity:" << arr1.getCapacity() << endl;

	MyArray<P5> arr(10);
	P5 p1("a", 18);
	P5 p2("b", 14);
	P5 p3("c", 13);
	P5 p4("d", 15);
	P5 p5("e", 16);
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i].name << ' ' << arr[i].age << endl;
	}
	cout << "size:" << arr.getSize() << endl;
	cout << "capacity:" << arr.getCapacity() << endl;
}


int main() {
	//test1();
	//test2(); 
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8(); 
	//test9();
	//test10();
	test11();

	system("pause");
	return 0;
}