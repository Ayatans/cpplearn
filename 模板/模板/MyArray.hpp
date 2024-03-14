#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template<class T>
class MyArray {
public:
	// 有参构造
	MyArray(int capacity) {
		cout << "you can gou zao" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}

	// 拷贝构造
	MyArray(const MyArray& arr) {
		cout << "kao bei gou zao" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= 防止浅拷贝问题 a=b=c 若b=c返回的是void就不能赋值给a了。
	MyArray& operator=(const MyArray& arr) {
		cout << "=" << endl;
		// 先判断原来堆区是否有数据 有就先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// 尾插法
	void PushBack(const T& val) {
		if (this->size == this->capacity) {
			return;
		}
		this->pAddress[this->size] = val;
		++this->size;
	}

	// 尾删法
	void PopBack() {
		if (this->size == 0) {
			return;
		}
		--this->size;
	}

	// 下标访问 若想通过下标对元素赋值，这里必须返回引用，否则返回的是临时变量，用完即释放，无法赋值
	T& operator[](int index) {
		return this->pAddress[index];
	}

	int getCapacity() {
		return this->capacity;
	}

	int getSize() {
		return this->size;
	}

	~MyArray() {
		if (this->pAddress != NULL) {
			cout << "xi gou" << endl;
			delete[] this->pAddress; 
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;	// 指针指向堆区开辟的真实数组
	int capacity;
	int size;
};