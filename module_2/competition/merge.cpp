#include <memory>
#include <cstring>

template<typename T>
void simpleInsertionSort(T *arr, int p, int r)
{
    for(int i = p+1; i <= r; ++i)
    {
        T num = arr[i];
        int pos = i-1;
        while(pos >= p && arr[pos] > num)
        {
            arr[pos+1] = arr[pos];
            --pos;
        }
        arr[pos+1] = num;
    }
}

template<typename T>
int binarySearchPos(T *arr, int from, int end, const T &cmp)
{
    if(cmp >= arr[end]) return end+1;

    int pos = from;
    if(cmp > arr[from])
    {
        int right = end+1;
        int left = from;
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
void binarySearchBlockedCopyInsertion(T *arr, int p, int r)
{
    for(int i = p+1; i <= r; ++i)
    {
        T num = arr[i];
        if(num >= arr[i-1]) continue;

        int pos = binarySearchPos(arr, p, i-1, num);
        memmove(arr+pos+1, arr+pos, (i-pos)*sizeof(T));
        arr[pos] = num;
    }
}

template<typename T>
void gallopedMerge(T *arr, int p, int mid, int r)
{
    int n = mid-p+1;
    T *tmp = new T[n];
    std::memcpy(tmp, arr+p, sizeof(T)*n);

    int k{0}; // pos in tmp array
    int i{p}; // pos for insertion next element
    int j(mid+1); // current pos in second-part array
    int contFrom1 = 0;
    int contFrom2 = 0;

    while(k < n)
    {
        if(contFrom1 == 7)
        {
            int pos = binarySearchPos(tmp, k, n-1, arr[j]);
            int n_move = pos - k;
            std::memcpy(arr+i, tmp+k, sizeof(T)*n_move);
            i += n_move, k = pos;
            contFrom1 = 0, contFrom2 = 0;

            if(k >= n) break;
        }
        else if(contFrom2 == 7)
        {
            int pos = binarySearchPos(arr, j, r, tmp[k]);
            int n_move = pos - j;
            std::memcpy(arr+i, arr+j, sizeof(T)*n_move);
            i += n_move, j = pos;
            contFrom1 = 0, contFrom2 = 0;
        }
        if(j > r)
        {
            std::memmove(arr+i, tmp+k, sizeof(T)*(n-k));
            break;
        }
        else if(arr[j] < tmp[k])
        {
            arr[i] = arr[j];
            ++j, ++contFrom2, contFrom1 = 0;
        }
        else
        {
            arr[i] = tmp[k];
            ++k, ++contFrom1, contFrom2 = 0;
        }
        ++i;
    }

    delete[] tmp;
}

template<typename T>
void merge(T *arr, int p, int mid, int r)
{
    int n = mid-p+1;
    T *tmp = new T[n];
    std::memmove(tmp, arr+p, sizeof(T)*n);

    int k{0};
    int i{p};
    int j(mid+1);

    while(k < n)
    {
        if(j > r)
        {
            std::memmove(arr+i, tmp+k, sizeof(T)*(n-k));
            break;
        }
        else if(arr[j] < tmp[k])
        {
            arr[i] = arr[j];
            ++j;
        }
        else
        {
            arr[i] = tmp[k];
            ++k;
        }
        ++i;
    }

    delete[] tmp;
}

template<typename T>
void merge_insertion(T *arr, int p, int r)
{
    if(r-p <= 32)
    {
        binarySearchBlockedCopyInsertion<T>(arr, p, r);
        return;
    }

    int mid = (p+r)/2;
    merge_insertion(arr, p, mid);
    merge_insertion(arr, mid+1, r);
    merge(arr, p, mid, r);
}

void sort(BlackInt *begin, BlackInt *end){
    size_t size = end - begin;
    merge_insertion<BlackInt>(begin, 0, size-1);
}