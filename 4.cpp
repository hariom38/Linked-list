
// 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp=head;

//         ListNode* prev=NULL;

//         while(temp != NULL){
//             ListNode* nxt=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=nxt;
//         }
//         return prev;
        
//     }
// };



#include<iostream>
using namespace std;

struct ListNode{
    public:
    int data;
    ListNode* next;
};

ListNode* reverseList(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp != NULL){
        ListNode* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    return prev;
}

int main(){
    ListNode* head = new ListNode();
    head->data = 1;

    head->next = new ListNode();
    head->next->data = 2;

    head->next->next = new ListNode();
    head->next->next->data = 3;

    head->next->next->next = new ListNode();
    head->next->next->next->data = 4;

    head->next->next->next->next = new ListNode();
    head->next->next->next->next->data = 5;

    head->next->next->next->next->next = NULL;

    // ✅ Print original first
    cout<<"Actual Linked List: ";
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    // Reverse
    ListNode* newHead = reverseList(head);

    // Print reversed
    cout<<"\nReversed Linked List: ";
    while(newHead != NULL){
        cout << newHead->data << " ";
        newHead = newHead->next;
    }

    return 0;
}
