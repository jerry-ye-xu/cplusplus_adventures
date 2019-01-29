
#include <iostream>
#include <string>

#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "node_implement.h"
#include "huffman_algorithm.h"

huffman_algorithm::huffman_algorithm(std::vector<std::string> &sentences): root_node(0), tree_size(0){

	/*
	Count the characters and map 
	*/
	// for (std::string sentence : *sentences){
	// 	for (char letter : sentence)
	// 		if(this->char_set->count(letter) == 0){
	// 			this->char_set->insert(letter);
	// 			this->count_map[letter] = 1;
	// 		} else {
	// 			this->count_map[letter]++;
	// 		}
	// }

	/*
	Using the map, generate the nodes to insert into priority queue. 
	*/

	// for(auto it = char_set.begin(), char_set.end(), it++){
	// 	cout << *it << endl;
	// }

	count_char(sentences);
	for(auto it = char_set.begin(); it != char_set.end(); it++){
		std::cout << *it << " " << count_map[*it] << std::endl;
	} 

	std::cout << "Huffman Algorithm Initialised!!" << std::endl;
}

void huffman_algorithm::count_char(std::vector <std::string> &sentences){
	/* Takes the sentences and constructs a mapping of counts for each unique character. */

	std::vector<std::string> *sent_ptr;
	sent_ptr = &sentences; 

	for (std::string sentence : *sent_ptr){
		for (char letter : sentence)
			if(this->char_set.count(letter) == 0){
				this->char_set.insert(letter);
				this->count_map[letter] = 1;
			} else {
				this->count_map[letter]++;
			}
	}	
}

void huffman_algorithm::insert_priority_queue(){
	/*
	Extract each character and their counts to an individual node, and push all of them
	into the priority queue. 
	*/
	for(auto it = char_set.begin(); it != char_set.end(); it++){
		std::cout << *it << " " << count_map[*it] << std::endl;
		this->pqueue.push(new Node<char, int>(*it, count_map[*it]));
	} 
}


/* 
Comparator Methods for Priority Queue on the node class. 
*/
// bool operator < (Node<char, int> &node_1, Node<char, int> &node_2){
// 	return node_1.get_value() < node_2.get_value();
// }

// bool operator > (Node<char, int> &node_1, Node<char, int> &node_2){
// 	return node_1.get_value() > node_2.get_value();
// }

void huffman_algorithm::build_huffman_tree(){
	std::cout << "Building Huffman Tree...";
}	

/*
For error checking
*/
void huffman_algorithm::print_code_map(){
	std::cout << "The code map is: ";
}

void huffman_algorithm::print_count_map(){
	std::cout << "The count map is: ";	
}

