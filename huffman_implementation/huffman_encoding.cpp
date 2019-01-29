
#include <iostream>
#include <string>

#include <vector>
#include <unordered_set>
#include <map>
#include "huffman_algorithm.h"

int main(){

	/*
	CODE TESTING FOR ALL THE INDIVIDUAL FUNCTIONS WHEN 
	CODING THIS ASSIGNMENT.
	*/


	std::vector<std::string> sentences = {"Hi my name is Jerry.", 
								 "Welcome to the first data set for the huffman encoding algorithm.",
								 "I am looking forward to the result."
								};

	for (std::string sentence : sentences){
		std::cout << std::endl;
		for (char letter : sentence)
		std::cout << letter;
	}
	std::cout << std::endl;

	std::unordered_map<char, int> char_count_map;
	std::unordered_map<char, int> *map_ptr;

	map_ptr = &char_count_map;

	(*map_ptr)['a'] = 1;
	(*map_ptr)['e'] = 5;
	(*map_ptr)['i'] = 9;
	(*map_ptr)['o'] = 15;
	(*map_ptr)['u'] = 21;

	char_count_map['a']++;

	std::cout << (*map_ptr)['a'] << " " << (*map_ptr)['e'] << " ";
	std::cout << (*map_ptr)['i'] << " " << (*map_ptr)['o'] << " " << (*map_ptr)['u'] << " " << std::endl;

	std::unordered_set<int> set_of_ints;
	set_of_ints.insert(3);
	set_of_ints.insert(8);
	set_of_ints.insert(1);
	set_of_ints.insert(12);

	for(auto it = set_of_ints.begin(); it != set_of_ints.end(); ++it){
		std::cout << *it << std::endl;
	}

	/*
	THE HUFFMAN ALGORITHM START HERES
	*/

	return 0;
}