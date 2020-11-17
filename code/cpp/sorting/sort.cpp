#include <iostream>
#include <cassert>
#include <random>
#include <cmath>

template <class T>
void swap(T &a, T &b) {
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
void insertionsort(T* arr, const int len) {
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
void merge(const T* arr1, int len1, const T* arr2, int len2, T* merged) {
    int i, j, k;
    i = j = k = 0;
    while (i < len1 && j < len2) {
        /* this can be unsafe as j could refer to past the last item of arr2
        if ((arr1[i] < arr2[j] && i < len1) || j >= len2)
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];*/
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while (i < len1) merged[k++] = arr1[i++];
    while (j < len2) merged[k++] = arr2[j++];
}

template <class T>
void mergesort(T* arr, int len, T* merged) {
    // sorting NOT in-place
    // O(n) space complexity
    if (len < 2) {
        T* it; int i;
        for (it = arr, i = 0; it < arr + len; ++it, ++i)
            merged[i] = *it;
        return;
    }
    int len1 = len / 2, len2 = ceil(len / 2);
    T* merged1 = new T [len1];
    mergesort(arr, len1, merged1);

    T* merged2 = new T [len2];
    mergesort(arr + len1, len2, merged2);

    merge(merged1, len1, merged2, len2, merged);

    delete[] merged1;
    delete[] merged2;
}

template <class T>
void in_place_merge(T arr[], int low, int mid, int high) {
    T temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    // order items in temp
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];

    --k; // set k value to last index of temp
    // copy ordered items from temp to arr
    while (k >= 0) {
        arr[low + k] = temp[k];
        --k;
    }
}

template <class T>
// T arr[]: syntactic sugar for T* arr
void in_place_mergesort(T arr[], int low, int high) {
    // O(n) space complexity (more efficient than not-in-place by a factor of 2)
    if (low >= high)
        return;

    int mid = (high + low) / 2;
    in_place_mergesort(arr, low, mid);
    in_place_mergesort(arr, mid + 1, high);

    in_place_merge(arr, low, mid, high);
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
    int sorted[16];
    mergesort(arr, 16, sorted);
    std::cout << "Mergesort: ";
    for (int i = 0; i < 16; ++i) std::cout << sorted[i] << " ";
    std::cout << std::endl;
    std::cout << "In-place mergesort: ";
    in_place_mergesort(arr, 0, 15);
    for (int i = 0; i < 16; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}
