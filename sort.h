#ifndef SORT
#define SORT

#include <stdint.h> 
#include "stringProcessor.h"

// ВАЖЛИВО: Попереднє оголошення функції, щоб компілятор її "бачив"
int32_t strcmpp(const char* fStr, const char* sStr);

void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char** arr, int low, int high)
{
    char* pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        // Тепер компілятор знає, що таке strcmpp
        if (strcmpp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_recursive(char** arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(char** arr, size_t length)
{
    if (length > 0) {
        quick_sort_recursive(arr, 0, (int)length - 1);
    }
}
#endif // !SORT