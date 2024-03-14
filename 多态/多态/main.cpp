#include <iostream>
#include <string>
using namespace std;

// ��̬
class Animal {
public:
	// ǰ�����virtual�����麯��
	virtual void speak() {
		cout << "animal speaks" << endl;
	}
	// 
};
class Cat: public Animal {
public:
	void speak() {
		cout << "cat speaking" << endl;
	}
};
// ��ʹָ���Ĳ����Ǹ��࣬��������ʱҲ�ܵ��������е���غ�����
// ��󶨵�д�������ܴ���ʲô�����ᰴanimal�еĺ������С�
// ������������еķ�����Ҫ�ĳ���󶨡�
void doSpeak(Animal& animal) {
	animal.speak();
}
void test1() {
	Cat c;
	doSpeak(c);
}
void test2() {
	cout << sizeof(Animal) << endl;
}

// ����1����������
// ��ͨд��
class Calculator {
public:
	int n1;
	int n2;
	int getResult(string oper) {
		if (oper == "+") {
			return n1 + n2;
		}
		else if (oper == "-") {
			return n1 - n2;
		}
		else if (oper == "*") {
			return n1 * n2;
		}
	}
	// �������չ�µĹ��ܣ��ͻ�Ҫ�޸ĸú�����
};
void test3() {
	Calculator c;
	c.n1 = 10;
	c.n2 = 20;
	cout << c.getResult("+") << c.getResult("-") << c.getResult("*") << endl;
}
// ʵ�ּ������ĳ�����
class Abstract {
public:
	int n1;
	int n2;
	virtual int getResult() {
		return 0;
	}
};
class AddCal :public Abstract {
public:
	int getResult() {
		return n1 + n2;
	}
};
class MinusCal :public Abstract {
public:
	int getResult() {
		return n1 - n2;
	}
};
class MulCal :public Abstract {
public:
	int getResult() {
		return n1 * n2;
	}
};
void test4() {
	// �����ָ��ָ���������
	// �ӷ�
	Abstract* ab = new AddCal;
	ab->n1 = 20;
	ab->n2 = 10;
	cout << ab->getResult() << endl;
	delete ab; // ������������Ҫ�ֶ�����
	// ����
	ab = new MinusCal;
	ab->n1 = 20;
	ab->n2 = 5;
	cout << ab->getResult() << endl;
	delete ab;
}

// ���麯���ͳ�����
class Base {
public:
	virtual void func() = 0;
};
class Son:public Base {
public:
	virtual void func(){
		cout << "son func" << endl;
	};
};
void test5() {
	// Base b;	// �������޷�ʵ����
	// new Base;
	Base* b = new Son;	// ��̬���������е��麯����
	b->func();
}

// ��̬����2 ������Ʒ
class AbstractDrinking {
public:
	virtual void Boil() = 0;	//��ˮ
	virtual void Brew() = 0;	// ����
	virtual void Pour() = 0;	// ���뱭��
	virtual void Ingredient() = 0;	// ���븨��
	void makeDrink() {	// ������Ʒ
		Boil();
		Brew();
		Pour();
		Ingredient();
	}
};
class Coffee :public AbstractDrinking {
	virtual void Boil() {
		cout << "boiling water" << endl;
	}; 	//��ˮ
	virtual void Brew() {
		cout << "brewing coffee" << endl;
	}; 	// ����
	virtual void Pour() {
		cout << "pouring into cup" << endl;
	};	// ���뱭��
	virtual void Ingredient() {
		cout << "adding sugar and milk" << endl;
	}; 	// ���븨��
};
class Tea :public AbstractDrinking {
	virtual void Boil() {
		cout << "boiling good water" << endl;
	}; 	//��ˮ
	virtual void Brew() {
		cout << "brewing tea" << endl;
	}; 	// ����
	virtual void Pour() {
		cout << "pouring into cup" << endl;
	};	// ���뱭��
	virtual void Ingredient() {
		cout << "adding lemon" << endl;
	}; 	// ���븨��
};
void doDrinking(AbstractDrinking *abs) {
	abs->makeDrink();
	delete abs; // �ͷŵ������ڴ棬��ֹ�ڴ�й¶��
}
void test6() {
	doDrinking(new Coffee);
	doDrinking(new Tea);
}

int main() {
	//test1();
	//test2();

	//test3();
	//test4();

	//test5();
	test6();

}