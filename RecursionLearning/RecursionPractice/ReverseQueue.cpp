#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*
Given a queue, write a recursive function to reverse it. 

Standard operations allowed : 

enqueue(x) : Add an item x to rear of queue. 
dequeue() : Remove an item from front of queue. 
empty() : Checks if a queue is empty or not.

Examples :  

Input : Q = [5, 24, 9, 6, 8, 4, 1, 8, 3, 6]
Output : Q = [6, 3, 8, 1, 4, 8, 6, 9, 24, 5]

Explanation : Output queue is the reverse of the input queue.

Input : Q = [8, 7, 2, 5, 1]
Output : Q = [1, 5, 2, 7, 8]
*/

void printQueue(queue <int> q){
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop() ;   
    }
}
void reverseQueue(queue <int>& q){
    if(q.empty())return ; 
    int temp = q.front() ; 
    q.pop() ; 
    reverseQueue(q);
    q.push(temp);
}
int main() {
    queue<int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    reverseQueue(Queue);
    printQueue(Queue);
    return 0;
}