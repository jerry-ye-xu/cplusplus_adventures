
#ifndef NODE_IMPLEMENT_H
#define NODE_IMPLEMENT_H

class Node{
	public:
		Node(int new_value);
		// ~ Node();
		
		int get_value();

		Node* get_next_node();
		Node* get_prev_node();
		void set_next_node(Node* node);
		void set_prev_node(Node* node);
		void point_to_current_top(Node* current_stack_top);

	private:
		int value;
		Node* next_node;
		Node* prev_node;

};

#endif