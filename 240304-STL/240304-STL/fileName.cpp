//using namespace std;

// version 17.9 or more 
// release , x64
// project -> �Ӽ� -> std::c++latest , SDL - no

// ���â 80 X 25

// 2024.03.04
// source file save ���

// const std::string& == string_view (�޸��� �����ּҿ� ������ �˷���)

#include "save.h"


// [����] main() �� �����ϸ� �ȵȴ�. �Լ� change() �� �����ϰ� ����

class Dog; // forward declaration (���漱��)

template <class T>
void change(T&, T&);

//void change(int& a, int& b);
//void change(Dog& a, Dog& b);
// std::ostream& operator<< (std::ostream&, const Dog&);

class Dog {

public:
	Dog(int num) : num{ num } {}
	// Dog(const Dog& other) {}; // -> special �Լ� : �����Ϸ��� �ڵ� ����

	operator int() {
		return num;
	}

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num;
	}

private:
	int num;
};

int main()
{
	Dog a{ 1 }, b{ 2 };

	change(a, b); // change<Dog>(a,b) �̷��� ���� ���� ���� , �����Ϸ��� ����� �Ҽ� ����
	std::cout << a << ", " << b << std::endl; //[���] 2 , 1

	save("fileName.cpp");
}

//void change(Dog& a, Dog& b) 
//{
//	Dog temp{ b }; // ���� �����Ǵ� ���� (copy-construction)
//	b = a;
//	a = temp;
//}

template <class T>
void change(T& a, T& b) {
	T temp{ a };
	a = b;
	b = temp;
}

// oop -> Ư�� �ڷ���
// Generic -> �ڷ����� ������ �ڵ� -> template -> �Լ� : �˰��� , Ŭ���� : �ڷᱸ��