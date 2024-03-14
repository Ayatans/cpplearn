#pragma once
#include <iostream>
#include <string.h>
using namespace std;

template<class T>
class MyArray {
public:
	// �вι���
	MyArray(int capacity) {
		cout << "you can gou zao" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}

	// ��������
	MyArray(const MyArray& arr) {
		cout << "kao bei gou zao" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= ��ֹǳ�������� a=b=c ��b=c���ص���void�Ͳ��ܸ�ֵ��a�ˡ�
	MyArray& operator=(const MyArray& arr) {
		cout << "=" << endl;
		// ���ж�ԭ�������Ƿ������� �о����ͷ�
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

	// β�巨
	void PushBack(const T& val) {
		if (this->size == this->capacity) {
			return;
		}
		this->pAddress[this->size] = val;
		++this->size;
	}

	// βɾ��
	void PopBack() {
		if (this->size == 0) {
			return;
		}
		--this->size;
	}

	// �±���� ����ͨ���±��Ԫ�ظ�ֵ��������뷵�����ã����򷵻ص�����ʱ���������꼴�ͷţ��޷���ֵ
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
	T* pAddress;	// ָ��ָ��������ٵ���ʵ����
	int capacity;
	int size;
};