#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>	// ��׼�㷨ͷ�ļ�
using namespace std;

void myPrint(int val) {
	cout << val << endl;
}

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void constructVector(vector<int>& v) {
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
}

void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	vector<int>::iterator itBegin = v.begin();	// v.begin()��һ����ʼ��������ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();	// v.end()��һ��������������ָ�����������һ��Ԫ�ص���һ��λ�ã���

	// ����Ӧ���� [begin, end) ��
	// ������1
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	// ������2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	// ������3 myPrint�Ǻ���ָ�� �ص�����
	for_each(v.begin(), v.end(), myPrint);

	// ������4 �Զ�����
	for (auto i : v) {
		cout << i << endl;
	}
	
	cout << v.size() << " " << v.capacity() << endl;
}

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

// ����Զ����������� and ָ��
void test2() {
	vector<Person> v;
	vector<Person*> v1;
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	v1.push_back(&p4);
	v1.push_back(&p5);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).name << " " << (*it).age << endl;
		cout << it->name << " " << it->age << endl;
	} 
	for (vector<Person*>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << (**it).name << " " << (**it).age << endl;
		cout << (*it)->name << " " << (*it)->age << endl;
	}
}

// ����Ƕ������
void test3() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++) {
			cout << (*itt) << endl;
		}
	}

}

// vector ���캯��
void test11() {
	// Ĭ���޲ι���
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	printVector(v1);

	// ���䷽ʽ����
	vector<int> v2(v1.begin()+1, v1.end()-1);	// ��[begin+1, end-1) ����������
	printVector(v2);

	// n��element ����
	vector<int> v3(10, 100);
	printVector(v3);

	// ��������
	vector<int> v4(v3);
	printVector(v4);

}

// vector ��ֵ���� = assign
void test12() {
	vector<int> v1;
	constructVector(v1);
	printVector(v1);

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin() + 1, v1.end() - 2);
	printVector(v3);

	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

// vector ���� ��С empty() capacity() size() resize(n) resize(n, elem)
void test13() {
	vector<int> v1;
	constructVector(v1);
	vector<int> v2;
	cout << v1.empty() << " " << v2.empty() << endl;
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(20);	// resize�󳬳�ԭ�����ȣ���Ĭ����0�
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(5);	// resize����̣������Ķ���
	printVector(v1);
	// ����Сresizeֻ��Ӱ��size����Ӱ��capacity������ֻ���������൱��װ����ˮ�Ż������ƿ�ӣ�������sizeû��Ҫ�ٻ���Сƿ��
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(10, 245);	// ��245���������Ĳ���
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;

}

// vector ���� ɾ�� push_back pop_back insert erase clear
void test14() {
	vector<int> v1;
	constructVector(v1);
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	v1.insert(v1.begin(), 100);	// ��ָ��λ�ò���һ��ֵ100
	printVector(v1);
	v1.insert(v1.begin() + 3, 3, 2455);	// ��ָ��λ�ò��� 3 �� 2455
	printVector(v1);
	v1.erase(v1.begin()+4);
	printVector(v1);
	v1.erase(v1.begin() + 6, v1.end() - 2);
	printVector(v1);
	v1.clear();
	printVector(v1);
}

// vector ���ݴ�ȡ
void test15() {
	vector<int> v1;
	constructVector(v1);
	cout << v1[3] << endl;
	cout << v1.at(3) << endl;
	cout << v1.front() << endl;	// ��һ��Ԫ��
	cout << v1.back() << endl;	// ���һ��Ԫ��
}

// vector ����
void test16() {
	vector<int> v1(10, 245);
	vector<int> v2(10, 135);
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	
	// ʵ����;�������ڴ�ռ�
	// ����vector resize��Сʱ����capacity����䣬�˷ѿռ䡣�Լ����Լ�swap�ɽ��
	vector<int> v3(100, 1);
	cout << v3.capacity() << endl;
	v3.resize(10);
	cout << v3.capacity() << endl;
	vector<int>(v3).swap(v3);	// vector<int>(v) �Կ������촴����һ��������������vector��������10��Ȼ���v3�����ˣ����н��������������Զ��ͷ�
	cout << v3.capacity() << endl;
}
 
// vector Ԥ���ռ� �ɼ��ٶ�̬��չʱ����չ���� ��Ԥ���ռ�û��Ĭ��ֵ�����ɷ���
void test17() {
	vector<int> v1;
	v1.reserve(10000);
	// �鿴��̬��չ����
	vector<int> v;
	int* p = NULL;
	int num = 0;
	for (int i = 0; i < 10000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	num = 0;
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}

int main1() {
	//test1();
	//test2();
	//test3();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	test17();
	system("pause");
	return 0;
}