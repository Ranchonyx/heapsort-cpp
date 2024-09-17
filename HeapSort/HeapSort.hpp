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
#define ulong unsigned long
#define insert push_back

vector<int> CreateDummyArray(size_t size, ulong max = 0xffffffff);

void SwapInt(ArrayList& arr, size_t idxA, size_t idxB);

void HeapSort(ArrayList& elements);
void BuildHeap(ArrayList& elements);
void Heapify(ArrayList& heap, int size, int parentIdx);

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

void PrintArray(ArrayList& arr) {
	printf("[");

	for (size_t i = 0; i < arr.size(); i++)
		printf("%u ", arr[i]);

	printf("]\n\n");
}

#endif