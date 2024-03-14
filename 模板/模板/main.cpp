#include<iostream>
#include<string>
using namespace std;
//#include"person.hpp"	// ��ģ���Ա�������ļ�ʵ��
#include"MyArray.hpp"

// ����ģ��
// ʵ����������/�����ͽ����ĺ���������������ͺ͸���������δ������������
// �ֱ�дһ�������⣬���ú���ģ��
template<typename T>	// ����һ��ģ����߱�������������н����ŵ�T��Ҫ����TΪͨ����������
void myswap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}
void test1() {
	int a = 20;
	int b = 10;
	// ���ַ����ú���ģ��
	// 1 �Զ������Ƶ�
	myswap(a, b);
	// 2 ��ʾָ������
	myswap<int>(a, b);
	cout << a << b << endl;
}

// ����ģ�尸������װһ�����������Բ�ͬ�������͵�����Ӵ�Сѡ������char��int����
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

// ���þ��廯��Personʵ�֣��������ȵ���
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

// ��ģ��
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

// ��ģ���������������
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
// 1 ָ����������
void print1(Person2<string, int>& p) {	// ע�������ô���
	p.showP2();
}

void test5() {
	Person2<string, int> p1("John", 100);
	print1(p1);

}

// 2 ����ģ�廯
template<class T1, class T2>
void print2(Person2<T1, T2>& p) {
	p.showP2();
	cout << typeid(T1).name() << " " << typeid(T2).name() << endl;
}

void test6() {
	Person2<string, int> p1("John", 100);
	print2(p1);
}


// 3 ������ģ�廯
template<class T>
void print3(T &p) {
	p.showP2();
	cout << typeid(T).name() << endl;
}

void test7() {
	Person2<string, int> p1("John", 100);
	print3(p1);
}

// ��ģ����̳�
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


// ��ģ���Ա����������ʵ��
template<class T1, class T2>
class Person3 {
public:
	Person3(T1 name, T2 age);
	void showPerson3();
	T1 names;
	T2 ages;
};
// ���캯��������ʵ��
template<class T1, class T2>
Person3<T1, T2>::Person3(T1 name, T2 age) {
	this->names = name;
	this->ages = age;
}
// ��Ա����������ʵ��
template<class T1, class T2>
void Person3<T1, T2>::showPerson3() {
	cout << this->names << " " << this->ages << endl;
}
void test9() {
	Person3<string, int> s("tom", 29);
	s.showPerson3();
}

// ��ģ����ļ���д ����ͷͷ�ļ�

// ��ģ������Ԫ
// ͨ��ȫ�ֺ�����ӡPerson4��Ϣ

// ����ʵ����Ҫ���ñ�����֪���������
template<class T1, class T2>
class Person4;

template<class T1, class T2>
void showP4out(Person4<T1, T2> p) {
	cout << p.name << " " << p.age << endl;
}

template<class T1, class T2>
class Person4 {
	// ȫ�ֺ��� ����ʵ�� ����friend��ȫ�ֺ���������Ĭ����private��Ա������
	friend void showP4(Person4<T1, T2> p) {
		cout << p.name << " " << p.age << endl;
	}
	// ȫ�ֺ��� ����ʵ�� ��������������һ����ģ��Ĳ����б�����ǰ����������������������ʱ��template<class T1, class T2>
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


// ������ʵ��һ��ͨ�õ�������
//���Զ��������������Լ��Զ����������͵����ݽ��д洢
//�������е����ݴ洢������
//���캯���п��Դ������������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
//�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//����ͨ����ʾ�ķ�ʽ���������е�Ԫ��
//���Ի�ȡ�����е�ǰԪ�ظ��������������

class P5 {
public:
	// �û��ṩ�вι��������������ṩĬ���޲ι��죬��д�Ļ��ᱨ��
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