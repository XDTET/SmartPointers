
#include <iostream>
#include <memory>
#include <array>

class MyClass {
public:
	MyClass()
	{
		std::cout << "Created Object" << std::endl;
	}
	~MyClass()
	{
		std::cout << "Destroyed Object" << std::endl;
	}
};

int main()
{
	std::unique_ptr<int> ptr1 = std::make_unique<int>(25);
	std::unique_ptr<int> ptr2;

	// Bad ptr2 = ptr1; 

	std::shared_ptr<MyClass> s_ptr1 = std::make_shared<MyClass>();
	std::shared_ptr<MyClass> s_ptr2 = s_ptr1;

	std::cout << s_ptr1.use_count() << std::endl;

	std::weak_ptr<MyClass> w_ptr1;
	w_ptr1 = s_ptr1;;

	std::cout << s_ptr1.use_count() << std::endl;

	return 0;
}

