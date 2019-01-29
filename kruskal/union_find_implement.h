
#include <iostream>
#include <vector>
#include <unordered_map>

#ifndef UNION_FIND_IMPLEMENT_H
#define UNION_FIND_IMPLEMENT_H

template class<T>
class union_find{
	public:
		union_find(int num_of_components, vector<tuple<T, T> > &union_instructions);
		
		int find_root(T element_a);
		bool connected(T element_a, T element_b);
		void join_nodes();
		
		int check_num_of_objects();
		int check_num_of_unique_elements();
		

	private:
		int num_of_components;
		
		// Pointer to the instructions for the union of nodes  
		T *union_instructions_ptr;

		// Mapping of elements to 
		unordered_map<T, int> obj_idx_dict;

		// Array of size for each ID individually. Updated everytime it 
		int size_of_groups[num_of_components];

		// Array ID of objects that store it's idx of the parent. 
		int object_id[num_of_components];

		unordered_set<T> elements_set;
		
};

#endif