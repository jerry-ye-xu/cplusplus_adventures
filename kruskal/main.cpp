
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <tuple> 

#include "union_find_implement.h"

int main(){
	std::vector<std::tuple <char, char> > instructions;
	std::vector<std::tuple <char, char> > *instruct_ptr;

	/*
	Without the last 2 instructions, the sets are:
	{e, l, f}, {i, c, d, k, j, a, b}, {g, h}
	With the last 2 instructions, the sets are:
	{e, l, f, g, h, i, c, d, k, j, a, b}
	*/
	int element_size = 12;
	instructions.push_back(std::make_tuple('c', 'k'));
	instructions.push_back(std::make_tuple('f', 'e'));
	instructions.push_back(std::make_tuple('a', 'j'));
	instructions.push_back(std::make_tuple('a', 'b'));
	instructions.push_back(std::make_tuple('c', 'd'));
	instructions.push_back(std::make_tuple('d', 'i'));
	instructions.push_back(std::make_tuple('l', 'f'));
	instructions.push_back(std::make_tuple('c', 'a'));
	instructions.push_back(std::make_tuple('h', 'g'));
	// instructions.push_back(make_tuple('h', 'f'));
	// instructions.push_back(make_tuple('h', 'b'));

	std::cout << std::get<0>(instructions[0]) << std::endl;
	std::cout << std::get<1>(instructions[0]) << std::endl;

	instruct_ptr = &instructions;

	// instruct_ptr =  &instructions;
	std::cout << std::get<0>((*instruct_ptr)[0]) << std::endl;
	std::cout << std::get<1>((*instruct_ptr)[0]) << std::endl;

	std::cout << "iterating through the *instruct_ptr" << std::endl;  
	for (auto ptr: *instruct_ptr){
		std::cout << std::get<0>((ptr)) << std::endl;
	}
	std::cout << "end iteration of *instruct_ptr" << std::endl;

	std::tuple<int, int> test = std::make_tuple(1, 3);

	std::cout << std::get<0>(test) << std::endl;
	std::cout << std::get<1>(test) << std::endl;

	std::cout << "TESTING KRUSAL UNION FIND ALGORITHM" << std::endl;

	union_find<char> krus(element_size, instructions);
	std::cout << "ORIGINAL ROOTS" << std::endl;
	std::cout << krus.check_root_of_elem('a') << std::endl;
	std::cout << krus.check_root_of_elem('b') << std::endl;
	std::cout << krus.check_root_of_elem('c') << std::endl;
	std::cout << krus.check_root_of_elem('d') << std::endl;
	std::cout << krus.check_root_of_elem('e') << std::endl;
	std::cout << krus.check_root_of_elem('f') << std::endl;
	std::cout << krus.check_root_of_elem('g') << std::endl;
	std::cout << krus.check_root_of_elem('h') << std::endl;
	std::cout << krus.check_root_of_elem('i') << std::endl;
	std::cout << krus.check_root_of_elem('j') << std::endl;
	std::cout << krus.check_root_of_elem('k') << std::endl;
	std::cout << krus.check_root_of_elem('l') << std::endl;


	krus.join_nodes();

	std::cout << "JOINING NODES.... NEW ROOTS" << std::endl;
	std::cout << krus.check_root_of_elem('a') << std::endl;
	std::cout << krus.check_root_of_elem('b') << std::endl;
	std::cout << krus.check_root_of_elem('c') << std::endl;
	std::cout << krus.check_root_of_elem('d') << std::endl;
	std::cout << krus.check_root_of_elem('e') << std::endl;
	std::cout << krus.check_root_of_elem('f') << std::endl;
	std::cout << krus.check_root_of_elem('g') << std::endl;
	std::cout << krus.check_root_of_elem('h') << std::endl;
	std::cout << krus.check_root_of_elem('i') << std::endl;
	std::cout << krus.check_root_of_elem('j') << std::endl;
	std::cout << krus.check_root_of_elem('k') << std::endl;
	std::cout << krus.check_root_of_elem('l') << std::endl;

	std::cout << "CONNECTED NODES...." << std::endl;
	// {e, l, f}, {i, c, d, k, j, a, b}, {g, h}
	std::cout << "TRUE...." << std::endl;
	std::cout << krus.connected('a', 'b') << std::endl;
	std::cout << krus.connected('k', 'j') << std::endl;
	std::cout << krus.connected('a', 'k') << std::endl;
	std::cout << krus.connected('i', 'k') << std::endl;
	std::cout << krus.connected('c', 'b') << std::endl;
	std::cout << krus.connected('j', 'a') << std::endl;

	std::cout << krus.connected('g', 'h') << std::endl;
	std::cout << krus.connected('h', 'g') << std::endl;

	std::cout << krus.connected('e', 'f') << std::endl;
	std::cout << krus.connected('l', 'e') << std::endl;
	std::cout << krus.connected('l', 'f') << std::endl;

	std::cout << "FALSE...." << std::endl;

	std::cout << krus.connected('l', 'i') << std::endl;
	std::cout << krus.connected('l', 'k') << std::endl;
	std::cout << krus.connected('l', 'g') << std::endl;
	std::cout << krus.connected('h', 'e') << std::endl;

	std::cout << krus.connected('i', 'g') << std::endl;
	std::cout << krus.connected('c', 'g') << std::endl;
	std::cout << krus.connected('d', 'g') << std::endl;
	std::cout << krus.connected('k', 'g') << std::endl;
	std::cout << krus.connected('j', 'g') << std::endl;
	std::cout << krus.connected('a', 'g') << std::endl;
	std::cout << krus.connected('b', 'g') << std::endl;


	return 0;
}