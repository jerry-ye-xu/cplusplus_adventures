
#include <iostream>

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "node_implement.h"

#ifndef HUFFMAN_ALGORITHM_H
#define HUFFMAN_ALGORITHM_H

// std::unordered_map<char, int>* count_char(std::vector <std::string> &sentences);

// void insert_priority_queue(std::unordered_map<char, int>& char_map);

// void build_huffman_tree();

// void map_bit_encoding_to_set();

// void compress_data(std::vector <std::string> &sentences);

// void decompress_data();

class huffman_algorithm{
	public:
		huffman_algorithm(std::vector<std::string> &sentences);

		std::vector<std::string> compress_data(std::vector<std::string> &sentences);

	private:
		/*
		Allocate space for map, tree and priority queue in 
		*/
		std::unordered_set<char> char_set;
		std::unordered_map<char, int> count_map;
		std::unordered_map<char, std::string> code_map; 
		// std::priority_queue<Node<char, int>, std::vector<Node<char, int>>, std::less<std::vector<Node<char, int >>::value_type> > pqueue;
		
		Node<char, int> *root_node;
		int tree_size;

		void count_char(std::vector <std::string> &sentences);
		void insert_priority_queue ();
		void build_huffman_tree();
		void map_bit_encoding_to_set();

		int get_tree_size();
		void print_count_map();
		void print_code_map();
};

#endif

/*



*/
