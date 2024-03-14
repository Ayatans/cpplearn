#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>	// ��׼�㷨ͷ�ļ�
using namespace std;

// string ��ʼ���͸�ֵ = assign
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
	str5.assign("elphin", 4);	// ���������ַ�����ǰn���ַ���ֵ����ǰ�ַ���
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

// string ƴ�� + append
void test5() {
	string s1 = "me";
	string s2 = "bi";
	s1 += "good";
	s1 += 'o';
	s1 += s2;
	s1.append(" di");
	s1.append("nner", 2);
	s1.append(s2);
	s1.append(s2, 0, 1);	// ��ȡ���֣�������0��ʼ����ȡ����Ϊ1����Ƭ
	cout << s1 << endl;
}

// string ���Һ��滻 find rfind replace
void test6() {
	string s1 = "hello world el";
	int p1 = s1.find("el");	// �����ҵ����������Ҳ�����-1
	cout << p1 << endl;
	int p2 = s1.rfind("el");	// ���������ң����ص��������Ǵ������ҵ� 
	cout << p2 << endl;

	s1.replace(1, 5, "abcd");	// ������1��ʼ��5���ַ��滻Ϊ������ַ���
	cout << s1 << endl;
}

// string �Ƚϣ����ַ���ASCII�Աȣ���ȷ���0��a>b ����1��a<b ����-1
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

// string �ַ���ȡ
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

// string �����ɾ��
void test9() {
	string s1 = "hello world";
	s1.insert(1, "222");	// ����λ�ã������ַ������ַ�
	s1.insert(3, 5, 'c');	// ����λ�ã������ַ��������������ַ�
	s1.erase(10, 2);		// ��λ��3��ʼ��ɾ��2���ַ�
	cout << s1 << endl;
}

// string ��ȡ�Ӵ�
void test10() {
	string s1 = "hello world";
	string s2 = s1.substr(2, 7);	// ��λ��2��ʼ��7���ַ���ɵ��ַ���
	cout << s2 << endl;

	string e = "abcde@gmail.com";	// ��ȡemail�û���
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