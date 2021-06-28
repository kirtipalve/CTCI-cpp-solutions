/* 
 * Cracking the coding interview edition 6
 * Problem 2-6 Palindrome : Implement a function to check if a linked list is a palindrome.
 * Approach 1 : Reverse the linked list and compare with original linked list.
 * 				Space complexity O(n) & Time complexity O(n)
 * Approach 2: Use a stack to store the first half of the list, compare first half with second half
 *             Space complexity O(n) & Time complexity O(n)
 * Approach 3: Using recursive approach to compare the left-most and right-most elements and moving inward
 *             Space complexity O(n) & Time complexity O(n)
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
        Node* temp=new Node();
        temp->data=data;
        temp->next=NULL;
        if(head==NULL) {
            head=temp;
            return;
        }
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        

        
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

    //by reversing the list
    bool palindrome1(){
        if(head==NULL or head->next==NULL){
            return true;
            
        }
        Node* reversed= new Node();
        reversed->data=head->data;
        reversed->next=NULL;
        Node* ptr=head;
        Node* ptr2=ptr->next;
        Node* ptr3;
        Node* temp;
        
        while(ptr2!=NULL){
            
            ptr3=ptr2->next;
            temp=new Node();
            temp->data=ptr2->data;
            temp->next=reversed;
            reversed=temp;
            ptr=ptr2;
            ptr2=ptr3;

        }
        ptr=temp;
        
        Node* original=head;
        while(ptr!=NULL){
            if(ptr->data!=original->data){
                return false;
            }
            ptr=ptr->next;
            original=original->next;
        }
        return true;



    }

    //using a stack

    bool palindrome2(){
        if(head==NULL || head->next==NULL) return true;
        stack<Node*> s;
        Node* slow_ptr=head;
        Node* fast_ptr=head;
        while(fast_ptr->next!=NULL && fast_ptr->next->next!=NULL){
            s.push(slow_ptr);
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }
        
        //evenlength push the last in first half if odd , skip the middle one
        if(fast_ptr->next!=NULL){
            s.push(slow_ptr);
        }


        
        slow_ptr=slow_ptr->next;
        while(slow_ptr!=NULL){
            if(s.top()->data!=slow_ptr->data){
                return false;
            }
            s.pop();
            slow_ptr=slow_ptr->next;
        }
        return true;

    }

    //recursive approach by comparing left-most and right-most element and then moving inward

    bool palindrome3(Node* &left, Node* &right){
        if(right==nullptr) return true;

        bool isPalindrome = palindrome3(left, right->next);
        if (!isPalindrome) {
            return false;
        }
        isPalindrome = ( left->data == right->data );

        // move left to next for next call.
        left = left->next;

        return isPalindrome;


    }
};
int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Display \n3.Palindrome (by reversing) \n4.Palindrome (using a stack) \n5.Palindorome (recursive approach) \n0.Exit \n";
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
                    ll.append(data);
                }
                break;
            }

            case 2:{
                ll.display(ll.head);
                break;

            }

            case 3:{
                if(ll.palindrome1()==true){
                    cout<<"yes is a palindrome"<<endl;
                }
                else{
                    cout<<"no not a palindrome"<<endl;
                }
                break;
                
            }

            case 4:{
                if(ll.palindrome2()==true){
                    cout<<"yes is a palindrome (stack)"<<endl;
                }
                else{
                    cout<<"no not a palindrome (stack)"<<endl;
                }
                break;
            }

            case 5:{
                
                if(ll.palindrome3(ll.head,ll.head)==true){
                    cout<<"yes is a palindrome (recursive)"<<endl;
                }
                else{
                    cout<<"no not a palindrome (recursive)"<<endl;
                }
                break;
            }


           
           
        }
    }while(ch!=0);
    return 0;
}
