
#ifndef NODE_IMPLEMENT_H
#define NODE_IMPLEMENT_H

template <class T, class S>
class Node{
	public:
		Node(T new_value, S char_count);
		Node(T new_value);
		// ~ Node();
		
		T get_value();

		Node* get_left_child();
		Node* get_right_child();
		Node* get_parent_node();
		void set_left_child(Node* node);
		void set_right_child(Node* node);
		void set_parent_node(Node* node);

	private:
		T value;
		S char_count; 
		Node* parent_node;
		Node* left_child;
		Node* right_child;

		friend bool operator < (Node<char, int> &node_1, Node<char, int> &node_2);
		friend bool operator > (Node<char, int> &node_1, Node<char, int> &node_2);
};

#endif