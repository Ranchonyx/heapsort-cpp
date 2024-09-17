#ifndef _HEAP_SORT_HPP_
#define _HEAP_SORT_HPP_

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <chrono>
#include <set>
#include <thread>

#define Vec std::vector<int>
#define VecRef Vec&

std::vector<int> create_dummy_array(size_t size, uint64_t max = 0xffffffff);

void optimized_int_swap(VecRef arr, size_t idxA, size_t idxB);

void heap_sort(VecRef elements);
void build_heap(VecRef elements);
void heapify(VecRef heap, int size, int parentIdx);

void print_vector(VecRef arr) {
    std::printf("[");

    for (size_t i = 0; i < arr.size(); i++)
        std::printf("%u ", arr[i]);

    std::printf("]\n");
}


#endif