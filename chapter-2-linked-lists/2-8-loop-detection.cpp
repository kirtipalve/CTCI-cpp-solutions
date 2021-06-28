//done theory to be understood yet
/* 
 * Cracking the coding interview edition 6
 * Problem 2-8-Loop Detection : Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
 * Approach: Floyd's algorithm for cycle detection
 *           Space complexity O(1) & Time complexity O(n)
*/

#include<bits/stdc++.h>
using namespace std;
class Node
{
    private:
    int data;
    Node* next;
    public:
    Node(int val){
        data=val;
        next=NULL;
    }
    friend class LinkedList;
    
};

class LinkedList 
{
    public:
    
    Node* head;
    
    
    public:
    LinkedList(){
        head=NULL;
        
        
    }

    //function to create the linked list with a cycle
    void circular_list(Node* &head){
        
        head=new Node(2);
        
        head->next=new Node(4);
        

        head->next->next=new Node(6);
        head->next->next->next=new Node(8);
        head->next->next->next->next=new Node(10);
        head->next->next->next->next->next=new Node(12);
        head->next->next->next->next->next->next=new Node(14);
        head->next->next->next->next->next->next->next=head->next->next;

        cout<<"list is 2->4->6->8->->10->12->14->6...."<<endl;


        

    }


    void loop_detection(Node* head1){
        
        Node* ptr=head1;
        Node *slow_p = head1, *fast_p = head1;
 
        while (slow_p && fast_p && fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p) {
                break;
            }
        }
        slow_p=head1;
        while(slow_p!=fast_p){
            slow_p=slow_p->next;
            fast_p=fast_p->next;
        }
         
        
        cout<<"Starting of loop is "<<slow_p->data<<endl;
        
    }

    

    

};
int main(){
    LinkedList ll;
    ll.circular_list(ll.head);   
    ll.loop_detection(ll.head);
  
return 0;
}