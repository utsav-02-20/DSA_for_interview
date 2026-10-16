#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define int128 __int128
typedef ll ton;

class sorting {
    private:

        vector < int > arr;
    int n;

    public:

        sorting(vector < int > & arr, int n) {
            this -> n = n; // assiging the size 
            this -> arr = arr; // assiging the array element
        }

    void STLsort() {

        // STL sorting

        sort(arr.begin(), arr.end()); // assending order 
        sort(arr.rbegin(), arr.rend()); // decending order 

        int pos = 0;
        sort(arr.begin(), arr.begin() + pos); // sort upto position "pos"
        sort(arr.begin() + pos, arr.end()); // sort from position "pos" 

        int pos1 = 1, pos2 = 3;
        sort(arr.begin() + pos1, arr.begin() + pos2); // sort from pos1 to pos2 

        // tc = O(log n) , sc = O(log n) ; 
    }

    void bubble_sort() {

        // Approach: Compare adjacent elements and swap if they are
        // in the wrong order. Each pass places the largest unsorted
        // element at the end. Stop early if no swaps occur.

        for (int i = 0; i < n - 1; i++) {
            bool swapped = false; // checker 

            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) {
                break;
            }
        }

        // TC: Best O(n), Average O(n²), Worst O(n²)
        // SC: O(1) auxiliary space
    }

    void selection_sort() {

        // Approach: Find the minimum element in the unsorted
        // portion and swap it with the first unsorted element.
        // Repeat until the array is sorted.

        for (int i = 0; i < n - 1; i++) {
            int mini = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[mini]) {
                    mini = j;
                }
            }

            swap(arr[i], arr[mini]);
        }

        // TC: Best, Average, Worst = O(n^2)
        // SC: O(1) auxiliary space
    }

    void insertion_sort() {

        // Approach: Take each element and insert it into its
        // correct position in the already sorted left portion.

        for (int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {

                arr[j + 1] = arr[j];
                j--;

            }

            arr[j + 1] = key;
        }

        // TC: Best O(n), Average O(n²), Worst O(n²)
        // SC: O(1) auxiliary space
    }

    // merge sort 

    // Approach:
    // 1. Divide the array into two halves recursively.
    // 2. Continue dividing until each half has one element.
    // 3. Merge both halves in sorted order.
    // 4. Copy the merged elements back into the original array.

    void merge2(int left, int mid, int right) {
        vector < int > temp;

        int i = left;
        int j = mid + 1;

        // Merge both sorted halves
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        // Copy remaining elements
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        // Copy merged elements back
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    void merge1(int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        merge1(left, mid);
        merge1(mid + 1, right);

        merge2(left, mid, right);
    }

    void merge_sort() {
        merge1(0, n - 1);

        // Time: (O(n log n))
        // Auxiliary space: (O(n))
    }

    // quick sort 

    // Approach:
    // 1. Choose a pivot element from the array.
    // 2. Partition the array so smaller elements are on the left and greater elements are on the right of the pivot.
    // 3. Recursively apply Quick Sort to both partitions.
    // 4. Stop when a partition has zero or one element.

    int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quick1(int low, int high) {
        if (low >= high) {
            return;
        }

        int p = partition(low, high);

        quick1(low, p - 1);
        quick1(p + 1, high);
    }

    void quick_sort() {
        quick1(0, n - 1);
    }

    // Average time: (O(nlog n))
    // Worst-case time: (O(n^2))
    // Average auxiliary space: (O(log n))


};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector < int > arr;
    int n;
    cin >> n; // array size ; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // array element 
    }

    return 0;
}
