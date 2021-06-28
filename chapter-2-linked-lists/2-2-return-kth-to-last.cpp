//done 
/* 
 * Cracking the coding interview edition 6
 * Problem 2-2-Return Kth to Last : Implement an algorithm to find the kth to last element of a singly linked list.
 * Approach 1 : By finding the length of list.
 * 				Space complexity O(1) & Time complexity O(n)
 * Approach 2: Using recursive solution
 *             Space complexity O(n) & Time complexity O(n)
 * Approach 3: Iterative method using two pointers
 *             Space complexity O(1) & Time Complexity O(n)
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

    void append(int data){
        Node* temp= new Node();
        temp->data=data;
        temp->next=NULL;
    
        if (head==NULL){
            head=temp;
            
        }
        else{
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        }

    }

    void display(){
        Node* ptr=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;

        }
        cout<<"NULL";
    }
    

    //by finding the length of the list
    void kth_to_last1(int k){
        if(head==NULL) return;
        Node* ptr=head;
        int count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        
        count=count-k;
        ptr=head;
        while(count--){
            ptr=ptr->next;

        }
        cout<<ptr->data<<endl;

    }



    //using recursive solution
    int kth_to_last2(int k,Node* temp){
        if(temp==NULL){
            return 0;
        }
        int index=kth_to_last2(k,temp->next) +1;
        
        if(index==k){
            cout<<temp->data;
        }
        cout<<endl;
        return index;
        

    }
    
    //iterative way using two pointers
    int kth_to_last3(int k){
        if(head==NULL){
            return 0;
        }
        Node* ptr= head;
        Node* ptr2=head;
        int i=k;
        while(i--){
            ptr2=ptr2->next;

        }
        while(ptr2!=NULL){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        cout<<ptr->data<<endl;

    }
};

int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Display \n3.Kth last (length of list) \n4.Kth last (recursive) \n5.Kth to last (iterative) \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                while(true){
                    int data;
                    cout<<"Enter value or -1 to exit"<<endl;
                    cin>>data;
                    if(data==-1){
                        break;
                    }
                    ll.append(data);
                }
                break;
            }

            case 2:{
                ll.display();
                cout<<endl;
                break;
            }

            case 3:{
                int k;
                cout<<"Enter the value of k"<<endl;
                cin>>k;
                ll.kth_to_last1(k);
                break;
            }
            case 4:{
                int k;
                cout<<"Enter the value of k"<<endl;
                cin>>k;
                
                ll.kth_to_last2(k,ll.head);
                break;
            }

            case 5:{
                int k;
                cout<<"Enter the value of k"<<endl;
                cin>>k;
                ll.kth_to_last3(k);
                break;
            }

          
        }
    }while(ch!=0);
    return 0;
}