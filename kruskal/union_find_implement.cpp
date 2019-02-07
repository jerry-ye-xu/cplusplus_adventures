
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "union_find_implement.h"

template <class T>
union_find<T>::union_find(int num_of_components, std::vector<std::tuple<T, T> > &union_instructions){

	this->num_of_components = num_of_components;
	this->union_instructions_ptr = &union_instructions;
	size_of_groups_ptr = new int[this->num_of_components];
	object_id_ptr 	   = new int[this->num_of_components];
	object_ptr         = new char[this->num_of_components];

	/*
	First we create a set of unique elements, and then
	auto map them to an index. Then, we create and set the ID array to the correct index and
	initialise the size of each group to 1. 
	*/
	for(auto instruct : *union_instructions_ptr){
		this->elements_set.insert(std::get<0>(instruct));
		this->elements_set.insert(std::get<1>(instruct));
	}
	
	int idx = 0;
	for(auto elem : elements_set){
		obj_idx_dict[elem] = idx;
		object_id_ptr[idx] = idx;
		object_ptr[idx] = elem;
		size_of_groups_ptr[idx++] = 1; // initialise size of each group to 1. 
	}
}

template <class T>
union_find<T>::~union_find(){
	delete [] size_of_groups_ptr;
	delete [] object_id_ptr;
}

template <class T>
int union_find<T>::find_root(T element_a){
	int a_idx = obj_idx_dict[element_a];

	int root_idx = a_idx;
	while(root_idx != object_id_ptr[root_idx]){
		root_idx = object_id_ptr[root_idx];
	}

	/* 
	Compress the node path such that it becomes an amortised O(1);
	*/
	while(a_idx != root_idx){
		int next_idx = object_id_ptr[a_idx];
		object_id_ptr[a_idx] = root_idx;
		a_idx = next_idx;
	}

	return root_idx;
}
	
template <class T>
bool union_find<T>::connected(T element_a, T element_b){
	return (find_root(element_a) == find_root(element_b));
}

template <class T>
void union_find<T>::join_nodes(){
	for(auto instruct: *union_instructions_ptr){
		std::cout << "join(" << std::get<0>(instruct) << ", " << std::get<1>(instruct) << ")" << std::endl;

		/* 
		CAN'T JUST SEARCH FOR DIRECT NODE! SOMETIMES THE CONNECTION TO THE ROOT NODE
		IS MULTI-EDGED. HENCE YOU MUST SEARCH FOR THE ROOT NODE EVERYTIME OTHERWISE YOU
		WILL END UP IN A INFINITE-LOOP. 
		*/
		int idx_a = find_root(std::get<0>(instruct));
		int idx_b = find_root(std::get<1>(instruct));

		if (idx_a == idx_b){
			return;
		}

		if(size_of_groups_ptr[idx_a] < size_of_groups_ptr[idx_b]){
			size_of_groups_ptr[idx_b] += size_of_groups_ptr[idx_a];
			object_id_ptr[idx_a] = idx_b;
		} else {
			size_of_groups_ptr[idx_a] += size_of_groups_ptr[idx_b];
			object_id_ptr[idx_b] = idx_a;			
		}
	}
}

template <class T>
char union_find<T>::check_root_of_elem(T element_a){
	int idx = find_root(element_a);

	return object_ptr[idx];
}

template <class T>
int union_find<T>::check_num_of_components(){
	return num_of_components;
}

template <class T> 
int union_find<T>::check_num_of_unique_elements(){
	return elements_set.size();
}

/* 
PRIVATE METHODS
*/

template class union_find<char>;