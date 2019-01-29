
#include <iostream>

#include "data_structures/stack_implement.h"
#include "data_structures/node_implement.h"

using namespace std;

int reverse_integer(int x);

int main(){
	
	// reverse_integer(234);
	// reverse_integer(25);

	int *p1;
	int *p2;

	int x = 25;
	int y = 35;

	p1 = &x;
	p2 = &y;

	cout << "x is: " << *p1 << endl;
	cout << "y is: " << *p2 << endl;

	p1 = p2;

	cout << "reassign p1 to p2" << endl;
	cout << "x is now: " << *p1 << endl;

	Stack container;
	cout << "size: " << container.check_size() << endl;

	// container.push(3);
	// cout << "The top of the stack is: " << container.check_top() << endl;	

	// container.push(5);
	// cout << "The top of the stack is: " << container.check_top() << endl;

	// container.push(7);
	// cout << "The top of the stack is: " << container.check_top() << endl;

	// container.push(9);
	// cout << "The top of the stack is: " << container.check_top() << endl;	

	// cout << "size: " << container.check_size() << endl;

	// int first_pop = container.pop();
	// cout << "The top of the stack is: " << container.check_top() << endl;	
	// int second_pop = container.pop();
	// cout << "The top of the stack is: " << container.check_top() << endl;		

	// cout << "size: " << container.check_size() << endl;
	// container.destroy_stack();

	// int a = -2524;
	// int b = a % 10;
	// cout << b << endl;

	// int c = 5;
	// cout << c % 10 << endl;

	// while(a > 10){
	// 	container.push(a % 10);
	// 	cout << a << endl;
	// 	a /= 10;
	// }
	// container.push(a);
	// cout << "last value of a is: " << a << endl;

	// int reverse = 0;
	// int power = 1;
	// while(container.check_size() != 0){
	// 	cout << "The top of the stack is: " << container.check_top() << endl;
	// 	reverse += container.pop() * power;
		
	// 	power *= 10;
	// }
	// cout << "last value of reverse is: " << reverse << endl;

	cout << reverse_integer(0) << endl;
	cout << reverse_integer(12345) << endl;
	cout << reverse_integer(1234567890) << endl;
	cout << reverse_integer(-1) << endl;
	cout << reverse_integer(-25300) << endl;
	cout << reverse_integer(-654000) << endl;
	cout << reverse_integer(-87654321) << endl;
	return 0;

}

int reverse_integer(int x){

	if (x == 0){
		return 0;
	} else if (x < INT_MIN){
		return 0;
	} else if (x > INT_MAX){
		return 0;
	}

	bool negative = false;
	if (x < 0){
		x = -1*x; 
		negative = true;
	}

	Stack container;

	while(x > 10){
		container.push(x % 10);
		x /= 10;
	}
	// push the last digit in.
	container.push(x);

	int reverse = 0; 
	int power = 1;
	while(container.check_size() != 0){
		reverse += container.pop() * power;
		power *= 10;
	}
	if (negative){
		reverse = reverse * -1;
	}
	return reverse;
}

// g++ -std=c++11 -o reverse_int reverse_int.cpp data_structures/node_implement.h data_structures/stack_implement.h