//done
/* 
 * Cracking the coding interview edition 6
 * Problem 2-4-Partition : 
 * Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to X.
 * If X is conatined within the list, the values of x only need to be after the elements less than x. 
 * The partition element x can appear anywhere in the 'right partition'; it does not need to appear between left and right partitions.
 * Approach 1: using two pointers and swapping
 * 			   Space complexity O(1) & time complexity O(n)
 * Approach 2: creating two linked lists and then merging them to maintain stability
 *             Space complexity O(n) & time complexity O(n)
 * 

*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node* next;
    public:
    Node(){
        data=0;
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

    void append(int data,Node* &node){
        Node* temp= new Node();
        temp->data=data;
        temp->next=NULL;
        if(node==NULL){
            node=temp;
        }
        else{
            Node* ptr=node;
            while(ptr->next!=NULL){
                ptr=ptr->next;

            }
            ptr->next=temp;
        }
    }
    
    void display(Node* node){
        if(node==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            Node* ptr=node;
            while(ptr!=NULL){
                cout<<ptr->data<<"->";
                ptr=ptr->next;

            }
            cout<<"NULL"<<endl;
        }
    }


    //using two pointers
    void partition1(int k){
        int countLessThan=0;
        int current=0;
        Node* ptr=head;
        Node* ptr2=head;
        while(ptr!=NULL){
            if(ptr->data<k){
                swap(ptr->data,ptr2->data);
                ptr2=ptr2->next;
            }
            ptr=ptr->next;
        }
        cout<<"new list is "<<endl;
        display(head);

    }

    //stable solution

    void partition2(int k){
        Node* smaller=NULL;
        Node* bigger= NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->data<k){
                append(ptr->data,smaller);
            }
            else{
                append(ptr->data,bigger);
            }
            ptr=ptr->next;
        }
        cout<<"smaller and bigger lists"<<endl;
        display(smaller);
        display(bigger);
        ptr=smaller;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=bigger;
        cout<<"final list is"<<endl;

        display(smaller);
    }



    
};

int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Display \n3.partition \n4.partition2 \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                while(true){
                    int data;
                    cout<<"Enter value or -1 to exit"<<endl;
                    cin>>data;
                    if(data==-1){
                        ll.display(ll.head);
                        break;
                    }
                    ll.append(data,ll.head);
                }
                break;
            }

            case 2:{
                ll.display(ll.head);
                cout<<endl;
                break;
            }

            case 3:{
                int k;
                cout<<"Enter value of partition"<<endl;
                cin>>k;

                ll.partition1(k);
                break;
            }
            case 4:{
                int k;
                cout<<"Enter value of partition"<<endl;
                cin>>k;

                ll.partition2(k);
                break;

            }
           
        }
    }while(ch!=0);
    return 0;
}
