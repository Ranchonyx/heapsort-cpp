#include "HeapSort.hpp"



ArrayList create_dummy_array(size_t size, uint64_t max) {
    // set a random seed for srand
    srand(time(nullptr));
    ArrayList dummy;

    // fill the dummy
    for( int i = 0; i < size; i++) {
        dummy.insert(rand() % max);
    }

    return dummy;
}

//Swap two integer numbers in a vector using XOR
void optimized_int_swap(ArrayList& arr, size_t idxA, size_t idxB) {
    arr[idxA] ^= arr[idxB];
    arr[idxB] ^= arr[idxA];
    arr[idxA] ^= arr[idxB];
}

void build_heap(ArrayList& heap) {
    int heap_sz = heap.size();

    for (int i = (heap_sz / 2) - 1; i >= 0; i--) {
        heapify(heap, heap_sz, i);
    }
}

void heapify(ArrayList& heap, int size, int parentIdx) {
    size_t largestIdx = parentIdx; //Largest is the (sub)tree root
    size_t leftChildIdx = static_cast<size_t>(parentIdx) * 2 + 1; //Left position is 2 * parentIdx + 1
    size_t rightChildIdx = static_cast<size_t>(parentIdx) * 2 + 2; //Right position is 2 * parentIdx + 2

    //If left child is larger than root
    if (leftChildIdx < size && heap[leftChildIdx] > heap[largestIdx])
        largestIdx = leftChildIdx;

    //If right is larger than largest so far
    if (rightChildIdx < size && heap[rightChildIdx] > heap[largestIdx])
        largestIdx = rightChildIdx;

    //If largest is not root
    if (largestIdx != parentIdx) {
        optimized_int_swap(heap, parentIdx, largestIdx);

        //Recursively heapify subtree
        heapify(heap, size, largestIdx);
    }
}

void heap_sort(ArrayList& elements) {
    build_heap(elements);

    int heap_sz = elements.size();
    for (int i = heap_sz - 1; i > 0; i--) {
        optimized_int_swap(elements, 0, i);

        heapify(elements, i, 0);
    }
}

int main() {

    int dummy_len = 16;
    ArrayList dummy = create_dummy_array(dummy_len, 0xff);

    print("Before sort");
    print_vector(dummy);
    print("");

    const auto t0 = chrono::high_resolution_clock::now();
    heap_sort(dummy);
    const auto t1 = chrono::high_resolution_clock::now();

    const chrono::duration<double> dur{ t1 - t0 };

    print("After sort");
    print_vector(dummy);
    printf("\nheap_sort(arr(%i)) took %f s\n", dummy_len, dur.count());
}