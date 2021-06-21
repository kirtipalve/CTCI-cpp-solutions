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
    void solution1(int k){
        Node* ptr=head;
        int count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        k;
        count=count-k;
        ptr=head;
        while(count--){
            ptr=ptr->next;

        }
        cout<<ptr->data<<endl;

    }

    //by using a stack

    void solution2(int k){
        stack<Node*> s;
        Node* ptr=head;
        while(ptr!=NULL){
            s.push(ptr);
            ptr=ptr->next;
        }
        k--;
        while(k--){
            s.pop();
        }
        cout<<s.top()->data<<endl;
    }

    //using recursive solution
    int solution3(int k,Node* temp){
        if(temp==NULL){
            return 0;
        }
        int index=solution3(k,temp->next)+1;
        if(index==k){
            cout<<temp->data;
        }
        return index;

    }
    
};

int main(){
    LinkedList ll;
    int ch;
    
    do{
        cout<<"MENU \n1.Create list \n2.Display \n3.Kth last using method 1 \n4.Kth last using method 2 \n0.Exit \n";
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
                ll.solution1(k);
                break;
            }
            case 4:{
                int k;
                cout<<"Enter the value of k"<<endl;
                cin>>k;
                ll.solution2(k);
                break;
            }

            case 5:{
                int k;
                cout<<"Enter the value of k"<<endl;
                cin>>k;
                ll.solution3(k,ll.head);
                break;
            }
        }
    }while(ch!=0);
    return 0;
}