/* 
*Given a sorted array with unique integer elements, 
*write an algorithm to create a binary search tree with minimal height.
*/

#include<bits/stdc++.h>
using namespace std;

class treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
    public:
    treeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }

    friend class BST;
};

class BST
{
   public:
   treeNode* root;
   public:
   BST(){
       root=NULL;
   }

   void inorder(treeNode* A){
       if(A==NULL) return;
       inorder(A->left);
       cout<<A->val<<" ";
       inorder(A->right);
   }

   treeNode* solve(vector <int> &v,int start,int end){
       //cout<<"start and end is "<<start<<" "<<end<<endl;
       if(start>end){
           return NULL;
       }
       int mid=(start+end)/2;
       //cout<<"value of mid is "<<mid<<" ";
       treeNode* node= new treeNode();
       node->val=v[mid];
      // cout<<"we here "<<node->val<<endl;
       node->left=solve(v,start,mid-1);
       node->right=solve(v,mid+1,end);
       return node;
   }

   void final(vector <int> &v,int start,int end){
       //cout<<"start and end is "<<start<<" "<<end<<endl;
       treeNode* f=solve(v,start,end);
       //cout<<f->val<<endl;
       inorder(f);
   }
 
};

int main(){
    BST t;
    vector<int> v={1,2,3,4,5,6,7,8,9};
   // cout<<v.size()<<endl;
    t.final(v,0,v.size()-1);
    
    //t.inorder(final);

}