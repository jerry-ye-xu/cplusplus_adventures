
#include <iostream>
#include "stack_implement.h"
#include "node_implement.h"



										// #################
										// ###   STACK   ###
										// #################

Stack::Stack(): current_stack_top(0), size(0) { }

void Stack::push(int value){
		Node* new_node = new Node(value);
		if (size == 0){
			std::cout << "adding first Node to Stack.\nSetting Stack pointer to new node." << std::endl;
			current_stack_top = new_node;
		} else{
			new_node->point_to_current_top(current_stack_top);
			current_stack_top = new_node;
		}
		this->size++;
	}

int Stack::pop(){	
	if (this->size == 0){
		std::cout << "Stack is empty. Nothing to pop." << std::endl;
		return -1;
	}

	int pop_value = current_stack_top->get_value();
	current_stack_top = current_stack_top->get_next_node();

	this->size--;
	return pop_value;
}

int Stack::check_top(){
	if (this->size == 0){
		std::cout << "Stack is empty. Nothing on top." << std::endl;
		return -1;
	}
	return current_stack_top->get_value();
}

int Stack::check_size(){
	return this->size;
}

void Stack::destroy_stack(){
	std::cout << "Destroying stack.\n";
	if (size == 0){
		std::cout << "Stack is empty." << std::endl;
	} else if(size == 1){
		std::cout << "one Node in stack." << std::endl;
		delete current_stack_top;
		size--; 
	}

	Node* next_node_to_be_deleted;
	while(this->size != 0){
		next_node_to_be_deleted = current_stack_top->get_next_node();
		delete current_stack_top;

		current_stack_top = next_node_to_be_deleted; 
		size--;
	}
	std::cout << "Stack destroyed.\n";
}

