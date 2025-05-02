#include<iostream>
#include<vector>
using namespace std;

void dfsHelper(int src,vector<bool> &vis,vector<vector<int>>& adj) //O(V+E)
{
   vis[src]=true;
   cout<<src<<" ";
   for(int v:adj[src])
   {
    if(!vis[v])
    {
        dfsHelper(v,vis,adj);
    }
   }
}
void dfs(vector<vector<int>> &adj,int V)
{
    vector<bool> vis(V,false);
    dfsHelper(0,vis,adj);
}
int main()
{
    cout<<"Enter the vertex and edge"<<endl;
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    cout<<"enter the u and v"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,V);
    return 0;
}