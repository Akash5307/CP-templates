#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool visited[N];
void dfs(int vertex){
    /*take action on vertex after entering the vertex*/
    cout<<vertex<<"\n";
    //if(visited[vertex]=1) return;
    visited[vertex]=true;
    for(int child:g[vertex]){
        if(visited[vertex]==true) continue;
        cout<<"parent:"<<vertex<<" Child:"<<child<<"\n";
    /*Take action on child before entering the child node*/
        dfs(child);
    /*Take action on child after exiting the child node*/    
    }
    /*Take action on vertex before exiting the vertex*/
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}
