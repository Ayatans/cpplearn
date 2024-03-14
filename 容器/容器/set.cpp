#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;

void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void buildSet(set<int>& s1) {
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(20);
}

// 构造 仅能用insert
void test33() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(20);
	printSet(s1);
	set<int> s2(s1);
	printSet(s2);
	set<int> s3;
	s3 = s2;
	printSet(s3);
}

// 大小 交换
void test34() {
	set<int> s1;
	set<int> s2;
	buildSet(s1);
	cout << s1.empty() << " " << s2.empty() << endl;
	cout << s1.size() << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

// 插入 删除 insert clear erase 
void test35() {
	set<int> s1;
	buildSet(s1);
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);
	s1.erase(s1.begin(), s1.end());
	printSet(s1);
	s1.clear();
}

// 查找 统计
void test36() {
	set<int> s1;
	buildSet(s1);
	set<int>::iterator it = s1.find(20);
	// 如果找到，返回该位置；找不到，返回s.end()
	cout << *it << endl;
	set<int>::iterator t = s1.find(35);
	// 不能读取end处的值来输出！！
	if (t==s1.end()){
		cout << " not found " << endl;
	}
	cout << s1.count(10) << endl;
	cout << s1.count(25) << endl;
}

// multiset
void test37() {
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(35);
	if (ret.second) {
		cout << "insert success" << endl;
	}
	else {
		cout << "insert fail" << endl;
	}
	pair<set<int>::iterator, bool> ret1 = s.insert(35);
	if (ret1.second) {
		cout << "insert success" << endl;
	}
	else {
		cout << "insert fail" << endl;
	}
	multiset<int> m;
	m.insert(10);
	m.insert(10);
	m.insert(10);
	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << *it << endl;
	}
}

// 排序
class MyCompare {
public:
	bool operator()( int a,  int b) const {	
		return a > b;
	}
};

void buildSetMyCompare(set<int, MyCompare>& s1) {
	s1.insert(10);
	s1.insert(30);
	s1.insert(50);
	s1.insert(20);
}

void test39() {
	set<int, MyCompare> s1;
	buildSetMyCompare(s1);
	// 用仿函数可以改变排序规则
	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << endl;
	}
}

// 自定义数据类型排序规则
class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

// 自定义数据类型存set 必须要写仿函数
class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const {	// 两个地方都要加const
		return p1.age > p2.age;
	}
};

void test40() {
	set<Person, comparePerson> s;
	Person p1("a", 28);
	Person p2("b", 25);
	Person p3("c", 31);
	Person p4("d", 12);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->name << " " << it->age << endl;
	}
}

int main6() {

	//test33();
	//test34();
	//test35();
	//test36();
	//test37();
	//test39();
	test40();
	

	system("pause");
	return 0;
}