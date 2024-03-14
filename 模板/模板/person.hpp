#pragma once
#include <iostream>
using namespace std;


template<class T1, class T2>
class Person3 {
public:
	Person3(T1 name, T2 age);
	void showPerson3();
	T1 names;
	T2 ages;
}; 
template<class T1, class T2>
Person3<T1, T2>::Person3(T1 name, T2 age) {
	this->names = name;
	this->ages = age;
}
// 成员函数的类外实现
template<class T1, class T2>
void Person3<T1, T2>::showPerson3() {
	cout << this->names << " " << this->ages << endl;
}