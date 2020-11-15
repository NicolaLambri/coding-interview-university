#include <iostream>
#include <cassert>
#include <random>
#include <cmath>

template <class T>
void swap(T &a, T&b) {
    auto temp = a;
    a = b;
    b = temp;
}

// in-place quicksort
template <class T>
void quicksort(T* arr, int low, int high) {
    if (high <= low)
        return;
    assert(high > low);
    int v = rand() % (high - low) + low; // random pivot in [low, high]
    swap(arr[high], arr[v]); // swap pivot with last element in array
    int i = low, j = high - 1; // indexes of sorting range
    while (i < j) {
        while (arr[i] <= arr[high]) i++;
        while (arr[j] >= arr[high] && j > low) j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[high]); // swap pivot to correct position
    quicksort(arr, low, i - 1);
    quicksort(arr, i + 1, high);
}

template <class T>
void insertionsort(T* arr, int len) {
    for (int i = 1; i < len; ++i) { // O(n)
        for (int j = i - 1; j >= 0; --j) {
            // O(n) move to the right all the elements that are greater than the new value
            if (arr[i] > arr[j]) { 
                T temp = arr[i];
                for (int index = i; index > j + 1; --index) {
                    arr[index] = arr[index - 1];
                }
                arr[j + 1] = temp;
                break;
            }
        }
    }
}

template <class T>
T* merge(T* arr1, int len1, T* arr2, int len2) {
    T* merged = new T[len1 + len2];
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    if (i == len1) {
        for (int l = j; l < len2; ++l)
            merged[k++] = arr2[l];
    }
    else {
        for (int l = i; l < len1; ++l)
            merged[k++] = arr1[l];
    }
    return merged;
}

int main () {
    int arr[] = {1,3,5,6,2,6,34,6,2,6,34,3,46,36,345,7};
    std::cout << "Before sort: " << std::endl;
    for (auto item : arr) std::cout << item << " ";
    std::cout << std::endl;
    /*quicksort(arr, 0, 14);
    std::cout << "Quicksort: " << std::endl;
    for (auto item : arr) std::cout << item << " ";
    std::cout << std::endl;*/
    /*insertionsort(arr, 16);
    std::cout << "Insertion Sort: " << std::endl;
    for (auto item : arr) std::cout << item << " ";
    std::cout << std::endl;*/
    /*int* sorted = mergesort(arr, 0, 15);
    std::cout << "Mergesort: " << std::endl;
    for (int i = 0; i < 15; ++i) std::cout << *(sorted + i) << " ";
    std::cout << std::endl;*/
    int arr1[] = {1,3,5,8};
    int arr2[] = {3,4,9,10,12,16,18};
    int* s = merge(arr1, 4, arr2, 7);
    for (int i = 0; i < 11; ++i) std::cout << s[i] << " ";
    std::cout << std::endl;
}
