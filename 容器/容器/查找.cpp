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

class Persona {
public:
	Persona(string name, int age) {
		this->age = age;
		this->name = name;
	}
	string name;
	int age;
	// 必须重载== 否则没法对比
	bool operator==(const Persona& p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		else {
			return false;
		}
	}
};

class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

class Greater20 {
public:
	bool operator()(Persona& p) {
		return p.age > 20;
	}
};

void test52() {
	vector<int> v;
	for (int i = 0; i < 10; i++) v.push_back(i);
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "not found"<< endl;
	}
	else {
		cout << "found " << *it << endl;
	}
	vector<int>::iterator it2 = find_if(v.begin(), v.end(), GreaterFive());
	if (it2 == v.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << "found " << *it2 << endl;
	}
	vector<int>::iterator it3 = adjacent_find(v.begin(), v.end()); // 用得少
	bool a = binary_search(v.begin(), v.end(), 4);
	cout << a << endl;
	int b = count(v.begin(), v.end(), 4);
	cout << b << endl;
	int c = count_if(v.begin(), v.end(), GreaterFive());
	cout << c << endl;
}

void test53() {
	vector<Persona> v;
	Persona p1("aaa", 10);
	Persona p2("aba", 12);
	Persona p3("aca", 14);
	Persona p4("ada", 156);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Persona>::iterator it = find(v.begin(), v.end(), p2);
	if (it == v.end()) {
		cout << " not found" << endl;
	}
	else {
		cout << "found " << it->age << ' ' << it->name << endl;
	}

	vector<Persona>::iterator it2 = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end()) {
		cout << " not found" << endl;
	}
	else {
		cout << "found " << it2->age << ' ' << it2->name << endl;
	}
}


int main11() {
	test52();
	test53();
	


	system("pause");
	return 0;
}