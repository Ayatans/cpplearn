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
using namespace std;

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}

// 构造 赋值
void test41() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(2, 20)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(3, 30)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(4, 40)); // 匿名pair变量赋值
	map<int, int> m2(m1);
	printMap(m1);
	printMap(m2);
	map<int, int>m3;
	m3 = m2;
	printMap(m3);

}

// 大小 交换 size empty swap
void test42() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(2, 20)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(3, 30)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(4, 40)); // 匿名pair变量赋值
	map<int, int>m2;
	cout << m1.size() << " " << m2.size() << endl;
	cout << m1.empty() << " " << m2.empty() << endl;
	m1.swap(m2);
	printMap(m1);
	printMap(m2);
}

// 插入 删除 insert clear erase
void test43() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // 匿名pair变量赋值
	m1.insert(make_pair(2, 20));
	m1.insert(map<int, int>::value_type(3, 30)); // 不常用
	m1[4] = 40; // 不建议，通过[]读取不存在的key时，不会报错，而是会加一个键值对，value=0
	printMap(m1);
	m1.erase(m1.begin());
	m1.erase(3);	// 按key删除
	printMap(m1);
	m1.erase(m1.begin(), m1.end());
	m1.clear();
}

// 查找 统计 find存在返回迭代器，不存在返回end()
void test44() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(2, 20)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(3, 30)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(4, 40)); // 匿名pair变量赋值
	map<int, int>::iterator pos = m1.find(3);
	if (pos != m1.end()) {
		cout << (*pos).first << " " << (*pos).second << endl;
	}
	int num = m1.count(3);
	cout << num << endl;

}

// 排序
// 仿函数
class MyCompare {
public:
	bool operator()( int a, int b) const {
		return a > b;
	}
};

void test45() {
	map<int, int, MyCompare> m1;
	m1.insert(pair<int, int>(1, 10)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(2, 20)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(3, 30)); // 匿名pair变量赋值
	m1.insert(pair<int, int>(4, 40)); // 匿名pair变量赋值
	for (map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}
}
int main8() {

	//test41();
	//test42();
	//test43();
	//test44();
	test45();
	// 对unordered_map 赋值的另一种方法，与py的dict很像，test43有
	// unordered_map<int, int> m; 
	// m[12]=1;  // {(12,1)}


	system("pause");
	return 0;
}