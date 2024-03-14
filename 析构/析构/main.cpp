#include<iostream>
#include<string>
using namespace std;

// �������ʹ�������
// ����test1���к��֣������˸���Ĺ��죬����Ĺ��죬�����������ȴû���������������
// ˵����������û�ͷŸɾ���������ڴ�й¶����Ϊ����ʵ�����ڡ�
// ������������ڸ��������ǰ���һ��virtual���ɽ���������⡣
class Animal {
public:
	Animal() {
		cout << "animal gouzao" << endl;
	}
	// ������
	//virtual ~Animal() {
	//	cout << "animal xigou" << endl;
	//}
	// �������� ��Ҫ������Ҳ��Ҫ��ʵ��
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};
// ʵ�ִ�������
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
			delete name;	// delete�ͷŵ���ָ��ָ��Ķ����ڴ棬
			name = NULL;	// ָ��������ָ������ڴ��ַ�������������ָ�������ʣ�Ϊ��ֹ����������ø�ָ�룬�ÿա�
		}
	}
	string* name;	// �������ֵ�ָ�룬�����ִ����ڶ���
};
void test1() {
	Animal* a = new Cat("Tom");
	a->speak();
	// ��Ϊ�������Ǹ���ָ�룬����ָ������ʱ������������������
	// ������������ж������ԣ�������ڴ�й¶��
	delete a;
}
// ����3
// ÿ��������������࣬�ṩ��ͬ����
// ���������� �õ��Թ��� ����ÿ������Ľӿ�
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
		// ����API
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



