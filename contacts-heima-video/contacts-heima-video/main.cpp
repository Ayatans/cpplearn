#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

struct person {
	string name;
	int sex;
	int age;
	string phone;
	string add;
};

struct contact {
	struct person arr[MAX];
	int size;
};

void showMenu() {
	cout << "1, add person" << endl;
	cout << "2, show all" << endl;
	cout << "3, delete person" << endl;
	cout << "4, search person" << endl;
	cout << "5, change person" << endl;
	cout << "6, delete all" << endl;
	cout << "0, exit" << endl;
}

void addPerson(contact* con) {
	if (con->size == MAX) {
		cout << 'FULL' << endl;
		return;
	}
	else {
		

		string name;
		cout << "input name" << endl;
		cin >> name;
		con->arr[con->size].name = name;

		int sex;
		cout << "input sex" << endl;
		cout << "1--male" << endl;
		cout << "2--female" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				con->arr[con->size].sex = sex;
				break;
			}
			else {
				cout << "wrong sex" << endl; 
				continue;
			}
		}

		cout << "input age" << endl;
		int age = 0;
		cin >> age;
		con->arr[con->size].age = age;

		cout << "input phone" << endl;
		string phone;
		cin >> phone;
		con->arr[con->size].phone = phone;

		cout << "input address" << endl;
		string add;
		cin >> add;
		con->arr[con->size].add = add;

		con->size++;

		cout << "add done!" << endl;
		system("pause");
		// 每次添加成功后，清屏
		system("cls");
	}
}

void showperson(contact* con) {
	if (con->size == 0) {
		cout << "empty contact" << endl;
	}
	else {
		for (int i = 0; i < con->size; i++) {
			cout << con->arr[i].name << '\t' << (con->arr[i].sex ==1 ? "male" : "female" )<< '\t' << con->arr[i].age << '\t' <<
				con->arr[i].phone << '\t' << con->arr[i].add << '\t' << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(contact* con, string name) {
	for (int i = 0; i < con->size; i++) {
		if (con->arr[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(contact* con) {
	cout << "input delete name" << endl;
	string dname;
	cin >> dname;
	int index = isExist(con, dname);
	if (index == -1) {
		cout << "no such person" << endl;
	}
	else {
		for (int i = index; i < con->size; i++) {
			con->arr[i] = con->arr[i + 1];
		}
		con->size--;
		cout << "delete done" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(contact* con) {
	cout << "input search person" << endl;
	string sname;
	cin >> sname;
	int index = isExist(con, sname);
	if (index == -1) {
		cout << "no such person" << endl;
	}
	else {
		cout << con->arr[index].name << '\t' << (con->arr[index].sex == 1 ? "male" : "female") << '\t' << con->arr[index].age << '\t' <<
			con->arr[index].phone << '\t' << con->arr[index].add << '\t' << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(contact* con) {
	cout << "input change person" << endl;
	string cname;
	cin >> cname;
	int index = isExist(con, cname);
	if (index == -1) {
		cout << "no such person" << endl;
	}
	else {
		string name;
		cout << "input name" << endl;
		cin >> name;
		con->arr[index].name = name;

		int sex;
		cout << "input sex" << endl;
		cout << "1--male" << endl;
		cout << "2--female" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				con->arr[index].sex = sex;
				break;
			}
			else {
				cout << "wrong sex" << endl;
				continue;
			}
		}

		cout << "input age" << endl;
		int age = 0;
		cin >> age;
		con->arr[index].age = age;

		cout << "input phone" << endl;
		string phone;
		cin >> phone;
		con->arr[index].phone = phone;

		cout << "input address" << endl;
		string add;
		cin >> add;
		con->arr[index].add = add;

		cout << "change done" << endl;
	}
	system("pause");
	system("cls");
}

void emptyContact(contact* con) {
	con->size = 0;
	cout << "empty done" << endl;
	system("pause");
	system("cls");
}

int main() {

	contact con;
	con.size = 0;



	int select = 0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&con);
			break;
		case 2:
			showperson(&con);
			break;
		case 3:
			deletePerson(&con);
			break;
		case 4:
			findPerson(&con);
			break;
		case 5:
			changePerson(&con);
			break;
		case 6:
			emptyContact(&con);
			break;
		case 0:
			cout << "welcome next time" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}


	system("pause");
	return 0;
}