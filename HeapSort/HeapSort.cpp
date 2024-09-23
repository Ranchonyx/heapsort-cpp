#include "HeapSort.hpp"


ArrayList CreateDummyArray(size_t size, unsigned long max) {
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
void SwapInt(ArrayList& arr, size_t idxA, size_t idxB) {
    printf("swapped index %i (%i) with index %i (%i) \n", idxA, arr[idxA], idxB, arr[idxB]);
    arr[idxA] ^= arr[idxB];
    arr[idxB] ^= arr[idxA];
    arr[idxA] ^= arr[idxB];
}

void BuildHeap(ArrayList& heap) {
    int heap_sz = heap.size();

    for (int i = (heap_sz / 2) - 1; i >= 0; i--) {
        Heapify(heap, heap_sz, i);
    }
}

void Heapify(ArrayList& heap, int size, int parentIdx) {
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
        SwapInt(heap, parentIdx, largestIdx);

        //Recursively heapify subtree
        Heapify(heap, size, largestIdx);
    }
}

void HeapSort(ArrayList& elements) {
    BuildHeap(elements);

    int heap_sz = elements.size();
    for (int i = heap_sz - 1; i > 0; i--) {
        SwapInt(elements, 0, i);

        Heapify(elements, i, 0);
    }
}

int main() {
    int dummy_len = 16;
    ArrayList dummy = CreateDummyArray(dummy_len, 0xff);

    print("Before sort");
    PrintArray(dummy);

    const auto t0 = chrono::high_resolution_clock::now();
    HeapSort(dummy);
    const auto t1 = chrono::high_resolution_clock::now();

    const chrono::duration<double> dur{ t1 - t0 };

    print("After sort");
    PrintArray(dummy);
    printf("heap_sort(arr(%i)) took %f s\n", dummy_len, dur.count());
}