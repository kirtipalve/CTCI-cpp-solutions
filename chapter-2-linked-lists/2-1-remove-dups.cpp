/* 
 * Cracking the coding interview edition 6
 * Problem 2-1 : Write code to remove duplicates from an unsorted linked list.
 * Approach 1 : Naive approach of iterating and remove all further duplicates of current node.
 * 							Space complexity O(1) & time complexity O(n^2)
 * Approach 2: Use a hash table, space complexity O(n), time complexity O(n)
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Node
{
    Node* next;
    int data;

    public:
    Node(){
        next=NULL;
        data=0;
    }

    friend class LinkedList;
};

class LinkedList
{
    Node* head;
    public:

    LinkedList(){
        head=NULL;
    }

    //Method to create the linked list
    void append(int val){
        Node* temp= new Node();
        temp->data=val;
        if(head==NULL){
            head=temp;
        }
        else{
            Node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
        temp->next=NULL;

    }


    //Method to print the linked list
    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            Node* ptr=head;
            while(ptr!=NULL){
                cout<<ptr->data<<"->";
                ptr=ptr->next;
            }
            cout<<"NULL"<<endl;

    }
    }

    /* Approach 1: 
        * Iterate through the list and for every iteration , make a pass through the list to check if the same element exists
        * Time complexity O(n^2)
        * Space complexity O(1)
    */
    void removeDuplicates(){
        Node* temp=head;
        Node* temp2;
        Node* temp3;
        if(temp==NULL || temp->next==NULL){
            cout<<"Removed duplicates successfully"<<endl;
            display();
        }
        else{
        while(temp!=NULL){
            temp3=temp;
            temp2=temp->next;
            while(temp2!=NULL){
                if((temp2->data)==(temp->data)){
                    temp3->next=temp2->next; //deleting duplicates
                    temp2=temp2->next;
                }
                else{
                    temp3=temp3->next;
                    temp2=temp2->next;
                }
            }

            temp=temp->next;
            
        }
        cout<<"Removed duplicates successfully"<<endl;
        display();
        }
    }
    /* Approach 2:
        * Use a hash map to keep track of already traversed elements, delete if element already visited
        * Time complexity O(n)
        * Space complexity O(n)
    */
   
    void removeDuplicates2(){
        unordered_map <int,int> m;
        Node* temp=head;
        if(temp==NULL || temp->next==NULL){
            cout<<"Removed duplicates successfully"<<endl;
            display();
        }
        
        Node* temp2=temp->next;
        m[temp->data]=1;
        while(temp2!=NULL){
            if(m[temp2->data]==1){
                temp->next=temp2->next;
                temp2=temp2->next;

            }
            else{
                m[temp->data]=1;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        cout<<"Removed duplicates successfully"<<endl;
        display();

    }
};


int main(){
    int ch;
    
    LinkedList ll;
    do{
        cout<<"MENU \n 1.Create list \n 2.Display list \n 3.Remove Duplicates (Naive Approach) \n 4.Remove Duplicates (using hash table) \n 0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1: {
                while(true){
                int val;
                cout<<"enter value or enter -1 to exit"<<endl;
                cin>>val;
                if(val==-1){
                    break;
                }
                ll.append(val);

            }
            break;
            }
            case 2: {
                ll.display();
                break;

            }
            case 3: {
                ll.removeDuplicates();
                break;
            }
            case 4:{
                ll.removeDuplicates2();
                break;
            }

        
        }
    }while(ch!=0);

    return 0;
}



