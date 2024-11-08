#include "RandomArray.h"
#include "Sort.h"

#include <chrono>
#include <iostream>

const int SIZE = 1000000;
const int MIN = 0;
const int MAX = 1000;

void testSort(void (*sort)(int *, const int, const int), const char *name)
{
    int *arr = new int[SIZE];
    RandomArray::generateRandomArray(arr, SIZE, MIN, MAX);
    auto start = std::chrono::high_resolution_clock::now();
    sort(arr, 0, SIZE);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << name << " took " << elapsed.count() << " seconds.\n";

    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            std::cout << name << " failed.\n";
            return;
        }
    }
    delete[] arr;
}

int main(int, char **)
{
    // too slow
    // testSort(Sort::bubbleSort, "Bubble Sort");
    // testSort(Sort::selectionSort, "Selection Sort");
    // testSort(Sort::insertionSort, "Insertion Sort");
    testSort(Sort::mergeSort, "Merge Sort");
    testSort(Sort::quickSort, "Quick Sort");
    testSort(Sort::heapSort, "Heap Sort");
    testSort(Sort::countingSort, "Counting Sort");
    testSort(Sort::radixSort, "Radix Sort");
    // TODO fix bug: Segmentation fault (core dumped)
    // testSort(Sort::bucketSort, "Bucket Sort");
    testSort(Sort::shellSort, "Shell Sort");
    testSort(Sort::stdSort, "std::sort");
    testSort(Sort::stdStableSort, "std::stable_sort");
    testSort(Sort::customQuickSort, "Custom Quick Sort");
    testSort(Sort::customRadixSort, "Custom Radix Sort");

    return 0;
}
