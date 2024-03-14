#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>	// 标准算法头文件
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
	vector<int>::iterator itBegin = v.begin();	// v.begin()是一个起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();	// v.end()是一个结束迭代器，指向容器中最后一个元素的下一个位置！！

	// 遍历应该在 [begin, end) 内
	// 遍历法1
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	// 遍历法2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	// 遍历法3 myPrint是函数指针 回调函数
	for_each(v.begin(), v.end(), myPrint);

	// 遍历法4 自动推理
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

// 存放自定义数据类型 and 指针
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

// 容器嵌套容器
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

// vector 构造函数
void test11() {
	// 默认无参构造
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	printVector(v1);

	// 区间方式构造
	vector<int> v2(v1.begin()+1, v1.end()-1);	// 将[begin+1, end-1) 的区间拿来
	printVector(v2);

	// n个element 构造
	vector<int> v3(10, 100);
	printVector(v3);

	// 拷贝构造
	vector<int> v4(v3);
	printVector(v4);

}

// vector 赋值操作 = assign
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

// vector 容量 大小 empty() capacity() size() resize(n) resize(n, elem)
void test13() {
	vector<int> v1;
	constructVector(v1);
	vector<int> v2;
	cout << v1.empty() << " " << v2.empty() << endl;
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(20);	// resize后超出原来长度，会默认用0填补
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(5);	// resize后更短，则后面的丢弃
	printVector(v1);
	// 大往小resize只会影响size，不影响capacity！容量只增不减，相当于装不下水才换更大的瓶子，但减少size没必要再换成小瓶。
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(10, 245);	// 用245补充拉长的部分
	printVector(v1);
	cout << v1.size() << " " << v1.capacity() << endl;

}

// vector 插入 删除 push_back pop_back insert erase clear
void test14() {
	vector<int> v1;
	constructVector(v1);
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	v1.insert(v1.begin(), 100);	// 在指定位置插入一个值100
	printVector(v1);
	v1.insert(v1.begin() + 3, 3, 2455);	// 在指定位置插入 3 个 2455
	printVector(v1);
	v1.erase(v1.begin()+4);
	printVector(v1);
	v1.erase(v1.begin() + 6, v1.end() - 2);
	printVector(v1);
	v1.clear();
	printVector(v1);
}

// vector 数据存取
void test15() {
	vector<int> v1;
	constructVector(v1);
	cout << v1[3] << endl;
	cout << v1.at(3) << endl;
	cout << v1.front() << endl;	// 第一个元素
	cout << v1.back() << endl;	// 最后一个元素
}

// vector 互换
void test16() {
	vector<int> v1(10, 245);
	vector<int> v2(10, 135);
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	
	// 实际用途：缩减内存空间
	// 当把vector resize更小时，其capacity不会变，浪费空间。自己对自己swap可解决
	vector<int> v3(100, 1);
	cout << v3.capacity() << endl;
	v3.resize(10);
	cout << v3.capacity() << endl;
	vector<int>(v3).swap(v3);	// vector<int>(v) 以拷贝构造创建了一个匿名对象，匿名vector容量就是10，然后和v3互换了，本行结束后匿名对象自动释放
	cout << v3.capacity() << endl;
}
 
// vector 预留空间 可减少动态扩展时的扩展次数 但预留空间没有默认值，不可访问
void test17() {
	vector<int> v1;
	v1.reserve(10000);
	// 查看动态扩展次数
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