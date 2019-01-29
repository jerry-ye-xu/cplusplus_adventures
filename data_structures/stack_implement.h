
#include "node_implement.h"

#ifndef STACK_IMPLEMENT_H
#define STACK_IMPLEMENT_H

class Stack{
	public:
		Stack();
		// Stack(int value);
		
		void push(int value);
		int pop();
		int check_top();
		int check_size();

		void destroy_stack();
	
	private:
		int size;
		Node* current_stack_top;

};

#endif