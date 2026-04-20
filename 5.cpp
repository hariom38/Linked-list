

// 160. Intersection of Two Linked Lists

// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
// Output: Intersected at '8'

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//time complexity--------->o(max(m,n))
//space complexity--------->o(1)



#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Your approach: length difference
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n = 0, m = 0;

    ListNode* A = headA;
    ListNode* B = headB;

    // Count length of list A
    while(A != NULL){
        n++;
        A = A->next;
    }
    // Count length of list B
    while(B != NULL){
        m++;
        B = B->next;
    }
    ListNode* p1 = headA;
    ListNode* p2 = headB;

    // Move pointer of longer list
    int d = abs(n - m);
    if(n > m){
        while(d--) p1 = p1->next;
    } else {
        while(d--) p2 = p2->next;
    }
    // Move both pointers together
    while(p1 != NULL && p2 != NULL){
        if(p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}
int main(){

    // Create common intersection part: 8 → 4 → 5
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A: 4 → 1 → 8 → 4 → 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B: 5 → 6 → 1 → 8 → 4 → 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    // Find intersection
    ListNode* result = getIntersectionNode(headA, headB);

    if(result != NULL){
        cout << "Intersected at node with value: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
// Time: O(n + m)
// Space: O(1)

