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


void test54() {
	vector<int> v;
	v.push_back(20);
	v.push_back(50);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	sort(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end(); i += 1) {
		cout << *i << " ";
	}
	vector<int> v2(v);
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());
	for (auto i = v.begin(); i != v.end(); i += 1) {
		cout << *i << " ";
	}
	cout << endl;
	random_shuffle(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end(); i += 1) {
		cout << *i << " ";
	}
	cout << endl;

	//vector<int> v3;
	//// 必须先开内存！
	//v3.resize(v.size() + v2.size()); 
	//merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	//for (auto i = v3.begin(); i != v3.end(); i += 1) {
	//	cout << *i << " ";
	//}

	reverse(v2.begin(), v2.end());
	for (auto i = v2.begin(); i != v2.end(); i += 1) {
		cout << *i << " ";
	}
	cout << endl;
}

int main12() {
	test54();



	system("pause");
	return 0;
}