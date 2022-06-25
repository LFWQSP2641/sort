#include "pch.h"
#include "Sorts.h"
#include "RandomArrayInt.h"

inline bool startWith(std::string s1, std::string s2)
{
    return s1.compare(0, s2.size(), s2) == 0;
}

int main(int argc, char* argv[])
{
    int arrayLength(10000000), randomMax(INT32_MAX);
    bool isC(false), qs(false), qso(false), rs(false), rso(false);
    for (auto i(2); i <= argc; ++i)
    {
        std::string arg(argv[i - 1]);
        if (startWith(arg, std::string("arrayLength=")))
        {
            arg.erase(0, 12);
            arrayLength = std::stoi(arg);
        }
        else if (startWith(arg, std::string("randomMax=")))
        {
            arg.erase(0, 10);
            randomMax = std::stoi(arg);
        }
        else if (arg == "qs" || arg == "\"Quick Sort\"")
        {
            isC = true;
            qs = true;
        }
        else if (arg == "qso" || arg == "\"Quick Sort(optimization)\"")
        {
            isC = true;
            qso = true;
        }
        else if (arg == "rs" || arg == "\"Radix Sort\"")
        {
            isC = true;
            rs = true;
        }
        else if (arg == "rso" || arg == "\"Radix Sort(optimization)\"")
        {
            isC = true;
            rso = true;
        }
        else
        {
            std::cout << "Unrecognized option : " << arg << std::endl;
        }
    }
    if (!isC)
    {
        qs = true;
        qso = true;
        rs = true;
        rso = true;
    }
    std::cout << "arrayLength:" << arrayLength << std::endl << "randomMax:" << randomMax << std::endl << std::endl;
    RandomArrayInt array;
    array.create(arrayLength, randomMax);
    //array.printData();

    std::cout << std::endl;

    if (qs)
    {
        std::cout << "Quick Sort" << std::endl;
        auto a = array.copy();
        auto t_start = std::chrono::high_resolution_clock::now();
        Sorts::quickSort(a, 0, array.arrayLength - 1);
        auto t_end = std::chrono::high_resolution_clock::now();
        float t_total = std::chrono::duration<float, std::milli>(t_end - t_start).count();
        std::cout << "time:" << t_total << " ms." << std::endl << std::endl;
        delete[] a;
        a = NULL;
    }

    if (qso)
    {
        std::cout << "Quick Sort(optimization)" << std::endl;
        auto a = array.copy();
        auto t_start = std::chrono::high_resolution_clock::now();
        Sorts::quickSortOptimization(a, 0, array.arrayLength - 1);
        auto t_end = std::chrono::high_resolution_clock::now();
        float t_total = std::chrono::duration<float, std::milli>(t_end - t_start).count();
        std::cout << "time:" << t_total << " ms." << std::endl << std::endl;
        delete[] a;
        a = NULL;
    }

    if (rs)
    {
        std::cout << "Radix Sort" << std::endl;
        auto a = array.copy();
        auto t_start = std::chrono::high_resolution_clock::now();
        Sorts::radixSort(a, array.arrayLength);
        auto t_end = std::chrono::high_resolution_clock::now();
        float t_total = std::chrono::duration<float, std::milli>(t_end - t_start).count();
        std::cout << "time:" << t_total << " ms." << std::endl << std::endl;
        delete[] a;
        a = NULL;
    }

    if (rso)
    {
        std::cout << "Radix Sort(optimization)" << std::endl;
        auto a = array.copy();
        auto t_start = std::chrono::high_resolution_clock::now();
        Sorts::radixSortOptimization(a, array.arrayLength);
        auto t_end = std::chrono::high_resolution_clock::now();
        float t_total = std::chrono::duration<float, std::milli>(t_end - t_start).count();
        std::cout << "time:" << t_total << " ms." << std::endl << std::endl;
        delete[] a;
        a = NULL;
    }
    std::cout << std::endl;

    //pause();
    return 0;
}