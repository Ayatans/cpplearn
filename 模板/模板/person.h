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