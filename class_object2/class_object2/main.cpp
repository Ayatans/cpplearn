#include<iostream>
#include<string>
using namespace std;

// ���������
// ��Ա��������+
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
// ȫ�ֺ������� ������ĳ�Ա�������ض�ѡһ���ڡ�
Person operator+(Person& p1, Person& p2) {
	Person t;
	t.a = p1.a + p2.a;
	t.b = p1.b + p2.b;
	return t;
}
// ���������Ҳ���Է����������أ�������������������
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
	// ��Ա�������ʵ��õ���
	//p3 = p1.operator+(p2);
	// ȫ�ֺ������ʵ��õ���
	//p3 = operator+(p1, p2);
	p3 = p1 + p2;
	Person p4 = p1 + 233;
	cout << p3.a << "  " << p3.b << endl;
	cout << p4.a << "  " << p4.b << endl;
}

// �������������
class Person2 {
public:

	int a;
	int b;
};
ostream& operator<<(ostream &cout, Person2 &p) {
	cout << p.a << "  " << p.b << endl;
	// return cout��Ϊ����ʽ��̵�˼�룬��������cout������������Ҳ�������endl
	return cout;
}
void test2() {
	Person2 p;
	p.a = 10;
	p.b = 20;
	cout << p << endl;
}

// �������������
class myInt {
	friend ostream& operator<<(ostream& cout, myInt& i);
public:
	myInt() {
		n = 0;
	}
	// ����ǰ��++����������ﷵ��nҲ�У���֪���������ģ�
	// ����������������ã���ô�ڶ�ν���++ʱ ++(++i1)���ᵼ��
	// ���Ƕ�ͬһ���������++�������¸�����һ������
	// ����������Ϊ��ʼ�ն�һ�����ݽ���++
	myInt& operator++() {
		n++;
		return *this;
	}
	// ���غ���++����� ������Ӹ�int����������֪���Ǻ������������ 
	// int����ռλ����������++���ص���ֵ����Ϊ���ܷ��ؾֲ����������
	// ���ǰ��++ -- �Ⱥ���Ҫ�죡
	// ע�⣬(a++)++����ʲô�������Ͷ�����ʵ��
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
	// ������Ϊi2++���صĲ������ö���ֵ�����Բ���ֱ���������
	// �������أ�Ҫ�ѵڶ���������ֵ����ʽ����
	cout << i2 << endl;
}

// ��ֵ���������
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
	// �������ò��Ƿ��������������������з��ر�֤������ʽ��ֵ
	Person3& operator=(Person3 &p) {	
		// ���ж��Ƿ��������ڶ�������������ͷŸɾ�
		if (age != NULL) {
			delete age;
			age = NULL;
		}
		age = new int(*p.age); // ���
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

// ��ϵ���������
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

// �����������������
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
	// ������������ myAdd() ����+() ��ǰ��ִ���������ͷ�
	cout << myAdd()(10, 5) << endl;
}

int main() {
	// ���������
	// ��Ա��������+
	// test1();

	// �������������
	// test2();

	// �������������
	// test3();

	// ��ֵ���������
	//test4();

	// ��ϵ���������
	//test5();
	
	// �����������������
	test6();
}