#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define int128 __int128
typedef ll ton;

class sorting {
    private: 
    
        vector<int> arr ; 
        int n ; 
        
    public: 
    
        sorting(vector<int> &arr , int n) {
            this -> n = n ; // assiging the size 
            this -> arr = arr ; // assiging the array element
        }
        
        void STLsort() {
            
            // STL sorting
            
            sort(arr.begin() , arr.end()) ; // assending order 
            sort(arr.rbegin() , arr.rend()) ; // decending order 
            
            int pos = 0 ; 
            sort(arr.begin() , arr.begin() + pos) ; // sort upto position "pos"
            sort(arr.begin() + pos , arr.end()) ; // sort from position "pos" 
            
            int pos1 = 1 , pos2 = 3 ; 
            sort(arr.begin() + pos1 , arr.begin() + pos2) ; // sort from pos1 to pos2 
            
            // tc = O(log n) , sc = O(log n) ; 
        }
        
        void bubble_sort() {
            
            // Approach: Compare adjacent elements and swap if they are
            // in the wrong order. Each pass places the largest unsorted
            // element at the end. Stop early if no swaps occur.
            
            for(int i = 0 ; i < n - 1 ; i++) {
                bool swapped = false ; // checker 
                
                for(int j = 0 ; j < n - i - 1 ; j++) {
                    if(arr[j] > arr[j + 1]) {
                        swap(arr[j] , arr[j + 1]) ; 
                        swapped = true ; 
                    }
                }
                
                if(!swapped) {
                    break ; 
                }
            }
            
            // TC: Best O(n), Average O(n²), Worst O(n²)
            // SC: O(1) auxiliary space
        }
        
        void selection_sort() {
            
            // Approach: Find the minimum element in the unsorted
            // portion and swap it with the first unsorted element.
            // Repeat until the array is sorted.
            
            for(int i = 0 ; i < n - 1 ; i++) {
                int mini = i ; 
                for(int j = i + 1 ; j < n ; j++) {
                    if(arr[j] > arr[mini]) {
                        mini = j ; 
                    }
                }
                
                swap(arr[i] , arr[mini]) ; 
            }
            
            // TC: Best, Average, Worst = O(n^2)
            // SC: O(1) auxiliary space
        }
        
        void insertion_sort() {
            
        }
        
        
} ;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr ; 
    int n ; cin >> n ; // array size ; 
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ; // array element 
    }
    
    return 0;
}
