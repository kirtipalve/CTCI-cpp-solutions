/*
*Given a directed graph,design an algorithm to find out whether there is a 
*route between two nodes.
*Time complexity O(V+E), Space Complexity O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <vector <int>> adj={{1},{2,3,4},{},{},{0,6},{},{5}};
    vector <bool> visited(7,false);
    int node1;
    int node2;
    cout<<"Enter the two nodes "<<endl;
    cin>>node1>>node2;
    vector<int> path;
    
    queue <int> q;
    visited[node1]=true;
    q.push(node1);
    while(!q.empty()){
        int s=q.front();
        path.push_back(s);
        q.pop();
        
        for(int i=0;i<adj[s].size();i++){
            if(visited[adj[s][i]]==false){
                visited[adj[s][i]]=true;
                q.push(adj[s][i]);
                
            }
        }
        
    }
    
    if(find(path.begin(),path.end(),node2)!=path.end()){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    return 0;
}
