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

#define ArrayList vector<int>

#define insert push_back

vector<int> create_dummy_array(size_t size, uint64_t max = 0xffffffff);

void optimized_int_swap(ArrayList& arr, size_t idxA, size_t idxB);

void heap_sort(ArrayList& elements);
void build_heap(ArrayList& elements);
void heapify(ArrayList& heap, int size, int parentIdx);

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

void print_vector(ArrayList& arr) {
	printf("[");

	for (size_t i = 0; i < arr.size(); i++)
		printf("%u ", arr[i]);

	printf("]\n");
}

#endif