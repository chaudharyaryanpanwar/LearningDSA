#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//COULDNOT UNDERSTAND IT 

/*
Given a queue and the task is to sort it using recursion without using any loop.
We can only use the following functions of queue: 
Examples: 

Input: queue = {10, 7, 16, 9, 20, 5} 
Output: 5 7 9 10 16 20
Input: queue = {0, -2, -1, 2, 3, 1} 
Output: -2 -1 0 1 2 3 
*/

// Function to push element in last by
// popping from front until size becomes 0
void frontToLast(queue<int> &q , int qsize){
	if(qsize == 0 || q.empty()){
		return ; 
	}
	//pop from element and push 
	//this last in a queue
	q.push(q.front());
	q.pop();

	//recursive call for pushing element
	frontToLast(q , qsize -1 );

}
// Function to push an element in the queue
// while maintaining the sorted order
void pushInQueue(queue<int>& q, int temp, int qsize)
{
	// Base condition
	if (q.empty() || qsize == 0) {
		q.push(temp);
		return;
	}

	// If current element is less than
	// the element at the front
	else if (temp <= q.front()) {

		// Call stack with front of queue
		q.push(temp);

		// Recursive call for inserting a front
		// element of the queue to the last
		frontToLast(q, qsize);
	}
	else {

		// Push front element into
		// last in a queue
		q.push(q.front());
		q.pop();

		// Recursive call for pushing
		// element in a queue
		pushInQueue(q, temp, qsize - 1);
	}
}

// Function to sort the given
// queue using recursion
void sortQueue(queue<int>& q)
{

	// Return if queue is empty
	if (q.empty())
		return;

	// Get the front element which will
	// be stored in this variable
	// throughout the recursion stack
	int temp = q.front();

	// Remove the front element
	q.pop();

	// Recursive call
	sortQueue(q);

	// Push the current element into the queue
	// according to the sorting order
	pushInQueue(q, temp, q.size());
}

// Driver code
int main()
{

	// Push elements to the queue
	queue<int> qu;
	qu.push(10);
	qu.push(7);
	qu.push(16);
	qu.push(9);
	qu.push(20);
	qu.push(5);

	// Sort the queue
	sortQueue(qu);

	// Print the elements of the
	// queue after sorting
	while (!qu.empty()) {
		cout << qu.front() << " ";
		qu.pop();
	}
}
