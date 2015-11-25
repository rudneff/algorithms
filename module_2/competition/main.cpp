#include <stdlib.h>
#include <algorithm>
#include <iostream>

template <class T>
void quick_sort(T *a, int n) {
    int i = 0;
    int j = n - 1;
    bool side = 0;
    while (i != j) {
        if (a[i] > a[j]) {
            std::swap(a[i], a[j]);
            side = !side;
        }
        if (side) {
            ++i;
        } else {
            --j;
        }
    }
    if (i > 1) quick_sort<T>(a, i);
    if (n > i + 1) quick_sort<T>(a + (i + 1), n - (i + 1));
}

void sort(BlackInt *begin, BlackInt *end){
    size_t size = end - begin;
    quick_sort<BlackInt>(begin, size);
}

//int main(){
//    int a[10] = {9, 43, 3, 2, 34, 43, 545, 45, 45, 23434};
//    quick_sort<int>(a, 10);
//    for (int i = 0; i < 10; ++i)
//    {
//        std::cout << a[i] << " ";
//    }
//}