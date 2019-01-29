
#include <iostream>

#include "node_implement.h"



										// ################
										// ###   NODE   ###
										// ################

// can use "nullptr" in C++11.
Node::Node(int new_value): value(new_value), next_node(0), prev_node(0) { }

// ~Node::Node() {
// 	std::cout << "Deleting Node." << std::endl;
// }

int Node::get_value(){
	return value;
}

Node* Node::get_next_node(){
	return next_node;
}

Node* Node::get_prev_node(){
	return prev_node;
}

void Node::set_next_node(Node* node){
	next_node = node;
}

void Node::set_prev_node(Node* node){
	prev_node = node;
}

void Node::point_to_current_top(Node* current_stack_top){
	next_node = current_stack_top;
}