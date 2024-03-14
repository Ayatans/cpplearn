#include <iostream>
#include <string>
using namespace std;

// 多态
class Animal {
public:
	// 前面加上virtual构成虚函数
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
// 即使指定的参数是父类，传入子类时也能调用子类中的相关函数。
// 早绑定的写法，不管传入什么，都会按animal中的函数运行。
// 如果想用子类中的方法，要改成晚绑定。
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

// 案例1：计算器类
// 普通写法
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
	// 如果想扩展新的功能，就还要修改该函数。
};
void test3() {
	Calculator c;
	c.n1 = 10;
	c.n2 = 20;
	cout << c.getResult("+") << c.getResult("-") << c.getResult("*") << endl;
}
// 实现计算器的抽象类
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
	// 父类的指针指向子类对象
	// 加法
	Abstract* ab = new AddCal;
	ab->n1 = 20;
	ab->n2 = 10;
	cout << ab->getResult() << endl;
	delete ab; // 堆区数据用完要手动销毁
	// 减法
	ab = new MinusCal;
	ab->n1 = 20;
	ab->n2 = 5;
	cout << ab->getResult() << endl;
	delete ab;
}

// 纯虚函数和抽象类
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
	// Base b;	// 抽象类无法实例化
	// new Base;
	Base* b = new Son;	// 多态调用子类中的虚函数。
	b->func();
}

// 多态案例2 制作饮品
class AbstractDrinking {
public:
	virtual void Boil() = 0;	//煮水
	virtual void Brew() = 0;	// 冲泡
	virtual void Pour() = 0;	// 倒入杯中
	virtual void Ingredient() = 0;	// 加入辅料
	void makeDrink() {	// 制作饮品
		Boil();
		Brew();
		Pour();
		Ingredient();
	}
};
class Coffee :public AbstractDrinking {
	virtual void Boil() {
		cout << "boiling water" << endl;
	}; 	//煮水
	virtual void Brew() {
		cout << "brewing coffee" << endl;
	}; 	// 冲泡
	virtual void Pour() {
		cout << "pouring into cup" << endl;
	};	// 倒入杯中
	virtual void Ingredient() {
		cout << "adding sugar and milk" << endl;
	}; 	// 加入辅料
};
class Tea :public AbstractDrinking {
	virtual void Boil() {
		cout << "boiling good water" << endl;
	}; 	//煮水
	virtual void Brew() {
		cout << "brewing tea" << endl;
	}; 	// 冲泡
	virtual void Pour() {
		cout << "pouring into cup" << endl;
	};	// 倒入杯中
	virtual void Ingredient() {
		cout << "adding lemon" << endl;
	}; 	// 加入辅料
};
void doDrinking(AbstractDrinking *abs) {
	abs->makeDrink();
	delete abs; // 释放掉堆区内存，防止内存泄露。
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