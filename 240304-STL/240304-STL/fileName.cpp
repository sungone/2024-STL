//using namespace std;

// version 17.9 or more 
// release , x64
// project -> 속성 -> std::c++latest , SDL - no

// 출력창 80 X 25

// 2024.03.04
// source file save 기능

// const std::string& == string_view (메모리의 시작주소와 개수만 알려줌)

#include "save.h"


// [문제] main() 을 변경하면 안된다. 함수 change() 를 선언하고 정의

class Dog; // forward declaration (전방선언)

template <class T>
void change(T&, T&);

//void change(int& a, int& b);
//void change(Dog& a, Dog& b);
// std::ostream& operator<< (std::ostream&, const Dog&);

class Dog {

public:
	Dog(int num) : num{ num } {}
	// Dog(const Dog& other) {}; // -> special 함수 : 컴파일러가 자동 생성

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

	change(a, b); // change<Dog>(a,b) 이렇게 굳이 쓰지 않음 , 컴파일러가 디덕션 할수 있음
	std::cout << a << ", " << b << std::endl; //[출력] 2 , 1

	save("fileName.cpp");
}

//void change(Dog& a, Dog& b) 
//{
//	Dog temp{ b }; // 복사 생성되는 순간 (copy-construction)
//	b = a;
//	a = temp;
//}

template <class T>
void change(T& a, T& b) {
	T temp{ a };
	a = b;
	b = temp;
}

// oop -> 특정 자료형
// Generic -> 자료형과 무관한 코딩 -> template -> 함수 : 알고리즘 , 클래스 : 자료구조