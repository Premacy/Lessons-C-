#include <iostream>
Qa}]MTpve6i=,s,
int main(){

	// Types

	int a = 5;		    // 4b

	float b = 5.5;	    //4b
	double c = 10.5;	// 8b

	char s = 'F';		// 1b [-127,128]

	bool flag = true;	// 1b
	flag = false;

	// Math operations

	int a;
	int b;

	// Or

	int a, b;
	int c;

	c = a + b;
	c = a - b;
	c = a / b;
	c = a * b;

	//

	flag = 234;		// 0 = false, ANY = true
	std::cout << flag << std::endl;

	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(b) << std::endl;
	std::cout << sizeof(c) << std::endl;
	std::cout << sizeof(s) << std::endl;
	std::cout << sizeof(flag) << std::endl;
	
	return 0;
}