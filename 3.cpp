// 876. Middle of the Linked List

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100



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
 
// Odd case   
// middle element----->fast->next != NULL

// even case 
// 1st middle element---> fast->next->next != NULL
// 2nd middle element---> fast->next != NULL



#include<iostream>
using namespace std;
struct ListNode{
    public:
    int data;
    ListNode*next;
};
ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
}

int main(){
    cout<<"Radhe Radhe"<<endl;
    ListNode*head=new ListNode();
    head->data=1;
    head->next=new ListNode();
    head->next->data=2;
    head->next->next=new ListNode();
    head->next->next->data=3;
    head->next->next->next=new ListNode();
    head->next->next->next->data=4;
    head->next->next->next->next=NULL;
    cout<<"middle node address is ->"<<middleNode(head)<<endl;
    cout<<"middle node data is  ->"<<middleNode(head)->data;

    return 0;
}
// Time: O(n)
// Space: O(1)


