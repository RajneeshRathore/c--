#include<iostream>
#include<vector>
using namespace std;

void dfsHelper(int src,int dest,vector<bool> &vis,vector<vector<int>>& adj,vector<bool> &recPath,string &str) //O(V+E)
{
    if(src==dest)
    {
        cout<<str<<dest<<endl;
        return ;
    }
   vis[src]=true;
   str.append(to_string(src));
   for(int v:adj[src])
   {
    if(!vis[v])
    {
        dfsHelper(v,dest,vis,adj,recPath,str);
    }
   }
   recPath[src]=false;
   vis[src]=false;
   str=str.substr(0,str.size()-1);
}
void dfs(vector<vector<int>> &adj,int V)
{
    vector<bool> vis(V,false);
    vector<bool> recPath(V,false);
    string str="";
    dfsHelper(5,1,vis,adj,recPath,str);
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
    dfs(adj,V);
    return 0;
}