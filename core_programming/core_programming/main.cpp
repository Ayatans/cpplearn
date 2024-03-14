#include<iostream>
#include<string>
using namespace std;
// 不要返回局部变量的地址，后续会错乱
int* func() {
	int a = 20;
	return &a;
}
// new一个int，将数据开辟到堆区
int* func1() {
	
	// 虽然指针本质也是局部变量，但指针保存的内存地址是在堆区的
	int *p=new int(10);
	return p;
}
// new创建数组
void newArr() {
	
	int * arr=new int[10];
	for (int i = 0; i < 10; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) cout << arr[i] << endl;
	delete[] arr;
}
// 引用做函数参数，用形参修饰实参，这里的形参是传入的变量的别名。等效于地址传递
void swap1(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
// 引用作函数返回值，这里加个&
int& test1() {
	static int a = 10;
	return a;
}
// 引用的本质是指针常量
void func2(int &ref) {
	ref = 100;
}
// 常量引用
void func3(const int& v) {
	// v += 10;
	cout << v << endl;
}

// 函数重载
void func4() {
	cout << "aababcc" << endl;
}

void func4(int a) {
	cout << a << endl;
}

void func4(int a, double b) {
	cout << a << '\t' << b << endl;
}

void func4(double a, int b) {
	cout << a << '\t' << b << endl;
}
// 引用作为函数重载的条件
void func5(int& a) {
	cout << "int &a" << endl;
}

void func5(const int& a) {
	cout << "const int& a" << endl;
}
// 函数重载碰到默认参数造成混淆，此时再传入一个int，会报错
void func6(int a) {
	cout << a << endl;
}

void func6(int a, int b = 10) {
	cout << a << endl;
}

int main() {
	// 不要返回局部变量的地址，后续会错乱
	//int* p = func();
	//cout << *p << endl; 
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;

	//// 堆区数据一直存在，如果不手动释放
	//int* p = func1();
	//cout << *p << endl;
	//// delete释放堆区内存
	//delete p;
	//// cout << *p << endl; // 报错

	// new创建数组
	// newArr();

	//// 引用
	//int a = 10;
	//int& b = a;
	//cout << a << '\t' << b << endl;
	//b = 20;
	//cout << a << '\t' << b << endl;

	//// 引用做函数参数，用形参修饰实参
	//int a = 10;
	//int b = 20;
	//swap1(a, b);
	//cout << a << '\t' << b << endl;

	//// 引用作函数返回值
	//int &ref = test1();
	//cout << ref << endl;
	//test1() = 100;
	//cout << ref << endl;

	//// 引用的本质 指针常量
	//int a = 10;
	//int& ref = a;
	//ref = 20;
	//cout << ref << endl;
	//func2(ref);
	//cout << ref << endl;

	// 常量引用
	//int a = 10;
	//func3(a);

	// 函数重载
	//func4();
	//func4(10);
	//func4(10, 3.14);
	//func4(3.14, 10);

	// 引用作为函数重载的条件
	//int a = 10;
	//func5(a);
	//func5(10);

	// 函数重载碰到默认参数造成混淆
	// func6(10);

}