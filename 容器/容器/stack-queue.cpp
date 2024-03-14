#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
using namespace std;

// stack push pop top empty size 
void test24() {
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.push(4);
	while (!s.empty()) {
		cout << s.size() << " " << s.top() << endl;
		s.pop();
	}
}

// queue
void test25() {
	queue<int> q;
	q.push(2);
	q.push(10);
	q.push(5);
	q.push(1);
	while (!q.empty()) {
		cout << q.front() << endl;
		cout << q.back() << endl;
		q.pop();
	}
	cout << q.size() << endl;

}

int main4() {

	//test24();
	test25();

	system("pause");
	return 0;
}