//done
/* 
 * Cracking the coding interview edition 6
 * Problem 2-4-Sum Lists : 
 * You have two numbers represented by a linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the 1's digit is at the head of the list.
 * Write a function that adds the two numbers and returns the sum as a linked list. 
 * FOLLOW UP: Suppose the digits are stored in forward order. Repeat the above problem.
 * 			   
 * Approach 1: Naive approach by converting list to integer and back to linked list
 *             Space Complexity O(1) & Time complexity O(A+B)
 * Approach 2: Directly making the final list
 *             Space Complexity O(1) & Time complexity O(A+B)
 * Approach for forward order : pad shorter list, then use recursion/stack
 *                              Space Complexity O(A+B) & Time complexity O(A+B)
 * 

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
    public:
    
    Node* head;
    Node* head2;
    
    public:
    LinkedList(){
        head=NULL;
        head2=NULL;
        
    }

    //function to create a linked list
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

    void insert_at_front(int data,Node* &node){
        Node* temp= new Node();
        temp->data=data;
        temp->next=node;
        node=temp;
    }
    //function to print linkedlist
    void display(Node* node){
        Node* ptr=node;
        if(node==NULL){
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

    //naive approach by converting list to integer and back to linked list
    void sumLists(Node* &node1,Node* &node2){
        if(node1==NULL && node2==NULL){
            return;
        }
        
        int k=1;
        int firstNumber=0;
        int secondNumber=0;
        Node* ptr=node1;
        while(ptr!=NULL){
            firstNumber+=k*(ptr->data);
            k*=10;
            ptr=ptr->next;
        }
        ptr=node2;
        k=1;
        while(ptr!=NULL){
            secondNumber+=k*(ptr->data);
            k*=10;
            ptr=ptr->next;
        }

        
        int final=firstNumber+secondNumber;
        Node* sum=NULL;
        ptr=sum;
        while(final>0){
            append(final%10,sum);
            final/=10;
        }
        display(sum);
    }
     
          
    //efficient approach by directly making final list   
    void sumLists2(Node* node1,Node* node2){
        if(node1==NULL && node2==NULL){
            return;
        }
        
        int carry=0;
        int n1=0;
        int n2=0;
        Node* final=NULL;
        Node* ptr=node1;
        Node* ptr2=node2;
        while(ptr!=NULL){
            n1++;
            ptr=ptr->next;
        }
        while(ptr2!=NULL){
            n2++;
            ptr2=ptr2->next;
        }
        if(n1>n2){
           int diff=n1-n2;
           while(diff--){
               append(0,node2);
           }
        }
        else if(n2>n1){
            int diff= n2-n1;
            while(diff--){
                append(0,node1);
            }
        }
        ptr=node1;
        ptr2=node2;

        while(ptr!=NULL){
            int val=ptr->data+ptr2->data+carry;
            append(val%10,final);
            carry=(val-val%10)/10;
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        
        //append(carry,final);
        
        display(final);
    }


    //FOLLOW UP - forward order

    //to pad the shorter list
    void padding(Node* &node1, Node* &node2){
        if(node1==NULL && node2==NULL){
            return;
        }
        
        int n1=0;
        int n2=0;
        Node* ptr=node1;
        Node* ptr2=node2;
        while(ptr!=NULL){
            n1++;
            ptr=ptr->next;
        }
        while(ptr2!=NULL){
            n2++;
            ptr2=ptr2->next;
        }
        if(n1>n2){
           int diff=n1-n2;
           while(diff--){
               insert_at_front(0,node2);
           }
        }
        else if(n2>n1){
            int diff= n2-n1;
            while(diff--){
                insert_at_front(0,node1);
            }
        }

    }

    //add lists in forward order using stack
    void sumLists_forwardOrder(Node* node1,Node* node2){
        
        padding(node1,node2);
        
        stack<Node*> s;
        Node* ptr=node1;
        Node* ptr2=node2;
        int carry=0;
        Node* final=NULL;
        int add=0;

        while(ptr2!=NULL){
            s.push(ptr);
            s.push(ptr2);
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        display(final);
        while(s.empty()==false){
            add=s.top()->data;
            s.pop();
            add+=s.top()->data+carry;
            insert_at_front(add%10,final);
            carry=(add-add%10)/10;
            s.pop();
        }
        
        //append(carry,final);
        
        display(final);
    }

    

    

};
int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Insert at front \n3.Display \n4.Sum lists (naive) \n5.Sum lists (efficient) \n6.Sum lists (forward order) \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                while(true){
                    cout<<"For list 1"<<endl;
                    int data;
                    cout<<"Enter value or -1 to exit"<<endl;
                    cin>>data;
                    if(data==-1){
                        ll.display(ll.head);
                        break;
                    }
                    ll.append(data,ll.head);
                }
                while(true){
                    cout<<"For list 2"<<endl;
                    int data;
                    cout<<"Enter value or -1 to exit"<<endl;
                    cin>>data;
                    if(data==-1){
                        ll.display(ll.head2);
                        break;
                    }
                    ll.append(data,ll.head2);
                }
                break;
            }

            case 2:{
                while(true){
                int data;
                cout<<"Enter value or -1 to exit"<<endl;
                cin>>data;
                if(data==-1){
                    ll.display(ll.head);
                    break;
                }
                ll.insert_at_front(data,ll.head);
                }
                break;

            }

            case 3:{
                ll.display(ll.head);
                ll.display(ll.head2);
                cout<<endl;
                break;
            }

            case 4:{
            

                ll.sumLists(ll.head,ll.head2);
                break;
            }

            case 5:{
                ll.sumLists2(ll.head,ll.head2);
                break;
            }

            case 6:{
                ll.sumLists_forwardOrder(ll.head,ll.head2);
                break;
            }
            
            
           
        }
    }while(ch!=0);
    return 0;
}