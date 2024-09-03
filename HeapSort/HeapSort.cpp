#include <iostream>
#include "HeapSort.hpp"


#define DUMMY_LENGTH 10
int main()
{
    //Create an array with 64 random values which at most may be 0xff -> 255
    NUMTYPE* dummy = create_dummy_array(DUMMY_LENGTH);

    
    
    std::printf("Before sort: \n");
    print_numtype_array(dummy);
    
    NUMTYPE watch[DUMMY_LENGTH];
    memset(watch, 0, sizeof(NUMTYPE) * DUMMY_LENGTH);
    memcpy(watch, dummy, sizeof(NUMTYPE) * DUMMY_LENGTH);

    //Heap sort it
    heap_sort(dummy, DUMMY_LENGTH);

    std::printf("\nAfter sort: \n");
    print_numtype_array(dummy);    
}


static void print_numtype_array(NUMTYPE* arr) {
    std::printf("[");
    while(*arr)
        std::printf("%d " , *arr++);
    std::printf("]\n");
}

static NUMTYPE * create_dummy_array(size_t size, uint32_t max) {
    std::srand(std::time(nullptr));

    NUMTYPE * array_to_sort = nullptr;
    array_to_sort = (NUMTYPE*)malloc(sizeof(NUMTYPE) * size);

    for(size_t i = 0; i < size; i++) {
        array_to_sort[i] = std::rand() % max;
        //std::cout << "[" << i << "] => " << array_to_sort[i] << std::endl;
    }
    return array_to_sort;
}

static void build_heap(NUMTYPE * elements, size_t length) {
    size_t lastParentNode = length / 2 - 1;

    for (int i = static_cast<int>(lastParentNode); i >= 0; i--)
        heapify(elements, length, i);
}

static void xor_swap_arr(NUMTYPE * arr, size_t idxA, size_t idxB) {
    arr[idxA] ^= arr[idxB];
    arr[idxB] ^= arr[idxA];
    arr[idxA] ^= arr[idxB];
    std::printf("Swapped arr[%d] (%d) with arr[%d] (%d)\n", idxA, arr[idxA], idxB, arr[idxB]);
}

static void heapify(NUMTYPE* heap, size_t length, NUMTYPE parentIdx) {
    while (true) {

        size_t leftChildIdx = static_cast<size_t>(parentIdx) * 2 + 1;
        size_t rightChildIdx = static_cast<size_t>(parentIdx) * 2 + 2;
        size_t largestIdx = parentIdx;

        //If left child is larger than root
        if (leftChildIdx < length && heap[leftChildIdx] > heap[largestIdx])
            largestIdx = leftChildIdx;

        //If right is larger than largest so far
        if (rightChildIdx < length && heap[rightChildIdx] > heap[largestIdx])
            largestIdx = rightChildIdx;

        //If largest is not root
        if (largestIdx == parentIdx) {
            xor_swap_arr(heap, parentIdx, largestIdx);

            //Reheapicursively heapify subtree
            heapify(heap, length, largestIdx);
        }
    }
}

static void heap_sort(NUMTYPE* elements, size_t length) {
    build_heap(elements, length);

    for (size_t swapToIdx = length - 1; swapToIdx > 0; swapToIdx--) {
        xor_swap_arr(elements, 0, swapToIdx);
        heapify(elements, length, 0);
    }
}
