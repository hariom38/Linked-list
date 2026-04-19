//count no of nodes in the linked list
#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node*next;
};
int count_nodes(Node*head){
    int count=0;
    Node*curr=head;
    while(curr !=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}
int main(){
    cout<<"Radhe Radhe"<<endl;
    Node*head=new Node();
    head->data=1;
    head->next=new Node();
    head->next->data=2;
    head->next->next=new Node();
    head->next->next->data=3;
    head->next->next->next=NULL;
    cout<<"Number of Nodes->"<<count_nodes(head);

    return 0;
}
// output------>Number of Nodes->3
