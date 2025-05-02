#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topoHelper(int src,vector<bool> &vis,vector<vector<int>>& adj,stack<int> &s) //O(V+E)
{
   vis[src]=true;
   for(int v:adj[src])
   {
    if(!vis[v])
    {
        topoHelper(v,vis,adj,s);
    }
   }
   s.push(src);
}
void topo(vector<vector<int>> &adj,int V)
{
    vector<bool> vis(V,false);
    stack<int> s;
    vector<int> ans;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
           topoHelper(i,vis,adj,s);
        }
    }
    while(!s.empty())
    {
        int cur = s.top();
        ans.push_back(cur);
        s.pop();
    }
    for(int i=0;i<ans.size();i++)
    {
       cout<<ans[i]<<" ";
    }
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
       // adj[v].push_back(u);
    }
    topo(adj,V);
    return 0;
}