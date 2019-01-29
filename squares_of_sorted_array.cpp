
#include <iostream>
#include "search_algos/binary_search_implement.h"

using namespace std;

int find_split_point(int array[], int size);
int* squares_of_sorted_array(int array[], int size);

int main(){

	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	int array2[] = {-34, -27, -10, -1, 0, 3, 8, 12, 19};
	int array3[] = {-50, -4, -13, -9, 2, 12, 17, 50, 52};
	int empty_array[] = {};

	cout << find_split_point(array2, 9) << endl;
	cout << find_split_point(array3, 9) << endl;

	cout << binary_search_implement(1, array, 0, 24) << endl;
	cout << binary_search_implement(2, array, 0, 24) << endl;
	cout << binary_search_implement(13, array, 0, 24) << endl;
	cout << binary_search_implement(20, array, 0, 24) << endl;
	cout << binary_search_implement(24, array, 0, 24) << endl;
	cout << binary_search_implement(25, array, 0, 24) << endl;

	int size2 = 9;
	int* sort2 = squares_of_sorted_array(array3, size2);
	// squares_of_sorted_array(empty_array, 0);

	for (int i=0; i<size2; i++){
		cout << sort2[i] << endl;
	}

	return 0;
}

int* squares_of_sorted_array(int array[], int size){
	if (size==0){
		cout << "Array is empty." << endl;
		return 0;
	}

	if (array[0] >= 0){
		for(int i=0; i < size; i++){
			array[i] *= array[i];
		}
		return array;
	}

	int* return_array = new int[size];  
	int return_array_idx = 0;

	if (array[size-1] < 0){
		for(int i=size; i > 0; i--){
			return_array[size-i] = array[i] * array[i];
		}
	}

	int right_ptr = find_split_point(array, size);
	int left_ptr = right_ptr - 1;

	cout << "right_ptr is: " << right_ptr << endl;

	while(right_ptr < size & left_ptr >= 0){
		if(array[right_ptr] * array[right_ptr] < array[left_ptr] * array[left_ptr]){
			return_array[return_array_idx++] = array[right_ptr] * array[right_ptr];
			right_ptr++;
		} else {
			// cout << "left_ptr is: " << left_ptr << " with array value " << return_array[return_array_idx-1] << endl;
			return_array[return_array_idx++] = array[left_ptr] * array[left_ptr];
			left_ptr--;
		}
	}

	while(right_ptr < size){
		return_array[return_array_idx++] = array[right_ptr] * array[right_ptr];
		right_ptr++;
	}

	while(left_ptr >= 0){
		return_array[return_array_idx++] = array[left_ptr] * array[left_ptr];
		left_ptr--;
	}
	
	return return_array;
}

/*
Returns the index of the first positive integer in the array. 
*/
int find_split_point(int array[], int size){
	int split_idx = 0;

	while(array[split_idx] < 0){
		cout << split_idx << endl;
		split_idx++;
	}

	return split_idx;
}

// g++ -std=c++11 -o squares_of_sorted_array squares_of_sorted_array.cpp search_algos/binary_search_implement.cpp