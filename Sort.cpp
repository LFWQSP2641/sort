#include "Sort.h"

#include <algorithm>
#include <random>
#include <vector>

void Sort::bubbleSort(int *arr, const int begin, const int end)
{
    for (int i = begin; i < end - 1; ++i)
    {
        for (int j = begin; j < end - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort::selectionSort(int *arr, const int begin, const int end)
{
    for (int i = begin; i < end - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < end; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void Sort::insertionSort(int *arr, const int begin, const int end)
{
    for (int i = begin + 1; i < end; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= begin && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void Sort::mergeSort(int *arr, const int begin, const int end)
{
    if (end - begin > 1)
    {
        int mid = begin + (end - begin) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid, end);
        _merge(arr, begin, mid, end);
    }
}

void Sort::quickSort(int *arr, const int begin, const int end)
{
    if (end - begin > 1)
    {
        int pivot = arr[end - 1];
        int i = begin - 1;
        for (int j = begin; j < end - 1; ++j)
        {
            if (arr[j] < pivot)
            {
                std::swap(arr[++i], arr[j]);
            }
        }
        std::swap(arr[++i], arr[end - 1]);
        quickSort(arr, begin, i);
        quickSort(arr, i + 1, end);
    }
}

void Sort::heapSort(int *arr, const int begin, const int end)
{
    for (int i = end / 2 - 1; i >= begin; --i)
    {
        _heapify(arr, begin, end, i);
    }
    for (int i = end - 1; i > begin; --i)
    {
        std::swap(arr[begin], arr[i]);
        _heapify(arr, begin, i, begin);
    }
}

void Sort::countingSort(int *arr, const int begin, const int end)
{
    int max = *std::max_element(arr + begin, arr + end);
    int min = *std::min_element(arr + begin, arr + end);
    int range = max - min + 1;

    std::vector<int> count(range);
    std::vector<int> output(end - begin);

    for (int i = begin; i < end; ++i)
    {
        ++count[arr[i] - min];
    }
    for (int i = 1; i < range; ++i)
    {
        count[i] += count[i - 1];
    }
    for (int i = end - 1; i >= begin; --i)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        --count[arr[i] - min];
    }
    for (int i = begin, j = 0; i < end; ++i, ++j)
    {
        arr[i] = output[j];
    }
}

void Sort::radixSort(int *arr, const int begin, const int end)
{
    int max = *std::max_element(arr + begin, arr + end);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, begin, end);
    }
}

void Sort::bucketSort(int *arr, const int begin, const int end)
{
    int max = *std::max_element(arr + begin, arr + end);
    int min = *std::min_element(arr + begin, arr + end);
    int range = max - min + 1;

    std::vector<std::vector<int>> buckets(range);
    for (int i = begin; i < end; ++i)
    {
        buckets[(arr[i] - min) * range / (max - min + 1)].push_back(arr[i]);
    }
    for (int i = 0; i < range; ++i)
    {
        std::sort(buckets[i].begin(), buckets[i].end());
    }
    for (int i = 0, j = begin; i < range; ++i)
    {
        for (int k = 0; k < buckets[i].size(); ++k)
        {
            arr[j++] = buckets[i][k];
        }
    }
}

void Sort::shellSort(int *arr, const int begin, const int end)
{
    for (int gap = (end - begin) / 2; gap > 0; gap /= 2)
    {
        for (int i = begin + gap; i < end; ++i)
        {
            int key = arr[i];
            int j = i;
            while (j >= begin + gap && arr[j - gap] > key)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}

void Sort::stdSort(int *arr, const int begin, const int end)
{
    std::sort(arr + begin, arr + end);
}

void Sort::stdStableSort(int *arr, const int begin, const int end)
{
    std::stable_sort(arr + begin, arr + end);
}

void Sort::customQuickSort(int *arr, const int begin, const int end)
{
    const auto right = end - 1;
    const auto left = begin;
    if (right - left <= 15)
    {
        Sort::insertionSort(arr, left, right + 1);
        return;
    }
    std::random_device rd;
    std::swap(arr[left], arr[rd() % (right - left) + left + 1]);
    const int criteria = arr[left];
    int smallerIndex(left - 1), biggerIndex(right + 1), i(left + 1), j(right);
    while (i <= j)
    {
        while (i <= j)
        {
            if (arr[j] > criteria)
                arr[--biggerIndex] = arr[j--];
            else if (arr[j] < criteria)
            {
                arr[++smallerIndex] = arr[j--];
                break;
            }
            else
                --j;
        }
        while (i < j)
        {
            if (arr[i] < criteria)
                arr[++smallerIndex] = arr[i++];
            else if (arr[i] > criteria)
            {
                arr[--biggerIndex] = arr[i++];
                break;
            }
            else
                ++i;
        }
    }
    for (auto k = smallerIndex + 1; k < biggerIndex; ++k)
    {
        arr[k] = criteria;
    }
    Sort::customQuickSort(arr, left, smallerIndex + 1);
    Sort::customQuickSort(arr, biggerIndex, right + 1);
}

void Sort::customRadixSort(int *arr, const int begin, const int end)
{
    const auto arrayLength = end - begin;
    auto *a = arr + begin;
    auto *ceArray = new int[arrayLength]{};
    int index[10], max(0), maxDigit(0), radix(1);
    for (auto i(0); i < arrayLength; ++i) // 获取最大值
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    // 获取最大值的位数
    for (auto num(max); num > 0; ++maxDigit) // 判断num是否大于0，否则长度+1
        num /= 10;

    int *temp1; // temp1----被操作
    int *temp2; // temp2----待操作
    if (maxDigit % 2)
    {
        for (auto i(0); i < arrayLength; ++i)
            ceArray[i] = a[i];
        temp1 = ceArray;
        temp2 = a;
    }
    else
    {
        temp1 = a;
        temp2 = ceArray;
    }
    for (auto i(1); i <= maxDigit; ++i) // 开始排序
    {
        for (auto j(0); j < 10; ++j)
            index[j] = 0;
        for (auto j(0); j < arrayLength; ++j)
            ++index[(temp1[j] / radix) % 10]; // 统计每个桶中的记录数
        for (auto j(1); j < 10; ++j)
            index[j] += index[j - 1]; // 将index中的位置依次分配
        for (auto j(arrayLength - 1); j >= 0; --j)
            temp2[--index[(temp1[j] / radix) % 10]] = temp1[j]; // 将所有桶中记录依次收集到temp2中
        std::swap(temp1, temp2);
        radix *= 10;
    }
    delete[] ceArray;
}

void Sort::_heapify(int *arr, const int begin, const int end, const int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < end && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < end && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        _heapify(arr, begin, end, largest);
    }
}

void Sort::_merge(int *arr, const int begin, const int mid, const int end)
{
    int n1 = mid - begin;
    int n2 = end - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; ++i)
    {
        left[i] = arr[begin + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        right[i] = arr[mid + i];
    }

    int i = 0, j = 0, k = begin;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}