#pragma once
#include<iostream>
using namespace std;
// 练习点圆关系，头文件里只声明不定义
class Point {
private:
	int x;
	int y;
public:
	void setx(int a);
	void sety(int a);
	int getx();
	int gety();
};