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
// 普通函数
void fun1(int val) {
	cout << val << " ";
}
// 仿函数
class fun2 {
public:
	// 重载() 作为函数指针传入for_each时，在其内部被调用时会加小括号变成fun(val)，就可以调用这里重载后的输出方法
	void operator()(int val) {
		cout << val << " ";
	}
};
void test50() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	
	for_each(v.begin(), v.end(), fun1);
	for_each(v.begin(), v.end(), fun2()); // 必须传一个匿名函数对象进来才行
}
class fun3 {
public:
	int operator()(int val) {
		return val+100;
	}
};
void test51() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> t;
	// 不提前开辟target的空间的话会报错
	t.resize(v.size());  
	transform(v.begin(), v.end(), t.begin(), fun3());
	for_each(t.begin(), t.end(), fun1);

}
int main10() {
	//test50();
	test51();


	system("pause");
	return 0;
}