#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Node {
public : 
    int data ; 
    Node *  next ; 

    Node (int newData){
        this->data = newData;
        this->next = nullptr ; 
    }
};

//given the head of the list , delete the linked list
void deleteLinkedList(Node * head){
    if (head == nullptr || head == NULL)return ; 
    Node * temp = head->next ; 
    delete(head);
    return deleteLinkedList(temp);
}
void printLinkedList(Node * head){
    while (head != nullptr){
        cout << head->data << " "; 
        head = head->next ; 
    }
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printLinkedList(head);
    deleteLinkedList(head);
    head= nullptr ; 
    printLinkedList(head);
    return 0;
}