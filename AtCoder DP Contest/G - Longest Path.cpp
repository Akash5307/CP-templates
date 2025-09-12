#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;

int n,m;
vector<vector<int>>g;
int dp[100100];
int dfs(int node){
    if(dp[node]!=-1)return dp[node];
    int ans=0;
    for(auto child:g[node]){
        ans=max(ans,1+dfs(child));
    }
    return dp[node]=ans;
}
void solve(){
    cin>>n>>m;
    g=vector<vector<int>>(n+1);
    int x,y;
    while(m--){
        cin>>x>>y;
        g[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}
