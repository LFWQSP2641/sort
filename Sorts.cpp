#include "pch.h"
#include "Sorts.h"

/*-----------------------------------Insert Sort-----------------------------------*/
void Sorts::insertSort(int arr[], const int left, const int right)
{
    // 外层循环遍历所有元素
    for (auto i = left + 1; i <= right; i++) {
        int temp = arr[i];
        auto j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


/*-----------------------------------Quick Sort-----------------------------------*/
void Sorts::quickSort(int a[], const int left, const int right)
{
    if (right - left <= 15)
    {
        Sorts::insertSort(a, left, right);
        return;
    }
    std::random_device rd;
    std::swap(a[left], a[rd() % (right - left) + left + 1]);
    const int criteria = a[left];
    int i = left, j = right;
    while (i < j)
    {
        for (; a[j] >= criteria && i < j; --j) {}
        a[i] = a[j];
        for (; a[i] <= criteria && i < j; ++i) {}
        a[j] = a[i];
    }
    a[i] = criteria;
    Sorts::quickSort(a, left, i - 1);
    Sorts::quickSort(a, i + 1, right);
}

/*-----------------------------------Quick Sort Optimization-----------------------------------*/
void Sorts::quickSortOptimization(int a[], const int left, const int right)
{
    if (right - left <= 15)
    {
        Sorts::insertSort(a, left, right);
        return;
    }
    std::random_device rd;
    std::swap(a[left], a[rd() % (right - left) + left + 1]);
    const int criteria = a[left];
    int smallerIndex(left - 1), biggerIndex(right + 1), i(left + 1), j(right);
    while (i <= j)
    {
        while (i <= j)
        {
            if (a[j] > criteria)
                a[--biggerIndex] = a[j--];
            else if (a[j] < criteria)
            {
                a[++smallerIndex] = a[j--];
                break;
            }
            else
                --j;
        }
        while (i < j)
        {
            if (a[i] < criteria)
                a[++smallerIndex] = a[i++];
            else if (a[i] > criteria)
            {
                a[--biggerIndex] = a[i++];
                break;
            }
            else
                ++i;
        }
    }
    for (auto k = smallerIndex + 1; k < biggerIndex; ++k)
    {
        a[k] = criteria;
    }
    Sorts::quickSortOptimization(a, left, smallerIndex);
    Sorts::quickSortOptimization(a, biggerIndex, right);
}

/*-----------------------------------Radix Sort-----------------------------------*/
int Sorts::maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];              // 获取最大数
    // 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
    /*    int d = 1; //保存最大的位数
        int p = 10;
        for(int i = 0; i < n; ++i)
        {
            while(data[i] >= p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;*/
}
void Sorts::radixSort(int data[], int n) //基数排序
{
    int d = Sorts::maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}

/*-----------------------------------Radix Sort Optimization-----------------------------------*/
void Sorts::radixSortOptimization(int a[], const int arrayLength)
{
    auto* ceArray = new int[arrayLength] {};
    int index[10], max(0), maxDigit(0), radix(1);
    for (auto i(0); i < arrayLength; ++i)     //获取最大值
    {
        if (a[i] > max) { max = a[i]; }
    }
    //获取最大值的位数
    for (auto num(max); num > 0; ++maxDigit)    // 判断num是否大于0，否则长度+1
        num /= 10;

    int* temp1;     //temp1----被操作
    int* temp2;     //temp2----待操作
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
    for (auto i(1); i <= maxDigit; ++i)      //开始排序
    {
        for (auto j(0); j < 10; ++j)
            index[j] = 0;
        for (auto j(0); j < arrayLength; ++j)
            ++index[(temp1[j] / radix) % 10];        //统计每个桶中的记录数
        for (auto j(1); j < 10; ++j)
            index[j] += index[j - 1];        //将index中的位置依次分配
        for (auto j(arrayLength - 1); j >= 0; --j)
            temp2[--index[(temp1[j] / radix) % 10]] = temp1[j];    //将所有桶中记录依次收集到temp2中
        std::swap(temp1, temp2);
        radix *= 10;
    }
    delete[] ceArray;
}