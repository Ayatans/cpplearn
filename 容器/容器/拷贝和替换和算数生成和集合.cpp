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
#include<numeric>
using namespace std;

void myPrint(vector<int> v2) {
	for (auto i = v2.begin(); i != v2.end(); i += 1) {
		cout << *i << " ";
	}
	cout << endl;
}

class Greater30 {
public:
	bool operator()(int val) {
		return val >= 30;
	}
};

void test55() {
	vector<int> v1;
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(30);
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	myPrint(v2);
	replace(v1.begin(), v1.end(), 20, 2200);
	myPrint(v1);
	replace_if(v1.begin(), v1.end(), Greater30(), 3000);
	myPrint(v1);
	swap(v1, v2);
	myPrint(v1);
	myPrint(v2);
	int sum1 = accumulate(v1.begin(), v1.end(), 0);
	cout << sum1 << endl;
	vector<int> v3;
	v3.resize(10);
	fill(v3.begin(), v3.end(), 20);
	myPrint(v3);
	vector<int> v4;
	v4.resize(min(v1.size(), v3.size()));
	sort(v1.begin(), v1.end());
	sort(v3.begin(), v3.end());
	vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v3.begin(), v3.end(), v4.begin());
	// 注意这里的重点迭代器不是end()
	for(auto i = v4.begin(); i != it; i += 1) {
		cout << *i << " ";
	}
	cout << endl;
	v4.resize(v1.size()+v3.size());
	it = set_union(v1.begin(), v1.end(), v3.begin(), v3.end(), v4.begin());
	for (auto i = v4.begin(); i != it; i += 1) {
		cout << *i << " ";
	}
	cout << endl;
	v4.resize(max(v1.size(), v3.size()));
	it = set_difference(v1.begin(), v1.end(), v3.begin(), v3.end(), v4.begin());
	for (auto i = v4.begin(); i != it; i += 1) {
		cout << *i << " ";
	}
	cout << endl;
}


void test56() {
	const int n = 9;
	int a[n];



}

int main() {
	/*test55();
	test56();*/
	 int a = 10;
	int* b = (int*)&a;
	*b = 20;
	std::cout << a << endl << *b << endl << &a << endl << b << endl;
	return 0;

	system("pause");
	return 0;
}