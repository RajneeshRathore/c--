#include<iostream>
#include<vector>
using namespace std;

int Find(int x,vector<int> &parent)
{
    if(parent[x]==x)
    {
        return x;
    }
    return Find(parent[x],parent);
}
void union_by_rank(int a,int b,vector<int> &parent,vector<int> &rank)
{
    int parentA=Find(a,parent);
    int parentB=Find(b,parent);
    if(rank[parentA]==rank[parentB])
    {
        parent[parentB]=parentA;
        rank[parentA]++;
    }
    else if(rank[parentA]>rank[parentB])
    {
       parent[parentB]=parentA;
    }
    else
    {
       parent[parentA]=parentB;
    }
}
int main()
{
    int n;
    cout<<"enter the size of an array"<<endl;
    cin>>n;
    vector<int> parent(n);
    for(int i=0;i<parent.size();i++)
    {
        parent[i]=i;
    }
    vector<int> rank(n,0);
    union_by_rank(0,2,parent,rank);
    cout<<Find(2,parent)<<endl;
    union_by_rank(1,3,parent,rank);
    union_by_rank(2,5,parent,rank);
    union_by_rank(0,3,parent,rank);
    cout<<Find(2,parent)<<endl;

 



    return 0;
}