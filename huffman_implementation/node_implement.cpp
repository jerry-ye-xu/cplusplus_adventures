
#include <iostream>

#include "node_implement.h"



										// ################
										// ###   NODE   ###
										// ################

// can use "nullptr" in C++11.
template <class T, class S>
Node<T, S>::Node(T new_value, S char_count): 
	value(new_value), char_count(char_count), 
	left_child(0), right_child(0), parent_node(0) { }

template <class T, class S>
Node<T, S>::Node(T new_value): 
	value(new_value), char_count(0), 
	left_child(0), right_child(0), parent_node(0) { }

// ~Node::Node() {
// 	std::cout << "Deleting Node." << std::endl;
// }

template <class T, class S>
T Node<T, S>::get_value(){
	return value;
}

template <class T, class S>
Node<T, S>* Node<T, S>::get_parent_node(){
	return parent_node;
}

template <class T, class S>
Node<T, S>* Node<T, S>::get_left_child(){
	return left_child;
}

template <class T, class S>
Node<T, S>* Node<T, S>::get_right_child(){
	return right_child;
}

template <class T, class S>
void Node<T, S>::set_left_child(Node* node){
	left_child = node;
}

template <class T, class S>
void Node<T, S>::set_right_child(Node* node){
	right_child = node;
}

template <class T, class S>
void Node<T, S>::set_parent_node(Node* node){
	parent_node = node;
}

bool operator < (Node<char, int> &node_1, Node<char, int> &node_2){
	return node_1.get_value() < node_2.get_value();
}

bool operator > (Node<char, int> &node_1, Node<char, int> &node_2){
	return node_1.get_value() > node_2.get_value();
}