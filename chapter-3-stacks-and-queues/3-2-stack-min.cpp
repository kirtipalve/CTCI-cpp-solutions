 /* Cracking the coding interview edition 6
 * Problem 3-2-Stack min : How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element?
 * Push,pop and min should all operate in O(1)
 * 			   
 * Approach 1: Use an auxillary stack that stores minimum elements from the main stack
 *             Space Complexity O(n) & Time complexity O(1)
 * Approach 2: Using a variable to keep track of the min
 *             Space Complexity O(1) & Time complexity O(A+B)
 * 

*/

#include<bits/stdc++.h>
using namespace std;


class Stack
{
    stack<int> primary_stack;
    stack<int> auxillary_stack;

    public:
  

    void push(int data){
        primary_stack.push(data);
        if(auxillary_stack.empty()|| data<=auxillary_stack.top()){
            auxillary_stack.push(data);
        }
    }

    void pop(){
        if(primary_stack.top()==auxillary_stack.top()){
            auxillary_stack.pop();
        }
        primary_stack.pop();
    }

    int min_val(){
        return auxillary_stack.top();
    }

};

int main(){
    int ch;
    Stack obj;

    do{
        cout<<"MENU \n1.Push \n2.Pop \n3.Get min value (using two stacks approach) \n0.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:{
                while(true){
                    string p;
                    cout<<"Enter element to be pushed or type 'done' to stop pushing"<<endl;
                    cin>>p;
                    if(p=="done") break;
                    obj.push(stoi(p));

                }
                break;
            }
            case 2:{
                obj.pop();
                break;
            }

            case 3:{
                cout<<"minimum value is "<<obj.min_val()<<endl;
                break;
            }

        }

    }while(ch!=0);

    return 0;


}
