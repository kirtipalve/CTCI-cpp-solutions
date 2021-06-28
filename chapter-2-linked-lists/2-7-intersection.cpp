//done
/* 
 * Cracking the coding interview edition 6
 * Problem 2-7-Intersection : Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. 
 * Approach 1: Naive approach of using a hashmap to keep track of all nodes.
 * 				Space complexity O(A) & Time complexity O(A+B)
 * Approach 2: Combining the two lists and using a cycle detection algorithm
 *             Space complexity O(1) & Time complexity O(A+B)
 * Approach 3: Using length of lists 
 *             Space complexity O(1) & Time complexity O(A+B)
*/

#include<bits/stdc++.h>
using namespace std;

//class to generate node

class Node
{
    Node* next;
    int data;
    public:
    /*Node(){
        next=NULL;
        data=0;
    }*/
    Node(int val){
        next=NULL;
        data=val;
    }

    friend class LinkedList;

};

class LinkedList
{
    public:
    Node* head1;
    Node* head2;
    public:
    LinkedList(){
        head1=NULL;
        head2=NULL;
    }

    //Lists to input

    void two_intersecting_lists(Node* &head1,Node* &head2){
        
        head1=new Node(2);
        //head1->data=2;
        head1->next=new Node(4);
        //head1->next->data=4;

        head1->next->next=new Node(6);
        head1->next->next->next=new Node(8);
        head1->next->next->next->next=new Node(10);

        head2=new Node(1);
        head2->next=head1->next->next;

    }


    void display(Node* head){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }

    //function to check is two strings intersect
    // we do this by checking if the last node of both lists is same
    bool check_intersection(Node* head1, Node* head2){
        Node* ptr=head1;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        Node* ptr2=head2;
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
        }
        if(ptr==ptr2)
            return true;
        
        return false;
    }


    //using hashmap time O(A+B) and space O(A)
    void intersection_node(Node* head1, Node* head2){
        if(!check_intersection(head1,head2)){
            cout<<"No intersection found"<<endl;
            return;

        }
        unordered_map<Node*,int> m;
        Node* ptr=head1;
        int count=1;
        while(ptr!=NULL){
            m[ptr]=count;
            ptr=ptr->next;
            count++;
        }
        ptr=head2;
        count=0;
        while(ptr!=NULL){
            count++;
            if(m[ptr]>=1){
                cout<<"Intersecting node is "<<ptr->data<<endl;
                break;

            }
            ptr=ptr->next;
        }

    }

    //using floyd cycle algo
    void intersection_node2(Node* head1,Node* head2){
        if(!check_intersection(head1,head2)){
            cout<<"Lists do not intersect"<<endl;
            return;
        }
        Node* ptr=head1;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=head2;
        int count=1;
        int count2=1;
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
        Node* ptr2=ptr->next;
        while(ptr2!=fast_p){
            count2++;
            ptr2=ptr2->next;
        }
        ptr->next=NULL;
        ptr=head1;
        while(ptr!=fast_p){
            count++;
            ptr=ptr->next;
        }
        cout<<"Intersecting node is "<<ptr->data<<endl;
        
    }


    //by calculating length of the lists and then traversing bigger list from (bigger length - smaller length)
    void intersection_node3(Node* head1, Node* head2){
        if(!check_intersection(head1,head2)){
            cout<<"Lists do not intersect"<<endl;
            return;
        }
        Node* ptr1=head1;
        Node* ptr2=head2;
        int len1=0,len2=0;
        while(ptr1!=NULL){
            len1++;
            ptr1=ptr1->next;

        }
         while(ptr2!=NULL){
            len2++;
            ptr2=ptr2->next;

        }
        ptr1=head1;
        ptr2=head2;
        int i=0;
        if(len1>len2){
            while(ptr1 && i<len1-len2){
                ptr1=ptr1->next;
                i++;
            }
        }
        else{
            while(ptr2 && i<len2-len1){
                ptr2=ptr2->next;
                i++;
            }

        }
        while(ptr1!=NULL){
            if(ptr1==ptr2){
                cout<<"Intersecting node is "<<ptr1->data<<endl;
                break;

            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }

};

int main(){
    int ch;
    
    LinkedList ll;
    ll.two_intersecting_lists(ll.head1,ll.head2);
    do{
        cout<<"MENU \n1.Display \n2.Find intersection (using hashing) \n3.Find intersection (Floyd cycle algo) \n4.Find intersection (Using length of lists) \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1: {
                cout<<"First list is"<<endl;
                ll.display(ll.head1);
                cout<<"Second list is"<<endl;
                ll.display(ll.head2);
                break;

            }

            case 2: {
                cout<<"The two lists are"<<endl;
                ll.display(ll.head1);
                ll.display(ll.head2);
                cout<<endl;
                cout<<"Using hashing"<<endl;
                ll.intersection_node(ll.head1,ll.head2);
                break;
            }

            case 3: {
                cout<<"The two lists are"<<endl;
                ll.display(ll.head1);
                ll.display(ll.head2);
                cout<<endl;
                cout<<"Using Floyd Cycle algo"<<endl;
                ll.intersection_node2(ll.head1,ll.head2);
                break;
            }

             case 4: {
                cout<<"The two lists are"<<endl;
                ll.display(ll.head1);
                ll.display(ll.head2);
                cout<<endl;
                cout<<"Using length of lists"<<endl;
                ll.intersection_node3(ll.head1,ll.head2);
                break;
            }
           

        
        }
    }while(ch!=0);

    return 0;
}

