#include <bits/stdc++.h>
using namespace std;
#define int long long int
using vi=vector<int>;
const int mod=1e9+7;
int n;
vector<vector<int>>g;
int dp[100100][2];
int dfs(int node,int p,int color){
    if(dp[node][color]!=-1)return dp[node][color];
    int ans=1;
    for(auto child:g[node]){
        if(child==p)continue;
        if(color==0){
            ans*=(dfs(child,node,0)+dfs(child,node,1));
            ans%=mod;
        }else if(color==1){
            ans*=dfs(child,node,0);
            ans%=mod;
        }
    }
    return dp[node][color]=ans;
}
void solve(){
    cin>>n;
    int x,y;
    g=vector<vi>(n+1);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    int ans=dfs(1,-1,0);
    ans+=dfs(1,-1,1);
    ans%=mod;
    cout<<ans;
}
int32_t main() {
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

}
