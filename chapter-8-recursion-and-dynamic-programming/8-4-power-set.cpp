/*
*Write a method to return all subsets of a set
*/

#include<bits/stdc++.h>
using namespace std;



void subsets(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int i){

    if(i==A.size()){
        ans.push_back(temp);
        return;
    }
   
    
    subsets(A,ans,temp,i+1);
    temp.push_back(A[i]);
    subsets(A,ans,temp,i+1);

    


}
int main(){
    vector<int> A={1,2,3,4};
    vector<vector<int>> ans;
    
    vector<int> temp;
    //ans.push_back(A);
    subsets(A,ans,temp,0);

    for (int i = 0; i < ans.size(); i++){
    cout<<"{";

    for (int j = 0; j < ans[i].size(); j++)
    {

        cout << ans[i][j];
        if(j!=ans[i].size()-1){
            cout<<",";
        }
    }
    cout<<"}"<<endl;
}

return 0;

}