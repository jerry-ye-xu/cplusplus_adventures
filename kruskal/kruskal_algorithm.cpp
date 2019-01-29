
#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple> 

#include "union_find_implement.h"

using namespace std;

int main(){
	vector<tuple <char, char> > instructions;
	vector<tuple <char, char> > *instruct_ptr;

	/*
	Without the last 2 instructions, the sets are:
	{e, l, f}, {i, c, d, k, j, a, b}, {g, h}
	With the last 2 instructions, the sets are:
	{e, l, f, g, h, i, c, d, k, j, a, b}
	*/
	int element_size = 12;
	instructions.push_back(make_tuple('c', 'k'));
	instructions.push_back(make_tuple('f', 'e'));
	instructions.push_back(make_tuple('a', 'j'));
	instructions.push_back(make_tuple('a', 'b'));
	instructions.push_back(make_tuple('c', 'd'));
	instructions.push_back(make_tuple('d', 'i'));
	instructions.push_back(make_tuple('l', 'f'));
	instructions.push_back(make_tuple('c', 'a'));
	instructions.push_back(make_tuple('h', 'g'));
	// instructions.push_back(make_tuple('h', 'f'));
	// instructions.push_back(make_tuple('h', 'b'));

	cout << get<0>(instructions[0]) << endl;
	cout << get<1>(instructions[0]) << endl;

	instruct_ptr = &instructions;

	// instruct_ptr =  &instructions;
	cout << get<0>((*instruct_ptr)[0]) << endl;
	cout << get<1>((*instruct_ptr)[0]) << endl;

	cout << "iterating through the *instruct_ptr" << endl;  
	for (auto ptr: *instruct_ptr){
		cout << get<0>((ptr)) << endl;
	}
	cout << "end iteration of *instruct_ptr" << endl;

	tuple<int, int> test = make_tuple(1, 3);

	cout << get<0>(test) << endl;
	cout << get<1>(test) << endl;

	return 0;
}