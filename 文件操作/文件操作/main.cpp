#include<fstream>
#include<iostream>
#include<string>
using namespace std;

// 文本文件写
void test1() {
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "name: John " << endl;
	ofs << "sex: male " << endl;
	ofs.close();

}
// 文本文件读
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
	//	cout << buf << endl;	// 遇到空格会换一行输出
	//}

	// Method 2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {	// 从ifs里读每一行到buf里，读出大小是buf的大小
	//	cout << buf << endl;	// 遇到空格不会换一行
	//}

	// Method 3
	//string buf;
	//while (getline(ifs, buf)) {	// 从ifs里读行到buf里
	//	cout << buf << endl;	// 遇到空格不会换一行
	//}

	// Method 4 ( Not Recommended, low efficiency)
	char c;
	while ((c = ifs.get()) != EOF) {	// get 是一个字符一个字符读，只要没读到文件尾就一直读
		cout << c;
	}

	ifs.close();
	return;
}
// 二进制文件写
class Person {
public:
	char name[64];
	int age;
};
void test3() {
	ofstream ofs("person.txt", ios::out | ios::binary);	// 构造函数，创建时即可指定
	//ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "John", 18 };
	ofs.write((const char*)&p, sizeof(Person));	// 第一项要强转，因为要求是const char*
	ofs.close();
}
// 二进制文件读
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