#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A() ";
	}

	A& operator=(const A& other)
	{
		std::cout << "OP= A";

		return *this;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B() ";
	}

	B& operator=(const B& other)
	{
		std::cout << "OP= B";

		return *this;
	}
};

class T
{
	A a;
	A* a2;
	B b;

public:
	T() 
	{
		std::cout << "T() ";

	}
	T(const T& other) //от предното демо знаем защо това ще извика
		              //default-ните конструктори на [A] и [B]
	{

		this->a = other.a; //това извиква operator= на [A]
		this->b = other.b; //това извиква operator= на [B]

		std::cout << "CpyT";

	}
	T& operator=(const T& other)
	{
		std::cout << "OP= T";

		return *this;
	}
};

void f(T copy)
{
	;
}

void f2(T& copy)
{
	;
}

int main()
{
	//вика конструкторите A() B() T() (2 пъти - за t1, t2)
	T t1;
	T t2; 

	//напомняме за една от основните разлики, при op= и двата обекта вече съществуват
	//при копиращия се създава в този момент

	t1 = t2; //викане на op=
	T t3(t2); //викане на копиращия конструктор


	std::cout << std::endl;
	std::cout << std::endl;

	f(t1); //f предизвиква извикването на копиращия конструктор на T,
		     //в който първо ще се иницализират [a] и [b] с default-ните си конструктори,
		     //тъй като не сме казали как, след което има две извиквания на op=
	       //и накрая ще се отпечата "CpyT"
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	f2(t1); //не се извиква копиращия => нява да доведе и до викането на op=, намиращо се в него

	f({});  //(вече го разгледахме) не се извиква копиращия => нява да доведе и до викането на op=, намиращо се в него
	return 0;

} 
