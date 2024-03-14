#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>	// 标准算法头文件
using namespace std;

// string 初始化和赋值 = assign
void test4() {
	string s1;
	const char* str = "hello";
	string s2(str);
	string s3(s2);
	string s4(5, 'c');
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;

	string str1;
	string str2;
	string str3;
	string str4;
	string str5;
	string str6;
	string str7;
	str1 = "hello world";
	str2 = str1;
	str3 = 'a';
	str4.assign("c++");
	str5.assign("elphin", 4);	// 把括号里字符串的前n个字符赋值给当前字符串
	str6.assign(str5);
	str7.assign(10, 'w');
	//cout << str1 << endl; 
	//cout << str2 << endl; 
	//cout << str3 << endl; 
	//cout << str4 << endl; 
	//cout << str5 << endl; 
	//cout << str6 << endl; 
	//cout << str7 << endl; 

}

// string 拼接 + append
void test5() {
	string s1 = "me";
	string s2 = "bi";
	s1 += "good";
	s1 += 'o';
	s1 += s2;
	s1.append(" di");
	s1.append("nner", 2);
	s1.append(s2);
	s1.append(s2, 0, 1);	// 截取部分，从索引0开始，截取长度为1的切片
	cout << s1 << endl;
}

// string 查找和替换 find rfind replace
void test6() {
	string s1 = "hello world el";
	int p1 = s1.find("el");	// 返回找到的索引，找不到是-1
	cout << p1 << endl;
	int p2 = s1.rfind("el");	// 从右向左找，返回的索引还是从左往右的 
	cout << p2 << endl;

	s1.replace(1, 5, "abcd");	// 把索引1开始的5个字符替换为后面的字符串
	cout << s1 << endl;
}

// string 比较，按字符的ASCII对比，相等返回0，a>b 返回1，a<b 返回-1
void test7() {
	string s1 = "hello";
	string s2 = "world";
	string s3 = "hello";
	string s4 = "apple";
	string s5 = "bun";
	cout << s1.compare(s2) << endl;
	cout << s1.compare(s3) << endl;
	cout << s1.compare(s4) << endl;
	cout << s1.compare(s5) << endl;
}

// string 字符存取
void test8() {
	string s1 = "hello world";
	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << endl;
		cout << s1.at(i) << endl;
	}
	s1[0] = 's';
	s1.at(1) = 't';
	cout << s1 << endl;

}

// string 插入和删除
void test9() {
	string s1 = "hello world";
	s1.insert(1, "222");	// 插入位置，插入字符串或字符
	s1.insert(3, 5, 'c');	// 插入位置，插入字符个数，被插入字符
	s1.erase(10, 2);		// 从位置3开始，删除2个字符
	cout << s1 << endl;
}

// string 截取子串
void test10() {
	string s1 = "hello world";
	string s2 = s1.substr(2, 7);	// 从位置2开始，7个字符组成的字符串
	cout << s2 << endl;

	string e = "abcde@gmail.com";	// 获取email用户名
	int ind = e.find('@');
	string esub = e.substr(0, ind);
	cout << esub << endl;
}

int main2() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	test10();
	system("pause");
	return 0;
}