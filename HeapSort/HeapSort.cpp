#include <iostream>
#include <chrono>
#include <set>
#include <thread>
#include "HeapSort.hpp"

void print_vector(VecRef arr) {
    std::printf("[");

    for (size_t i = 0; i < arr.size(); i++)
        std::printf("%u ", arr[i]);

    std::printf("]\n");
}

Vec create_dummy_array(size_t size, uint32_t max) {
    std::srand(std::time(nullptr));

    std::set<int> uniques;

    while ((uniques.size()) != size) {
        uniques.insert(std::rand() % max);
    }

    Vec uniques_vector(uniques.begin(), uniques.end());

    return uniques_vector;
}

//Swap two integer numbers in a vector using XOR
void optimized_int_swap(VecRef arr, size_t idxA, size_t idxB) {
    arr[idxA] ^= arr[idxB];
    arr[idxB] ^= arr[idxA];
    arr[idxA] ^= arr[idxB];

    //std::cout << "Swapped arr[" << idxA << "]" << " (" << arr[idxA] << ") with arr[" << idxB << "] (" << arr[idxB] << ")" << std::endl;
}

void build_heap(VecRef heap) {
    int heap_sz = heap.size();

    for (int i = (heap_sz / 2) - 1; i >= 0; i--) {
        heapify(heap, heap_sz, i);
    }
}

void heapify(VecRef heap, int size, int parentIdx) {
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
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //print_vector(heap);
        optimized_int_swap(heap, parentIdx, largestIdx);

        //Recursively heapify subtree
        heapify(heap, size, largestIdx);
    }
}

void heap_sort(VecRef elements) {
    build_heap(elements);

    int heap_sz = elements.size();
    for (int i = heap_sz - 1; i > 0; i--) {
        optimized_int_swap(elements, 0, i);

        heapify(elements, i, 0);
    }
}

int main() {

    int n_dummy = 16;
    Vec dummy = create_dummy_array(n_dummy, 0xff);

    std::cout << "Before sort" << std::endl;
    print_vector(dummy);
    std::cout << std::endl;

    const auto t0 = std::chrono::high_resolution_clock::now();
    heap_sort(dummy);
    const auto t1 = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> dur{ t1 - t0 };

    std::cout << "After sort" << std::endl;
    print_vector(dummy);
    std::cout << "heap_sort(arr(" << n_dummy << ")) took " << dur.count() << " s" << std::endl;
}