/* 
 * Cracking the coding interview edition 6
 * Problem 2-3 : Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.
 * Approach : Since we do not have the access to head node, we will copy the content of the node next to the node to be deleted.
 *            Then we will delete the next node.
 * 			  Space complexity O(1) & time complexity O(1)

*/

#include<bits/stdc++.h>
using namespace std;
class Node
{
    private:
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
    
    Node* head;
    
    public:
    LinkedList(){
        head=NULL;
        
    }

    //function to create a linked list
    void append(int data){
        Node* temp= new Node();
        temp->data=data;
        temp->next=NULL;
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
    }
    //function to print linkedlist
    void display(){
        Node* ptr=head;
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
        }
    }

    //method to generate node to be deleted
    Node* generateNode(){
        return head->next->next;
    }

    //method to delete node
    void solution1(Node* node){
        if(node==NULL || node->next==NULL){
            return;
        }
        else{
            Node* ptr=node;
            //ptr is the node accessible
            Node* ptr2=ptr->next;
            ptr->data=ptr2->data;
            ptr->next=ptr2->next;
            delete ptr2;

        }
        cout<<"updated list is"<<endl;
        display();
    }

    

};
int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Display \n3.Delete middle node \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                while(true){
                    int data;
                    cout<<"Enter value or -1 to exit"<<endl;
                    cin>>data;
                    if(data==-1){
                        ll.display();
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
                Node* temp=ll.generateNode();

                ll.solution1(temp);
                break;
            }
           
        }
    }while(ch!=0);
    return 0;
}