#ifndef _HEAP_SORT_HPP_
#define _HEAP_SORT_HPP_

// includes for createDummyArray(size_t size);
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <chrono>
#include <set>
#include <thread>

using namespace std;

#define Vec vector<int>
#define VecRef Vec&

vector<int> create_dummy_array(size_t size, uint64_t max = 0xffffffff);

void optimized_int_swap(VecRef arr, size_t idxA, size_t idxB);

void heap_sort(VecRef elements);
void build_heap(VecRef elements);
void heapify(VecRef heap, int size, int parentIdx);

void print(std::string s) {
	cout << s << endl;
}

void print(char* c_str) {
	while (*c_str)
	{
		cout << *c_str++;
	}
	cout << endl;
}

#endif