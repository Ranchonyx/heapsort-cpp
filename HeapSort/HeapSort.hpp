#ifndef _HEAP_SORT_HPP_
#define _HEAP_SORT_HPP_

// includes for createDummyArray(size_t size);
#include <cstdlib>
#include <ctime>

#define NUMTYPE uint32_t

static void print_numtype_array(NUMTYPE* arr);
static NUMTYPE* create_dummy_array(size_t size, uint32_t max = 0xff);
static void build_heap(NUMTYPE* elements, size_t length);
static void xor_swap_arr(NUMTYPE * arr, size_t idxA, size_t idxB);
static void heapify(NUMTYPE* heap, size_t length, NUMTYPE parentIdx);
static void heap_sort(NUMTYPE* elements, size_t length);

#endif