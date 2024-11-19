#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*

*/
struct Item {
    int profit , weight ; 
    
    Item(int profit , int weight){
        this->profit = profit ; 
        this->weight = weight ; 
    }
};

//Comparison function to sort the item 
static bool cmp(struct Item a , struct Item b ){
    double r1 = (double)a.profit / (double)a.weight ; 
    double r2 = (double)b.profit / (double) b.weight ; 
    return r1 > r2 ; 
}

double fractionalKnapsack(int W , struct Item arr[] , int N){

    //sorting item on the basis of ration 
    sort(arr , arr + N , cmp);

    double finalValue  = 0.0 ; 

    for (int i =0 ; i < N; i++){

        //if adding item won't overflow then add 
        if (arr[i].weight <= W){
            W -= arr[i].weight ; 
            finalValue += arr[i].profit ;
        }

        else {
            finalValue += arr[i].profit * ((double) W / (double) arr[i].weight);
            break ; 
        }
    }

    return finalValue ; 
}

int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}