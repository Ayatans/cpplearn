#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
using namespace std;

void constructDeque(deque<int>& d) {
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
}

// 只读迭代器
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// deque 构造
void test18() {
	deque<int> d1;
	constructDeque(d1);
	deque<int> d2(d1.begin() + 2, d1.end() - 2);
	printDeque(d1);
	printDeque(d2);
	deque<int> d3(10, 100);
	printDeque(d3);
	deque<int> d4(d3);
	printDeque(d4);
}

// deque 赋值
void test19() {
	deque<int> d1;
	constructDeque(d1);
	deque<int> d2 = d1;
	printDeque(d2);
	deque<int> d3;
	d3.assign(d1.begin() + 1, d1.end() - 3);
	printDeque(d3);
	deque<int> d4;
	d4.assign(10, 100);
	printDeque(d4);
}

// deque 大小 empty size resize 和vector一样的
void test20() {
	deque<int>d1;
	constructDeque(d1);
	deque<int>d2;
	cout << d1.empty() << " " << d2.empty() << endl;
	cout << d1.size() << " " << d2.size() << endl;
	d1.resize(20);
	cout << d1.size() << endl;
	printDeque(d1);
	d1.resize(5);
	cout << d1.size() << endl;
	printDeque(d1);
	d1.resize(20, 245);
	cout << d1.size() << endl;
	printDeque(d1);
}

// deque 插入和删除 push_back push_front pop_back pop_front insert clear erase
void test21() {
	deque<int> d1;
	constructDeque(d1);
	d1.push_back(10);
	d1.push_front(-1);
	printDeque(d1); 
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);
	d1.insert(d1.begin() + 2, 1000);
	printDeque(d1);
	d1.insert(d1.begin() + 2, 2, 10000);
	printDeque(d1);
	deque<int> d2;
	constructDeque(d2);
	d1.insert(d1.begin() + 5, d2.begin() + 3, d2.begin() + 6);
	printDeque(d1);
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);
	d1.erase(d1.end() - 4, d1.end());
	printDeque(d1);
	d1.clear();
}

// deque 存取 和vector一样
void test22() {
	deque<int> d1;
	constructDeque(d1);
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << " ";
		cout << d1.at(i) << " ";
	}
	cout << endl;
	cout << d1.front() << " " << d1.back() << endl;
}

// deque 排序 对支持随机访问的迭代器的容器都可以用sort
void test23() {
	deque<int> d1;
	constructDeque(d1);
	d1.push_back(3);
	d1.push_front(15);
	sort(d1.begin(), d1.end());
	printDeque(d1); 
}

int main3() {

	//test18();
	//test19();
	//test20();
	//test21();
	//test22();
	test23();

	system("pause");
	return 0;
}