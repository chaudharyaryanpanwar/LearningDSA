#include <bits/stdc++.h>
using namespace std ; 

class MinHeap{
    vector <int> arr ; 

    int left (int i ){return 2*i+1 ; }
    int right(int i ){return 2*i+2 ; }
    int parent(int i ){return (i-1)/2 ; }

    void heapify(int idx){
        int size = arr.size() ; 
        while (idx < size){
            int leftIdx = left(idx);
            int rightIdx = right(idx);
            int minIdx = idx ;  
            if (leftIdx < size && arr[leftIdx]<arr[minIdx]){
                minIdx = leftIdx ; 
            }

            if (rightIdx < size && arr[rightIdx] < arr[minIdx]){
                minIdx = rightIdx ; 
            }

            if (minIdx != idx){
                swap(arr[idx] , arr[minIdx]);
                idx = minIdx ;
            } else 
                break ; 
        }
    }

    public : 
        void insert(int num){
            arr.push_back(num);
            int size = arr.size() ;
            int idx  = size - 1 ;
            while (idx){
                int parentIdx = parent(idx);
                if (arr[idx]<arr[parentIdx]){
                    swap(arr[idx] , arr[parentIdx]);
                    idx = parentIdx ; 
                } else 
                    break ; 
            }
        }

        int top(){
            if (!arr.empty())
                return arr[0] ; 
            else return -1 ;
        }

        void remove(){
            if (arr.empty())return ; 
            swap(arr[0] , arr[arr.size()-1]);
            arr.pop_back();
            heapify(0);
        }

        int size(){ return arr.size() ;}
        bool empty(){ return arr.empty() ; }

        void printHeap(){
            for (int val : arr)cout << val <<" ";
            cout << endl ; 
        }
};

int main(){
    MinHeap minHeap ;
    minHeap.insert(10) ; 
    minHeap.insert(5) ; 
    minHeap.insert(15) ; 

    cout << minHeap.top() << endl ;
    
    minHeap.insert(1);

    minHeap.printHeap() ; 

    cout << minHeap.top() << endl ; 

    minHeap.remove() ; 

    cout << minHeap.top() << endl ; 
    return 0 ; 
}