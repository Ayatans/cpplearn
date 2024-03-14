#pragma once
#include<iostream>
#include"Point.h"
class Yuan {
private:
	int r;
	Point center;
public:
	void setr(int a);
	int getr();
	void setcenter(Point a);
	Point getcenter();
};
