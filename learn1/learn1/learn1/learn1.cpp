#include <iostream>
#include "swap.h"
#include <cmath>
using namespace std;

# define day 7	

void swap(int *num1, int *num2) {
	int t = *num1;
	*num1 = *num2;
	*num2 = t;
}

void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}

void bubblesort(int* arr, int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			// ����д��
			if (*(arr + j) > *(arr + j + 1)) {
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
			//if (arr[j] > arr[j + 1]) {
			//	int temp = arr[j];
			//	arr[j] = arr[j + 1];
			//	arr[j + 1] = temp;
			//}
		}
	}
}



struct student {
	string name;
	int age;
	int score;
};

struct teacher {
	int id;
	struct student stu[5];	//	Ƕ��

};

struct hero {
	string name;
	int age;
	string sex;
};

void bubblehero(struct hero arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			// �ҵ�д��
			if ((arr + j)->age > (arr + j + 1)->age) {
				hero temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
			// ��Ƶд��
			if (arr[j].age > arr[j + 1].age) {
				hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void allocateAttibute(teacher arr[], int len) {
	for (int i = 0; i < len; i++) {
		arr[i].id = i;
		for (int j = 0; j < 5; j++) {
			arr[i].stu[j].age = 3 * i + 4 * j;
		}
	}
}

void printStruct(teacher arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i].id << endl;
		for (int j = 0; j < 5; j++) {
			cout << arr[i].stu[j].age<<endl;
		}
	}
}



int main() {
	//int a = 10;
	//const int month = 12;
	//cout << "hello world" << "a=" << a <<endl;
	//cout << day << " " << month << endl;

	//int a[2][3] = { 1,2,3,4,5,6 };
	//cout << a << endl;
	//cout << a[0] << endl;
	//cout << &a[0][0] << endl;
	//cout << add1(3, day) << endl;
	//swap(day, 4);

	//int a = 10;
	//int a[8] = { 3,4,5 };
	//int* pa = a;
	////cout << pa << endl;
	//for (int i = 0; i < 8; i++) {
	//	cout << *pa << endl;
	//	pa++;	// ָ��+4��ָ����һ��Ԫ�صĵ�ַ
	//}

	// ��ַ����
	//int a = 10;
	//int b = 20;
	//swap(&a, &b);
	//cout << a << b << endl;

	//int a[10] = { 4,3,6,9,1,2,10,8,7,5 };
	//int len = sizeof(a) / sizeof(a[0]);	//cpp��len��������洫������������������㲻������ĳ��ȡ�
	//bubblesort(a, len);
	//printArray(a, len);

	//student arr[3] = { {"john",18,70},{"emy",19,80},{"jack",19,100} };
	//arr[2].name = "jack";
	//arr[2].age = 20;
	//arr[2].score = 100;
	//for (int i = 0; i < 3; i++) {
	//	cout << arr[i].name << "\t" << arr[i].age << "\t" << arr[i].score << endl;
	//}
	
	/*teacher arr[3];
	allocateAttibute(arr, 3);
	printStruct(arr, 3);*/

	// Ӣ�۽ṹ ������ð��
	struct hero arr[5] = {
		{"����", 23, "��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"}
	};

	bubblehero(arr, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr[i].name << arr[i].age << arr[i].sex << endl;
	}

	system("pause");


	return 0;
}