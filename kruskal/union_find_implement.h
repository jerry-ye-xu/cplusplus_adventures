
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifndef UNION_FIND_IMPLEMENT_H
#define UNION_FIND_IMPLEMENT_H

template <class T>
class union_find{
	public:
		union_find(int num_of_components, std::vector<std::tuple<T, T> > &union_instructions);
		~union_find();
		
		char check_root_of_elem(T element_a);
		bool connected(T element_a, T element_b);
		void join_nodes();
		
		int check_num_of_components();
		int check_num_of_unique_elements();
		

	private:
		int num_of_components;
		
		// Pointer to the instructions for the union of nodes  
		std::vector<std::tuple<T, T> > *union_instructions_ptr;

		// Mapping of elements to 
		std::unordered_map<T, int> obj_idx_dict;

		// Array of size for each ID individually. Updated everytime it 
		int *size_of_groups_ptr;

		// Array ID of objects that store it's idx of the parent. 
		int *object_id_ptr;

		// Array ID of objects that stores the idx against the element itself.
		char *object_ptr;

		std::unordered_set<T> elements_set;

		int find_root(T element_a);
		
};

#endif