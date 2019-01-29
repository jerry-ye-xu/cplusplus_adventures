
#include <iostream>
#include "queue_implement.h"



										// #################
										// ###   QUEUE   ###
										// #################

Queue::Queue(): size(0), head(0), tail(0) { }

void Queue::enqueue(int value){
	Node* new_node = new Node(value);
	if(size == 0){
		std::cout << "Queue is empty. Adding in first Node." << std::endl;
		tail = new_node;
		head = new_node;
	}
	tail->set_prev_node(new_node);
	new_node->set_next_node(tail);
	tail = new_node;
	
	size++;
}

int Queue::dequeue(){
	if (this->size == 0){
		std::cout << "Queue is empty. Nothing in front." << std::endl;
		return -1;
	}
	int ret_value = head->get_value();
	Node* next_head = head->get_prev_node();

	head = next_head;

	size--;
	return ret_value;
}

int Queue::check_front(){
	if (this->size == 0){
		std::cout << "Queue is empty. Nothing in front." << std::endl;
		return -1;
	}
	return head->get_value();
}

int Queue::check_size(){
	return this->size;
}

void Queue::destroy_queue(){
	std::cout << "Destroying Queue.\n";
	if (size == 0){
		std::cout << "Queue is empty." << std::endl;
	} else if(size == 1){
		std::cout << "one Node in Queue." << std::endl;
		delete head;
		size--; 
	}

	Node* current_node_to_be_deleted = tail;
	Node* next_node_to_be_deleted;
	while(this->size != 0){
		next_node_to_be_deleted = current_node_to_be_deleted->get_next_node();
		delete current_node_to_be_deleted;

		current_node_to_be_deleted = next_node_to_be_deleted;
		size--;
	}
	std::cout << "Queue destroyed.\n";
}
