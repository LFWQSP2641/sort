#pragma once

class RandomArrayInt
{
public:
    RandomArrayInt();
    ~RandomArrayInt();
    void deleteData();
    void reset(const int len = -1, const int max = -1, const int min = -1, int* prtToData = NULL);
    void create(const int len, const int max = INT32_MAX, const int min = 0);
    void recreate();
    void printData();
    void copyTo(RandomArrayInt array);
    int* copy();
    int* data;
    int arrayLength;
    int randomMax;
    int randomMin;
private:
};

