#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<list>
using namespace std;

void printList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void buildList(list<int>& l) {
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
}

// 创建
void test26() {
	list<int> l1;
	buildList(l1);
	list<int> l2(l1.begin(), l1.end());
	printList(l2);
	list<int> l3(l2);
	printList(l3);
	list<int> l4(10, 256);
	printList(l4);
}

// 赋值 交换 assign = swap
void test27() {
	list<int> l1;
	buildList(l1);
	list<int> l2 = l1;
	printList(l2);
	list<int> l3;
	l3.assign(l2.begin(), l2.end());
	printList(l3);
	list<int> l4;
	l4.assign(10, 100);
	printList(l4);

	l1.swap(l4);
	printList(l1);
	printList(l4);
}

// 大小 size empty resize
void test28() {
	list<int> l1;
	buildList(l1);
	list<int> l2;
	cout << l1.empty() << " " << l2.empty() << endl;
	cout << l1.size() << endl;
	l1.resize(20);
	cout << l1.size() << endl;
	printList(l1);
	l1.resize(5);
	cout << l1.size() << endl;
	printList(l1);
	l1.resize(15, 36);
	printList(l1);
}

// 插入 删除 pushback popback pushfront popfront insert clear erase remove(删除所有和elem匹配的元素)
void test29() {
	list<int> l1;
	buildList(l1);
	l1.push_back(20);
	l1.push_front(17);
	printList(l1);
	l1.pop_back();
	l1.pop_front();
	printList(l1);
	list<int>::iterator it = l1.begin();
	l1.insert(++it, 1000);
	printList(l1);

	it = l1.begin();
	l1.erase(it);
	printList(l1);
	l1.push_back(5);
	printList(l1);
	l1.remove(5);
	printList(l1);
	l1.clear();
}

// 数据存取 front back 不能用[i]
void test30() {
	list<int> l1;
	buildList(l1);
	cout << l1.front() << endl;
	cout << l1.back() << endl;
}

// 反转 排序 reverse sort
bool comp(int v1, int v2) {
	return v1 > v2;
}

void test31() {
	list<int> l1;
	buildList(l1);
	l1.reverse();
	printList(l1);
	l1.push_back(7);
	l1.push_front(5);
	l1.sort();	// 不支持随机访问迭代器的容器，不可以用algorithm下的sort！
	printList(l1);
	l1.sort(comp);
	printList(l1);
}

// 自定义类型排序案例
class Person {
public:
	Person(string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}
	string name;
	int age;
	int height;
};

bool compa(Person& p1, Person& p2) {
	if (p1.age == p2.age) {
		return p1.height < p2.height;
	}
	return p1.age < p2.age;
}

void test32() {
	list<Person> l;
	Person p1("a", 1, 2);
	Person p2("b", 7, 8);
	Person p3("c", 5, 6);
	Person p4("d", 3, 4);
	Person p5("e", 1, 4);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.sort(compa);
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++) {
		cout << it->name << " " << it->age << " " << it->height << endl;
	}
}




int main5() {

	//test26();
	//test27();
	//test28();
	//test29();
	//test30();
	//test31();
	//test32();

	system("pause");
	return 0;
}