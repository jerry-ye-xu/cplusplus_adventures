
#include <iostream>
#include <vector>
#include <unordered_map>

template <class T>
union_find<T>::union_find(int num_of_components, vector<tuple<T, T> > &union_instructions) 
	num_of_components(num_of_components), 
	union_instructions_ptr(union_instructions) 
	{ 

	/*
	First we create a set of unique elements, and then
	auto map them to an index. Then, we create and set the ID array to the correct index and
	initialise the size of each group to 1. 
	*/
	for(auto instruct : *union_instructions_ptr){
		this->elements_set.insert(get<0>(instruct));
		this->elements_set.insert(get<1>(instruct));
	}
	
	int idx = 0;
	for(auto elem : elements_set){
		obj_idx_dict[elem] = idx;
		object_id[idx] = idx;
		size_of_groups[idx++] = 1; // initialise size of each group to 1. 
	}
}

template <class T>
int union_find<T>::find_root(T element_a){
	int a_idx = obj_idx_dict[element_a]

	root_idx = a_idx;
	while(root_idx != object_id[root_idx]){
		root_idx = object_id[root_idx];
	}

	/* 
	Compress the node path such that it becomes an amortised O(1);
	*/
	while(a_idx != root_idx){
		int next_idx = object_id[a_idx];
		object_id[a_idx] = root_idx;
		a_idx = next_idx;
	}

	return root;
}
	
template <class T>
bool union_find<T>::connected(T element_a, T element_b){
	return (find_root(element_a) == find_root(element_b));
}

template <class T>
void union_find<T>::join_nodes(){
	for(auto instruct: *union_instructions_ptr){
		std::cout << "join(" << get<0>(instruct) << ", " << get<1>(instruct) << endl;

		/* 
		CAN'T JUST SEARCH FOR DIRECT NODE! SOMETIMES THE CONNECTION TO THE ROOT NODE
		IS MULTI-EDGED. HENCE YOU MUST SEARCH FOR THE ROOT NODE EVERYTIME OTHERWISE YOU
		WILL END UP IN A INFINITE-LOOP. 
		*/
		int idx_a = find_root(get<0>(instruct))
		int idx_b = find_root(get<1>(instruct));

		if (idx_a == idx_b){
			return;
		}

		if(size_of_groups[idx_a] < size_of_groups[idx_b]){
			size_of_groups[idx_b] += size_of_groups[idx_a];
			object_id[idx_a] = idx_b;
		} else {
			size_of_groups[idx_a] += size_of_groups[idx_b];
			object_id[idx_b] = idx_a;			
		}
	}
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