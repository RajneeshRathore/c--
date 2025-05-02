#include <iostream>
#include <vector>
using namespace std;

bool isCycleHelper(int src, int parent, vector<bool> &vis, vector<vector<int>> &adj) // O(V+E)
{
    vis[src] = true;
    for (int v : adj[src])
    {
        if (!vis[v])
        {
            if (isCycleHelper(v, src, vis, adj))
            {
                return true;
            }
        }
        else
        {
            if (parent!=v)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj, int V)
{
    vector<bool> vis(V, false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
           if(isCycleHelper(0, -1, vis, adj))
           {
              return true;
           }
        }
    }
    return false;
}
int main()
{
    cout << "Enter the vertex and edge" << endl;
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    cout << "enter the u and v" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"isCycle: "<<isCycle(adj, V);
    return 0;
}