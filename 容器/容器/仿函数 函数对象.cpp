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
#include<map>
#include<functional>
using namespace std;

class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

class MyPrint {
public:
	MyPrint() {
		this->times = 0;
	}
	void operator()(string t) {
		this->times++;
		cout << t << endl;
	}
	int times;
};

// 一元谓词
class GreaterFive {
public:
	// 一元谓词
	bool operator()(int v) {
		return v > 5;
	}
};

// 二元谓词
class MyCompare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

void doprint(MyPrint& p, string t) {
	p(t);
	cout << p.times << endl;
}

void test46() {
	MyAdd m;
	cout << m(10, 20) << endl;
	MyPrint p;
	p("efji");
	p("efji");
	p("efji");
	cout << p.times << endl;
	doprint(p, "eijiji");
}

void test47() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it != v.end()) {
		cout << *it << endl;
	}
}

void test48() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), MyCompare());
	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}
}


// 内建的函数对象（仿函数）
void test49() {
	// 取相反数
	negate < int> n;
	cout << n(50) << endl;
	// 加
	plus<int> p;
	cout << p(20, 36) << endl;
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	vector<bool> v2;
	v2.resize(v1.size());	// 用transform前一定要先开空间，否则会报错
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << endl;
	}


}

int main9() {

	//test46();
	//test47();
	//test48();
	test49();


	system("pause");
	return 0;
}