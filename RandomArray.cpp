#include "RandomArray.h"

#include <random>

void RandomArray::generateRandomArray(int *arr, int size, int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < size; ++i)
    {
        arr[i] = dis(gen);
    }
}