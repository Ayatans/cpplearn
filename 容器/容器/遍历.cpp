#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<functional>
using namespace std;
// ��ͨ����
void fun1(int val) {
	cout << val << " ";
}
// �º���
class fun2 {
public:
	// ����() ��Ϊ����ָ�봫��for_eachʱ�������ڲ�������ʱ���С���ű��fun(val)���Ϳ��Ե����������غ���������
	void operator()(int val) {
		cout << val << " ";
	}
};
void test50() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	
	for_each(v.begin(), v.end(), fun1);
	for_each(v.begin(), v.end(), fun2()); // ���봫һ���������������������
}
class fun3 {
public:
	int operator()(int val) {
		return val+100;
	}
};
void test51() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> t;
	// ����ǰ����target�Ŀռ�Ļ��ᱨ��
	t.resize(v.size());  
	transform(v.begin(), v.end(), t.begin(), fun3());
	for_each(t.begin(), t.end(), fun1);

}
int main10() {
	//test50();
	test51();


	system("pause");
	return 0;
}