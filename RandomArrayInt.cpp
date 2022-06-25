#include "pch.h"
#include "RandomArrayInt.h"

RandomArrayInt::RandomArrayInt()
{
    this->data = NULL;
    this->arrayLength = -1;
    this->randomMax = -1;
    this->randomMin = -1;
}

RandomArrayInt::~RandomArrayInt()
{
    this->deleteData();
}

void RandomArrayInt::deleteData()
{
    delete[] data;
    data = NULL;
}

void RandomArrayInt::reset(const int len, const int max, const int min, int* prtToData)
{
    delete[] data;
    this->data = prtToData;
    this->arrayLength = len;
    this->randomMax = max;
    this->randomMin = min;
}

void RandomArrayInt::create(const int len, const int max, const int min)
{
    this->arrayLength = len;
    this->data = new int[len];
    this->randomMax = max;
    this->randomMin = min;

    std::random_device rd;
    std::uniform_int_distribution<> undis(min, max);
    std::default_random_engine re(rd());
    for (auto i(0); i < len; ++i)
        this->data[i] = undis(re);
}

void RandomArrayInt::recreate()
{
    if (this->arrayLength <= 0 || this->randomMax < 0 || this->randomMin < 0) { throw; };

    std::random_device rd;
    std::uniform_int_distribution<> undis(this->randomMin, this->randomMax);
    std::default_random_engine re(rd());
    for (auto i(0); i < this->arrayLength; ++i)
        this->data[i] = undis(re);
}

void RandomArrayInt::printData()
{
    if (this->data == NULL) { throw std::logic_error(""); }

    for (auto i(0); i < this->arrayLength; ++i)
    {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}

void RandomArrayInt::copyTo(RandomArrayInt array)
{
    if (this->arrayLength <= 0 || this->randomMax < 0 || this->randomMin < 0 || this->data == NULL) { throw std::logic_error(""); };

    array.arrayLength = this->arrayLength;
    array.randomMax = this->randomMax;
    array.randomMin = this->randomMin;
    array.deleteData();

    array.data = new int[this->arrayLength];
    for (auto i(0); i < this->arrayLength; ++i)
        array.data[i] = this->data[i];
}

int* RandomArrayInt::copy()
{
    if (this->data == NULL) { throw std::logic_error(""); }

    auto* temp = new int[this->arrayLength];
    for (auto i(0); i < this->arrayLength; ++i)
    {
        temp[i] = data[i];
    }
    return temp;
}
