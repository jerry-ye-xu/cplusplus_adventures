
#include <iostream>

#ifndef BINARY_SEARCH_IMPLEMENT_H
#define BINARY_SEARCH_IMPLEMENT_H

int binary_search_implement(int target, int array[], int left, int right){
	int mid = (left+right)/2;

	if(array[mid] < target){
		std::cout << "idx: " << mid << std::endl;
		return binary_search_implement(target, array, mid+1, right);
	} else if(array[mid] > target){
		std::cout << "idx: " << mid << std::endl;
		return binary_search_implement(target, array, left, mid-1);
	}

	if(array[mid] == target){
		return mid;
	} else {
		std::cout << "Failed to find target." << std::endl;
		return -1;
	}
}

#endif