#pragma once

namespace Sort
{
    extern void bubbleSort(int *arr, const int begin, const int end);
    extern void selectionSort(int *arr, const int begin, const int end);
    extern void insertionSort(int *arr, const int begin, const int end);
    extern void mergeSort(int *arr, const int begin, const int end);
    extern void quickSort(int *arr, const int begin, const int end);
    extern void heapSort(int *arr, const int begin, const int end);
    extern void countingSort(int *arr, const int begin, const int end);
    extern void radixSort(int *arr, const int begin, const int end);
    extern void bucketSort(int *arr, const int begin, const int end);
    extern void shellSort(int *arr, const int begin, const int end);

    extern void stdSort(int *arr, const int begin, const int end);
    extern void stdStableSort(int *arr, const int begin, const int end);

    extern void customQuickSort(int *arr, const int begin, const int end);
    extern void customRadixSort(int *arr, const int begin, const int end);

    void _heapify(int *arr, const int begin, const int end, const int i);
    void _merge(int *arr, const int begin, const int mid, const int end);
} // namespace Sort