#include<iostream>
#include<string>
using namespace std;

// 虚析构和纯虚析构
// 下面test1运行后发现，调用了父类的构造，子类的构造，父类的析构，却没调用子类的析构。
// 说明堆区数据没释放干净，造成了内存泄露，因为子类实例还在。
// 添加虚析构：在父类的析构前面加一个virtual，可解决上述问题。
class Animal {
public:
	Animal() {
		cout << "animal gouzao" << endl;
	}
	// 虚析构
	//virtual ~Animal() {
	//	cout << "animal xigou" << endl;
	//}
	// 纯虚析构 需要有声明也需要有实现
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};
// 实现纯虚析构
Animal::~Animal() {
	cout << "Animal chunxu xigou" << endl;
}
class Cat :public Animal {
public:
	Cat(string tname) {
		cout << "cat gouzao" << endl;
		name = new string(tname);
	}
	virtual void speak() {
		cout << *name << "cat speaking" << endl;
	}
	~Cat() {
		cout << "cat xigou" << endl;
		if (name != NULL) {
			delete name;	// delete释放的是指针指向的堆区内存，
			name = NULL;	// 指针自身还能指向这个内存地址，还可以用这个指针来访问，为防止其他代码调用该指针，置空。
		}
	}
	string* name;	// 创建名字的指针，让名字创建在堆区
};
void test1() {
	Animal* a = new Cat("Tom");
	a->speak();
	// 因为创建的是父类指针，父类指针析构时不会调用子类的析构。
	// 导致子类如果有堆区属性，会出现内存泄露。
	delete a;
}
// 案例3
// 每个电脑零件抽象类，提供不同厂商
// 创建电脑类 让电脑工作 调用每个零件的接口
class CPU {
public:
	virtual void compute() = 0;
};
class GPU {
public:
	virtual void display() = 0;
};
class Memory {
public:
	virtual void storage() = 0;
};
class PC {
public:
	PC(CPU* c, GPU* g, Memory* m) {
		cpu = c;
		gpu = g;
		mem = m;
	}
	void work() {
		// 调用API
		cpu->compute();
		gpu->display();
		mem->storage();
	}
	~PC() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (gpu != NULL) {
			delete cpu;
			gpu = NULL;
		}
		if (mem != NULL) {
			delete cpu;
			mem = NULL;
		}
	}
private:
	CPU* cpu;
	GPU* gpu;
	Memory* mem;
};
class IntelCPU : public CPU {
public:
	virtual void compute() {
		cout << "Intel CPU working" << endl;
	}
};
class IntelGPU : public GPU {
public:
	virtual void display() {
		cout << "Intel GPU working" << endl;
	}
};
class IntelMEM : public Memory {
public:
	virtual void storage() {
		cout << "Intel Memory working" << endl;
	}
};
class AMDCPU : public CPU {
public:
	virtual void compute() {
		cout << "AMD CPU working" << endl;
	}
};
class AMDGPU : public GPU {
public:
	virtual void display() {
		cout << "AMD GPU working" << endl;
	}
};
class AMDMEM : public Memory {
public:
	virtual void storage() {
		cout << "AMD Memory working" << endl;
	}
};
void test2() {
	CPU* intelcpu = new IntelCPU;
	GPU* intelgpu = new IntelGPU;
	Memory* intelmem = new IntelMEM;
	PC* c1 = new PC(intelcpu,intelgpu,intelmem);
	c1->work();
	delete c1;
}

int main() {

	//test1();
	test2();

	system("pause");
	return 0;
}



