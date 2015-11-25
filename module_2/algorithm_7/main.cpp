#include <cstring>
#include <memory>
#include <iostream>

template<typename T>
long binarySearchPos(T *arr, long from, long end, const T &cmp)
{
    if(cmp >= arr[end]) return end+1;

    long pos = from;
    if(cmp > arr[from])
    {
        long right = end+1;
        long left = from;
        pos = (left+right)/2;
        while(arr[pos] < cmp || arr[pos-1] > cmp)
        {
            if(arr[pos] < cmp)
                left = pos;
            else
                right = pos;

            pos = (left + right) / 2;
        }
    }

    return pos;
}

template<typename T>
void binarySearchBlockedCopyInsertion(T *arr, long p, long r)
{
    for(long i = p+1; i <= r; ++i)
    {
        T num = arr[i];
        if(num >= arr[i-1]) continue;

        long pos = binarySearchPos(arr, p, i-1, num);
        memmove(arr+pos+1, arr+pos, (i-pos)*sizeof(T));
        arr[pos] = num;
    }
}

template<typename T>
void swap(T *arr, long i, long j)
{
    if(i == j) return;
    std::swap(arr[i], arr[j]);
}

template<typename T>
void partitionSmart(T *arr, long p, long r, long &q, long &t)
{
    q = p-1;
    t = p-1;
    T x = arr[r];
    for(long j = p; j < r; ++j)
    {
        if(arr[j] <= x)
        {
            ++t;
            if(arr[j] == x)
                swap<T>(arr, j, t);
            else
            {
                ++q;
                swap<T>(arr, j, q);
                if(q != t)
                    swap<T>(arr, t, j);
            }
        }
    }
    ++q;
    ++t;
    swap<T>(arr, r, t);
}

template<typename T>
long middle(T *arr, long i1, long i2, long i3)
{
    long mid = i1;
    long min = i2;
    long max = i3;
    if(arr[min] > arr[max]) std::swap(min, max);
    if(arr[min] > arr[mid]) std::swap(min, mid);
    if(arr[mid] > arr[max]) std::swap(mid, max);
    return mid;
}

template<typename T>
void randPartitionSmart(T *arr, long p, long r, long &q, long &t)
{
    long ind1 = p + rand() % (r-p);
    long ind2 = p + rand() % (r-p);
    long ind3 = p + rand() % (r-p);
    long mid = middle<T>(arr, ind1, ind2, ind3);
    swap<T>(arr, r, mid);
    partitionSmart<T>(arr, p, r, q, t);
}

template<typename T>
void smartPartitionQuickSortVarN(T *arr, long p, long r, long N = 0)
{
    if(r-p <= N)
    {
        binarySearchBlockedCopyInsertion<T>(arr, p, r);
        return;
    }

    long q, t;
    while(p < r)
    {
        randPartitionSmart<T>(arr, p, r, q, t);
        smartPartitionQuickSortVarN<T>(arr, p, q-1, N);
        p = t+1;
    }
}

template<typename T>
void blah(T *arr, long p, long r)
{
    if(r-p <= 138)
    {
        binarySearchBlockedCopyInsertion<T>(arr, p, r);
        return;
    }

    long q, t;
    while(p < r)
    {
        randPartitionSmart<T>(arr, p, r, q, t);
        blah<T>(arr, p, q-1);
        p = t+1;
    }
}

void FastSort(int* vector, int n) {
    blah<int>(vector, 0, n - 1);
}