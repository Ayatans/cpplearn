#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// �ı��ļ�д
void test1() {
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "name: John " << endl;
	ofs << "sex: male " << endl;
	ofs.close();

}
// �ı��ļ���
void test2() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "open fail" << endl;
		return;
	}
	// Method 1 read data
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;	// �����ո�ỻһ�����
	//}

	// Method 2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {	// ��ifs���ÿһ�е�buf�������С��buf�Ĵ�С
	//	cout << buf << endl;	// �����ո񲻻ỻһ��
	//}

	// Method 3
	//string buf;
	//while (getline(ifs, buf)) {	// ��ifs����е�buf��
	//	cout << buf << endl;	// �����ո񲻻ỻһ��
	//}

	// Method 4 ( Not Recommended, low efficiency)
	char c;
	while ((c = ifs.get()) != EOF) {	// get ��һ���ַ�һ���ַ�����ֻҪû�����ļ�β��һֱ��
		cout << c;
	}

	ifs.close();
	return;
}
// �������ļ�д
class Person {
public:
	char name[64];
	int age;
};
void test3() {
	ofstream ofs("person.txt", ios::out | ios::binary);	// ���캯��������ʱ����ָ��
	//ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "John", 18 };
	ofs.write((const char*)&p, sizeof(Person));	// ��һ��Ҫǿת����ΪҪ����const char*
	ofs.close();
}
// �������ļ���
void test4() {
	ifstream ifs;
	ifs.open("person.txt", ios::out | ios::binary);
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << p.name << p.age << endl;
	ifs.close();
}
int main() {
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}