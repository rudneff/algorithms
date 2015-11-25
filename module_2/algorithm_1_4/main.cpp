#include <iostream>
#include <cstring>


const int NMAX = 256;

void insertion_sort(char arr[][NMAX], int n, bool (*is_greater)(const char* a, const char* b));
bool is_greater(const char *a, const char *b);
int main() {

    int n;
    std::cin >> n;
    char str_arr[n][NMAX];

    for (int i = 0; i < n; ++i) {
        std::memset(&str_arr, 0, NMAX);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> str_arr[i];
    }

    insertion_sort(str_arr, n, is_greater);

    for (int i = 0; i < n; ++i) {
        std::cout << str_arr[i] << std::endl;
    }

}

bool is_greater(const char *a, const char *b) {
    return std::strcmp(a, b) > 0;
}

void insertion_sort(char arr[][NMAX], int n, bool (*is_greater)(const char* a, const char* b)) {

    for(int i = 1; i < n; ++i) {
        char temp[NMAX];
        std::memset(&temp, 0, NMAX);
        std::memmove(&temp, arr[i], NMAX);
        int j = i;
        for(j; j > 0 && is_greater(arr[j-1], temp); --j) {
            std::memmove(arr[j], arr[j-1], NMAX);
        }
        std::memmove(arr[j], &temp, NMAX);
    }
    return;
}