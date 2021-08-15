#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    //number of ways to climb 0 steps
    v[0]=0;
    //number of ways to climb 1 steps
    v[1]=1;
    //number of ways to climb 2 steps
    v[2]=2;
    v[3]=4;
    for(int i=4;i<=n;i++){
        v[i]=v[i-1]+v[i-2]+v[i-3];

    }
    cout<<v[n]<<endl;

    return 0;
}