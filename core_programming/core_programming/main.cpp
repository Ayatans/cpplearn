#include<iostream>
#include<string>
using namespace std;
// ��Ҫ���ؾֲ������ĵ�ַ�����������
int* func() {
	int a = 20;
	return &a;
}
// newһ��int�������ݿ��ٵ�����
int* func1() {
	
	// ��Ȼָ�뱾��Ҳ�Ǿֲ���������ָ�뱣����ڴ��ַ���ڶ�����
	int *p=new int(10);
	return p;
}
// new��������
void newArr() {
	
	int * arr=new int[10];
	for (int i = 0; i < 10; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) cout << arr[i] << endl;
	delete[] arr;
}
// �������������������β�����ʵ�Σ�������β��Ǵ���ı����ı�������Ч�ڵ�ַ����
void swap1(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
// ��������������ֵ������Ӹ�&
int& test1() {
	static int a = 10;
	return a;
}
// ���õı�����ָ�볣��
void func2(int &ref) {
	ref = 100;
}
// ��������
void func3(const int& v) {
	// v += 10;
	cout << v << endl;
}

// ��������
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
// ������Ϊ�������ص�����
void func5(int& a) {
	cout << "int &a" << endl;
}

void func5(const int& a) {
	cout << "const int& a" << endl;
}
// ������������Ĭ�ϲ�����ɻ�������ʱ�ٴ���һ��int���ᱨ��
void func6(int a) {
	cout << a << endl;
}

void func6(int a, int b = 10) {
	cout << a << endl;
}

int main() {
	// ��Ҫ���ؾֲ������ĵ�ַ�����������
	//int* p = func();
	//cout << *p << endl; 
	//cout << *p << endl;
	//cout << *p << endl;
	//cout << *p << endl;

	//// ��������һֱ���ڣ�������ֶ��ͷ�
	//int* p = func1();
	//cout << *p << endl;
	//// delete�ͷŶ����ڴ�
	//delete p;
	//// cout << *p << endl; // ����

	// new��������
	// newArr();

	//// ����
	//int a = 10;
	//int& b = a;
	//cout << a << '\t' << b << endl;
	//b = 20;
	//cout << a << '\t' << b << endl;

	//// �������������������β�����ʵ��
	//int a = 10;
	//int b = 20;
	//swap1(a, b);
	//cout << a << '\t' << b << endl;

	//// ��������������ֵ
	//int &ref = test1();
	//cout << ref << endl;
	//test1() = 100;
	//cout << ref << endl;

	//// ���õı��� ָ�볣��
	//int a = 10;
	//int& ref = a;
	//ref = 20;
	//cout << ref << endl;
	//func2(ref);
	//cout << ref << endl;

	// ��������
	//int a = 10;
	//func3(a);

	// ��������
	//func4();
	//func4(10);
	//func4(10, 3.14);
	//func4(3.14, 10);

	// ������Ϊ�������ص�����
	//int a = 10;
	//func5(a);
	//func5(10);

	// ������������Ĭ�ϲ�����ɻ���
	// func6(10);

}